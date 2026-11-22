// func sensor_status_change_cb_reg @ 004e9ee8 size=1

undefined4 sensor_status_change_cb_reg(int param_1)

{
  void *__s;
  char *__format;
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_ERROR]%s()/%d input error\n";
    uVar1 = 0xc51;
  }
  else {
    __s = (void *)FUN_00408450(0x10,0xc55);
    if (__s != (void *)0x0) {
      memset(__s,0,0x10);
      *(int *)((int)__s + 0xc) = param_1;
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d insert register entry\n","sensor_status_change_cb_reg",0xc5f);
      }
      FUN_004086b0(&l_status_change_callback_list,__s);
      return 0;
    }
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_ERROR]%s()/%d malloc reg_node error\n";
    uVar1 = 0xc58;
  }
  printf(__format,"sensor_status_change_cb_reg",uVar1);
  return 0xffffffff;
}

