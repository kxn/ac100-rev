// func _mesh_db_foreach_add_child @ 004b6a84 size=436

undefined4 _mesh_db_foreach_add_child(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  undefined *puVar3;
  void *__s;
  
  if (param_1 != 0xffff) {
    pcVar1 = (char *)(DAT_00767f6c + param_1 * 8);
    if (*pcVar1 == '\0') {
      return 0;
    }
    if (*(int *)(pcVar1 + 4) == 0) {
      return 0;
    }
  }
  __s = (void *)0x0;
  if (param_2 != 0) {
    __s = (void *)FUN_00408450(0x3c,0x15e);
    if (__s == (void *)0x0) {
      if (mesh_err_switch == '\0') {
        return 0xffffffff;
      }
      printf("[MESH_ERROR]%s()/%d Malloc failed\n","_mesh_db_foreach_add_child",0x161);
      return 0xffffffff;
    }
    memset(__s,0,0x3c);
    if (param_1 == 0xffff) {
      puVar3 = &DAT_00767f70;
    }
    else {
      puVar3 = *(undefined **)(DAT_00767f6c + param_1 * 8 + 4);
    }
    memcpy(__s,puVar3,0x3c);
    if (param_4 == 0) {
      FUN_004086b0(param_3,__s);
    }
  }
  if (param_1 == 0xffff) {
    puVar3 = &DAT_00767f90;
  }
  else {
    puVar3 = (undefined *)(*(int *)(DAT_00767f6c + param_1 * 8 + 4) + 0x20);
  }
  for (iVar2 = FUN_004081b0(puVar3); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
    _mesh_db_foreach_add_child(*(undefined2 *)(iVar2 + 0xc),1,param_3,param_4);
  }
  if ((param_2 != 0) && (param_4 != 0)) {
    FUN_004086b0(param_3,__s);
  }
  return 0;
}

