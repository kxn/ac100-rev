// func arp_defend_print_all_arp @ 0047efc8 size=184

void arp_defend_print_all_arp(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  uVar1 = 0;
  while (uVar1 < g_arp_defend_profile) {
    if (*(int *)(DAT_0076710c + uVar1 * 0x120) == -1) {
      iVar3 = iVar3 + 1;
      uVar1 = uVar1 + 1;
    }
    else {
      iVar2 = iVar2 + 1;
      arp_defend_print_arp_entry();
      uVar1 = uVar1 + 1;
    }
  }
  printf("total group entry number count: is %d, unused is %d\n",iVar2,iVar3);
  return;
}

