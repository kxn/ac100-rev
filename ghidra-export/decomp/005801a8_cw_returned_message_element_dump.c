// func cw_returned_message_element_dump @ 005801a8 size=332

undefined4 cw_returned_message_element_dump(int param_1)

{
  char *__format;
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Returned Message Element \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Returned Message Element (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x...\r\n",(uint)*pbVar2,(uint)pbVar2[1]);
  uVar1 = (uint)*pbVar2;
  if (uVar1 - 1 < 4) {
    printf("\t\t\tReason: %d \r\n");
    uVar1 = (uint)pbVar2[1];
    if ((uVar1 != 0) && (*(ushort *)(param_1 + 0xe) - 2 == uVar1)) {
      printf("\t\t\tLength: %d \r\n");
      if (*(int *)(pbVar2 + 4) != 0) {
        printf("\t\t\tMessage: ");
        for (iVar3 = 0; iVar3 < (int)(uint)pbVar2[1]; iVar3 = iVar3 + 1) {
          printf("%02x",(uint)*(byte *)(*(int *)(pbVar2 + 4) + iVar3));
        }
        puts("\r");
        return 0;
      }
      puts("\t\t\t***Message is NULL \r");
      return 0xffffffff;
    }
    __format = "\t\t\t***Length(%d) Is Wrong \r\n";
  }
  else {
    __format = "\t\t\t***Reason(%d) Is Wrong \r\n";
  }
  printf(__format,uVar1);
  return 0xffffffff;
}

