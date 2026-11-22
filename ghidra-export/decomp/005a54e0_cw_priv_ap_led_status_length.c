// func cw_priv_ap_led_status_length @ 005a54e0 size=12

undefined4 cw_priv_ap_led_status_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

