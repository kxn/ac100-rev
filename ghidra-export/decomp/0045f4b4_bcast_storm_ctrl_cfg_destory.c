// func bcast_storm_ctrl_cfg_destory @ 0045f4b4 size=76

undefined4 bcast_storm_ctrl_cfg_destory(void)

{
  _bcast_storm_ctrl_cfg_destroy(l_bcast_storm_ctrl_cfg);
  l_bcast_storm_ctrl_cfg = 0;
  if (l_bcast_storm_ctrl_cfg_mutex != 0) {
    FUN_00408360();
    l_bcast_storm_ctrl_cfg_mutex = 0;
  }
  return 0;
}

