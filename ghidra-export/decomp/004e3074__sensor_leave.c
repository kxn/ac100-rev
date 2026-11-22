// func _sensor_leave @ 004e3074 size=88

undefined4 _sensor_leave(int param_1)

{
  if (*(int *)(param_1 + 0x14) == 7) {
    sensor_db_update_scan_bssid_info(*(undefined2 *)(param_1 + 0x10),0,0);
    sensor_db_update_vap_info(*(undefined2 *)(param_1 + 0x10),0,0);
  }
  return 0;
}

