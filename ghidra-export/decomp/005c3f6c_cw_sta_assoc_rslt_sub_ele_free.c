// func cw_sta_assoc_rslt_sub_ele_free @ 005c3f6c size=160

void cw_sta_assoc_rslt_sub_ele_free(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    while (iVar1 = FUN_004081b0(param_1 + 0x14), iVar1 != 0) {
      FUN_00408500(iVar1);
      iVar2 = *(int *)(iVar1 + 0x10);
      if (iVar2 != 0) {
        if ((*(short *)(iVar1 + 0xc) == 1) && (*(int *)(iVar2 + 4) != 0)) {
          FUN_00407df0();
          *(undefined4 *)(iVar2 + 4) = 0;
        }
        FUN_00407df0(*(undefined4 *)(iVar1 + 0x10));
      }
      FUN_00407df0(iVar1);
    }
  }
  return;
}

