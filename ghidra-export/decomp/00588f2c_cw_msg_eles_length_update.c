// func cw_msg_eles_length_update @ 00588f2c size=124

undefined4 cw_msg_eles_length_update(int param_1)

{
  short sVar2;
  int iVar1;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_msg_eles_length_update",0x62e);
    }
  }
  else {
    sVar2 = cw_msg_eles_length_count();
    *(short *)(param_1 + 0x16) = sVar2 + 3;
    uVar3 = 0;
  }
  return uVar3;
}

