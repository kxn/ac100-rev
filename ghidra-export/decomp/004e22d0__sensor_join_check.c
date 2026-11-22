// func _sensor_join_check @ 004e22d0 size=92

bool _sensor_join_check(int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = true;
  if ((((allow_sensor_join_direct == 0) && (*(int *)(param_1 + 0x14) == 7)) &&
      (*(int *)(param_1 + 0x3c) == 0)) && ((bVar1 = false, param_2 != 0 && (g_sensor_enable != 0))))
  {
    return g_sensor_state == 1;
  }
  return bVar1;
}

