// func multi_link_status_switch_by_inner @ 00664118 size=372

undefined4
multi_link_status_switch_by_inner
          (uint param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__format;
  undefined4 uVar4;
  undefined1 auStack_2f8 [732];
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2f8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f8);
  iVar2 = g_multi_link_array;
  if (iVar1 == 0) {
    uVar3 = param_1;
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      uVar3 = (param_1 - 50000) + iVar1;
    }
    iVar1 = g_multi_link_config_changed_array;
    if (*(char *)(iVar2 + uVar3) == '\x01') {
      return 0;
    }
    uVar3 = param_1;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      uVar3 = (param_1 - 50000) + iVar2;
    }
    *(undefined1 *)(iVar1 + uVar3) = param_3;
    multi_link_status_switch(param_1,param_2,param_3,param_4,param_5,param_6);
    iVar2 = _multi_link_checksum_send(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    if (multi_link_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = 
    "[MULTI_LINK_ERROR]%s()/%d Failed to assemble config update req packet to send checksum to ap.\n"
    ;
    uVar4 = 0xe4;
  }
  else {
    if (multi_link_warning_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[MULTI_LINK_WARNING]%s()/%d Cannot find matched ap.\n";
    uVar4 = 0xda;
  }
  printf(__format,"multi_link_status_switch_by_inner",uVar4);
  return 0xffffffff;
}

