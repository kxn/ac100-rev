// func cw_wtp_descriptor_assemble @ 00584674 size=772

undefined4 cw_wtp_descriptor_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  byte *pbVar7;
  
  pbVar7 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (((*pbVar7 < pbVar7[1]) || (*(int *)(pbVar7 + 0xc) == 0)) || (*(int *)(pbVar7 + 0x18) == 0)) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar4 = "[CW_ERROR]%32s():%4d failed to write value\n";
      uVar5 = 0x14b;
LAB_0058484c:
      printf(pcVar4,"cw_wtp_descriptor_assemble",uVar5);
    }
  }
  else {
    cw_protocol_restore8();
    cw_protocol_restore8(param_1,pbVar7[1]);
    cw_protocol_restore8(param_1,pbVar7[0xf]);
    for (iVar2 = FUN_004081b0(pbVar7 + 4); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      if ((*(byte *)(iVar2 + 0xc) & 0x1f) != *(byte *)(iVar2 + 0xc)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        uVar6 = (uint)*(byte *)(iVar2 + 0xc);
        pcVar4 = "[CW_ERROR]%32s():%4d wbid of encryption(0x%02x) is wrong\n";
        uVar5 = 0x15a;
        goto LAB_00584890;
      }
      if ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) < 3) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar4 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
        uVar5 = 0x15f;
        goto LAB_0058484c;
      }
      cw_protocol_restore8(param_1);
      cw_protocol_restore16(param_1,*(undefined2 *)(iVar2 + 0xe));
    }
    iVar2 = FUN_004081b0(pbVar7 + 0x10);
    while( true ) {
      if (iVar2 == 0) {
        if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if (3 < *(ushort *)(iVar2 + 0x10)) break;
      if ((*(ushort *)(iVar2 + 0x12) == 0) || (*(int *)(iVar2 + 0x14) == 0)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        uVar6 = (uint)*(ushort *)(iVar2 + 0x12);
        pcVar4 = "[CW_ERROR]%32s():%4d length(%d) is wrong\n";
        uVar5 = 0x175;
        goto LAB_00584890;
      }
      if ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) <
          (int)(*(ushort *)(iVar2 + 0x12) + 8)) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar4 = "[CW_ERROR]%32s():%4d remaining packet buffer isn\'t enough\n";
        uVar5 = 0x17a;
        goto LAB_0058484c;
      }
      cw_protocol_restore32(param_1,*(undefined4 *)(iVar2 + 0xc));
      cw_protocol_restore16(param_1,*(undefined2 *)(iVar2 + 0x10));
      cw_protocol_restore16(param_1,*(undefined2 *)(iVar2 + 0x12));
      cw_protocol_restore_raw_bytes
                (param_1,*(undefined4 *)(iVar2 + 0x14),*(undefined2 *)(iVar2 + 0x12));
      iVar2 = FUN_00408680(iVar2);
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar6 = (uint)*(ushort *)(iVar2 + 0x10);
    pcVar4 = "[CW_ERROR]%32s():%4d type(%d) is wrong\n";
    uVar5 = 0x170;
LAB_00584890:
    printf(pcVar4,"cw_wtp_descriptor_assemble",uVar5,uVar6);
  }
  return 0xffffffff;
}

