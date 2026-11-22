// func uac_wserv_ssid_portal_switch_to_ap @ 005dffa0 size=288

undefined4 uac_wserv_ssid_portal_switch_to_ap(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> ap_id = %d\r\n","uac_wserv_ssid_portal_switch_to_ap",0x12f0,
           param_1);
  }
  local_1c = 0;
  local_18 = 0;
  uVar2 = 0;
  local_14 = 0;
  local_20 = param_1;
  FUN_0051ad88(&local_1c);
  uac_wservice_for_each_entry_bind_ap
            (param_1,_uac_wserv_for_collect_ssid_portal_switch_cb,&local_20);
  iVar1 = wserv_db_ssid_portal_switch(param_1,&local_1c);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, g_wserv_error != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wportal_update_ssid_portal_switch_to_ap failed\r\n",
           "uac_wserv_ssid_portal_switch_to_ap",0x12f9);
  }
  while (iVar1 = FUN_004081b0(&local_1c), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  return uVar2;
}

