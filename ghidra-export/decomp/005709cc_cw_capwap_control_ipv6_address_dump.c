// func cw_capwap_control_ipv6_address_dump @ 005709cc size=268

undefined4 cw_capwap_control_ipv6_address_dump(int param_1)

{
  byte *pbVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  byte *__cp;
  char acStack_48 [52];
  
  __cp = *(byte **)(param_1 + 0x10);
  memset(acStack_48,0,0x2e);
  printf("\t\tType: (t=%d,l=%d) CAPWAP Control IPv6 Address \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: CAPWAP Control IPv6 Address (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar4 = 0;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: ");
  pbVar1 = __cp;
  do {
    iVar4 = iVar4 + 1;
    printf("%02x",(uint)*pbVar1);
    pbVar1 = __cp + iVar4;
  } while (iVar4 != 0x10);
  printf("%04x \r\n",(uint)*(ushort *)(__cp + 0x10));
  pcVar2 = inet_ntop(10,__cp,acStack_48,0x2e);
  uVar3 = 0xffffffff;
  if (pcVar2 != (char *)0x0) {
    printf("\t\t\tCAPWAP Control IP Address: %s \r\n",acStack_48);
    printf("\t\t\tCAPWAP Control WTP Count: %d \r\n",(uint)*(ushort *)(__cp + 0x10));
    uVar3 = 0;
  }
  return uVar3;
}

