// func wportal_db_vlanlist_for_aut_number @ 00434494 size=1

void wportal_db_vlanlist_for_aut_number(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  puts("Vlan list for aut:");
  FUN_004082d0(wportal_aut_mutex,0xffffffff);
  do {
    iVar1 = FUN_004081b0(vlan_list_array_for_aut + iVar2 * 0xc);
    if (iVar1 != 0) {
      iVar3 = 0;
      printf(" VLAN %d:, num: ",iVar2);
      do {
        iVar3 = iVar3 + (uint)(iVar1 != 0x110);
        iVar1 = FUN_00408680(iVar1);
      } while (iVar1 != 0);
      printf("%d\n",iVar3);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x1000);
  FUN_00407f30(wportal_aut_mutex);
  putchar(10);
  return;
}

