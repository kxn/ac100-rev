// func cw_priv_sta_ip_list_create @ 005c6224 size=436

int cw_priv_sta_ip_list_create(int *param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_sta_ip_list_create",0xe6);
    return 0;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if (*param_1 == 0) {
LAB_005c627c:
    uVar3 = cw_priv_sta_ip_list_length(iVar1);
    iVar4 = cw_protocol_msg_ele_create(0x4d,uVar3,iVar1);
    if (iVar4 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = *(int *)(iVar1 + 4);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_sta_ip_list_create",0x101);
          iVar2 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  else {
    if (param_1[1] == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        __format = "[CW_ERROR]%32s():%4d ip list is null\n";
        uVar3 = 0xf0;
LAB_005c63a4:
        printf(__format,"cw_priv_sta_ip_list_create",uVar3);
      }
    }
    else {
      iVar4 = cw_protocol_clone(param_1[1],*param_1 * 0x1c & 0xfffc);
      *(int *)(iVar1 + 4) = iVar4;
      if (iVar4 != 0) goto LAB_005c627c;
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone ip list\n";
        uVar3 = 0xf7;
        goto LAB_005c63a4;
      }
    }
    FUN_00407df0(iVar1);
    iVar4 = 0;
  }
  return iVar4;
}

