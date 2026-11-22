// func mesh_db_child_list_get_by_cap_id @ 004b7ef8 size=352

undefined2 * mesh_db_child_list_get_by_cap_id(undefined2 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *__s;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if (param_2 == (int *)0x0) {
    __s = (undefined2 *)0x0;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d num is null.\n","mesh_db_child_list_get_by_cap_id",0x3bb);
    }
  }
  else {
    FUN_0051ad88(&local_28);
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    iVar1 = _mesh_db_foreach_add_child(param_1,0,&local_28,0);
    if (iVar1 == 0) {
      __s = (undefined2 *)0x0;
      FUN_00407f30(DAT_00767eb4);
      iVar1 = FUN_00407fe0(&local_28);
      if (iVar1 != 0) {
        __s = (undefined2 *)FUN_00408450(iVar1 << 1,0x3cf);
        if (__s != (undefined2 *)0x0) {
          memset(__s,0,iVar1 << 1);
          iVar2 = FUN_004081b0(&local_28);
          puVar3 = __s;
          for (; iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
            *puVar3 = *(undefined2 *)(iVar2 + 0xc);
            puVar3 = puVar3 + 1;
          }
        }
      }
    }
    else {
      iVar1 = 0;
      FUN_00407f30(DAT_00767eb4);
      __s = (undefined2 *)0x0;
    }
    while (iVar2 = FUN_004081b0(&local_28), iVar2 != 0) {
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
    }
    *param_2 = iVar1;
  }
  return __s;
}

