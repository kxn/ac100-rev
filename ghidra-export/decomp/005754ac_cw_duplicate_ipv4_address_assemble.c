// func cw_duplicate_ipv4_address_assemble @ 005754ac size=388

undefined4 cw_duplicate_ipv4_address_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*puVar5);
  if (*(byte *)(puVar5 + 1) < 2) {
    cw_protocol_restore8(param_1);
    if ((*(char *)((int)puVar5 + 5) == '\x06') || (*(char *)((int)puVar5 + 5) == '\b')) {
      cw_protocol_restore8(param_1);
      if ((*(ushort *)(param_2 + 0xe) - 6 == (uint)*(byte *)((int)puVar5 + 5)) && (puVar5[2] != 0))
      {
        cw_protocol_restore_raw_bytes(param_1);
        if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d failed to write mac address\n",
             "cw_duplicate_ipv4_address_assemble",0xbc);
      return 0xffffffff;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = *(byte *)((int)puVar5 + 5);
    __format = "[CW_ERROR]%32s():%4d length of mac addrss(%d) is wrong\n";
    uVar4 = 0xb4;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = *(byte *)(puVar5 + 1);
    __format = "[CW_ERROR]%32s():%4d status(%d) is wrong\n";
    uVar4 = 0xac;
  }
  printf(__format,"cw_duplicate_ipv4_address_assemble",uVar4,(uint)bVar1);
  return 0xffffffff;
}

