// func cw_radio_administrative_state_free @ 0057f4b8 size=60

undefined4 cw_radio_administrative_state_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

