// func sensor_di_cw_send_stop_notify_all_sensors @ 004daa70 size=600

undefined4 sensor_di_cw_send_stop_notify_all_sensors(void)

{
  undefined4 *puVar1;
  uint uVar2;
  void *__ptr;
  char *__format;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 local_d8 [152];
  undefined4 local_40;
  int local_30 [3];
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_cw_send_stop_notify_all_sensors ENTER\n",
           "sensor_di_cw_send_stop_notify_all_sensors",0x815);
  }
  local_30[0] = 0;
  puVar1 = (undefined4 *)sensor_di_db_get_di_setting(local_30);
  if (puVar1 == (undefined4 *)0x0) {
    if (sensor_di_err_switch == 0) goto LAB_004dabc8;
    __format = "[SENSOR_DI_ERROR]%s()/line %d : get di setting fail\n";
    uVar3 = 0x81e;
  }
  else {
    if (local_30[0] < 1) {
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : cnt <= 0\n",
               "sensor_di_cw_send_stop_notify_all_sensors",0x823);
      }
      FUN_00407df0(puVar1);
      puVar1 = (undefined4 *)0x0;
      goto LAB_004dabc8;
    }
    iVar5 = 0;
    puVar4 = puVar1;
    while( true ) {
      if (local_30[0] <= iVar5) {
        if (sensor_di_debug_switch == 0) {
          return 0;
        }
        printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_cw_send_stop_notify_all_sensors success EXIT\n"
               ,"sensor_di_cw_send_stop_notify_all_sensors",0x839);
        return 0;
      }
      local_40 = 0;
      for (uVar2 = 0; uVar2 < 0x98; uVar2 = uVar2 + 1) {
        local_d8[uVar2] = *(undefined1 *)((int)puVar4 + uVar2 + 0xc);
      }
      __ptr = (void *)sensor_di_packet_json_generate(1,*puVar4,puVar4[1],puVar4[2]);
      if (__ptr == (void *)0x0) break;
      sensor_pkt_tdcp_send(*(undefined2 *)((int)puVar4 + 2),__ptr);
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : %s\n","sensor_di_cw_send_stop_notify_all_sensors",
               0x832,__ptr);
      }
      free(__ptr);
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 0x29;
    }
    if (sensor_di_err_switch == 0) goto LAB_004dabc8;
    __format = "[SENSOR_DI_ERROR]%s()/line %d : generate json_str fail\n";
    uVar3 = 0x82e;
  }
  printf(__format,"sensor_di_cw_send_stop_notify_all_sensors",uVar3);
LAB_004dabc8:
  if (sensor_di_err_switch != 0) {
    printf("[SENSOR_DI_ERROR]%s()/line %d : sensor_di_cw_send_stop_notify_all_sensors fail EXIT\n",
           "sensor_di_cw_send_stop_notify_all_sensors",0x83d);
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00407df0(puVar1);
  }
  return 0xffffffff;
}

