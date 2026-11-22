// func mesh_db_ap_entry_child_foreach_proc @ 004b797c size=328

int mesh_db_ap_entry_child_foreach_proc
              (undefined2 param_1,undefined4 param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if (param_3 == (code *)0x0) {
    iVar1 = 1;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Callback is null.\n","mesh_db_ap_entry_child_foreach_proc",0x313);
    }
  }
  else {
    FUN_0051ad88(&local_28);
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    iVar1 = _mesh_db_foreach_add_child(param_1,param_2,&local_28,0);
    if (iVar1 == 0) {
      FUN_00407f30(DAT_00767eb4);
      iVar2 = FUN_004081b0(&local_28);
      iVar1 = 0;
      if (iVar2 != 0) {
        do {
          iVar1 = (*param_3)(iVar2,param_4);
          if (iVar1 == 2) goto LAB_004b7a60;
          iVar2 = FUN_00408680(iVar2);
        } while (iVar2 != 0);
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 1;
      FUN_00407f30(DAT_00767eb4);
    }
LAB_004b7a60:
    while (iVar2 = FUN_004081b0(&local_28), iVar2 != 0) {
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
    }
  }
  return iVar1;
}

