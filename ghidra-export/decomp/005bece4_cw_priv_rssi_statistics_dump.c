// func cw_priv_rssi_statistics_dump @ 005bece4 size=512

undefined4 cw_priv_rssi_statistics_dump(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private rssi statistics request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private rssi statistics request(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar4 = 0;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",(uint)*pbVar3);
  printf("\t\t\t\tchannel load: ");
  pbVar1 = pbVar3;
  do {
    iVar4 = iVar4 + 1;
    printf("%u%%, ",(uint)*pbVar1);
    pbVar1 = pbVar3 + iVar4;
  } while (iVar4 != 8);
  puts("\r");
  iVar4 = 0;
  printf("\t\t\t\tnf: ");
  pbVar1 = pbVar3;
  do {
    iVar4 = iVar4 + 1;
    printf("%d, ",(int)(char)pbVar1[8]);
    pbVar1 = pbVar3 + iVar4;
  } while (iVar4 != 8);
  puts("\r");
  printf("\t\t\t\tstation count: %u \r\n",*(undefined4 *)(pbVar3 + 0x10));
  if ((*(int *)(pbVar3 + 0x10) != 0) && (uVar6 = 0, *(int *)(pbVar3 + 0x14) != 0)) {
    uVar2 = *(uint *)(pbVar3 + 0x10);
    for (; uVar6 < uVar2; uVar6 = uVar6 + 1) {
      iVar5 = 0;
      pbVar1 = (byte *)(*(int *)(pbVar3 + 0x14) + uVar6 * 0xe);
      printf("\t\t\t\tclient mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1],
             (uint)pbVar1[2],(uint)pbVar1[3],(uint)pbVar1[4],(uint)pbVar1[5]);
      printf("\t\t\t\trssi: ");
      iVar4 = *(int *)(pbVar3 + 0x14);
      while( true ) {
        iVar4 = iVar4 + uVar6 * 0xe + iVar5;
        iVar5 = iVar5 + 1;
        printf("%d, ",(int)*(char *)(iVar4 + 6));
        if (iVar5 == 8) break;
        iVar4 = *(int *)(pbVar3 + 0x14);
      }
      puts("\r");
      uVar2 = *(uint *)(pbVar3 + 0x10);
    }
  }
  return 0;
}

