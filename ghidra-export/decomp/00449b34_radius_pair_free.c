// func radius_pair_free @ 00449b34 size=96

void radius_pair_free(int param_1)

{
  if (param_1 != 0) {
    do {
      param_1 = *(int *)(param_1 + 0x150);
      uac_mem_free_my();
      pair_free = pair_free + 1;
    } while (param_1 != 0);
  }
  return;
}

