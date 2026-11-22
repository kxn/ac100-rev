// func wips_counter_interval @ 004cb68c size=132

void wips_counter_interval(void)

{
  int iVar1;
  
  wips_counter_timeout_check();
  iVar1 = FUN_00408340(600,0,wips_counter_interval,0,0,"wips_counter_interval",0xac);
  if ((iVar1 == -1) && (sensor_err_switch != '\0')) {
    printf("[SENSOR_ERROR]%s()/%d start wips_counter_clear timer error\n","wips_counter_interval",
           0xaf);
    return;
  }
  return;
}

