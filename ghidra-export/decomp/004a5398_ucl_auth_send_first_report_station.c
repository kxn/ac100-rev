// func ucl_auth_send_first_report_station @ 004a5398 size=352

undefined4 ucl_auth_send_first_report_station(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int local_28;
  char *local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_24 = (char *)0x0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_28 = 0;
  if (param_1 == 0) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x126;
    __format = "[UCL_AUTH_ERR]%s()/%d Para is invalid.\n";
  }
  else {
    if (ucl_info_switch != 0) {
      printf("[UCL_AUTH_INFO]%s()/%d First report request message: %s\n",
             "ucl_auth_send_first_report_station",0x12a,param_1);
    }
    local_14 = 0;
    local_24 = "/tums/ucl/v1/reportUclAuthTerminal";
    local_1c = 0;
    local_18 = 0;
    local_20 = param_1;
    iVar1 = sendto_business_by_short_link(&local_24,&local_28);
    if (iVar1 == 0) {
      if (local_28 == 0) {
        return 0;
      }
      if (ucl_warn_switch == 0) {
        return 0xffffffff;
      }
      printf("[UCL_AUTH_WARN]%s()/%d Error code is %d.\n","ucl_auth_send_first_report_station",0x136
            );
      return 0xffffffff;
    }
    if (ucl_warn_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x13d;
    __format = "[UCL_AUTH_WARN]%s()/%d Report first report station to NMS failed.\n";
  }
  printf(__format,"ucl_auth_send_first_report_station",uVar2);
  return 0xffffffff;
}

