// func cw_priv_config_extension_create @ 005bf718 size=280

int cw_priv_config_extension_create(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = cw_protocol_clone(param_1,0xc);
  if (iVar1 == 0) {
    iVar3 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_config_extension_create",0xba);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0;
    uVar2 = cw_protocol_clone(*(undefined4 *)(param_1 + 8),*(undefined2 *)(param_1 + 6));
    *(undefined4 *)(iVar1 + 8) = uVar2;
    iVar3 = cw_protocol_msg_ele_create(0xc0,*(int *)(iVar1 + 4) + 5U & 0xffff,iVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = *(int *)(iVar1 + 8);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar1 + 8);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_config_extension_create",0xc4);
          iVar4 = *(int *)(iVar1 + 8);
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 8) = 0;
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar3;
}

