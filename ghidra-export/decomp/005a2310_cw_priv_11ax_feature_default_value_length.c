// func cw_priv_11ax_feature_default_value_length @ 005a2310 size=12

undefined4 cw_priv_11ax_feature_default_value_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 9;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

