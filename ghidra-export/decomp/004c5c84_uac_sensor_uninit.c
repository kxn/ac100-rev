// func uac_sensor_uninit @ 004c5c84 size=36

void uac_sensor_uninit(void)

{
  sensor_mngt_uninit();
  sensor_test_uinit();
  wips_uninit();
  return;
}

