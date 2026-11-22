// func cw_duplicate_ipv6_address_dump @ 00575878 size=428

undefined4 cw_duplicate_ipv6_address_dump(int param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *__cp;
  char acStack_48 [52];
  
  __cp = *(byte **)(param_1 + 0x10);
  memset(acStack_48,0,0x2e);
  printf("\t\tType: (t=%d,l=%d) Duplicate IPv6 Address \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Duplicate IPv4 Address (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  uVar3 = 0xffffffff;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x...\r\n",(uint)*__cp);
  pcVar1 = inet_ntop(10,__cp,acStack_48,0x2e);
  if (pcVar1 != (char *)0x0) {
    printf("\t\t\tCAPWAP Local IP Address: %s \r\n",acStack_48);
    if (__cp[0x10] < 2) {
      printf("\t\t\tStatus: %d \r\n");
      uVar2 = (uint)__cp[0x11];
      if (((uVar2 == 6) || (uVar2 == 8)) && (*(ushort *)(param_1 + 0xe) - 6 == uVar2)) {
        printf("\t\t\tLength: %d \r\n");
        if (*(int *)(__cp + 0x14) == 0) {
          uVar3 = 0xffffffff;
          puts("\t\t\t***MAC Address Is NULL \r");
        }
        else {
          printf("\t\t\tMAC Address: ");
          uVar2 = 0;
          while ((int)uVar2 < (int)(uint)__cp[0x11]) {
            pcVar1 = "%02x \r\n";
            if (uVar2 + 1 != (uint)__cp[0x11]) {
              pcVar1 = "%02x:";
            }
            printf(pcVar1,(uint)*(byte *)(*(int *)(__cp + 0x14) + uVar2));
            uVar2 = uVar2 + 1;
          }
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0xffffffff;
        printf("\t\t\t***Length(%d) Is Wrong \r\n");
      }
    }
    else {
      printf("\t\t\t***Status(%d) Is Wrong \r\n");
    }
  }
  return uVar3;
}

