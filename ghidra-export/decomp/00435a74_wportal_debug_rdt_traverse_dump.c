// func wportal_debug_rdt_traverse_dump @ 00435a74 size=1

undefined4 wportal_debug_rdt_traverse_dump(void)

{
  int iVar1;
  int iVar2;
  
  puts("Rdt entry in uac:");
  iVar2 = 0;
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  do {
    iVar1 = rdt_list + iVar2;
    if (*(int *)(iVar1 + 0x134) != 0) {
      printf("  Vlan: %d, portalUrl: %s, portalId: %d, fail_id: %d, fail url: %s, auth_server_type: %d, is_escape: %d\n"
             ,*(int *)(iVar1 + 0x134),iVar1 + 0x80,*(undefined4 *)(iVar1 + 0x158),
             *(undefined4 *)(iVar1 + 0x154),iVar1,*(undefined4 *)(iVar1 + 0x160),
             *(undefined4 *)(iVar1 + 0x164));
    }
    iVar2 = iVar2 + 0x16c;
  } while (iVar2 != 0x16c16c);
  FUN_00407f30(wportal_rdt_mutex);
  putchar(10);
  return 0;
}

