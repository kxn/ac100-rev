// func stats_db_auth_ok_sta_hdl_reg @ 00671760 size=28

undefined4 stats_db_auth_ok_sta_hdl_reg(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    auth_ok_sta_hdl = param_1;
  }
  return uVar1;
}

