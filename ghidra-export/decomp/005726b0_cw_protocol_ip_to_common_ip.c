// func cw_protocol_ip_to_common_ip @ 005726b0 size=156

undefined4 cw_protocol_ip_to_common_ip(char *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (param_2 != (undefined1 *)0x0)) {
    if (*param_1 == '\x01') {
      memset(param_2,0,0x14);
      *param_2 = 1;
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 4);
    }
    else {
      if (*param_1 != '\x02') {
        return 0xffffffff;
      }
      memset(param_2,0,0x14);
      *param_2 = 2;
      memcpy(param_2 + 4,param_1 + 4,0x10);
    }
    uVar1 = 0;
  }
  return uVar1;
}

