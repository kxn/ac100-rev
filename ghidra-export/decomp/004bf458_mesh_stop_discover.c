// func mesh_stop_discover @ 004bf458 size=188

undefined4 mesh_stop_discover(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18 [3];
  
  local_18[0] = 0;
  iVar1 = mesh_db_discover_state_get();
  uVar2 = 0;
  if (iVar1 != 0) {
    if (g_mesh_discover_timer != -1) {
      FUN_00408060();
      g_mesh_discover_timer = -1;
    }
    if (g_mesh_pair_timer != -1) {
      FUN_00408060();
      g_mesh_pair_timer = -1;
    }
    if (g_mesh_discover_clear_timer != -1) {
      FUN_00408060();
      g_mesh_discover_clear_timer = -1;
    }
    mesh_db_discover_state_set(0);
    mesh_db_discover_list_clear();
    iVar1 = mesh_pkt_discover_request_send(0,local_18);
    uVar2 = 0xffffffff;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

