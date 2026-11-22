// func cw_80211_tx_power_level_assemble @ 00569f40 size=360

undefined4 cw_80211_tx_power_level_assemble(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  char *__format;
  uint uVar5;
  undefined4 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  pbVar7 = *(byte **)(param_2 + 0x10);
  uVar3 = *(ushort *)(param_1 + 4);
  if (*pbVar7 < 0x20) {
    cw_protocol_restore8();
    uVar5 = (uint)pbVar7[1];
    if (((uVar5 << 1 == *(ushort *)(param_2 + 0xe) - 2) && (uVar5 != 0)) && (uVar5 < 9)) {
      cw_protocol_restore8(param_1);
      pbVar8 = pbVar7;
      for (iVar4 = 0; iVar4 < (int)(uint)pbVar7[1]; iVar4 = iVar4 + 1) {
        pbVar1 = pbVar8 + 2;
        pbVar8 = pbVar8 + 2;
        cw_protocol_restore16(param_1,*(undefined2 *)pbVar1);
      }
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar3 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    bVar2 = pbVar7[1];
    __format = "[CW_ERROR]%32s():%4d num levels(%d) is wrong\n";
    uVar6 = 0xa5;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    bVar2 = *pbVar7;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x9d;
  }
  printf(__format,"cw_80211_tx_power_level_assemble",uVar6,(uint)bVar2);
  return 0xffffffff;
}

