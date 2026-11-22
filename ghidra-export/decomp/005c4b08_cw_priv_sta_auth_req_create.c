// func cw_priv_sta_auth_req_create @ 005c4b08 size=388

int cw_priv_sta_auth_req_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = cw_protocol_clone(param_1,0x10);
  if (iVar1 == 0) {
    iVar3 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_sta_auth_req_create",0xef);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    if (*(int *)(param_1 + 8) == 0) {
      iVar3 = *(int *)(iVar1 + 8);
    }
    else if (*(int *)(param_1 + 0xc) == 0) {
      iVar3 = *(int *)(iVar1 + 8);
    }
    else {
      *(int *)(iVar1 + 8) = *(int *)(param_1 + 8);
      iVar3 = cw_protocol_clone(*(undefined4 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 10));
      *(int *)(iVar1 + 0xc) = iVar3;
      if (iVar3 == 0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone backfill\n","cw_priv_sta_auth_req_create",
                 0xfc);
        }
        FUN_00407df0(iVar1);
        return 0;
      }
      iVar3 = *(int *)(iVar1 + 8);
    }
    iVar3 = cw_protocol_msg_ele_create(1,iVar3 + 0xcU & 0xffff,iVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = *(int *)(iVar1 + 0xc);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 0xc);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_sta_auth_req_create",0x106);
          iVar2 = *(int *)(iVar1 + 0xc);
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar3;
}

