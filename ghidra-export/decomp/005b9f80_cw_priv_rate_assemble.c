// func cw_priv_rate_assemble @ 005b9f80 size=356

undefined4 cw_priv_rate_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar4 < 0x20) {
    cw_protocol_restore8();
    cw_protocol_restore_raw_bytes(param_1,pbVar4 + 1,8);
    cw_protocol_restore_raw_bytes(param_1,pbVar4 + 9,8);
    cw_protocol_restore8(param_1,pbVar4[0x11]);
    cw_protocol_restore_raw_bytes(param_1,pbVar4 + 0x12,4);
    cw_protocol_restore_raw_bytes(param_1,pbVar4 + 0x16,4);
    cw_protocol_restore8(param_1,pbVar4[0x1a]);
    cw_protocol_restore_raw_bytes(param_1,pbVar4 + 0x1b,0xc);
    cw_protocol_restore_raw_bytes(param_1,pbVar4 + 0x27,0xc);
    cw_protocol_restore8(param_1,pbVar4[0x33]);
    cw_protocol_restore8(param_1,pbVar4[0x34]);
    cw_protocol_restore8(param_1,pbVar4[0x35]);
    cw_protocol_restore8(param_1,pbVar4[0x36]);
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_priv_rate_assemble",0xbf,
             (uint)*pbVar4);
    }
  }
  return uVar3;
}

