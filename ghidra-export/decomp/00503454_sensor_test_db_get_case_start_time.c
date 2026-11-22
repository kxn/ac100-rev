// func sensor_test_db_get_case_start_time @ 00503454 size=212

undefined4 sensor_test_db_get_case_start_time(uint param_1,undefined4 *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = 0xffffffff;
  if ((((-1 < (int)param_1) && (param_1 <= g_sensor_test_case_num_max)) &&
      (param_2 != (undefined4 *)0x0)) && (param_3 != (undefined2 *)0x0)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    uVar1 = l_sensor_test_db_mutex;
    piVar3 = (int *)(l_sensor_test_case_list + param_1 * 4);
    iVar2 = *piVar3;
    if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 4), iVar2 == 0)) {
      FUN_00407f30(l_sensor_test_db_mutex);
      uVar1 = 0xffffffff;
    }
    else {
      *param_2 = *(undefined4 *)(iVar2 + 4);
      *param_3 = *(undefined2 *)(*(int *)(*piVar3 + 4) + 2);
      FUN_00407f30(uVar1);
      uVar1 = 0;
    }
  }
  return uVar1;
}

