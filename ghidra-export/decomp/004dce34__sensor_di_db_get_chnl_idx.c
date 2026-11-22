// func _sensor_di_db_get_chnl_idx @ 004dce34 size=172

int _sensor_di_db_get_chnl_idx(int param_1,uint param_2)

{
  int iVar1;
  
  param_2 = param_2 & 0xff;
  if (param_2 - 1 < 4) {
    iVar1 = param_1 + -1;
    if (param_2 != 1) {
      iVar1 = param_1 + -0x24;
      if (param_2 == 2) {
        param_1 = param_1 + -0x21;
      }
      else {
        iVar1 = param_1 + -100;
        if (param_2 == 3) {
          param_1 = param_1 + -0x61;
        }
        else {
          iVar1 = param_1 + -0x95;
          param_1 = param_1 + -0x92;
        }
      }
      if (iVar1 < 0) {
        iVar1 = param_1;
      }
      iVar1 = iVar1 >> 2;
    }
  }
  else {
    iVar1 = -1;
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid band = %d\n","_sensor_di_db_get_chnl_idx",0x60
            );
    }
  }
  return iVar1;
}

