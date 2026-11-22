// func _sensor_test_sensor_alloc_hash_obj @ 004f7ee4 size=92

undefined4 _sensor_test_sensor_alloc_hash_obj(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d inputs error.\n","_sensor_test_sensor_alloc_hash_obj",0x109
            );
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,2,0);
  return uVar1;
}

