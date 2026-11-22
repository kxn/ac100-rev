// func sensor_test_db_del_bssid_to_result_list @ 00504c24 size=332

undefined4 sensor_test_db_del_bssid_to_result_list(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  
  if ((((int)param_1 < 0) || (g_sensor_test_case_num_max <= param_1)) || (param_2 == 0)) {
    uVar5 = 0xffffffff;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d invalid input\n","sensor_test_db_del_bssid_to_result_list",
             0x1306);
    }
  }
  else {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    for (iVar1 = FUN_004081b0(l_sensor_test_result_list + param_1 * 0xc); iVar1 != 0;
        iVar1 = FUN_00408680(iVar1)) {
      iVar2 = 0;
      do {
        iVar4 = iVar1 + iVar2;
        pcVar3 = (char *)(param_2 + iVar2);
        iVar2 = iVar2 + 1;
        if (*(char *)(iVar4 + 0x3e) != *pcVar3) goto LAB_00504d2c;
      } while (iVar2 != 6);
      FUN_00408500(iVar1);
      FUN_00407f40(*(undefined4 *)(l_sensor_test_result_list_hash + param_1 * 4),iVar1);
      sensor_test_db_bssid_result_node_mem_free(iVar1);
LAB_00504d2c:
    }
    FUN_00407f30(l_sensor_test_db_mutex);
    uVar5 = 0;
  }
  return uVar5;
}

