// func _apmngr_jcs_ap_vlan_get @ 005537f4 size=92

undefined4 _apmngr_jcs_ap_vlan_get(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  short local_10 [4];
  
  local_10[0] = 0;
  wserv_db_rd_get_bind_vlan_by_wlan_id(*param_1,*(undefined1 *)(param_1 + 1),local_10);
  if (local_10[0] != 0) {
    uVar1 = json_object_new_int();
    json_object_array_add(param_3,uVar1);
  }
  return 0;
}

