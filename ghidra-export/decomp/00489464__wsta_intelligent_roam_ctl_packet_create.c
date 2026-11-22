// func _wsta_intelligent_roam_ctl_packet_create @ 00489464 size=612

undefined4 _wsta_intelligent_roam_ctl_packet_create(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 uStack_5c;
  char local_5b;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  char local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  char local_47;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  char local_35;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  char local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  memset(&local_38,0,0x24);
  memset(&uStack_5c,0,0x22);
  iVar1 = cw_parsed_pkt_create(7);
  if (iVar1 == 0) {
    if (wsta_roam_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[WSTA_ROAM_ERROR]%s()/%d cw_parsed_pkt_create failed\n",
           "_wsta_intelligent_roam_ctl_packet_create",0x986);
    return 0xffffffff;
  }
  FUN_0051ad88(&local_68);
  iVar2 = wsta_roam_db_cfg_get(&uStack_5c);
  if (iVar2 == -1) {
    if (wsta_roam_err_switch == '\0') goto LAB_004895d8;
    __format = "[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n";
    uVar3 = 0x990;
  }
  else {
    local_38 = local_51;
    local_37 = local_50;
    local_36 = local_4f;
    local_35 = local_5b;
    if (local_5b != '\x01') {
      local_35 = local_4e;
    }
    local_33 = local_4c;
    local_32 = local_4b;
    local_31 = local_4a;
    local_30 = local_49;
    local_2f = local_48;
    if (local_5b == '\x01') {
      local_2e = local_5b;
    }
    else {
      local_2e = local_47;
    }
    local_2c = local_45;
    local_2b = local_44;
    local_2a = local_43;
    local_29 = local_42;
    local_28 = local_41;
    local_27 = local_40;
    local_26 = local_3f;
    local_25 = local_3e;
    local_24 = wsta_roam_db_roam_strategy_get();
    iVar2 = cw_service_msg_add(iVar1,0x25,&local_70,1,0x57,&local_38);
    if (iVar2 == 0) {
      iVar2 = capwap_packet_assemble(param_1,iVar1);
      if (iVar2 != -1) {
        cw_parsed_pkt_destroy(iVar1);
        return 0;
      }
      if (wsta_roam_err_switch == '\0') goto LAB_004895d8;
      __format = "[WSTA_ROAM_ERROR]%s()/%d capwap_packet_assemble failed\n";
      uVar3 = 0x9c8;
    }
    else {
      if (wsta_roam_err_switch == '\0') goto LAB_004895d8;
      __format = "[WSTA_ROAM_ERROR]%s()/%d cw_service_msg_add failed\n";
      uVar3 = 0x9c1;
    }
  }
  printf(__format,"_wsta_intelligent_roam_ctl_packet_create",uVar3);
LAB_004895d8:
  cw_parsed_pkt_destroy(iVar1);
  return 0xffffffff;
}

