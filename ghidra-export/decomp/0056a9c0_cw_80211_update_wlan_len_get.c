// func cw_80211_update_wlan_len_get @ 0056a9c0 size=28

short cw_80211_update_wlan_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 6) + 8;
  }
  return sVar1;
}

