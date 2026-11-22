// func wips_uninit @ 004caaf0 size=136

void wips_uninit(void)

{
  if (g_wips_id_allocator != 0) {
    FUN_00408160();
    g_wips_id_allocator = 0;
  }
  if (g_whitelist_id_allocator != 0) {
    FUN_00408160();
    g_whitelist_id_allocator = 0;
  }
  if (g_counter_info_hash != 0) {
    FUN_00408310();
    g_counter_info_hash = 0;
  }
  if (wips_global_mutex == 0) {
    return;
  }
  FUN_00408360();
  return;
}

