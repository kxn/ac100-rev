// func cw_ac_ipv4_list_dump @ 0056dd1c size=360

uint cw_ac_ipv4_list_dump(int param_1)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 local_28;
  char acStack_24 [20];
  
  local_28 = 0;
  puVar2 = *(ushort **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) AC IPv4 List \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Type: AC IPv4 List (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  if ((*(ushort *)(param_1 + 0xe) & 3) == 0) {
    printf("\t\t\tLength: %d \r\n");
    if (((*(int *)(puVar2 + 2) == 0) || (*puVar2 == 0)) ||
       (*puVar2 != *(ushort *)(param_1 + 0xe) >> 2)) {
      puts("\t\t\t***AC IPv4 List Is Wrong \r");
      uVar1 = 0xffffffff;
    }
    else {
      printf("\t\t\tValue: ");
      for (iVar3 = 0; iVar3 < (int)(uint)*puVar2; iVar3 = iVar3 + 1) {
        printf("%08x",*(undefined4 *)(*(int *)(puVar2 + 2) + iVar3 * 4));
      }
      puts("\r");
      for (iVar3 = 0; uVar1 = (uint)(iVar3 < (int)(uint)*puVar2), uVar1 != 0; iVar3 = iVar3 + 1) {
        local_28 = *(undefined4 *)(*(int *)(puVar2 + 2) + iVar3 * 4);
        inet_ntop(2,&local_28,acStack_24,0x14);
        printf("\t\t\tAC IPv4 List: %s (%s) \r\n",acStack_24,acStack_24);
      }
    }
  }
  else {
    printf("\t\t\t***Length(%d) Is Wrong \r\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

