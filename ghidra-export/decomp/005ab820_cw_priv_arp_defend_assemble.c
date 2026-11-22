// func cw_priv_arp_defend_assemble @ 005ab820 size=244

undefined4 cw_priv_arp_defend_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  puVar5 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar5);
  cw_protocol_restore8(param_1,puVar5[1]);
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar5 + 4));
  if (*(int *)(puVar5 + 4) == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    bVar3 = 0 < *(int *)(puVar5 + 4);
    while (iVar7 = iVar6 * 0xc, bVar3) {
      iVar6 = iVar6 + 1;
      cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(puVar5 + 8) + iVar7));
      cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar5 + 8) + iVar7 + 4,6);
      bVar3 = iVar6 < *(int *)(puVar5 + 4);
    }
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar4 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar4 = 0;
  }
  return uVar4;
}

