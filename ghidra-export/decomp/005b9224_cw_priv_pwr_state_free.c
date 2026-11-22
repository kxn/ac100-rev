// func cw_priv_pwr_state_free @ 005b9224 size=60

undefined4 cw_priv_pwr_state_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

