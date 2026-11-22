// func _sensor_test_bssid_alloc_hash_key @ 004f7f40 size=92

undefined4 _sensor_test_bssid_alloc_hash_key(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d inputs error.\n","_sensor_test_bssid_alloc_hash_key",0x12a)
      ;
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,6,0);
  return uVar1;
}

