// func cw_priv_sta_list_free @ 005c686c size=76

undefined4 cw_priv_sta_list_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(int *)(*(int *)(param_1 + 0x10) + 8) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

