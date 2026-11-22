// func cw_vendor_specific_payload_free @ 005824e4 size=72

undefined4 cw_vendor_specific_payload_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    cw_msg_eles_priv_free(iVar1);
    FUN_00407df0(iVar1);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

