// func cw_capwap_local_ipv6_address_dump @ 0057105c size=248

undefined4 cw_capwap_local_ipv6_address_dump(int param_1)

{
  byte *pbVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  byte *__cp;
  char acStack_48 [52];
  
  __cp = *(byte **)(param_1 + 0x10);
  memset(acStack_48,0,0x2e);
  printf("\t\tType: (t=%d,l=%d) CAPWAP Local IPv6 Address \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: CAPWAP Local IPv6 Address (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar4 = 0;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: ");
  pbVar1 = __cp;
  do {
    iVar4 = iVar4 + 1;
    printf("%02x",(uint)*pbVar1);
    pbVar1 = __cp + iVar4;
  } while (iVar4 != 0x10);
  puts("\r");
  pcVar2 = inet_ntop(10,__cp,acStack_48,0x2e);
  uVar3 = 0xffffffff;
  if (pcVar2 != (char *)0x0) {
    printf("\t\t\tCAPWAP Local IP Address: %s \r\n",acStack_48);
    uVar3 = 0;
  }
  return uVar3;
}

