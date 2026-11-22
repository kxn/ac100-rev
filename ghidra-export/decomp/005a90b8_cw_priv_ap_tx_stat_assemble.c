// func cw_priv_ap_tx_stat_assemble @ 005a90b8 size=576

undefined4 cw_priv_ap_tx_stat_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  puVar4 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar4);
  cw_protocol_restore_raw_bytes(param_1,puVar4 + 1,3);
  cw_protocol_restore64(param_1);
  cw_protocol_restore64(param_1);
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x18));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x1c));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x20));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x24));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x28));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x2c));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x30));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x34));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x38));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x3c));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x40));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x44));
  puVar2 = puVar4;
  do {
    iVar5 = iVar5 + 4;
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar2 + 0x8c));
    puVar2 = puVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar4 + 0x88));
  puVar2 = puVar4;
  do {
    iVar5 = iVar5 + 4;
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar2 + 0x8c));
    puVar2 = puVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puVar2 = puVar4;
  do {
    iVar5 = iVar5 + 4;
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar2 + 0xcc));
    puVar2 = puVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puVar2 = puVar4;
  do {
    iVar5 = iVar5 + 4;
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar2 + 0x10c));
    puVar2 = puVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puVar2 = puVar4;
  do {
    iVar5 = iVar5 + 4;
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar2 + 0x14c));
    puVar2 = puVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puVar2 = puVar4;
  do {
    iVar5 = iVar5 + 4;
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar2 + 0x18c));
    puVar2 = puVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puVar2 = puVar4;
  while( true ) {
    iVar5 = iVar5 + 4;
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar2 + 0x1cc));
    if (iVar5 == 0x40) break;
    puVar2 = puVar4 + iVar5;
  }
  uVar3 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

