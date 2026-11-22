// func stats_db_callback_wtp_leave_async @ 0066837c size=80

void stats_db_callback_wtp_leave_async(undefined4 param_1)

{
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  FUN_004082d0(l_stats_data,0xffffffff);
  FUN_00408570(DAT_007cc8e0,_stats_sta_ap_leave_handle,local_res0);
  FUN_00407f30(l_stats_data);
  return;
}

