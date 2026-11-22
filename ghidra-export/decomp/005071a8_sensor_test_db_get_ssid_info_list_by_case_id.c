// func sensor_test_db_get_ssid_info_list_by_case_id @ 005071a8 size=488

void * sensor_test_db_get_ssid_info_list_by_case_id(uint param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  char *__format;
  uint uVar4;
  undefined4 uVar5;
  void *__dest;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_ssid_info_list_by_case_id ENTER\n",
           "sensor_test_db_get_ssid_info_list_by_case_id",0x16af);
  }
  __dest = (void *)0x0;
  if (((param_2 != (uint *)0x0) && (-1 < (int)param_1)) && (param_1 < g_sensor_test_case_num_max)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    uVar2 = 0;
    piVar1 = l_sensor_test_case_list;
    if (g_sensor_test_case_num_max != 0) {
      do {
        puVar3 = (uint *)*piVar1;
        if (((puVar3 != (uint *)0x0) && (puVar3[1] != 0)) && (param_1 == *puVar3)) {
          *param_2 = (uint)*(byte *)(puVar3[1] + 0xb);
          uVar4 = (uint)*(byte *)(*(int *)(*piVar1 + 4) + 0xb);
          __dest = (void *)0x0;
          if ((uVar4 == 0) || (*(int *)(*(int *)(*piVar1 + 4) + 0x38) == 0)) goto LAB_00507258;
          __dest = (void *)FUN_00408450(uVar4 * 0x220,0x16c1);
          if (__dest != (void *)0x0) {
            memcpy(__dest,*(void **)(*(int *)(l_sensor_test_case_list[uVar2] + 4) + 0x38),
                   (uint)*(byte *)(*(int *)(l_sensor_test_case_list[uVar2] + 4) + 0xb) * 0x220);
            goto LAB_00507258;
          }
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",
                   "sensor_test_db_get_ssid_info_list_by_case_id",0x16c4);
          }
          FUN_00407f30(l_sensor_test_db_mutex);
          if (sensor_test_err_switch == '\0') {
            return (void *)0x0;
          }
          __format = "[SENSOR_TEST_ERROR]%s()/%d get_ssid_info_list fail\n";
          uVar5 = 0x16d3;
          goto LAB_00507280;
        }
        uVar2 = uVar2 + 1;
        piVar1 = piVar1 + 1;
      } while (uVar2 != g_sensor_test_case_num_max);
    }
    __dest = (void *)0x0;
LAB_00507258:
    FUN_00407f30(l_sensor_test_db_mutex);
    if (sensor_test_debug_switch != '\0') {
      __format = 
      "[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_ssid_info_list_by_case_id success exit\n";
      uVar5 = 0x16cf;
LAB_00507280:
      printf(__format,"sensor_test_db_get_ssid_info_list_by_case_id",uVar5);
    }
  }
  return __dest;
}

