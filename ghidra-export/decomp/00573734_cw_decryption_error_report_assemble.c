// func cw_decryption_error_report_assemble @ 00573734 size=476

undefined4 cw_decryption_error_report_assemble(int param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  sVar1 = *(short *)(param_2 + 0xe);
  uVar2 = *(ushort *)(param_1 + 4);
  if (*pbVar6 < 0x20) {
    cw_protocol_restore8();
    if (pbVar6[1] == 0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      uVar5 = (uint)pbVar6[1];
      __format = "[CW_ERROR]%32s():%4d num of entries(%d) is wrong\n";
      uVar4 = 0xb8;
    }
    else {
      cw_protocol_restore8(param_1);
      if ((pbVar6[2] == 6) || (pbVar6[2] == 8)) {
        cw_protocol_restore8(param_1);
        if (((ushort)(sVar1 + -3) == (ushort)((ushort)pbVar6[1] * (ushort)pbVar6[2])) &&
           (*(int *)(pbVar6 + 4) != 0)) {
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
               "cw_decryption_error_report_assemble",200);
        return 0xffffffff;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      uVar5 = (uint)pbVar6[2];
      __format = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
      uVar4 = 0xc0;
    }
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar5 = (uint)*pbVar6;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0xb0;
  }
  printf(__format,"cw_decryption_error_report_assemble",uVar4,uVar5);
  return 0xffffffff;
}

