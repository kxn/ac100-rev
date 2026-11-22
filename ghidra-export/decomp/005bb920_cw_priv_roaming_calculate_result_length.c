// func cw_priv_roaming_calculate_result_length @ 005bb920 size=96

uint cw_priv_roaming_calculate_result_length(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_1 != 0) {
    iVar2 = 0;
    uVar1 = *(int *)(param_1 + 8) * 6 + 10U & 0xffff;
    if (*(int *)(param_1 + 4) != 0) {
      do {
        iVar3 = iVar2 * 0x1c;
        iVar2 = iVar2 + 1;
        uVar1 = uVar1 + (uint)*(byte *)(*(int *)(param_1 + 0x10) + iVar3 + 0x16) * 10 + 0x17 &
                0xffff;
      } while (iVar2 != *(int *)(param_1 + 4));
    }
  }
  return uVar1;
}

