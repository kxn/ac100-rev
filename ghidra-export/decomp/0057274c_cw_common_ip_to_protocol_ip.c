// func cw_common_ip_to_protocol_ip @ 0057274c size=148

undefined4 cw_common_ip_to_protocol_ip(undefined1 *param_1,char *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_2 != (char *)0x0) && (param_1 != (undefined1 *)0x0)) {
    if (*param_2 == '\x01') {
      memset(param_1,0,0x14);
      *param_1 = 1;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    }
    else {
      if (*param_2 != '\x02') {
        return 0xffffffff;
      }
      memset(param_1,0,0x14);
      *param_1 = 2;
      memcpy(param_1 + 4,param_2 + 4,0x10);
    }
    uVar1 = 0;
  }
  return uVar1;
}

