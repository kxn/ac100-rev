// func _sensor_test_db_deep_copy_detail_result @ 00502a54 size=744

int * _sensor_test_db_deep_copy_detail_result(int *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int *__s;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d deep_copy_detail_result ENTER\n",
           "_sensor_test_db_deep_copy_detail_result",0xaa7);
  }
  if (param_1 == (int *)0x0) {
    if (sensor_test_debug_switch == '\0') {
      return (int *)0x0;
    }
    pcVar5 = "[SENSOR_TEST_DEBUG]%s()/%d src_detail_result is null\n";
    uVar6 = 0xaad;
LAB_00502b38:
    printf(pcVar5,"_sensor_test_db_deep_copy_detail_result",uVar6);
    return (int *)0x0;
  }
  __s = (int *)FUN_00408450(0xc,0xab2);
  if (__s == (int *)0x0) {
    if (sensor_test_err_switch == '\0') {
      return (int *)0x0;
    }
    pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
    uVar6 = 0xab5;
    goto LAB_00502b38;
  }
  memset(__s,0,0xc);
  bVar1 = *(byte *)(param_1 + 2);
  *(byte *)(__s + 2) = bVar1;
  uVar2 = *(undefined1 *)((int)param_1 + 9);
  __s[1] = 0;
  *__s = 0;
  *(undefined1 *)((int)__s + 9) = uVar2;
  if (bVar1 == 0) {
    bVar1 = *(byte *)((int)__s + 9);
LAB_00502acc:
    if (bVar1 == 0) {
      return __s;
    }
    pvVar3 = (void *)FUN_00408450((uint)bVar1 * 0x14,0xad9);
    __s[1] = (int)pvVar3;
    if (pvVar3 == (void *)0x0) {
      if (sensor_test_err_switch == '\0') goto LAB_00502bf0;
      pcVar5 = 
      "[SENSOR_TEST_ERROR]%s()/%d des_result_unit->detail_result.diagnosis mem malloc fail\n";
      uVar6 = 0xadc;
    }
    else {
      iVar7 = 0;
      memset(pvVar3,0,(uint)*(byte *)((int)__s + 9) * 0x14);
      bVar1 = *(byte *)((int)__s + 9);
      while( true ) {
        if ((int)(uint)bVar1 <= iVar7) {
          return __s;
        }
        iVar4 = _sensor_test_db_deep_copy_stage(__s[1] + iVar7 * 0x14,param_1[1] + iVar7 * 0x14);
        if (iVar4 == -1) break;
        iVar7 = iVar7 + 1;
        bVar1 = *(byte *)((int)__s + 9);
      }
      if (sensor_test_err_switch == '\0') goto LAB_00502bf0;
      pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d deep_copy_stage diagnosis fail\n";
      uVar6 = 0xae5;
    }
  }
  else {
    pvVar3 = (void *)FUN_00408450((uint)bVar1 * 0x14,0xac3);
    *__s = (int)pvVar3;
    if (pvVar3 != (void *)0x0) {
      memset(pvVar3,0,(uint)*(byte *)(__s + 2) * 0x14);
      bVar1 = *(byte *)(__s + 2);
      for (iVar7 = 0; iVar7 < (int)(uint)bVar1; iVar7 = iVar7 + 1) {
        iVar4 = _sensor_test_db_deep_copy_stage(*__s + iVar7 * 0x14,*param_1 + iVar7 * 0x14);
        if (iVar4 == -1) {
          if (sensor_test_err_switch == '\0') goto LAB_00502bf0;
          pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d deep_copy_stage test fail\n";
          uVar6 = 0xacf;
          goto LAB_00502cac;
        }
        bVar1 = *(byte *)(__s + 2);
      }
      bVar1 = *(byte *)((int)__s + 9);
      goto LAB_00502acc;
    }
    if (sensor_test_err_switch == '\0') goto LAB_00502bf0;
    pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d des_result_unit->detail_result.test mem malloc fail\n";
    uVar6 = 0xac6;
  }
LAB_00502cac:
  printf(pcVar5,"_sensor_test_db_deep_copy_detail_result",uVar6);
LAB_00502bf0:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d deep_copy_detail_result fail EXIT\n",
           "_sensor_test_db_deep_copy_detail_result",0xaee);
  }
  sensor_test_db_detail_result_nested_mem_free(__s);
  FUN_00407df0(__s);
  return (int *)0x0;
}

