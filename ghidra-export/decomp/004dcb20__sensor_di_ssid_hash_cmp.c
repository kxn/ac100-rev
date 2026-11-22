// func _sensor_di_ssid_hash_cmp @ 004dcb20 size=132

bool _sensor_di_ssid_hash_cmp(int param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    bVar2 = false;
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input null.\n","_sensor_di_ssid_hash_cmp",0x180);
    }
  }
  else {
    bVar2 = false;
    if ((param_2[0x31] == *(char *)(param_1 + 0x3d)) && (bVar2 = true, param_2[0x31] == '\0')) {
      iVar1 = strcmp((char *)(param_1 + 0xc),param_2);
      bVar2 = iVar1 == 0;
    }
  }
  return bVar2;
}

