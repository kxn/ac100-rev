// func _wsta_roam_ap_disconnect_cb @ 00480658 size=48

undefined4 _wsta_roam_ap_disconnect_cb(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    wsta_roam_db_ap_stats_clear(*(undefined2 *)(param_1 + 0x10));
  }
  return 0;
}

