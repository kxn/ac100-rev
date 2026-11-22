// func cw_80211_station_len_get @ 005681e0 size=24

int cw_80211_station_len_get(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 0xf) + 0xd;
  }
  return iVar1;
}

