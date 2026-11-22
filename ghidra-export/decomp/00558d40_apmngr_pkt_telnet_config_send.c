// func apmngr_pkt_telnet_config_send @ 00558d40 size=304

undefined4 apmngr_pkt_telnet_config_send(int param_1,undefined1 param_2,undefined2 param_3)

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
    local_30 = CONCAT13(param_2,local_30._1_3_);
    local_30 = CONCAT22(local_30._0_2_,param_3);
    iVar3 = cw_service_msg_add(iVar2,0x25,&local_2c,1,0x9f,&local_30);
    if (iVar3 == 0) {
      if (apmngr_pkt_switch != '\0') {
        capwap_parsed_packet_dump(iVar2);
      }
      iVar3 = capwap_packet_assemble(iVar1,iVar2);
      if (iVar3 != -1) {
        cw_parsed_pkt_destroy(iVar2);
        uVar4 = serv_packet_send(param_1,iVar1,1);
        goto LAB_00558e34;
      }
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  uVar4 = 0xffffffff;
LAB_00558e34:
  cw_pkt_buf_destroy(iVar1);
  return uVar4;
}

