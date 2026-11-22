// func cw_priv_lag_config_create @ 005b4394 size=428

int cw_priv_lag_config_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_lag_config_create",0xc5);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  uVar4 = (uint)*(byte *)(param_1 + 2);
  if (uVar4 == 0) {
LAB_005b43ec:
    iVar2 = cw_protocol_msg_ele_create(0xa3,uVar4 + 3,iVar1);
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
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_lag_config_create",0xe3);
          iVar3 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar3 != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 4) = 0;
      }
      FUN_00407df0(iVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar5 = 0xd0;
LAB_005b450c:
        printf(__format,"cw_priv_lag_config_create",uVar5);
      }
    }
    else {
      iVar2 = cw_protocol_clone();
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 != 0) {
        uVar4 = (uint)*(byte *)(param_1 + 2);
        goto LAB_005b43ec;
      }
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar5 = 0xd9;
        goto LAB_005b450c;
      }
    }
    FUN_00407df0(iVar1);
    iVar2 = 0;
  }
  return iVar2;
}

