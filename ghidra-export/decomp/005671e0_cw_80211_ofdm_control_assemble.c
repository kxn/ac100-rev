// func cw_80211_ofdm_control_assemble @ 005671e0 size=376

undefined4 cw_80211_ofdm_control_assemble(int param_1,int param_2)

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
    if (pbVar5[1] == 0) {
      cw_protocol_restore8(param_1,0);
      cw_protocol_restore8(param_1,pbVar5[2]);
      if ((pbVar5[3] & 0x7f) == pbVar5[3]) {
        cw_protocol_restore8(param_1);
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
      uVar4 = (uint)pbVar5[3];
      __format = "[CW_ERROR]%32s():%4d band support(%d) is wrong\n";
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
      __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
      uVar3 = 0xae;
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
    uVar3 = 0xa6;
  }
  printf(__format,"cw_80211_ofdm_control_assemble",uVar3,uVar4);
  return 0xffffffff;
}

