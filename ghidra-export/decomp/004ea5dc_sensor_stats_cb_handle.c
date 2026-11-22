// func sensor_stats_cb_handle @ 004ea5dc size=224

int sensor_stats_cb_handle(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar1 = -1;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","sensor_stats_cb_handle",0xf4,
           "(NULL != key) && (NULL != stats_data)");
  }
  else {
    iVar1 = FUN_00407fa0(sensor_cb_hash,param_1);
    if (iVar1 == 0) {
      iVar1 = -1;
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d Nothing to do\n","sensor_stats_cb_handle",0xfa);
      }
    }
    else {
      for (iVar1 = FUN_004081b0(iVar1 + 0x38); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
          (**(code **)(iVar1 + 0x10))(param_2);
        }
      }
    }
  }
  return iVar1;
}

