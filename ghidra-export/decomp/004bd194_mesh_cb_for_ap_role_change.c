// func mesh_cb_for_ap_role_change @ 004bd194 size=776

undefined4 mesh_cb_for_ap_role_change(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_28 = 0;
  local_24 = 0;
  if (param_2 == 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(param_2 + 0x14);
  if ((iVar1 == 4) || (iVar1 == 8)) {
    uVar3 = *(undefined2 *)(param_2 + 0x18);
LAB_004bd308:
    local_20 = CONCAT22(uVar3,uVar3);
  }
  else if (iVar1 == 6) {
    uVar3 = *(undefined2 *)(param_2 + 0x18);
    goto LAB_004bd308;
  }
  iVar2 = *(int *)(param_1 + 0x14);
  if ((((iVar2 == 4) || (iVar2 == 8)) || (iVar2 == 6)) &&
     (((iVar1 == 1 || (iVar1 == 3)) || (iVar1 == 2)))) {
LAB_004bd2a0:
    iVar1 = mesh_db_ap_entry_delete(*(undefined2 *)(param_2 + 0x10));
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x14);
    }
    else if (mesh_err_switch == '\0') {
      iVar1 = *(int *)(param_1 + 0x14);
    }
    else {
      printf("[MESH_ERROR]%s()/%d Delete ap entry(%d) failed\n","mesh_cb_for_ap_role_change",0x144,
             (uint)*(ushort *)(param_2 + 0x10));
      iVar1 = *(int *)(param_1 + 0x14);
    }
    if (((iVar1 == 4) || (iVar1 == 8)) || (iVar1 == 6)) {
      memcpy(&local_28,(void *)(param_2 + 0x48),6);
      mesh_pkt_re_operation_request_send((int)*(short *)(param_1 + 0x18),1,&local_28,3);
      iVar1 = *(int *)(param_2 + 0x14);
    }
    else {
      iVar1 = *(int *)(param_2 + 0x14);
    }
    if ((iVar1 == 1) || (iVar1 == 3)) {
      uVar3 = *(undefined2 *)(param_2 + 0x10);
    }
    else if (iVar1 == 2) {
      uVar3 = *(undefined2 *)(param_2 + 0x10);
    }
    else {
      uVar3 = *(undefined2 *)(param_2 + 0x18);
    }
    mesh_pkt_tmp_re_roam_timer_start(uVar3);
    iVar1 = *(int *)(param_1 + 0x14);
  }
  else if (((iVar2 == 1) || (iVar2 == 3)) || (iVar2 == 2)) {
    if (((iVar1 == 4) || (iVar1 == 8)) || (iVar1 == 6)) goto LAB_004bd2a0;
    iVar1 = *(int *)(param_1 + 0x14);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14);
  }
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_2 + 0x14);
LAB_004bd424:
    if ((iVar2 != 1) && (iVar2 != 3)) {
      if (iVar2 == 2) {
        iVar1 = *(int *)(param_2 + 0x14);
        goto LAB_004bd3b8;
      }
      goto LAB_004bd250;
    }
  }
  else {
    if ((iVar1 == 4) || (iVar1 == 8)) {
      iVar2 = *(int *)(param_2 + 0x14);
      goto LAB_004bd424;
    }
    if (iVar1 == 6) {
      iVar2 = *(int *)(param_2 + 0x14);
      goto LAB_004bd424;
    }
LAB_004bd250:
    if (((iVar1 != 1) && (iVar1 != 3)) && (iVar1 != 2)) {
      return 0;
    }
    iVar1 = *(int *)(param_2 + 0x14);
    if ((iVar1 == 4) || (iVar1 == 8)) goto LAB_004bd3b8;
    if (iVar1 != 6) {
      return 0;
    }
  }
  iVar1 = *(int *)(param_2 + 0x14);
LAB_004bd3b8:
  bVar4 = true;
  if ((iVar1 != 1) && (iVar1 != 3)) {
    bVar4 = iVar1 == 2;
  }
  iVar1 = mesh_db_ap_entry_add(*(undefined2 *)(param_2 + 0x10),bVar4,&local_20,0);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_2 + 0x14);
    if (((iVar1 == 4) || (iVar1 == 8)) || (uVar5 = 0, iVar1 == 6)) {
      uVar5 = 0;
      memcpy(&local_28,(void *)(param_2 + 0x48),6);
      mesh_pkt_re_operation_request_send((int)*(short *)(param_2 + 0x18),1,&local_28,2);
    }
  }
  else {
    uVar5 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Add ap entry(%d) failed\n","mesh_cb_for_ap_role_change",0x153,
             (uint)*(ushort *)(param_2 + 0x10));
    }
  }
  return uVar5;
}

