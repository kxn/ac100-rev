// func _sensor_test_db_hash_obj @ 004fe8fc size=96

undefined4 _sensor_test_db_hash_obj(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d inputs error.\n","_sensor_test_db_hash_obj",0xc5d);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1 + 0x3e,6,0);
  return uVar1;
}

