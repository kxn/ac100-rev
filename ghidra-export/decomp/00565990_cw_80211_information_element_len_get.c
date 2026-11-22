// func cw_80211_information_element_len_get @ 00565990 size=28

short cw_80211_information_element_len_get(int param_1)

{
  short sVar1;
  
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 4) + 3;
  }
  return sVar1;
}

