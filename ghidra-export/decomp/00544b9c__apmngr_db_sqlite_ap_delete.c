// func _apmngr_db_sqlite_ap_delete @ 00544b9c size=292

undefined4 _apmngr_db_sqlite_ap_delete(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_410 [1024];
  
  memset(acStack_410,0,0x400);
  snprintf(acStack_410,0x400,"DELETE FROM %s WHERE entry_id = %d;","ApEntryCfg_table",param_1);
  iVar1 = FUN_00407d60(g_apmngr_db,acStack_410);
  if (iVar1 == 0) {
    snprintf(acStack_410,0x400,"DELETE FROM %s WHERE entry_id = %d;","ApEntryRun_table",param_1);
    iVar1 = FUN_00407d60(DAT_007c58e8,acStack_410);
    if (iVar1 == 0) {
      return 0;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x387;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x381;
  }
  printf("[APMNGR_ERROR]%s()/%d Failed to delete ap entry.\n","_apmngr_db_sqlite_ap_delete",uVar2);
  return 0xffffffff;
}

