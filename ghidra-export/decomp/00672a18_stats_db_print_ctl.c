// func stats_db_print_ctl @ 00672a18 size=148

void stats_db_print_ctl(void)

{
  printf("sta_switch: %d\n",(uint)stats_ctl);
  printf("rssi_switch: %d\n",(uint)DAT_00758cf5);
  printf("ap_switch: %d\n",(uint)DAT_00758cf6);
  printf("sta_notify_interval: %d\n",(uint)DAT_00758cf8);
  printf("rssi_notify_interval: %d\n",(uint)DAT_00758cfa);
  printf("ap_notify_interval: %d\n",(uint)PTR_DAT_00758cfc._0_2_);
  printf("nbr expire time: %d\n",stats_nbr_expire_time);
  return;
}

