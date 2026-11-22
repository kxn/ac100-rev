// func cw_priv_wlan_rssi_orient_assemble @ 005cbcec size=140

undefined4 cw_priv_wlan_rssi_orient_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*puVar3);
  cw_protocol_restore16(param_1,*(undefined2 *)(puVar3 + 1));
  cw_protocol_restore8(param_1,*(undefined1 *)((int)puVar3 + 6));
  cw_protocol_restore8(param_1,*(undefined1 *)((int)puVar3 + 7));
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

