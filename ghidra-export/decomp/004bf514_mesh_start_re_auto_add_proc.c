// func mesh_start_re_auto_add_proc @ 004bf514 size=236

undefined4 mesh_start_re_auto_add_proc(void)

{
  undefined4 uVar1;
  
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d mesh_start_re_auto_add_proc ENTER\n","mesh_start_re_auto_add_proc",
           0x80a);
  }
  mesh_db_re_auto_add_state_set(1);
  if (g_mesh_re_auto_add_wait_timer != -1) {
    FUN_00408060();
    g_mesh_re_auto_add_wait_timer = -1;
  }
  uVar1 = 0;
  g_mesh_re_auto_add_wait_timer =
       FUN_00408340(0x3c,0,mesh_re_auto_add_wait_time_out,0,0,"mesh_start_re_auto_add_proc",0x813);
  if ((g_mesh_re_auto_add_wait_timer == -1) && (uVar1 = 0xffffffff, mesh_err_switch != '\0')) {
    printf("[MESH_ERROR]%s()/%d start discover timer failed\n","mesh_start_re_auto_add_proc",0x816);
  }
  return uVar1;
}

