// func cw_priv_ap_tx_stat_length @ 005a8d90 size=12

undefined4 cw_priv_ap_tx_stat_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x208;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

