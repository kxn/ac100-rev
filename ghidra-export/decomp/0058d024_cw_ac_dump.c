// func cw_ac_dump @ 0058d024 size=152

void cw_ac_dump(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (ac != 0) {
    puts("\n***************************AC INFO******************************");
    uVar1 = capwap_ac_session_total_num_get();
    printf("total num:\t%d\n",uVar1);
    for (uVar2 = 0; uVar2 < *(uint *)(ac + 0x18); uVar2 = uVar2 + 1) {
      cw_ac_thread_dump(uVar2);
    }
    puts("\n*****************************END********************************");
    return;
  }
  return;
}

