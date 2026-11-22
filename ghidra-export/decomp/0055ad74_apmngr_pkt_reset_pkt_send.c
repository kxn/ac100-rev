// func apmngr_pkt_reset_pkt_send @ 0055ad74 size=336

undefined4 apmngr_pkt_reset_pkt_send(int param_1,uint param_2)

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
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (3 < param_2) {
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
  iVar2 = cw_parsed_pkt_create(0x11);
  if (iVar2 != 0) {
    uVar4 = 1;
    if (param_2 == 1) {
LAB_0055ae48:
      if (apmngr_pkt_switch != '\0') {
        capwap_parsed_packet_dump(iVar2);
      }
      iVar3 = capwap_packet_assemble(iVar1,iVar2);
      if (iVar3 != -1) {
        cw_parsed_pkt_destroy(iVar2);
        uVar4 = serv_packet_send(param_1,iVar1,1);
        goto LAB_0055ae88;
      }
    }
    else {
      FUN_0051ad88(&local_24);
      if (param_2 != 2) {
        uVar4 = 3;
      }
      local_30 = uVar4;
      iVar3 = cw_service_msg_add(iVar2,0x25,&local_2c,1,0x23,&local_30);
      if (iVar3 == 0) goto LAB_0055ae48;
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  uVar4 = 0xffffffff;
LAB_0055ae88:
  cw_pkt_buf_destroy(iVar1);
  return uVar4;
}

