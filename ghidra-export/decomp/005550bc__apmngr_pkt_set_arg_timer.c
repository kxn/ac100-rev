// func _apmngr_pkt_set_arg_timer @ 005550bc size=176

undefined4
_apmngr_pkt_set_arg_timer
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined2 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = 0xffffffff;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_20);
  if (iVar1 == 0) {
    iVar1 = serv_wtp_address_arg_add
                      (&local_20,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
    if ((iVar1 == 0) && (iVar1 = serv_timer_set(&local_20,1,param_8), iVar1 == 0)) {
      uVar2 = 0;
    }
  }
  serv_wtp_address_arg_destroy(&local_20);
  return uVar2;
}

