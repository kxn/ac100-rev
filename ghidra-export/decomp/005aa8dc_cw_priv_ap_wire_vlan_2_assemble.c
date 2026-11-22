// func cw_priv_ap_wire_vlan_2_assemble @ 005aa8dc size=148

undefined4 cw_priv_ap_wire_vlan_2_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 *puVar5;
  
  iVar4 = 0;
  puVar5 = *(undefined2 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  puVar2 = puVar5;
  while( true ) {
    iVar4 = iVar4 + 2;
    cw_protocol_restore16(param_1,*puVar2);
    if (iVar4 == 8) break;
    puVar2 = (undefined2 *)((int)puVar5 + iVar4);
  }
  uVar3 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

