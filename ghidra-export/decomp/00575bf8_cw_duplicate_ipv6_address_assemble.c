// func cw_duplicate_ipv6_address_assemble @ 00575bf8 size=392

undefined4 cw_duplicate_ipv6_address_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  cw_protocol_restore_raw_bytes(param_1,iVar5,0x10);
  if (*(byte *)(iVar5 + 0x10) < 2) {
    cw_protocol_restore8(param_1);
    if ((*(char *)(iVar5 + 0x11) == '\x06') || (*(char *)(iVar5 + 0x11) == '\b')) {
      cw_protocol_restore8(param_1);
      if ((*(ushort *)(param_2 + 0xe) - 0x12 == (uint)*(byte *)(iVar5 + 0x11)) &&
         (*(int *)(iVar5 + 0x14) != 0)) {
        cw_protocol_restore_raw_bytes(param_1);
        if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d failed to write mac address\n",
             "cw_duplicate_ipv6_address_assemble",0xc2);
      return 0xffffffff;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = *(byte *)(iVar5 + 0x11);
    __format = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
    uVar4 = 0xba;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = *(byte *)(iVar5 + 0x10);
    __format = "[CW_ERROR]%32s():%4d status(%d) is wrong\n";
    uVar4 = 0xb2;
  }
  printf(__format,"cw_duplicate_ipv6_address_assemble",uVar4,(uint)bVar1);
  return 0xffffffff;
}

