// func cw_80211_tx_power_free @ 005699dc size=60

undefined4 cw_80211_tx_power_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

