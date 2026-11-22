// func cw_ac_ipv6_list_create @ 0056e50c size=316

int cw_ac_ipv6_list_create(ushort *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    iVar3 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_ac_ipv6_list_create",0xbe);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 4) = 0;
    if (*param_1 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      if (*(int *)(param_1 + 2) != 0) {
        iVar3 = (*param_1 & 0xfff) << 4;
        iVar2 = cw_protocol_clone(*(int *)(param_1 + 2),iVar3);
        *(int *)(iVar1 + 4) = iVar2;
        if (iVar2 == 0) {
          FUN_00407df0(iVar1);
          return 0;
        }
      }
    }
    iVar3 = cw_protocol_msg_ele_create(3,iVar3,iVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = *(int *)(iVar1 + 4);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message element\n","cw_ac_ipv6_list_create",
                 0xd3);
          iVar2 = *(int *)(iVar1 + 4);
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

