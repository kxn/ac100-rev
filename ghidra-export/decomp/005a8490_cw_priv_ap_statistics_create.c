// func cw_priv_ap_statistics_create @ 005a8490 size=780

int cw_priv_ap_statistics_create(byte *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  
  if (8 < *param_1) {
LAB_005a84c4:
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u:%u]\n","cw_priv_ap_statistics_create",
             0x1af,(uint)*param_1,(uint)param_1[1]);
    }
    return 0;
  }
  bVar1 = param_1[1];
  if (bVar1 >= 0x41) goto LAB_005a84c4;
  if ((*param_1 != 0) && (*(int *)(param_1 + 0x2c) == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d radio list is null\n";
    uVar5 = 0x1b5;
LAB_005a8654:
    printf(__format,"cw_priv_ap_statistics_create",uVar5);
    return 0;
  }
  if ((bVar1 != 0) && (*(int *)(param_1 + 0x30) == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap(bVar1 < 0x41,0x34);
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d ssid list is null\n";
    uVar5 = 0x1ba;
    goto LAB_005a8654;
  }
  iVar2 = cw_protocol_clone(param_1);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d failed to clone value\n";
    uVar5 = 0x1c3;
    goto LAB_005a8654;
  }
  *(undefined4 *)(iVar2 + 0x2c) = 0;
  *(undefined4 *)(iVar2 + 0x30) = 0;
  if (*param_1 == 0) {
    uVar3 = (uint)param_1[1];
  }
  else if (*(int *)(param_1 + 0x2c) == 0) {
    uVar3 = (uint)param_1[1];
  }
  else {
    iVar4 = cw_protocol_clone(*(int *)(param_1 + 0x2c),(uint)*param_1 << 5);
    *(int *)(iVar2 + 0x2c) = iVar4;
    if (iVar4 == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone radio list\n","cw_priv_ap_statistics_create",
               0x1cf);
      }
      goto LAB_005a8720;
    }
    uVar3 = (uint)param_1[1];
  }
  if ((uVar3 != 0) && (*(int *)(param_1 + 0x30) != 0)) {
    iVar4 = cw_protocol_clone(*(int *)(param_1 + 0x30),uVar3 * 0x1c);
    *(int *)(iVar2 + 0x30) = iVar4;
    if (iVar4 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = *(int *)(iVar2 + 0x2c);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar2 + 0x2c);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to clone ssid list\n","cw_priv_ap_statistics_create",
                 0x1db);
          iVar4 = *(int *)(iVar2 + 0x2c);
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
      }
LAB_005a8720:
      FUN_00407df0(iVar2);
      return 0;
    }
  }
  uVar5 = cw_priv_ap_statistics_length(iVar2);
  iVar4 = cw_protocol_msg_ele_create(0x54,uVar5,iVar2);
  if (iVar4 != 0) {
    return iVar4;
  }
  if (capwap_err_switch == 0) {
    iVar4 = *(int *)(iVar2 + 0x2c);
  }
  else {
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      iVar4 = *(int *)(iVar2 + 0x2c);
    }
    else {
      printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
             "cw_priv_ap_statistics_create",0x1e9);
      iVar4 = *(int *)(iVar2 + 0x2c);
    }
  }
  if (iVar4 == 0) {
    iVar4 = *(int *)(iVar2 + 0x30);
  }
  else {
    FUN_00407df0();
    iVar4 = *(int *)(iVar2 + 0x30);
  }
  if (iVar4 != 0) {
    FUN_00407df0();
  }
  FUN_00407df0(iVar2);
  return 0;
}

