// func check_stats_consumer_bit_mask @ 00672a00 size=24

undefined4 check_stats_consumer_bit_mask(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 >> (param_2 & 0x1f) & 1U) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}

