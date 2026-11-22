// func cw_priv_fail_station_dump @ 005b0c54 size=432

undefined4 cw_priv_fail_station_dump(int param_1)

{
  byte *pbVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private bstm trigger request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private bstm trigger request(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",*puVar2);
  printf("\t\t\t\tstation cnt: %u \r\n",*puVar2);
  if ((*puVar2 != 0) && (uVar4 = 0, puVar2[1] != 0)) {
    for (; uVar4 < *puVar2; uVar4 = uVar4 + 1) {
      iVar3 = uVar4 * 0x14;
      pbVar1 = (byte *)(puVar2[1] + iVar3);
      printf("\t\t\t\t  station mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*pbVar1,
             (uint)pbVar1[1],(uint)pbVar1[2],(uint)pbVar1[3],(uint)pbVar1[4],(uint)pbVar1[5]);
      printf("\t\t\t\t  radio id: %u \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 6));
      printf("\t\t\t\t  wlan id: %u \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 7));
      printf("\t\t\t\t  fail phase: %u \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 8));
      printf("\t\t\t\t  fail code: %u \r\n",*(undefined4 *)(puVar2[1] + iVar3 + 0xc));
      printf("\t\t\t\t  time dif: %u \r\n",*(undefined4 *)(puVar2[1] + iVar3 + 0x10));
    }
  }
  puts("\r");
  return 0;
}

