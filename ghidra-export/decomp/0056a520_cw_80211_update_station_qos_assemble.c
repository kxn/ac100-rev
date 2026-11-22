// func cw_80211_update_station_qos_assemble @ 0056a520 size=428

undefined4 cw_80211_update_station_qos_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  byte *pbVar8;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar6 < 0x20) {
    iVar2 = 0;
    cw_protocol_restore8();
    cw_protocol_restore_raw_bytes(param_1,pbVar6 + 1,6);
    pbVar8 = pbVar6;
    do {
      if ((pbVar8[7] & 7) != pbVar8[7]) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        __format = "[CW_ERROR]%32s():%4d 8021p(0x%02x) is wrong\n";
        uVar5 = (uint)pbVar6[iVar2 * 2 + 7];
        uVar4 = 0xbd;
        goto LAB_0056a63c;
      }
      cw_protocol_restore8(param_1);
      if ((pbVar8[8] & 0x3f) != pbVar8[8]) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        __format = "[CW_ERROR]%32s():%4d dscp(0x%02x) is wrong\n";
        uVar5 = (uint)pbVar6[iVar2 * 2 + 8];
        uVar4 = 0xc5;
        goto LAB_0056a63c;
      }
      iVar2 = iVar2 + 1;
      cw_protocol_restore8(param_1);
      pbVar8 = pbVar8 + 2;
    } while (iVar2 != 4);
    uVar7 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      uVar5 = (uint)*pbVar6;
      __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
      uVar4 = 0xaf;
LAB_0056a63c:
      uVar7 = 0xffffffff;
      printf(__format,"cw_80211_update_station_qos_assemble",uVar4,uVar5);
    }
  }
  return uVar7;
}

