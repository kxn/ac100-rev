// func cw_priv_clr_stat_assemble @ 005ae558 size=112

undefined4 cw_priv_clr_stat_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if (*(short *)(param_2 + 0xe) == 0) {
    uVar2 = *(ushort *)(param_1 + 4);
  }
  else {
    cw_protocol_restore32(param_1,**(undefined4 **)(param_2 + 0x10));
    uVar2 = *(ushort *)(param_1 + 4);
  }
  uVar3 = 0xffffffff;
  if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar3 = 0;
  }
  return uVar3;
}

