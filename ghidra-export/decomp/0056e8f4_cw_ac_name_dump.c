// func cw_ac_name_dump @ 0056e8f4 size=292

undefined4 cw_ac_name_dump(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  int iVar4;
  
  puVar3 = *(ushort **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) AC Name \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: AC Name (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  if ((*(int *)(puVar3 + 2) == 0) || (*puVar3 != *(ushort *)(param_1 + 0xe))) {
    puts("\t\t\t***AC Name Is NULL Or Length Is Wrong \r");
    uVar2 = 0xffffffff;
  }
  else {
    printf("\t\t\tValue: ");
    for (iVar4 = 0; iVar4 < (int)(uint)*puVar3; iVar4 = iVar4 + 1) {
      printf("%02x",(uint)*(byte *)(*(int *)(puVar3 + 2) + iVar4));
    }
    puts("\r");
    printf("\t\t\tAC Name: ");
    uVar1 = *puVar3;
    for (iVar4 = 0; iVar4 < (int)(uint)uVar1; iVar4 = iVar4 + 1) {
      putchar((uint)*(byte *)(*(int *)(puVar3 + 2) + iVar4));
      uVar1 = *puVar3;
    }
    puts("\r");
    uVar2 = 0;
  }
  return uVar2;
}

