// func cw_priv_ap_firmware_id_length @ 005a4950 size=32

int cw_priv_ap_firmware_id_length(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = (uint)*(byte *)(param_1 + 0x10) * 0x10 + 0x11;
  }
  return iVar1;
}

