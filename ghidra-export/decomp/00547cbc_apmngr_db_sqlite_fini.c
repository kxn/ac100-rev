// func apmngr_db_sqlite_fini @ 00547cbc size=300

void apmngr_db_sqlite_fini(void)

{
  int iVar1;
  int iVar2;
  
  if (g_apmngr_sqlite_thread_start != 0) {
    iVar1 = pthread_kill(g_apmngr_sqlite_thread,3);
    if ((iVar1 == 0) || (apmngr_err_switch == '\0')) {
      g_apmngr_sqlite_thread_start = 0;
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        g_apmngr_sqlite_thread_start = 0;
      }
      else {
        printf("[APMNGR_ERROR]%s()/%d %d.\n\n","apmngr_db_sqlite_fini",0x660,iVar1);
        g_apmngr_sqlite_thread_start = 0;
      }
    }
  }
  if (g_apmngr_db != 0) {
    FUN_004080b0();
    g_apmngr_db = 0;
  }
  if (DAT_007c58e8 != 0) {
    FUN_004080b0();
    DAT_007c58e8 = 0;
  }
  if (apmngr_msg_mutex != 0) {
    FUN_00408360();
  }
  if (apmngr_msg_cond != 0) {
    FUN_00408220();
  }
  while (iVar1 = FUN_004081b0(&g_apmngr_msg_list), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(*(undefined4 *)(iVar1 + 0x10));
    FUN_00407df0(iVar1);
  }
  return;
}

