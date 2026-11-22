// func sensor_is_bh_testing @ 004e9fd8 size=152

bool sensor_is_bh_testing(uint param_1)

{
  bool bVar1;
  
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  bVar1 = false;
  if (((g_sensor_enable != 0) && (g_sensor_state == 3)) && (unfinished_sensor_id_map != 0)) {
    bVar1 = *(short *)(unfinished_sensor_id_map + ((param_1 & 0xffff) - 50000) * 2) != -1;
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  return bVar1;
}

