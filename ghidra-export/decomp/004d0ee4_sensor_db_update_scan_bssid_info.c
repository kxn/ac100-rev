// func sensor_db_update_scan_bssid_info @ 004d0ee4 size=472

undefined4 sensor_db_update_scan_bssid_info(uint param_1,short param_2,void *param_3)

{
  int iVar1;
  void *__dest;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  param_1 = param_1 & 0xffff;
  iVar4 = (int)param_2;
  if (((param_1 < 50000) || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= (int)param_1)) ||
     ((0 < iVar4 && (param_3 == (void *)0x0)))) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_db_update_scan_bssid_info",0x34d);
    return 0xffffffff;
  }
  FUN_004082d0(g_sensor_mutex,0xffffffff);
  iVar3 = param_1 * 0x18 + -1200000;
  iVar1 = g_sensor_entry_array + iVar3;
  if (*(char *)(iVar1 + 2) == '\0') {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Entry id %d is not used\n","sensor_db_update_scan_bssid_info",
             0x353,param_1);
    }
LAB_004d1078:
    uVar2 = 0xffffffff;
    FUN_00407f30(g_sensor_mutex);
  }
  else {
    *(short *)(iVar1 + 0xc) = param_2;
    if (*(int *)(iVar1 + 0x10) != 0) {
      FUN_00407df0();
      *(undefined4 *)(g_sensor_entry_array + iVar3 + 0x10) = 0;
    }
    if (0 < iVar4) {
      iVar1 = g_sensor_entry_array + iVar3;
      uVar2 = FUN_00408450(iVar4 * 0x14,0x35f);
      *(undefined4 *)(iVar1 + 0x10) = uVar2;
      __dest = *(void **)(g_sensor_entry_array + iVar3 + 0x10);
      if (__dest == (void *)0x0) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","sensor_db_update_scan_bssid_info",0x362);
        }
        *(undefined2 *)(g_sensor_entry_array + iVar3 + 0xc) = 0;
        goto LAB_004d1078;
      }
      memcpy(__dest,param_3,iVar4 * 0x14);
    }
    uVar2 = 0;
    FUN_00407f30(g_sensor_mutex);
  }
  return uVar2;
}

