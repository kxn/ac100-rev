// func serv_wtp_address_arg_move @ 0059aca0 size=264

void serv_wtp_address_arg_move(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = cw_ac_data_size_get();
  if (param_1 == (int *)0x0) {
    return;
  }
  if (param_2 == (int *)0x0) {
    return;
  }
  iVar2 = 0;
  if (*param_1 == 0) {
LAB_0059ad1c:
    iVar2 = param_1[1];
  }
  else {
    if (*param_2 != 0) {
      for (; iVar2 < iVar1; iVar2 = iVar2 + 1) {
        FUN_004082c0(*param_1 + iVar2 * 0xc,*param_2 + iVar2 * 0xc);
      }
      goto LAB_0059ad1c;
    }
    iVar2 = param_1[1];
  }
  iVar3 = 0;
  if (iVar2 != 0) {
    if (param_2[1] == 0) {
      iVar1 = param_1[2];
      goto LAB_0059ad74;
    }
    for (; iVar3 < iVar1; iVar3 = iVar3 + 1) {
      FUN_004082c0(param_1[1] + iVar3 * 0xc,param_2[1] + iVar3 * 0xc);
    }
    param_1[3] = param_1[3] + param_2[3];
  }
  iVar1 = param_1[2];
LAB_0059ad74:
  param_1[2] = iVar1 + param_2[2];
  param_2[2] = 0;
  param_2[3] = 0;
  return;
}

