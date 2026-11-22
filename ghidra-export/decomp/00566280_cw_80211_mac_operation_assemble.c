// func cw_80211_mac_operation_assemble @ 00566280 size=344

undefined4 cw_80211_mac_operation_assemble(int param_1,int param_2)

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
    if (pbVar5[1] == 0) {
      cw_protocol_restore8(param_1,0);
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 2));
      cw_protocol_restore8(param_1,pbVar5[4]);
      cw_protocol_restore8(param_1,pbVar5[5]);
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 6));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar5 + 8));
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar5 + 0xc));
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
    __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t zeroed\n";
    uVar4 = 0xd2;
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
    uVar4 = 0xca;
  }
  printf(__format,"cw_80211_mac_operation_assemble",uVar4,(uint)bVar1);
  return 0xffffffff;
}

