// func cw_priv_wechat_iplist_create @ 005cb1cc size=428

int cw_priv_wechat_iplist_create(int param_1)

{
  int *piVar1;
  int iVar2;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)cw_protocol_clone(param_1,8);
  if (piVar1 == (int *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_wechat_iplist_create",0xbd);
    return 0;
  }
  piVar1[1] = 0;
  if (*piVar1 == 0) {
    iVar3 = *piVar1;
LAB_005cb220:
    iVar3 = cw_protocol_msg_ele_create(0x42,iVar3 + 4U & 0xffff,piVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = piVar1[1];
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = piVar1[1];
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_wechat_iplist_create",0xd8);
          iVar2 = piVar1[1];
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(piVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar4 = 199;
LAB_005cb344:
        printf(__format,"cw_priv_wechat_iplist_create",uVar4);
      }
    }
    else {
      iVar3 = cw_protocol_clone(*(int *)(param_1 + 4),*(undefined2 *)(param_1 + 2));
      piVar1[1] = iVar3;
      if (iVar3 != 0) {
        iVar3 = *piVar1;
        goto LAB_005cb220;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone iplist\n";
        uVar4 = 0xce;
        goto LAB_005cb344;
      }
    }
    FUN_00407df0(piVar1);
    iVar3 = 0;
  }
  return iVar3;
}

