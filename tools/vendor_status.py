#!/usr/bin/env python3
"""Read the running vendor AC's AP count, model/status and SSIDs through JCS GET."""
from qemu_harness import Guest, H

SCRIPT = '''local u=require"uds"
local j=require"cjson"
for _,name in ipairs({"ap_count","ap_status","ap_status_ssid"}) do
 local p="/tmp/envcheck."..u.getpid().."."..name
 local s=u.open(p)
 local data=name=="ap_count" and "{}" or name=="ap_status_ssid" and '{"entry_id":"0","start":0,"size":64}' or '{"start":0,"size":10}'
 local req='{"name":"'..name..'","op":3,"clt_path":"'..p..'","data":'..data..'}'
 local ok,e=u.send(s,"/tmp/jcs.ui.srv.uac",req)
 local r,err=nil,e
 if ok and not e then r,err=u.rcve(s,3) end
 print(name,r or err or "no response")
 if r then
  local good,obj=pcall(j.decode,r)
  if good and obj.file_name then
   local f=io.open(obj.file_name)
   if f then print(f:read("*a"));f:close() end
  end
 end
 u.close(s);os.remove(p)
end
'''


def main():
    g = Guest()
    try:
        g.connect(timeout=5)
        g.wait_prompt(timeout=5)
        g.put_file("/mnt/share/environment-status.lua", SCRIPT)
        result = g.run_lua("/share/environment-status.lua", "__STATUS_DONE", timeout=15)
        (H / "environment-status.txt").write_bytes(result)
        print(result.decode("utf-8", "replace"))
    finally:
        g.close()


if __name__ == "__main__":
    main()
