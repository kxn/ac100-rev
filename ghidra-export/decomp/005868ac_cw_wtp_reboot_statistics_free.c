// func cw_wtp_reboot_statistics_free @ 005868ac size=60

undefined4 cw_wtp_reboot_statistics_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

