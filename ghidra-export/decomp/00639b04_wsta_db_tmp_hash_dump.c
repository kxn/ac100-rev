// func wsta_db_tmp_hash_dump @ 00639b04 size=84

void wsta_db_tmp_hash_dump(void)

{
  puts("tmp sta hash table show:");
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  FUN_00408570(DAT_007cc718,_wsta_db_tmp_hash_show_cb,0);
  FUN_00407f30(DAT_007cc6bc);
  return;
}

