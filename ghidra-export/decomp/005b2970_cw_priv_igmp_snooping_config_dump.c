// func cw_priv_igmp_snooping_config_dump @ 005b2970 size=368

undefined4 cw_priv_igmp_snooping_config_dump(int param_1)

{
  char *pcVar1;
  undefined *puVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar3 = *(char **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private igmp snooping config \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private igmp snooping config (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  if (*pcVar3 == '\x01') {
    pcVar1 = "true";
  }
  else {
    pcVar1 = "false";
  }
  printf("\t\t\t\tsnooping enable: %s \r\n",pcVar1);
  if (pcVar3[1] == '\x01') {
    puVar2 = &DAT_006a2b04;
  }
  else {
    puVar2 = &DAT_00691368;
  }
  printf("\t\t\t\tdrop unknown: %s \r\n",puVar2);
  printf("\t\t\t\tradio count: %u \r\n",(uint)(byte)pcVar3[2]);
  puts("\t\t\t\tradio list: \r");
  if ((pcVar3[2] != '\0') && (iVar4 = 0, *(int *)(pcVar3 + 4) != 0)) {
    for (; iVar4 < (int)(uint)(byte)pcVar3[2]; iVar4 = iVar4 + 1) {
      printf("\t\t\t\tradio(%d):\r\n",iVar4);
      printf("\t\t\t\t\tradio id: %d \r\n",(uint)*(byte *)(*(int *)(pcVar3 + 4) + iVar4 * 4));
      printf("\t\t\t\t\trate: %d \r\n",(uint)*(ushort *)(*(int *)(pcVar3 + 4) + iVar4 * 4 + 2));
    }
  }
  return 0;
}

