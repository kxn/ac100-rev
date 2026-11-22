// func sensor_backhaul_set_test @ 004e915c size=1

undefined4 sensor_backhaul_set_test(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 auStack_120 [9];
  undefined1 auStack_117 [247];
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  memset(auStack_120,0,0x100);
  if (g_backhaul_wserv_id == 0xffffffff) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[SENSOR_ERROR]%s()/%d Backhual wserv id(%d) is error\n";
    uVar5 = 0xb31;
    param_1 = 0xffffffff;
code_r0x004e92a8:
    printf(pcVar4,"sensor_backhaul_set_test",uVar5,param_1);
  }
  else {
    uVar1 = rdmngr_db_generate_rd_id(param_2,param_3);
    uVar2 = wserv_db_wlanid_get_by_wservid(uVar1,g_backhaul_wserv_id);
    if (uVar2 == 0xffffffff) {
      if (sensor_err_switch == '\0') {
        return 0xffffffff;
      }
      pcVar4 = "[SENSOR_ERROR]%s()/%d Get wlan id failed of radio id %d and wserv id %d\n";
      uVar5 = 0xb38;
      param_3 = g_backhaul_wserv_id;
    }
    else {
      iVar3 = stats_db_ssid_get(param_2,param_3 & 0xff,uVar2 & 0xff,auStack_120);
      if (iVar3 == 0) {
        iVar3 = sensor_backhaul_set(param_1,1,auStack_117,1);
        if (iVar3 == 0) {
          return 0;
        }
        if (sensor_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar4 = "[SENSOR_ERROR]%s()/%d Sensor_backhaul_set failed for sensor %d\n";
        uVar5 = 0xb42;
        goto code_r0x004e92a8;
      }
      if (sensor_err_switch == '\0') {
        return 0xffffffff;
      }
      pcVar4 = "[SENSOR_ERROR]%s()/%d Get bssid failed of (%d,%d,%d)\n";
      uVar5 = 0xb3d;
      uVar1 = param_2;
    }
    printf(pcVar4,"sensor_backhaul_set_test",uVar5,uVar1,param_3);
  }
  return 0xffffffff;
}

