// func _uac_dhcpdef_ap_enter_run_cb @ 00465d98 size=180

undefined4 _uac_dhcpdef_ap_enter_run_cb(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2e0 [12];
  uint local_2d4;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_ap_enter_run_cb",0x8d4,
           "_uac_dhcpdef_ap_enter_run_cb");
  }
  memset(auStack_2e0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e0);
  uVar2 = 0xffffffff;
  if ((iVar1 == 0) && (uVar2 = 0, local_2d4 < 3)) {
    iVar1 = _uac_dhcpdef_notify_ap(param_1,1);
    uVar2 = 0xffffffff;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

