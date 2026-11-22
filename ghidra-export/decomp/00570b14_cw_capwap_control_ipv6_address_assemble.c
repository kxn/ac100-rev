// func cw_capwap_control_ipv6_address_assemble @ 00570b14 size=120

undefined4 cw_capwap_control_ipv6_address_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore_raw_bytes(param_1,iVar3,0x10);
  cw_protocol_restore16(param_1,*(undefined2 *)(iVar3 + 0x10));
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

