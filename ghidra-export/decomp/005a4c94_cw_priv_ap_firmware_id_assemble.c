// func cw_priv_ap_firmware_id_assemble @ 005a4c94 size=192

undefined4 cw_priv_ap_firmware_id_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  iVar6 = *(int *)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore_raw_bytes(param_1,iVar6,0x10);
  cw_protocol_restore8(param_1,*(undefined1 *)(iVar6 + 0x10));
  if (*(char *)(iVar6 + 0x10) == '\0') {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    bVar3 = *(char *)(iVar6 + 0x10) != '\0';
    while (bVar3) {
      iVar4 = iVar7 * 0x10;
      iVar7 = iVar7 + 1;
      cw_protocol_restore_raw_bytes(param_1,*(int *)(iVar6 + 0x14) + iVar4,0x10);
      bVar3 = iVar7 < (int)(uint)*(byte *)(iVar6 + 0x10);
    }
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar5 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar5 = 0;
  }
  return uVar5;
}

