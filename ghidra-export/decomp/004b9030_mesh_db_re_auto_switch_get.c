// func mesh_db_re_auto_switch_get @ 004b9030 size=136

undefined4 mesh_db_re_auto_switch_get(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_re_auto_switch_get",0x4b4);
    }
  }
  else {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    *param_1 = DAT_00767f40;
    uVar1 = 0;
    FUN_00407f30(DAT_00767eb4);
  }
  return uVar1;
}

