// func cw_priv_join_request_transmit_assemble @ 005b40fc size=116

undefined4 cw_priv_join_request_transmit_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  puVar3 = *(undefined2 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore16(param_1,*puVar3);
  cw_protocol_restore16(param_1,puVar3[1]);
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

