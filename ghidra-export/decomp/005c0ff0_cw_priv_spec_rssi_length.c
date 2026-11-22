// func cw_priv_spec_rssi_length @ 005c0ff0 size=12

undefined4 cw_priv_spec_rssi_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

