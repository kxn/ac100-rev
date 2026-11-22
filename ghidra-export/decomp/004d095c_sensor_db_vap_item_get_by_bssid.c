// func sensor_db_vap_item_get_by_bssid @ 004d095c size=184

undefined4 sensor_db_vap_item_get_by_bssid(int param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    uVar1 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_db_vap_item_get_by_bssid",0x2e1);
    }
  }
  else {
    FUN_004082d0(g_sensor_mutex,0xffffffff);
    uVar1 = 0xffffffff;
    __src = (void *)FUN_00407fa0(g_sensor_vap_hash,param_1);
    if (__src != (void *)0x0) {
      uVar1 = 0;
      memcpy(param_2,__src,0x10);
    }
    FUN_00407f30(g_sensor_mutex);
  }
  return uVar1;
}

