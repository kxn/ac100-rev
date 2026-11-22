// func sensor_test_db_get_summary_result @ 00506c78 size=436

undefined4
sensor_test_db_get_summary_result
          (uint param_1,uint param_2,short param_3,undefined4 param_4,undefined4 param_5,
          undefined4 *param_6,undefined2 *param_7)

{
  bool bVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  
  if ((((param_6 == (undefined4 *)0x0) || (param_7 == (undefined2 *)0x0)) || ((int)param_1 < 0)) ||
     (g_sensor_test_case_num_max <= param_1)) {
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d input invalid\n";
    uVar3 = 0x14af;
  }
  else {
    iVar2 = sensor_test_db_is_test_case_id_legal();
    if (iVar2 != 0) {
      if (param_2 == 0xffffffff) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
        if (8 < param_2) {
          if (sensor_test_debug_switch == '\0') {
            return 0xffffffff;
          }
          __format = "[SENSOR_TEST_DEBUG]%s()/%d input test_type invalid\n";
          uVar3 = 0x14c4;
          goto LAB_00506d2c;
        }
      }
      *param_6 = 0xffffffff;
      *param_7 = 0;
      param_7[1] = 0;
      param_7[2] = 0;
      if (bVar1) {
        iVar2 = 0;
        do {
          iVar4 = iVar2 + 1;
          _sensor_test_db_get_summary_result
                    (param_1,iVar2,0xffffffff,param_4,param_5,param_6,param_7);
          iVar2 = iVar4;
        } while (iVar4 != 9);
        return 0;
      }
      _sensor_test_db_get_summary_result
                (param_1,param_2,(int)param_3,param_4,param_5,param_6,param_7);
      return 0;
    }
    if (sensor_test_debug_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_TEST_DEBUG]%s()/%d input case_id invalid\n";
    uVar3 = 0x14b6;
  }
LAB_00506d2c:
  printf(__format,"sensor_test_db_get_summary_result",uVar3);
  return 0xffffffff;
}

