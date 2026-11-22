// func wserv_db_sync_wlan_to_re @ 005efe90 size=48

undefined4 wserv_db_sync_wlan_to_re(undefined2 *param_1)

{
  mesh_db_ap_entry_child_foreach_proc(*param_1,0,_wserv_db_ap_sync,param_1);
  return 0;
}

