// func cw_ac_stat_reset @ 0058d13c size=88

void cw_ac_stat_reset(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (ac != 0) {
    for (; uVar1 < *(uint *)(ac + 0x18); uVar1 = uVar1 + 1) {
      cw_ac_thread_stat_reset(uVar1);
    }
  }
  return;
}

