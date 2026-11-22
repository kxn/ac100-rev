// func cw_ac_queue_dump @ 0058d194 size=284

void cw_ac_queue_dump(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (ac != 0) {
    uVar1 = capwap_ac_session_total_num_get();
    printf("total num:\t%d\n",uVar1);
    for (uVar2 = 0; uVar2 < *(uint *)(ac + 0x18); uVar2 = uVar2 + 1) {
      puts("\n***************************AC INPUT******************************");
      cw_packet_queue_dump(*(undefined4 *)(*(int *)(ac + 0x1c) + uVar2 * 0xa0 + 0x20));
      puts("\n*****************************END********************************");
    }
    for (uVar2 = 0; uVar2 < *(uint *)(ac + 0x18); uVar2 = uVar2 + 1) {
      puts("\n***************************AC OUTPUT******************************");
      cw_packet_queue_dump(*(undefined4 *)(*(int *)(ac + 0x1c) + uVar2 * 0xa0 + 0x38));
      puts("\n*****************************END********************************");
    }
  }
  return;
}

