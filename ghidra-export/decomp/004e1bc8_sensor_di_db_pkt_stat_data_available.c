// func sensor_di_db_pkt_stat_data_available @ 004e1bc8 size=244

undefined4 sensor_di_db_pkt_stat_data_available(undefined4 param_1,short param_2)

{
  int iVar1;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_id=%d, chnl=%d\n",
           "sensor_di_db_pkt_stat_data_available",0xc92,param_1,(int)param_2);
  }
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
  if (iVar1 != 0) {
    if ((int)*(short *)(iVar1 + 0x1c514) == (int)param_2) {
      FUN_00407f30(l_sensor_di_data_mutex);
      return 1;
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : input chnl unmatch\n",
             "sensor_di_db_pkt_stat_data_available",0xc9f);
    }
  }
  FUN_00407f30(l_sensor_di_data_mutex);
  return 0;
}

