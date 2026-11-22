// func jcs_sensor_test_del_test_case @ 004fbf8c size=800

void jcs_sensor_test_del_test_case(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 local_28 [2];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_del_test_case ENTER\n",
           "jcs_sensor_test_del_test_case",0x1b4f);
  }
  local_28[0] = 0;
  uVar1 = sensor_test_db_get_case_num_max();
  iVar2 = json_object_object_get(param_1,"test_case_id");
  if (iVar2 == 0) {
LAB_004fc010:
    uVar6 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_sensor_test_del_test_case",6999);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar6 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_004fc010;
      uVar7 = json_object_get_double(iVar2);
      uVar6 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d case id to del is=%d\n","jcs_sensor_test_del_test_case",7000,
           uVar6);
  }
  iVar2 = sensor_test_db_get_case(uVar6);
  if (iVar2 == 0) {
    if (sensor_test_err_switch != '\0') {
      pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d db_get_case fail\n";
      uVar4 = 0x1b5e;
LAB_004fc1bc:
      printf(pcVar5,"jcs_sensor_test_del_test_case",uVar4);
    }
  }
  else {
    iVar3 = sensor_test_db_del_case(uVar6,0);
    if (iVar3 == -1) {
      if (sensor_test_err_switch != '\0') {
        pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d db_del_case fail\n";
        uVar4 = 0x1b65;
        goto LAB_004fc1bc;
      }
    }
    else {
      FUN_004082d0(0,0xffffffff);
      if (((-1 < (int)uVar6) && (uVar6 < uVar1)) &&
         (*(int *)(l_sensor_test_ssid_alloc_list + uVar6 * 4) != 0)) {
        _sensor_test_ssid_alloc_list_mem_free();
        *(undefined4 *)(l_sensor_test_ssid_alloc_list + uVar6 * 4) = 0;
        sensor_test_sql_del_bssid_alloc_table(uVar6);
      }
      FUN_00407f30(0);
      iVar3 = sensor_test_deployment_case(1,uVar6,iVar2,local_28);
      if (iVar3 != -1) {
        sensor_test_db_case_setting_mem_free(iVar2);
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d jcs del test case success EXIT\n",
                 "jcs_sensor_test_del_test_case",0x1b80);
        }
        uVar4 = json_object_new_int(0);
        pcVar5 = "ret";
        goto LAB_004fc14c;
      }
      if (sensor_test_err_switch != '\0') {
        pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d del case fail at deploy stage\n";
        uVar4 = 0x1b76;
        goto LAB_004fc1bc;
      }
    }
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs del test case fail EXIT\n",
           "jcs_sensor_test_del_test_case",0x1b85);
  }
  if (iVar2 != 0) {
    sensor_test_db_case_setting_mem_free(iVar2);
  }
  uVar4 = json_object_new_int(1);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  uVar4 = json_object_new_int(local_28[0]);
  pcVar5 = "err_code";
LAB_004fc14c:
  json_object_object_add(param_2,pcVar5,uVar4);
  return;
}

