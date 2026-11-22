// func _sensor_test_calc_total_test_round @ 004eb31c size=76

int _sensor_test_calc_total_test_round(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = 0;
  if ((param_1 <= param_3) && (iVar1 = 1, 0 < param_2)) {
    uVar3 = param_2 * 0x3c;
    if (uVar3 == 0) {
      trap(7);
    }
    iVar2 = (param_3 - param_1) / uVar3 + (uint)((param_3 - param_1) % uVar3 != 0);
    iVar1 = 10;
    if (iVar2 < 0xb) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

