// func cw_sta_rssi_dump @ 005813c4 size=320

undefined4 cw_sta_rssi_dump(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) station rssi \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: station rssi (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x... \r\n",(uint)*pbVar2);
  printf("\t\t\tradio id: %d \r\n",(uint)*pbVar2);
  printf("\t\t\tstation count: %d \r\n",*(undefined4 *)(pbVar2 + 4));
  if ((*(int *)(pbVar2 + 4) != 0) && (uVar3 = 0, *(int *)(pbVar2 + 8) != 0)) {
    for (; uVar3 < *(uint *)(pbVar2 + 4); uVar3 = uVar3 + 1) {
      pbVar1 = (byte *)(*(int *)(pbVar2 + 8) + uVar3 * 7);
      printf("\t\t\tclient mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1],
             (uint)pbVar1[2],(uint)pbVar1[3],(uint)pbVar1[4],(uint)pbVar1[5]);
      printf("\t\t\trssi: %d \r\n",(int)*(char *)(*(int *)(pbVar2 + 8) + uVar3 * 7 + 6));
    }
  }
  return 0;
}

