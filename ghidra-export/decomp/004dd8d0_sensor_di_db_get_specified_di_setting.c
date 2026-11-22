// func sensor_di_db_get_specified_di_setting @ 004dd8d0 size=344

undefined4 sensor_di_db_get_specified_di_setting(int param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_get_specified_di_setting ENTER, sensor_id=%d\n"
           ,"sensor_di_db_get_specified_di_setting",0x818,param_1);
  }
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  if (l_sensor_di_setting_cnt < 1) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : l_sensor_di_setting_cnt=%d, fail to get specified di setting\n"
             ,"sensor_di_db_get_specified_di_setting",0x81e);
    }
    uVar3 = 0xffffffff;
    FUN_00407f30(l_sensor_di_data_mutex);
  }
  else {
    iVar1 = 0;
    piVar2 = l_sensor_di_setting;
    do {
      if (param_1 == *piVar2) {
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : find specified di setting,EXIT\n",
                 "sensor_di_db_get_specified_di_setting",0x826);
        }
        uVar3 = 0;
        memcpy(param_2,l_sensor_di_setting + iVar1 * 0x29,0xa4);
        goto LAB_004dd954;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x29;
    } while (iVar1 != l_sensor_di_setting_cnt);
    uVar3 = 0xffffffff;
LAB_004dd954:
    FUN_00407f30(l_sensor_di_data_mutex);
  }
  return uVar3;
}

