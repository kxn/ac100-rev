// func st_set_result_param_dump @ 00508728 size=1

void st_set_result_param_dump
               (uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
               undefined1 param_6)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  uStack_28 = 0;
  uStack_24 = 0;
  if (((((int)param_1 < 0) || (g_sensor_test_case_num_max <= param_1)) || (param_3 == 0)) ||
     (((int)param_2 < 0 || (8 < (int)param_2)))) {
    printf("input case_id invalid");
    return;
  }
  _str2mac(param_3,&uStack_28);
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(*(undefined4 *)(l_sensor_test_result_list_hash + param_1 * 4),&uStack_28);
  if (iVar1 == 0) {
    if (sensor_test_err_switch == '\0') goto code_r0x0050886c;
    __format = "[SENSOR_TEST_ERROR]%s()/%d hash get bssid_result_node fail\n";
    uVar2 = 0x18be;
  }
  else {
    iVar1 = _sensor_test_db_get_sepcified_list_from_bssid_result_node(iVar1,param_2 & 0xff,0);
    if (iVar1 != 0) {
      for (iVar1 = FUN_004081b0(iVar1); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        *(undefined4 *)(iVar1 + 0x10) = param_5;
        *(undefined1 *)(iVar1 + 0x24) = param_6;
        *(undefined4 *)(iVar1 + 0xc) = param_4;
      }
      goto code_r0x0050886c;
    }
    if (sensor_test_err_switch == '\0') goto code_r0x0050886c;
    __format = "[SENSOR_TEST_ERROR]%s()/%d get result_config_list fail\n";
    uVar2 = 0x18c5;
  }
  printf(__format,"st_set_result_param_dump",uVar2);
code_r0x0050886c:
  FUN_00407f30(l_sensor_test_db_mutex);
  return;
}

