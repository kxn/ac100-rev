// func _mesh_db_foreach_add_parent @ 004b695c size=296

undefined4 _mesh_db_foreach_add_parent(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  void *__s;
  
  param_1 = param_1 * 8;
  if ((*(char *)(DAT_00767f6c + param_1) != '\0') &&
     (*(int *)((char *)(DAT_00767f6c + param_1) + 4) != 0)) {
    if (param_2 != 0) {
      __s = (void *)FUN_00408450(0x3c,0x17e);
      if (__s == (void *)0x0) {
        if (mesh_err_switch == '\0') {
          return 0xffffffff;
        }
        printf("[MESH_ERROR]%s()/%d Malloc failed\n","_mesh_db_foreach_add_parent",0x181);
        return 0xffffffff;
      }
      memset(__s,0,0x3c);
      memcpy(__s,*(void **)(DAT_00767f6c + param_1 + 4),0x3c);
      FUN_004086b0(param_3,__s);
    }
    iVar1 = *(int *)(DAT_00767f6c + param_1 + 4);
    if ((*(int *)(iVar1 + 0x10) == 0) && (iVar1 = *(int *)(iVar1 + 8), iVar1 != 0)) {
      _mesh_db_foreach_add_parent(*(undefined2 *)(iVar1 + -0x14),1,param_3);
    }
  }
  return 0;
}

