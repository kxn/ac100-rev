// func uac_wservice_for_each_bind_vlan @ 005dda60 size=24

undefined4 uac_wservice_for_each_bind_vlan(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = wserv_db_for_each_bind_vlan();
    return uVar1;
  }
  return 0;
}

