// func cw_priv_bluetooth_config_length @ 005abea0 size=12

undefined4 cw_priv_bluetooth_config_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 9;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

