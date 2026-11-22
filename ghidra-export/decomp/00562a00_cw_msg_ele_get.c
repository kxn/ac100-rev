// func cw_msg_ele_get @ 00562a00 size=84

int cw_msg_ele_get(int param_1,short param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_1 != 0) && (iVar2 = FUN_004081b0(param_1 + 0x1c), iVar2 != 0)) {
    sVar1 = *(short *)(iVar2 + 0xc);
    while ((sVar1 != param_2 && (iVar2 = FUN_00408680(iVar2), iVar2 != 0))) {
      sVar1 = *(short *)(iVar2 + 0xc);
    }
  }
  return iVar2;
}

