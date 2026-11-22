// func cw_priv_ap_led_mode_ctrl_length @ 005a4f00 size=12

undefined4 cw_priv_ap_led_mode_ctrl_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

