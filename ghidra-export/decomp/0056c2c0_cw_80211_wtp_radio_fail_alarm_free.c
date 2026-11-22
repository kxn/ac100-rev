// func cw_80211_wtp_radio_fail_alarm_free @ 0056c2c0 size=60

undefined4 cw_80211_wtp_radio_fail_alarm_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

