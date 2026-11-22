// func sensor_backhaul_set @ 004e7370 size=888

undefined4 sensor_backhaul_set(uint param_1,int param_2,void *param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_520;
  undefined4 local_51c;
  undefined4 local_518;
  uint local_514;
  undefined4 local_510;
  undefined4 local_50c;
  undefined4 local_508;
  undefined4 local_504;
  undefined4 local_500;
  undefined4 local_4fc;
  undefined1 auStack_4f8 [520];
  undefined1 auStack_2f0 [20];
  int local_2dc;
  int local_2b4;
  undefined4 local_2b0;
  undefined1 auStack_d8 [192];
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2f0,0,0x2d8);
  local_510 = 0;
  local_50c = 0;
  local_508 = 0;
  local_504 = 0;
  local_500 = 0;
  local_4fc = 0;
  memset(auStack_4f8,0,0x205);
  local_520 = 0;
  local_51c = 0;
  local_518 = 0;
  local_514 = 0;
  if ((param_1 < 50000) || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= (int)param_1)) {
    uVar5 = 0xffffffff;
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar3 = "[SENSOR_ERROR]%s()/%d Input error\n";
    uVar4 = 0x93c;
    goto LAB_004e74b4;
  }
  if ((g_sensor_enable == 0) || (g_backhaul_wserv_id == -1)) {
    uVar5 = 0;
    if (sensor_warning_switch == '\0') {
      return 0;
    }
    pcVar3 = "[SENSOR_WARNING]%s()/%d Sensor is not enabled or backhual wserv id(%d) is error\n";
    uVar4 = 0x941;
LAB_004e7490:
    printf(pcVar3,"sensor_backhaul_set",uVar4,g_backhaul_wserv_id);
    return uVar5;
  }
  iVar1 = wserv_db_get_entry_by_id(g_backhaul_wserv_id,auStack_4f8);
  if (iVar1 != 0) {
    uVar5 = 0xffffffff;
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar3 = "[SENSOR_ERROR]%s()/%d Get backhaul wservice(%d) failed\n";
    uVar4 = 0x947;
    goto LAB_004e7490;
  }
  iVar1 = sensor_db_get(param_1,&local_510,0);
  if ((((iVar1 != 0) || (iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f0), iVar1 != 0)) ||
      (local_2dc != 7)) || (local_2b4 == 0)) {
    uVar5 = 0xffffffff;
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar3 = 
    "[SENSOR_ERROR]%s()/%d sensor_db_get/apmngr_db_entry_get_by_id failed or role error or not firmed\n"
    ;
    uVar4 = 0x94c;
    goto LAB_004e74b4;
  }
  iVar1 = apdb_get_radio_extend_capability(local_2b0,auStack_d8,1,0xffffffff,&local_520,0x10);
  if (iVar1 != 0) {
    uVar5 = 0xffffffff;
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar3 = "[SENSOR_ERROR]%s()/%d apdb_get_radio_extend_capability failed\n";
    uVar4 = 0x951;
    goto LAB_004e74b4;
  }
  if ((local_514 & 0x40) == 0) {
    uVar5 = 0;
    if (sensor_warning_switch == '\0') {
      return 0;
    }
    pcVar3 = "[SENSOR_WARNING]%s()/%d Sensor not support backhaul\n";
    uVar4 = 0x956;
    goto LAB_004e74b4;
  }
  uVar5 = 2;
  if (param_2 != 0) {
    uVar2 = local_50c >> 0x18;
    uVar4 = 3;
    if (param_3 == (void *)0x0) {
LAB_004e7610:
      uVar5 = 1;
      if (uVar2 == 0) goto LAB_004e7654;
    }
    else {
      uVar4 = 1;
      if (uVar2 != 0) {
        uVar4 = 2;
        uVar2 = memcmp(param_3,(void *)((int)&local_50c + 1),6);
        goto LAB_004e7610;
      }
    }
    iVar1 = sensor_db_update_backhaul_bssid(param_1,param_3);
    if (iVar1 != 0) {
      uVar5 = 0xffffffff;
      if (sensor_err_switch == '\0') {
        return 0xffffffff;
      }
      pcVar3 = "[SENSOR_ERROR]%s()/%d sensor_db_update_backhaul_bssid failed\n";
      uVar4 = 0x974;
      goto LAB_004e74b4;
    }
    iVar1 = _sensor_backhaul_ssid_send(param_1,param_3,1,auStack_4f8,uVar4,0);
    if (iVar1 != 0) {
      uVar5 = 0xffffffff;
      if (sensor_err_switch == '\0') {
        return 0xffffffff;
      }
      pcVar3 = "[SENSOR_ERROR]%s()/%d sensor_backhaul_ssid_send for primary bssid failed\n";
      uVar4 = 0x97a;
      goto LAB_004e74b4;
    }
    uVar5 = 1;
  }
LAB_004e7654:
  iVar1 = _sensor_backhaul_ssid_send(param_1,0,0,auStack_4f8,uVar5,0);
  if (iVar1 == 0) {
    return 0;
  }
  uVar5 = 0xffffffff;
  if (sensor_err_switch == '\0') {
    return 0xffffffff;
  }
  pcVar3 = "[SENSOR_ERROR]%s()/%d sensor_backhaul_ssid_send for backup bssid failed\n";
  uVar4 = 0x97f;
LAB_004e74b4:
  printf(pcVar3,"sensor_backhaul_set",uVar4);
  return uVar5;
}

