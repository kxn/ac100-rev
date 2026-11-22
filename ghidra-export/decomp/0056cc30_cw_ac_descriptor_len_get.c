// func cw_ac_descriptor_len_get @ 0056cc30 size=88

short cw_ac_descriptor_len_get(int param_1)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0;
  if (param_1 != 0) {
    sVar2 = 0xc;
    for (iVar1 = FUN_004081b0(param_1 + 0xc); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      sVar2 = sVar2 + *(short *)(iVar1 + 0x12) + 8;
    }
  }
  return sVar2;
}

