// func sensor_test_init @ 004f8c08 size=1428

/* WARNING: Type propagation algorithm not settling */

undefined4 sensor_test_init(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  uint *puVar7;
  int local_858 [4];
  char *local_848;
  undefined4 local_844;
  code *local_840;
  char *local_83c;
  undefined4 local_838;
  code *local_830;
  code *local_828;
  uint local_7fc [502];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_init ENTER\n","sensor_test_init",0x13e8);
  }
  memset(local_7fc,0,2000);
  local_7fc[0] = 0xffffffff;
  local_858[0] = 0;
  local_858[1] = 0;
  local_858[2] = 0;
  local_858[3] = 0;
  FUN_0051ad88(local_858 + 1);
  iVar2 = sensor_test_db_init();
  if ((iVar2 == 0) && (uVar3 = sensor_test_db_get_case_num_max(), uVar3 != 0)) {
    l_sensor_test_ssid_alloc_list = (void *)FUN_00408450(uVar3 << 2,0x1400);
    if (l_sensor_test_ssid_alloc_list == (void *)0x0) {
      if (sensor_test_err_switch == '\0') goto LAB_004f8c7c;
      __format = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
      uVar6 = 0x1403;
    }
    else {
      memset(l_sensor_test_ssid_alloc_list,0,uVar3 << 2);
      iVar2 = sensor_test_db_get_case_id_list(local_7fc,local_858);
      if (iVar2 == -1) goto LAB_004f8c7c;
      if (0 < local_858[0]) {
        puVar7 = local_7fc;
        iVar2 = 0;
        while (iVar2 < local_858[0]) {
          uVar4 = *puVar7;
          if (((int)uVar4 < 0) || (uVar3 <= uVar4)) {
            if (sensor_test_warning_switch == '\0') {
              iVar2 = iVar2 + 1;
              puVar7 = puVar7 + 1;
            }
            else {
              printf("[SENSOR_TEST_WARNING]%s()/%d invalid test_case id, case_id_list[%d]=%d\n",
                     "sensor_test_init",0x1413,iVar2,uVar4);
              iVar2 = iVar2 + 1;
              puVar7 = puVar7 + 1;
            }
          }
          else {
            piVar1 = local_858 + 1;
            FUN_0051ad88(piVar1);
            iVar5 = sensor_test_sql_get_bssid_alloc_table(*puVar7,piVar1);
            if (iVar5 == -1) {
              while (iVar5 = FUN_004081b0(piVar1), iVar5 != 0) {
                FUN_00408500(iVar5);
                FUN_00407df0(iVar5);
              }
              iVar2 = iVar2 + 1;
              puVar7 = puVar7 + 1;
            }
            else {
              iVar5 = _sensor_test_ssid_alloc_list_init(*puVar7,piVar1);
              if (iVar5 == -1) goto LAB_004f8c7c;
              while (iVar5 = FUN_004081b0(piVar1), iVar5 != 0) {
                FUN_00408500(iVar5);
                FUN_00407df0(iVar5);
              }
              iVar2 = iVar2 + 1;
              puVar7 = puVar7 + 1;
            }
          }
        }
      }
      FUN_004084d0("sensor_test_ssid_list",3,jcs_sensor_test_get_ssid_list);
      FUN_004084d0("sensor_test_digest",3,jcs_sensor_test_get_digest);
      FUN_004084d0("sensor_test_summary",3,jcs_sensor_test_get_summary_result);
      FUN_004084d0("sensor_test_summary_new",3,jcs_sensor_test_get_summary_result_new);
      FUN_004084d0("sensor_test_result",3,jcs_sensor_test_get_simple_result);
      FUN_004084d0("sensor_test_detail_result",3,jcs_sensor_test_get_detail_result);
      FUN_004084d0("sensor_test_case_list",2,jcs_sensor_test_set_test_case);
      FUN_004084d0("sensor_test_case_list",0,jcs_sensor_test_add_test_case);
      FUN_004084d0("sensor_test_case_list",1,jcs_sensor_test_del_test_case);
      FUN_004084d0("sensor_test_group_delete_event_handle",2,
                   jcs_sensor_test_group_delete_event_handle);
      FUN_004084d0("sensor_test_wserv_delete_event_handle",2,
                   jcs_sensor_test_wserv_delete_event_handle);
      sensor_stats_cb_reg_by_funcname("sensor-test",100,sensor_test_result_collect_cb);
      local_844 = 0x28000000;
      local_83c = (char *)0x0;
      local_848 = "sensor_test";
      local_840 = _sensor_test_multilink_callback_sensor_add;
      iVar2 = multi_link_reg(&local_848);
      if (iVar2 == -1) {
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d register callback to multi link failed.\n",
                 "_sensor_test_multilink_callback_init",0x12a8);
        }
        if (sensor_test_err_switch == '\0') goto LAB_004f8c7c;
        __format = "[SENSOR_TEST_ERROR]%s()/%d sensor_test_multilink_callback_init() fail!\n";
        uVar6 = 0x1446;
      }
      else {
        memset(&local_848,0,0x4c);
        local_83c = "sensor_test";
        local_838 = 0x28;
        local_828 = _sensor_test_apmngr_callback_sensor_destory;
        iVar2 = apmngr_callback_register(&local_848);
        if (iVar2 == 0) {
          memset(&local_848,0,0x20);
          memset(&local_848,0,0x20);
          local_83c = "sensor_test";
          local_838 = 0x28;
          local_830 = _sensor_test_wserv_update_event_handle;
          iVar2 = uac_wservice_callback_register(&local_848);
          if (iVar2 != -1) {
            l_sensor_test_aged_result_clear_timer = 0xffffffff;
            l_sensor_test_aged_result_clear_timer =
                 FUN_00408340(0x708,0,_sensor_test_aged_result_clean_time_out_handler,0,0,
                              "sensor_test_init",0x1458);
            return 0;
          }
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d register wservice_callback failed.\n",
                   "_sensor_test_wserv_callback_init",0x1294);
          }
          if (sensor_test_err_switch == '\0') goto LAB_004f8c7c;
          __format = "[SENSOR_TEST_ERROR]%s()/%d _sensor_test_wserv_callback_init() fail!\n";
          uVar6 = 0x1452;
        }
        else {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d apmngr_callback_register fail\n",
                   "_sensor_test_apmngr_callback_init",0x12ba);
          }
          if (sensor_test_err_switch == '\0') goto LAB_004f8c7c;
          __format = "[SENSOR_TEST_ERROR]%s()/%d _sensor_test_apmngr_callback_init() fail!\n";
          uVar6 = 0x144c;
        }
      }
    }
    printf(__format,"sensor_test_init",uVar6);
  }
LAB_004f8c7c:
  while (iVar2 = FUN_004081b0(local_858 + 1), iVar2 != 0) {
    FUN_00408500(iVar2);
    FUN_00407df0(iVar2);
  }
  sensor_test_db_uninit();
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d sensor_test_init fail EXIT\n","sensor_test_init",0x1466);
  }
  return 0xffffffff;
}

