// func mesh_db_discover_list_foreach_proc @ 004ba03c size=624

int mesh_db_discover_list_foreach_proc(code *param_1,undefined4 param_2)

{
  void *__src;
  void *__dest;
  void *__src_00;
  void *__dest_00;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if (param_1 == (code *)0x0) {
    iVar4 = 1;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Callback is null.\n","mesh_db_discover_list_foreach_proc",0x691);
    }
  }
  else {
    FUN_0051ad88(&local_38);
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    for (__src = (void *)FUN_004081b0(&DAT_00767f5c); __src != (void *)0x0;
        __src = (void *)FUN_00408680(__src)) {
      __dest = (void *)FUN_00408450(0x68,0x69a);
      if (__dest == (void *)0x0) {
        if (mesh_err_switch != '\0') {
          uVar3 = 0x69d;
LAB_004ba22c:
          printf("[MESH_ERROR]%s()/%d Malloc failed\n","mesh_db_discover_list_foreach_proc",uVar3);
        }
LAB_004ba16c:
        iVar4 = 1;
        FUN_00407f30(DAT_00767eb4);
        goto LAB_004ba174;
      }
      memcpy(__dest,__src,0x68);
      FUN_0051ad88((int)__dest + 0x58);
      FUN_004086b0(&local_38,__dest);
      for (__src_00 = (void *)FUN_004081b0((int)__src + 0x58); __src_00 != (void *)0x0;
          __src_00 = (void *)FUN_00408680(__src_00)) {
        __dest_00 = (void *)FUN_00408450(0x1c,0x6a7);
        if (__dest_00 == (void *)0x0) {
          if (mesh_err_switch == '\0') goto LAB_004ba16c;
          uVar3 = 0x6aa;
          goto LAB_004ba22c;
        }
        memcpy(__dest_00,__src_00,0x1c);
        FUN_004086b0((int)__dest + 0x58,__dest_00);
      }
    }
    FUN_00407f30(DAT_00767eb4);
    iVar2 = FUN_004081b0(&local_38);
    while ((iVar4 = 0, iVar2 != 0 && (iVar4 = (*param_1)(iVar2,param_2), iVar4 != 2))) {
      iVar2 = FUN_00408680(iVar2);
    }
LAB_004ba174:
    while (iVar2 = FUN_004081b0(&local_38), iVar2 != 0) {
      FUN_00408500(iVar2);
      while (iVar1 = FUN_004081b0(iVar2 + 0x58), iVar1 != 0) {
        FUN_00408500(iVar1);
        FUN_00407df0(iVar1);
      }
      FUN_00407df0(iVar2);
    }
  }
  return iVar4;
}

