// func cw_priv_roaming_trigger_length @ 005bcfc0 size=76

short cw_priv_roaming_trigger_length(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = 0;
  if (param_1 != 0) {
    iVar2 = 0;
    sVar1 = 7;
    if (*(int *)(param_1 + 4) != 0) {
      do {
        iVar3 = iVar2 * 0x10;
        iVar2 = iVar2 + 1;
        sVar1 = sVar1 + (ushort)*(byte *)(*(int *)(param_1 + 8) + iVar3 + 9) * 9 + 10;
      } while (iVar2 != *(int *)(param_1 + 4));
    }
  }
  return sVar1;
}

