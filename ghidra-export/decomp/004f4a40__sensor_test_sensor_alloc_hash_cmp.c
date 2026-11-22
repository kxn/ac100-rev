// func _sensor_test_sensor_alloc_hash_cmp @ 004f4a40 size=108

bool _sensor_test_sensor_alloc_hash_cmp(short *param_1,short *param_2)

{
  bool bVar1;
  
  if ((param_1 == (short *)0x0) || (param_2 == (short *)0x0)) {
    bVar1 = false;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d inputs error.\n","_sensor_test_sensor_alloc_hash_cmp",0x117
            );
    }
  }
  else {
    bVar1 = *param_2 == *param_1;
  }
  return bVar1;
}

