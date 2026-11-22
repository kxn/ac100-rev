// func cw_priv_sub_fireware_info_length @ 005c8f50 size=12

undefined4 cw_priv_sub_fireware_info_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x1a;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

