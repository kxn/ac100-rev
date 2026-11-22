// func _mesh_pkt_join_req_listen @ 004c1838 size=1772

undefined4 _mesh_pkt_join_req_listen(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int *piVar7;
  int iVar8;
  void *__src;
  int iVar9;
  char *pcVar10;
  uint extraout_v1;
  uint extraout_v1_00;
  undefined4 uVar11;
  ushort uVar12;
  undefined4 local_a20;
  undefined2 local_a1c;
  undefined4 local_a18;
  undefined4 local_a14;
  undefined4 local_a10;
  undefined4 local_a0c;
  undefined1 auStack_a08 [128];
  int local_988;
  undefined1 auStack_8a0 [18];
  undefined2 local_88e;
  int local_88c;
  ushort local_888;
  undefined2 local_878;
  undefined4 local_874;
  undefined4 local_870;
  undefined4 local_864;
  undefined4 local_860;
  undefined4 local_85c;
  undefined4 local_858;
  undefined2 local_854;
  undefined1 auStack_852 [227];
  undefined1 local_76f;
  undefined1 auStack_76e [65];
  undefined1 auStack_72d [69];
  undefined4 local_6e8;
  undefined4 local_6e4;
  undefined4 local_6e0;
  undefined1 local_6dc;
  undefined1 auStack_5c8 [16];
  ushort local_5b8;
  undefined2 local_5b6;
  int local_5b4;
  uint local_344;
  int local_31c;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0 [2];
  int local_2dc;
  short local_2d8;
  undefined4 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined2 local_2a4;
  undefined1 auStack_2a2 [227];
  undefined1 local_1bf;
  undefined1 auStack_1be [65];
  undefined1 auStack_17d [69];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 local_12c;
  undefined1 auStack_d8 [192];
  
  memset(auStack_2f0,0,0x2d8);
  memset(auStack_5c8,0,0x2d8);
  memset(auStack_a08,0,0x168);
  local_a18 = 0;
  local_a14 = 0;
  local_a10 = 0;
  local_a0c = 0;
  piVar7 = (int *)cw_msg_ele_val_get(param_3,0x21);
  if ((piVar7 != (int *)0x0) && (*piVar7 != 0)) {
    if (mesh_debug_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_DEBUG]%s()/%d Failed to join for formal callback return failed result code.\n",
           "_mesh_pkt_join_req_listen",0x13e);
    return 0xffffffff;
  }
  iVar8 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x76);
  __src = (void *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x5b);
  if (__src == (void *)0x0) {
    local_a18 = 0xffffffff;
    local_a14 = 0xffffffff;
    local_a10 = 0xffffffff;
    local_a0c = 0xffffffff;
  }
  else {
    memcpy(&local_a18,__src,0x10);
  }
  iVar9 = apmngr_db_entry_get_by_mac(param_2,auStack_2f0);
  uVar11 = local_2b0;
  if (iVar9 != 0) {
    if (iVar8 == 0) {
      return 0;
    }
    pcVar10 = (char *)cw_priv_mesh_private_control_get(iVar8,0x10);
    if (pcVar10 == (char *)0x0) {
      return 0;
    }
    if (*pcVar10 != '\x01') {
      return 0;
    }
    iVar8 = apmngr_db_entry_get_by_mac(pcVar10 + 1,auStack_5c8);
    if (((iVar8 == 0) && (((local_5b4 == 1 || (local_5b4 == 3)) || (local_5b4 == 2)))) &&
       (local_31c - 2U < 2)) {
      if (param_2[0xc] != 0) {
        return 0;
      }
      FUN_00407e70();
      if ((local_344 <= extraout_v1) && (10 < extraout_v1 - local_344)) {
        return 0;
      }
    }
    if (mesh_warning_switch == '\0') goto LAB_004c1b40;
    bVar1 = param_2[1];
    bVar2 = *param_2;
    pcVar10 = 
    "[MESH_WARNING]%s()/%d Illegal join of AP [%02x:%02x:%02x:%02x:%02x:%02x] because CAP not exist or not in running state\n"
    ;
    bVar3 = param_2[2];
    uVar11 = 0x1d7;
    bVar4 = param_2[3];
    bVar5 = param_2[4];
    bVar6 = param_2[5];
LAB_004c1e24:
    printf(pcVar10,"_mesh_pkt_join_req_listen",uVar11,(uint)bVar2,(uint)bVar1,(uint)bVar3,
           (uint)bVar4,(uint)bVar5,(uint)bVar6);
LAB_004c1b40:
    FUN_004c10bc(param_3);
    return 0xffffffff;
  }
  if (((local_2dc != 1) && (local_2dc != 3)) &&
     ((local_2dc != 2 && (((local_2dc != 4 && (local_2dc != 8)) && (local_2dc != 6)))))) {
    if (local_2dc != 5) {
      return 0;
    }
    if (param_2[0xc] == 0) {
      return 0;
    }
    iVar8 = apmngr_db_entry_get_by_mac(param_2 + 6,auStack_5c8);
    if (iVar8 != 0) {
      return 0;
    }
    if ((uint)local_5b8 == (int)local_2d8) {
      return 0;
    }
LAB_004c19a4:
    apmngr_ap_disconnect(local_2e0,1,0);
    apmngr_ap_capid_update(local_2e0[0],local_5b8);
    return 0;
  }
  iVar9 = apdb_get_ap_by_id(local_2b0,&local_a18,auStack_a08);
  if (iVar9 != 0) {
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Cannot find apdb of model %d.\n","_mesh_pkt_join_req_listen",0x154
             ,uVar11);
    }
    goto LAB_004c1b40;
  }
  if ((iVar8 == 0) ||
     (pcVar10 = (char *)cw_priv_mesh_private_control_get(iVar8,0x10), pcVar10 == (char *)0x0)) {
joined_r0x004c1b58:
    if (((local_2dc != 4) && (local_2dc != 8)) && (local_2dc != 6)) {
      return 0;
    }
    iVar8 = 2;
    if ((local_988 != 3) && (iVar8 = 3, local_988 != 1)) {
      iVar8 = 1;
    }
    uVar12 = 0xffff;
  }
  else {
    if (*pcVar10 != '\x01') {
      if (*pcVar10 != '\0') {
        return 0;
      }
      goto joined_r0x004c1b58;
    }
    FUN_00407e70();
    iVar8 = apmngr_db_entry_get_by_mac(pcVar10 + 1,auStack_5c8);
    if (((iVar8 != 0) ||
        ((((local_5b4 != 1 && (local_5b4 != 3)) && (local_5b4 != 2)) || (1 < local_31c - 2U)))) ||
       ((param_2[0xc] == 0 && ((extraout_v1_00 < local_344 || (extraout_v1_00 - local_344 < 0xb)))))
       ) {
      if (mesh_warning_switch == '\0') goto LAB_004c1b40;
      bVar1 = param_2[1];
      bVar2 = *param_2;
      pcVar10 = "[MESH_WARNING]%s()/%d Illegal join of AP [%02x:%02x:%02x:%02x:%02x:%02x]\n";
      bVar3 = param_2[2];
      uVar11 = 0x1bb;
      bVar4 = param_2[3];
      bVar5 = param_2[4];
      bVar6 = param_2[5];
      goto LAB_004c1e24;
    }
    if (((local_2dc != 1) && (local_2dc != 3)) && (local_2dc != 2)) {
      if ((uint)local_5b8 == (int)local_2d8) {
        return 0;
      }
      goto LAB_004c19a4;
    }
    iVar8 = 5;
    if (local_988 == 1) {
      if (param_2[0xc] == 0) {
        iVar8 = 6;
      }
    }
    else {
      iVar8 = 8;
      if (local_988 != 3) {
        iVar8 = 4;
      }
    }
    uVar12 = local_5b8;
    if (iVar8 == 4) goto LAB_004c1bac;
  }
  if (((iVar8 != 8) && (iVar8 != 5)) && (iVar8 != 6)) {
    apmngr_ap_disconnect(local_2e0,1,0);
    apmngr_ap_role_update(local_2e0[0],iVar8,uVar12);
    mesh_pkt_tmp_re_roam_timer_start(local_2e0[0]);
    return 0;
  }
LAB_004c1bac:
  if (mesh_warning_switch != '\0') {
    printf("[MESH_WARNING]%s()/%d AP [%02x:%02x:%02x:%02x:%02x:%02x]\'s role changed from CAP to RE\n"
           ,"_mesh_pkt_join_req_listen",0x1c3,(uint)*param_2,(uint)param_2[1],(uint)param_2[2],
           (uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
  }
  memset(auStack_8a0,0,0x2d8);
  local_a20 = 0;
  local_a1c = 0;
  FUN_00407e80("_mesh_cap_change_to_re");
  mesh_db_ap_entry_child_foreach_proc(local_2e0[0],0,_mesh_cb_child_capid_clear,0);
  mesh_pkt_tmp_re_roam_timer_start(local_5b8);
  apmngr_ap_delete(local_2e0,1,1,0x3cf3,1);
  apmngr_db_entry_init(auStack_8a0,auStack_d8,local_2b0,4);
  local_888 = local_5b8;
  local_864 = local_2b4;
  local_88e = local_5b6;
  local_878 = 0;
  local_860 = local_2b0;
  local_874 = 0xffffffff;
  local_870 = 0xffffffff;
  local_858 = local_2a8;
  local_854 = local_2a4;
  local_85c = local_2ac;
  local_88c = iVar8;
  memcpy(auStack_852,auStack_2a2,0x9a);
  local_6e8 = local_138;
  local_76f = local_1bf;
  memcpy(auStack_76e,auStack_1be,0x41);
  memcpy(auStack_72d,auStack_17d,0x41);
  local_6e4 = local_134;
  local_6e0 = local_130;
  local_6dc = local_12c;
  apmngr_ap_add(auStack_8a0,auStack_d8,0,0,1);
  FUN_004082b0(local_2b4,"_mesh_cap_change_to_re");
  local_a20 = local_2a8;
  local_a1c = local_2a4;
  mesh_pkt_re_operation_request_send(local_5b8,1,&local_a20,2);
  return 0;
}

