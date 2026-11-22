// func sensor_test_db_add_case @ 00503730 size=748

undefined4 sensor_test_db_add_case(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (sensor_test_debug_switch == '\0') {
    if (param_1 != (uint *)0x0) {
      uVar1 = param_1[1];
LAB_00503778:
      if ((uVar1 != 0) && (param_2 != (undefined4 *)0x0)) {
        FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
        if (l_sensor_test_case_id_allocator == 0) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d l_sensor_test_case_id_allocator is null!\n",
                   "sensor_test_db_add_case",0x10be);
          }
LAB_0050392c:
          FUN_00407f30(l_sensor_test_db_mutex);
          return 0xffffffff;
        }
        uVar1 = FUN_004085b0();
        if (((int)uVar1 < 0) || (g_sensor_test_case_num_max <= uVar1)) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d ALLOC test_case_id=%d\n","sensor_test_db_add_case",
                   0x10c6,uVar1);
          }
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d uac_id_alloc id fail\n","sensor_test_db_add_case",
                   0x10c7);
          }
          FUN_00407f30(l_sensor_test_db_mutex);
          *param_2 = 0xfffffffe;
          return 0xffffffff;
        }
        *param_1 = uVar1;
        iVar5 = uVar1 * 4;
        *(undefined1 *)(param_1[1] + 8) = 0;
        iVar2 = _sensor_test_db_deep_copy_test_case(param_1);
        uVar3 = l_sensor_test_db_mutex;
        if (iVar2 == 0) {
          *(undefined4 *)(l_sensor_test_case_list + iVar5) = 0;
          FUN_00407f30(uVar3);
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d deep_copy_case fail\n","sensor_test_db_add_case",
                   0x10d5);
          }
          FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
          if (*(int *)(l_sensor_test_case_list + iVar5) != 0) {
            if (*(int *)(*(int *)(l_sensor_test_case_list + iVar5) + 4) != 0) {
              sensor_test_db_case_setting_mem_free();
              *(undefined4 *)(*(int *)(l_sensor_test_case_list + iVar5) + 4) = 0;
            }
            FUN_00407df0(*(undefined4 *)(l_sensor_test_case_list + iVar5));
            *(undefined4 *)(l_sensor_test_case_list + iVar5) = 0;
          }
          if (uVar1 < g_sensor_test_case_num_max) {
            FUN_004080f0(l_sensor_test_case_id_allocator,uVar1);
          }
          goto LAB_0050392c;
        }
        uVar4 = 0;
        *(int *)(l_sensor_test_case_list + iVar5) = iVar2;
        FUN_00407f30(uVar3);
        if (sensor_test_debug_switch == '\0') {
          return 0;
        }
        __format = "[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_add_case success EXIT\n";
        uVar3 = 0x10dc;
        goto LAB_0050388c;
      }
    }
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_add_case ENTER\n","sensor_test_db_add_case",
           0x10ad);
    if (param_1 != (uint *)0x0) {
      uVar1 = param_1[1];
      goto LAB_00503778;
    }
  }
  uVar4 = 0xffffffff;
  if (sensor_test_err_switch == '\0') {
    return 0xffffffff;
  }
  __format = "[SENSOR_TEST_ERROR]%s()/%d new_case_ptr or setting is null\n";
  uVar3 = 0x10b4;
LAB_0050388c:
  printf(__format,"sensor_test_db_add_case",uVar3);
  return uVar4;
}

