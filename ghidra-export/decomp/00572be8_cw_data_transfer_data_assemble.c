// func cw_data_transfer_data_assemble @ 00572be8 size=464

undefined4 cw_data_transfer_data_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*pbVar5 - 1 < 2) || (*pbVar5 == 5)) {
    cw_protocol_restore8(param_1);
    if (pbVar5[1] - 1 < 2) {
      cw_protocol_restore8(param_1);
      if (((uint)*(ushort *)(pbVar5 + 2) == *(ushort *)(param_2 + 0xe) - 4) &&
         (*(ushort *)(pbVar5 + 2) != 0)) {
        cw_protocol_restore16(param_1);
        if (*(int *)(pbVar5 + 4) != 0) {
          cw_protocol_restore_raw_bytes(param_1,*(int *)(pbVar5 + 4),*(undefined2 *)(pbVar5 + 2));
          if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d data is null\n","cw_data_transfer_data_assemble",0xc1);
        return 0xffffffff;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)*(ushort *)(pbVar5 + 2);
      __format = "[CW_ERROR]%32s():%4d length of data(%d) is wrong\n";
      uVar3 = 0xb9;
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)pbVar5[1];
      __format = "[CW_ERROR]%32s():%4d mode(%d) is wrong\n";
      uVar3 = 0xb1;
    }
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar4 = (uint)*pbVar5;
    __format = "[CW_ERROR]%32s():%4d type(%d) is wrong\n";
    uVar3 = 0xa9;
  }
  printf(__format,"cw_data_transfer_data_assemble",uVar3,uVar4);
  return 0xffffffff;
}

