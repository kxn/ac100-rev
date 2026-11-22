// func cw_priv_sta_pmk_req_length @ 005c6e70 size=12

undefined4 cw_priv_sta_pmk_req_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x65;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

