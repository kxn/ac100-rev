// func _sensor_test_sync_case_config_to_sensor @ 004f9bf0 size=1100

undefined4
_sensor_test_sync_case_config_to_sensor(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_sync_case_config_to_sensor ENTER, sensor_id=%d, case_id=%d\n"
           ,"_sensor_test_sync_case_config_to_sensor",0x7a0,param_1,param_2);
  }
  local_28 = 0;
  local_24 = 0;
  uVar1 = sensor_test_db_get_case_num_max();
  if (((int)param_2 < 0) || (uVar1 <= param_2)) {
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d invalid input\n";
    uVar8 = 0x7ab;
    goto LAB_004f9cc0;
  }
  iVar2 = sensor_test_db_get_case(param_2);
  if (iVar2 == 0) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d db_get_case fail \n",
             "_sensor_test_sync_case_config_to_sensor",0x7b2);
    }
  }
  else {
    local_28 = 0;
    local_24 = 0;
    local_30 = param_2;
    local_2c = iVar2;
    FUN_004082d0(0,0xffffffff);
    iVar3 = _sensor_test_generate_ssid_info_to_deploy
                      (&local_28,*(undefined4 *)(l_sensor_test_ssid_alloc_list + param_2 * 4),
                       param_1);
    if (iVar3 == -1) {
      if (sensor_test_warning_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_WARNING]%s()/%d _sensor_test_generate_ssid_info_to_deploy fail\n";
        uVar8 = 0x7bf;
LAB_004f9fac:
        printf(pcVar7,"_sensor_test_sync_case_config_to_sensor",uVar8);
      }
    }
    else if ((local_28 == 0) || (local_24 == 0)) {
      if (sensor_test_warning_switch != '\0') {
        printf("[SENSOR_TEST_WARNING]%s()/%d sensor_id=%d, has no ssid_info_to_deploy\n",
               "_sensor_test_sync_case_config_to_sensor",0x7c6,param_1);
      }
      pvVar4 = (void *)sensor_test_send_packet_json_generate(1,&local_30,0);
      if (pvVar4 != (void *)0x0) {
        sensor_pkt_tdcp_send(param_1,pvVar4);
        sensor_test_db_set_case_sensor_add_flag(param_2,param_1,0);
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_id=%d, pkt_json_str is:%s\n",
                 "_sensor_test_sync_case_config_to_sensor",2000,param_1,pvVar4);
        }
        free(pvVar4);
        goto LAB_004f9e84;
      }
      if (sensor_test_err_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d generate packet_json fail\n";
        uVar8 = 0x7ca;
        goto LAB_004f9fac;
      }
    }
    else {
      pvVar4 = (void *)sensor_test_send_packet_json_generate(param_3,&local_30,&local_28);
      if (pvVar4 != (void *)0x0) {
        sensor_pkt_tdcp_send(param_1,pvVar4);
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_id=%d, pkt_json_str is:%s\n",
                 "_sensor_test_sync_case_config_to_sensor",0x7df,param_1,pvVar4);
        }
        free(pvVar4);
        for (iVar3 = 0; iVar3 < local_28; iVar3 = iVar3 + 1) {
          iVar9 = 0;
          while( true ) {
            iVar5 = local_24 + iVar3 * 0x254;
            iVar6 = iVar9 * 0x18;
            if (*(int *)(iVar5 + 8) <= iVar9) break;
            iVar9 = iVar9 + 1;
            sensor_test_db_add_bssid_to_result_list(param_2,*(int *)(iVar5 + 0x250) + iVar6 + 0xc);
          }
        }
LAB_004f9e84:
        iVar3 = 0;
        FUN_00407f30(0);
        sensor_test_db_case_setting_mem_free(iVar2);
        local_2c = 0;
        if (local_24 == 0) {
          return 0;
        }
        while (iVar3 < local_28) {
          iVar2 = iVar3 * 0x254;
          iVar3 = iVar3 + 1;
          if (*(int *)(local_24 + iVar2 + 0x250) != 0) {
            FUN_00407df0();
            *(undefined4 *)(local_24 + iVar2 + 0x250) = 0;
          }
        }
        FUN_00407df0();
        return 0;
      }
      if (sensor_test_err_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d generate packet_json fail\n";
        uVar8 = 0x7da;
        goto LAB_004f9fac;
      }
    }
    FUN_00407f30(0);
    sensor_test_db_case_setting_mem_free(iVar2);
    local_2c = 0;
  }
  iVar2 = 0;
  if (local_24 != 0) {
    while (iVar2 < local_28) {
      iVar3 = iVar2 * 0x254;
      iVar2 = iVar2 + 1;
      if (*(int *)(local_24 + iVar3 + 0x250) != 0) {
        FUN_00407df0();
        *(undefined4 *)(local_24 + iVar3 + 0x250) = 0;
      }
    }
    FUN_00407df0();
    local_24 = 0;
    local_28 = 0;
  }
  if (sensor_test_warning_switch == '\0') {
    return 0xffffffff;
  }
  pcVar7 = "[SENSOR_TEST_WARNING]%s()/%d _sensor_test_sync_case_config_to_sensor fail EXIT\n";
  uVar8 = 0x822;
LAB_004f9cc0:
  printf(pcVar7,"_sensor_test_sync_case_config_to_sensor",uVar8);
  return 0xffffffff;
}

