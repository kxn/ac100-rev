// func mesh_db_cap_id_list_get @ 004b7d50 size=1

undefined2 * mesh_db_cap_id_list_get(int *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined2 *__s;
  undefined2 *puVar5;
  
  __s = (undefined2 *)0x0;
  if (param_1 != (int *)0x0) {
    iVar4 = 0;
    iVar3 = 0;
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    while (iVar1 = apmngr_db_get_ap_max(), iVar3 < iVar1) {
      pcVar2 = (char *)(DAT_00767f6c + iVar3 * 8);
      iVar3 = iVar3 + 1;
      if ((*pcVar2 != '\0') && (iVar1 = *(int *)(pcVar2 + 4), iVar1 != 0)) {
        iVar4 = iVar4 + (uint)(*(int *)(iVar1 + 0x10) != 0);
      }
    }
    __s = (undefined2 *)0x0;
    if (iVar4 != 0) {
      __s = (undefined2 *)FUN_00408450(iVar4 << 1,0x399);
      if (__s == (undefined2 *)0x0) {
        FUN_00407f30(DAT_00767eb4);
        return (undefined2 *)0x0;
      }
      memset(__s,0,iVar4 << 1);
      puVar5 = __s;
      for (iVar3 = 0; iVar1 = apmngr_db_get_ap_max(), iVar3 < iVar1; iVar3 = iVar3 + 1) {
        pcVar2 = (char *)(DAT_00767f6c + iVar3 * 8);
        if ((((*pcVar2 != '\0') && (iVar1 = *(int *)(pcVar2 + 4), iVar1 != 0)) &&
            (*(int *)(iVar1 + 0x10) != 0)) && (iVar3 < iVar4)) {
          *puVar5 = *(undefined2 *)(iVar1 + 0xc);
        }
        puVar5 = puVar5 + 1;
      }
    }
    FUN_00407f30(DAT_00767eb4);
    *param_1 = iVar4;
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d cap_num=%d\n","mesh_db_cap_id_list_get",0x3ac,iVar4);
    }
  }
  return __s;
}

