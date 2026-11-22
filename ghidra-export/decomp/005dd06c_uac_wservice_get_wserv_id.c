// func uac_wservice_get_wserv_id @ 005dd06c size=48

void uac_wservice_get_wserv_id(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = rdmngr_db_generate_rd_id(param_1,param_2);
  wserv_db_rd_get_wserv_id(uVar1,param_3);
  return;
}

