// func sensor_di_db_get_pkt_stat_scantime @ 004e1cbc size=1

int sensor_di_db_get_pkt_stat_scantime(undefined4 param_1,short param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(param_1);
  if (iVar1 != 0) {
    if (*(short *)(iVar1 + 0x1c514) == param_2) {
      iVar3 = *(int *)(iVar1 + 0x1c524);
      iVar2 = *(int *)(iVar1 + 0x1c528);
      iVar1 = *(int *)(iVar1 + 0x1c52c);
      FUN_00407f30(l_sensor_di_data_mutex);
      return iVar3 + iVar2 + iVar1;
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : input sensor_id and chnl unmatch or no pkt_stat\n",
             "sensor_di_db_get_pkt_stat_scantime",0xcb9);
    }
  }
  FUN_00407f30(l_sensor_di_data_mutex);
  return 0;
}

