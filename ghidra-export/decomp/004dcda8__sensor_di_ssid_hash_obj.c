// func _sensor_di_ssid_hash_obj @ 004dcda8 size=140

undefined4 _sensor_di_ssid_hash_obj(int param_1)

{
  undefined4 uVar1;
  char *__s;
  size_t sVar2;
  
  if (param_1 == 0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input null.\n","_sensor_di_ssid_hash_obj",0x16f);
    }
    return 0;
  }
  if (*(char *)(param_1 + 0x3d) == '\0') {
    __s = (char *)(param_1 + 0xc);
    sVar2 = strlen(__s);
  }
  else {
    __s = (char *)(param_1 + 0x3d);
    sVar2 = 1;
  }
  uVar1 = FUN_004083d0(__s,sVar2,0);
  return uVar1;
}

