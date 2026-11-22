// func cw_priv_sniffing_control_length @ 005c0140 size=12

undefined4 cw_priv_sniffing_control_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 5;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

