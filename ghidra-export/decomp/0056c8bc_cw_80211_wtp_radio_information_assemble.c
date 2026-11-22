// func cw_80211_wtp_radio_information_assemble @ 0056c8bc size=276

undefined4 cw_80211_wtp_radio_information_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if ((*(uint *)(pbVar5 + 4) & 0x3f) == *(uint *)(pbVar5 + 4)) {
    cw_protocol_restore8(param_1,*pbVar5);
    if (*pbVar5 < 0x20) {
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar5 + 4));
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
    uVar4 = (uint)*pbVar5;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar3 = 0xad;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar4 = *(uint *)(pbVar5 + 4);
    __format = "[CW_ERROR]%32s():%4d radio type(0x%08x) is wrong\n";
    uVar3 = 0xa5;
  }
  printf(__format,"cw_80211_wtp_radio_information_assemble",uVar3,uVar4);
  return 0xffffffff;
}

