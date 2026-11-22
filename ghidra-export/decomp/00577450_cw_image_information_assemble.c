// func cw_image_information_assemble @ 00577450 size=120

undefined4 cw_image_information_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore32(param_1,*puVar3);
  cw_protocol_restore_raw_bytes(param_1,puVar3 + 1,0x10);
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

