// func stats_callback_proc @ 0066c530 size=288

int stats_callback_proc(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0) {
    iVar1 = -1;
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d invalid event[%d].\n","stats_callback_proc",0x868,param_1);
    }
  }
  else {
    iVar1 = FUN_004081b0(&g_stats_cb_list);
    iVar2 = 0;
    for (; iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      if ((param_1 == 0) && (*(code **)(iVar1 + 0x14) != (code *)0x0)) {
        iVar2 = (**(code **)(iVar1 + 0x14))(param_2);
      }
      if ((iVar2 != 0) && (stats_err_switch != '\0')) {
        printf("[STATISTICS_ERROR]%s()/%d Failed to proc %d callback of [%s].\n",
               "stats_callback_proc",0x882,param_1,*(undefined4 *)(iVar1 + 0xc));
      }
    }
  }
  return iVar1;
}

