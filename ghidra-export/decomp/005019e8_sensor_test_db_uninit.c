// func sensor_test_db_uninit @ 005019e8 size=356

undefined4 sensor_test_db_uninit(void)

{
  uint uVar1;
  int iVar2;
  
  sensor_test_sqlite_uninit();
  if (l_sensor_test_case_id_allocator != 0) {
    FUN_00408160();
  }
  l_sensor_test_case_id_allocator = 0;
  if (l_sensor_test_db_mutex != 0) {
    FUN_00408360();
    l_sensor_test_db_mutex = 0;
  }
  uVar1 = 0;
  if (l_sensor_test_case_list != 0) {
    while (uVar1 < g_sensor_test_case_num_max) {
      iVar2 = uVar1 * 4;
      if (*(int *)(l_sensor_test_case_list + iVar2) == 0) {
        uVar1 = uVar1 + 1;
      }
      else {
        sensor_test_db_case_setting_mem_free
                  (*(undefined4 *)(*(int *)(l_sensor_test_case_list + iVar2) + 4));
        FUN_00407df0(*(undefined4 *)(l_sensor_test_case_list + iVar2));
        *(undefined4 *)(l_sensor_test_case_list + iVar2) = 0;
        uVar1 = uVar1 + 1;
      }
    }
    FUN_00407df0(l_sensor_test_case_list);
    l_sensor_test_case_list = 0;
  }
  if (l_sensor_test_result_list != 0) {
    FUN_00407df0();
    l_sensor_test_result_list = 0;
  }
  uVar1 = 0;
  if (l_sensor_test_result_list_hash != 0) {
    while (uVar1 < g_sensor_test_case_num_max) {
      iVar2 = uVar1 * 4;
      uVar1 = uVar1 + 1;
      if (*(int *)(l_sensor_test_result_list_hash + iVar2) != 0) {
        FUN_00408310();
        *(undefined4 *)(l_sensor_test_result_list_hash + iVar2) = 0;
      }
    }
  }
  return 0;
}

