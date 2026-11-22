// func mesh_db_mesh_enable_set @ 004b8bf0 size=116

undefined4 mesh_db_mesh_enable_set(undefined4 param_1)

{
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d mesh_db_mesh_enable_set enable=%d\n","mesh_db_mesh_enable_set",0x459
           ,param_1);
  }
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  DAT_00767eb8 = param_1;
  FUN_00407f30(DAT_00767eb4);
  return 0;
}

