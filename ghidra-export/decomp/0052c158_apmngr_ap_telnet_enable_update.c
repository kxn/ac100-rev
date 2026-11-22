// func apmngr_ap_telnet_enable_update @ 0052c158 size=84

undefined4 apmngr_ap_telnet_enable_update(undefined4 param_1)

{
  undefined2 local_18 [2];
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = 0;
  local_10 = 0;
  apmngr_db_telnet_port_get(local_18);
  local_10 = CONCAT22(local_18[0],local_10._2_2_);
  local_14 = param_1;
  apmngr_db_foreach_proc(0xffffffff,_apmngr_send_to_telnet_ap,&local_14);
  return 0;
}

