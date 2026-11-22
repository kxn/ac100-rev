// func _mesh_sync_rf_entry_to_re_handle @ 004bf174 size=48

undefined4 _mesh_sync_rf_entry_to_re_handle(undefined2 param_1)

{
  mesh_db_ap_entry_child_foreach_proc(param_1,0,_mesh_sync_rf_entry_to_re_cb,0);
  return 0;
}

