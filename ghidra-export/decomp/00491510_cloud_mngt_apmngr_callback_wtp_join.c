// func cloud_mngt_apmngr_callback_wtp_join @ 00491510 size=136

undefined4 cloud_mngt_apmngr_callback_wtp_join(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_apmngr_callback_wtp_join start\n",
           "cloud_mngt_apmngr_callback_wtp_join",0xd69);
  }
  uVar1 = notify_ap_onoffline_handle(param_1);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_apmngr_callback_wtp_join end\n",
           "cloud_mngt_apmngr_callback_wtp_join",0xd6b);
  }
  return uVar1;
}

