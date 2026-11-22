// func sensor_di_db_get_freq_density @ 004e0c34 size=424

void * sensor_di_db_get_freq_density(int param_1)

{
  int iVar1;
  void *__dest;
  char *pcVar2;
  undefined4 uVar3;
  
  if (sensor_di_debug_switch == 0) {
    if (-1 < param_1) goto LAB_004e0c6c;
LAB_004e0d10:
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid sensor_id\n","sensor_di_db_get_freq_density",
             0xbaa);
    }
  }
  else {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : db_get_freq_density ENTER,sensor_id=%d\n",
           "sensor_di_db_get_freq_density",0xba4,param_1);
    if (param_1 < 0) goto LAB_004e0d10;
LAB_004e0c6c:
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
    if (iVar1 == 0) {
      if (sensor_di_debug_switch != 0) {
        pcVar2 = "[SENSOR_DI_DEBUG]%s()/line %d : sensor node no found\n";
        uVar3 = 0xbb2;
LAB_004e0db8:
        printf(pcVar2,"sensor_di_db_get_freq_density",uVar3);
      }
    }
    else {
      __dest = (void *)FUN_00408450(0x1248,2999);
      if (__dest != (void *)0x0) {
        memcpy(__dest,(void *)(iVar1 + 0x31f2),0x1248);
        FUN_00407f30(l_sensor_di_data_mutex);
        if (sensor_di_debug_switch == 0) {
          return __dest;
        }
        pcVar2 = "[SENSOR_DI_DEBUG]%s()/line %d : db_get_freq_density success EXIT\n";
        uVar3 = 0xbc1;
        goto LAB_004e0d40;
      }
      if (sensor_di_debug_switch != 0) {
        pcVar2 = "[SENSOR_DI_DEBUG]%s()/line %d : mem malloc fail\n";
        uVar3 = 0xbba;
        goto LAB_004e0db8;
      }
    }
    FUN_00407f30(l_sensor_di_data_mutex);
  }
  __dest = (void *)0x0;
  if (sensor_di_warning_switch == 0) {
    return (void *)0x0;
  }
  pcVar2 = "[SENSOR_DI_WARNING]%s()/line %d : db_get_freq_density fail EXIT\n";
  uVar3 = 0xbc5;
LAB_004e0d40:
  printf(pcVar2,"sensor_di_db_get_freq_density",uVar3);
  return __dest;
}

