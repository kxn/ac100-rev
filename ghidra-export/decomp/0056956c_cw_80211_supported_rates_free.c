// func cw_80211_supported_rates_free @ 0056956c size=60

undefined4 cw_80211_supported_rates_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

