// func stats_db_callback_wtp_leave @ 00669ce4 size=256

undefined4 stats_db_callback_wtp_leave(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (puVar1 = (undefined2 *)FUN_00408450(2,0xa7e), puVar1 == (undefined2 *)0x0))
  {
    uVar3 = 0xffffffff;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d stats_db_callback_wtp_leave fail\n",
             "stats_db_callback_wtp_leave",0xa80);
    }
  }
  else {
    *puVar1 = *(undefined2 *)(param_1 + 0x10);
    uVar3 = 0;
    iVar2 = FUN_00408340(0,10000,stats_db_callback_wtp_leave_async,puVar1,
                         stats_db_callback_wtp_leave_arg_free,"stats_db_callback_wtp_leave",0xa85);
    if (iVar2 == -1) {
      if (stats_err_switch != '\0') {
        printf("[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n","stats_db_callback_wtp_leave",
               0xa88);
      }
      FUN_00407df0(puVar1);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

