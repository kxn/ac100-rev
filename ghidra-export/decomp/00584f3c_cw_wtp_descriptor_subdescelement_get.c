// func cw_wtp_descriptor_subdescelement_get @ 00584f3c size=212

int cw_wtp_descriptor_subdescelement_get(int param_1,short param_2)

{
  short sVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d input is NULL\n";
    uVar3 = 0x291;
  }
  else {
    iVar2 = FUN_004081b0(param_1 + 0x10);
    if (iVar2 != 0) {
      sVar1 = *(short *)(iVar2 + 0x10);
      while( true ) {
        if (sVar1 == param_2) {
          return iVar2;
        }
        iVar2 = FUN_00408680(iVar2);
        if (iVar2 == 0) break;
        sVar1 = *(short *)(iVar2 + 0x10);
      }
    }
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d cann\'t find sub descriptor element in wtp descriptor\n";
    uVar3 = 0x2a0;
  }
  printf(__format,"cw_wtp_descriptor_subdescelement_get",uVar3);
  return 0;
}

