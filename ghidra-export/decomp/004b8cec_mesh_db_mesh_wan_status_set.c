// func mesh_db_mesh_wan_status_set @ 004b8cec size=136

undefined4 mesh_db_mesh_wan_status_set(char param_1)

{
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d mesh_db_mesh_wan_status_set wan_status: %d\n",
           "mesh_db_mesh_wan_status_set",0x46e,(int)param_1);
  }
  if (param_1 < 2) {
    param_1 = '\x02';
  }
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  DAT_00767ebc = param_1;
  FUN_00407f30(DAT_00767eb4);
  return 0;
}

