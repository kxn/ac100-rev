// func cw_wtp_descriptor_len_get @ 00583fb0 size=136

short cw_wtp_descriptor_len_get(int param_1)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0;
  if (param_1 != 0) {
    sVar2 = 3;
    for (iVar1 = FUN_004081b0(param_1 + 4); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      sVar2 = sVar2 + 3;
    }
    for (iVar1 = FUN_004081b0(param_1 + 0x10); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      sVar2 = sVar2 + *(short *)(iVar1 + 0x12) + 8;
    }
  }
  return sVar2;
}

