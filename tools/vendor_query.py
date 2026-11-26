#!/usr/bin/env python3
"""Query the local QEMU oracle's native JCS envelope; writes only when --op is explicit."""
import argparse
import json
from pathlib import Path
import re
from ac100_env import WORK
from qemu_harness import Guest


def query(name, op, data):
    request = json.dumps({"name": name, "op": op, "data": data}, separators=(",", ":"))
    # The argument is JSON-encoded as a Lua string, not interpolated as code.
    encoded = " ..\n".join(json.dumps(request[i:i+120], ensure_ascii=True) for i in range(0,len(request),120))
    script = '''local u=require"uds";local j=require"cjson"
local wire=%s
local req=j.decode(wire)
local path="/tmp/go_oracle."..u.getpid();req.clt_path=path
local s=u.open(path);local ok,err=u.send(s,"/tmp/jcs.ui.srv.uac",j.encode(req))
local response,error=nil,err
if ok and not err then response,error=u.rcve(s,5) end
local out={response=response,error=error}
if response then local good,r=pcall(j.decode,response);if good then
 out.response=r
 if r.file_name then local f=io.open(r.file_name);if f then local body=f:read("*a");f:close();local valid,decoded=pcall(j.decode,body);out.file=valid and decoded or body end end
end end
u.close(s);os.remove(path);print("ORACLE_JSON="..j.encode(out))
''' % encoded
    guest = Guest()
    try:
        guest.connect(5);guest.wait_prompt(5)
        guest.put_file("/mnt/share/go_oracle.lua", script)
        result=guest.run_lua("/share/go_oracle.lua", "__ORACLE_QUERY_DONE", timeout=15).decode("utf-8", "replace")
        match=re.search(r"(?:^|\n)ORACLE_JSON=(.*)\r?\n",result)
        if not match:raise RuntimeError(result[-2500:])
        return json.loads(match.group(1))
    finally:guest.close()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("name");p.add_argument("--op",type=int,choices=(0,1,2,3),default=3)
    p.add_argument("--data",default="{}");p.add_argument("--output",type=Path)
    args=p.parse_args();result=query(args.name,args.op,json.loads(args.data))
    if args.output:
        args.output.parent.mkdir(parents=True,exist_ok=True)
        args.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+"\n");args.output.chmod(0o600)
    print(json.dumps(result,ensure_ascii=False,indent=2))


if __name__=="__main__":main()
