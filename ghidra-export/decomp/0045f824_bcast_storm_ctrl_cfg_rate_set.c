// func bcast_storm_ctrl_cfg_rate_set @ 0045f824 size=164

undefined4 bcast_storm_ctrl_cfg_rate_set(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (l_bcast_storm_ctrl_cfg == 0) {
    uVar3 = 0xffffffff;
    if ((bcast_storm_ctrl_cfg_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : config not init in memory yet.\n",
             "bcast_storm_ctrl_cfg_rate_set",0x19d);
    }
  }
  else {
    FUN_004082d0(l_bcast_storm_ctrl_cfg_mutex,0xffffffff);
    uVar1 = l_bcast_storm_ctrl_cfg_mutex;
    uVar3 = 0;
    *(undefined4 *)(l_bcast_storm_ctrl_cfg + 8) = param_1;
    FUN_00407f30(uVar1);
  }
  return uVar3;
}

