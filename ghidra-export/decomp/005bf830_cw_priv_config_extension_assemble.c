// func cw_priv_config_extension_assemble @ 005bf830 size=148

undefined4 cw_priv_config_extension_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  puVar4 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar4);
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 4));
  if (*(uint *)(puVar4 + 4) == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    cw_protocol_restore_raw_bytes
              (param_1,*(undefined4 *)(puVar4 + 8),*(uint *)(puVar4 + 4) & 0xffff);
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

