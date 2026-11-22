// func _apmngr_db_sqlite_ap_firm @ 00546af0 size=464

undefined4 _apmngr_db_sqlite_ap_firm(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  char acStack_410 [1028];
  
  memset(acStack_410,0,0x400);
  if (*(int *)(param_1 + 0x3c) == 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Not firmed entry.\n";
    uVar2 = 0x3a2;
  }
  else {
    _apmngr_ap_cfg_insert_sql_gene(acStack_410,0x400,param_1);
    iVar1 = FUN_00407d60(g_apmngr_db,acStack_410);
    if (iVar1 == 0) {
      snprintf(acStack_410,0x400,"DELETE FROM %s WHERE entry_id = %d;","ApEntryTmpCfg_table",
               (uint)*(ushort *)(param_1 + 0x10));
      iVar1 = FUN_00407d60(DAT_007c58e8,acStack_410);
      if (iVar1 == 0) {
        snprintf(acStack_410,0x400,
                 "UPDATE %s SET seq = (SELECT MAX(seq)+1 FROM %s), firm = 1 WHERE entry_id = %d;",
                 "ApEntryRun_table","ApEntryRun_table",(uint)*(ushort *)(param_1 + 0x10));
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
        printf("[APMNGR_ERROR]%s()/%d Failed to update run seq and firm of entry %d.\n",
               "_apmngr_db_sqlite_ap_firm",0x3bb,(uint)*(ushort *)(param_1 + 0x10));
        return 0xffffffff;
      }
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d Failed to delete ap entry.\n";
      uVar2 = 0x3b2;
    }
    else {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d Failed to insert to AP-entry table.\n";
      uVar2 = 0x3a9;
    }
  }
  printf(__format,"_apmngr_db_sqlite_ap_firm",uVar2);
  return 0xffffffff;
}

