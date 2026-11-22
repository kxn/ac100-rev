// func sensor_db_firm @ 004d04b8 size=392

undefined4 sensor_db_firm(uint param_1)

{
  int iVar1;
  char *__format;
  void *__src;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  param_1 = param_1 & 0xffff;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if ((param_1 < 50000) || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= (int)param_1)) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_db_firm",0x295);
    return 0xffffffff;
  }
  FUN_004082d0(g_sensor_mutex,0xffffffff);
  __src = (void *)(g_sensor_entry_array + param_1 * 0x18 + -1200000);
  if (*(char *)((int)__src + 2) == '\0') {
    if (sensor_warning_switch == '\0') goto LAB_004d05ec;
    __format = "[SENSOR_WARNING]%s()/%d Entry id %d is not used\n";
    uVar2 = 0x29b;
  }
  else {
    if (*(char *)((int)__src + 3) == '\0') {
      *(undefined1 *)((int)__src + 3) = 1;
      memcpy(&local_28,__src,0x18);
      FUN_00407f30(g_sensor_mutex);
      iVar1 = sensor_db_sqlite_notify_msg(0,&local_28,0x18);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      return 0;
    }
    if (sensor_err_switch == '\0') goto LAB_004d05ec;
    __format = "[SENSOR_ERROR]%s()/%d Entry id %d is already firmed\n";
    uVar2 = 0x2a1;
  }
  printf(__format,"sensor_db_firm",uVar2,param_1);
LAB_004d05ec:
  FUN_00407f30(g_sensor_mutex);
  return 0xffffffff;
}

