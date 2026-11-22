// func replace_old_uac_nms_params_report @ 0049e1d4 size=164

int replace_old_uac_nms_params_report(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 != 0) {
    if (param_1 < 1) {
      iVar2 = 0;
    }
    else {
      while ((iVar1 = FUN_004081b0(param_2), iVar1 != 0 && (0 < param_1))) {
        if (*(int *)(iVar1 + 0x20) != 0) {
          FUN_00407df0();
          *(undefined4 *)(iVar1 + 0x20) = 0;
          iVar2 = iVar2 + *(int *)(iVar1 + 0x1c);
          param_1 = param_1 - *(int *)(iVar1 + 0x1c);
        }
        FUN_00408500(iVar1);
        FUN_00407df0(iVar1);
      }
    }
  }
  return iVar2;
}

