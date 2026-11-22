// func sensor_db_update_backhaul_bssid @ 004d0d48 size=412

undefined4 sensor_db_update_backhaul_bssid(uint param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *__src;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  param_1 = param_1 & 0xffff;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if ((param_1 < 50000) || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= (int)param_1)) {
    uVar2 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_db_update_backhaul_bssid",0x32d);
    }
  }
  else {
    FUN_004082d0(g_sensor_mutex,0xffffffff);
    __src = (void *)(g_sensor_entry_array + param_1 * 0x18 + -1200000);
    if ((*(char *)((int)__src + 2) == '\0') || (*(char *)((int)__src + 3) == '\0')) {
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d Entry id %d is not used or not firmed\n",
               "sensor_db_update_backhaul_bssid",0x333,param_1);
      }
      uVar2 = 0xffffffff;
      FUN_00407f30(g_sensor_mutex);
    }
    else {
      *(bool *)((int)__src + 4) = param_2 != (void *)0x0;
      if (param_2 == (void *)0x0) {
        *(undefined1 *)((int)__src + 5) = 0;
        *(undefined1 *)((int)__src + 6) = 0;
        *(undefined1 *)((int)__src + 7) = 0;
        *(undefined1 *)((int)__src + 8) = 0;
        *(undefined1 *)((int)__src + 9) = 0;
        *(undefined1 *)((int)__src + 10) = 0;
      }
      else {
        memcpy((void *)((int)__src + 5),param_2,6);
      }
      memcpy(&local_30,__src,0x18);
      uVar2 = 0xffffffff;
      FUN_00407f30(g_sensor_mutex);
      iVar1 = sensor_db_sqlite_notify_msg(1,&local_30,0x18);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

