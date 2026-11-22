// func _sensor_test_insert_serv_id_into_list @ 004f4bc4 size=188

void _sensor_test_insert_serv_id_into_list(int param_1,uint param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != -1) {
    iVar1 = *param_3;
    if (((-1 < iVar1) && (iVar1 < 300)) && (param_4 != (int *)0x0)) {
      if (iVar1 == 0) {
        *param_4 = param_1;
      }
      else {
        iVar3 = 0;
        piVar2 = param_4;
        do {
          if (param_1 == *piVar2) {
            piVar2[1] = piVar2[1] | param_2;
            return;
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 2;
        } while (iVar3 < iVar1);
        param_4[iVar1 * 2] = param_1;
      }
      param_4[*param_3 * 2 + 1] = param_2;
      *param_3 = *param_3 + 1;
      return;
    }
  }
  if (sensor_test_warning_switch == '\0') {
    return;
  }
  printf("[SENSOR_TEST_WARNING]%s()/%d input invalid, no handle\n",
         "_sensor_test_insert_serv_id_into_list",0x212);
  return;
}

