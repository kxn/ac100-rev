// func cw_priv_stat_prd_free @ 005c8054 size=60

undefined4 cw_priv_stat_prd_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

