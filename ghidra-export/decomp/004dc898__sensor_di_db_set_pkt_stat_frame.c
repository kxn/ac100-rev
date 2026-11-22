// func _sensor_di_db_set_pkt_stat_frame @ 004dc898 size=224

undefined4
_sensor_di_db_set_pkt_stat_frame(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  if ((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
     ((param_4 == (int *)0x0 || (param_5 == (int *)0x0)))) {
    uVar5 = 0xffffffff;
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : input invalid\n","_sensor_di_db_set_pkt_stat_frame",
             0x1f5);
    }
  }
  else {
    iVar4 = 0;
    *param_1 = 0;
    *param_2 = 0;
    do {
      iVar4 = iVar4 + 1;
      *param_1 = *param_1 + *param_3 + *param_4 + *param_5;
      piVar1 = param_3 + 1;
      param_3 = param_3 + 0x1a;
      piVar2 = param_4 + 1;
      param_4 = param_4 + 0x10;
      piVar3 = param_5 + 1;
      param_5 = param_5 + 0xc;
      *param_2 = *param_2 + *piVar1 + *piVar2 + *piVar3;
    } while (iVar4 != 3);
    uVar5 = 0;
  }
  return uVar5;
}

