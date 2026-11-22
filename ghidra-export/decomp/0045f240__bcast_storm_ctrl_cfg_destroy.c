// func _bcast_storm_ctrl_cfg_destroy @ 0045f240 size=92

void _bcast_storm_ctrl_cfg_destroy(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_00407df0();
    return;
  }
  if ((bcast_storm_ctrl_cfg_warning_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[BCAST_STORM_CTRL_CFG_WARNING]%s()/line %d : you want to free null pointer.\n",
           "_bcast_storm_ctrl_cfg_destroy",0xb9);
    return;
  }
  return;
}

