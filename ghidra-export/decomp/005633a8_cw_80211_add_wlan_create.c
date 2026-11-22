// func cw_80211_add_wlan_create @ 005633a8 size=488

int cw_80211_add_wlan_create(int param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  short sVar3;
  undefined4 uVar4;
  
  iVar1 = cw_protocol_clone(param_1,0x20);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_80211_add_wlan_create",399);
    return 0;
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  if (*(short *)(param_1 + 6) == 0) {
    sVar3 = *(short *)(param_1 + 0x18);
LAB_00563400:
    if (sVar3 == 0) {
      sVar3 = *(short *)(iVar1 + 6);
    }
    else if (*(int *)(param_1 + 0x1c) == 0) {
      sVar3 = *(short *)(iVar1 + 6);
    }
    else {
      iVar2 = cw_protocol_duplicate_string();
      *(int *)(iVar1 + 0x1c) = iVar2;
      if (iVar2 == 0) {
        if (capwap_err_switch == 0) {
          iVar2 = *(int *)(iVar1 + 8);
          goto LAB_005634b8;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 8);
          goto LAB_005634b8;
        }
        __format = "[CW_ERROR]%32s():%4d failed to clone ssid\n";
        uVar4 = 0x1a6;
        goto LAB_00563520;
      }
      sVar3 = *(short *)(iVar1 + 6);
    }
    iVar2 = cw_protocol_msg_ele_create(0x400,sVar3 + *(short *)(iVar1 + 0x18) + 0x13,iVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 8);
      goto LAB_005634b8;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 8);
      goto LAB_005634b8;
    }
    __format = "[CW_ERROR]%32s():%4d failed to create message element\n";
    uVar4 = 0x1af;
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      sVar3 = *(short *)(param_1 + 0x18);
      goto LAB_00563400;
    }
    iVar2 = cw_protocol_clone();
    *(int *)(iVar1 + 8) = iVar2;
    if (iVar2 != 0) {
      sVar3 = *(short *)(param_1 + 0x18);
      goto LAB_00563400;
    }
    if (capwap_err_switch == 0) {
      iVar2 = *(int *)(iVar1 + 8);
      goto LAB_005634b8;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 8);
      goto LAB_005634b8;
    }
    __format = "[CW_ERROR]%32s():%4d failed to clone key\n";
    uVar4 = 0x19b;
  }
LAB_00563520:
  printf(__format,"cw_80211_add_wlan_create",uVar4);
  iVar2 = *(int *)(iVar1 + 8);
LAB_005634b8:
  if (iVar2 == 0) {
    iVar2 = *(int *)(iVar1 + 0x1c);
  }
  else {
    FUN_00407df0();
    iVar2 = *(int *)(iVar1 + 0x1c);
  }
  if (iVar2 != 0) {
    FUN_00407df0();
  }
  FUN_00407df0(iVar1);
  return 0;
}

