// func _sensor_di_ssid_hash_key @ 004dcd1c size=140

undefined4 _sensor_di_ssid_hash_key(char *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  
  if (param_1 == (char *)0x0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input null.\n","_sensor_di_ssid_hash_key",0x15e);
    }
    return 0;
  }
  if (param_1[0x31] == '\0') {
    sVar2 = strlen(param_1);
  }
  else {
    param_1 = param_1 + 0x31;
    sVar2 = 1;
  }
  uVar1 = FUN_004083d0(param_1,sVar2,0);
  return uVar1;
}

