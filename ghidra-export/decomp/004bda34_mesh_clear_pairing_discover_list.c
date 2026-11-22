// func mesh_clear_pairing_discover_list @ 004bda34 size=16

void mesh_clear_pairing_discover_list(void)

{
  g_mesh_pair_timer = 0xffffffff;
  mesh_db_discover_list_pair_state_refresh_by_timeout();
  return;
}

