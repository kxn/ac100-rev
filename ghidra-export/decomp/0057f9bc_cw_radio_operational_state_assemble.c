// func cw_radio_operational_state_assemble @ 0057f9bc size=356

undefined4 cw_radio_operational_state_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar5 < 0x20) {
    cw_protocol_restore8();
    if (pbVar5[1] - 1 < 2) {
      cw_protocol_restore8(param_1);
      if (pbVar5[2] < 4) {
        cw_protocol_restore8(param_1);
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
      uVar4 = (uint)pbVar5[2];
      __format = "[CW_ERROR]%32s():%4d cause(%d) is wrong\n";
      uVar3 = 0xba;
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
      __format = "[CW_ERROR]%32s():%4d state(%d) is wrong\n";
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
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar3 = 0xa9;
  }
  printf(__format,"cw_radio_operational_state_assemble",uVar3,uVar4);
  return 0xffffffff;
}

