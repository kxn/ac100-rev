// func _apmngr_delete_wtp_session @ 00554a48 size=152

undefined4
_apmngr_delete_wtp_session
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined2 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar1 = serv_wtp_address_arg_init(&local_18);
  if (iVar1 == 0) {
    serv_wtp_address_arg_add(&local_18,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
    serv_session_delete(&local_18);
    serv_wtp_address_arg_destroy(&local_18);
  }
  return 0;
}

