// func bcast_storm_ctrl_cfg_rate_get @ 0045f73c size=232

undefined4 bcast_storm_ctrl_cfg_rate_get(undefined4 *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    if (bcast_storm_ctrl_cfg_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = 
    "[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : input pointer bcast_storm_ctrl_rate null.\n";
    uVar2 = 0x17c;
  }
  else {
    if (l_bcast_storm_ctrl_cfg != 0) {
      FUN_004082d0(l_bcast_storm_ctrl_cfg_mutex,0xffffffff);
      uVar2 = l_bcast_storm_ctrl_cfg_mutex;
      *param_1 = *(undefined4 *)(l_bcast_storm_ctrl_cfg + 8);
      FUN_00407f30(uVar2);
      return 0;
    }
    if (bcast_storm_ctrl_cfg_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : config not init in memory yet.\n";
    uVar2 = 0x182;
  }
  printf(__format,"bcast_storm_ctrl_cfg_rate_get",uVar2);
  return 0xffffffff;
}

