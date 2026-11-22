// func _sensor_di_sta_hash_obj @ 004dcc00 size=96

undefined4 _sensor_di_sta_hash_obj(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input null.\n","_sensor_di_sta_hash_obj",0x1d6);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1 + 0xc,6,0);
  return uVar1;
}

