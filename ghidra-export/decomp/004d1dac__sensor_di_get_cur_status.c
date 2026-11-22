// func _sensor_di_get_cur_status @ 004d1dac size=72

int _sensor_di_get_cur_status(void)

{
  int iVar1;
  
  FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
  iVar1 = (int)l_sensor_di_status._2_2_;
  FUN_00407f30(l_sensor_di_status_mutex);
  return iVar1;
}

