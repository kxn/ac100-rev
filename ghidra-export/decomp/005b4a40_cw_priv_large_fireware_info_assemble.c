// func cw_priv_large_fireware_info_assemble @ 005b4a40 size=156

undefined4 cw_priv_large_fireware_info_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar3);
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar3 + 4));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar3 + 8));
  cw_protocol_restore_raw_bytes(param_1,puVar3 + 0xc,0x10);
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar3 + 0x1c));
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

