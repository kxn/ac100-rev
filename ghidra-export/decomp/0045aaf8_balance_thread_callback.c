// func balance_thread_callback @ 0045aaf8 size=88

void balance_thread_callback(void)

{
  do {
    sleep(300);
    FUN_004082d0(balance_db_mutex,0xffffffff);
    FUN_00408570(balance_dis_sta_hash,balance_cnt_wtp_delete_timer_callback,0);
    FUN_00407f30(balance_db_mutex);
  } while( true );
}

