// func mesh_stop_discover_time @ 004bd8f4 size=320

void mesh_stop_discover_time(void)

{
  g_mesh_discover_timer = 0xffffffff;
  mesh_db_discover_state_set(2);
  mesh_db_discover_list_idle_state_refresh_by_timeout();
  g_mesh_pair_timer =
       FUN_00408340(0x1e,0,mesh_clear_pairing_discover_list,0,0,"mesh_stop_discover_time",0x208);
  if (g_mesh_pair_timer == -1) {
    mesh_db_discover_list_pair_state_refresh_by_timeout();
  }
  g_mesh_discover_clear_timer =
       FUN_00408340(300,0,mesh_clear_discover_list,0,0,"mesh_stop_discover_time",0x20d);
  if (g_mesh_discover_clear_timer == -1) {
    if (g_mesh_pair_timer != -1) {
      FUN_00408060();
      g_mesh_pair_timer = -1;
    }
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d start clear discover list timer failed\n",
             "mesh_stop_discover_time",0x215);
    }
    mesh_db_discover_state_set(0);
    mesh_db_discover_list_clear();
  }
  mesh_db_re_auto_add_state_set(0);
  return;
}

