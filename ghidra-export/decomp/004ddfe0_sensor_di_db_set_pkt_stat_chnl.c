// func sensor_di_db_set_pkt_stat_chnl @ 004ddfe0 size=232

undefined4 sensor_di_db_set_pkt_stat_chnl(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_pkt_stat_chnl ENTER sensor_id=%d, chnl=%d\n"
           ,"sensor_di_db_set_pkt_stat_chnl",0x8ba,param_1,param_2);
  }
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
  uVar2 = l_sensor_di_data_mutex;
  if (iVar1 == 0) {
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_id=%d not exists_in cached list\n",
             "sensor_di_db_set_pkt_stat_chnl",0x8c2,param_1);
      uVar2 = l_sensor_di_data_mutex;
    }
  }
  else {
    *(short *)(iVar1 + 0x1c514) = (short)param_2;
  }
  FUN_00407f30(uVar2);
  return 0;
}

