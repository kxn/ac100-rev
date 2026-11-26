#!/usr/bin/env node
/*
 * Extract the data fields built at each LuCI -> uac JCS call site.
 *
 * The vendor controllers are minified Lua 5.1.  For every jcsUI2uac(...)
 * call we resolve the 4th argument: a table constructor is read directly;
 * a local variable is resolved from assignments in the enclosing function.
 * Output is JSONL:
 *   {file,line,name,op,data_expr,fields:{path:value_expr},source}
 */
const fs = require('fs');
const path = require('path');
const luaparse = require(process.env.LUAPARSE || 'luaparse');

const ROOT = path.resolve(process.env.AC100_REV_ROOT || path.join(__dirname, '..'));
const TSV = path.join(ROOT, 'notes/vendor-web/web-jcs-calls.tsv');
const work = path.resolve(process.env.AC100_WORK_DIR || path.join(ROOT, '.local/ac100'));
const fw = process.env.AC100_ROOTFS || process.env.AC100_FW || path.join(work, 'rootfs');
const crypto = require('crypto');
const expected = 'b12d1584fcafda2a71aa9038b41b7e1c5b893b350f3e6edf5105e445d024a912';
const binary = path.join(fw, 'usr/sbin/uac');
if (!fs.existsSync(binary)) throw new Error(`Missing ${binary}; import the V6 firmware first (docs/setup.md)`);
if (crypto.createHash('sha256').update(fs.readFileSync(binary)).digest('hex') !== expected) {
  throw new Error('Firmware mismatch: this extractor requires TL-AC100 V6.0 1.0.3 Build 260817 Rel.68871n');
}

function walk(node, fn, parent = null) {
  if (!node || typeof node !== 'object') return;
  if (Array.isArray(node)) { for (const n of node) walk(n, fn, parent); return; }
  if (node.type) fn(node, parent);
  for (const k of Object.keys(node)) {
    if (k === 'loc' || k === 'range') continue;
    walk(node[k], fn, node.type ? node : parent);
  }
}

function exprText(node) {
  if (!node) return '';
  switch (node.type) {
    case 'StringLiteral': return JSON.stringify(node.value);
    case 'NumericLiteral': return String(node.value);
    case 'BooleanLiteral': return String(node.value);
    case 'NilLiteral': return 'nil';
    case 'Identifier': return node.name;
    case 'MemberExpression': return exprText(node.base) + (node.indexer === '.' ? '.' + node.identifier.name : '[' + exprText(node.index) + ']');
    case 'IndexExpression': return exprText(node.base) + '[' + exprText(node.index) + ']';
    case 'CallExpression': return exprText(node.base) + '(...)';
    case 'TableConstructorExpression': return '{...}';
    default: return node.type;
  }
}

function memberPath(node) {
  // returns [root, key1, key2...] for a.b["c"], or null
  let keys = [];
  let cur = node;
  while (cur) {
    if (cur.type === 'MemberExpression') {
      if (cur.indexer === '.') keys.unshift(cur.identifier.name);
      else if (cur.index.type === 'StringLiteral') keys.unshift(cur.index.value);
      else keys.unshift('[' + exprText(cur.index) + ']');
      cur = cur.base;
    } else if (cur.type === 'IndexExpression') {
      if (cur.index.type === 'StringLiteral') keys.unshift(cur.index.value);
      else keys.unshift('[' + exprText(cur.index) + ']');
      cur = cur.base;
    } else if (cur.type === 'Identifier') {
      keys.unshift(cur.name); return keys;
    } else return null;
  }
  return null;
}

function tableFields(tbl, prefix, out) {
  for (const f of tbl.fields || []) {
    if (f.type === 'TableKeyString') {
      const p = prefix ? prefix + '.' + f.key.name : f.key.name;
      out[p] = exprText(f.value);
      if (f.value.type === 'TableConstructorExpression') tableFields(f.value, p, out);
    } else if (f.type === 'TableKey') {
      const k = f.key.type === 'StringLiteral' ? f.key.value : exprText(f.key);
      const p = prefix ? prefix + '.' + k : k;
      out[p] = exprText(f.value);
      if (f.value.type === 'TableConstructorExpression') tableFields(f.value, p, out);
    } else if (f.type === 'TableValue') {
      const p = prefix ? prefix + '[]' : '[]';
      out[p] = exprText(f.value);
      if (f.value.type === 'TableConstructorExpression') tableFields(f.value, p, out);
    }
  }
}

function enclosingFunction(node, funcs) {
  let best = null;
  for (const f of funcs) {
    if (f.range[0] <= node.range[0] && node.range[1] <= f.range[1]) {
      if (!best || (f.range[1] - f.range[0]) < (best.range[1] - best.range[0])) best = f;
    }
  }
  return best;
}

function collectFunctionAssignments(fn, varName, funcs) {
  const fields = {};
  const calls = new Set();
  if (!fn) return { fields, calls };
  walk(fn.body, (n) => {
    if (n.type === 'AssignmentStatement') {
      for (let i = 0; i < n.variables.length; i++) {
        const v = n.variables[i], val = n.init[i];
        if (!val) continue;
        const p = memberPath(v);
        if (p && p[0] === varName && p.length > 1) {
          const key = p.slice(1).join('.');
          fields[key] = exprText(val);
          if (val.type === 'TableConstructorExpression') tableFields(val, key, fields);
        }
        if (p && p.length === 1 && p[0] === varName && val.type === 'TableConstructorExpression') {
          tableFields(val, '', fields);
        }
        if (p && p.length === 1 && p[0] === varName && val.type === 'CallExpression') {
          calls.add(exprText(val.base));
        }
      }
    }
    if (n.type === 'LocalStatement') {
      for (let i = 0; i < n.variables.length; i++) {
        const v = n.variables[i], val = n.init[i];
        if (!val) continue;
        if (v.name === varName && val.type === 'TableConstructorExpression') tableFields(val, '', fields);
        if (v.name === varName && val.type === 'CallExpression') calls.add(exprText(val.base));
      }
    }
  });
  return { fields, calls };
}

function main() {
  const rows = fs.readFileSync(TSV, 'utf8').split('\n').slice(1).filter(Boolean).map(l => l.split('\t'));
  const byFile = {};
  for (const r of rows) {
    const [controller, line, fn, client, name, op, dataExpr] = r;
    (byFile[controller] = byFile[controller] || []).push({ line: +line, fn, client, name, op: op.split(' ')[0], dataExpr });
  }
  const out = [];
  for (const rel of Object.keys(byFile)) {
    const file = path.join(fw, rel);
    if (!fs.existsSync(file)) continue;
    let ast;
    try { ast = luaparse.parse(fs.readFileSync(file, 'utf8'), { locations: true, ranges: true, luaVersion: '5.2' }); }
    catch (e) { process.stderr.write('PARSE ' + rel + ': ' + e.message + '\n'); continue; }
    const funcs = [];
    walk(ast, (n) => { if (n.type === 'FunctionDeclaration') funcs.push(n); });
    const calls = [];
    walk(ast, (n) => {
      if (n.type !== 'CallExpression') return;
      const b = n.base;
      let fname = b.type === 'Identifier' ? b.name : (b.type === 'MemberExpression' ? b.identifier.name : '');
      if (!/^jcs(UI|Service)2/.test(fname)) return;
      const arg = n.arguments[3];
      if (!arg) return;
      const nm = n.arguments[0], op = n.arguments[1];
      calls.push({ node: n, file: rel, line: n.loc.start.line, jname: nm && nm.type === 'StringLiteral' ? nm.value : '', jop: exprText(op), arg });
    });
    for (const c of calls) {
      let matches = byFile[rel].filter(r => r.line === c.line && r.name === (c.jname || ''));
      if (!matches.length) matches = byFile[rel].filter(r => r.line === c.line);
      const meta = matches[0] || {};
      const jname = c.jname || meta.name;
      let fields = {}, source = '', helperCalls = new Set();
      if (c.arg.type === 'TableConstructorExpression') {
        tableFields(c.arg, '', fields);
        source = 'inline';
      } else {
        const p = memberPath(c.arg);
        if (p && p.length === 1) {
          const fn = enclosingFunction(c.node, funcs);
          const res = collectFunctionAssignments(fn, p[0], funcs);
          fields = res.fields; helperCalls = res.calls;
          source = 'local:' + p[0];
          // one-level helper resolution: function name(...) in same file
          for (const h of helperCalls) {
            const hf = funcs.find(f => f.identifier && f.identifier.name === h && f.isLocal);
            if (hf) {
              // collect returns of table constructors in helper
              walk(hf.body, (n) => {
                if (n.type === 'ReturnStatement') {
                  for (const a of n.arguments || []) {
                    if (a.type === 'TableConstructorExpression') tableFields(a, '', fields);
                    if (a.type === 'Identifier') {
                      const r2 = collectFunctionAssignments(hf, a.name, funcs);
                      Object.assign(fields, r2.fields);
                    }
                  }
                }
              });
            }
          }
        } else {
          source = 'expr:' + exprText(c.arg);
        }
      }
      out.push({ file: rel, line: c.line, name: jname, op: c.jop, data_expr: meta.dataExpr || exprText(c.arg), source, fields });
    }
  }
  const seen = new Set();
  for (const r of out) {
    const k = r.file + ':' + r.line + ':' + r.name + ':' + r.op;
    if (seen.has(k)) continue; seen.add(k);
    process.stdout.write(JSON.stringify(r) + '\n');
  }
  process.stderr.write('calls=' + out.length + ' unique=' + seen.size + '\n');
}
main();
