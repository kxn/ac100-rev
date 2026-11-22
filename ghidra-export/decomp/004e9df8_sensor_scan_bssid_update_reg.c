// func sensor_scan_bssid_update_reg @ 004e9df8 size=240

undefined4 sensor_scan_bssid_update_reg(int param_1)

{
  void *__s;
  char *__format;
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_ERROR]%s()/%d input error\n";
    uVar1 = 0xc2f;
  }
  else {
    __s = (void *)FUN_00408450(0x10,0xc33);
    if (__s != (void *)0x0) {
      memset(__s,0,0x10);
      *(int *)((int)__s + 0xc) = param_1;
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d insert register entry\n","sensor_scan_bssid_update_reg",0xc3d)
        ;
      }
      FUN_004086b0(&l_scan_bssid_callback_list,__s);
      return 0;
    }
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_ERROR]%s()/%d malloc reg_node error\n";
    uVar1 = 0xc36;
  }
  printf(__format,"sensor_scan_bssid_update_reg",uVar1);
  return 0xffffffff;
}

