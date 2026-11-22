// func cw_80211_direct_sequence_control_create @ 00565424 size=280

int cw_80211_direct_sequence_control_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = cw_protocol_clone(param_1,0x14);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n",
             "cw_80211_direct_sequence_control_create",0xf8);
    }
  }
  else {
    uVar4 = 0x13;
    if ((((*(uint *)(param_1 + 8) & 0xff00ffff) == 0xff00ffff) && (*(int *)(param_1 + 0xc) == -1))
       && (*(int *)(param_1 + 0x10) == -1)) {
      uVar4 = 8;
    }
    iVar2 = cw_protocol_msg_ele_create(0x404,uVar4,iVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message element\n",
               "cw_80211_direct_sequence_control_create",0x10f);
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

