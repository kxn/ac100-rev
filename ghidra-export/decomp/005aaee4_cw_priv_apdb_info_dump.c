// func cw_priv_apdb_info_dump @ 005aaee4 size=380

undefined4 cw_priv_apdb_info_dump(int param_1)

{
  bool bVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  
  puVar5 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) apdb info \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: apdb info (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: ");
  if ((*puVar5 != 0) && (iVar4 = 0, *(int *)(puVar5 + 2) != 0)) {
    while( true ) {
      uVar3 = (uint)*puVar5;
      bVar1 = 10 < uVar3;
      if (bVar1) {
        uVar3 = 10;
      }
      if ((int)uVar3 <= iVar4) break;
      pbVar2 = (byte *)(*(int *)(puVar5 + 2) + iVar4);
      iVar4 = iVar4 + 1;
      printf("%02x",(uint)*pbVar2);
    }
    if (!bVar1) goto LAB_005aafa8;
  }
  printf("...");
LAB_005aafa8:
  puts("\r");
  if (*(int *)(puVar5 + 2) != 0) {
    iVar4 = 0;
    printf("\t\t\t\tapdb info: ");
    while( true ) {
      uVar3 = (uint)*puVar5;
      bVar1 = 10 < uVar3;
      if (bVar1) {
        uVar3 = 10;
      }
      if ((int)uVar3 <= iVar4) break;
      pbVar2 = (byte *)(*(int *)(puVar5 + 2) + iVar4);
      iVar4 = iVar4 + 1;
      printf("%02x",(uint)*pbVar2);
    }
    if (bVar1) {
      printf("...");
    }
    puts("\r");
  }
  return 0;
}

