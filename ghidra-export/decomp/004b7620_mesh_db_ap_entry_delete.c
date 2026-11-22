// func mesh_db_ap_entry_delete @ 004b7620 size=604

undefined4 mesh_db_ap_entry_delete(uint param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    iVar1 = param_1 * 8;
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    pcVar2 = (char *)(DAT_00767f6c + iVar1);
    if ((*pcVar2 == '\0') || (*(int *)(pcVar2 + 4) == 0)) {
      if (mesh_warning_switch != '\0') {
        printf("[MESH_WARNING]%s()/%d AP id(%d) is used\n","mesh_db_ap_entry_delete",0x2c7,param_1);
      }
      uVar6 = 0xffffffff;
      FUN_00407f30(DAT_00767eb4);
    }
    else {
      *pcVar2 = '\0';
      iVar7 = *(int *)(DAT_00767f6c + iVar1 + 4);
      while (iVar3 = FUN_004081b0(iVar7 + 0x20), iVar3 != 0) {
        FUN_00408500(iVar3);
        if (*(ushort *)(iVar3 + 0x14) == 0xffff) {
          FUN_004086b0(&DAT_00767f90,iVar3);
          *(undefined2 *)(iVar3 + 0x16) = 0xffff;
        }
        else {
          pcVar2 = (char *)(DAT_00767f6c + (uint)*(ushort *)(iVar3 + 0x14) * 8);
          if (*pcVar2 == '\0') {
            uVar4 = *(undefined2 *)(iVar3 + 0xc);
LAB_004b7754:
            *(undefined2 *)(iVar3 + 0x14) = 0xffff;
            *(undefined2 *)(iVar3 + 0x16) = uVar4;
          }
          else {
            iVar5 = *(int *)(pcVar2 + 4);
            if (iVar5 == 0) {
              uVar4 = *(undefined2 *)(iVar3 + 0xc);
              goto LAB_004b7754;
            }
            FUN_004086b0(iVar5 + 0x20,iVar3);
            *(undefined2 *)(iVar3 + 0x16) = *(undefined2 *)(iVar3 + 0x14);
          }
        }
      }
      if (*(ushort *)(*(int *)(DAT_00767f6c + iVar1 + 4) + 0x16) != param_1) {
        FUN_00408500();
      }
      iVar7 = *(int *)(DAT_00767f6c + iVar1 + 4);
      if ((*(char *)(iVar7 + 0x34) != '\0') &&
         (*(undefined1 *)(iVar7 + 0x34) = 0,
         *(int *)(*(int *)(DAT_00767f6c + iVar1 + 4) + 0x38) != -1)) {
        FUN_00408060();
        *(undefined4 *)(*(int *)(DAT_00767f6c + iVar1 + 4) + 0x38) = 0xffffffff;
      }
      FUN_00407df0(*(undefined4 *)(DAT_00767f6c + iVar1 + 4));
      *(undefined4 *)(DAT_00767f6c + iVar1 + 4) = 0;
      uVar6 = 0;
      FUN_00407f30(DAT_00767eb4);
    }
  }
  else {
    uVar6 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_ap_entry_delete",0x2c0);
    }
  }
  return uVar6;
}

