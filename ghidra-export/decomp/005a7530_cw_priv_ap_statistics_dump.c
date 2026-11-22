// func cw_priv_ap_statistics_dump @ 005a7530 size=1208

undefined4 cw_priv_ap_statistics_dump(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap statistics request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap statistics request(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",(uint)*pbVar3);
  printf("\t\t\t\tradio count: %u \r\n",(uint)*pbVar3);
  printf("\t\t\t\tssid count: %u \r\n",(uint)pbVar3[1]);
  printf("\t\t\t\tcpu num: %u \r\n",(uint)pbVar3[4]);
  bVar1 = pbVar3[4];
  for (iVar4 = 0; iVar4 < (int)(uint)bVar1; iVar4 = iVar4 + 1) {
    printf("\t\t\t\tcpu[%d] utilization: %u%% \r\n",iVar4,(uint)pbVar3[iVar4 + 5]);
    bVar1 = pbVar3[4];
  }
  printf("\t\t\t\tmem utilization: %u%% \r\n",(uint)pbVar3[0xd]);
  printf("\t\t\t\tcapabilities: 0x%04x \r\n",(uint)*(ushort *)(pbVar3 + 0xe));
  printf("\t\t\t\tsta_associate_success_dif: %u \r\n",*(undefined4 *)(pbVar3 + 0x10));
  printf("\t\t\t\tsta_associate_fail_dif: %u \r\n",*(undefined4 *)(pbVar3 + 0x14));
  printf("\t\t\t\tsta_associate_auth_fail_dif: %u \r\n",*(undefined4 *)(pbVar3 + 0x18));
  printf("\t\t\t\tsta_associate_unknown_fail_dif: %u \r\n",*(undefined4 *)(pbVar3 + 0x1c));
  printf("\t\t\t\tsta_dhcp_fail_dif: %u \r\n",*(undefined4 *)(pbVar3 + 0x20));
  printf("\t\t\t\tsta_portal_fail_dif: %u \r\n",*(undefined4 *)(pbVar3 + 0x24));
  printf("\t\t\t\tsta_transport_fail_dif: %u \r\n",*(undefined4 *)(pbVar3 + 0x28));
  if (*pbVar3 == 0) {
    bVar1 = pbVar3[1];
  }
  else {
    iVar4 = 0;
    if (*(int *)(pbVar3 + 0x2c) != 0) {
      for (; iVar4 < (int)(uint)*pbVar3; iVar4 = iVar4 + 1) {
        iVar2 = iVar4 * 0x20;
        printf("\t\t\t\tradio id: %u \r\n",(uint)*(byte *)(*(int *)(pbVar3 + 0x2c) + iVar2));
        printf("\t\t\t\t  channel: %u \r\n",(uint)*(byte *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 1));
        printf("\t\t\t\t  bw mode: %u \r\n",(uint)*(ushort *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 2));
        printf("\t\t\t\t  tx power: %u \r\n",(uint)*(ushort *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 4))
        ;
        printf("\t\t\t\t  capabilities: 0x%04x \r\n",
               (uint)*(ushort *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 6));
        printf("\t\t\t\t  nf: %d \r\n",(int)*(char *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 8));
        printf("\t\t\t\t  channel load: %u%% \r\n",
               (uint)*(byte *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 9));
        printf("\t\t\t\t  packet rtx rate: %u%% \r\n",
               (uint)*(byte *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 10));
        printf("\t\t\t\t  packet loss rate: %u%% \r\n",
               (uint)*(byte *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0xb));
        printf("\t\t\t\t  upstream rate: %u Kbps\r\n",
               *(undefined4 *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0xc));
        printf("\t\t\t\t  downstream rate: %u Kbps\r\n",
               *(undefined4 *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0x10));
        printf("\t\t\t\t  upstream load increament: %u KBytes\r\n",
               *(undefined4 *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0x14));
        printf("\t\t\t\t  downstream load increament: %u KBytes\r\n",
               *(undefined4 *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0x18));
        printf("\t\t\t\t  channel_interference: %d%% \r\n",
               (int)*(char *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0x1c));
        printf("\t\t\t\t  channel up load : %u%% \r\n",
               (uint)*(byte *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0x1d));
        printf("\t\t\t\t  channel down load : %u%% \r\n",
               (uint)*(byte *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0x1e));
        printf("\t\t\t\t  weak signal station rate : %u%% \r\n",
               (uint)*(byte *)(*(int *)(pbVar3 + 0x2c) + iVar2 + 0x1f));
      }
    }
    bVar1 = pbVar3[1];
  }
  if ((bVar1 != 0) && (iVar4 = 0, *(int *)(pbVar3 + 0x30) != 0)) {
    for (; iVar4 < (int)(uint)pbVar3[1]; iVar4 = iVar4 + 1) {
      iVar5 = iVar4 * 0x1c;
      printf("\t\t\t\tradio id: %u, wlan id: %u \r\n",
             (uint)*(byte *)(*(int *)(pbVar3 + 0x30) + iVar5),
             (uint)((byte *)(*(int *)(pbVar3 + 0x30) + iVar5))[1]);
      iVar2 = *(int *)(pbVar3 + 0x30) + iVar5;
      printf("\t\t\t\t  bssid: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*(byte *)(iVar2 + 2),
             (uint)*(byte *)(iVar2 + 3),(uint)*(byte *)(iVar2 + 4),(uint)*(byte *)(iVar2 + 5),
             (uint)*(byte *)(iVar2 + 6),(uint)*(byte *)(iVar2 + 7));
      printf("\t\t\t\t  capabilities: 0x%04x \r\n",
             (uint)*(ushort *)(*(int *)(pbVar3 + 0x30) + iVar5 + 8));
      printf("\t\t\t\t  packet rtx rate: %u%% \r\n",
             (uint)*(byte *)(*(int *)(pbVar3 + 0x30) + iVar5 + 10));
      printf("\t\t\t\t  packet loss rate: %u%% \r\n",
             (uint)*(byte *)(*(int *)(pbVar3 + 0x30) + iVar5 + 0xb));
      printf("\t\t\t\t  upstream rate: %u Kbps\r\n",
             *(undefined4 *)(*(int *)(pbVar3 + 0x30) + iVar5 + 0xc));
      printf("\t\t\t\t  downstream rate: %u Kbps\r\n",
             *(undefined4 *)(*(int *)(pbVar3 + 0x30) + iVar5 + 0x10));
      printf("\t\t\t\t  upstream load increament: %u KBytes\r\n",
             *(undefined4 *)(*(int *)(pbVar3 + 0x30) + iVar5 + 0x14));
      printf("\t\t\t\t  downstream load increament: %u KBytes\r\n",
             *(undefined4 *)(*(int *)(pbVar3 + 0x30) + iVar5 + 0x18));
    }
  }
  puts("\r");
  return 0;
}

