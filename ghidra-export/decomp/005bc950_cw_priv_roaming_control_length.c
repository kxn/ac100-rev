// func cw_priv_roaming_control_length @ 005bc950 size=12

undefined4 cw_priv_roaming_control_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x24;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

