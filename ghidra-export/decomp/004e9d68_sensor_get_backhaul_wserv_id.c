// func sensor_get_backhaul_wserv_id @ 004e9d68 size=72

undefined4 sensor_get_backhaul_wserv_id(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  uVar1 = g_backhaul_wserv_id;
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar1;
}

