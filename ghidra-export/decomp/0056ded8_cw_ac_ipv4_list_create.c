// func cw_ac_ipv4_list_create @ 0056ded8 size=304

int cw_ac_ipv4_list_create(ushort *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    iVar4 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value of ac ipv4 list\n","cw_ac_ipv4_list_create"
             ,0xc2);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 4) = 0;
    iVar4 = 0;
    if ((*param_1 != 0) && (*(int *)(param_1 + 2) != 0)) {
      iVar4 = (*param_1 & 0x3fff) << 2;
      uVar2 = cw_protocol_clone(*(int *)(param_1 + 2),iVar4);
      *(undefined4 *)(iVar1 + 4) = uVar2;
    }
    iVar4 = cw_protocol_msg_ele_create(2,iVar4,iVar1);
    if (iVar4 == 0) {
      if (capwap_err_switch == 0) {
        iVar3 = *(int *)(iVar1 + 4);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create ac ipv4 list\n","cw_ac_ipv4_list_create",
                 0xd8);
          iVar3 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar3 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar4;
}

