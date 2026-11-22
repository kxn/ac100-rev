// func ucl_auth_cloud_client_register @ 004a4710 size=904

undefined4 ucl_auth_cloud_client_register(void)

{
  FILE *pFVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_390 [56];
  undefined1 auStack_358 [72];
  undefined1 auStack_310 [55];
  undefined1 auStack_2d9 [73];
  undefined1 auStack_290 [61];
  undefined1 auStack_253 [67];
  char acStack_210 [512];
  
  memset(acStack_210,0,0x200);
  memcpy(auStack_290,"lua /lib/ucl_auth/notify_cloud_online_status.sh report_basic",0x3d);
  memset(auStack_253,0,0x43);
  memcpy(auStack_310,"lua /lib/ucl_auth/notify_cloud_online_status.sh online",0x37);
  memset(auStack_2d9,0,0x49);
  memcpy(auStack_390,"lua /lib/ucl_auth/notify_cloud_online_status.sh offline",0x38);
  memset(auStack_358,0,0x48);
  snprintf(acStack_210,0x200,
           "ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"%s\",\"wait_time\":0,\"type\":\"%s\",\"action\":\"%s\"}\' &> /dev/null"
           ,auStack_290,"report_basic","add");
  if (ucl_info_switch != 0) {
    printf("[UCL_AUTH_INFO]%s()/%d %s\n","ucl_auth_cloud_client_register",0x45c,acStack_210);
  }
  pFVar1 = popen(acStack_210,"r");
  if (pFVar1 == (FILE *)0x0) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x461;
    __format = "[UCL_AUTH_ERR]%s()/%d Register report_basic action to cloud client failed.\n";
  }
  else {
    pclose(pFVar1);
    snprintf(acStack_210,0x200,
             "ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"%s\",\"wait_time\":0,\"type\":\"%s\",\"action\":\"%s\"}\' &> /dev/null"
             ,auStack_310,"online","add");
    if (ucl_info_switch != 0) {
      printf("[UCL_AUTH_INFO]%s()/%d %s\n","ucl_auth_cloud_client_register",0x469,acStack_210);
    }
    pFVar1 = popen(acStack_210,"r");
    if (pFVar1 == (FILE *)0x0) {
      if (ucl_err_switch == 0) {
        return 0xffffffff;
      }
      uVar2 = 0x46e;
      __format = "[UCL_AUTH_ERR]%s()/%d Register online action to cloud client failed.\n";
    }
    else {
      pclose(pFVar1);
      snprintf(acStack_210,0x200,
               "ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"%s\",\"wait_time\":0,\"type\":\"%s\",\"action\":\"%s\"}\' &> /dev/null"
               ,auStack_390,"offline","add");
      if (ucl_info_switch != 0) {
        printf("[UCL_AUTH_INFO]%s()/%d %s\n","ucl_auth_cloud_client_register",0x476,acStack_210);
      }
      pFVar1 = popen(acStack_210,"r");
      if (pFVar1 == (FILE *)0x0) {
        if (ucl_err_switch == 0) {
          return 0xffffffff;
        }
        uVar2 = 0x47b;
        __format = "[UCL_AUTH_ERR]%s()/%d Register offline action to cloud client failed.\n";
      }
      else {
        pclose(pFVar1);
        pFVar1 = popen("ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"echo  3\",\"wait_time\":0,\"type\":\"feature\",\"action\":\"add\"}\' &> /dev/null"
                       ,"r");
        if (pFVar1 != (FILE *)0x0) {
          pclose(pFVar1);
          return 0;
        }
        if (ucl_err_switch == 0) {
          return 0xffffffff;
        }
        uVar2 = 0x484;
        __format = "[UCL_AUTH_ERR]%s()/%d Register feature report to cloud client failed.\n";
      }
    }
  }
  printf(__format,"ucl_auth_cloud_client_register",uVar2);
  return 0xffffffff;
}

