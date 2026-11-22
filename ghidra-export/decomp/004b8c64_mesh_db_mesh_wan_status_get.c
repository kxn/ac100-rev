// func mesh_db_mesh_wan_status_get @ 004b8c64 size=136

undefined4 mesh_db_mesh_wan_status_get(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d input error\n","mesh_db_mesh_wan_status_get",0x463);
    }
  }
  else {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    *param_1 = DAT_00767ebc;
    uVar1 = 0;
    FUN_00407f30(DAT_00767eb4);
  }
  return uVar1;
}

