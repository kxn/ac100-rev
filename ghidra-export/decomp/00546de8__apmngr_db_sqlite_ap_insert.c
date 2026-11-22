// func _apmngr_db_sqlite_ap_insert @ 00546de8 size=456

undefined4 _apmngr_db_sqlite_ap_insert(int param_1)

{
  bool bVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  char acStack_418 [1024];
  
  memset(acStack_418,0,0x400);
  iVar4 = *(int *)(param_1 + 0x3c);
  _apmngr_ap_cfg_insert_sql_gene(acStack_418,0x400,param_1);
  bVar1 = iVar4 != 1;
  iVar4 = FUN_00407d60((&g_apmngr_db)[bVar1],acStack_418);
  if (iVar4 == 0) {
    _apmngr_ap_run_insert_sql_gene(acStack_418,0x400,param_1);
    iVar4 = FUN_00407d60(DAT_007c58e8,acStack_418);
    if (iVar4 == 0) {
      return 0;
    }
    if (apmngr_err_switch == '\0') {
      iVar4 = *(int *)(param_1 + 0x3c);
    }
    else {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x3c);
      }
      else {
        printf("[APMNGR_ERROR]%s()/%d Failed to insert to AP-entry table, roll back.\n",
               "_apmngr_db_sqlite_ap_insert",0x24a);
        iVar4 = *(int *)(param_1 + 0x3c);
      }
    }
    if (iVar4 == 1) {
      pcVar2 = "ApEntryCfg_table";
    }
    else {
      pcVar2 = "ApEntryTmpCfg_table";
    }
    snprintf(acStack_418,0x400,"DELETE FROM %s WHERE entry_id = %d;",pcVar2,
             (uint)*(ushort *)(param_1 + 0x10));
    iVar4 = FUN_00407d60((&g_apmngr_db)[bVar1],acStack_418);
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[APMNGR_ERROR]%s()/%d Severe Error: delete ap-cfg-entry failed even when roll back.\n"
    ;
    uVar3 = 0x250;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[APMNGR_ERROR]%s()/%d Failed to insert to AP-entry table.\n";
    uVar3 = 0x243;
  }
  printf(pcVar2,"_apmngr_db_sqlite_ap_insert",uVar3);
  return 0xffffffff;
}

