// func _sensor_test_db_get_result_unit_node_num_by_serindex @ 004fe030 size=348

int _sensor_test_db_get_result_unit_node_num_by_serindex
              (int param_1,uint param_2,undefined4 param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  
  if ((param_2 < 9) && (param_6 != 0)) {
    if (param_1 == 0) {
      if (sensor_test_err_switch == '\0') {
        return 0;
      }
      __format = "[SENSOR_TEST_ERROR]%s()/%d bssid_result_node is null\n";
      uVar3 = 0x747;
    }
    else {
      iVar4 = 0;
      uVar1 = _sensor_test_db_get_idx_of_serindex();
      if (uVar1 == 0xffffffff) {
        return 0;
      }
      iVar2 = _sensor_test_db_get_sepcified_list_from_bssid_result_node
                        (param_1,param_2 & 0xff,uVar1 & 0xffff);
      if (iVar2 != 0) {
        iVar2 = FUN_004081b0(iVar2);
        do {
          if (iVar2 == 0) {
            return iVar4;
          }
          uVar1 = *(uint *)(iVar2 + 0x2c);
          if (uVar1 < param_4) {
            if (param_5 <= uVar1) {
              return iVar4;
            }
          }
          else {
            if (param_5 <= uVar1) {
              return iVar4;
            }
            iVar4 = iVar4 + 1;
          }
          iVar2 = FUN_00408680(iVar2);
        } while( true );
      }
      if (sensor_test_debug_switch == '\0') {
        return 0;
      }
      __format = "[SENSOR_TEST_DEBUG]%s()/%d can not find specified config list\n";
      uVar3 = 0x754;
    }
  }
  else {
    if (sensor_test_err_switch == '\0') {
      return 0;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d input invalid\n";
    uVar3 = 0x741;
  }
  printf(__format,"_sensor_test_db_get_result_unit_node_num_by_serindex",uVar3);
  return 0;
}

