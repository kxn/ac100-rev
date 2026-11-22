// func _sensor_test_db_deep_copy_test_case_setting @ 00500fa4 size=2208

undefined2 * _sensor_test_db_deep_copy_test_case_setting(undefined2 *param_1)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 *__s;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_db_deep_copy_test_case_setting ENTER\n",
           "_sensor_test_db_deep_copy_test_case_setting",0xbcf);
  }
  if (param_1 == (undefined2 *)0x0) {
    __s = (undefined2 *)0x0;
    if (sensor_test_err_switch == '\0') {
      return (undefined2 *)0x0;
    }
    pcVar6 = "[SENSOR_TEST_ERROR]%s()/%d src_setting is NULL\n";
    uVar7 = 0xbd4;
    goto LAB_005011a8;
  }
  __s = (undefined2 *)FUN_00408450(0x5c,0xbd8);
  if (__s == (undefined2 *)0x0) {
    if (sensor_test_err_switch == '\0') {
      return (undefined2 *)0x0;
    }
    pcVar6 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
    uVar7 = 0xbdb;
    goto LAB_005011a8;
  }
  memset(__s,0,0x5c);
  *__s = *param_1;
  __s[1] = param_1[1];
  *(undefined4 *)(__s + 2) = *(undefined4 *)(param_1 + 2);
  *(undefined1 *)(__s + 4) = *(undefined1 *)(param_1 + 4);
  *(undefined1 *)(__s + 6) = *(undefined1 *)(param_1 + 6);
  *(undefined1 *)((int)__s + 9) = *(undefined1 *)((int)param_1 + 9);
  *(undefined1 *)(__s + 5) = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)((int)__s + 0xb) = *(undefined1 *)((int)param_1 + 0xb);
  strncpy((char *)((int)__s + 0xd),(char *)((int)param_1 + 0xd),0x20);
  if (*(byte *)((int)param_1 + 9) == 0) {
    bVar2 = *(byte *)(param_1 + 5);
LAB_00501064:
    if (bVar2 == 0) {
      bVar2 = *(byte *)((int)param_1 + 0xb);
    }
    else {
      pvVar4 = (void *)FUN_00408450((uint)bVar2 << 2,0xbf7);
      *(void **)(__s + 0x1a) = pvVar4;
      if (pvVar4 == (void *)0x0) {
        if (sensor_test_err_switch == '\0') goto LAB_00501594;
        pcVar6 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
        uVar7 = 0xbfa;
        goto LAB_005015f0;
      }
      memcpy(pvVar4,*(void **)(param_1 + 0x1a),(uint)*(byte *)(param_1 + 5) << 2);
      bVar2 = *(byte *)((int)param_1 + 0xb);
    }
    if (bVar2 != 0) {
      pvVar4 = (void *)FUN_00408450((uint)bVar2 * 0x220,0xc02);
      *(void **)(__s + 0x1c) = pvVar4;
      if (pvVar4 == (void *)0x0) {
        if (sensor_test_err_switch == '\0') goto LAB_00501594;
        pcVar6 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
        uVar7 = 0xc05;
        goto LAB_005015f0;
      }
      memcpy(pvVar4,*(void **)(param_1 + 0x1c),(uint)*(byte *)((int)param_1 + 0xb) * 0x220);
    }
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d deep_copy_test_case_setting_service ENTER\n",
             "_sensor_test_db_deep_copy_test_case_setting_service",0xb20);
    }
    memset(__s + 0x1e,0,0x20);
    uVar3 = param_1[0x1e];
    bVar1 = sensor_test_debug_switch != '\0';
    __s[0x1e] = uVar3;
    if (bVar1) {
      printf("[SENSOR_TEST_DEBUG]%s()/%d src_service->service_type=%d\n",
             "_sensor_test_db_deep_copy_test_case_setting_service",0xb2b,(uint)(ushort)param_1[0x1e]
            );
    }
    if ((uVar3 & 1) != 0) {
      __s[0x1f] = param_1[0x1f];
    }
    if ((uVar3 & 2) != 0) {
      *(undefined4 *)(__s + 0x20) = 0;
      pvVar4 = (void *)FUN_00408450(0x102,0xb35);
      *(void **)(__s + 0x20) = pvVar4;
      if (pvVar4 != (void *)0x0) {
        memset(pvVar4,0,0x102);
        memcpy(*(void **)(__s + 0x20),*(void **)(param_1 + 0x20),0x102);
        goto LAB_005010f0;
      }
      if (sensor_test_err_switch != '\0') {
        uVar7 = 0xb39;
        goto LAB_005016c8;
      }
      goto LAB_00501654;
    }
LAB_005010f0:
    if ((uVar3 & 4) == 0) {
LAB_005010fc:
      if ((uVar3 & 8) != 0) {
        *(undefined4 *)(__s + 0x24) = 0;
        pvVar4 = (void *)FUN_00408450(0x38c,0xb5c);
        *(void **)(__s + 0x24) = pvVar4;
        if (pvVar4 == (void *)0x0) {
          if (sensor_test_err_switch == '\0') goto LAB_00501654;
          uVar7 = 0xb60;
          goto LAB_005016c8;
        }
        memset(pvVar4,0,0x38c);
        memcpy(*(void **)(__s + 0x24),*(void **)(param_1 + 0x24),0x38c);
      }
      if ((uVar3 & 0x10) == 0) {
LAB_00501110:
        if ((uVar3 & 0x20) != 0) {
          *(undefined4 *)(__s + 0x28) = 0;
          pvVar4 = (void *)FUN_00408450(8,0xb86);
          *(void **)(__s + 0x28) = pvVar4;
          if (pvVar4 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              uVar7 = 0xb8a;
              goto LAB_005016c8;
            }
            goto LAB_00501654;
          }
          memset(pvVar4,0,8);
          if (**(int **)(param_1 + 0x28) != 0) {
            **(int **)(__s + 0x28) = **(int **)(param_1 + 0x28);
            *(undefined4 *)(*(int *)(__s + 0x28) + 4) = 0;
            piVar8 = *(int **)(__s + 0x28);
            iVar5 = FUN_00408450(*piVar8 * 0x104,0xb93);
            piVar8[1] = iVar5;
            pvVar4 = (void *)(*(int **)(__s + 0x28))[1];
            if (pvVar4 == (void *)0x0) {
              if (sensor_test_err_switch != '\0') {
                uVar7 = 0xb96;
                goto LAB_005016c8;
              }
              goto LAB_00501654;
            }
            memcpy(pvVar4,*(void **)(*(int *)(param_1 + 0x28) + 4),**(int **)(__s + 0x28) * 0x104);
          }
        }
        if ((uVar3 & 0x40) != 0) {
          *(undefined4 *)(__s + 0x2a) = 0;
          pvVar4 = (void *)FUN_00408450(8,0xba0);
          *(void **)(__s + 0x2a) = pvVar4;
          if (pvVar4 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              uVar7 = 0xba4;
              goto LAB_005016c8;
            }
            goto LAB_00501654;
          }
          memset(pvVar4,0,8);
          if (**(int **)(param_1 + 0x2a) != 0) {
            **(int **)(__s + 0x2a) = **(int **)(param_1 + 0x2a);
            *(undefined4 *)(*(int *)(__s + 0x2a) + 4) = 0;
            piVar8 = *(int **)(__s + 0x2a);
            iVar5 = FUN_00408450(*piVar8 * 0xa8e,0xbad);
            piVar8[1] = iVar5;
            pvVar4 = (void *)(*(int **)(__s + 0x2a))[1];
            if (pvVar4 == (void *)0x0) {
              if (sensor_test_err_switch != '\0') {
                uVar7 = 0xbb0;
                goto LAB_005016c8;
              }
              goto LAB_00501654;
            }
            memcpy(pvVar4,*(void **)(*(int *)(param_1 + 0x2a) + 4),**(int **)(__s + 0x2a) * 0xa8e);
          }
        }
        if ((uVar3 & 0x80) != 0) {
          *(undefined4 *)(__s + 0x2c) = 0;
          pvVar4 = (void *)FUN_00408450(0x804,0xbba);
          *(void **)(__s + 0x2c) = pvVar4;
          if (pvVar4 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              uVar7 = 0xbbe;
              goto LAB_005016c8;
            }
            goto LAB_00501654;
          }
          memset(pvVar4,0,0x804);
          memcpy(*(void **)(__s + 0x2c),*(void **)(param_1 + 0x2c),0x804);
        }
        if (sensor_test_debug_switch == '\0') {
          return __s;
        }
        pcVar6 = 
        "[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_db_deep_copy_test_case_setting success EXIT\n";
        uVar7 = 0xc11;
LAB_005011a8:
        printf(pcVar6,"_sensor_test_db_deep_copy_test_case_setting",uVar7);
        return __s;
      }
      *(undefined4 *)(__s + 0x26) = 0;
      pvVar4 = (void *)FUN_00408450(8,0xb6b);
      *(void **)(__s + 0x26) = pvVar4;
      if (pvVar4 != (void *)0x0) {
        memset(pvVar4,0,8);
        if (**(int **)(param_1 + 0x26) != 0) {
          **(int **)(__s + 0x26) = **(int **)(param_1 + 0x26);
          *(undefined4 *)(*(int *)(__s + 0x26) + 4) = 0;
          piVar8 = *(int **)(__s + 0x26);
          iVar5 = FUN_00408450(*piVar8 * 0x28c,0xb78);
          piVar8[1] = iVar5;
          pvVar4 = (void *)(*(int **)(__s + 0x26))[1];
          if (pvVar4 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              uVar7 = 0xb7b;
              goto LAB_005016c8;
            }
            goto LAB_00501654;
          }
          memcpy(pvVar4,*(void **)(*(int *)(param_1 + 0x26) + 4),**(int **)(__s + 0x26) * 0x28c);
        }
        goto LAB_00501110;
      }
      if (sensor_test_err_switch != '\0') {
        uVar7 = 0xb6f;
        goto LAB_005016c8;
      }
    }
    else {
      *(undefined4 *)(__s + 0x22) = 0;
      pvVar4 = (void *)FUN_00408450(8,0xb43);
      *(void **)(__s + 0x22) = pvVar4;
      if (pvVar4 != (void *)0x0) {
        memset(pvVar4,0,8);
        if (**(int **)(param_1 + 0x22) != 0) {
          **(int **)(__s + 0x22) = **(int **)(param_1 + 0x22);
          *(undefined4 *)(*(int *)(__s + 0x22) + 4) = 0;
          piVar8 = *(int **)(__s + 0x22);
          iVar5 = FUN_00408450(*piVar8 * 0x102,0xb4f);
          piVar8[1] = iVar5;
          pvVar4 = (void *)(*(int **)(__s + 0x22))[1];
          if (pvVar4 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              uVar7 = 0xb52;
              goto LAB_005016c8;
            }
            goto LAB_00501654;
          }
          memcpy(pvVar4,*(void **)(*(int *)(param_1 + 0x22) + 4),**(int **)(__s + 0x22) * 0x102);
        }
        goto LAB_005010fc;
      }
      if (sensor_test_err_switch == '\0') goto LAB_00501654;
      uVar7 = 0xb47;
LAB_005016c8:
      printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",
             "_sensor_test_db_deep_copy_test_case_setting_service",uVar7);
    }
LAB_00501654:
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d deep_copy_test_case_setting_service fail EXIT\n",
             "_sensor_test_db_deep_copy_test_case_setting_service",0xbc8);
    }
    sensor_test_db_service_nested_mem_free(__s + 0x1e);
    if (sensor_test_err_switch == '\0') goto LAB_00501594;
    pcVar6 = "[SENSOR_TEST_ERROR]%s()/%d deep_copy_service fail\n";
    uVar7 = 0xc0d;
  }
  else {
    pvVar4 = (void *)FUN_00408450((uint)*(byte *)((int)param_1 + 9) << 1,0xbec);
    *(void **)(__s + 0x18) = pvVar4;
    if (pvVar4 != (void *)0x0) {
      memcpy(pvVar4,*(void **)(param_1 + 0x18),(uint)*(byte *)((int)param_1 + 9) << 1);
      bVar2 = *(byte *)(param_1 + 5);
      goto LAB_00501064;
    }
    if (sensor_test_err_switch == '\0') goto LAB_00501594;
    pcVar6 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
    uVar7 = 0xbef;
  }
LAB_005015f0:
  printf(pcVar6,"_sensor_test_db_deep_copy_test_case_setting",uVar7);
LAB_00501594:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d _sensor_test_db_deep_copy_test_case_setting fail EXIT\n",
           "_sensor_test_db_deep_copy_test_case_setting",0xc15);
  }
  sensor_test_db_case_setting_mem_free(__s);
  return (undefined2 *)0x0;
}

