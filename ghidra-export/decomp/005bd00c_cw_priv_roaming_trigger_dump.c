// func cw_priv_roaming_trigger_dump @ 005bd00c size=648

undefined4 cw_priv_roaming_trigger_dump(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private roaming trigger request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private roaming trigger request(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",(uint)*pbVar3);
  printf("\t\t\t\tradio id: %u \r\n",(uint)*pbVar3);
  printf("\t\t\t\tchannel load: %u%% \r\n",(uint)pbVar3[1]);
  printf("\t\t\t\tnoise floor: %d \r\n",(int)(char)pbVar3[2]);
  printf("\t\t\t\tstation count: %u \r\n",*(undefined4 *)(pbVar3 + 4));
  if ((*(int *)(pbVar3 + 4) != 0) && (uVar7 = 0, *(int *)(pbVar3 + 8) != 0)) {
    for (; uVar7 < *(uint *)(pbVar3 + 4); uVar7 = uVar7 + 1) {
      iVar4 = uVar7 * 0x10;
      pbVar1 = (byte *)(*(int *)(pbVar3 + 8) + iVar4);
      printf("\t\t\t\tstation mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1]
             ,(uint)pbVar1[2],(uint)pbVar1[3],(uint)pbVar1[4],(uint)pbVar1[5]);
      printf("\t\t\t\t  wlan id: %u \r\n",(uint)*(byte *)(*(int *)(pbVar3 + 8) + iVar4 + 6));
      printf("\t\t\t\t  rssi: %d \r\n",(int)*(char *)(*(int *)(pbVar3 + 8) + iVar4 + 7));
      printf("\t\t\t\t  band mode: %d \r\n",(uint)*(byte *)(*(int *)(pbVar3 + 8) + iVar4 + 8));
      printf("\t\t\t\t  neighbor_cnt: %d \r\n",(uint)*(byte *)(*(int *)(pbVar3 + 8) + iVar4 + 9));
      iVar2 = *(int *)(pbVar3 + 8);
      for (iVar6 = 0; iVar6 < (int)(uint)*(byte *)(iVar2 + iVar4 + 9); iVar6 = iVar6 + 1) {
        iVar5 = iVar6 * 9;
        pbVar1 = (byte *)(*(int *)(iVar2 + iVar4 + 0xc) + iVar5);
        printf("\t\t\t\t\t  bssid: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1]
               ,(uint)pbVar1[2],(uint)pbVar1[3],(uint)pbVar1[4],(uint)pbVar1[5]);
        printf("\t\t\t\t\t  rcpi: %d \r\n",
               (uint)*(byte *)(*(int *)(*(int *)(pbVar3 + 8) + iVar4 + 0xc) + iVar5 + 6));
        printf("\t\t\t\t\t  rsni: %d \r\n",
               (uint)*(byte *)(*(int *)(*(int *)(pbVar3 + 8) + iVar4 + 0xc) + iVar5 + 7));
        printf("\t\t\t\t\t  channel: %d \r\n",
               (uint)*(byte *)(*(int *)(*(int *)(pbVar3 + 8) + iVar4 + 0xc) + iVar5 + 8));
        iVar2 = *(int *)(pbVar3 + 8);
      }
    }
  }
  puts("\r");
  return 0;
}

