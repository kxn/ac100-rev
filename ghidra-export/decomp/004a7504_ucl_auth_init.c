// func ucl_auth_init @ 004a7504 size=716

undefined4 ucl_auth_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_40 [4];
  char acStack_3c [32];
  code *local_1c;
  undefined4 local_18;
  code *local_14;
  undefined4 local_10;
  
  iVar1 = ucl_auth_db_init();
  if (iVar1 == -1) {
    if (ucl_err_switch == 0) goto LAB_004a7674;
    uVar2 = 0x528;
    __format = "[UCL_AUTH_ERR]%s()/%d Ucl auth db init failed.\n";
  }
  else {
    iVar1 = jcs_callback_register("ucl_auth",2,ucl_auth_config_set);
    if (iVar1 == 0) {
      iVar1 = ucl_auth_cloud_client_register();
      if (iVar1 == -1) {
        if (ucl_err_switch == 0) goto LAB_004a7674;
        uVar2 = 0x534;
        __format = "[UCL_AUTH_ERR]%s()/%d Ucl auth register to cloud client failed.\n";
      }
      else {
        memset(acStack_3c,0,0x30);
        snprintf(acStack_3c,0x20,"ucl_sta_unauth");
        local_1c = (code *)0xa;
        local_10 = 0;
        local_18 = 1;
        local_14 = ucl_auth_sta_unauth;
        iVar1 = wportal_db_event_register(acStack_3c);
        if (iVar1 == -1) {
          if (ucl_err_switch != 0) {
            printf("[UCL_AUTH_ERR]%s()/%d Ucl auth register to wportal failed.\n",
                   "ucl_auth_wportal_register",0x4ad);
          }
          if (ucl_err_switch == 0) goto LAB_004a7674;
          uVar2 = 0x53a;
          __format = "[UCL_AUTH_ERR]%s()/%d Ucl auth register to wportal failed.\n";
        }
        else {
          memset(acStack_3c,0,0x24);
          snprintf(acStack_3c,0x20,"ucl_online_report");
          local_1c = ucl_auth_report_online_station_cb;
          iVar1 = radius_result_check_register(acStack_3c);
          if (iVar1 == -1) {
            if (ucl_err_switch != 0) {
              printf("[UCL_AUTH_ERR]%s()/%d Ucl auth register to radius failed.\n",
                     "ucl_auth_radius_register",0x4be);
            }
            if (ucl_err_switch == 0) goto LAB_004a7674;
            uVar2 = 0x540;
            __format = "[UCL_AUTH_ERR]%s()/%d Ucl auth register to radius failed.\n";
          }
          else {
            iVar1 = uac_thread_create(auStack_40,"ucl_auth_thread",ucl_auth_report_thread,0);
            if (iVar1 == 0) {
              return 0;
            }
            if (ucl_err_switch == 0) goto LAB_004a7674;
            uVar2 = 0x546;
            __format = "[UCL_AUTH_ERR]%s()/%d Create ucl auth offline report thread failed.\n";
          }
        }
      }
    }
    else {
      if (ucl_err_switch == 0) goto LAB_004a7674;
      uVar2 = 0x52e;
      __format = "[UCL_AUTH_ERR]%s()/%d Ucl auth jcs init failed.\n";
    }
  }
  printf(__format,"ucl_auth_init",uVar2);
LAB_004a7674:
  ucl_auth_fini();
  return 0xffffffff;
}

