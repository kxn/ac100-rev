// func apmngr_id_datasync_timeout @ 0052a4dc size=40

void apmngr_id_datasync_timeout(void)

{
  apmngr_db_datasync_id_allocator_get();
  g_apmngr_id_datasync_timer = 0xffffffff;
  return;
}

