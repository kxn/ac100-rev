// func cw_priv_sn_md5_dump @ 005bfd7c size=316

undefined4 cw_priv_sn_md5_dump(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private sn md5 \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private sn md5 (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar2 = 0;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: ");
  pbVar1 = pbVar3;
  do {
    iVar2 = iVar2 + 1;
    printf("%02x",(uint)*pbVar1);
    pbVar1 = pbVar3 + iVar2;
  } while (iVar2 != 10);
  iVar2 = 0;
  puts("...\r");
  printf("\t\t\t\told sn md5: ");
  pbVar1 = pbVar3;
  do {
    iVar2 = iVar2 + 1;
    printf("%02x",(uint)*pbVar1);
    pbVar1 = pbVar3 + iVar2;
  } while (iVar2 != 0x10);
  iVar2 = 0;
  puts("\r");
  printf("\t\t\t\tnew sn md5: ");
  pbVar1 = pbVar3;
  do {
    iVar2 = iVar2 + 1;
    printf("%02x",(uint)pbVar1[0x10]);
    pbVar1 = pbVar3 + iVar2;
  } while (iVar2 != 0x10);
  puts("\r");
  return 0;
}

