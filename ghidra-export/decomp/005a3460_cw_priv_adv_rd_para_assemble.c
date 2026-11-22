// func cw_priv_adv_rd_para_assemble @ 005a3460 size=500

undefined4 cw_priv_adv_rd_para_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  byte *pbVar7;
  
  pbVar7 = *(byte **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  if (0x1f < *pbVar7) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_adv_rd_para_assemble",0xe4,
           (uint)*pbVar7);
    return 0xffffffff;
  }
  cw_protocol_restore8();
  cw_protocol_restore8(param_1,pbVar7[1]);
  cw_protocol_restore8(param_1,pbVar7[2]);
  cw_protocol_restore8(param_1,pbVar7[3]);
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar7 + 4));
  cw_protocol_restore8(param_1,pbVar7[6]);
  cw_protocol_restore8(param_1,pbVar7[7]);
  cw_protocol_restore8(param_1,pbVar7[8]);
  cw_protocol_restore8(param_1,pbVar7[9]);
  cw_protocol_restore8(param_1,pbVar7[10]);
  cw_protocol_restore8(param_1,pbVar7[0xb]);
  cw_protocol_restore8(param_1,pbVar7[0xc]);
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar7 + 0xe));
  cw_protocol_restore8(param_1,pbVar7[0x10]);
  uVar5 = (uint)*(ushort *)(param_2 + 0xe);
  if ((uVar5 - 0x14 < 2) || (uVar5 == 0x1a)) {
    bVar1 = pbVar7[0x11];
  }
  else {
    if (uVar5 != 0x1b) goto LAB_005a359c;
    bVar1 = pbVar7[0x11];
  }
  cw_protocol_restore8(param_1,bVar1);
  cw_protocol_restore8(param_1,pbVar7[0x12]);
  cw_protocol_restore8(param_1,pbVar7[0x13]);
  cw_protocol_restore8(param_1,pbVar7[0x14]);
  uVar5 = (uint)*(ushort *)(param_2 + 0xe);
LAB_005a359c:
  if ((uVar5 & 1) == 0) {
    uVar3 = *(ushort *)(param_2 + 0xe);
  }
  else {
    cw_protocol_restore8(param_1,pbVar7[0x15]);
    uVar3 = *(ushort *)(param_2 + 0xe);
  }
  if (uVar3 < 0x16) {
    uVar3 = *(ushort *)(param_1 + 4);
  }
  else {
    cw_protocol_restore_raw_bytes(param_1,pbVar7 + 0x16,6);
    uVar3 = *(ushort *)(param_1 + 4);
  }
  uVar6 = 0xffffffff;
  if ((uint)uVar3 - (uint)uVar2 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar6 = 0;
  }
  return uVar6;
}

