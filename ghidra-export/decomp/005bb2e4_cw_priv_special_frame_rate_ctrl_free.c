// func cw_priv_special_frame_rate_ctrl_free @ 005bb2e4 size=76

undefined4 cw_priv_special_frame_rate_ctrl_free(int param_1)

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

