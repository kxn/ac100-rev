// func mesh_db_policy_mask_get @ 004bab50 size=136

undefined4 mesh_db_policy_mask_get(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d input error\n","mesh_db_policy_mask_get",0x708);
    }
  }
  else {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    *param_1 = DAT_00767fb4;
    uVar1 = 0;
    FUN_00407f30(DAT_00767eb4);
  }
  return uVar1;
}

