// func uac_sensor_init @ 004c5b48 size=316

int uac_sensor_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = sensor_mngt_init();
  if (iVar1 == 0) {
    iVar1 = sensor_pkt_init();
    if (iVar1 == 0) {
      iVar1 = sensor_test_init();
      if (iVar1 == 0) {
        iVar1 = sensor_di_init();
        if (iVar1 == 0) {
          iVar1 = wips_init();
          if (iVar1 != 0) {
            return iVar1;
          }
          apmngr_support_capacity_register(0x34);
          udbg_help_register("sensor","sensor_debug_help()");
          return 0;
        }
        if (sensor_err_switch == '\0') {
          return iVar1;
        }
        __format = "[SENSOR_ERROR]%s()/%d sensor_di_init failed\n";
        uVar2 = 0x78;
      }
      else {
        if (sensor_err_switch == '\0') {
          return iVar1;
        }
        __format = "[SENSOR_ERROR]%s()/%d sensor_test_init failed\n";
        uVar2 = 0x72;
      }
    }
    else {
      if (sensor_err_switch == '\0') {
        return iVar1;
      }
      __format = "[SENSOR_ERROR]%s()/%d sensor_pkt_init failed\n";
      uVar2 = 0x6c;
    }
  }
  else {
    if (sensor_err_switch == '\0') {
      return iVar1;
    }
    __format = "[SENSOR_ERROR]%s()/%d sensor_mngt_init failed\n";
    uVar2 = 0x66;
  }
  printf(__format,"uac_sensor_init",uVar2);
  return iVar1;
}

