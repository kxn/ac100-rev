// func cw_priv_trans_data_request_dump @ 005c993c size=380

undefined4 cw_priv_trans_data_request_dump(int param_1)

{
  ushort uVar1;
  bool bVar2;
  byte *pbVar3;
  int iVar4;
  char *__format;
  ushort *puVar5;
  int iVar6;
  
  puVar5 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private trans data request \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private trans data request (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %04x%04x...\r\n",(uint)*puVar5,(uint)puVar5[1]);
  printf("\t\t\t\toperation: %u",(uint)*puVar5);
  uVar1 = *puVar5;
  if (uVar1 == 1) {
    __format = "(change channel)";
  }
  else if (uVar1 == 0) {
    __format = "(get n/g/b ap)";
  }
  else if (uVar1 == 2) {
    __format = "(change power)";
  }
  else {
    __format = "(unknown operation)";
  }
  printf(__format);
  puts("\r");
  iVar6 = 0;
  printf("\t\t\t\toperation mask: 0x%4x\r\n ",(uint)puVar5[1]);
  printf("\t\t\t\ttrans data: ");
  uVar1 = *(ushort *)(param_1 + 0xe);
  while( true ) {
    iVar4 = uVar1 - 4;
    bVar2 = 10 < iVar4;
    if (bVar2) {
      iVar4 = 10;
    }
    if (iVar4 <= iVar6) break;
    pbVar3 = (byte *)(*(int *)(puVar5 + 4) + iVar6);
    iVar6 = iVar6 + 1;
    printf("%02x",(uint)*pbVar3);
    uVar1 = *(ushort *)(param_1 + 0xe);
  }
  if (bVar2) {
    printf("...");
  }
  puts("\r");
  return 0;
}

