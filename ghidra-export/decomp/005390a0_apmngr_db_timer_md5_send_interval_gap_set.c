// func apmngr_db_timer_md5_send_interval_gap_set @ 005390a0 size=1

undefined4 apmngr_db_timer_md5_send_interval_gap_set(undefined2 param_1)

{
  g_apmngr_timer_md5_send_interval_gap = param_1;
  return 0;
}

