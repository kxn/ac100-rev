// func _wportal_common_free_strategy_arg_add @ 0040be48 size=132

void _wportal_common_free_strategy_arg_add(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_1 != 0) {
    FUN_004082d0(wportal_free_strategy_packet_mutex,0xffffffff);
    if (param_2 == 0) {
      puVar1 = &free_strategy_arg_nosupp;
    }
    else {
      puVar1 = &free_strategy_arg;
    }
    serv_wtp_address_arg_move(puVar1,param_1);
    FUN_00407f30(wportal_free_strategy_packet_mutex);
    return;
  }
  return;
}

