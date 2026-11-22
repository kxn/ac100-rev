// func uac_wservice_get_vlan @ 005dd9bc size=64

void uac_wservice_get_vlan
               (undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = rdmngr_db_generate_rd_id(param_1,param_2);
  wserv_db_rd_get_bind_vlan_by_wlan_id(uVar1,param_3,param_4);
  return;
}

