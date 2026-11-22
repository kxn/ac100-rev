// func arp_defend_print_all_ap @ 0047ef10 size=184

void arp_defend_print_all_ap(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar4 = 0;
  iVar3 = 0;
  while( true ) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (iVar1 + iVar2 <= iVar3) break;
    if (*(int *)(DAT_00767104 + iVar3 * 0x10) == -1) {
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 1;
    }
    else {
      iVar4 = iVar4 + 1;
      arp_defend_print_ap_entry();
      iVar3 = iVar3 + 1;
    }
  }
  printf("total mac entry number count: is %d, unused is %d\n",iVar4,iVar5);
  return;
}

