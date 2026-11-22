// func FUN_004e3340 @ 004e3340 size=164

undefined4 FUN_004e3340(byte *param_1,char *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (byte *)0x0) || (param_2 == (char *)0x0)) {
    uVar1 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_bssid_str_transfer",0xed);
    }
  }
  else {
    uVar1 = 0;
    snprintf(param_2,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,(uint)param_1[1],
             (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  }
  return uVar1;
}

