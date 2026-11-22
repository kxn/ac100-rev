// func cw_capwap_local_ipv4_address_free @ 00570e04 size=60

undefined4 cw_capwap_local_ipv4_address_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

