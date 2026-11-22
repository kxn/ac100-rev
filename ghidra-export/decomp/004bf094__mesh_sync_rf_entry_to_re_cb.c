// func _mesh_sync_rf_entry_to_re_cb @ 004bf094 size=224

undefined4 _mesh_sync_rf_entry_to_re_cb(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_2f0 [2];
  undefined1 auStack_2e8 [20];
  int local_2d4;
  
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d _mesh_sync_rf_entry_to_re_cb ENTER\n","_mesh_sync_rf_entry_to_re_cb"
           ,0x498);
  }
  uVar2 = 1;
  if (param_1 != 0) {
    memset(auStack_2e8,0,0x2d8);
    local_2f0[0] = 0;
    iVar1 = mesh_db_bh_work_mode_get(local_2f0);
    if (((iVar1 != -1) &&
        (iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0xc),auStack_2e8), iVar1 != -1)
        ) && ((local_2d4 == 4 ||
              (((local_2d4 == 8 || (local_2d4 == 6)) || (uVar2 = 0, local_2d4 == 5)))))) {
      uVar2 = mesh_set_rd_cfg_to_re_handle(auStack_2e8,local_2f0[0],1);
    }
  }
  return uVar2;
}

