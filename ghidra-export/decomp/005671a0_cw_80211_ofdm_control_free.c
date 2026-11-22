// func cw_80211_ofdm_control_free @ 005671a0 size=64

undefined4 cw_80211_ofdm_control_free(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

