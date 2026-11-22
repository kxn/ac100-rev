// func mesh_pkt_tmp_re_roam_timer_start @ 004c115c size=168

void mesh_pkt_tmp_re_roam_timer_start(undefined2 param_1)

{
  int iVar1;
  undefined4 local_10;
  int local_c;
  
  local_c = 0;
  iVar1 = mesh_db_re_auto_switch_get(&local_c);
  if (iVar1 == 0) {
    if (local_c == 0) {
      local_10 = 1;
      mesh_db_ap_entry_child_foreach_proc(param_1,1,_mesh_tmp_re_roam_pkt_send,&local_10);
      mesh_db_ap_entry_tmp_re_roam_timer_op(param_1,1,_mesh_tmp_re_roam_timer_timeout,0);
    }
  }
  else if (mesh_err_switch != '\0') {
    printf("[MESH_ERROR]%s()/%d Failed to join for formal callback return failed result code.\n",
           "mesh_pkt_tmp_re_roam_timer_start",0x321);
  }
  return;
}

