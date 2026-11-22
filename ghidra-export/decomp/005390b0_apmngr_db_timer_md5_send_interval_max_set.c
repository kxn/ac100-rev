// func apmngr_db_timer_md5_send_interval_max_set @ 005390b0 size=1

undefined4 apmngr_db_timer_md5_send_interval_max_set(undefined2 param_1)

{
  g_apmngr_timer_md5_send_interval_max = param_1;
  return 0;
}

