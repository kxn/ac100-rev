// func _sensor_di_sta_hash_key @ 004dcba4 size=92

undefined4 _sensor_di_sta_hash_key(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input null.\n","_sensor_di_sta_hash_key",0x1c8);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1,6,0);
  return uVar1;
}

