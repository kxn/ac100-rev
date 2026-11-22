// func cw_duplicate_ipv6_address_parse @ 00575d80 size=552

undefined4 cw_duplicate_ipv6_address_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  uint uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x18,0x6d);
  if (__s == (void *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_duplicate_ipv6_address_parse",0x70);
    return 0xffffffff;
  }
  memset(__s,0,0x18);
  cw_protocol_retrieve_bytes(param_1,__s,0x10);
  uVar2 = cw_protocol_retrieve8(param_1);
  *(char *)((int)__s + 0x10) = (char)uVar2;
  if (uVar2 < 2) {
    iVar3 = cw_protocol_retrieve8(param_1);
    *(char *)((int)__s + 0x11) = (char)iVar3;
    if ((iVar3 == 6) || (iVar3 == 8)) {
      if (*(ushort *)(param_2 + 0xe) - 0x12 == iVar3) {
        iVar3 = cw_protocol_retrieve_raw_bytes(param_1,iVar3);
        *(int *)((int)__s + 0x14) = iVar3;
        if (iVar3 != 0) {
          *(void **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read mac address\n",
                 "cw_duplicate_ipv6_address_parse",0x94);
        }
        goto LAB_00575ec0;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00575ec0;
      uVar2 = (uint)*(ushort *)(param_2 + 0xe);
      __format = "[CW_ERROR]%32s():%4d length of message element(%d) is wrong\n";
      uVar4 = 0x8d;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00575ec0;
      uVar2 = (uint)*(byte *)((int)__s + 0x11);
      __format = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
      uVar4 = 0x85;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00575ec0;
    uVar2 = (uint)*(byte *)((int)__s + 0x10);
    __format = "[CW_ERROR]%32s():%4d status(%d) is wrong\n";
    uVar4 = 0x7c;
  }
  printf(__format,"cw_duplicate_ipv6_address_parse",uVar4,uVar2);
LAB_00575ec0:
  FUN_00407df0(__s);
  return 0xffffffff;
}

