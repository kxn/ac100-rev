// func _mesh_bh_work_mode_changed_cb @ 004beff0 size=164

bool _mesh_bh_work_mode_changed_cb(int param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d _mesh_bh_work_mode_changed_cb ENTER\n",
           "_mesh_bh_work_mode_changed_cb",0x47a);
  }
  bVar1 = false;
  if (((param_1 != 0) && (param_2 != (undefined4 *)0x0)) &&
     ((iVar2 = *(int *)(param_1 + 0x14), iVar2 == 4 ||
      (((iVar2 == 8 || (iVar2 == 6)) || (iVar2 == 5)))))) {
    iVar2 = mesh_set_rd_cfg_to_re_handle(param_1,*param_2,1);
    bVar1 = iVar2 != 0;
  }
  return bVar1;
}

