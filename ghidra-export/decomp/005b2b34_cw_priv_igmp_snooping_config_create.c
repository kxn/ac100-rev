// func cw_priv_igmp_snooping_config_create @ 005b2b34 size=428

int cw_priv_igmp_snooping_config_create(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *__format;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_igmp_snooping_config_create",0xd9
          );
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if (*(byte *)(param_1 + 2) == 0) {
LAB_005b2b84:
    uVar3 = cw_priv_igmp_snooping_config_length(iVar1);
    iVar2 = cw_protocol_msg_ele_create(0x70,uVar3,iVar1);
    if (iVar2 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = *(int *)(iVar1 + 4);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_igmp_snooping_config_create",0xf4);
          iVar4 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d radio list is null\n";
        uVar3 = 0xe3;
LAB_005b2cac:
        printf(__format,"cw_priv_igmp_snooping_config_create",uVar3);
      }
    }
    else {
      iVar2 = cw_protocol_clone(*(int *)(param_1 + 4),(uint)*(byte *)(param_1 + 2) << 2);
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 != 0) goto LAB_005b2b84;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone radio list\n";
        uVar3 = 0xea;
        goto LAB_005b2cac;
      }
    }
    FUN_00407df0(iVar1);
    iVar2 = 0;
  }
  return iVar2;
}

