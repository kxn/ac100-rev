// func cw_msg_ele_priv_get_from_pkt @ 00583074 size=160

int cw_msg_ele_priv_get_from_pkt(int param_1,short param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (iVar2 = FUN_004081b0(param_1 + 0x1c), iVar2 != 0)) {
    sVar1 = *(short *)(iVar2 + 0xc);
    while( true ) {
      if (sVar1 == 0x25) {
        for (iVar3 = FUN_004081b0(*(int *)(iVar2 + 0x10) + 8); iVar3 != 0;
            iVar3 = FUN_00408680(iVar3)) {
          if (*(short *)(iVar3 + 0xc) == param_2) {
            return iVar3;
          }
        }
      }
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      sVar1 = *(short *)(iVar2 + 0xc);
    }
  }
  return 0;
}

