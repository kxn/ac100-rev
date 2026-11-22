// func cw_wtp_frame_tunnel_mode_free @ 0058556c size=60

undefined4 cw_wtp_frame_tunnel_mode_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

