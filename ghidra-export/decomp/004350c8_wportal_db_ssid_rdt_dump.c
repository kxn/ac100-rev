// func wportal_db_ssid_rdt_dump @ 004350c8 size=212

void wportal_db_ssid_rdt_dump(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  puts("Rdt entry for ssid:");
  uVar3 = 0;
  FUN_004082d0(wportal_rdt_mutex,0xffffffff);
  while( true ) {
    uVar1 = wserv_profile_get_max_wservice();
    if (uVar1 <= uVar3) break;
    iVar2 = *(int *)(wportal_wserv_node + uVar3 * 8 + 4);
    if (iVar2 != 0) {
      printf(" wserv_id: %d, auth_type: %d, failId: %d, failUrl: %s, portalId: %d, portalUrl: %s, auth_server_type: %d, is_escape: %d\n"
             ,*(undefined4 *)(iVar2 + 0x134),*(undefined4 *)(iVar2 + 0x15c),
             *(undefined4 *)(iVar2 + 0x154),iVar2,*(undefined4 *)(iVar2 + 0x158),iVar2 + 0x80,
             *(undefined4 *)(iVar2 + 0x160),*(undefined4 *)(iVar2 + 0x164));
      putchar(10);
    }
    uVar3 = uVar3 + 1;
  }
  FUN_00407f30(wportal_rdt_mutex);
  return;
}

