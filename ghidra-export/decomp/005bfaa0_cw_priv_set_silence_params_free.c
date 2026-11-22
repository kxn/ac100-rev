// func cw_priv_set_silence_params_free @ 005bfaa0 size=44

undefined4 cw_priv_set_silence_params_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
  }
  return 0;
}

