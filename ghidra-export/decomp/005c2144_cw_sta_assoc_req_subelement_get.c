// func cw_sta_assoc_req_subelement_get @ 005c2144 size=84

int cw_sta_assoc_req_subelement_get(int param_1,short param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_1 != 0) && (iVar2 = FUN_004081b0(param_1 + 0x14), iVar2 != 0)) {
    sVar1 = *(short *)(iVar2 + 0xc);
    while (sVar1 != param_2) {
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) {
        return 0;
      }
      sVar1 = *(short *)(iVar2 + 0xc);
    }
    iVar2 = *(int *)(iVar2 + 0x10);
  }
  return iVar2;
}

