// func sensor_di_db_init @ 004dd07c size=316

undefined4 sensor_di_db_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_init ENTER\n","sensor_di_db_init",0x708);
  }
  iVar1 = FUN_0051eb48("sensor","di_cache_max",&l_sensor_di_cache_sensor_max);
  if (iVar1 == -1) {
    if (sensor_di_err_switch == 0) {
      l_sensor_di_cache_sensor_max = 2;
    }
    else {
      printf("[SENSOR_DI_ERROR]%s()/line %d : get profile[sensor->di_cache_max] failed.\n",
             "sensor_di_db_init",0x70d);
      l_sensor_di_cache_sensor_max = 2;
    }
  }
  l_sensor_di_data_mutex = FUN_00407f00("sensor_di_data_mutex",1);
  if (l_sensor_di_data_mutex == 0) {
    uVar3 = 0xffffffff;
    sensor_di_db_destroy();
    if (sensor_di_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[SENSOR_DI_ERROR]%s()/line %d : sensor_di_db_init fail\n";
    uVar2 = 0x71d;
  }
  else {
    uVar3 = 0;
    FUN_0051ad88(&l_sensor_di_cached_sensor_list);
    if (sensor_di_debug_switch == 0) {
      return 0;
    }
    __format = "[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_init success\n";
    uVar2 = 0x718;
  }
  printf(__format,"sensor_di_db_init",uVar2);
  return uVar3;
}

