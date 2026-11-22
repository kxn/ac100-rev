// func cw_priv_rrm_neighs_list_dump @ 005be174 size=472

undefined4 cw_priv_rrm_neighs_list_dump(int param_1)

{
  ushort uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  pbVar8 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private rrm neighs list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private rrm neighs list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%04x...\r\n",(uint)*pbVar8,(uint)pbVar8[1],
         (uint)*(ushort *)(pbVar8 + 2));
  printf("\t\t\t\tradio id: %u \r\n",(uint)*pbVar8);
  printf("\t\t\t\tneighbor type: %d \r\n",(uint)pbVar8[1]);
  printf("\t\t\t\tneighbor count: %u \r\n",(uint)*(ushort *)(pbVar8 + 2));
  if (*(short *)(pbVar8 + 2) != 0) {
    puts("\t\t\t\tneighbor list: ");
    uVar1 = *(ushort *)(pbVar8 + 2);
    for (iVar10 = 0; iVar10 < (int)(uint)uVar1; iVar10 = iVar10 + 1) {
      iVar11 = iVar10 * 0xc;
      pbVar2 = (byte *)(*(int *)(pbVar8 + 4) + iVar11);
      uVar4 = (uint)pbVar2[3];
      uVar5 = (uint)pbVar2[4];
      uVar6 = (uint)pbVar2[5];
      uVar3 = (uint)pbVar2[6];
      printf("\t\t\t\t\tmac:%02X-%02X-%02X-%02X-%02X-%02X channel_op:%u ",(uint)*pbVar2,
             (uint)pbVar2[1],(uint)pbVar2[2],uVar4,uVar5,uVar6,uVar3);
      printf("rssi list(%u):[ ",(uint)*(byte *)(*(int *)(pbVar8 + 4) + iVar11 + 7));
      iVar7 = *(int *)(pbVar8 + 4);
      for (iVar9 = 0; iVar9 < (int)(uint)*(byte *)(iVar7 + iVar11 + 7); iVar9 = iVar9 + 1) {
        pbVar2 = (byte *)(*(int *)(iVar7 + iVar11 + 8) + iVar9 * 3);
        printf("<%u,%u,%d> ",(uint)*pbVar2,(uint)pbVar2[1],(int)(char)pbVar2[2],uVar4,uVar5,uVar6,
               uVar3);
        iVar7 = *(int *)(pbVar8 + 4);
      }
      puts("]");
      uVar1 = *(ushort *)(pbVar8 + 2);
    }
  }
  return 0;
}

