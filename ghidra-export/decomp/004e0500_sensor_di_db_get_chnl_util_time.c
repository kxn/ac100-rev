// func sensor_di_db_get_chnl_util_time @ 004e0500 size=508

void * sensor_di_db_get_chnl_util_time(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *__s;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : db_get_chnl_util_time ENTER,sensor_id=%d\n",
           "sensor_di_db_get_chnl_util_time",0xad2,param_1);
  }
  if (param_1 < 0) {
    if (sensor_di_err_switch == 0) goto LAB_004e0600;
    pcVar4 = "[SENSOR_DI_ERROR]%s()/line %d : invalid sensor_id\n";
    uVar5 = 0xad9;
  }
  else {
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
    if (iVar1 == 0) {
      if (sensor_di_debug_switch == 0) goto LAB_004e0600;
      pcVar4 = "[SENSOR_DI_DEBUG]%s()/line %d : sensor node no found\n";
      uVar5 = 0xae2;
    }
    else {
      iVar2 = 0;
      iVar3 = iVar1;
      do {
        if (*(byte *)(iVar3 + 0x4c1) == param_2) {
          __s = (void *)FUN_00408450(0x1e2,0xaef);
          if (__s != (void *)0x0) {
            memset(__s,0,0x1e2);
            memcpy(__s,(void *)(iVar1 + iVar2 * 0x1e2 + 0x2e0),0x1e2);
            FUN_00407f30(l_sensor_di_data_mutex);
            if (sensor_di_debug_switch == 0) {
              return __s;
            }
            pcVar4 = "[SENSOR_DI_DEBUG]%s()/line %d : db_get_chnl_util_time success EXIT\n";
            uVar5 = 0xafa;
            goto LAB_004e062c;
          }
          if (sensor_di_debug_switch == 0) goto LAB_004e0600;
          pcVar4 = "[SENSOR_DI_DEBUG]%s()/line %d : mem malloc fail\n";
          uVar5 = 0xaf2;
          goto LAB_004e06c8;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x1e2;
      } while (iVar2 != 0x19);
      if (sensor_di_debug_switch == 0) goto LAB_004e0600;
      pcVar4 = "[SENSOR_DI_DEBUG]%s()/line %d : specified chnl no found\n";
      uVar5 = 0xaea;
    }
  }
LAB_004e06c8:
  printf(pcVar4,"sensor_di_db_get_chnl_util_time",uVar5);
LAB_004e0600:
  __s = (void *)0x0;
  FUN_00407f30(l_sensor_di_data_mutex);
  if (sensor_di_warning_switch != 0) {
    pcVar4 = "[SENSOR_DI_WARNING]%s()/line %d : db_get_chnl_util_time fail EXIT\n";
    uVar5 = 0xafe;
LAB_004e062c:
    printf(pcVar4,"sensor_di_db_get_chnl_util_time",uVar5);
  }
  return __s;
}

