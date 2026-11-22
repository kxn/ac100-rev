// func _apmngr_pkt_element_encap @ 00555818 size=1024

undefined4 _apmngr_pkt_element_encap(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined2 local_130;
  uint local_12c;
  int local_128;
  undefined4 local_124;
  uint local_120;
  undefined4 local_11c;
  uint local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined1 auStack_e4 [8];
  undefined1 auStack_dc [12];
  undefined1 auStack_d0 [20];
  undefined1 auStack_bc [20];
  char acStack_a8 [64];
  char acStack_68 [68];
  
  iVar7 = 3;
  memset(auStack_e4,0,0x3c);
  local_130 = 0;
  if (param_4 == 0) {
    iVar7 = 2;
  }
  iVar6 = 0;
  local_118 = 0;
  local_114 = 0;
  local_fc = 0;
  local_f8 = 0;
  local_f4 = 0;
  local_f0 = 0;
  local_ec = 0;
  local_e8 = 0;
  memset(acStack_a8,0,0x80);
  local_124 = 0;
  local_128 = 0;
  iVar1 = 0;
  do {
    iVar6 = iVar6 + 1;
    FUN_0051ad88(auStack_e4 + iVar1 + 8);
    iVar1 = iVar6 * 0x14;
  } while (iVar6 < iVar7);
  local_130 = CONCAT11(0x14,*(undefined1 *)(param_1 + 0x2a));
  local_118 = (uint)*(ushort *)((int)param_1 + 0xaa);
  local_114 = apmngr_db_get_echo_timeout();
  local_fc = param_1[0x2c];
  local_f8 = 300;
  if (param_4 == 0) {
    local_124 = param_1[0x2b];
  }
  else {
    strncpy(acStack_a8,(char *)(param_1 + 0x2d),0x3f);
    strncpy(acStack_68,(char *)(param_1 + 0x35),0x3f);
    local_124 = param_1[0x2b];
  }
  iVar7 = apdb_get_ext_wire_phy_by_id(*param_1,param_2 + 0x10,&local_128);
  if (iVar7 != 0) {
    local_128 = 0;
  }
  iVar7 = cw_service_msg_add(param_3,0x25,auStack_e4,1,5,&local_118);
  if (iVar7 == 0) {
    uVar4 = 0x3c;
    puVar8 = &local_fc;
    iVar7 = cw_service_msg_add(param_3,0x25,auStack_d0,1,0x3c,puVar8);
    if (((iVar7 != 0) ||
        (iVar7 = cw_service_msg_add(param_3,0xc,&local_130,0,uVar4,puVar8), iVar7 != 0)) ||
       (iVar1 = cw_service_msg_add(param_3,0x17,&local_124,0,uVar4,puVar8), iVar7 = local_128,
       iVar1 != 0)) goto LAB_00555958;
    local_12c = 0;
    local_120 = 0;
    local_11c = 0;
    local_110 = 0;
    local_10c = 0;
    local_108 = 0;
    local_104 = 0;
    local_100 = 0;
    if (0 < local_128) {
      if (local_128 == 1) {
        local_12c = (uint)*(ushort *)(param_1 + 0x3a);
        puVar5 = &local_12c;
      }
      else {
        if (2 < local_128 - 2U) goto LAB_00555b6c;
        local_120 = param_1[0x3a];
        local_11c = param_1[0x3b];
        puVar5 = &local_120;
      }
      FUN_0051ad88(&local_108);
      uVar4 = 0x30;
      if (iVar7 != 1) {
        uVar4 = 0x43;
      }
      iVar7 = cw_service_msg_add(param_3,0x25,&local_110,1,uVar4,puVar5);
      if (iVar7 != 0) {
        if ((apmngr_err_switch != '\0') && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
          printf("[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements for config status response.\n"
                 ,"_apmngr_pkt_phy_wired_vlan_encap",0x65e);
        }
        goto LAB_00555958;
      }
    }
LAB_00555b6c:
    if ((param_4 == 0) ||
       (iVar7 = cw_service_msg_add(param_3,0x25,auStack_bc,1,0x3d,acStack_a8), iVar7 == 0)) {
      uVar4 = 0;
      if (apmngr_debug_switch == '\0') {
        return 0;
      }
      iVar7 = is_target_debug_ap();
      if (iVar7 == 0) {
        return 0;
      }
      pcVar2 = "[APMNGR_DEBUG]%s()/%d Success to encap Config Status elements.\n";
      uVar3 = 0x74d;
      goto LAB_00555b5c;
    }
    if ((apmngr_err_switch != '\0') && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      pcVar2 = "[APMNGR_ERROR]%s()/%d add AP user failed.\n";
      uVar4 = 0x749;
      goto LAB_00555b3c;
    }
  }
  else {
LAB_00555958:
    if ((apmngr_err_switch != '\0') && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      pcVar2 = "[APMNGR_ERROR]%s()/%d add AP\'s configure failed.\n";
      uVar4 = 0x743;
LAB_00555b3c:
      printf(pcVar2,"_apmngr_pkt_element_encap",uVar4);
    }
  }
  uVar4 = 0xffffffff;
  if (apmngr_err_switch == '\0') {
    return 0xffffffff;
  }
  iVar7 = is_target_debug_ap();
  if (iVar7 == 0) {
    return 0xffffffff;
  }
  pcVar2 = 
  "[APMNGR_ERROR]%s()/%d Failed to insert vendor-specific elements for config status response.\n";
  uVar3 = 0x751;
LAB_00555b5c:
  printf(pcVar2,"_apmngr_pkt_element_encap",uVar3);
  return uVar4;
}

