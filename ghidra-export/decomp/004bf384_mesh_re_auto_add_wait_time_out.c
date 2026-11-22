// func mesh_re_auto_add_wait_time_out @ 004bf384 size=212

void mesh_re_auto_add_wait_time_out(void)

{
  int iVar1;
  int local_10 [2];
  
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d mesh_re_auto_add_wait_time_out ENTER\n",
           "mesh_re_auto_add_wait_time_out",0x21e);
  }
  local_10[0] = 0;
  iVar1 = mesh_db_re_auto_add_state_get(local_10);
  if (iVar1 == -1) {
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d get re_auto_add_state fail\n","mesh_re_auto_add_wait_time_out",
             0x223);
    }
  }
  else if (local_10[0] == 1) {
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d re_auto_add_state=%d, begin auto_discover proc.\n",
             "mesh_re_auto_add_wait_time_out",0x22a,1);
    }
    mesh_start_discover();
  }
  return;
}

