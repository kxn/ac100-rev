// func band_navigation_packet_send @ 0055f040 size=516

undefined4 band_navigation_packet_send(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_1 == 0) {
    if (band_navigation_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[BAND_NAVIGATION_ERR]%s()/%d inputs error.\n","band_navigation_packet_send",0x75);
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
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 == 0) {
LAB_0055f120:
    if ((band_navigation_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_0055f130;
    __format = "[BAND_NAVIGATION_ERR]%s()/%d create packet failed\n";
    uVar4 = 0x81;
  }
  else {
    FUN_0051ad88(&local_28);
    band_navigation_db_get(&local_44);
    if (local_40 != 0) {
      local_48 = 0x1000000;
    }
    local_48 = CONCAT31(CONCAT21(CONCAT11(local_48._0_1_,(char)local_3c),(char)local_38),
                        (char)local_34);
    iVar3 = cw_service_msg_add(iVar2,0x25,&local_30,1,0x3a,&local_48);
    if ((iVar3 != 0) || (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 == -1)) {
      cw_parsed_pkt_destroy(iVar2);
      goto LAB_0055f120;
    }
    cw_parsed_pkt_destroy(iVar2);
    iVar2 = serv_packet_send(param_1,iVar1,1);
    if (iVar2 != -1) {
      cw_pkt_buf_destroy(iVar1);
      return 0;
    }
    if ((band_navigation_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_0055f130;
    __format = "[BAND_NAVIGATION_ERR]%s()/%d send packet failed.\n";
    uVar4 = 0x86;
  }
  printf(__format,"band_navigation_packet_send",uVar4);
LAB_0055f130:
  cw_pkt_buf_destroy(iVar1);
  return 0xffffffff;
}

