// func stats_db_print_bssid_all @ 006717e4 size=72

void stats_db_print_bssid_all(void)

{
  FUN_004082d0(l_stats_data,0xffffffff);
  FUN_00408570(DAT_007cc8f4,_stats_db_print_bssid_cb,0);
  FUN_00407f30(l_stats_data);
  return;
}

