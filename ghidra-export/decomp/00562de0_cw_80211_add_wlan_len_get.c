// func cw_80211_add_wlan_len_get @ 00562de0 size=36

short cw_80211_add_wlan_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 6) + *(short *)(param_1 + 0x18) + 0x13;
  }
  return sVar1;
}

