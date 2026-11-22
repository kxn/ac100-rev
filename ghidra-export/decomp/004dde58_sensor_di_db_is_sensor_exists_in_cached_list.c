// func sensor_di_db_is_sensor_exists_in_cached_list @ 004dde58 size=176

undefined4 sensor_di_db_is_sensor_exists_in_cached_list(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar1 = FUN_004081b0(&l_sensor_di_cached_sensor_list);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0xc);
    while (param_1 != iVar2) {
      iVar1 = FUN_00408680(iVar1);
      if (iVar1 == 0) {
        uVar3 = 0;
        goto LAB_004ddeb8;
      }
      iVar2 = *(int *)(iVar1 + 0xc);
    }
    uVar3 = 1;
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : find sensor exists in cached list.\n",
             "sensor_di_db_is_sensor_exists_in_cached_list",0x89b);
    }
  }
LAB_004ddeb8:
  FUN_00407f30(l_sensor_di_data_mutex);
  return uVar3;
}

