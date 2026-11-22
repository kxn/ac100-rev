// func cw_priv_wtp_sub_capability_free @ 005d03a0 size=76

undefined4 cw_priv_wtp_sub_capability_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(int *)(*(int *)(param_1 + 0x10) + 4) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

