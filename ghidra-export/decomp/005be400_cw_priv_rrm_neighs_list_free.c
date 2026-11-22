// func cw_priv_rrm_neighs_list_free @ 005be400 size=60

undefined4 cw_priv_rrm_neighs_list_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    cw_priv_rrm_neighs_list_val_free();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

