// func cw_priv_rrm_neighs_list_length @ 005be120 size=84

short cw_priv_rrm_neighs_list_length(int param_1)

{
  byte *pbVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  sVar2 = 4;
  if (*(ushort *)(param_1 + 2) != 0) {
    iVar4 = *(int *)(param_1 + 4);
    sVar2 = 0;
    if (iVar4 != 0) {
      sVar2 = 4;
      for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(param_1 + 2); iVar3 = iVar3 + 1) {
        pbVar1 = (byte *)(iVar4 + 7);
        iVar4 = iVar4 + 0xc;
        sVar2 = sVar2 + (ushort)*pbVar1 * 3 + 8;
      }
    }
  }
  return sVar2;
}

