// func close_ap_mesh_switch_cb @ 004be838 size=508

undefined4 close_ap_mesh_switch_cb(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int local_910;
  undefined4 local_90c;
  undefined2 local_908;
  int local_904;
  undefined2 local_900 [52];
  undefined1 auStack_898 [728];
  undefined1 auStack_5c0 [20];
  int local_5ac;
  undefined2 local_328;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  int local_2d4;
  undefined4 local_2a0;
  undefined2 local_29c;
  
  memset(&local_904,0,0x68);
  local_90c = 0;
  local_908 = 0;
  local_910 = 1;
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_5c0,0,0x2d8);
  memset(auStack_898,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  uVar3 = 0xffffffff;
  if ((iVar1 == 0) && (((local_2d4 == 1 || (local_2d4 == 3)) || (uVar3 = 0, local_2d4 == 2)))) {
    iVar1 = mesh_db_discover_state_get();
    if (iVar1 != 0) {
      mesh_db_discover_list_delete_by_capid(local_2d8);
    }
    mesh_db_ap_entry_child_foreach_proc(local_2d8,0,_mesh_cb_child_collect,&local_904);
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d Delete %d mesh child ap\n","close_ap_mesh_switch_cb",0x31b,
             local_904);
    }
    uVar3 = 0;
    if (0 < local_904) {
      puVar4 = local_900;
      iVar1 = 0;
      while (uVar3 = 0, iVar1 < local_904) {
        iVar2 = apmngr_db_entry_get_by_id(*puVar4,auStack_5c0);
        if (iVar2 != 0) {
          return 0xffffffff;
        }
        if ((((local_5ac == 4) || (local_5ac == 8)) || ((local_5ac == 6 || (local_5ac == 5)))) &&
           ((iVar2 = mesh_db_mesh_enable_get(&local_910), iVar2 == 0 && (local_910 != 0)))) {
          local_90c = local_2a0;
          local_908 = local_29c;
          mesh_pkt_re_operation_request_send(local_2d8,1,&local_90c,1);
        }
        mesh_re_entry_delete(*puVar4);
        iVar2 = apmngr_db_entry_get_by_id(local_328,auStack_898);
        if (iVar2 == 0) {
          iVar1 = iVar1 + 1;
          puVar4 = puVar4 + 1;
          mesh_re_entry_delete(local_328);
        }
        else {
          iVar1 = iVar1 + 1;
          puVar4 = puVar4 + 1;
        }
      }
    }
  }
  return uVar3;
}

