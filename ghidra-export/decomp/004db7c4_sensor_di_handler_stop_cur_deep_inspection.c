// func sensor_di_handler_stop_cur_deep_inspection @ 004db7c4 size=400

undefined4 sensor_di_handler_stop_cur_deep_inspection(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : stop_cur_deep_inspection ENTER\n",
           "sensor_di_handler_stop_cur_deep_inspection",0x10ad);
  }
  _sensor_di_set_freq_analy_data_last_refresh_time(0);
  FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
  if (l_sensor_di_status == 1) {
    iVar1 = sensor_di_cw_send_stop_notify_all_sensors();
    if (iVar1 == -1) {
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : stop all sensors fail\n",
               "sensor_di_handler_stop_cur_deep_inspection",0x10b4);
      }
      FUN_00407f30(l_sensor_di_status_mutex);
      uVar3 = 0xffffffff;
      if (sensor_di_err_switch == 0) {
        return 0xffffffff;
      }
      __format = "[SENSOR_DI_ERROR]%s()/line %d : stop_cur_deep_inspection fail EXIT\n";
      uVar2 = 0x10cb;
      goto LAB_004db8d4;
    }
    l_sensor_di_status = 0;
  }
  if (l_sensor_di_timer != -1) {
    FUN_00408060();
    l_sensor_di_timer = -1;
  }
  uVar3 = 0;
  l_sensor_di_last_inspection_time = _sensor_di_get_cur_running_time();
  l_sensor_di_start_local_timestamp = 0;
  DAT_007685dc = 0;
  l_sensor_di_start_utc_timestamp = 0;
  l_sensor_di_cur_viewed_sensor_id = 0xffffffff;
  FUN_00407f30(l_sensor_di_status_mutex);
  if (sensor_di_debug_switch == 0) {
    return 0;
  }
  __format = "[SENSOR_DI_DEBUG]%s()/line %d : stop_cur_deep_inspection success EXIT\n";
  uVar2 = 0x10c7;
LAB_004db8d4:
  printf(__format,"sensor_di_handler_stop_cur_deep_inspection",uVar2);
  return uVar3;
}

