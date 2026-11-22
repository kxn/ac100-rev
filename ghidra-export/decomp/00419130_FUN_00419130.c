// func FUN_00419130 @ 00419130 size=180

undefined4 FUN_00419130(int param_1,byte param_2)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_14 = 0x17;
  local_18 = 0;
  local_c = 0;
  local_10 = (uint)param_2 << 0x18;
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d set method: %d\n","_wportal_sync_auth_status",0x67f,local_14);
  }
  if (g_portal_auth_mode == 1) {
    local_c = *(int *)(param_1 + 0x134);
    if (local_c == 0xfff) {
      local_c = 0;
    }
    uac_wservice_for_each_ap_bind_vlan(local_c,_wportal_get_roam_sta_cb,&local_18);
  }
  return 0;
}

