// func _sensor_di_get_cur_running_time @ 004d1f20 size=108

int _sensor_di_get_cur_running_time(void)

{
  short extraout_v1;
  int iVar1;
  
  FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
  FUN_00407e70();
  iVar1 = (int)(short)(extraout_v1 - DAT_007685dc._2_2_);
  if (iVar1 < 0x259) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 600;
  }
  FUN_00407f30(l_sensor_di_status_mutex);
  return iVar1;
}

