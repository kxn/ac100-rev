// func sensor_test_db_get_case_id_list_by_sensor @ 0050704c size=348

undefined4 sensor_test_db_get_case_id_list_by_sensor(short param_1,int param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  undefined4 uVar8;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_case_id_list_by_sensor ENTER\n",
           "sensor_test_db_get_case_id_list_by_sensor",0x1687);
  }
  if ((param_2 == 0) || (param_3 == (uint *)0x0)) {
    uVar8 = 0xffffffff;
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d input invalid\n",
             "sensor_test_db_get_case_id_list_by_sensor",0x168f);
    }
  }
  else {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    uVar2 = 0;
    piVar4 = l_sensor_test_case_list;
    for (uVar3 = 0; uVar1 = l_sensor_test_db_mutex, uVar3 < g_sensor_test_case_num_max;
        uVar3 = uVar3 + 1) {
      if (((*piVar4 != 0) && (iVar5 = *(int *)(*piVar4 + 4), iVar5 != 0)) &&
         (*(byte *)(iVar5 + 10) != 0)) {
        psVar7 = *(short **)(iVar5 + 0x34);
        iVar6 = 0;
        if (psVar7 != (short *)0x0) {
          do {
            iVar6 = iVar6 + 1;
            if ((*psVar7 == param_1) && (uVar2 < g_sensor_test_case_num_max)) {
              iVar5 = uVar2 * 4;
              uVar2 = uVar2 + 1;
              *(uint *)(param_2 + iVar5) = uVar3;
              break;
            }
            psVar7 = psVar7 + 2;
          } while (iVar6 < (int)(uint)*(byte *)(iVar5 + 10));
        }
      }
      piVar4 = piVar4 + 1;
    }
    uVar8 = 0;
    *param_3 = uVar2;
    FUN_00407f30(uVar1);
  }
  return uVar8;
}

