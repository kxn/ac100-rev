// func sensor_test_db_is_sensor_available @ 005067a4 size=1

undefined4 sensor_test_db_is_sensor_available(short param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  undefined4 uVar6;
  
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  iVar1 = 0;
  piVar2 = l_sensor_test_case_list;
  if (g_sensor_test_case_num_max == 0) {
    uVar6 = 1;
  }
  else {
    do {
      if ((((iVar1 != param_2) && (*piVar2 != 0)) && (iVar3 = *(int *)(*piVar2 + 4), iVar3 != 0)) &&
         ((*(byte *)(iVar3 + 10) != 0 &&
          (psVar5 = *(short **)(iVar3 + 0x34), psVar5 != (short *)0x0)))) {
        iVar4 = 0;
        do {
          iVar4 = iVar4 + 1;
          if (*psVar5 == param_1) {
            uVar6 = 0;
            goto code_r0x00506858;
          }
          psVar5 = psVar5 + 2;
        } while (iVar4 < (int)(uint)*(byte *)(iVar3 + 10));
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 != g_sensor_test_case_num_max);
    uVar6 = 1;
  }
code_r0x00506858:
  FUN_00407f30(l_sensor_test_db_mutex);
  return uVar6;
}

