// func _sensor_test_travel_bssid_alloc_hash_cb @ 004f80b4 size=60

void _sensor_test_travel_bssid_alloc_hash_cb(int param_1,short *param_2)

{
  if (((param_1 != 0) && (param_2 != (short *)0x0)) && (*(short *)(param_1 + 0x20) == *param_2)) {
    *(undefined2 *)(param_1 + 0x20) = 0;
    *(undefined1 *)(param_1 + 0x22) = 1;
    sensor_test_db_del_bssid_to_result_list(*(undefined4 *)(param_2 + 2),param_1 + 0xc);
    return;
  }
  return;
}

