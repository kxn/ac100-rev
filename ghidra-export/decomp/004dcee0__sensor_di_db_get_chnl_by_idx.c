// func _sensor_di_db_get_chnl_by_idx @ 004dcee0 size=152

int _sensor_di_db_get_chnl_by_idx(int param_1,uint param_2)

{
  int iVar1;
  
  param_2 = param_2 & 0xff;
  if (param_2 - 1 < 4) {
    iVar1 = param_1 + 1;
    if (param_2 != 1) {
      iVar1 = param_1 + 9;
      if (param_2 != 2) {
        if (param_2 != 3) {
          return param_1 * 4 + 0x95;
        }
        iVar1 = param_1 + 0x19;
      }
      iVar1 = iVar1 << 2;
    }
  }
  else {
    iVar1 = 0;
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid band = %d\n","_sensor_di_db_get_chnl_by_idx",
             0x7f);
    }
  }
  return iVar1;
}

