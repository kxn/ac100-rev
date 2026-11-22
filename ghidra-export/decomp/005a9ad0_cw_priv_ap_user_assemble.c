// func cw_priv_ap_user_assemble @ 005a9ad0 size=124

undefined4 cw_priv_ap_user_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore_raw_bytes(param_1,iVar3,0x40);
  cw_protocol_restore_raw_bytes(param_1,iVar3 + 0x40,0x40);
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

