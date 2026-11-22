// func scan_passthrough_waitting_result_list @ 0050b238 size=368

void scan_passthrough_waitting_result_list(void)

{
  int iVar1;
  int iVar2;
  int extraout_v1;
  
  scan_waitting_result_list_timerid = 0xffffffff;
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_wairting_result_list_ock\n",
           "scan_passthrough_waitting_result_list",0x16f);
  }
  pthread_mutex_lock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
  FUN_00407e70();
  iVar2 = FUN_004081b0(&g_ac_passthrough_waitting_result_list);
  while (iVar1 = iVar2, iVar1 != 0) {
    iVar2 = FUN_00408680(iVar1);
    if (((0 < *(int *)(iVar1 + 0xc)) && (0 < *(int *)(iVar1 + 0x10))) &&
       (0xb3 < extraout_v1 - *(int *)(iVar1 + 0x10))) {
      _ac_passthrough_response_clean_all_aps();
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
      g_ac_passthrough_waitting_result_cnt = g_ac_passthrough_waitting_result_cnt + -1;
    }
  }
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_wairting_result_list_ock\n",
           "scan_passthrough_waitting_result_list",0x182);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&ac_passthrough_wairting_result_list_ock);
  scan_waitting_result_list_timerid =
       FUN_00408340(0x1e,0,scan_passthrough_waitting_result_list,0,0,
                    "scan_passthrough_waitting_result_list",0x183);
  return;
}

