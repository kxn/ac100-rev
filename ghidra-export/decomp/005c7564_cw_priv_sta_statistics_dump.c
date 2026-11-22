// func cw_priv_sta_statistics_dump @ 005c7564 size=672

undefined4 cw_priv_sta_statistics_dump(int param_1)

{
  byte *pbVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private station statistics request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private station statistics request(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",*puVar2);
  printf("\t\t\t\tstation count: %u \r\n",*puVar2);
  if ((*puVar2 != 0) && (uVar4 = 0, puVar2[1] != 0)) {
    for (; uVar4 < *puVar2; uVar4 = uVar4 + 1) {
      iVar3 = uVar4 * 0x28;
      pbVar1 = (byte *)(puVar2[1] + iVar3);
      printf("\t\t\t\tclient mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1],
             (uint)pbVar1[2],(uint)pbVar1[3],(uint)pbVar1[4],(uint)pbVar1[5]);
      printf("\t\t\t\t  radio id: %u \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 6));
      printf("\t\t\t\t  wlan id: %u \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 7));
      printf("\t\t\t\t  auth type: %u \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 8));
      printf("\t\t\t\t  enc alg: %u \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 9));
      printf("\t\t\t\t  rssi: %d dBm\r\n",(int)*(char *)(puVar2[1] + iVar3 + 10));
      printf("\t\t\t\t  nego bw: %d \r\n",(int)*(char *)(puVar2[1] + iVar3 + 0xb));
      printf("\t\t\t\t  nego rate: %u Mbps\r\n",(uint)*(ushort *)(puVar2[1] + iVar3 + 0xc));
      printf("\t\t\t\t  support: 0x%08x \r\n",*(undefined4 *)(puVar2[1] + iVar3 + 0x10));
      printf("\t\t\t\t  capabilities: 0x%04x \r\n",(uint)*(ushort *)(puVar2[1] + iVar3 + 0x14));
      printf("\t\t\t\t  packet rtx rate: %u%% \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 0x16));
      printf("\t\t\t\t  packet loss rate: %u%% \r\n",(uint)*(byte *)(puVar2[1] + iVar3 + 0x17));
      printf("\t\t\t\t  upstream rate: %u Kbps\r\n",*(undefined4 *)(puVar2[1] + iVar3 + 0x18));
      printf("\t\t\t\t  downstream rate: %u Kbps\r\n",*(undefined4 *)(puVar2[1] + iVar3 + 0x1c));
      printf("\t\t\t\t  upstream load increament: %u KBytes\r\n",
             *(undefined4 *)(puVar2[1] + iVar3 + 0x20));
      printf("\t\t\t\t  downstream load increament: %u KBytes\r\n",
             *(undefined4 *)(puVar2[1] + iVar3 + 0x24));
    }
  }
  puts("\r");
  return 0;
}

