// func uac_wservice_for_ap_bind_vlan @ 005dda30 size=24

undefined4 uac_wservice_for_ap_bind_vlan(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    uVar1 = wserv_db_for_ap_bind_vlan();
    return uVar1;
  }
  return 0;
}

