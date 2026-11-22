// func _sensor_test_db_get_config_cnt @ 004fdde0 size=292

undefined4 _sensor_test_db_get_config_cnt(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 9) {
    uVar2 = 0;
    if (param_1 != 0) {
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 == 0) {
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d setting is null\n","_sensor_test_db_get_config_cnt",
                 0x61a);
        }
        uVar2 = 0;
        FUN_00407f30(l_sensor_test_db_mutex);
      }
      else if (((int)(uint)*(ushort *)(iVar1 + 0x3c) >> (param_2 & 0x1f) & 1U) != 0) {
        if (param_2 == 4) {
          uVar2 = **(undefined4 **)(iVar1 + 0x4c);
        }
        else if ((int)param_2 < 5) {
          if (param_2 == 2) {
            uVar2 = **(undefined4 **)(iVar1 + 0x44);
          }
          else {
            uVar2 = 1;
          }
        }
        else if (param_2 == 5) {
          uVar2 = **(undefined4 **)(iVar1 + 0x50);
        }
        else if (param_2 == 6) {
          uVar2 = **(undefined4 **)(iVar1 + 0x54);
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  else {
    uVar2 = 0;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d input test_type invalid\n","_sensor_test_db_get_config_cnt"
             ,0x609);
    }
  }
  return uVar2;
}

