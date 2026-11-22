// func wportal_db_vlanlist_for_aut_dump @ 00433ff4 size=284

void wportal_db_vlanlist_for_aut_dump(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  puts("Vlan list for aut:");
  do {
    iVar1 = FUN_004081b0(vlan_list_array_for_aut + iVar2 * 0xc);
    if (iVar1 != 0) {
      printf(" VLAN %d: \n",iVar2);
      for (; iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        if (iVar1 != 0x110) {
          printf("   autEntry: vlan %d, wserid: %d, mac: %02x:%02x:%02x:%02x:%02x:%02x, auth_type: %d, IP: %s, expire: %d status: %d\n"
                 ,*(undefined4 *)(iVar1 + -0xfc),*(undefined4 *)(iVar1 + -0xfc),
                 (uint)*(byte *)(iVar1 + -0x104),(uint)*(byte *)(iVar1 + -0x103),
                 (uint)*(byte *)(iVar1 + -0x102),(uint)*(byte *)(iVar1 + -0x101),
                 (uint)*(byte *)(iVar1 + -0x100),(uint)*(byte *)(iVar1 + -0xff),
                 (uint)*(byte *)(iVar1 + -0x90),iVar1 + -0xb8,*(undefined4 *)(iVar1 + -0xd4),
                 *(undefined4 *)(iVar1 + 0x3c));
        }
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x1000);
  putchar(10);
  return;
}

