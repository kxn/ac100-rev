// func cw_wtp_radio_statistics_assemble @ 00586308 size=388

undefined4 cw_wtp_radio_statistics_assemble(int param_1,int param_2)

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
    if (0xfa < (byte)(pbVar5[1] - 4)) {
      cw_protocol_restore8(param_1);
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 2));
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 4));
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 6));
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 8));
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 10));
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 0xc));
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 0xe));
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 0x10));
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 0x12));
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
    __format = "[CW_ERROR]%32s():%4d last fail type(%d) is wrong\n";
    uVar4 = 0xc3;
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
    uVar4 = 0xb9;
  }
  printf(__format,"cw_wtp_radio_statistics_assemble",uVar4,(uint)bVar1);
  return 0xffffffff;
}

