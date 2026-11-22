// func wsta_print_profile @ 0063a180 size=136

void wsta_print_profile(void)

{
  undefined4 uVar1;
  
  puts("########################################################");
  uVar1 = apmngr_db_get_ap_max();
  printf("WSTA_MAX_AP_SUPPORT        = %d\n",uVar1);
  printf("WSTA_MAX_STA_SUPPORT       = %d\n",l_wsta_profile);
  uVar1 = rdmngr_profile_get_max_wlan_per_rd();
  printf("WSTA_MAX_WLAN_PER_RD       = %d\n",uVar1);
  uVar1 = rdmngr_profile_get_max_rd_per_ap();
  printf("WSTA_MAX_RADIO_NUM_PER_AP  = %d\n",uVar1);
  puts("########################################################");
  return;
}

