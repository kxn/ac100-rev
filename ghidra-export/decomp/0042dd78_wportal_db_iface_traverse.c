// func wportal_db_iface_traverse @ 0042dd78 size=232

undefined4 wportal_db_iface_traverse(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  puts("iface entry in uac:");
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  do {
    iVar1 = iface_list + iVar2;
    if (*(char *)(iVar1 + 0x134) != '\0') {
      printf("  Interface: %s, portalUrl: %s, portalId: %d, fail_id: %d, fail url: %s, auth_server_type: %d\n"
             ,iVar1 + 0x134,iVar1 + 0x80,*(undefined4 *)(iVar1 + 0x158),
             *(undefined4 *)(iVar1 + 0x154),iVar1,*(undefined4 *)(iVar1 + 0x160));
    }
    iVar2 = iVar2 + 0x16c;
  } while (iVar2 != 0x2d80);
  FUN_00407f30(wportal_rdt_mutex);
  putchar(10);
  printf("cmcc_iface_list_count is %d \n",cmcc_iface_list_count);
  return 0;
}

