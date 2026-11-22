// func cw_priv_ap_user_length @ 005a99b0 size=12

undefined4 cw_priv_ap_user_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x80;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

