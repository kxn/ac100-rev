// func mesh_cb_for_ap_delete @ 004bd6f8 size=468

/* WARNING: Type propagation algorithm not settling */

undefined4 mesh_cb_for_ap_delete(int param_1)

{
  int iVar1;
  int local_80 [2];
  undefined2 local_78;
  int local_74;
  undefined1 auStack_70 [104];
  
  memset(&local_74,0,0x68);
  iVar1 = *(int *)(param_1 + 0x14);
  local_80[1] = 0;
  local_78 = 0;
  local_80[0] = 1;
  if (((iVar1 == 1) || (iVar1 == 3)) || (iVar1 == 2)) {
    iVar1 = mesh_db_discover_state_get();
    if (iVar1 != 0) {
      mesh_db_discover_list_delete_by_capid(*(undefined2 *)(param_1 + 0x10));
    }
    mesh_db_ap_entry_child_foreach_proc
              (*(undefined2 *)(param_1 + 0x10),0,_mesh_cb_child_collect,&local_74);
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d Delete %d mesh child ap\n","mesh_cb_for_ap_delete",0xe9,local_74);
    }
    if (0 < local_74) {
      apmngr_ap_delete(auStack_70,local_74,0,0,1);
      iVar1 = *(int *)(param_1 + 0x14);
      goto LAB_004bd76c;
    }
  }
  else if (((iVar1 == 4) || (iVar1 == 8)) || ((iVar1 == 6 || (iVar1 == 5)))) {
    iVar1 = mesh_db_mesh_enable_get(local_80);
    if (iVar1 == 0) {
      if (local_80[0] == 0) {
        iVar1 = *(int *)(param_1 + 0x14);
      }
      else {
        memcpy(local_80 + 1,(void *)(param_1 + 0x48),6);
        mesh_pkt_re_operation_request_send((int)*(short *)(param_1 + 0x18),1,local_80 + 1,1);
        iVar1 = *(int *)(param_1 + 0x14);
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x14);
    }
    goto LAB_004bd76c;
  }
  iVar1 = *(int *)(param_1 + 0x14);
LAB_004bd76c:
  if (((iVar1 == 1) || (iVar1 == 3)) ||
     (((iVar1 == 2 || (((iVar1 == 4 || (iVar1 == 8)) || (iVar1 == 6)))) || (iVar1 == 5)))) {
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d Delete mesh ap:%d\n","mesh_cb_for_ap_delete",0xf6,
             (uint)*(ushort *)(param_1 + 0x10));
    }
    mesh_db_ap_entry_delete(*(undefined2 *)(param_1 + 0x10));
  }
  return 0;
}

