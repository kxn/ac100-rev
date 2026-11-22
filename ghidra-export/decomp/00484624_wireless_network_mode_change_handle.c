// func wireless_network_mode_change_handle @ 00484624 size=476

undefined4 wireless_network_mode_change_handle(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 uStack_438;
  undefined1 local_437;
  char acStack_414 [1028];
  
  memset(acStack_414,0,0x400);
  if (param_1 - 1U < 2) {
    memset(&uStack_438,0,0x22);
    iVar1 = wsta_roam_db_cfg_get(&uStack_438);
    if (iVar1 == -1) {
      if (wsta_roam_err_switch != '\0') {
        printf("[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n",
               "_wstat_roam_switch_cur_wirless_network_mode",0xb5d);
      }
      if (wsta_roam_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = "[WSTA_ROAM_ERROR]%s()/%d _wstat_roam_switch_wirless_network_mode failed.\n";
      uVar2 = 0xba6;
    }
    else {
      local_437 = (undefined1)param_1;
      wsta_roam_db_cfg_set(&uStack_438);
      snprintf(acStack_414,0x400,"uci set %s.%s.%s=%d;uci commit %s","apmng_roam",
               "wireless_network_mode","cur_wireless_network_mode",param_1,"apmng_roam");
      system(acStack_414);
      reset_acs_container();
      iVar1 = apmngr_db_foreach_proc(0x15f0000,_wstat_roam_update_wireless_network_mode_to_ap,0);
      if (iVar1 == -1) {
        if (wsta_roam_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = 
        "[WSTA_ROAM_ERROR]%s()/%d wsta_intelligent_roam_update_all_ap_wireless_network_mode failed.\n"
        ;
        uVar2 = 0xbb5;
      }
      else {
        iVar1 = apmngr_db_foreach_proc(0x15f0000,local_wsta_intelligent_roam_set_params_cb,0);
        if (iVar1 != -1) {
          return 0;
        }
        if (wsta_roam_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = 
        "[WSTA_ROAM_ERROR]%s()/%d wsta_intelligent_roam_update_all_ap_roam_params failed.\n";
        uVar2 = 0xbbb;
      }
    }
    printf(__format,"wireless_network_mode_change_handle",uVar2);
  }
  else if (wsta_roam_err_switch != '\0') {
    printf("[WSTA_ROAM_ERROR]%s()/%d invalid ap mode:%d.\n","wireless_network_mode_change_handle",
           0xba0,param_1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

