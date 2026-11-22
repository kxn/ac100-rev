// func cw_80211_wtp_radio_configuration_len_get @ 0056bbb0 size=12

undefined4 cw_80211_wtp_radio_configuration_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

