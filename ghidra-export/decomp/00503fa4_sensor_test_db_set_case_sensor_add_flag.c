// func sensor_test_db_set_case_sensor_add_flag @ 00503fa4 size=284

undefined4 sensor_test_db_set_case_sensor_add_flag(uint param_1,short param_2,undefined1 param_3)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (((int)param_1 < 0) || (g_sensor_test_case_num_max <= param_1)) {
    uVar4 = 0xffffffff;
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d input invalid\n","sensor_test_db_set_case_sensor_add_flag",
             0x119c);
    }
  }
  else {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    if ((((l_sensor_test_case_list != 0) &&
         (iVar1 = *(int *)(l_sensor_test_case_list + param_1 * 4), iVar1 != 0)) &&
        (iVar1 = *(int *)(iVar1 + 4), iVar1 != 0)) && (*(byte *)(iVar1 + 10) != 0)) {
      iVar3 = 0;
      psVar2 = *(short **)(iVar1 + 0x34);
      if (*(short **)(iVar1 + 0x34) != (short *)0x0) {
        for (; iVar3 < (int)(uint)*(byte *)(iVar1 + 10); iVar3 = iVar3 + 1) {
          if (*psVar2 == param_2) {
            *(undefined1 *)(psVar2 + 1) = param_3;
            break;
          }
          psVar2 = psVar2 + 2;
        }
      }
    }
    uVar4 = 0;
    FUN_00407f30(l_sensor_test_db_mutex);
  }
  return uVar4;
}

