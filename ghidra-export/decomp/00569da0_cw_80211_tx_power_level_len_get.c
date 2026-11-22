// func cw_80211_tx_power_level_len_get @ 00569da0 size=28

int cw_80211_tx_power_level_len_get(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = (*(byte *)(param_1 + 1) + 1) * 2;
  }
  return iVar1;
}

