// func _sensor_pkt_wtp_event_req_listen @ 004ea218 size=284

undefined4 _sensor_pkt_wtp_event_req_listen(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  int local_2dc;
  
  memset(auStack_2f0,0,0x2d8);
  puVar1 = (undefined4 *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x83);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  if ((param_1 != 0) && (sensor_pkt_dump_switch != '\0')) {
    capwap_parsed_packet_dump(param_1);
  }
  iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_2f0);
  if (iVar2 == 0) {
    if (local_2dc == 7) {
      sensor_tdcp_confirm(local_2e0,*puVar1);
      return 0;
    }
    uVar4 = 0;
    if (sensor_warning_switch == '\0') {
      return 0;
    }
    __format = "[SENSOR_WARNING]%s()/%d Not sensor,ignore the packet.\n";
    uVar3 = 0x196;
  }
  else {
    uVar4 = 0xffffffff;
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_ERROR]%s()/%d apmngr_db_entry_get_by_mac() fail.\n";
    uVar3 = 0x191;
  }
  printf(__format,"_sensor_pkt_wtp_event_req_listen",uVar3);
  return uVar4;
}

