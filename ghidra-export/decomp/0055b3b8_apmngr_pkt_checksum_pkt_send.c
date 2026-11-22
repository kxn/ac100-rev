// func apmngr_pkt_checksum_pkt_send @ 0055b3b8 size=328

undefined4 apmngr_pkt_checksum_pkt_send(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == (void *)0x0) {
    return 0xffffffff;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 != 0) {
    FUN_0051ad88(&local_28);
    memcpy(&local_40,param_2,0x10);
    iVar3 = cw_service_msg_add(iVar2,0x25,&local_30,1,0x41,&local_40);
    if (iVar3 == 0) {
      if (apmngr_pkt_switch != '\0') {
        capwap_parsed_packet_dump(iVar2);
      }
      iVar3 = capwap_packet_assemble(iVar1,iVar2);
      if (iVar3 != -1) {
        cw_parsed_pkt_destroy(iVar2);
        uVar4 = serv_packet_send(param_1,iVar1,1);
        goto LAB_0055b4b4;
      }
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  uVar4 = 0xffffffff;
LAB_0055b4b4:
  cw_pkt_buf_destroy(iVar1);
  return uVar4;
}

