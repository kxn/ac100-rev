// func cw_priv_spec_msg_sw_length @ 005c0ce0 size=12

undefined4 cw_priv_spec_msg_sw_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 8;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

