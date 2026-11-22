// func cloud_mngt_rd_cfg_all_change_cb @ 004981d0 size=64

undefined4 cloud_mngt_rd_cfg_all_change_cb(undefined4 param_1)

{
  if (ap_report_switch != 0) {
    cloud_mngt_notify_report(9);
    _cloud_mngt_rd_cfg_changed(param_1);
  }
  return 0;
}

