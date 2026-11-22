// func _wsta_intelligent_roam_set_wireless_network_mode_send @ 004839a0 size=676

undefined4 _wsta_intelligent_roam_set_wireless_network_mode_send(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 uStack_40;
  char local_3f;
  undefined1 local_3d;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined2 local_38;
  
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_58 = 0;
  memset(&uStack_40,0,0x22);
  iVar2 = wsta_roam_db_cfg_get(&uStack_40);
  if (iVar2 == -1) {
    if (wsta_roam_err_switch != '\0') {
      pcVar4 = "[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n";
      uVar5 = 0xa2c;
LAB_00483a9c:
      printf(pcVar4,"_wsta_intelligent_roam_set_wireless_network_mode_create",uVar5);
    }
LAB_00483a30:
    if (wsta_roam_err_switch == '\0') goto LAB_00483a40;
    pcVar4 = "[WSTA_ROAM_ERROR]%s()/%d create packet failed\n";
    uVar5 = 0xa70;
  }
  else {
    if (1 < (byte)(local_3f - 1U)) {
      if (wsta_roam_err_switch != '\0') {
        pcVar4 = "[WSTA_ROAM_ERROR]%s()/%d invalid ap mode\n";
        uVar5 = 0xa31;
        goto LAB_00483a9c;
      }
      goto LAB_00483a30;
    }
    iVar2 = cw_parsed_pkt_create(7);
    if (iVar2 == 0) {
      if (wsta_roam_err_switch != '\0') {
        pcVar4 = "[WSTA_ROAM_ERROR]%s()/%d cw_parsed_pkt_create failed\n";
        uVar5 = 0xa37;
        goto LAB_00483a9c;
      }
      goto LAB_00483a30;
    }
    local_54 = 0x12345678;
    local_50 = CONCAT22(0x9d,local_50._2_2_);
    FUN_0051ad88(&local_4c);
    if (local_3f == '\x01') {
      local_58 = CONCAT13(local_3a,local_58._1_3_);
      local_3c = local_38;
    }
    else {
      local_58 = CONCAT13(local_3d,local_58._1_3_);
    }
    local_58 = CONCAT22(local_58._0_2_,local_3c);
    iVar3 = cw_service_msg_add(iVar2,0x25,&local_54,1,0x9d,&local_58);
    if (iVar3 != 0) {
      if (wsta_roam_err_switch != '\0') {
        pcVar4 = "[WSTA_ROAM_ERROR]%s()/%d cw_service_msg_add failed\n";
        uVar5 = 0xa4d;
LAB_00483bc8:
        printf(pcVar4,"_wsta_intelligent_roam_set_wireless_network_mode_create",uVar5);
      }
LAB_00483b50:
      cw_parsed_pkt_destroy(iVar2);
      goto LAB_00483a30;
    }
    iVar3 = capwap_packet_assemble(iVar1,iVar2);
    if (iVar3 == -1) {
      if (wsta_roam_err_switch != '\0') {
        pcVar4 = "[WSTA_ROAM_ERROR]%s()/%d capwap_packet_assemble failed\n";
        uVar5 = 0xa54;
        goto LAB_00483bc8;
      }
      goto LAB_00483b50;
    }
    cw_parsed_pkt_destroy(iVar2);
    iVar2 = serv_packet_send(param_1,iVar1,1);
    if (iVar2 != -1) {
      cw_pkt_buf_destroy(iVar1);
      return 0;
    }
    if (wsta_roam_err_switch == '\0') goto LAB_00483a40;
    pcVar4 = "[WSTA_ROAM_ERROR]%s()/%d send packet failed.\n";
    uVar5 = 0xa75;
  }
  printf(pcVar4,"_wsta_intelligent_roam_set_wireless_network_mode_send",uVar5);
LAB_00483a40:
  cw_pkt_buf_destroy(iVar1);
  return 0xffffffff;
}

