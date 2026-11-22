// func mesh_db_re_auto_add_state_get @ 004b9264 size=88

undefined4 mesh_db_re_auto_add_state_get(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    *param_1 = DAT_00767fb8;
    FUN_00407f30(DAT_00767eb4);
    uVar1 = 0;
  }
  return uVar1;
}

