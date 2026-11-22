// func rdmngr_thread_callback @ 00613f8c size=92

void rdmngr_thread_callback(void)

{
  uint uVar1;
  
  do {
    do {
      sleep(rdmngr_channel_collect_interval);
      uVar1 = rdmngr_channel_collect_interval << 1;
      rdmngr_channel_collect_interval = rdmngr_channel_collect_interval_max;
      if (uVar1 <= rdmngr_channel_collect_interval_max) {
        rdmngr_channel_collect_interval = uVar1;
      }
    } while (rdmngr_channel_collect_switch == 0);
    rdmngr_working_channel_set_collect();
  } while( true );
}

