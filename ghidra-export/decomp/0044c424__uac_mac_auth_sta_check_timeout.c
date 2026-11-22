// func _uac_mac_auth_sta_check_timeout @ 0044c424 size=92

void _uac_mac_auth_sta_check_timeout(void)

{
  undefined4 uVar1;
  
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_sta_check() begin.\n",
           "_uac_mac_auth_sta_check_timeout",0xc5);
  }
  g_sta_check_timer_id = 0xffffffff;
  uVar1 = wsta_profile_get_max_wstation();
  wsta_db_sta_for_each_range(0,uVar1,_uac_mac_auth_sta_check,0);
  return;
}

