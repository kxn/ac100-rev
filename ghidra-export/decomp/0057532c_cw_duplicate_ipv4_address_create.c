// func cw_duplicate_ipv4_address_create @ 0057532c size=384

int cw_duplicate_ipv4_address_create(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = cw_protocol_clone(param_1,0xc);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_duplicate_ipv4_address_create",0xd5);
    return 0;
  }
  *(undefined4 *)(iVar2 + 8) = 0;
  if (*(char *)(param_1 + 5) == '\x06') {
    iVar3 = *(int *)(param_1 + 8);
LAB_005753a4:
    if (iVar3 == 0) {
      bVar1 = *(byte *)(iVar2 + 5);
      goto LAB_00575370;
    }
    iVar3 = cw_protocol_clone();
    *(int *)(iVar2 + 8) = iVar3;
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone mac address\n",
               "cw_duplicate_ipv4_address_create",0xe0);
      }
      FUN_00407df0(iVar2);
      return 0;
    }
  }
  else if (*(char *)(param_1 + 5) == '\b') {
    iVar3 = *(int *)(param_1 + 8);
    goto LAB_005753a4;
  }
  bVar1 = *(byte *)(iVar2 + 5);
LAB_00575370:
  iVar3 = cw_protocol_msg_ele_create(0x15,bVar1 + 6,iVar2);
  if (iVar3 == 0) {
    if (capwap_err_switch == 0) {
      iVar4 = *(int *)(iVar2 + 8);
    }
    else {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar2 + 8);
      }
      else {
        printf("[CW_ERROR]%32s():%4d failed to create message element\n",
               "cw_duplicate_ipv4_address_create",0xea);
        iVar4 = *(int *)(iVar2 + 8);
      }
    }
    if (iVar4 != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar2);
  }
  return iVar3;
}

