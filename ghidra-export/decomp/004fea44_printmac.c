// func printmac @ 004fea44 size=100

void printmac(byte *param_1)

{
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d BSSID is=%.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n","printmac",0xd4e,
           (uint)*param_1,(uint)param_1[1],(uint)param_1[2],(uint)param_1[3],(uint)param_1[4],
           (uint)param_1[5]);
  }
  return;
}

