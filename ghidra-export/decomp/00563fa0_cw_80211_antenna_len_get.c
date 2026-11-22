// func cw_80211_antenna_len_get @ 00563fa0 size=24

int cw_80211_antenna_len_get(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = *(byte *)(param_1 + 3) + 4;
  }
  return iVar1;
}

