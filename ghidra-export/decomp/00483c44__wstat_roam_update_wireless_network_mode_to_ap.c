// func _wstat_roam_update_wireless_network_mode_to_ap @ 00483c44 size=368

undefined4 _wstat_roam_update_wireless_network_mode_to_ap(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (param_1 == 0) {
    if (wsta_roam_err_switch == '\0') {
      return 1;
    }
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d input error\n";
    uVar4 = 0xb6c;
LAB_00483d34:
    printf(pcVar2,"_wstat_roam_update_wireless_network_mode_to_ap",uVar4);
    return 1;
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_20);
  if (iVar1 == -1) {
    if (wsta_roam_err_switch == '\0') {
      return 1;
    }
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n";
    uVar4 = 0xb73;
    goto LAB_00483d34;
  }
  iVar1 = apmngr_db_get_addr_by_capacity
                    (*(undefined2 *)(param_1 + 0x10),&local_20,1,1,0x15f0000,1,0x48);
  if ((iVar1 == -1) || (local_18 == 0)) {
    uVar4 = 0;
    if (wsta_roam_debug_switch == '\0') goto LAB_00483cdc;
    pcVar2 = "[WSTA_ROAM_DEBUG]%s()/%d no AP need to send configure\n";
    uVar3 = 0xb79;
  }
  else {
    uVar4 = 0;
    iVar1 = _wsta_intelligent_roam_set_wireless_network_mode_send(&local_20);
    if ((iVar1 != -1) || (uVar4 = 1, wsta_roam_err_switch == '\0')) goto LAB_00483cdc;
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d send packet to AP failed\n";
    uVar3 = 0xb80;
  }
  printf(pcVar2,"_wstat_roam_update_wireless_network_mode_to_ap",uVar3);
LAB_00483cdc:
  serv_wtp_address_arg_destroy(&local_20);
  return uVar4;
}

