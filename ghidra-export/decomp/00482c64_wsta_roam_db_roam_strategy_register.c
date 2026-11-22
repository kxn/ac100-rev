// func wsta_roam_db_roam_strategy_register @ 00482c64 size=160

undefined4 wsta_roam_db_roam_strategy_register(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (wsta_roam_warning_switch != '\0') {
      printf("[WSTA_ROAM_WARNING]%s()/%d Input error!\n","wsta_roam_db_roam_strategy_register",0x459
            );
    }
  }
  else {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    piVar1 = &wsta_roam_strategy_fun + strategy_reg_num;
    strategy_reg_num = strategy_reg_num + 1;
    *piVar1 = param_1;
    uVar2 = 0;
    FUN_00407f30(l_wsta_roam_data);
  }
  return uVar2;
}

