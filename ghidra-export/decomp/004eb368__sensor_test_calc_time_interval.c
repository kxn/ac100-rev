// func _sensor_test_calc_time_interval @ 004eb368 size=224

void _sensor_test_calc_time_interval
               (uint param_1,int param_2,uint param_3,int param_4,uint *param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_5 != (uint *)0x0) && (param_6 != (uint *)0x0)) {
    if (param_3 < param_1) {
      *param_5 = param_1;
      *param_6 = param_1;
    }
    else if (param_2 < 1) {
      *param_5 = param_1;
      *param_6 = param_3;
    }
    else {
      uVar2 = param_2 * 0x3c;
      iVar1 = _sensor_test_calc_total_test_round();
      *param_5 = param_3;
      if (uVar2 == 0) {
        trap(7);
      }
      uVar3 = (param_3 - param_1) % uVar2;
      if (iVar1 <= param_4) {
        param_4 = iVar1;
      }
      if (uVar3 != 0) {
        param_4 = param_4 + -1;
        *param_5 = param_3 - uVar3;
      }
      if (param_4 == 0) {
        *param_6 = param_3;
      }
      else {
        uVar3 = *param_5 - param_4 * uVar2;
        *param_5 = uVar3;
        *param_6 = uVar3 + uVar2;
      }
    }
  }
  return;
}

