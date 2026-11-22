// func apmngr_db_sqlite_init @ 00547a30 size=244

undefined4 apmngr_db_sqlite_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  apmngr_msg_mutex = FUN_00407f00("apmngr_sql_msg_mutex",0);
  if (apmngr_msg_mutex == 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Create apmngr msg mutex failed.\n";
    uVar2 = 0x61e;
  }
  else {
    apmngr_msg_cond = FUN_00407d80("apmngr_sql_msg_cond");
    if (apmngr_msg_cond != 0) {
      FUN_0051ad88(&g_apmngr_msg_list);
      FUN_00408620("/etc/nouci_config/dbs/apmngr.db",apmngr_db_sqlite_option_changed_node_num_get);
      return 0;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Create apmngr msg cond failed.\n";
    uVar2 = 0x625;
  }
  printf(__format,"apmngr_db_sqlite_init",uVar2);
  return 0xffffffff;
}

