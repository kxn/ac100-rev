// func _apmngr_db_sqlite_ap_capid_update @ 0054422c size=320

undefined4 _apmngr_db_sqlite_ap_capid_update(ushort *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_410 [1028];
  
  memset(acStack_410,0,0x400);
  snprintf(acStack_410,0x400,"UPDATE %s SET group_id = \'%d\' WHERE entry_id = %d;",
           "ApEntryRun_table",(uint)param_1[2],(uint)*param_1);
  iVar1 = FUN_00407d60(DAT_007c58e8,acStack_410);
  if (iVar1 == 0) {
    snprintf(acStack_410,0x400,
             "UPDATE %s SET group_id = \'%d\', cap_id = \'%d\' WHERE entry_id = %d;",
             "ApEntryCfg_table",(uint)param_1[2],(uint)param_1[1],(uint)*param_1);
    iVar1 = FUN_00407d60(g_apmngr_db,acStack_410);
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
    uVar2 = 0x281;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x275;
  }
  printf("[APMNGR_ERROR]%s()/%d Failed to update AP-entry table.\n",
         "_apmngr_db_sqlite_ap_capid_update",uVar2);
  return 0xffffffff;
}

