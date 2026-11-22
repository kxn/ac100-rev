// func mesh_db_discover_entry_get @ 004b9924 size=200

undefined4 mesh_db_discover_entry_get(int param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    uVar1 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Illegal input\n","mesh_db_discover_entry_get",0x5be);
    }
  }
  else {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    __src = (void *)FUN_00407fa0(DAT_00767f68,param_1);
    if (__src == (void *)0x0) {
      uVar1 = 0xffffffff;
      FUN_00407f30(DAT_00767eb4);
    }
    else {
      memcpy(param_2,__src,0x68);
      uVar1 = 0;
      FUN_00407f30(DAT_00767eb4);
    }
  }
  return uVar1;
}

