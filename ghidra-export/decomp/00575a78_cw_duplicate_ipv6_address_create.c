// func cw_duplicate_ipv6_address_create @ 00575a78 size=384

int cw_duplicate_ipv6_address_create(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = cw_protocol_clone(param_1,0x18);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_duplicate_ipv6_address_create",0xdb);
    return 0;
  }
  *(undefined4 *)(iVar2 + 0x14) = 0;
  if (*(char *)(param_1 + 0x11) == '\x06') {
    iVar3 = *(int *)(param_1 + 0x14);
LAB_00575af0:
    if (iVar3 == 0) {
      bVar1 = *(byte *)(iVar2 + 0x11);
      goto LAB_00575abc;
    }
    iVar3 = cw_protocol_clone();
    *(int *)(iVar2 + 0x14) = iVar3;
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone mac address\n",
               "cw_duplicate_ipv6_address_create",0xe6);
      }
      FUN_00407df0(iVar2);
      return 0;
    }
  }
  else if (*(char *)(param_1 + 0x11) == '\b') {
    iVar3 = *(int *)(param_1 + 0x14);
    goto LAB_00575af0;
  }
  bVar1 = *(byte *)(iVar2 + 0x11);
LAB_00575abc:
  iVar3 = cw_protocol_msg_ele_create(0x16,bVar1 + 0x12,iVar2);
  if (iVar3 == 0) {
    if (capwap_err_switch == 0) {
      iVar4 = *(int *)(iVar2 + 0x14);
    }
    else {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar2 + 0x14);
      }
      else {
        printf("[CW_ERROR]%32s():%4d failed to creat message element\n",
               "cw_duplicate_ipv6_address_create",0xf0);
        iVar4 = *(int *)(iVar2 + 0x14);
      }
    }
    if (iVar4 != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar2);
  }
  return iVar3;
}

