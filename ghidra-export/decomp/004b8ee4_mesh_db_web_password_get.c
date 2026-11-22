// func mesh_db_web_password_get @ 004b8ee4 size=172

undefined4 mesh_db_web_password_get(char *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (char *)0x0) || (param_2 < 2)) {
    uVar1 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_web_password_get",0x49c);
    }
  }
  else {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    strncpy(param_1,&DAT_00767f44,param_2 - 1);
    uVar1 = 0;
    FUN_00407f30(DAT_00767eb4);
  }
  return uVar1;
}

