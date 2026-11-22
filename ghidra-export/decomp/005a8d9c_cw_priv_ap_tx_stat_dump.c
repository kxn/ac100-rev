// func cw_priv_ap_tx_stat_dump @ 005a8d9c size=736

undefined4 cw_priv_ap_tx_stat_dump(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap tx stat \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap tx stat (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar5 = 0;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%02x%02x... \r\n",(uint)*pbVar4,(uint)pbVar4[1],(uint)pbVar4[2],
         (uint)pbVar4[3]);
  printf("\t\t\t\tradio id: %u\r\n ",(uint)*pbVar4);
  uVar3 = *(undefined4 *)(pbVar4 + 0x14);
  uVar1 = *(undefined4 *)(pbVar4 + 0x10);
  printf("\t\t\t\ttx bytes: %llu  tx data bytes: %llu\r\n ");
  printf("\t\t\t\ttx pkt: %u  tx unicast pkt: %u  tx multicast pkt: %u\r\n ",
         *(undefined4 *)(pbVar4 + 0x18),*(undefined4 *)(pbVar4 + 0x1c),
         *(undefined4 *)(pbVar4 + 0x20),uVar1,uVar3);
  printf("\t\t\t\ttx success: %u  tx drop: %u  tx retry: %u\r\n ",*(undefined4 *)(pbVar4 + 0x28),
         *(undefined4 *)(pbVar4 + 0x24),*(undefined4 *)(pbVar4 + 0x2c));
  printf("\t\t\t\ttx rts OK: %u  tx rts fail: %u\r\n ",*(undefined4 *)(pbVar4 + 0x30),
         *(undefined4 *)(pbVar4 + 0x34));
  printf("\t\t\t\ttx hardware OK: %u  tx data pkt: %u\r\n ",*(undefined4 *)(pbVar4 + 0x38),
         *(undefined4 *)(pbVar4 + 0x3c));
  printf("\t\t\t\ttid paused: %u  tid resumed: %u\r\n ",*(undefined4 *)(pbVar4 + 0x40),
         *(undefined4 *)(pbVar4 + 0x44));
  printf("\t\t\t\ttx no-qus data num: %u\r\n ",*(undefined4 *)(pbVar4 + 0x88));
  printf("\t\t\t\ttx qos data num:");
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 4;
    printf(" %u",*(undefined4 *)(pbVar2 + 0x48));
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puts("\r");
  printf("\t\t\t\ttx Q pkt:");
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 4;
    printf(" %u",*(undefined4 *)(pbVar2 + 0x8c));
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puts("\r");
  printf("\t\t\t\ttx Q retry:");
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 4;
    printf(" %u",*(undefined4 *)(pbVar2 + 0xcc));
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puts("\r");
  printf("\t\t\t\ttx Q error:");
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 4;
    printf(" %u",*(undefined4 *)(pbVar2 + 0x10c));
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puts("\r");
  printf("\t\t\t\ttx Q filter:");
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 4;
    printf(" %u",*(undefined4 *)(pbVar2 + 0x14c));
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puts("\r");
  printf("\t\t\t\ttx Q athbuf limit:");
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 4;
    printf(" %u",*(undefined4 *)(pbVar2 + 0x18c));
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 0x40);
  iVar5 = 0;
  puts("\r");
  printf("\t\t\t\ttx Q nobuf:");
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 4;
    printf(" %u",*(undefined4 *)(pbVar2 + 0x1cc));
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 0x40);
  puts("\r");
  return 0;
}

