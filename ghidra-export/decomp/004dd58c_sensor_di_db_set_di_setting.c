// func sensor_di_db_set_di_setting @ 004dd58c size=440

undefined4 sensor_di_db_set_di_setting(void *param_1,int param_2)

{
  char *__format;
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (sensor_di_debug_switch == 0) {
    if (param_2 < 1) goto LAB_004dd69c;
LAB_004dd5c8:
    if (param_1 == (void *)0x0) goto LAB_004dd69c;
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    if (l_sensor_di_setting != (void *)0x0) {
      FUN_00407df0();
      l_sensor_di_setting = (void *)0x0;
      l_sensor_di_setting_cnt = 0;
    }
    l_sensor_di_setting = (void *)FUN_00408450(param_2 * 0xa4,0x7e1);
    if (l_sensor_di_setting != (void *)0x0) {
      memcpy(l_sensor_di_setting,param_1,param_2 * 0xa4);
      uVar2 = 0;
      l_sensor_di_setting_cnt = param_2;
      FUN_00407f30(l_sensor_di_data_mutex);
      if (sensor_di_debug_switch == 0) {
        return 0;
      }
      __format = "[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_di_setting success EXIT\n";
      uVar1 = 0x7ed;
      goto LAB_004dd6c8;
    }
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n","sensor_di_db_set_di_setting",0x7e4
            );
    }
    FUN_00407f30(l_sensor_di_data_mutex);
  }
  else {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_di_setting ENTER,setting_num=%d\n",
           "sensor_di_db_set_di_setting",0x7d1,param_2);
    if (0 < param_2) goto LAB_004dd5c8;
LAB_004dd69c:
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : input param invalid.maybe di_setting null or setting_num invalid\n"
             ,"sensor_di_db_set_di_setting",0x7d4);
    }
  }
  uVar2 = 0xffffffff;
  if (sensor_di_err_switch == 0) {
    return 0xffffffff;
  }
  __format = "[SENSOR_DI_ERROR]%s()/line %d : sensor_di_db_set_di_setting fail EXIT\n";
  uVar1 = 0x7f0;
LAB_004dd6c8:
  printf(__format,"sensor_di_db_set_di_setting",uVar1);
  return uVar2;
}

