// func cw_80211_delete_wlan_assemble @ 00564e94 size=264

undefined4 cw_80211_delete_wlan_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar4 < 0x20) {
    cw_protocol_restore8();
    if (pbVar4[1] < 0x11) {
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
    uVar3 = 0x9d;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar3 = 0x95;
  }
  printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_80211_delete_wlan_assemble",uVar3,
         (uint)*pbVar4);
  return 0xffffffff;
}

