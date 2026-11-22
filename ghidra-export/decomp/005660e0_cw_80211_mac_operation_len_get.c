// func cw_80211_mac_operation_len_get @ 005660e0 size=12

undefined4 cw_80211_mac_operation_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

