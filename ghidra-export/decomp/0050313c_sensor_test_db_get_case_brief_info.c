// func sensor_test_db_get_case_brief_info @ 0050313c size=620

undefined4 sensor_test_db_get_case_brief_info(uint param_1,undefined2 *param_2)

{
  byte bVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_case_brief_info ENTER,case_id=%d\n",
           "sensor_test_db_get_case_brief_info",0xfef,param_1);
  }
  if (g_sensor_test_case_num_max <= param_1) {
    return 0xffffffff;
  }
  if ((int)param_1 < 0) {
    return 0xffffffff;
  }
  if (param_2 == (undefined2 *)0x0) {
    return 0xffffffff;
  }
  iVar4 = param_1 * 4;
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  piVar2 = (int *)(l_sensor_test_case_list + iVar4);
  if (*piVar2 == 0) {
    FUN_00407f30(l_sensor_test_db_mutex);
    return 0xffffffff;
  }
  bVar1 = *(byte *)(*(int *)(*piVar2 + 4) + 9);
  param_2[4] = (ushort)bVar1;
  *param_2 = **(undefined2 **)(*piVar2 + 4);
  param_2[1] = *(undefined2 *)(*(int *)(*piVar2 + 4) + 2);
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(*(int *)(*piVar2 + 4) + 4);
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)(*(int *)(*piVar2 + 4) + 10);
  *(undefined1 *)((int)param_2 + 0xb) = *(undefined1 *)(*(int *)(*piVar2 + 4) + 0xb);
  if (*(char *)(*(int *)(*piVar2 + 4) + 9) == '\0') {
    bVar1 = *(byte *)(param_2 + 5);
LAB_00503238:
    if (bVar1 != 0) {
      pvVar3 = (void *)FUN_00408450((uint)bVar1 << 2,0x100c);
      *(void **)(param_2 + 6) = pvVar3;
      if (pvVar3 == (void *)0x0) {
        if (sensor_test_err_switch != '\0') {
          uVar5 = 0x100f;
          goto LAB_00503374;
        }
        goto LAB_00503318;
      }
      memcpy(pvVar3,*(void **)(*(int *)(*(int *)(l_sensor_test_case_list + iVar4) + 4) + 0x34),
             (uint)*(byte *)(param_2 + 5) << 2);
    }
    uVar5 = 0;
    FUN_00407f30(l_sensor_test_db_mutex);
  }
  else {
    pvVar3 = (void *)FUN_00408450((uint)bVar1 << 1,0x1000);
    *(void **)(param_2 + 8) = pvVar3;
    if (pvVar3 != (void *)0x0) {
      memcpy(pvVar3,*(void **)(*(int *)(*(int *)(l_sensor_test_case_list + iVar4) + 4) + 0x30),
             (uint)(ushort)param_2[4] << 1);
      bVar1 = *(byte *)(param_2 + 5);
      goto LAB_00503238;
    }
    if (sensor_test_err_switch != '\0') {
      uVar5 = 0x1003;
LAB_00503374:
      printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n","sensor_test_db_get_case_brief_info",
             uVar5);
    }
LAB_00503318:
    FUN_00407f30(l_sensor_test_db_mutex);
    if (*(int *)(param_2 + 8) == 0) {
      iVar4 = *(int *)(param_2 + 6);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_2 + 8) = 0;
      iVar4 = *(int *)(param_2 + 6);
    }
    uVar5 = 0xffffffff;
    if (iVar4 != 0) {
      FUN_00407df0();
      *(undefined4 *)(param_2 + 6) = 0;
    }
  }
  return uVar5;
}

