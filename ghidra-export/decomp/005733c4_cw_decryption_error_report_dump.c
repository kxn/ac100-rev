// func cw_decryption_error_report_dump @ 005733c4 size=388

undefined4 cw_decryption_error_report_dump(int param_1)

{
  ushort uVar1;
  char *__format;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  uVar1 = *(ushort *)(param_1 + 0xe);
  printf("\t\tType: (t=%d,l=%d) Decryption Error Report \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)uVar1);
  printf("\t\t\tType: Add MAC ACL Entry (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar2,(uint)pbVar2[1]);
  if (*pbVar2 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (pbVar2[1] == 0) {
      __format = "\t\t\t***Num of Entries(%d) is wrong \r\n";
    }
    else {
      printf("\t\t\tNum of Entries: %d \r\n");
      if ((pbVar2[2] == 6) || (pbVar2[2] == 8)) {
        uVar4 = uVar1 - 3;
        printf("\t\t\tLength: %d \r\n");
        if ((uVar4 == (uint)pbVar2[1] * (uint)pbVar2[2]) && (*(int *)(pbVar2 + 4) != 0)) {
          printf("\t\t\tMAC Address: ");
          for (uVar3 = 0; uVar3 < uVar4; uVar3 = uVar3 + 1) {
            printf("%02x",(uint)*(byte *)(*(int *)(pbVar2 + 4) + uVar3));
          }
          puts("\r");
          return 0;
        }
        puts("\t\t\t***mac address is wrong \r");
        return 0xffffffff;
      }
      __format = "\t\t\t***Length(%d) is wrong \r\n";
    }
  }
  else {
    __format = "\t\t\t***Radio ID(%d) is wrong. Radio ID must be in 1 ~ 31 \r\n";
  }
  printf(__format);
  return 0xffffffff;
}

