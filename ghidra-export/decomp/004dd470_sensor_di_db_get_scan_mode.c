// func sensor_di_db_get_scan_mode @ 004dd470 size=284

undefined4 sensor_di_db_get_scan_mode(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_scan_mode ENTER\n",
           "sensor_di_db_get_scan_mode",0x7a8);
  }
  if ((param_2 == (undefined1 *)0x0) || (param_3 == (undefined1 *)0x0)) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid input\n","sensor_di_db_get_scan_mode",0x7ae);
      return 0xffffffff;
    }
  }
  else {
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    uVar1 = l_sensor_di_data_mutex;
    if ((0 < l_sensor_di_setting_cnt) &&
       (iVar3 = 0, piVar2 = l_sensor_di_setting, l_sensor_di_setting != (int *)0x0)) {
      do {
        if (param_1 == *piVar2) {
          *param_2 = *(undefined1 *)((int)piVar2 + 6);
          *param_3 = *(undefined1 *)((int)piVar2 + 7);
          FUN_00407f30(uVar1);
          return 0;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 0x29;
      } while (iVar3 != l_sensor_di_setting_cnt);
    }
    FUN_00407f30(l_sensor_di_data_mutex);
  }
  return 0xffffffff;
}

