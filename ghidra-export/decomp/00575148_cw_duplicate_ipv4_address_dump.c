// func cw_duplicate_ipv4_address_dump @ 00575148 size=400

undefined4 cw_duplicate_ipv4_address_dump(int param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_30;
  char acStack_2c [24];
  
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Duplicate IPv4 Address \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Duplicate IPv4 Address (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %08x...\r\n",*puVar3);
  local_30 = *puVar3;
  inet_ntop(2,&local_30,acStack_2c,0x14);
  printf("\t\t\tDuplicate IP Address: %s (%s) \r\n",acStack_2c,acStack_2c);
  if (*(byte *)(puVar3 + 1) < 2) {
    printf("\t\t\tStatus: %d \r\n");
    uVar2 = (uint)*(byte *)((int)puVar3 + 5);
    if (((uVar2 == 6) || (uVar2 == 8)) && (*(ushort *)(param_1 + 0xe) - 6 == uVar2)) {
      printf("\t\t\tLength: %d \r\n");
      if (puVar3[2] != 0) {
        printf("\t\t\tMAC Address: ");
        uVar2 = 0;
        while ((int)uVar2 < (int)(uint)*(byte *)((int)puVar3 + 5)) {
          pcVar1 = "%02x \r\n";
          if (uVar2 + 1 != (uint)*(byte *)((int)puVar3 + 5)) {
            pcVar1 = "%02x:";
          }
          printf(pcVar1,(uint)*(byte *)(puVar3[2] + uVar2));
          uVar2 = uVar2 + 1;
        }
        return 0;
      }
      puts("\t\t\t***MAC Address Is NULL \r");
      return 0xffffffff;
    }
    pcVar1 = "\t\t\t***Length(%d) Is Wrong \r\n";
  }
  else {
    pcVar1 = "\t\t\t***Status(%d) Is Wrong \r\n";
  }
  printf(pcVar1);
  return 0xffffffff;
}

