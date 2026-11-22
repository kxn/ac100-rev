// func cw_80211_mac_operation_free @ 00566244 size=60

undefined4 cw_80211_mac_operation_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

