// func cw_80211_rsna_error_report_len_get @ 00567ac0 size=12

undefined4 cw_80211_rsna_error_report_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x28;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

