// func apmngr_db_fini @ 00541d0c size=224

void apmngr_db_fini(void)

{
  if (g_apmngr_ap_id_allocator != 0) {
    FUN_00408160();
    g_apmngr_ap_id_allocator = 0;
  }
  if (g_apmngr_template_id_allocator != 0) {
    FUN_00408160();
    g_apmngr_template_id_allocator = 0;
  }
  if (g_apmngr_entry_array != 0) {
    FUN_00407df0();
    g_apmngr_entry_array = 0;
  }
  if (apmngr_db_mutex != 0) {
    FUN_00408360();
    apmngr_db_mutex = 0;
  }
  if (g_apmngr_group_array != 0) {
    FUN_00407df0();
    g_apmngr_group_array = 0;
  }
  if (g_apmngr_ap_hash != 0) {
    FUN_00408310();
    g_apmngr_ap_hash = 0;
  }
  if (g_apmngr_template_hash != 0) {
    FUN_00408310();
    g_apmngr_template_hash = 0;
  }
  return;
}

