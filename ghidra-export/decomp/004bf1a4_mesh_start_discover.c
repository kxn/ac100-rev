// func mesh_start_discover @ 004bf1a4 size=320

undefined4 mesh_start_discover(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [3];
  
  local_18[0] = 0;
  iVar1 = mesh_db_discover_state_get();
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
  }
  uVar2 = 0xffffffff;
  iVar1 = mesh_pkt_discover_request_send_with_check(1,local_18);
  if ((iVar1 == 0) && (uVar2 = 0xfffffffe, local_18[0] != 0)) {
    g_mesh_discover_timer =
         FUN_00408340(0x78,0,mesh_stop_discover_time,0,0,"mesh_start_discover",0x7e0);
    if (g_mesh_discover_timer == -1) {
      uVar2 = 0xffffffff;
      if (mesh_err_switch != '\0') {
        printf("[MESH_ERROR]%s()/%d start discover timer failed\n","mesh_start_discover",0x7e3);
      }
    }
    else {
      uVar2 = 0;
      mesh_db_discover_state_set(1);
    }
  }
  return uVar2;
}

