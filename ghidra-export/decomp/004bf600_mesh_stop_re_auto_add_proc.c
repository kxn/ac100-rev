// func mesh_stop_re_auto_add_proc @ 004bf600 size=124

undefined4 mesh_stop_re_auto_add_proc(void)

{
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d mesh_stop_re_auto_add_proc ENTER\n","mesh_stop_re_auto_add_proc",
           0x81e);
  }
  if (g_mesh_re_auto_add_wait_timer != -1) {
    FUN_00408060();
    g_mesh_re_auto_add_wait_timer = -1;
  }
  mesh_db_re_auto_add_state_set(0);
  return 0;
}

