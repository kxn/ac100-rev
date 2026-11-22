// func cw_80211_rate_set_len_get @ 00567610 size=24

int cw_80211_rate_set_len_get(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 1) + 1;
  }
  return iVar1;
}

