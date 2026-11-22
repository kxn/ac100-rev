// func wserv_db_print_ap_hash @ 005f504c size=1

void wserv_db_print_ap_hash(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  if (l_wserv_data != 0) {
    puts("########################################################");
    iVar2 = 0;
    do {
      iVar1 = *(int *)(DAT_007cbf08 + iVar2 * 4);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
        printf("vlan[%d]\'s ap hash size = %d",iVar2);
        FUN_00408570(*(undefined4 *)(DAT_007cbf08 + iVar2 * 4),_print_vlan_ap_hash,0);
        puts("\n########################################################");
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x1000);
  }
  uac_mutex_give(DAT_007cbef0);
  return;
}

