// func sensor_di_handler_start_new_deep_inspection @ 004db954 size=868

undefined4 sensor_di_handler_start_new_deep_inspection(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int local_30 [3];
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : start_new_deep_inspection ENTER\n",
           "sensor_di_handler_start_new_deep_inspection",0x10d1);
  }
  local_30[0] = 0;
  iVar2 = sensor_di_get_cache_sensor_max();
  iVar3 = sensor_di_handler_stop_cur_deep_inspection();
  if (iVar3 == -1) {
    iVar3 = 0;
    if (sensor_di_err_switch == 0) goto LAB_004dbc00;
    pcVar6 = "[SENSOR_DI_ERROR]%s()/line %d : stop_cur_deep_inspection fail\n";
    uVar8 = 0x10dd;
  }
  else {
    sensor_di_db_all_sensor_cached_list_free();
    sensor_di_db_pkt_stat_cache_free(&l_sensor_di_pkt_stat_cache);
    iVar3 = sensor_di_db_get_di_setting(local_30);
    if (iVar3 == 0) {
      if (sensor_di_err_switch == 0) goto LAB_004dbc00;
      pcVar6 = "[SENSOR_DI_ERROR]%s()/line %d : get di_setting fail\n";
      uVar8 = 0x10e6;
    }
    else {
      iVar4 = sensor_di_cw_send_setting_to_all_sensors(iVar3,local_30[0]);
      if (iVar4 == -4) {
        FUN_00407df0(iVar3);
        uVar8 = 0xfffffffc;
        sensor_di_db_all_sensor_cached_list_free();
        if (sensor_di_err_switch == 0) {
          return 0xfffffffc;
        }
        pcVar6 = "[SENSOR_DI_ERROR]%s()/line %d : start_new_deep_inspection FAIL\n";
        uVar7 = 0x10f3;
LAB_004dbba8:
        printf(pcVar6,"sensor_di_handler_start_new_deep_inspection",uVar7);
        return uVar8;
      }
      if (iVar4 != -1) {
        iVar4 = local_30[0];
        if (iVar2 <= local_30[0]) {
          iVar4 = iVar2;
        }
        iVar2 = 0;
        iVar1 = iVar4;
        while (iVar1 = iVar1 + -1, -1 < iVar1) {
          if (sensor_di_debug_switch != 0) {
            printf("[SENSOR_DI_DEBUG]%s()/line %d : idx=%d\n",
                   "sensor_di_handler_start_new_deep_inspection",0x1108,iVar1);
          }
          iVar5 = iVar3 + iVar4 * 0xa4 + iVar2;
          iVar2 = iVar2 + -0xa4;
          sensor_di_db_add_new_sensor_to_cached_list(*(undefined4 *)(iVar5 + -0xa4));
        }
        FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
        l_sensor_di_cur_viewed_sensor_id = *(undefined4 *)(iVar3 + iVar1 * 0xa4);
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : cur_view_sensor=%d when start\n",
                 "sensor_di_handler_start_new_deep_inspection",0x110f);
        }
        l_sensor_di_status = 1;
        uVar9 = FUN_00407e70();
        l_sensor_di_start_local_timestamp = (undefined4)((ulonglong)uVar9 >> 0x20);
        DAT_007685dc = (undefined4)uVar9;
        l_sensor_di_start_utc_timestamp = time((time_t *)0x0);
        if (l_sensor_di_timer != -1) {
          FUN_00408060();
          l_sensor_di_timer = -1;
        }
        l_sensor_di_timer =
             FUN_00408340(600,0,sensor_di_handler_time_out,0,0,
                          "sensor_di_handler_start_new_deep_inspection",0x1118);
        FUN_00407f30(l_sensor_di_status_mutex);
        FUN_00407df0(iVar3);
        uVar8 = 0;
        if (sensor_di_debug_switch == 0) {
          return 0;
        }
        uVar7 = 0x1121;
        pcVar6 = "[SENSOR_DI_DEBUG]%s()/line %d : start_new_deep_inspection SUCCESS\n";
        goto LAB_004dbba8;
      }
      if (sensor_di_err_switch == 0) goto LAB_004dbc00;
      pcVar6 = "[SENSOR_DI_ERROR]%s()/line %d : send setting to all sensors failed\n";
      uVar8 = 0x10f8;
    }
  }
  printf(pcVar6,"sensor_di_handler_start_new_deep_inspection",uVar8);
LAB_004dbc00:
  if (sensor_di_err_switch != 0) {
    printf("[SENSOR_DI_ERROR]%s()/line %d : start_new_deep_inspection FAIL\n",
           "sensor_di_handler_start_new_deep_inspection",0x1125);
  }
  if (iVar3 != 0) {
    FUN_00407df0(iVar3);
  }
  sensor_di_db_all_sensor_cached_list_free();
  return 0xffffffff;
}

