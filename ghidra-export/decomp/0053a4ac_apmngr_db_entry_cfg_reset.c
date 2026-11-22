// func apmngr_db_entry_cfg_reset @ 0053a4ac size=152

void apmngr_db_entry_cfg_reset(int param_1)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x130) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined1 *)(param_1 + 0xe8) = 0x1e;
    *(undefined2 *)(param_1 + 0xea) = 300;
    *(undefined4 *)(param_1 + 0xec) = 0xe10;
    *(undefined4 *)(param_1 + 0xf0) = apmngr_dft_offline_selfmanage;
    *(undefined4 *)(param_1 + 0x1b8) = 1;
    *(undefined1 *)(param_1 + 0x1bd) = 7;
    *(undefined1 *)(param_1 + 0x1c1) = 7;
    strncpy((char *)(param_1 + 0xf4),"admin",0x1f);
    strncpy((char *)(param_1 + 0x114),"xxxxxx",0xf);
    return;
  }
  return;
}

