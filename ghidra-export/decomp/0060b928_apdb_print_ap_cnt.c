// func apdb_print_ap_cnt @ 0060b928 size=1

void apdb_print_ap_cnt(void)

{
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  printf("The elements of the apdb is %d\n",l_apdb_ap_item_cnt_cur);
  uac_mutex_give(l_apdb_mutex);
  return;
}

