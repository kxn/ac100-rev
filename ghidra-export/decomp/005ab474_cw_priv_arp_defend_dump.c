// func cw_priv_arp_defend_dump @ 005ab474 size=408

undefined4 cw_priv_arp_defend_dump(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  pcVar2 = *(char **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private arp bind list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private arp bind list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
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
  puts("\t\t\t\tarp info: \r");
  if ((0 < *(int *)(pcVar2 + 4)) && (uVar3 = 0, *(int *)(pcVar2 + 8) != 0)) {
    for (; (int)uVar3 < *(int *)(pcVar2 + 4); uVar3 = uVar3 + 1 & 0xff) {
      printf("\t\t\t\t\tarp ip: 0x%08x ",*(undefined4 *)(*(int *)(pcVar2 + 8) + uVar3 * 0xc));
      iVar4 = *(int *)(pcVar2 + 8) + uVar3 * 0xc;
      printf("mac: %02x:%02x:%02x:%02x:%02x:%02x\r\n",(uint)*(byte *)(iVar4 + 4),
             (uint)*(byte *)(iVar4 + 5),(uint)*(byte *)(iVar4 + 6),(uint)*(byte *)(iVar4 + 7),
             (uint)*(byte *)(iVar4 + 8),(uint)*(byte *)(iVar4 + 9));
    }
  }
  return 0;
}

