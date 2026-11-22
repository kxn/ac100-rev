// func cw_ac_stat_dump @ 0058d0bc size=128

void cw_ac_stat_dump(void)

{
  uint uVar1;
  
  if (ac != 0) {
    puts("\n***********************AC STAT INFO*****************************");
    for (uVar1 = 0; uVar1 < *(uint *)(ac + 0x18); uVar1 = uVar1 + 1) {
      cw_ac_thread_stat_dump(uVar1);
    }
    puts("\n*****************************END********************************");
    return;
  }
  return;
}

