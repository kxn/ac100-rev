// func wportal_db_ssid_rdt_exist @ 0043293c size=204

undefined4 wportal_db_ssid_rdt_exist(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((int)param_1 < 0) || (uVar1 = wserv_profile_get_max_wservice(), uVar1 <= param_1)) {
    uVar3 = 0xffffffff;
    if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d wserv_id is invalid: %d\n\n","wportal_db_ssid_rdt_exist",0x18d3,
             param_1);
    }
  }
  else {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    if (*(int *)(wportal_wserv_node + param_1 * 8 + 4) == 0) {
      uVar3 = 0xffffffff;
      FUN_00407f30(wportal_rdt_mutex);
    }
    else {
      uVar3 = 0;
      FUN_00407f30(wportal_rdt_mutex);
    }
  }
  return uVar3;
}

