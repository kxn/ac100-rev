// func cw_priv_port_info_create @ 005b8504 size=528

int cw_priv_port_info_create(byte *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char cVar5;
  int iVar4;
  char *__format;
  
  if (0x40 < *param_1) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d phy_num(%d) is too large\n","cw_priv_port_info_create",0x119,
           (uint)*param_1);
    return 0;
  }
  pcVar2 = (char *)cw_protocol_clone(param_1,8);
  if (pcVar2 == (char *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_port_info_create",0x120);
    return 0;
  }
  pcVar2[4] = '\0';
  pcVar2[5] = '\0';
  pcVar2[6] = '\0';
  pcVar2[7] = '\0';
  if (*param_1 == 0) {
LAB_005b85a0:
    uVar3 = cw_priv_port_info_length(pcVar2);
    iVar1 = cw_protocol_msg_ele_create(0xa2,uVar3,pcVar2);
    if (iVar1 == 0) {
      if (capwap_err_switch == 0) {
        cVar5 = *pcVar2;
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          cVar5 = *pcVar2;
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_port_info_create",0x13b);
          cVar5 = *pcVar2;
        }
      }
      if ((cVar5 != '\0') && (*(int *)(pcVar2 + 4) != 0)) {
        FUN_00407df0();
        pcVar2[4] = '\0';
        pcVar2[5] = '\0';
        pcVar2[6] = '\0';
        pcVar2[7] = '\0';
      }
      FUN_00407df0(pcVar2);
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        __format = "[CW_ERROR]%32s():%4d phy info is null\n";
        uVar3 = 0x12a;
LAB_005b86e0:
        printf(__format,"cw_priv_port_info_create",uVar3);
      }
    }
    else {
      iVar1 = cw_protocol_clone(*(int *)(param_1 + 4),(uint)*param_1 << 3);
      *(int *)(pcVar2 + 4) = iVar1;
      if (iVar1 != 0) goto LAB_005b85a0;
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone wlan info\n";
        uVar3 = 0x131;
        goto LAB_005b86e0;
      }
    }
    FUN_00407df0(pcVar2);
    iVar1 = 0;
  }
  return iVar1;
}

