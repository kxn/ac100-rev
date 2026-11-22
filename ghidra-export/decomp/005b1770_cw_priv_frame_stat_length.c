// func cw_priv_frame_stat_length @ 005b1770 size=12

undefined4 cw_priv_frame_stat_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x7c;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

