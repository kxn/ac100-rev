// func wsta_intelligent_roam_update_all_ap_rd_cfg @ 00489b4c size=20

void wsta_intelligent_roam_update_all_ap_rd_cfg(undefined4 param_1)

{
  apmngr_db_foreach_proc(0x15f0000,_wsta_intelligent_roam_set_rd_cfg,param_1);
  return;
}

