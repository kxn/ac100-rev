#!/usr/bin/env python3
"""Recover the uac JCS callback registry from jcs_callback_register call sites.

Evidence: jcs_callback_register @ 0x005af370 in the TL-AC100 V6.0 image.
Every subsystem init calls the local thunk at 0x0040cee0 with
(a0=name string, a1=op, a2=handler).  This script disassembles LOAD1, runs a
small branch/delay-slot-aware dataflow per registration function, and emits
name/op/handler/handler_symbol TSV rows.
"""
import os
import re
import subprocess
from pathlib import Path

from ac100_env import ROOTFS as FW
UAC = FW / "usr/sbin/uac"
SYM = FW / "usr/sbin/uac_symbol_fun"
from ac100_env import ASM
LOAD1_END = 0x8ba180

from ac100_env import build_vendor_asm as build_asm


import re
from pathlib import Path
build_asm()
BIN=UAC.read_bytes()
LOAD1=(0x400000,0x4ba180)
def read_cstr(va):
    if not (0x400000<=va<0x400000+0x4ba180): return None
    off=va-0x400000
    e=BIN.find(b'\0',off)
    if e<0: return None
    b=BIN[off:e]
    if len(b)<1 or len(b)>80: return None
    try: return b.decode('utf-8')
    except: return None
syms=[]
for line in SYM.read_text().splitlines():
    p=line.split()
    if len(p)>=4:
        try: a=int(p[0],16); s=int(p[1],16)
        except: continue
        syms.append((a,s," ".join(p[3:])))
syms.sort()
def sym_at(va):
    best=None
    for a,s,n in syms:
        if a<=va<a+s:
            if best is None or a>=best[0]: best=(a,n)
    return best[1] if best else None
def sym_start(va):
    for a,s,n in syms:
        if a<=va<a+s: return a,n
    return None,None
INS=re.compile(r'^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)\s*(.*)$')
# build instruction map
ins={}
for line in ASM.read_text().splitlines():
    m=INS.match(line)
    if not m: continue
    a=int(m.group(1),16); mn=m.group(3); ops=m.group(4).split('#')[0].strip()
    ins[a]=(mn,ops)
# call sites
calls=[a for a,(mn,ops) in ins.items() if mn=='jal' and ops=='0x40cee0']
calls.sort()
def s16(x):
    x&=0xffff
    return x-0x10000 if x>=0x8000 else x
def parse_imm(s):
    s=s.strip()
    try: return int(s,16) if s.startswith('0x') else int(s)
    except: return None
UNK=None
def transfer(state,mn,ops):
    st=dict(state)
    parts=[x.strip() for x in ops.split(',')] if ops else []
    if mn=='lui' and len(parts)==2:
        v=parse_imm(parts[1])
        st[parts[0]]=(v<<16)&0xffffffff if v is not None else UNK
    elif mn=='addiu' and len(parts)==3:
        v=parse_imm(parts[2]); base=st.get(parts[1])
        if base is not None and v is not None: st[parts[0]]=(base+v)&0xffffffff
        else: st[parts[0]]=UNK
    elif mn=='ori' and len(parts)==3:
        v=parse_imm(parts[2]); base=st.get(parts[1])
        if base is not None and v is not None: st[parts[0]]=(base|v)&0xffffffff
        else: st[parts[0]]=UNK
    elif mn=='li' and len(parts)==2:
        v=parse_imm(parts[1]); st[parts[0]]=v&0xffffffff if v is not None else UNK
    elif mn=='move' and len(parts)==2:
        st[parts[0]]=st.get(parts[1])
    elif mn=='or' and len(parts)==3 and parts[0]==parts[1]==parts[2]:
        st[parts[0]]=st.get(parts[2])
    elif mn in ('lw','lb','lbu','lh','lhu','lwl','lwr'):
        if parts: st[parts[0]]=UNK
    elif mn in ('sw','sb','sh','swl','swr'):
        pass
    elif mn in ('jal','jalr','bal'):
        for r in ('a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7','t8','t9','v0','v1','ra','gp'):
            st[r]=UNK
    elif mn in ('addu','subu','slt','sltu','slti','sltiu','andi','xori','sll','srl','sra','sllv','srlv','srav','negu','not','mul','div','divu','mfhi','mflo'):
        if parts: st[parts[0]]=UNK
    return st
def branch_target(mn,ops):
    if mn in ('beq','bne','beqz','bnez','bgez','bgtz','blez','bltz','bgezal','bltzal','beql','bnel','beqzl','bnezl','bgezl','bgtzl','blezl','bltzl','bgezall','bltzall'):
        t=ops.split(',')[-1].strip()
        return parse_imm(t)
    if mn in ('j','jal','b','bal'):
        # j/jal/b take target
        return parse_imm(ops.split(',')[0].strip())
    return None
def analyze(call):
    fstart,fn=sym_start(call)
    if fstart is None: return None
    # start state: args unknown
    init={'zero':0}
    init.update({r:UNK for r in ('a0','a1','a2','a3','v0','v1','t0','t1','t2','t3','t4','t5','t6','t7','t8','t9','s0','s1','s2','s3','s4','s5','s6','s7','fp','sp','ra')})
    # worklist of (pc, state)
    work=[(fstart,init)]
    seen=set()
    found=None
    steps=0
    while work:
        pc,st=work.pop()
        while True:
            steps+=1
            if steps>20000: return None
            if pc==call:
                if pc+4 in ins:
                    st=transfer(st,*ins[pc+4])
                found=st; break
            if pc not in ins: break
            # stop at function end
            if pc<fstart or sym_start(pc)[0]!=fstart: break
            mn,ops=ins[pc]
            key=(pc, tuple(sorted((k,v) for k,v in st.items() if k in ('a0','a1','a2','a3','s0','s1','s2','s3','s4','s5','s6','s7','v0','v1'))))
            if key in seen: break
            seen.add(key)
            if mn in ('jr','j','b','bal','jal','jalr') or mn.startswith('b'):
                pass
            # process delay slot for branches/jumps
            if mn in ('j','jal','b','bal') or mn.startswith('b'):
                # delay slot at pc+4
                if pc+4 in ins:
                    st=transfer(st,*ins[pc+4])
                if mn in ('j','b'):
                    tgt=branch_target(mn,ops)
                    if tgt is None: break
                    pc=tgt; continue
                elif mn=='bal':
                    tgt=branch_target(mn,ops)
                    if tgt is None: break
                    pc=tgt; continue
                elif mn=='jal':
                    # call target, then continue at pc+8
                    pc=pc+8; continue
                else:
                    tgt=branch_target(mn,ops)
                    # fork target and fallthrough
                    if tgt is not None:
                        work.append((tgt,dict(st)))
                    pc=pc+8; continue
            elif mn in ('jalr',):
                # delay slot then continue
                if pc+4 in ins: st=transfer(st,*ins[pc+4])
                pc=pc+8; continue
            elif mn=='j':
                tgt=branch_target(mn,ops)
                if tgt is None: break
                pc=tgt; continue
            else:
                st=transfer(st,mn,ops)
                pc=pc+4
        if found is not None: break
    return found
out=[]
for c in calls:
    st=analyze(c)
    if st is None:
        continue
    a0,a1,a2=st.get('a0'),st.get('a1'),st.get('a2')
    name=read_cstr(a0) if isinstance(a0,int) else None
    sym=sym_at(a2) if isinstance(a2,int) else None
    if not name or not isinstance(a1,int) or not isinstance(a2,int):
        continue
    print(f"{name}\t{a1}\t{a2:#010x}\t{sym or ''}")
