// func cw_radio_operational_state_length @ 0057f860 size=12

undefined4 cw_radio_operational_state_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

