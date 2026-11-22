// func ucl_auth_db_set_notify_first_report @ 004a79f8 size=128

undefined4 ucl_auth_db_set_notify_first_report(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 1U < 4) {
    uVar1 = 0;
    notify_first_report = param_1;
  }
  else {
    uVar1 = 0xffffffff;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Para is invalid.\n","ucl_auth_db_set_notify_first_report",0xbb);
    }
  }
  return uVar1;
}

