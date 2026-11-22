// func _wportal_wserv_del_notify @ 004213d4 size=124

undefined4 _wportal_wserv_del_notify(undefined4 param_1)

{
  int iVar1;
  
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Wservise del notify: wserv_id: %d\n","_wportal_wserv_del_notify",
           0x2e75,param_1);
  }
  if (g_portal_auth_mode == 0) {
    FUN_004212c8(param_1);
  }
  return 0;
}

