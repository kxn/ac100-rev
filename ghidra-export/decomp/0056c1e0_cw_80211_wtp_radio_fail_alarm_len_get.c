// func cw_80211_wtp_radio_fail_alarm_len_get @ 0056c1e0 size=12

undefined4 cw_80211_wtp_radio_fail_alarm_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

