// func cw_priv_portal_data_create @ 005b88a0 size=428

int cw_priv_portal_data_create(short *param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  
  psVar2 = (short *)cw_protocol_clone(param_1,8);
  if (psVar2 == (short *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_portal_data_create",0xb8);
    return 0;
  }
  psVar2[2] = 0;
  psVar2[3] = 0;
  if (*param_1 == 0) {
    sVar1 = *psVar2;
LAB_005b88f4:
    iVar3 = cw_protocol_msg_ele_create(0x28,sVar1 + 2,psVar2);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = *(int *)(psVar2 + 2);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = *(int *)(psVar2 + 2);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_portal_data_create",0xd3);
          iVar4 = *(int *)(psVar2 + 2);
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(psVar2);
    }
  }
  else {
    if (*(int *)(param_1 + 2) == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar5 = 0xc2;
LAB_005b8a18:
        printf(__format,"cw_priv_portal_data_create",uVar5);
      }
    }
    else {
      iVar3 = cw_protocol_clone();
      *(int *)(psVar2 + 2) = iVar3;
      if (iVar3 != 0) {
        sVar1 = *psVar2;
        goto LAB_005b88f4;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar5 = 0xc9;
        goto LAB_005b8a18;
      }
    }
    FUN_00407df0(psVar2);
    iVar3 = 0;
  }
  return iVar3;
}

