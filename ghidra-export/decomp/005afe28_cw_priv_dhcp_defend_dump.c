// func cw_priv_dhcp_defend_dump @ 005afe28 size=444

undefined4 cw_priv_dhcp_defend_dump(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private dhcp defend \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private dhcp defend (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
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
        addrtype2str((int)*(char *)(*(int *)(pbVar2 + 8) + uVar3 * 7),&local_38);
        printf("\t\t\t\t\taddr type: %s, ",&local_38);
        pcVar1 = (char *)(*(int *)(pbVar2 + 8) + uVar3 * 7);
        addr2str((int)*pcVar1,pcVar1 + 1,&local_2c);
        printf("svr_addr: %s\r\n",&local_2c);
      }
    }
  }
  return 0;
}

