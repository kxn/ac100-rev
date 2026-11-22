// func sensor_stats_cb_reg_by_funcname @ 004eaf7c size=196

undefined4 sensor_stats_cb_reg_by_funcname(char *param_1,undefined2 param_2,int param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 local_48;
  char acStack_44 [52];
  
  memset(&local_48,0,0x38);
  if (((param_1 == (char *)0x0) || (sVar1 = strlen(param_1), 0x32 < sVar1)) || (param_3 == 0)) {
    uVar2 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_stats_cb_reg_by_funcname",0x1db);
    }
  }
  else {
    local_48 = 1;
    strcpy(acStack_44,param_1);
    uVar2 = sensor_stats_cb_reg(&local_48,param_2,param_3);
  }
  return uVar2;
}

