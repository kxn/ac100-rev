// func cw_priv_adv_rd_para_length @ 005a2ea0 size=132

int cw_priv_adv_rd_para_length(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = param_1;
  if (param_1 != 0) {
    do {
      iVar1 = iVar1 + 1;
      if (*(char *)(iVar2 + 0x16) != -1) {
        iVar2 = 6;
        goto LAB_005a2ecc;
      }
      iVar2 = param_1 + iVar1;
    } while (iVar1 != 6);
    iVar2 = 0;
LAB_005a2ecc:
    iVar1 = 4;
    if (((*(char *)(param_1 + 0x11) == -1) && (*(short *)(param_1 + 0x12) == 0x1ff)) &&
       (*(char *)(param_1 + 0x14) == '\x01')) {
      iVar1 = 0;
    }
    iVar1 = iVar2 + iVar1 + (*(char *)(param_1 + 0x15) != -1) + 0x10;
  }
  return iVar1;
}

