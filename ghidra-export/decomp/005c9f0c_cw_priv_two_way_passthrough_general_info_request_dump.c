// func cw_priv_two_way_passthrough_general_info_request_dump @ 005c9f0c size=344

undefined4 cw_priv_two_way_passthrough_general_info_request_dump(int param_1)

{
  ushort uVar1;
  bool bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar6 = 0;
  pbVar5 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private two way passthrough general info \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType:  private two way passthrough general infot (%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tid: %u \r\n",(uint)*pbVar5);
  printf("\t\t\t\tis_request: %u \r\n ",(uint)pbVar5[1]);
  printf("\t\t\t\ttype: %u \r\n ",(uint)pbVar5[2]);
  printf("\t\t\t\tlen:%d \r\n",*(undefined4 *)(pbVar5 + 8));
  printf("\t\t\t\tneed_result: %u \r\n ",(uint)pbVar5[3]);
  printf("\t\t\t\ttrans data: ");
  uVar1 = *(ushort *)(param_1 + 0xe);
  while( true ) {
    iVar4 = uVar1 - 0xc;
    bVar2 = 10 < iVar4;
    if (bVar2) {
      iVar4 = 10;
    }
    if (iVar4 <= iVar6) break;
    pbVar3 = (byte *)(*(int *)(pbVar5 + 0xc) + iVar6);
    iVar6 = iVar6 + 1;
    printf("%02x ",(uint)*pbVar3);
    uVar1 = *(ushort *)(param_1 + 0xe);
  }
  if (bVar2) {
    printf("...");
  }
  puts("\r");
  printf("\t\t\t\ttrans data:%s",*(undefined4 *)(pbVar5 + 0xc));
  puts("\r");
  return 0;
}

