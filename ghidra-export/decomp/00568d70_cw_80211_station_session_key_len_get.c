// func cw_80211_station_session_key_len_get @ 00568d70 size=28

short cw_80211_station_session_key_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 0x14) + 0x14;
  }
  return sVar1;
}

