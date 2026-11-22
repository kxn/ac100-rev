// func cw_priv_chnl_scan_assemble @ 005ad6ec size=240

undefined4 cw_priv_chnl_scan_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  puVar4 = *(undefined1 **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar4);
  cw_protocol_restore8(param_1,puVar4[1]);
  do {
    bVar1 = puVar4[1];
    while( true ) {
      if ((int)(uint)bVar1 <= iVar5) {
        uVar3 = 0xffffffff;
        if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar2 == (uint)*(ushort *)(param_2 + 0xe)) {
          uVar3 = 0;
        }
        return uVar3;
      }
      iVar6 = iVar5 * 8;
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar4 + 4) + iVar6));
      cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar4 + 4) + iVar6 + 1));
      if (*(char *)(*(int *)(puVar4 + 4) + iVar6 + 1) == '\0') break;
      iVar5 = iVar5 + 1;
      cw_protocol_restore_raw_bytes(param_1,*(undefined4 *)(*(int *)(puVar4 + 4) + iVar6 + 4));
      bVar1 = puVar4[1];
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

