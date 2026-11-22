// func di_printmac @ 004dcfb4 size=100

void di_printmac(byte *param_1)

{
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : BSSID is=%.2X%.2X%.2X%.2X%.2X%.2X\n","di_printmac",0x702
           ,(uint)*param_1,(uint)param_1[1],(uint)param_1[2],(uint)param_1[3],(uint)param_1[4],
           (uint)param_1[5]);
  }
  return;
}

