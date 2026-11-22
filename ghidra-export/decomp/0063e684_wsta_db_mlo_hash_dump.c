// func wsta_db_mlo_hash_dump @ 0063e684 size=1

void wsta_db_mlo_hash_dump(void)

{
  puts("MLO wstation hash table show:");
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  FUN_00408570(DAT_007cc728,_wsta_db_mlo_hash_show_cb,0);
  puts("*********************PEER hash**********************");
  FUN_00408570(DAT_007cc72c,_wsta_db_peer_hash_show_cb,0);
  uac_mutex_give(DAT_007cc6bc);
  return;
}

