// func cw_priv_tdcp_passthrough_send_info_free @ 0057eef4 size=72

undefined4 cw_priv_tdcp_passthrough_send_info_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xc) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
  }
  return 0;
}

