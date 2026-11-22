// func cw_priv_ap_config_checksum_assemble @ 005a4734 size=96

undefined4 cw_priv_ap_config_checksum_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore_raw_bytes(param_1,*(undefined4 *)(param_2 + 0x10),0x10);
  uVar2 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar2 = 0;
  }
  return uVar2;
}

