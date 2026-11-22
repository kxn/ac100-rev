// func _apmngr_pkt_config_status_req_listen @ 0055516c size=568

undefined4 _apmngr_pkt_config_status_req_listen(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined2 local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380;
  undefined4 local_37c;
  undefined4 local_378;
  undefined4 local_374;
  undefined4 local_370;
  char acStack_36c [64];
  char acStack_32c [68];
  undefined1 auStack_2e8 [232];
  undefined1 local_200;
  char acStack_1f4 [32];
  char acStack_1d4 [452];
  
  pcVar3 = acStack_36c;
  local_380 = 0;
  local_37c = 0;
  local_378 = 0;
  local_374 = 0;
  local_370 = 0;
  local_394 = 0;
  local_390 = 0;
  local_38c = 0;
  local_388 = 0;
  local_384 = 0;
  memset(pcVar3,0,0x80);
  local_3a0 = 0;
  local_39c = 0;
  local_398 = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_2e8);
  if (iVar2 == 0) {
    local_3a0 = CONCAT11(0x14,local_200);
    strncpy(pcVar3,acStack_1f4,0x3f);
    strncpy(acStack_32c,acStack_1d4,0x3f);
    local_39c = 0x6f;
    local_398 = 0x2e;
    FUN_0051ad88(&local_378);
    FUN_0051ad88(&local_38c);
    uVar4 = 0x3d;
    iVar2 = cw_service_msg_add(param_3,0x25,&local_380,1,0x3d,pcVar3);
    if (((iVar2 == 0) &&
        (iVar2 = cw_service_msg_add(param_3,0xc,&local_3a0,0,uVar4,pcVar3), iVar2 == 0)) &&
       (iVar2 = cw_service_msg_add(param_3,0x25,&local_394,1,0x26,&local_39c), iVar2 == 0)) {
      if (apmngr_pkt_switch == '\0') {
        uVar1 = *(undefined2 *)(param_2 + 0x24);
      }
      else {
        capwap_parsed_packet_dump(param_3);
        uVar1 = *(undefined2 *)(param_2 + 0x24);
      }
      iVar2 = _apmngr_pkt_set_arg_timer
                        (*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                         *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                         *(undefined4 *)(param_2 + 0x20),uVar1,param_2,local_200);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if (apmngr_err_switch != '\0') {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar3 = "[APMNGR_ERROR]%s()/%d Failed to send config-status-request.\n";
      uVar4 = 0x782;
      goto LAB_005552ec;
    }
  }
  else if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    pcVar3 = "[APMNGR_DEBUG]%s()/%d Cannot find the ap entry.\n";
    uVar4 = 0x762;
LAB_005552ec:
    printf(pcVar3,"_apmngr_pkt_config_status_req_listen",uVar4);
    return 0xffffffff;
  }
  return 0xffffffff;
}

