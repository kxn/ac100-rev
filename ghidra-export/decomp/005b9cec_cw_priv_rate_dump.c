// func cw_priv_rate_dump @ 005b9cec size=600

undefined4 cw_priv_rate_dump(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private rate \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private rate (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar3 = 0;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",(uint)*pbVar2);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar2);
  printf("\t\t\t\t11a base: ");
  pbVar1 = pbVar2;
  do {
    iVar3 = iVar3 + 1;
    printf("%d ",(uint)pbVar1[1]);
    pbVar1 = pbVar2 + iVar3;
  } while (iVar3 != 8);
  iVar3 = 0;
  puts("\r");
  printf("\t\t\t\t11a supp: ");
  pbVar1 = pbVar2;
  do {
    iVar3 = iVar3 + 1;
    printf("%d ",(uint)pbVar1[9]);
    pbVar1 = pbVar2 + iVar3;
  } while (iVar3 != 8);
  iVar3 = 0;
  puts("\r");
  printf("\t\t\t\t11a mult: %d \r\n",(uint)pbVar2[0x11]);
  printf("\t\t\t\t11b base: ");
  pbVar1 = pbVar2;
  do {
    iVar3 = iVar3 + 1;
    printf("%d ",(uint)pbVar1[0x12]);
    pbVar1 = pbVar2 + iVar3;
  } while (iVar3 != 4);
  iVar3 = 0;
  puts("\r");
  printf("\t\t\t\t11b supp: ");
  pbVar1 = pbVar2;
  do {
    iVar3 = iVar3 + 1;
    printf("%d ",(uint)pbVar1[0x16]);
    pbVar1 = pbVar2 + iVar3;
  } while (iVar3 != 4);
  iVar3 = 0;
  puts("\r");
  printf("\t\t\t\t11b mult: %d \r\n",(uint)pbVar2[0x1a]);
  printf("\t\t\t\t11g base: ");
  pbVar1 = pbVar2;
  do {
    iVar3 = iVar3 + 1;
    printf("%d ",(uint)pbVar1[0x1b]);
    pbVar1 = pbVar2 + iVar3;
  } while (iVar3 != 0xc);
  iVar3 = 0;
  puts("\r");
  printf("\t\t\t\t11g supp: ");
  pbVar1 = pbVar2;
  do {
    iVar3 = iVar3 + 1;
    printf("%d ",(uint)pbVar1[0x27]);
    pbVar1 = pbVar2 + iVar3;
  } while (iVar3 != 0xc);
  puts("\r");
  printf("\t\t\t\t11g mult: %d \r\n",(uint)pbVar2[0x33]);
  printf("\t\t\t\t11n base mcs: %d \r\n",(uint)pbVar2[0x34]);
  printf("\t\t\t\t11n supp mcs: %d \r\n",(uint)pbVar2[0x35]);
  printf("\t\t\t\t11n mult mcs: %d \r\n",(uint)pbVar2[0x36]);
  return 0;
}

