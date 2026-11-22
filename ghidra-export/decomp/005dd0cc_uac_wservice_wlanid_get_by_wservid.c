// func uac_wservice_wlanid_get_by_wservid @ 005dd0cc size=48

void uac_wservice_wlanid_get_by_wservid(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = rdmngr_db_generate_rd_id(param_1,param_2);
  wserv_db_wlanid_get_by_wservid(uVar1,param_3);
  return;
}

