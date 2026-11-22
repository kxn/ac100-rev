// func sensor_discover_start @ 004e7edc size=612

undefined4 sensor_discover_start(int param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  int local_20 [3];
  
  local_20[0] = 0;
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  uVar4 = CONCAT44(sensor_discover_start_timestamp,DAT_00768624);
  if ((param_1 == 0) && (0 < param_2)) {
    uVar3 = 0xffffffff;
    if (sensor_err_switch == '\0') goto LAB_004e7f90;
    __format = "[SENSOR_ERROR]%s()/%d Input error\n";
    uVar2 = 0xa15;
  }
  else {
    if ((g_sensor_enable == 0) || (g_backhaul_wserv_id == -1)) {
      uVar3 = 0xfffffffe;
      uVar4 = CONCAT44(sensor_discover_start_timestamp,DAT_00768624);
      if (sensor_warning_switch != '\0') {
        printf("[SENSOR_WARNING]%s()/%d Sensor(%d) is closed or g_backhaul_wserv_id(%d) or state(%d) is error\n"
               ,"sensor_discover_start",0xa1b,g_sensor_enable,g_backhaul_wserv_id,g_sensor_state);
        uVar4 = CONCAT44(sensor_discover_start_timestamp,DAT_00768624);
      }
      goto LAB_004e7f90;
    }
    if (wait_for_delete_dft_wserv_id == 0) {
      if (g_sensor_state != 0) {
        _sensor_discover_reset(0);
      }
      iVar1 = sensor_default_backhual_add_to_ap(param_1,param_2,local_20,&g_dft_backhaul_wserv_id);
      if (iVar1 == 0) {
        if (local_20[0] != 0) {
          g_sensor_state = 1;
          sensor_discover_timer =
               FUN_00408340(sensor_discover_timeout,0,_sensor_discover_timeout,0,0,
                            "sensor_discover_start",0xa3b);
          if (sensor_discover_timer == -1) {
            uVar3 = 0xffffffff;
            _sensor_discover_reset(0);
            uVar4 = CONCAT44(sensor_discover_start_timestamp,DAT_00768624);
          }
          else {
            uVar3 = 0;
            uVar4 = FUN_00407e70();
          }
          goto LAB_004e7f90;
        }
        if (g_dft_backhaul_wserv_id != -1) {
          uac_wservice_entry_delete_by_id();
          g_dft_backhaul_wserv_id = -1;
        }
        uVar3 = 0xfffffffc;
        uVar4 = CONCAT44(sensor_discover_start_timestamp,DAT_00768624);
        if (sensor_warning_switch == '\0') goto LAB_004e7f90;
        __format = "[SENSOR_WARNING]%s()/%d No online ap\n";
        uVar2 = 0xa36;
      }
      else {
        uVar3 = 0xfffffffd;
        uVar4 = CONCAT44(sensor_discover_start_timestamp,DAT_00768624);
        if (sensor_err_switch == '\0') goto LAB_004e7f90;
        __format = "[SENSOR_ERROR]%s()/%d Add default ssid to AP failed\n";
        uVar2 = 0xa2b;
      }
    }
    else {
      uVar3 = 0xfffffffb;
      uVar4 = CONCAT44(sensor_discover_start_timestamp,DAT_00768624);
      if (sensor_warning_switch == '\0') goto LAB_004e7f90;
      __format = "[SENSOR_WARNING]%s()/%d Default wserv not deleted, please wait\n";
      uVar2 = 0xa21;
    }
  }
  printf(__format,"sensor_discover_start",uVar2);
  uVar4 = CONCAT44(sensor_discover_start_timestamp,DAT_00768624);
LAB_004e7f90:
  sensor_discover_start_timestamp = (undefined4)((ulonglong)uVar4 >> 0x20);
  DAT_00768624 = (undefined4)uVar4;
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar3;
}

