// func cloud_mngt_apmngr_callback_wtp_name_changed @ 004913b0 size=136

undefined4 cloud_mngt_apmngr_callback_wtp_name_changed(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_apmngr_callback_wtp_name_changed start\n",
           "cloud_mngt_apmngr_callback_wtp_name_changed",0xd73);
  }
  uVar1 = notify_ap_onoffline_handle(param_1);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_apmngr_callback_wtp_name_changed end\n",
           "cloud_mngt_apmngr_callback_wtp_name_changed",0xd75);
  }
  return uVar1;
}

