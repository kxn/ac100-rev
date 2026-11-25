local uds = require"uds"
local cjson = require"cjson"
local LOG = "/share/field-raw-results.jsonl"
local log = io.open(LOG, "a")
local pid = uds.getpid()
local start_i, end_i = 1, 1000000
local bf = io.open("/share/batch.txt")
if bf then start_i, end_i = bf:read("*n", "*n"); bf:close() end
local i = 0
for line in io.lines("/share/field-requests.tsv") do
  i = i + 1
  if i >= start_i and i <= end_i then
    local name, op, data = line:match("^([^\t]+)\t(%d)\t(.*)$")
    if name then
      local clt = "/tmp/jcs.probe." .. tostring(pid) .. "." .. tostring(i) .. ".clt"
      local req = '{"name":"' .. name .. '","op":' .. op .. ',"clt_path":"' .. clt .. '","data":' .. data .. '}'
      local s = uds.open(clt)
      local ok, err = uds.send(s, "/tmp/jcs.ui.srv.uac", req)
      log:write(cjson.encode({dir="tx", idx=i, name=name, op=tonumber(op), path=clt, data=req}), "\n"); log:flush()
      local resp, rerr = nil, err
      if ok and not err then resp, rerr = uds.rcve(s, 5) end
      log:write(cjson.encode({dir="rx", idx=i, data=resp, err=rerr}), "\n"); log:flush()
      uds.close(s)
      os.remove(clt)
      local ret = "-"
      if resp then
        local ok2, obj = pcall(cjson.decode, resp)
        if ok2 and type(obj) == "table" then ret = tostring(obj.ret) end
      end
      print(string.format("CASE %d %s %d ret=%s err=%s", i, name, tonumber(op), ret, tostring(rerr)))
      if rerr and (string.find(tostring(rerr), "Send pkt failed", 1, true) or string.find(tostring(rerr), "Connection refused", 1, true)) then
        print("UACDEAD", i); break
      end
    end
  end
end
log:close()
print("RAWDONE", i)
