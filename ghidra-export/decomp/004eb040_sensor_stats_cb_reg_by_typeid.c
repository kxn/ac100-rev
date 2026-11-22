// func sensor_stats_cb_reg_by_typeid @ 004eb040 size=152

undefined4 sensor_stats_cb_reg_by_typeid(undefined4 param_1,undefined2 param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 auStack_48 [4];
  undefined4 local_44;
  
  memset(auStack_48,0,0x38);
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_stats_cb_reg_by_typeid",0x1ea);
    }
  }
  else {
    local_44 = param_1;
    uVar1 = sensor_stats_cb_reg(auStack_48,param_2,param_3);
  }
  return uVar1;
}

