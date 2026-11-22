// func cw_80211_direct_sequence_control_assemble @ 0056553c size=480

undefined4 cw_80211_direct_sequence_control_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar6 < 0x20) {
    cw_protocol_restore8();
    if (pbVar6[1] == 0) {
      cw_protocol_restore8(param_1,0);
      cw_protocol_restore8(param_1,pbVar6[2]);
      if ((pbVar6[3] & 0x1f) == pbVar6[3]) {
        cw_protocol_restore8(param_1);
        cw_protocol_restore32(param_1,*(undefined4 *)(pbVar6 + 4));
        if (*(short *)(param_2 + 0xe) == 0x13) {
          cw_protocol_restore8(param_1,pbVar6[8]);
          cw_protocol_restore8(param_1,pbVar6[0x12]);
          cw_protocol_restore16(param_1,*(undefined2 *)(pbVar6 + 10));
          cw_protocol_restore16(param_1,*(undefined2 *)(pbVar6 + 0xc));
          cw_protocol_restore16(param_1,*(undefined2 *)(pbVar6 + 0xe));
          cw_protocol_restore16(param_1,*(undefined2 *)(pbVar6 + 0x10));
          cw_protocol_restore8(param_1,pbVar6[0x13]);
          uVar2 = *(ushort *)(param_1 + 4);
        }
        else {
          uVar2 = *(ushort *)(param_1 + 4);
        }
        if ((uint)uVar2 - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
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
      uVar5 = (uint)pbVar6[3];
      __format = "[CW_ERROR]%32s():%4d current cca(0x%02x) is wrong\n";
      uVar4 = 0xcf;
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      uVar5 = (uint)pbVar6[1];
      __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
      uVar4 = 0xc4;
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
    uVar4 = 0xbc;
  }
  printf(__format,"cw_80211_direct_sequence_control_assemble",uVar4,uVar5);
  return 0xffffffff;
}

