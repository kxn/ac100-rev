// func cw_duplicate_ipv4_address_parse @ 00575630 size=548

undefined4 cw_duplicate_ipv4_address_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *__s;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  char *__format;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined4 *)FUN_00408450(0xc,0x67);
  if (__s == (undefined4 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_duplicate_ipv4_address_parse",0x6a);
    return 0xffffffff;
  }
  memset(__s,0,0xc);
  uVar2 = cw_protocol_retrieve32(param_1);
  *__s = uVar2;
  uVar3 = cw_protocol_retrieve8(param_1);
  *(char *)(__s + 1) = (char)uVar3;
  if (uVar3 < 2) {
    iVar4 = cw_protocol_retrieve8(param_1);
    *(char *)((int)__s + 5) = (char)iVar4;
    if ((iVar4 == 6) || (iVar4 == 8)) {
      if (*(ushort *)(param_2 + 0xe) - 6 == iVar4) {
        iVar4 = cw_protocol_retrieve_raw_bytes(param_1,iVar4);
        __s[2] = iVar4;
        if (iVar4 != 0) {
          *(undefined4 **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read mac address\n",
                 "cw_duplicate_ipv4_address_parse",0x8e);
        }
        goto LAB_0057576c;
      }
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0057576c;
      uVar3 = (uint)*(ushort *)(param_2 + 0xe);
      __format = "[CW_ERROR]%32s():%4d length of message element(%d) is wrong\n";
      uVar2 = 0x87;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0057576c;
      uVar3 = (uint)*(byte *)((int)__s + 5);
      __format = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
      uVar2 = 0x7f;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0057576c;
    uVar3 = (uint)*(byte *)(__s + 1);
    __format = "[CW_ERROR]%32s():%4d status(%d) is wrong\n";
    uVar2 = 0x76;
  }
  printf(__format,"cw_duplicate_ipv4_address_parse",uVar2,uVar3);
LAB_0057576c:
  FUN_00407df0(__s);
  return 0xffffffff;
}

