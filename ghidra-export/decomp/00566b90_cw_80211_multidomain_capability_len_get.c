// func cw_80211_multidomain_capability_len_get @ 00566b90 size=12

undefined4 cw_80211_multidomain_capability_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 8;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

