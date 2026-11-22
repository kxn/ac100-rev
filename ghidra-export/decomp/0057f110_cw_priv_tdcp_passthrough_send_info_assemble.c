// func cw_priv_tdcp_passthrough_send_info_assemble @ 0057f110 size=144

undefined4 cw_priv_tdcp_passthrough_send_info_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*puVar3);
  cw_protocol_restore32(param_1,puVar3[1]);
  cw_protocol_restore8(param_1,*(undefined1 *)(puVar3 + 2));
  cw_protocol_restore_raw_bytes(param_1,puVar3[3],*(undefined2 *)((int)puVar3 + 6));
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

