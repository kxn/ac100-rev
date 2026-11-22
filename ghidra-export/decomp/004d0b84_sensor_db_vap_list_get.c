// func sensor_db_vap_list_get @ 004d0b84 size=368

undefined4 sensor_db_vap_list_get(uint param_1,void *param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1 = param_1 & 0xffff;
  if ((((param_1 < 50000) || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= (int)param_1)) ||
      (param_2 == (void *)0x0)) || ((param_4 == (int *)0x0 || (param_3 < 1)))) {
    uVar2 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_db_vap_list_get",0x307);
    }
  }
  else {
    FUN_004082d0(g_sensor_mutex,0xffffffff);
    iVar1 = g_sensor_entry_array + param_1 * 0x18 + -1200000;
    if (*(char *)(iVar1 + 2) == '\0') {
      if (sensor_warning_switch != '\0') {
        printf("[SENSOR_WARNING]%s()/%d Entry id %d is not used\n","sensor_db_vap_list_get",0x30d,
               param_1);
      }
      uVar2 = 0xffffffff;
      FUN_00407f30(g_sensor_mutex);
    }
    else {
      if (*(short *)(iVar1 + 0xe) < param_3) {
        param_3 = (int)*(short *)(iVar1 + 0xe);
      }
      *param_4 = param_3;
      if (0 < param_3) {
        memcpy(param_2,*(void **)(iVar1 + 0x14),param_3 * 0xc);
      }
      uVar2 = 0;
      FUN_00407f30(g_sensor_mutex);
    }
  }
  return uVar2;
}

