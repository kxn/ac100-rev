// func cw_priv_sta_list_dump @ 005c66d4 size=408

undefined4 cw_priv_sta_list_dump(int param_1)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  pbVar5 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private sta list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private sta list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%08x...\r\n",(uint)*pbVar5,(uint)pbVar5[1],
         *(undefined4 *)(pbVar5 + 4));
  printf("\t\t\t\tradio id: %u \r\n",(uint)*pbVar5);
  printf("\t\t\t\twlan id: %u \r\n",(uint)pbVar5[1]);
  printf("\t\t\t\tsta cnt: %u \r\n",*(undefined4 *)(pbVar5 + 4));
  if ((*(int *)(pbVar5 + 4) != 0) && (*(int *)(pbVar5 + 8) != 0)) {
    uVar7 = 0;
    printf("\t\t\t\tsta mac list: ");
    uVar4 = *(uint *)(pbVar5 + 4);
    while( true ) {
      bVar1 = 6 < uVar4;
      if (bVar1) {
        uVar4 = 6;
      }
      iVar8 = uVar7 * 6;
      if (uVar4 <= uVar7) break;
      iVar6 = 0;
      iVar2 = *(int *)(pbVar5 + 8);
      do {
        pbVar3 = (byte *)(iVar2 + iVar8 + iVar6);
        iVar6 = iVar6 + 1;
        printf("%02x:",(uint)*pbVar3);
        iVar2 = *(int *)(pbVar5 + 8);
      } while (iVar6 != 5);
      uVar7 = uVar7 + 1;
      printf("%02x ",(uint)*(byte *)(iVar2 + iVar8 + 5));
      uVar4 = *(uint *)(pbVar5 + 4);
    }
    if (bVar1) {
      printf("...");
    }
    puts("\r");
  }
  return 0;
}

