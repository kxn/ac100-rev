// func cw_wtp_board_data_len_get @ 00583230 size=88

short cw_wtp_board_data_len_get(int param_1)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0;
  if (param_1 != 0) {
    sVar2 = 4;
    for (iVar1 = FUN_004081b0(param_1 + 4); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      sVar2 = sVar2 + *(short *)(iVar1 + 0xe) + 4;
    }
  }
  return sVar2;
}

