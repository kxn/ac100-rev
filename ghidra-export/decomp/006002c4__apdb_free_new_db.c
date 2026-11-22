// func _apdb_free_new_db @ 006002c4 size=76

void _apdb_free_new_db(void)

{
  if (l_apdb_ap_item_new != 0) {
    _apdb_ap_item_free(l_apdb_ap_item_new,l_apdb_ap_item_cnt_new);
    l_apdb_ap_item_new = 0;
  }
  l_apdb_ap_item_cnt_new = 0;
  l_max_ap_cnt_new = 0;
  return;
}

