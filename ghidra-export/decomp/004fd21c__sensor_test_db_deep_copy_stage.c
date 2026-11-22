// func _sensor_test_db_deep_copy_stage @ 004fd21c size=944

undefined4 _sensor_test_db_deep_copy_stage(undefined2 *param_1,undefined2 *param_2)

{
  byte bVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  char *__format;
  undefined4 uVar8;
  void *__dest;
  
  if (param_2 == (undefined2 *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == (undefined2 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  bVar1 = *(byte *)((int)param_2 + 0x11);
  *(byte *)((int)param_1 + 0x11) = bVar1;
  *(undefined1 *)(param_1 + 9) = *(undefined1 *)(param_2 + 9);
  *(undefined1 *)((int)param_1 + 0x13) = *(undefined1 *)((int)param_2 + 0x13);
  if (bVar1 == 0) {
    bVar1 = *(byte *)(param_1 + 9);
LAB_004fd284:
    if (bVar1 == 0) {
      bVar1 = *(byte *)((int)param_1 + 0x13);
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0;
      pvVar2 = (void *)FUN_00408450((uint)bVar1 << 4,0xa5b);
      *(void **)(param_1 + 4) = pvVar2;
      if (pvVar2 == (void *)0x0) {
        if (sensor_test_err_switch == '\0') {
          iVar3 = *(int *)(param_1 + 2);
          goto LAB_004fd490;
        }
        __format = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
        uVar8 = 0xa5e;
        goto LAB_004fd508;
      }
      memset(pvVar2,0,(uint)*(byte *)(param_1 + 9) << 4);
      for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(param_1 + 9); iVar3 = iVar3 + 1) {
        if ((*(int *)(param_2 + 4) == 0) || (*(int *)(param_1 + 4) == 0)) {
          if (sensor_test_err_switch == '\0') {
            iVar3 = *(int *)(param_1 + 2);
            goto LAB_004fd490;
          }
          __format = "[SENSOR_TEST_ERROR]%s()/%d deep_copy_onboarding_data_type fail\n";
          uVar8 = 0xa66;
          goto LAB_004fd508;
        }
        puVar4 = (undefined4 *)(*(int *)(param_1 + 4) + iVar3 * 0x10);
        puVar6 = (undefined4 *)(*(int *)(param_2 + 4) + iVar3 * 0x10);
        *puVar4 = *puVar6;
        puVar4[1] = puVar6[1];
        puVar4[2] = puVar6[2];
        *(undefined1 *)(puVar4 + 3) = *(undefined1 *)(puVar6 + 3);
      }
      bVar1 = *(byte *)((int)param_1 + 0x13);
    }
    if (bVar1 == 0) {
LAB_004fd29c:
      if (sensor_test_debug_switch == '\0') {
        return 0;
      }
      printf("[SENSOR_TEST_DEBUG]%s()/%d deep_copy_stage success\n",
             "_sensor_test_db_deep_copy_stage",0xa82);
      return 0;
    }
    *(undefined4 *)(param_1 + 6) = 0;
    pvVar2 = (void *)FUN_00408450((uint)bVar1 << 3,0xa70);
    *(void **)(param_1 + 6) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,(uint)*(byte *)((int)param_1 + 0x13) << 3);
      for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)((int)param_1 + 0x13); iVar3 = iVar3 + 1) {
        if ((*(int *)(param_2 + 6) == 0) || (*(int *)(param_1 + 6) == 0)) {
          if (sensor_test_err_switch == '\0') {
            iVar3 = *(int *)(param_1 + 2);
            goto LAB_004fd490;
          }
          __format = "[SENSOR_TEST_ERROR]%s()/%d deep_copy_speed_data_type fail\n";
          uVar8 = 0xa7c;
          goto LAB_004fd508;
        }
        puVar5 = (undefined2 *)(*(int *)(param_1 + 6) + iVar3 * 8);
        puVar7 = (undefined2 *)(*(int *)(param_2 + 6) + iVar3 * 8);
        *puVar5 = *puVar7;
        puVar5[1] = puVar7[1];
        puVar5[2] = puVar7[2];
        puVar5[3] = puVar7[3];
      }
      goto LAB_004fd29c;
    }
    if (sensor_test_err_switch == '\0') {
      iVar3 = *(int *)(param_1 + 2);
      goto LAB_004fd490;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
    uVar8 = 0xa73;
  }
  else {
    *(undefined4 *)(param_1 + 2) = 0;
    pvVar2 = (void *)FUN_00408450((uint)bVar1 * 0x1c,0xa47);
    *(void **)(param_1 + 2) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,(uint)*(byte *)((int)param_1 + 0x11) * 0x1c);
      for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)((int)param_1 + 0x11); iVar3 = iVar3 + 1) {
        if ((*(int *)(param_2 + 2) == 0) || (*(int *)(param_1 + 2) == 0)) {
          if (sensor_test_err_switch == '\0') {
            iVar3 = *(int *)(param_1 + 2);
            goto LAB_004fd490;
          }
          __format = "[SENSOR_TEST_ERROR]%s()/%d deep_copy_common_data_type fail\n";
          uVar8 = 0xa52;
          goto LAB_004fd508;
        }
        __dest = (void *)(*(int *)(param_1 + 2) + iVar3 * 0x1c);
        pvVar2 = (void *)(*(int *)(param_2 + 2) + iVar3 * 0x1c);
        memcpy(__dest,pvVar2,0x14);
        *(undefined4 *)((int)__dest + 0x14) = *(undefined4 *)((int)pvVar2 + 0x14);
        *(undefined2 *)((int)__dest + 0x18) = *(undefined2 *)((int)pvVar2 + 0x18);
      }
      bVar1 = *(byte *)(param_1 + 9);
      goto LAB_004fd284;
    }
    if (sensor_test_err_switch == '\0') {
      iVar3 = *(int *)(param_1 + 2);
      goto LAB_004fd490;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
    uVar8 = 0xa4a;
  }
LAB_004fd508:
  printf(__format,"_sensor_test_db_deep_copy_stage",uVar8);
  iVar3 = *(int *)(param_1 + 2);
LAB_004fd490:
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 4);
  }
  else {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 2) = 0;
    *(undefined1 *)((int)param_1 + 0x11) = 0;
    iVar3 = *(int *)(param_1 + 4);
  }
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 6);
  }
  else {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 9) = 0;
    iVar3 = *(int *)(param_1 + 6);
  }
  if (iVar3 != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 0x13) = 0;
  }
  return 0xffffffff;
}

