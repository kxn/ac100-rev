// func _uac_mac_auth_sta_check_trigger @ 0044d114 size=232

undefined4 _uac_mac_auth_sta_check_trigger(void)

{
  undefined4 uVar1;
  
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_sta_check_trigger() begin.\n",
           "_uac_mac_auth_sta_check_trigger",0xcb);
  }
  if (g_sta_check_timer_id != -1) {
    FUN_00408060();
    g_sta_check_timer_id = -1;
  }
  uVar1 = 0;
  g_sta_check_timer_id =
       FUN_00408340(g_sta_check_timeout,0,_uac_mac_auth_sta_check_timeout,0,0,
                    "_uac_mac_auth_sta_check_trigger",0xd1);
  if ((g_sta_check_timer_id == -1) && (uVar1 = 0xffffffff, macauth_err_switch != 0)) {
    printf("[MACAUTH_ERROR]%s()/%d start sta check timer failed.\n",
           "_uac_mac_auth_sta_check_trigger",0xd4);
  }
  return uVar1;
}

