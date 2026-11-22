// func cw_priv_radio_role_table_dump @ 005b9500 size=260

undefined4 cw_priv_radio_role_table_dump(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) radio role table \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: apdb info (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: ");
  iVar4 = *(ushort *)(param_1 + 0xe) - 1;
  if (*(int *)(iVar2 + 4) != 0) {
    iVar3 = 10;
    if (iVar4 < 0xb) {
      iVar3 = iVar4;
    }
    printf("\t\t\t\tapdb info: ");
    for (iVar1 = 0; iVar1 < iVar3; iVar1 = iVar1 + 1) {
      printf("%02x",(uint)*(byte *)(*(int *)(iVar2 + 4) + iVar1));
    }
    if (iVar4 >= 0xb) {
      printf("...");
    }
    puts("\r");
  }
  return 0;
}

