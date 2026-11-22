// func sensor_get_default_backhaul_wserv_id @ 004e9db0 size=72

undefined4 sensor_get_default_backhaul_wserv_id(void)

{
  undefined4 uVar1;
  
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  uVar1 = g_dft_backhaul_wserv_id;
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar1;
}

