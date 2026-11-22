// func sensor_di_db_get_freq_water_fall @ 004e0a34 size=512

void * sensor_di_db_get_freq_water_fall(int param_1,short *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  void *__dest;
  
  if (sensor_di_debug_switch == 0) {
    if (-1 < param_1) goto LAB_004e0a6c;
LAB_004e0b2c:
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid sensor_id\n",
             "sensor_di_db_get_freq_water_fall",0xb74);
    }
  }
  else {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : db_get_freq_water_fall ENTER,sensor_id=%d\n",
           "sensor_di_db_get_freq_water_fall",0xb6e,param_1);
    if (param_1 < 0) goto LAB_004e0b2c;
LAB_004e0a6c:
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
    if (iVar1 == 0) {
      if (sensor_di_debug_switch != 0) {
        pcVar2 = "[SENSOR_DI_DEBUG]%s()/line %d : sensor node no found\n";
        uVar3 = 0xb7c;
LAB_004e0bd0:
        printf(pcVar2,"sensor_di_db_get_freq_water_fall",uVar3);
      }
    }
    else if (*(short *)(iVar1 + 0x14) < 1) {
      if (sensor_di_debug_switch != 0) {
        pcVar2 = "[SENSOR_DI_DEBUG]%s()/line %d : waterfall_cnt <= 0\n";
        uVar3 = 0xb83;
        goto LAB_004e0bd0;
      }
    }
    else {
      *param_2 = *(short *)(iVar1 + 0x14);
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : waterfall_cnt=%d\n",
               "sensor_di_db_get_freq_water_fall",0xb88,(int)*(short *)(iVar1 + 0x14));
      }
      __dest = (void *)FUN_00408450(0xb7c0,0xb89);
      if (__dest != (void *)0x0) {
        memcpy(__dest,(void *)(iVar1 + 0x10d52),0xb7c0);
        FUN_00407f30(l_sensor_di_data_mutex);
        if (sensor_di_debug_switch == 0) {
          return __dest;
        }
        pcVar2 = "[SENSOR_DI_DEBUG]%s()/line %d : db_get_freq_water_fall success EXIT\n";
        uVar3 = 0xb93;
        goto LAB_004e0b5c;
      }
      if (sensor_di_debug_switch != 0) {
        pcVar2 = "[SENSOR_DI_DEBUG]%s()/line %d : mem malloc fail\n";
        uVar3 = 0xb8c;
        goto LAB_004e0bd0;
      }
    }
    FUN_00407f30(l_sensor_di_data_mutex);
  }
  __dest = (void *)0x0;
  if (sensor_di_warning_switch == 0) {
    return (void *)0x0;
  }
  pcVar2 = "[SENSOR_DI_WARNING]%s()/line %d : db_get_freq_water_fall fail EXIT\n";
  uVar3 = 0xb97;
LAB_004e0b5c:
  printf(pcVar2,"sensor_di_db_get_freq_water_fall",uVar3);
  return __dest;
}

