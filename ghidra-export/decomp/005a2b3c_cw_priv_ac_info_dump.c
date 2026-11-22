// func cw_priv_ac_info_dump @ 005a2b3c size=256

undefined4 cw_priv_ac_info_dump(int param_1)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ac info \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ac info (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar2 = 0;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: ");
  pbVar1 = pbVar3;
  do {
    iVar2 = iVar2 + 1;
    printf("%02x",(uint)*pbVar1);
    pbVar1 = pbVar3 + iVar2;
  } while (iVar2 != 6);
  iVar2 = 0;
  puts("\r");
  printf("\t\t\t\tac mac: ");
  pbVar1 = pbVar3;
  do {
    iVar2 = iVar2 + 1;
    printf("%02x:",(uint)*pbVar1);
    pbVar1 = pbVar3 + iVar2;
  } while (iVar2 != 5);
  printf("%02x\r\n",(uint)pbVar3[5]);
  return 0;
}

