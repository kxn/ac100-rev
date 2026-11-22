// func cw_80211_rsna_error_report_assemble @ 00567d14 size=452

undefined4 cw_80211_rsna_error_report_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore_raw_bytes(param_1,iVar5,6);
  cw_protocol_restore_raw_bytes(param_1,iVar5 + 6,6);
  if (*(byte *)(iVar5 + 0xc) < 0x20) {
    cw_protocol_restore8(param_1);
    if (*(byte *)(iVar5 + 0xd) < 0x11) {
      cw_protocol_restore8(param_1);
      if (*(short *)(iVar5 + 0xe) == 0) {
        cw_protocol_restore16(param_1,0);
        cw_protocol_restore32(param_1,*(undefined4 *)(iVar5 + 0x10));
        cw_protocol_restore32(param_1,*(undefined4 *)(iVar5 + 0x14));
        cw_protocol_restore32(param_1,*(undefined4 *)(iVar5 + 0x18));
        cw_protocol_restore32(param_1,*(undefined4 *)(iVar5 + 0x1c));
        cw_protocol_restore32(param_1,*(undefined4 *)(iVar5 + 0x20));
        cw_protocol_restore32(param_1,*(undefined4 *)(iVar5 + 0x24));
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
      uVar4 = (uint)*(ushort *)(iVar5 + 0xe);
      __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
      uVar3 = 0xd1;
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)*(byte *)(iVar5 + 0xd);
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar3 = 0xc9;
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
    uVar4 = (uint)*(byte *)(iVar5 + 0xc);
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar3 = 0xc1;
  }
  printf(__format,"cw_80211_rsna_error_report_assemble",uVar3,uVar4);
  return 0xffffffff;
}

