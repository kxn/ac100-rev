// func sensor_di_db_pkt_stat_clear @ 004ddf08 size=216

undefined4 sensor_di_db_pkt_stat_clear(undefined4 param_1)

{
  int iVar1;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_pkt_stat_clear ENTER sensor_id=%d\n",
           "sensor_di_db_pkt_stat_clear",0x8a6,param_1);
  }
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
  if (iVar1 == 0) {
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_id=%d not exists_in cached list\n",
             "sensor_di_db_pkt_stat_clear",0x8ad,param_1);
    }
  }
  else {
    _sensor_di_db_sensor_di_data_pkt_stat_free(iVar1,0);
  }
  FUN_00407f30(l_sensor_di_data_mutex);
  return 0;
}

