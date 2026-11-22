// func apmngr_ap_telnet_port_update @ 0052c1ac size=84

undefined4 apmngr_ap_telnet_port_update(undefined2 param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = 0;
  local_10 = 0;
  apmngr_db_telnet_enable_get(&local_18);
  local_10 = CONCAT22(param_1,local_10._2_2_);
  local_14 = local_18;
  apmngr_db_foreach_proc(0xffffffff,_apmngr_send_to_telnet_ap,&local_14);
  return 0;
}

