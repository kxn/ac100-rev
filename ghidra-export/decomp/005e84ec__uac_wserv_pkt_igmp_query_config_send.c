// func _uac_wserv_pkt_igmp_query_config_send @ 005e84ec size=304

undefined4 _uac_wserv_pkt_igmp_query_config_send(int param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_30 = 0;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 != 0) {
    FUN_0051ad88(&local_24);
    local_30 = CONCAT22(param_2,CONCAT11(param_3,(undefined1)local_30));
    iVar3 = cw_service_msg_add(iVar2,0x25,&local_2c,1,0x72,&local_30);
    if (iVar3 == 0) {
      if (wserv_pkt_switch != '\0') {
        capwap_parsed_packet_dump(iVar2);
      }
      iVar3 = capwap_packet_assemble(iVar1,iVar2);
      if (iVar3 != -1) {
        cw_parsed_pkt_destroy(iVar2);
        uVar4 = serv_packet_send(param_1,iVar1,1);
        goto LAB_005e85e0;
      }
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  uVar4 = 0xffffffff;
LAB_005e85e0:
  cw_pkt_buf_destroy(iVar1);
  return uVar4;
}

