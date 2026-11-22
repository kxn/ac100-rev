// func handle_global_mesh_switch @ 004c46d8 size=104

undefined4 handle_global_mesh_switch(int param_1)

{
  int local_res0 [4];
  
  local_res0[0] = param_1;
  if (param_1 == 0) {
    apmngr_db_foreach_proc(0xe0000,mesh_switch_set,local_res0);
    mesh_pkt_enable_request_send_to_all(0);
  }
  else {
    apmngr_db_foreach_proc(0xe0000,mesh_switch_set,local_res0);
    apmngr_db_foreach_proc(0xe0000,mesh_switch_send,0);
  }
  return 0;
}

