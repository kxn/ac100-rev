// func wserv_db_print_all @ 005f5150 size=280

void wserv_db_print_all(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  if (l_wserv_data != 0) {
    puts("########################################################");
    uVar2 = 0;
    printf("l_wserv_data.wserv_used = %d\n",DAT_007cbef8);
    while (uVar2 < l_wserv_profile) {
      iVar3 = uVar2 * 0x21c;
      iVar1 = DAT_007cbefc + iVar3;
      if (*(int *)(iVar1 + 0xc) == 0) {
        uVar2 = uVar2 + 1;
      }
      else {
        uVar2 = uVar2 + 1;
        _wserv_print_entry(iVar1 + 0x10);
        printf("rd_hash   = ");
        FUN_00408570(*(undefined4 *)(DAT_007cbefc + iVar3 + 0x218),_print_rd_wlan_hash,0);
        putchar(10);
      }
    }
  }
  FUN_00407f30(DAT_007cbef0);
  return;
}

