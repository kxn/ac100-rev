// func sensor_di_db_get_di_setting @ 004dd744 size=396

void * sensor_di_db_get_di_setting(int *param_1)

{
  int iVar1;
  void *__dest;
  char *__format;
  undefined4 uVar2;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_get_di_setting ENTER\n",
           "sensor_di_db_get_di_setting",0x7f6);
  }
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar1 = l_sensor_di_setting_cnt;
  if (l_sensor_di_setting_cnt < 1) {
    if (sensor_di_warning_switch != 0) {
      printf("[SENSOR_DI_WARNING]%s()/line %d : l_sensor_di_setting_cnt=%d\n",
             "sensor_di_db_get_di_setting",0x7fd);
    }
  }
  else {
    *param_1 = l_sensor_di_setting_cnt;
    __dest = (void *)FUN_00408450(iVar1 * 0xa4,0x803);
    if (__dest != (void *)0x0) {
      memcpy(__dest,l_sensor_di_setting,l_sensor_di_setting_cnt * 0xa4);
      FUN_00407f30(l_sensor_di_data_mutex);
      if (sensor_di_debug_switch == 0) {
        return __dest;
      }
      __format = "[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_get_di_setting success EXIT\n";
      uVar2 = 0x80e;
      goto LAB_004dd840;
    }
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n","sensor_di_db_get_di_setting",0x806
            );
    }
  }
  __dest = (void *)0x0;
  FUN_00407f30(l_sensor_di_data_mutex);
  if (sensor_di_debug_switch == 0) {
    return (void *)0x0;
  }
  __format = "[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_get_di_setting fail EXIT\n";
  uVar2 = 0x812;
LAB_004dd840:
  printf(__format,"sensor_di_db_get_di_setting",uVar2);
  return __dest;
}

