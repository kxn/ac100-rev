// func ac_passthrough_systime_callback @ 0050f044 size=8

void ac_passthrough_systime_callback(void)

{
  ac_passthrough_time_stamp_sync_to_ap_all();
  return;
}

