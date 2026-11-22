// func _mesh_del_all_re_router @ 004bdcb8 size=184

undefined4 _mesh_del_all_re_router(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = mesh_db_ap_entry_delete(*(undefined2 *)(param_1 + 0x10));
  if (iVar1 == 0) {
    iVar1 = apmngr_ap_delete(param_1 + 0x10,1,0,0,1);
    if (iVar1 == 0) {
      return 0;
    }
    if (mesh_err_switch == '\0') {
      return 2;
    }
    uVar2 = 0x4c3;
  }
  else {
    if (mesh_err_switch == '\0') {
      return 2;
    }
    uVar2 = 0x4be;
  }
  printf("[MESH_ERROR]%s()/%d Delete ap entry(%d) failed\n","_mesh_del_all_re_router",uVar2,
         (uint)*(ushort *)(param_1 + 0x10));
  return 2;
}

