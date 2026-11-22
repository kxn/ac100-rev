// func bcast_storm_ctrl_cfg_get @ 0045f8c8 size=248

undefined4 bcast_storm_ctrl_cfg_get(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    if (bcast_storm_ctrl_cfg_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : input config invalid.\n";
    uVar3 = 0x1b8;
  }
  else {
    if (l_bcast_storm_ctrl_cfg != (undefined4 *)0x0) {
      FUN_004082d0(l_bcast_storm_ctrl_cfg_mutex,0xffffffff);
      puVar1 = l_bcast_storm_ctrl_cfg;
      uVar3 = l_bcast_storm_ctrl_cfg_mutex;
      *param_1 = *l_bcast_storm_ctrl_cfg;
      param_1[2] = puVar1[2];
      param_1[1] = puVar1[1];
      FUN_00407f30(uVar3);
      return 0;
    }
    if (bcast_storm_ctrl_cfg_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : config not init in memory yet.\n";
    uVar3 = 0x1be;
  }
  printf(__format,"bcast_storm_ctrl_cfg_get",uVar3);
  return 0xffffffff;
}

