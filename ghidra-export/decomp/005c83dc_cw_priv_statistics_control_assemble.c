// func cw_priv_statistics_control_assemble @ 005c83dc size=164

undefined4 cw_priv_statistics_control_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar3);
  cw_protocol_restore8(param_1,puVar3[1]);
  cw_protocol_restore8(param_1,puVar3[2]);
  cw_protocol_restore16(param_1,*(undefined2 *)(puVar3 + 4));
  cw_protocol_restore16(param_1,*(undefined2 *)(puVar3 + 6));
  cw_protocol_restore16(param_1,*(undefined2 *)(puVar3 + 8));
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

