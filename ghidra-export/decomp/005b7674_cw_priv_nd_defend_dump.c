// func cw_priv_nd_defend_dump @ 005b7674 size=420

undefined4 cw_priv_nd_defend_dump(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  undefined1 auStack_40 [40];
  
  pcVar2 = *(char **)(param_1 + 0x10);
  memset(auStack_40,0,0x28);
  printf("\t\t\tType: (t=%d,l=%d) private nd bind list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private nd bind list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x...\r\n",(int)*pcVar2);
  if (*pcVar2 == 1) {
    pcVar1 = "enable";
  }
  else {
    pcVar1 = "disable";
  }
  printf("\t\t\t\tenable: %u(%s) \r\n",(int)*pcVar2,pcVar1);
  if (pcVar2[1] == 1) {
    pcVar1 = "bind list changed";
  }
  else {
    pcVar1 = "bind list unchange";
  }
  printf("\t\t\t\trefresh operation: %u(%s) \r\n",(int)pcVar2[1],pcVar1);
  printf("\t\t\t\tbind count: %u \r\n",*(undefined4 *)(pcVar2 + 4));
  puts("\t\t\t\tnd info: \r");
  if ((0 < *(int *)(pcVar2 + 4)) && (uVar3 = 0, *(int *)(pcVar2 + 8) != 0)) {
    for (; (int)uVar3 < *(int *)(pcVar2 + 4); uVar3 = uVar3 + 1 & 0xff) {
      nd_addr2str(0,*(int *)(pcVar2 + 8) + uVar3 * 0x16,auStack_40,0x28);
      printf("\t\t\t\t\tnd ip: %s ",auStack_40);
      nd_addr2str(1,*(int *)(pcVar2 + 8) + uVar3 * 0x16 + 0x10,auStack_40,0x28);
      printf("mac: %s\r\n",auStack_40);
    }
  }
  return 0;
}

