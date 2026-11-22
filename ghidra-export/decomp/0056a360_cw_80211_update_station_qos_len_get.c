// func cw_80211_update_station_qos_len_get @ 0056a360 size=12

undefined4 cw_80211_update_station_qos_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xf;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

