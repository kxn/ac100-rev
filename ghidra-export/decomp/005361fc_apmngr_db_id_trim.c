// func apmngr_db_id_trim @ 005361fc size=84

void apmngr_db_id_trim(void)

{
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  FUN_004083b0(g_apmngr_ap_id_allocator);
  FUN_004083b0(g_apmngr_sensor_id_allocator);
  FUN_004083b0(g_apmngr_template_id_allocator);
  FUN_00407f30(apmngr_db_mutex);
  return;
}

