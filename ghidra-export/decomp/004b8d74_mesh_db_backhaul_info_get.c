// func mesh_db_backhaul_info_get @ 004b8d74 size=144

undefined4 mesh_db_backhaul_info_get(void *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_backhaul_info_get",0x47c);
    }
  }
  else {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    memcpy(param_1,&DAT_00767ebd,0x82);
    uVar1 = 0;
    FUN_00407f30(DAT_00767eb4);
  }
  return uVar1;
}

