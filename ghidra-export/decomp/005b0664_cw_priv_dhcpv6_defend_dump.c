// func cw_priv_dhcpv6_defend_dump @ 005b0664 size=444

undefined4 cw_priv_dhcpv6_defend_dump(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 local_48;
  undefined1 auStack_44 [44];
  
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  pbVar2 = *(byte **)(param_1 + 0x10);
  memset(auStack_44,0,0x28);
  printf("\t\t\tType: (t=%d,l=%d) private dhcpv6 defend \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private dhcpv6 defend (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x...\r\n",(uint)*pbVar2,(uint)pbVar2[1]);
  if (*pbVar2 == 1) {
    pcVar1 = "enable";
  }
  else {
    pcVar1 = "disable";
  }
  printf("\t\t\t\tenable      : %u(%s) \r\n",(uint)*pbVar2,pcVar1);
  if (pbVar2[1] == 1) {
    pcVar1 = "refresh";
  }
  else {
    pcVar1 = "non-refresh";
  }
  printf("\t\t\t\tbind refresh: %u(%s) \r\n",(uint)pbVar2[1],pcVar1);
  if (pbVar2[1] != 0) {
    printf("\t\t\t\tbind svr count: %u \r\n",*(undefined4 *)(pbVar2 + 4));
    puts("\t\t\t\tbind svr info : \r");
    if ((*(int *)(pbVar2 + 4) != 0) && (uVar3 = 0, *(int *)(pbVar2 + 8) != 0)) {
      for (; uVar3 < *(uint *)(pbVar2 + 4); uVar3 = uVar3 + 1) {
        dhcpv6_addrtype2str((int)*(char *)(*(int *)(pbVar2 + 8) + uVar3 * 0x11),&local_50);
        printf("\t\t\t\t\taddr type: %s, ",&local_50);
        pcVar1 = (char *)(*(int *)(pbVar2 + 8) + uVar3 * 0x11);
        dhcpv6_addr2str((int)*pcVar1,pcVar1 + 1,auStack_44,0x28);
        printf("svr_addr: %s\r\n",auStack_44);
      }
    }
  }
  return 0;
}

