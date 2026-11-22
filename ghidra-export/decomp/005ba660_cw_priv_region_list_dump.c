// func cw_priv_region_list_dump @ 005ba660 size=408

void cw_priv_region_list_dump(int param_1)

{
  byte bVar1;
  uint __n;
  byte *pbVar2;
  uint __n_00;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  char acStack_228 [256];
  char acStack_128 [256];
  
  iVar4 = 0;
  pbVar5 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) region list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: region list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  puts("\t\t\t\tValue: \r");
  puts("\t\t\t\tregion list items: \r");
  bVar1 = *pbVar5;
  for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) {
    memset(acStack_128,0,0x100);
    memset(acStack_228,0,0x100);
    pbVar2 = (byte *)(*(int *)(pbVar5 + 4) + iVar4);
    __n = (uint)pbVar2[1];
    __n_00 = (uint)pbVar2[__n + 2];
    iVar4 = iVar4 + __n + __n_00 + 3;
    printf("\t\t\t\t  Code:%d\r\n",(uint)*pbVar2);
    printf("\t\t\t\t  name_len:%d\r\n",__n);
    strncpy(acStack_128,(char *)(pbVar2 + 2),__n);
    printf("\t\t\t\t  name:%s\r\n",acStack_128);
    printf("\t\t\t\t  ch_lst_len:%d\r\n",__n_00);
    strncpy(acStack_228,(char *)(pbVar2 + __n + 3),__n_00);
    printf("\t\t\t\t  ch_lst:%s\r\n",acStack_228);
    puts("\r");
    bVar1 = *pbVar5;
  }
  return;
}

