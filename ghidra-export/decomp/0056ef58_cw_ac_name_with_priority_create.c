// func cw_ac_name_with_priority_create @ 0056ef58 size=376

int cw_ac_name_with_priority_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_ac_name_with_priority_create",0xa9);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 4) = 0;
    if (*(short *)(param_1 + 2) == 0) {
      sVar4 = *(short *)(iVar1 + 2);
    }
    else if (*(int *)(param_1 + 4) == 0) {
      sVar4 = *(short *)(iVar1 + 2);
    }
    else {
      iVar2 = cw_protocol_duplicate_string();
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone ac name\n","cw_ac_name_with_priority_create",
                 0xb4);
        }
        FUN_00407df0(iVar1);
        return 0;
      }
      sVar4 = *(short *)(iVar1 + 2);
    }
    iVar2 = cw_protocol_msg_ele_create(5,sVar4 + 1,iVar1);
    if (iVar2 == 0) {
      if (capwap_err_switch == 0) {
        iVar3 = *(int *)(iVar1 + 4);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message element\n",
                 "cw_ac_name_with_priority_create",0xbe);
          iVar3 = *(int *)(iVar1 + 4);
        }
      }
      if (iVar3 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

