// func cw_add_mac_acl_entry_create @ 0056f798 size=404

int cw_add_mac_acl_entry_create(byte *param_1)

{
  int iVar1;
  ushort uVar3;
  int iVar2;
  int iVar4;
  short sVar5;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_add_mac_acl_entry_create",0xd1);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 4) = 0;
    if (*param_1 == 0) {
      sVar5 = 0;
    }
    else if (*(int *)(param_1 + 4) == 0) {
      sVar5 = 0;
    }
    else {
      uVar3 = (ushort)param_1[1];
      if ((uVar3 == 6) || (sVar5 = 0, uVar3 == 8)) {
        sVar5 = uVar3 * *param_1;
        iVar2 = cw_protocol_clone(*(int *)(param_1 + 4),sVar5);
        *(int *)(iVar1 + 4) = iVar2;
        if (iVar2 == 0) {
          if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to clone mac address\n",
                   "cw_add_mac_acl_entry_create",0xdd);
          }
          FUN_00407df0(iVar1);
          return 0;
        }
      }
    }
    iVar2 = cw_protocol_msg_ele_create(7,sVar5 + 2,iVar1);
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
          printf("[CW_ERROR]%32s():%4d failed to create message element\n",
                 "cw_add_mac_acl_entry_create",0xe7);
          iVar4 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

