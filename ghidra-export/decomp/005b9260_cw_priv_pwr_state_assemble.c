// func cw_priv_pwr_state_assemble @ 005b9260 size=148

undefined4 cw_priv_pwr_state_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar3 < 0x20) {
    cw_protocol_restore8();
    cw_protocol_restore8(param_1,pbVar3[1]);
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  else {
    printf("radio id(%d) is wrong");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

