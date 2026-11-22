// func cw_priv_chnl_scan_length @ 005ada70 size=84

short cw_priv_chnl_scan_length(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = 2;
    iVar2 = 0;
    if (*(byte *)(param_1 + 1) != 0) {
      while ((iVar2 < (int)(uint)*(byte *)(param_1 + 1) && (*(int *)(param_1 + 4) != 0))) {
        iVar3 = iVar2 * 8;
        iVar2 = iVar2 + 1;
        sVar1 = sVar1 + *(byte *)(*(int *)(param_1 + 4) + iVar3 + 1) + 2;
      }
      return sVar1;
    }
  }
  return sVar1;
}

