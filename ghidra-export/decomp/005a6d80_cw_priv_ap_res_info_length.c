// func cw_priv_ap_res_info_length @ 005a6d80 size=12

undefined4 cw_priv_ap_res_info_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 5;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

