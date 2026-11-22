// func _sensor_di_cache_bssid_hash_obj @ 004d7cd4 size=96

undefined4 _sensor_di_cache_bssid_hash_obj(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input null.\n","_sensor_di_cache_bssid_hash_obj",0x16c
            );
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1 + 0xe,6,0);
  return uVar1;
}

