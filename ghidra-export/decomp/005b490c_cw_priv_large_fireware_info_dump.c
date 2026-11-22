// func cw_priv_large_fireware_info_dump @ 005b490c size=248

undefined4 cw_priv_large_fireware_info_dump(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private large fireware info \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private large fireware info (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar2 = 0;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tis_info: %d\r\n",(uint)*pbVar3);
  printf("\t\t\t\ttotal_size: %d\r\n",*(undefined4 *)(pbVar3 + 4));
  printf("\t\t\t\ttotal_piece: %d\r\n",*(undefined4 *)(pbVar3 + 8));
  printf("\t\t\t\tMD5: ");
  pbVar1 = pbVar3;
  do {
    iVar2 = iVar2 + 1;
    printf("%02x",(uint)pbVar1[0xc]);
    pbVar1 = pbVar3 + iVar2;
  } while (iVar2 != 0x10);
  puts("\r");
  printf("\t\t\t\treserved: %d\r\n",*(undefined4 *)(pbVar3 + 0x1c));
  return 0;
}

