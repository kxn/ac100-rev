// func cw_priv_portal_syn_dump @ 005b8c6c size=268

undefined4 cw_priv_portal_syn_dump(int param_1)

{
  bool bVar1;
  byte *pbVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  
  puVar4 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private portal syn \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private portal syn (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %04x...\r\n",(uint)*puVar4);
  printf("\t\t\t\tlength: %d \r\n",(uint)*puVar4);
  if (*(int *)(puVar4 + 2) != 0) {
    iVar5 = 0;
    printf("\t\t\t\tportal data: ");
    while( true ) {
      uVar3 = (uint)*puVar4;
      bVar1 = 10 < uVar3;
      if (bVar1) {
        uVar3 = 10;
      }
      if ((int)uVar3 <= iVar5) break;
      pbVar2 = (byte *)(*(int *)(puVar4 + 2) + iVar5);
      iVar5 = iVar5 + 1;
      printf("%02x",(uint)*pbVar2);
    }
    if (bVar1) {
      printf("...");
    }
    puts("\r");
  }
  return 0;
}

