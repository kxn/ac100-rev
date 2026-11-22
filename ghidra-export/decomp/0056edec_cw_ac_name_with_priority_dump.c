// func cw_ac_name_with_priority_dump @ 0056edec size=280

undefined4 cw_ac_name_with_priority_dump(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) AC Name With Priority \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: AC Name With Priority (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  if (((uint)*(ushort *)(param_1 + 0xe) == *(ushort *)(pbVar3 + 2) + 1) &&
     (*(int *)(pbVar3 + 4) != 0)) {
    printf("\t\t\tValue: ");
    printf("%02x",(uint)*pbVar3);
    uVar1 = *(ushort *)(pbVar3 + 2);
    for (iVar4 = 0; iVar4 < (int)(uint)uVar1; iVar4 = iVar4 + 1) {
      printf("%02x",(uint)*(byte *)(*(int *)(pbVar3 + 4) + iVar4));
      uVar1 = *(ushort *)(pbVar3 + 2);
    }
    puts("\r");
    printf("\t\t\tAC Name Priority: %d \r\n",(uint)*pbVar3);
    printf("\t\t\tAC Name: %s \r\n",*(undefined4 *)(pbVar3 + 4));
    uVar2 = 0;
  }
  else {
    puts("\t\t\t***AC Name Is NULL Or Length Is Wrong \r");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

