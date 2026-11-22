// func cw_ac_ipv6_list_dump @ 0056e34c size=364

uint cw_ac_ipv6_list_dump(int param_1)

{
  char *pcVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  char acStack_48 [52];
  
  puVar3 = *(ushort **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) AC IPv6 List \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Type: AC IPv6 List (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  if ((*(ushort *)(param_1 + 0xe) & 0xf) == 0) {
    printf("\t\t\tLength: %d \r\n");
    if (((*(int *)(puVar3 + 2) == 0) || (*puVar3 == 0)) ||
       (*puVar3 != *(ushort *)(param_1 + 0xe) >> 4)) {
      puts("\t\t\t***AC IPv4 List Is Wrong \r");
LAB_0056e4a0:
      uVar2 = 0xffffffff;
    }
    else {
      printf("\t\t\tValue: ");
      for (iVar4 = 0; iVar4 < (int)(uint)*(ushort *)(param_1 + 0xe); iVar4 = iVar4 + 1) {
        printf("%02x",(uint)*(byte *)(*(int *)(puVar3 + 2) + iVar4));
      }
      puts("\r");
      for (iVar4 = 0; uVar2 = (uint)(iVar4 < (int)(uint)*puVar3), uVar2 != 0; iVar4 = iVar4 + 1) {
        memset(acStack_48,0,0x2e);
        pcVar1 = inet_ntop(10,(void *)(*(int *)(puVar3 + 2) + iVar4 * 0x10),acStack_48,0x2e);
        if (pcVar1 == (char *)0x0) goto LAB_0056e4a0;
        printf("\t\t\tAC IPv4 List: %s \r\n",acStack_48);
      }
    }
  }
  else {
    printf("\t\t\t***Length(%d) Is Wrong \r\n");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

