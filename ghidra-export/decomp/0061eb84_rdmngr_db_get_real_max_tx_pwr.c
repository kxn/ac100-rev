// func rdmngr_db_get_real_max_tx_pwr @ 0061eb84 size=172

int rdmngr_db_get_real_max_tx_pwr(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == -1) {
    iVar2 = 0;
    iVar1 = param_1;
    iVar3 = DAT_007598ec + 0x17a4;
    do {
      iVar2 = iVar2 + 8;
      if (((*(int *)(iVar3 + 0x24) != 0) && (param_3 == 0)) && (iVar1 < *(int *)(iVar3 + 0x28))) {
        iVar1 = *(int *)(iVar3 + 0x28);
      }
      iVar3 = DAT_007598ec + 0x17a4 + iVar2;
    } while (iVar2 != 0x140);
    if (param_1 < iVar1) {
      iVar1 = param_1;
    }
    return iVar1;
  }
  iVar1 = 0;
  do {
    if (param_2 == *(int *)(DAT_007598ec + iVar1 * 8 + 0x17c8)) {
      iVar1 = *(int *)(DAT_007598ec + (iVar1 + 4) * 8 + 0x17ac);
      if (param_1 <= iVar1) {
        iVar1 = param_1;
      }
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x28);
  return -1;
}

