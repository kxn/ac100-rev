// func wsta_db_free_sta_by_mac @ 0063a780 size=456

int wsta_db_free_sta_by_mac(undefined4 param_1,code *param_2,undefined4 param_3)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char local_e8 [32];
  undefined1 auStack_c8 [44];
  undefined1 auStack_9c [104];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  
  local_e8[0] = '\0';
  local_e8[1] = '\0';
  local_e8[2] = '\0';
  local_e8[3] = '\0';
  local_e8[4] = '\0';
  local_e8[5] = '\0';
  local_e8[6] = '\0';
  local_e8[7] = '\0';
  local_e8[8] = '\0';
  local_e8[9] = '\0';
  local_e8[10] = '\0';
  local_e8[0xb] = '\0';
  local_e8[0xc] = '\0';
  local_e8[0xd] = '\0';
  local_e8[0xe] = '\0';
  local_e8[0xf] = '\0';
  local_e8[0x10] = '\0';
  local_e8[0x11] = '\0';
  local_e8[0x12] = '\0';
  local_e8[0x13] = '\0';
  memset(local_e8 + 0x14,0,0x38);
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  iVar3 = -1;
  __src = (void *)FUN_00407fa0(DAT_007cc6cc,param_1);
  if (__src != (void *)0x0) {
    iVar3 = 0;
    memcpy(auStack_9c,__src,0x80);
    _wsta_free_entry(__src);
  }
  FUN_00407f30(DAT_007cc6bc);
  if (iVar3 == 0) {
    if (param_2 == (code *)0x0) {
      _uac_wstation_do_event(1,auStack_9c);
      iVar1 = wsta_db_get_mac_entry_by_peer(&local_34,local_e8 + 0x14);
      if ((iVar1 == 0) && (iVar1 = memcmp(auStack_c8,&local_34,6), iVar1 != 0)) {
        return 0;
      }
      snprintf(local_e8,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_34,(uint)local_33,
               (uint)local_32,(uint)local_31,(uint)local_30,(uint)local_2f);
      uVar2 = 0x3a9a;
    }
    else {
      (*param_2)(auStack_9c,param_3);
      _uac_wstation_do_event(1,auStack_9c);
      snprintf(local_e8,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_34,(uint)local_33,
               (uint)local_32,(uint)local_31,(uint)local_30,(uint)local_2f);
      uVar2 = 0x3a9b;
    }
    loggerk_reg(0x5b,uVar2,1,local_e8,0);
  }
  return iVar3;
}

