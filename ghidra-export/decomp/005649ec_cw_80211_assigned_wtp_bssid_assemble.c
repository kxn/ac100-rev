// func cw_80211_assigned_wtp_bssid_assemble @ 005649ec size=288

undefined4 cw_80211_assigned_wtp_bssid_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  if (*pbVar5 < 0x20) {
    cw_protocol_restore8();
    if (pbVar5[1] < 0x11) {
      cw_protocol_restore8(param_1);
      cw_protocol_restore_raw_bytes(param_1,pbVar5 + 2,6);
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
    bVar1 = pbVar5[1];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar4 = 0xa2;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    bVar1 = *pbVar5;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x9a;
  }
  printf(__format,"cw_80211_assigned_wtp_bssid_assemble",uVar4,(uint)bVar1);
  return 0xffffffff;
}

