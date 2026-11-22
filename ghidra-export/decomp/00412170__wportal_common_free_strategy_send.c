// func _wportal_common_free_strategy_send @ 00412170 size=188

void _wportal_common_free_strategy_send(void)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  serv_wtp_address_arg_init(&local_18);
  _wportal_common_free_strategy_arg_copy_out(&local_18,1);
  _wportal_common_free_strategy_send_to_wtp(&local_18,1,1);
  serv_wtp_address_arg_clear(&local_18);
  FUN_004082d0(wportal_free_strategy_packet_mutex,0xffffffff);
  serv_wtp_address_arg_move(&local_18,&free_strategy_arg_v6);
  FUN_00407f30(wportal_free_strategy_packet_mutex);
  _wportal_common_free_strategy_send_to_wtp(&local_18,1,2);
  serv_wtp_address_arg_clear(&local_18);
  _wportal_common_free_strategy_arg_copy_out(&local_18,0);
  _wportal_common_free_strategy_send_to_wtp(&local_18,0,1);
  serv_wtp_address_arg_destroy(&local_18);
  return;
}

