// func cw_location_data_dump @ 005778d4 size=252

undefined4 cw_location_data_dump(int param_1)

{
  undefined4 uVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = *(short **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Location Data \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Location Data (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  if ((*(int *)(psVar2 + 2) == 0) || (*psVar2 != *(short *)(param_1 + 0xe))) {
    puts("\t\t\t***Location Or Length is wrong \r");
    uVar1 = 0xffffffff;
  }
  else {
    printf("\t\t\tValue: ");
    for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(param_1 + 0xe); iVar3 = iVar3 + 1) {
      printf("%02x",(uint)*(byte *)(*(int *)(psVar2 + 2) + iVar3));
    }
    puts("\r");
    printf("\t\t\tLocation Data: %s \r\n",*(undefined4 *)(psVar2 + 2));
    uVar1 = 0;
  }
  return uVar1;
}

