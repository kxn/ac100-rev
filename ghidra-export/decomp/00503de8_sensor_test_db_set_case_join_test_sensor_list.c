// func sensor_test_db_set_case_join_test_sensor_list @ 00503de8 size=444

undefined4 sensor_test_db_set_case_join_test_sensor_list(uint param_1,void *param_2,byte param_3)

{
  undefined4 uVar1;
  int iVar2;
  void *__dest;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar1 = 0xffffffff;
  uVar5 = (uint)param_3;
  if (((-1 < (int)param_1) && (param_1 <= g_sensor_test_case_num_max)) &&
     ((uVar5 == 0 || (param_2 != (void *)0x0)))) {
    iVar3 = param_1 * 4;
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    if ((*(int *)(l_sensor_test_case_list + iVar3) != 0) &&
       (iVar2 = *(int *)(*(int *)(l_sensor_test_case_list + iVar3) + 4), iVar2 != 0)) {
      if (uVar5 == 0) {
        if (*(int *)(iVar2 + 0x34) != 0) {
          FUN_00407df0();
          piVar4 = (int *)(l_sensor_test_case_list + iVar3);
          *(undefined4 *)(*(int *)(*piVar4 + 4) + 0x34) = 0;
          *(undefined1 *)(*(int *)(*piVar4 + 4) + 10) = 0;
        }
      }
      else {
        __dest = (void *)FUN_00408450(uVar5 << 2,0x117f);
        if (__dest == (void *)0x0) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",
                   "sensor_test_db_set_case_join_test_sensor_list",0x1183);
          }
          FUN_00407f30(l_sensor_test_db_mutex);
          return 0xffffffff;
        }
        memcpy(__dest,param_2,uVar5 << 2);
        if (*(int *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar3) + 4) + 0x34) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar3) + 4) + 0x34) = 0;
        }
        piVar4 = (int *)(l_sensor_test_case_list + iVar3);
        *(void **)(*(int *)(*piVar4 + 4) + 0x34) = __dest;
        *(byte *)(*(int *)(*piVar4 + 4) + 10) = param_3;
      }
    }
    FUN_00407f30(l_sensor_test_db_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

