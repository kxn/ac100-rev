// func sensor_backhaul_delete_test @ 004e9300 size=1

undefined4 sensor_backhaul_delete_test(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sensor_backhaul_set(param_1 & 0xffff,1,0,0);
  uVar2 = 0;
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, sensor_err_switch != '\0')) {
    printf("[SENSOR_ERROR]%s()/%d Sensor_backhaul_set failed for sensor %d\n",
           "sensor_backhaul_delete_test",0xb4b,param_1 & 0xffff);
  }
  return uVar2;
}

