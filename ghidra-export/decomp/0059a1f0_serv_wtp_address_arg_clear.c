// func serv_wtp_address_arg_clear @ 0059a1f0 size=224

void serv_wtp_address_arg_clear(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = cw_ac_data_size_get();
  if (param_1 != (int *)0x0) {
    iVar3 = 0;
    for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
      if (*param_1 == 0) {
        iVar2 = param_1[1];
      }
      else {
        iVar2 = *param_1;
        while (iVar2 = FUN_004081b0(iVar2 + iVar3), iVar2 != 0) {
          FUN_00408500(iVar2);
          FUN_00407df0(iVar2);
          iVar2 = *param_1;
        }
        iVar2 = param_1[1];
      }
      if (iVar2 != 0) {
        iVar2 = param_1[1];
        while (iVar2 = FUN_004081b0(iVar2 + iVar3), iVar2 != 0) {
          FUN_00408500(iVar2);
          FUN_00407df0(iVar2);
          iVar2 = param_1[1];
        }
      }
      iVar3 = iVar3 + 0xc;
    }
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}

