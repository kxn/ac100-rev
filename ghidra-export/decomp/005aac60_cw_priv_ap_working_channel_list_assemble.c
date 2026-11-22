// func cw_priv_ap_working_channel_list_assemble @ 005aac60 size=148

undefined4 cw_priv_ap_working_channel_list_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 0;
  puVar5 = *(undefined4 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  puVar2 = puVar5;
  while( true ) {
    iVar4 = iVar4 + 4;
    cw_protocol_restore32(param_1,*puVar2);
    if (iVar4 == 0x18) break;
    puVar2 = (undefined4 *)((int)puVar5 + iVar4);
  }
  uVar3 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

