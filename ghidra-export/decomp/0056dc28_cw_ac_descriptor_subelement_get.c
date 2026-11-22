// func cw_ac_descriptor_subelement_get @ 0056dc28 size=212

int cw_ac_descriptor_subelement_get(int param_1,short param_2)

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
    uVar3 = 0x27c;
  }
  else {
    iVar2 = FUN_004081b0(param_1 + 0xc);
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
    __format = "[CW_ERROR]%32s():%4d cann\'t find subelement in ac descriptor\n";
    uVar3 = 0x28a;
  }
  printf(__format,"cw_ac_descriptor_subelement_get",uVar3);
  return 0;
}

