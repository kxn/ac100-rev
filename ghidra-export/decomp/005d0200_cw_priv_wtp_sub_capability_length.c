// func cw_priv_wtp_sub_capability_length @ 005d0200 size=72

short cw_priv_wtp_sub_capability_length(ushort *param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = 0;
  if (param_1 != (ushort *)0x0) {
    sVar1 = 2;
    for (iVar2 = 0; iVar2 < (int)(uint)*param_1; iVar2 = iVar2 + 1) {
      sVar1 = sVar1 + *(short *)(*(int *)(param_1 + 2) + iVar2 * 8 + 2) + 4;
    }
  }
  return sVar1;
}

