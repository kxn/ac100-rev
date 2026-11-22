// func cw_msg_eles_length_count @ 00588934 size=148

int cw_msg_eles_length_count(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_msg_eles_length_count",0x613);
    }
  }
  else {
    iVar3 = 0;
    iVar2 = FUN_004081b0(param_1 + 0x1c);
    if (iVar2 != 0) {
      uVar1 = *(ushort *)(iVar2 + 0xe);
      while( true ) {
        iVar3 = iVar3 + uVar1 + 4;
        iVar2 = FUN_00408680(iVar2);
        if (iVar2 == 0) break;
        uVar1 = *(ushort *)(iVar2 + 0xe);
      }
    }
  }
  return iVar3;
}

