// func _apdb_free_all_db @ 00600258 size=108

void _apdb_free_all_db(void)

{
  if (l_apdb_ap_item_new != 0) {
    _apdb_ap_item_free(l_apdb_ap_item_new,l_apdb_ap_item_cnt_new);
    l_apdb_ap_item_new = 0;
  }
  l_apdb_ap_item_cnt_new = 0;
  l_max_ap_cnt_new = 0;
  if (l_apdb_ap_item_cur != 0) {
    _apdb_ap_item_free(l_apdb_ap_item_cur,l_apdb_ap_item_cnt_cur);
    l_apdb_ap_item_cur = 0;
  }
  l_apdb_ap_item_cnt_cur = 0;
  return;
}

