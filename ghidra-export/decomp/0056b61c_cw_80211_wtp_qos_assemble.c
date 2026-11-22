// func cw_80211_wtp_qos_assemble @ 0056b61c size=552

undefined4 cw_80211_wtp_qos_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  pbVar7 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar7 < 0x20) {
    cw_protocol_restore8();
    if ((pbVar7[1] & 0x1f) == pbVar7[1]) {
      iVar2 = 0;
      cw_protocol_restore8(param_1);
      pbVar6 = pbVar7;
      while( true ) {
        cw_protocol_restore8(param_1,pbVar6[2]);
        cw_protocol_restore16(param_1,*(undefined2 *)(pbVar6 + 4));
        cw_protocol_restore16(param_1,*(undefined2 *)(pbVar6 + 6));
        cw_protocol_restore8(param_1,pbVar6[8]);
        if ((pbVar6[9] & 7) != pbVar6[9]) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          __format = "[CW_ERROR]%32s():%4d 8021p(0x%02x) is wrong\n";
          uVar4 = 0xd4;
          uVar5 = (uint)pbVar7[iVar2 * 10 + 9];
          goto LAB_0056b70c;
        }
        cw_protocol_restore8(param_1);
        if ((pbVar6[10] & 0x3f) != pbVar6[10]) break;
        iVar2 = iVar2 + 1;
        cw_protocol_restore8(param_1);
        pbVar6 = pbVar6 + 10;
        if (iVar2 == 4) {
          if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      __format = "[CW_ERROR]%32s():%4d dscp(0x%02x) is wrong\n";
      uVar4 = 0xdc;
      uVar5 = (uint)pbVar7[iVar2 * 10 + 10];
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar5 = (uint)pbVar7[1];
      __format = "[CW_ERROR]%32s():%4d tagging policy(0x%02x) is wrong\n";
      uVar4 = 0xc3;
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
    uVar5 = (uint)*pbVar7;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0xbb;
  }
LAB_0056b70c:
  printf(__format,"cw_80211_wtp_qos_assemble",uVar4,uVar5);
  return 0xffffffff;
}

