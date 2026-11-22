// func mesh_wtp_packet_send @ 004bcc94 size=1280

undefined4 mesh_wtp_packet_send(uint param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 *puVar7;
  char local_7b8 [4];
  int local_7b4;
  int local_7b0;
  undefined4 local_7ac;
  uint local_7a8;
  undefined1 auStack_7a4 [52];
  char local_770;
  int local_768;
  undefined2 local_764 [50];
  undefined2 local_700 [152];
  undefined1 auStack_5d0 [72];
  undefined2 local_588;
  undefined2 local_586;
  undefined2 local_584;
  undefined1 auStack_2f8 [16];
  undefined2 local_2e8;
  int local_2e4;
  undefined2 local_2e0;
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_7a4,0,0x3c);
  memset(auStack_5d0,0,0x2d8);
  memset(&local_768,0,0x68);
  memset(local_700,0,300);
  local_7a8 = 0;
  local_7b8[0] = '\0';
  local_7ac = 0;
  local_7b0 = 0;
  local_7b4 = 0;
  iVar2 = apmngr_db_entry_get_by_id(param_1,auStack_2f8);
  if (iVar2 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[MESH_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar5 = 0x719;
    goto LAB_004bcfc8;
  }
  if (((local_2e4 == 1) || (local_2e4 == 3)) || (local_2e4 == 2)) {
    puVar7 = local_764;
    iVar6 = 0;
    iVar2 = 0;
    mesh_db_ap_entry_child_foreach_proc(param_1,0,_mesh_cb_child_collect,&local_768);
    while (iVar6 < local_768) {
      iVar3 = apmngr_db_entry_get_by_id(*puVar7,auStack_5d0);
      if (iVar3 == -1) {
        if (mesh_warning_switch == '\0') goto LAB_004bce58;
        printf("[MESH_WARNING]%s()/%d get ap entry by id failed.\n","mesh_wtp_packet_send",0x723);
        iVar6 = iVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      else {
        local_700[iVar2 * 3] = local_588;
        local_700[iVar2 * 3 + 1] = local_586;
        local_700[iVar2 * 3 + 2] = local_584;
        iVar2 = iVar2 + 1;
LAB_004bce58:
        iVar6 = iVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    mesh_db_re_auto_add_state_get(&local_7b0);
    if (local_7b0 == 1) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d re_auto_add_state=%d, no need to send re_list\n",
               "mesh_wtp_packet_send",0x72c,1);
      }
      iVar2 = mesh_pkt_re_operation_request_send(param_1,0,local_700,4);
      if (iVar2 != 0) {
        if (mesh_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[MESH_ERROR]%s()/%d Send re list failed\n";
        uVar5 = 0x72f;
        goto LAB_004bcfc8;
      }
    }
    else {
      iVar2 = mesh_pkt_re_operation_request_send(param_1,iVar2,local_700,4);
      if (iVar2 != 0) {
        if (mesh_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[MESH_ERROR]%s()/%d Send re list failed\n";
        uVar5 = 0x737;
        goto LAB_004bcfc8;
      }
    }
    iVar2 = mesh_db_mesh_enable_get(&local_7b4);
    if (((iVar2 == 0) && (local_7b4 != 0)) && (local_2e4 - 2U < 2)) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d ap(%u) role %d ap mesh witch open \n","mesh_wtp_packet_send",
               0x741,param_1,local_2e4);
      }
      apmngr_db_ap_mesh_switch_update(param_1,1);
    }
    iVar2 = ap_mesh_switch_is_enable(param_1);
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d ap(%u) role %d ap mesh witch  \n","mesh_wtp_packet_send",0x74a,
             param_1,(uint)(iVar2 != 0));
    }
    iVar2 = mesh_pkt_enable_request_send(param_1,(uint)(iVar2 != 0));
    if (iVar2 != 0) {
      if (mesh_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = "[MESH_ERROR]%s()/%d Send mesh switch failed\n";
      uVar5 = 0x74d;
      goto LAB_004bcfc8;
    }
  }
  uVar4 = local_2e8;
  if (((local_2e4 == 1) || (uVar4 = local_2e8, local_2e4 == 3)) ||
     ((uVar4 = local_2e8, local_2e4 == 2 ||
      (((uVar4 = local_2e0, local_2e4 == 4 || (local_2e4 == 8)) || (local_2e4 == 6)))))) {
    iVar2 = mesh_db_ap_entry_get(uVar4,auStack_7a4);
    if ((iVar2 != 0) || (iVar2 = mesh_db_re_auto_switch_get(&local_7a8), iVar2 != 0)) {
      if (mesh_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = "[MESH_ERROR]%s()/%d Get auto switch failed\n";
      uVar5 = 0x75d;
      goto LAB_004bcfc8;
    }
    bVar1 = local_7a8 == 0;
    local_7a8 = 1;
    if (bVar1) {
      local_7a8 = (uint)(local_770 != '\0');
    }
    iVar2 = mesh_pkt_auto_switch_request_send(param_1,local_7a8,1);
    if (iVar2 != 0) {
      if (mesh_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = "[MESH_ERROR]%s()/%d Send auto switch failed\n";
      uVar5 = 0x763;
      goto LAB_004bcfc8;
    }
  }
  iVar2 = mesh_db_bh_work_mode_get(&local_7ac);
  if ((iVar2 == 0) && (iVar2 = mesh_pkt_bh_work_mode_send(param_1,local_7ac), iVar2 == 0)) {
    iVar2 = mesh_db_mesh_wan_status_get(local_7b8);
    if ((iVar2 == 0) &&
       (iVar2 = mesh_pkt_wan_status_request_send(param_1,(int)local_7b8[0]), iVar2 == 0)) {
      return 0;
    }
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[MESH_ERROR]%s()/%d Send wan status failed\n";
    uVar5 = 0x76f;
  }
  else {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[MESH_ERROR]%s()/%d Send bh_work_mode failed\n";
    uVar5 = 0x769;
  }
LAB_004bcfc8:
  printf(__format,"mesh_wtp_packet_send",uVar5);
  return 0xffffffff;
}

