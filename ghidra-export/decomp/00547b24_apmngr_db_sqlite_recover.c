// func apmngr_db_sqlite_recover @ 00547b24 size=408

undefined4 apmngr_db_sqlite_recover(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00408130("/etc/nouci_config/dbs/apmngr.db",&g_apmngr_db,
                       uac_cfg_trigger_changed_by_restore);
  if (iVar1 == 0) {
    iVar1 = FUN_00408130("/tmp/apmngr_tmp.db",&DAT_007c58e8,uac_cfg_trigger_changed_by_restore);
    if (iVar1 == 0) {
      iVar1 = _apmngr_db_sql_try_create_table();
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      iVar1 = _apmngr_db_sql_recover();
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      apmngr_db_id_trim();
      iVar1 = FUN_004084e0(&g_apmngr_sqlite_thread,"tApmngr_sql",_apmngr_db_sqlite_thread_main,0);
      if (iVar1 == 0) {
        g_apmngr_sqlite_thread_start = 1;
        return 0;
      }
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[APMNGR_ERROR]%s()/%d Failed to create sqlite thread\n","apmngr_db_sqlite_recover",
             0x64c);
      return 0xffffffff;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    uVar2 = sqlite3_errmsg(DAT_007c58e8);
    uVar3 = 0x638;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    uVar2 = sqlite3_errmsg(g_apmngr_db);
    uVar3 = 0x634;
  }
  printf("[APMNGR_ERROR]%s()/%d Can\'t open database: %s/n\n","apmngr_db_sqlite_recover",uVar3,uVar2
        );
  return 0xffffffff;
}

