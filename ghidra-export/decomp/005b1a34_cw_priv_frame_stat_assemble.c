// func cw_priv_frame_stat_assemble @ 005b1a34 size=564

undefined4 cw_priv_frame_stat_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar4 < 0x20) {
    cw_protocol_restore8();
    cw_protocol_restore_raw_bytes(param_1,pbVar4 + 1,3);
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 4));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 8));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0xc));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x10));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x14));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x18));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x1c));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x20));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x24));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x28));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x2c));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x30));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x34));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x38));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x3c));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x40));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x44));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x48));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x4c));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x50));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x54));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x58));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x5c));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x60));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 100));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x68));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x6c));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x70));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x74));
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 0x78));
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_frame_stat_assemble",0xf0,
             (uint)*pbVar4);
    }
  }
  return uVar3;
}

