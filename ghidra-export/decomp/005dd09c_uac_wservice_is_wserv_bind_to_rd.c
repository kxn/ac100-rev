// func uac_wservice_is_wserv_bind_to_rd @ 005dd09c size=48

void uac_wservice_is_wserv_bind_to_rd(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = rdmngr_db_generate_rd_id(param_1,param_2);
  wserv_db_is_wserv_bind_to_rd(uVar1,param_3);
  return;
}

