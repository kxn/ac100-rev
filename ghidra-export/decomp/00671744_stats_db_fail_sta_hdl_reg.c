// func stats_db_fail_sta_hdl_reg @ 00671744 size=28

undefined4 stats_db_fail_sta_hdl_reg(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    fail_sta_hdl = param_1;
  }
  return uVar1;
}

