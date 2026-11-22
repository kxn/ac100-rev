// func balance_destroy @ 0045a554 size=1

void balance_destroy(void)

{
  if (balance_db_mutex != 0) {
    FUN_00408360();
    balance_db_mutex = 0;
  }
  if (balance_wtp_hash != 0) {
    FUN_00408310();
    balance_wtp_hash = 0;
  }
  if (balance_dis_sta_hash != 0) {
    FUN_00408570(balance_dis_sta_hash,balance_dis_sta_entry_delete,0);
    FUN_00408310(balance_dis_sta_hash);
    balance_dis_sta_hash = 0;
  }
  if (balance_com != 0) {
    FUN_00407df0();
    balance_com = 0;
  }
  if (balance_wtp_array != 0) {
    FUN_00407df0();
    balance_wtp_array = 0;
  }
  if (balance_wtp_id != 0) {
    FUN_00408160();
    balance_wtp_id = 0;
  }
  return;
}

