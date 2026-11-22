// func ucl_auth_report_online_station @ 004a6928 size=144

undefined4
ucl_auth_report_online_station(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (0x32 < param_2)) {
    uVar1 = 0xffffffff;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Para is invalid.\n","ucl_auth_report_online_station",0x255);
    }
  }
  else {
    uVar1 = ucl_auth_fill_online_station
                      (param_1,param_2,ucl_auth_send_online_station,param_3,param_4);
  }
  return uVar1;
}

