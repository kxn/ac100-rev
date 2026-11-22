// func cw_priv_sta_assoc_req_create @ 005c149c size=416

int cw_priv_sta_assoc_req_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0xc;
  if (*(int *)(param_1 + 8) < 0) {
    iVar3 = 0x10;
  }
  iVar1 = cw_protocol_clone(param_1,0x14);
  if (iVar1 == 0) {
    iVar3 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_sta_assoc_req_create",0x11f);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    if (*(int *)(param_1 + 0xc) == 0) {
      iVar2 = *(int *)(iVar1 + 0xc);
    }
    else if (*(int *)(param_1 + 0x10) == 0) {
      iVar2 = *(int *)(iVar1 + 0xc);
    }
    else {
      *(int *)(iVar1 + 0xc) = *(int *)(param_1 + 0xc);
      iVar2 = cw_protocol_clone(*(undefined4 *)(param_1 + 0x10),*(undefined2 *)(param_1 + 0xe));
      *(int *)(iVar1 + 0x10) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone backfill\n","cw_priv_sta_assoc_req_create",
                 300);
        }
        FUN_00407df0(iVar1);
        return 0;
      }
      iVar2 = *(int *)(iVar1 + 0xc);
    }
    iVar3 = cw_protocol_msg_ele_create(2,iVar3 + iVar2 & 0xffff,iVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 0x10);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_sta_assoc_req_create",0x136);
          iVar2 = *(int *)(iVar1 + 0x10);
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

