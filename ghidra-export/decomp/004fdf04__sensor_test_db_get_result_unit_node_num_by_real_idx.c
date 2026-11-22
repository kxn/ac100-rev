// func _sensor_test_db_get_result_unit_node_num_by_real_idx @ 004fdf04 size=300

int _sensor_test_db_get_result_unit_node_num_by_real_idx
              (int param_1,uint param_2,undefined4 param_3,uint param_4,uint param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  
  if ((param_2 < 9) && (param_6 != 0)) {
    if (param_1 == 0) {
      if (sensor_test_err_switch == '\0') {
        return 0;
      }
      __format = "[SENSOR_TEST_ERROR]%s()/%d bssid_result_node is null\n";
      uVar3 = 0x78b;
    }
    else {
      iVar1 = _sensor_test_db_get_sepcified_list_from_bssid_result_node(param_1,param_2 & 0xff);
      if (iVar1 != 0) {
        iVar1 = FUN_004081b0(iVar1);
        iVar4 = 0;
        if (iVar1 == 0) {
          return 0;
        }
        uVar2 = *(uint *)(iVar1 + 0x2c);
        while( true ) {
          if (uVar2 < param_4) {
            if (param_5 <= uVar2) {
              return iVar4;
            }
          }
          else {
            if (param_5 <= uVar2) {
              return iVar4;
            }
            iVar4 = iVar4 + 1;
          }
          iVar1 = FUN_00408680(iVar1);
          if (iVar1 == 0) break;
          uVar2 = *(uint *)(iVar1 + 0x2c);
        }
        return iVar4;
      }
      if (sensor_test_debug_switch == '\0') {
        return 0;
      }
      __format = "[SENSOR_TEST_DEBUG]%s()/%d can not find specified config list\n";
      uVar3 = 0x792;
    }
  }
  else {
    if (sensor_test_err_switch == '\0') {
      return 0;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d input invalid\n";
    uVar3 = 0x785;
  }
  printf(__format,"_sensor_test_db_get_result_unit_node_num_by_real_idx",uVar3);
  return 0;
}

