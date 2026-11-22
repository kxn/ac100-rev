// func sensor_test_db_get_case_sch_period @ 00507390 size=248

undefined4 sensor_test_db_get_case_sch_period(uint param_1,short *param_2)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  
  if (((param_1 < g_sensor_test_case_num_max) && (-1 < (int)param_1)) && (param_2 != (short *)0x0))
  {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    iVar1 = *(int *)(l_sensor_test_case_list + param_1 * 4);
    if (iVar1 == 0) {
      uVar3 = 0xffffffff;
      FUN_00407f30(l_sensor_test_db_mutex);
    }
    else {
      psVar2 = *(short **)(iVar1 + 4);
      if (*psVar2 == 1) {
        *param_2 = 0;
      }
      else {
        *param_2 = psVar2[1];
      }
      uVar3 = 0;
      FUN_00407f30(l_sensor_test_db_mutex);
    }
  }
  else {
    uVar3 = 0xffffffff;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d invalid input\n","sensor_test_db_get_case_sch_period",
             0x16db);
    }
  }
  return uVar3;
}

