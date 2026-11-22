// func wserv_db_get_entry_by_ssid @ 005f52e8 size=204

undefined4 wserv_db_get_entry_by_ssid(char *param_1,undefined4 param_2,void *param_3)

{
  void *__src;
  undefined4 uVar1;
  undefined4 local_50;
  char acStack_4c [52];
  
  uVar1 = 0xffffffff;
  memset(&local_50,0,0x38);
  if (param_1 != (char *)0x0) {
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    if (l_wserv_data != 0) {
      strncpy(acStack_4c,param_1,0x31);
      local_50 = param_2;
      __src = (void *)FUN_00407fa0(g_wserv_hash,&local_50);
      if (__src != (void *)0x0) {
        memcpy(param_3,__src,0x205);
        uVar1 = 0;
      }
    }
    FUN_00407f30(DAT_007cbef0);
  }
  return uVar1;
}

