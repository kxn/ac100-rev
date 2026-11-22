// func cw_wtp_descriptor_subencryelement_get @ 00584e68 size=1

int cw_wtp_descriptor_subencryelement_get(int param_1,ushort param_2)

{
  byte bVar1;
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
    uVar3 = 0x26d;
  }
  else {
    iVar2 = FUN_004081b0(param_1 + 4);
    if (iVar2 != 0) {
      bVar1 = *(byte *)(iVar2 + 0xc);
      while( true ) {
        if (bVar1 == param_2) {
          return iVar2;
        }
        iVar2 = FUN_00408680(iVar2);
        if (iVar2 == 0) break;
        bVar1 = *(byte *)(iVar2 + 0xc);
      }
    }
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d cann\'t find sub encryption element in wtp descriptor\n";
    uVar3 = 0x27c;
  }
  printf(__format,"cw_wtp_descriptor_subencryelement_get",uVar3);
  return 0;
}

