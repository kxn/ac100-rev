// func cw_priv_lldp_free @ 005b4d08 size=44

undefined4 cw_priv_lldp_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
  }
  return 0;
}

