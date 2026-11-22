// func _sensor_di_sta_hash_cmp @ 004dcab4 size=108

bool _sensor_di_sta_hash_cmp(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    bVar2 = false;
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input null.\n","_sensor_di_sta_hash_cmp",0x1e4);
    }
  }
  else {
    iVar1 = memcmp((void *)(param_1 + 0xc),param_2,6);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

