// func ac_passthrough_time_sync_regularly @ 0050f04c size=1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ac_passthrough_time_sync_regularly(void)

{
  _time_sync_timerid = 0xffffffff;
  ac_passthrough_time_stamp_sync_to_ap_all();
  _time_sync_timerid =
       FUN_00408340(0xe10,0,ac_passthrough_time_sync_regularly,0,0,
                    "ac_passthrough_time_sync_regularly",0x8b0);
  return;
}

