// func _mesh_cb_child_disconnect @ 004bd6d0 size=40

undefined4 _mesh_cb_child_disconnect(int param_1)

{
  apmngr_ap_disconnect(param_1 + 0xc,1,1);
  return 0;
}

