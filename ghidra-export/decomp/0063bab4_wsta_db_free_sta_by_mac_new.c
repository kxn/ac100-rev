// func wsta_db_free_sta_by_mac_new @ 0063bab4 size=396

int wsta_db_free_sta_by_mac_new(undefined4 param_1,code *param_2,undefined4 param_3)

{
  void *__src;
  undefined4 uVar1;
  int iVar2;
  char local_b0 [124];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  
  local_b0[0] = '\0';
  local_b0[1] = '\0';
  local_b0[2] = '\0';
  local_b0[3] = '\0';
  local_b0[4] = '\0';
  local_b0[5] = '\0';
  local_b0[6] = '\0';
  local_b0[7] = '\0';
  local_b0[8] = '\0';
  local_b0[9] = '\0';
  local_b0[10] = '\0';
  local_b0[0xb] = '\0';
  local_b0[0xc] = '\0';
  local_b0[0xd] = '\0';
  local_b0[0xe] = '\0';
  local_b0[0xf] = '\0';
  local_b0[0x10] = '\0';
  local_b0[0x11] = '\0';
  local_b0[0x12] = '\0';
  local_b0[0x13] = '\0';
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  iVar2 = -1;
  __src = (void *)FUN_00407fa0(DAT_007cc6cc,param_1);
  if (__src != (void *)0x0) {
    iVar2 = 0;
    memcpy(local_b0 + 0x14,__src,0x80);
    _wsta_free_entry_new(__src);
  }
  FUN_00407f30(DAT_007cc6bc);
  if (iVar2 == 0) {
    if (param_2 == (code *)0x0) {
      _uac_wstation_do_event(1,local_b0 + 0x14);
      snprintf(local_b0,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_34,(uint)local_33,
               (uint)local_32,(uint)local_31,(uint)local_30,(uint)local_2f);
      uVar1 = 0x3a9a;
    }
    else {
      (*param_2)(local_b0 + 0x14,param_3);
      _uac_wstation_do_event(1,local_b0 + 0x14);
      snprintf(local_b0,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_34,(uint)local_33,
               (uint)local_32,(uint)local_31,(uint)local_30,(uint)local_2f);
      uVar1 = 0x3a9b;
    }
    loggerk_reg(0x5b,uVar1,1,local_b0,0);
  }
  return iVar2;
}

