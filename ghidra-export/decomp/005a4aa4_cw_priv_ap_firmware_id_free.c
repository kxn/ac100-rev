// func cw_priv_ap_firmware_id_free @ 005a4aa4 size=88

undefined4 cw_priv_ap_firmware_id_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x14) != 0) {
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

