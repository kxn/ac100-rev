// func cw_add_mac_acl_entry_assemble @ 0056f92c size=396

undefined4 cw_add_mac_acl_entry_assemble(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  sVar2 = *(short *)(param_2 + 0xe);
  uVar3 = *(ushort *)(param_1 + 4);
  if (*pbVar6 == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    bVar1 = *pbVar6;
    __format = "[CW_ERROR]%32s():%4d num of entries(%d) is wrong\n";
    uVar5 = 0xa7;
  }
  else {
    cw_protocol_restore8();
    if ((pbVar6[1] == 6) || (pbVar6[1] == 8)) {
      cw_protocol_restore8(param_1);
      if (((ushort)(sVar2 + -2) == (ushort)((ushort)*pbVar6 * (ushort)pbVar6[1])) &&
         (*(int *)(pbVar6 + 4) != 0)) {
        cw_protocol_restore_raw_bytes(param_1);
        if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar3 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d failed to write mac address\n","cw_add_mac_acl_entry_assemble",
             0xb7);
      return 0xffffffff;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    bVar1 = pbVar6[1];
    __format = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
    uVar5 = 0xaf;
  }
  printf(__format,"cw_add_mac_acl_entry_assemble",uVar5,(uint)bVar1);
  return 0xffffffff;
}

