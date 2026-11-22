// func cw_priv_igmp_snooping_group_policy_dump @ 005b36a0 size=376

undefined4 cw_priv_igmp_snooping_group_policy_dump(int param_1)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_50 [44];
  
  puVar2 = *(uint **)(param_1 + 0x10);
  memset(auStack_50,0,0x28);
  printf("\t\t\tType: (t=%d,l=%d) private igmp snooping group policy \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private igmp snooping group policy (%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x...\r\n",*puVar2);
  printf("\t\t\t\tip count: %u \r\n",*puVar2);
  puts("\t\t\t\tip info: \r");
  if ((*puVar2 != 0) && (uVar3 = 0, puVar2[1] != 0)) {
    while (uVar3 < *puVar2) {
      iVar4 = uVar3 * 0x18;
      printf("\t\t\t\tip list(%d):\r\n",uVar3);
      uVar3 = uVar3 + 1;
      cw_protocol_addr2str(puVar2[1] + iVar4 + 4,auStack_50,0x28);
      pcVar1 = "unicast";
      if (*(char *)(puVar2[1] + iVar4) != '\x01') {
        pcVar1 = "multicast";
      }
      printf("\t\t\t\t\trelay policy: %s\r\n",pcVar1);
      printf("\t\t\t\t\tip: %s\r\n",auStack_50);
    }
  }
  return 0;
}

