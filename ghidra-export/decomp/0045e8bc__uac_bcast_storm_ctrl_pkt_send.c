// func _uac_bcast_storm_ctrl_pkt_send @ 0045e8bc size=776

undefined4 _uac_bcast_storm_ctrl_pkt_send(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    if (bcast_storm_ctrl_error_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[BCAST_STORM_CTRL_ERROR]%s()/line %d : input arg error.\n";
    uVar5 = 0xaa;
LAB_0045ea2c:
    printf(pcVar4,"_uac_bcast_storm_ctrl_pkt_send",uVar5);
    return 0xffffffff;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    if (bcast_storm_ctrl_error_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[BCAST_STORM_CTRL_ERROR]%s()/line %d : create capwap packet buffer failed.\n";
    uVar5 = 0xb1;
    goto LAB_0045ea2c;
  }
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 == 0) {
    if (bcast_storm_ctrl_error_switch != 0) {
      printf("[BCAST_STORM_CTRL_ERROR]%s()/line %d : malloc for CW_PARSED_PKT failed.\n",
             "_uac_bcast_storm_ctrl_pkt_create",0x60);
    }
LAB_0045ea54:
    if (bcast_storm_ctrl_error_switch == 0) goto LAB_0045ea60;
    pcVar4 = 
    "[BCAST_STORM_CTRL_ERROR]%s()/line %d : create broadcast storm control packet buffer failed.\n";
    uVar5 = 0xb7;
  }
  else {
    local_2c = 0x12345678;
    local_28 = CONCAT22(0x46,local_28._2_2_);
    FUN_0051ad88(&local_24);
    bcast_storm_ctrl_cfg_get(&local_38);
    local_3c = local_30;
    local_40 = CONCAT13((char)local_34,local_40._1_3_);
    iVar3 = cw_service_msg_add(iVar2,0x25,&local_2c,1,0x46,&local_40);
    if (iVar3 != 0) {
      if (bcast_storm_ctrl_error_switch != 0) {
        pcVar4 = "[BCAST_STORM_CTRL_ERROR]%s()/line %d : add msg element failed.\n";
        uVar5 = 0x77;
LAB_0045e9c8:
        printf(pcVar4,"_uac_bcast_storm_ctrl_pkt_create",uVar5);
      }
LAB_0045ea48:
      cw_parsed_pkt_destroy(iVar2);
      goto LAB_0045ea54;
    }
    if (bcast_storm_ctrl_debug_switch != 0) {
      printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : add msg element success.\n",
             "_uac_bcast_storm_ctrl_pkt_create",0x7a);
    }
    iVar3 = capwap_packet_assemble(iVar1,iVar2);
    if (iVar3 != 0) {
      if (bcast_storm_ctrl_error_switch != 0) {
        pcVar4 = "[BCAST_STORM_CTRL_ERROR]%s()/line %d : assemble packet buffer failed.\n";
        uVar5 = 0x80;
        goto LAB_0045e9c8;
      }
      goto LAB_0045ea48;
    }
    if (bcast_storm_ctrl_debug_switch != 0) {
      printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : create parsed_pkt success.\n",
             "_uac_bcast_storm_ctrl_pkt_create",0x83);
    }
    cw_parsed_pkt_destroy(iVar2);
    if (bcast_storm_ctrl_debug_switch != 0) {
      printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : create packet buffer success.\n",
             "_uac_bcast_storm_ctrl_pkt_send",0xba);
    }
    iVar2 = serv_packet_send(param_1,iVar1,1);
    if (iVar2 == 0) {
      if (bcast_storm_ctrl_debug_switch != 0) {
        printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : send packet buffer success.\n",
               "_uac_bcast_storm_ctrl_pkt_send",0xc1);
      }
      cw_pkt_buf_destroy(iVar1);
      return 0;
    }
    if (bcast_storm_ctrl_error_switch == 0) goto LAB_0045ea60;
    pcVar4 = "[BCAST_STORM_CTRL_ERROR]%s()/line %d : send packet buffer failed.\n";
    uVar5 = 0xbe;
  }
  printf(pcVar4,"_uac_bcast_storm_ctrl_pkt_send",uVar5);
LAB_0045ea60:
  cw_pkt_buf_destroy(iVar1);
  return 0xffffffff;
}

