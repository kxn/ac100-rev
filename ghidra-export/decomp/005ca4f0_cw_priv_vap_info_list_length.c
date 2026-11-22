// func cw_priv_vap_info_list_length @ 005ca4f0 size=68

short cw_priv_vap_info_list_length(byte *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = 1;
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = *(int *)(param_1 + 4);
    for (iVar2 = 0; iVar2 < (int)(uint)*param_1; iVar2 = iVar2 + 1) {
      sVar1 = sVar1 + *(short *)(iVar3 + 0x10) + 0x10;
      iVar3 = iVar3 + 0x20;
    }
  }
  return sVar1;
}

