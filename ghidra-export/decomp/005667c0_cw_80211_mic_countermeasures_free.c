// func cw_80211_mic_countermeasures_free @ 005667c0 size=60

undefined4 cw_80211_mic_countermeasures_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

