// func cw_priv_igmp_snooping_config_by_ssid_dump @ 005b2fd4 size=356

undefined4 cw_priv_igmp_snooping_config_by_ssid_dump(int param_1)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = *(uint **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private igmp config by ssid \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private igmp config by ssid (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tssid count: %u \r\n",*puVar2);
  puts("\t\t\t\tssid list: \r");
  if ((*puVar2 != 0) && (uVar3 = 0, puVar2[1] != 0)) {
    for (; uVar3 < *puVar2; uVar3 = uVar3 + 1) {
      iVar4 = uVar3 * 3;
      printf("\t\t\t\tssid(%d):\r\n",uVar3);
      printf("\t\t\t\t\tradio id: %d \r\n",(uint)*(byte *)(puVar2[1] + iVar4));
      printf("\t\t\t\t\twlan id: %d \r\n",(uint)*(byte *)(puVar2[1] + iVar4 + 1));
      pcVar1 = "disable";
      if (*(char *)(puVar2[1] + iVar4 + 2) == '\x01') {
        pcVar1 = "enable";
      }
      printf("\t\t\t\t\tsnooping enable: %s \r\n",pcVar1);
    }
  }
  return 0;
}

