// func senosr_test_db_set_case_start_time @ 005033a8 size=172

undefined4 senosr_test_db_set_case_start_time(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  short *psVar3;
  
  uVar1 = 0xffffffff;
  if ((-1 < (int)param_1) && (param_1 <= g_sensor_test_case_num_max)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    iVar2 = *(int *)(l_sensor_test_case_list + param_1 * 4);
    if ((iVar2 == 0) || (psVar3 = *(short **)(iVar2 + 4), psVar3 == (short *)0x0)) {
      FUN_00407f30(l_sensor_test_db_mutex);
      uVar1 = 0xffffffff;
    }
    else {
      if (*psVar3 == 0) {
        *(undefined4 *)(psVar3 + 2) = param_2;
      }
      FUN_00407f30(l_sensor_test_db_mutex);
      uVar1 = 0;
    }
  }
  return uVar1;
}

