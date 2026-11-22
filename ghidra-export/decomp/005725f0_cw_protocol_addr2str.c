// func cw_protocol_addr2str @ 005725f0 size=192

undefined4 cw_protocol_addr2str(char *param_1,char *param_2,socklen_t param_3)

{
  undefined4 uVar1;
  int __af;
  undefined4 *__cp;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar1 = 0xffffffff;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
    if (*param_1 == '\x01') {
      local_28 = *(undefined4 *)(param_1 + 4);
      __af = 2;
      __cp = &local_28;
    }
    else {
      if (*param_1 != '\x02') {
        snprintf(param_2,param_3,"N/A");
        return 0;
      }
      memcpy(&local_24,param_1 + 4,0x10);
      __af = 10;
      __cp = &local_24;
    }
    inet_ntop(__af,__cp,param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}

