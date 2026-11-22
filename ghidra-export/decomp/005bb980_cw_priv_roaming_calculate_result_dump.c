// func cw_priv_roaming_calculate_result_dump @ 005bb980 size=796

undefined4 cw_priv_roaming_calculate_result_dump(int param_1)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private roaming calculate result request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private roaming calculate result request(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",(uint)*pbVar3);
  printf("\t\t\t\tcurrent ap: %u \r\n",(uint)*pbVar3);
  printf("\t\t\t\tradio id: %u \r\n",(uint)pbVar3[1]);
  printf("\t\t\t\tstation count: %u \r\n",*(undefined4 *)(pbVar3 + 4));
  printf("\t\t\t\tap union count: %u \r\n",*(undefined4 *)(pbVar3 + 8));
  if (*(int *)(pbVar3 + 8) == 0) {
    iVar1 = *(int *)(pbVar3 + 4);
  }
  else {
    uVar7 = 0;
    if (*(int *)(pbVar3 + 0xc) != 0) {
      for (; uVar7 < *(uint *)(pbVar3 + 8); uVar7 = uVar7 + 1) {
        pbVar2 = (byte *)(*(int *)(pbVar3 + 0xc) + uVar7 * 6);
        printf("\t\t\t\t ap mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*pbVar2,(uint)pbVar2[1],
               (uint)pbVar2[2],(uint)pbVar2[3],(uint)pbVar2[4],(uint)pbVar2[5]);
      }
    }
    iVar1 = *(int *)(pbVar3 + 4);
  }
  if ((iVar1 != 0) && (uVar7 = 0, *(int *)(pbVar3 + 0x10) != 0)) {
    for (; uVar7 < *(uint *)(pbVar3 + 4); uVar7 = uVar7 + 1) {
      iVar4 = uVar7 * 0x1c;
      iVar5 = 0;
      pbVar2 = (byte *)(*(int *)(pbVar3 + 0x10) + iVar4);
      printf("\t\t\t\t  station mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*pbVar2,
             (uint)pbVar2[1],(uint)pbVar2[2],(uint)pbVar2[3],(uint)pbVar2[4],(uint)pbVar2[5]);
      printf("\t\t\t\t    ap union bitmap: ");
      iVar1 = *(int *)(pbVar3 + 0x10);
      while( true ) {
        iVar1 = iVar1 + iVar4 + iVar5;
        iVar5 = iVar5 + 1;
        printf("0x%02x ",(uint)*(byte *)(iVar1 + 6));
        if (iVar5 == 0x10) break;
        iVar1 = *(int *)(pbVar3 + 0x10);
      }
      puts("\r");
      printf("\t\t\t\t    radio count: %u \r\n",
             (uint)*(byte *)(*(int *)(pbVar3 + 0x10) + iVar4 + 0x16));
      iVar1 = *(int *)(pbVar3 + 0x10);
      for (iVar5 = 0; iVar5 < (int)(uint)*(byte *)(iVar1 + iVar4 + 0x16); iVar5 = iVar5 + 1) {
        iVar6 = iVar5 * 10;
        printf("\t\t\t\t      ap index: %u \r\n",
               (uint)*(byte *)(*(int *)(iVar1 + iVar4 + 0x18) + iVar6));
        printf("\t\t\t\t      radio id: %u \r\n",
               (uint)*(byte *)(*(int *)(*(int *)(pbVar3 + 0x10) + iVar4 + 0x18) + iVar6 + 1));
        printf("\t\t\t\t      wlan id: %u \r\n",
               (uint)*(byte *)(*(int *)(*(int *)(pbVar3 + 0x10) + iVar4 + 0x18) + iVar6 + 2));
        iVar1 = *(int *)(*(int *)(pbVar3 + 0x10) + iVar4 + 0x18) + iVar6;
        printf("\t\t\t\t      bssid: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*(byte *)(iVar1 + 3),
               (uint)*(byte *)(iVar1 + 4),(uint)*(byte *)(iVar1 + 5),(uint)*(byte *)(iVar1 + 6),
               (uint)*(byte *)(iVar1 + 7),(uint)*(byte *)(iVar1 + 8));
        printf("\t\t\t\t      channel: %u \r\n",
               (uint)*(byte *)(*(int *)(*(int *)(pbVar3 + 0x10) + iVar4 + 0x18) + iVar6 + 9));
        iVar1 = *(int *)(pbVar3 + 0x10);
      }
    }
  }
  puts("\r");
  return 0;
}

