// func _sensor_di_db_sort_array_by_ascending_order @ 004dc510 size=92

undefined4
_sensor_di_db_sort_array_by_ascending_order(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = 0xffffffff;
  if (((param_3 < param_4) && (-1 < param_3)) && (param_2 != 0)) {
    piVar3 = (int *)(param_2 + param_3 * 4);
    *piVar3 = param_1;
    if (param_3 != 0) {
      do {
        iVar2 = piVar3[-1];
        param_3 = param_3 + -1;
        if (*piVar3 < iVar2) {
          piVar3[-1] = *piVar3;
          *piVar3 = iVar2;
        }
        piVar3 = piVar3 + -1;
      } while (param_3 != 0);
    }
    uVar1 = 0;
  }
  return uVar1;
}

