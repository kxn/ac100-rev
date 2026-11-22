// func mesh_db_web_password_set @ 004b8f90 size=160

undefined4 mesh_db_web_password_set(char *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (char *)0x0) || (param_2 < 2)) {
    uVar1 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_web_password_set",0x4a8);
    }
  }
  else {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    strncpy(&DAT_00767f44,param_1,0x10);
    uVar1 = 0;
    FUN_00407f30(DAT_00767eb4);
  }
  return uVar1;
}

