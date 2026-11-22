// func sensor_discover_scan_stop @ 004e8140 size=204

undefined4 sensor_discover_scan_stop(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if (((g_sensor_enable == 0) || (g_backhaul_wserv_id == -1)) || (g_sensor_state != 1)) {
    uVar1 = 0xfffffffe;
    if (sensor_warning_switch != '\0') {
      printf("[SENSOR_WARNING]%s()/%d Sensor(%d) is closed or g_backhaul_wserv_id(%d) or state(%d) is error\n"
             ,"sensor_discover_scan_stop",0xa50,g_sensor_enable,g_backhaul_wserv_id,g_sensor_state);
    }
  }
  else {
    uVar1 = 0;
    g_sensor_state = 2;
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar1;
}

