// func cw_msg_ele_priv_check @ 00581d7c size=428

undefined4 cw_msg_ele_priv_check(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  char *__format;
  undefined4 uVar6;
  
  if ((param_1 == 0) || (param_2 == (ushort *)0x0)) {
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_msg_ele_priv_check",0x80);
    }
  }
  else if (*(ushort *)(param_1 + 0xc) == *param_2) {
    if (*(ushort *)(param_1 + 0xe) < param_2[4]) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      uVar5 = *(undefined4 *)(param_2 + 2);
      uVar1 = *(ushort *)(param_1 + 0xe);
      __format = "[CW_ERROR]%32s():%4d the length(%d) of %s(%d) is too short, need at least(%d)\n";
      uVar2 = *param_2;
      uVar6 = 0x8d;
      uVar3 = param_2[4];
    }
    else {
      if (*(ushort *)(param_1 + 0xe) <= param_2[5]) {
        return 0;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      uVar5 = *(undefined4 *)(param_2 + 2);
      uVar1 = *(ushort *)(param_1 + 0xe);
      __format = "[CW_ERROR]%32s():%4d the length(%d) of %s(%d) is too long, need at most(%d)\n";
      uVar2 = *param_2;
      uVar6 = 0x92;
      uVar3 = param_2[5];
    }
    printf(__format,"cw_msg_ele_priv_check",uVar6,(uint)uVar1,uVar5,(uint)uVar2,(uint)uVar3);
  }
  else if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[CW_ERROR]%32s():%4d capwap message type(%d) doesn\'t match manager\'s type(%d)\n",
           "cw_msg_ele_priv_check",0x87,(uint)*(ushort *)(param_1 + 0xc),(uint)*param_2);
  }
  return 0xffffffff;
}

