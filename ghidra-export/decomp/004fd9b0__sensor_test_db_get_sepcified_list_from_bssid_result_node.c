// func _sensor_test_db_get_sepcified_list_from_bssid_result_node @ 004fd9b0 size=396

int _sensor_test_db_get_sepcified_list_from_bssid_result_node(int param_1,uint param_2,uint param_3)

{
  char *__format;
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if (sensor_test_err_switch == '\0') {
      return 0;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d bssid_result_node is null\n";
    uVar1 = 0x6d9;
    goto LAB_004fda58;
  }
  if (8 < param_2) {
    if (sensor_test_err_switch == '\0') {
      return 0;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d input invalid\n";
    uVar1 = 0x6df;
    goto LAB_004fda58;
  }
  iVar2 = param_1 + 0x48;
  switch(param_2 - 1 & 0xff) {
  case 0:
    iVar2 = param_1 + 0x54;
    break;
  case 1:
    if (param_3 < *(byte *)(param_1 + 0x95)) {
      return *(int *)(param_1 + 0x84) + param_3 * 0xc;
    }
    goto LAB_004fda94;
  case 2:
    iVar2 = param_1 + 0x60;
    break;
  case 3:
    if (param_3 < *(byte *)(param_1 + 0x96)) {
      return *(int *)(param_1 + 0x88) + param_3 * 0xc;
    }
    goto LAB_004fda94;
  case 4:
    if (param_3 < *(byte *)(param_1 + 0x97)) {
      return *(int *)(param_1 + 0x8c) + param_3 * 0xc;
    }
    goto LAB_004fda94;
  case 5:
    if (param_3 < *(byte *)(param_1 + 0x98)) {
      return *(int *)(param_1 + 0x90) + param_3 * 0xc;
    }
LAB_004fda94:
    iVar2 = 0;
    if (sensor_test_debug_switch != '\0') {
      __format = 
      "[SENSOR_TEST_DEBUG]%s()/%d didn\'t find config list by specified test_type and idx \n";
      uVar1 = 0x71d;
LAB_004fda58:
      iVar2 = 0;
      printf(__format,"_sensor_test_db_get_sepcified_list_from_bssid_result_node",uVar1);
    }
    break;
  case 6:
    iVar2 = param_1 + 0x6c;
    break;
  case 7:
    iVar2 = param_1 + 0x78;
  }
  return iVar2;
}

