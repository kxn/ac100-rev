// func cw_80211_antenna_create @ 0056421c size=372

int cw_80211_antenna_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_80211_antenna_create",0xec);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 4) = 0;
    if (*(char *)(param_1 + 3) == '\0') {
      uVar4 = (uint)*(byte *)(iVar1 + 3);
    }
    else if (*(int *)(param_1 + 4) == 0) {
      uVar4 = (uint)*(byte *)(iVar1 + 3);
    }
    else {
      iVar2 = cw_protocol_clone();
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone selection\n","cw_80211_antenna_create",0xf7);
        }
        FUN_00407df0(iVar1);
        return 0;
      }
      uVar4 = (uint)*(byte *)(iVar1 + 3);
    }
    iVar2 = cw_protocol_msg_ele_create(0x401,uVar4 + 4,iVar1);
    if (iVar2 == 0) {
      if (capwap_err_switch == 0) {
        iVar3 = *(int *)(iVar1 + 4);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message element\n","cw_80211_antenna_create"
                 ,0x101);
          iVar3 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar3 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

