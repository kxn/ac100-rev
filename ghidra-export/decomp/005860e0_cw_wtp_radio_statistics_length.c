// func cw_wtp_radio_statistics_length @ 005860e0 size=12

undefined4 cw_wtp_radio_statistics_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x14;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

