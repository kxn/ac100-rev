// func cw_priv_roaming_control_assemble @ 005bcb9c size=360

undefined4 cw_priv_roaming_control_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar3);
  cw_protocol_restore8(param_1,puVar3[1]);
  cw_protocol_restore8(param_1,puVar3[2]);
  cw_protocol_restore8(param_1,puVar3[3]);
  cw_protocol_restore8(param_1,puVar3[4]);
  cw_protocol_restore8(param_1,puVar3[5]);
  cw_protocol_restore8(param_1,puVar3[6]);
  cw_protocol_restore8(param_1,puVar3[7]);
  cw_protocol_restore8(param_1,puVar3[8]);
  cw_protocol_restore8(param_1,puVar3[9]);
  cw_protocol_restore8(param_1,puVar3[10]);
  cw_protocol_restore8(param_1,puVar3[0xb]);
  cw_protocol_restore8(param_1,puVar3[0xc]);
  cw_protocol_restore8(param_1,puVar3[0xd]);
  cw_protocol_restore8(param_1,puVar3[0xe]);
  cw_protocol_restore8(param_1,puVar3[0xf]);
  cw_protocol_restore8(param_1,puVar3[0x10]);
  cw_protocol_restore8(param_1,puVar3[0x11]);
  cw_protocol_restore8(param_1,puVar3[0x12]);
  cw_protocol_restore8(param_1,puVar3[0x13]);
  cw_protocol_restore8(param_1,puVar3[0x14]);
  cw_protocol_restore_raw_bytes(param_1,puVar3 + 0x15,0xf);
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

