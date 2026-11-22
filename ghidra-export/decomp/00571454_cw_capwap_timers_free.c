// func cw_capwap_timers_free @ 00571454 size=60

undefined4 cw_capwap_timers_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

