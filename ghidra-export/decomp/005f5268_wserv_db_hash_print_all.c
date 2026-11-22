// func wserv_db_hash_print_all @ 005f5268 size=1

void wserv_db_hash_print_all(void)

{
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  if (l_wserv_data != 0) {
    puts("########################################################");
    printf("l_wserv_data.wserv_used = %d\n",DAT_007cbef8);
    FUN_00408570(g_wserv_hash,_wserv_print_hash_entry,0);
  }
  uac_mutex_give(DAT_007cbef0);
  return;
}

