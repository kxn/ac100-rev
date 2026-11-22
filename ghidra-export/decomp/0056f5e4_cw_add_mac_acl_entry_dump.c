// func cw_add_mac_acl_entry_dump @ 0056f5e4 size=352

undefined4 cw_add_mac_acl_entry_dump(int param_1)

{
  ushort uVar1;
  char *__format;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  uVar1 = *(ushort *)(param_1 + 0xe);
  printf("\t\tType: (t=%d,l=%d) Add MAC ACL Entry \r\n",(uint)*(ushort *)(param_1 + 0xc),(uint)uVar1
        );
  printf("\t\t\tType: Add MAC ACL Entry (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar2,(uint)pbVar2[1]);
  if (*pbVar2 == 0) {
    __format = "\t\t\t***Num of Entries(%d) Is Wrong \r\n";
  }
  else {
    printf("\t\t\tNum of Entries: %d \r\n");
    if ((pbVar2[1] == 6) || (pbVar2[1] == 8)) {
      uVar4 = uVar1 - 2;
      printf("\t\t\tLength: %d \r\n");
      if ((uVar4 == (uint)*pbVar2 * (uint)pbVar2[1]) && (*(int *)(pbVar2 + 4) != 0)) {
        printf("\t\t\tMAC Address: ");
        for (uVar3 = 0; uVar3 < uVar4; uVar3 = uVar3 + 1) {
          printf("%02x",(uint)*(byte *)(*(int *)(pbVar2 + 4) + uVar3));
        }
        puts("\r");
        return 0;
      }
      puts("\t\t\t***MAC Address Is NULL Or Total Length Of MAC Address Is Wrong \r");
      return 0xffffffff;
    }
    __format = "\t\t\t***Length(%d) Is Wrong \r\n";
  }
  printf(__format);
  return 0xffffffff;
}

