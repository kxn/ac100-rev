// func wips_counter_reset_send @ 004c6560 size=152

void wips_counter_reset_send(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_2e0 [20];
  int local_2cc;
  
  memset(auStack_2e0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e0);
  if ((iVar1 != -1) && (local_2cc == 7)) {
    if (sensor_debug_switch != '\0') {
      printf("[SENSOR_DEBUG]%s()/%d wips_counter_reset_send[ap_id=%d]: {\"method\":\"do\",\"wireless_counter\":{\"reset\":{}}}\n"
             ,"wips_counter_reset_send",0x43f,param_1);
    }
    sensor_pkt_tdcp_send(param_1,"{\"method\":\"do\",\"wireless_counter\":{\"reset\":{}}}");
  }
  return;
}

