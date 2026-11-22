// func _sensor_test_ap_exists_cb @ 004f5dd8 size=116

undefined4 _sensor_test_ap_exists_cb(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 2;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d Input error\n","_sensor_test_ap_exists_cb",0x236);
    }
  }
  else {
    uVar1 = 0;
    if (*(short *)(param_1 + 0x10) == *(short *)(param_2 + 1)) {
      uVar1 = 2;
      *param_2 = 1;
    }
  }
  return uVar1;
}

