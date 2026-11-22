// func mesh_db_bh_work_mode_set @ 004b915c size=116

undefined4 mesh_db_bh_work_mode_set(undefined4 param_1)

{
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d mesh_db_bh_work_mode_set ENTER bh_work_mode=%d\n",
           "mesh_db_bh_work_mode_set",0x4d1,param_1);
  }
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  DAT_00767fac = param_1;
  FUN_00407f30(DAT_00767eb4);
  return 0;
}

