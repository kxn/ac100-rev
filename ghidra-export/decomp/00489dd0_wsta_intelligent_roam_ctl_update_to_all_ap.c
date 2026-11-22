// func wsta_intelligent_roam_ctl_update_to_all_ap @ 00489dd0 size=348

undefined4 wsta_intelligent_roam_ctl_update_to_all_ap(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_20);
  if (iVar1 == -1) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n",
           "wsta_intelligent_roam_ctl_update_to_all_ap",0xcb7);
    return 0xffffffff;
  }
  if (param_1 == 0) {
    iVar1 = apmngr_db_get_all_addr_by_capacity(&local_20,1,1,0x15f0000,1,0x19);
  }
  else {
    iVar1 = apmngr_db_get_all_addr_by_capacity(&local_20,1,1,0x15f0000,2,0x19,0x35);
  }
  if ((iVar1 == -1) || (local_18 == 0)) {
    uVar3 = 0;
    if (wsta_roam_debug_switch == '\0') goto LAB_00489e5c;
    __format = "[WSTA_ROAM_DEBUG]%s()/%d no AP need to send configure\n";
    uVar2 = 0xcbf;
  }
  else {
    uVar3 = 0;
    iVar1 = _wsta_intelligent_roam_ctl_packet_send(&local_20);
    if ((iVar1 != -1) || (uVar3 = 0xffffffff, wsta_roam_err_switch == '\0')) goto LAB_00489e5c;
    __format = "[WSTA_ROAM_ERROR]%s()/%d send packet to AP failed\n";
    uVar2 = 0xcc5;
  }
  printf(__format,"wsta_intelligent_roam_ctl_update_to_all_ap",uVar2);
LAB_00489e5c:
  serv_wtp_address_arg_destroy(&local_20);
  return uVar3;
}

