// func mesh_clear_discover_list @ 004bd8cc size=40

void mesh_clear_discover_list(void)

{
  g_mesh_discover_clear_timer = 0xffffffff;
  mesh_db_discover_state_set(0);
  mesh_db_discover_list_clear();
  return;
}

