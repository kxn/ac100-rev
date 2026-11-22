// func sensor_test_db_set_result @ 005079a0 size=1348

undefined4 sensor_test_db_set_result(int param_1,void *param_2,void *param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  time_t tVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  void *__dest;
  int iVar9;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_set_result ENTER\n",
           "sensor_test_db_set_result",0x13cb);
  }
  if ((param_2 == (void *)0x0) || (param_3 == (void *)0x0)) {
    __dest = (void *)0x0;
    if (sensor_test_err_switch == '\0') goto LAB_00507cb0;
    pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d input invalid\n";
    uVar8 = 0x13d8;
  }
  else {
    iVar2 = sensor_test_db_is_test_case_id_legal(param_1);
    if (iVar2 != 0) {
      param_1 = param_1 * 4;
      FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
      printmac((int)param_2 + 0x34);
      iVar2 = FUN_00407fa0(*(undefined4 *)(l_sensor_test_result_list_hash + param_1),
                           (int)param_2 + 0x34);
      if (iVar2 == 0) {
        if (sensor_test_err_switch != '\0') {
          pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d hash get bssid_result_node fail\n";
          uVar8 = 0x13e8;
LAB_00507e14:
          printf(pcVar7,"sensor_test_db_set_result",uVar8);
        }
      }
      else {
        *(undefined2 *)(iVar2 + 0x44) = *(undefined2 *)((int)param_2 + 0x32);
        memcpy((void *)(iVar2 + 0xc),param_2,0x32);
        if ((*(int *)(l_sensor_test_case_list + param_1) == 0) ||
           (iVar6 = *(int *)(*(int *)(l_sensor_test_case_list + param_1) + 4), iVar6 == 0)) {
          if (sensor_test_err_switch != '\0') {
            pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d case_ptr or setting is null\n";
            uVar8 = 0x13f5;
            goto LAB_00507e14;
          }
        }
        else {
          uVar3 = _sensor_test_db_get_idx_of_serindex
                            (iVar6 + 0x3c,*(undefined1 *)((int)param_3 + 0x32),
                             *(undefined2 *)((int)param_3 + 0x30));
          if (uVar3 == 0xffffffff) {
            if (sensor_test_err_switch != '\0') {
              pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d get index of serindex fail\n";
              uVar8 = 0x13fc;
              goto LAB_00507e14;
            }
          }
          else {
            iVar2 = _sensor_test_db_get_sepcified_list_from_bssid_result_node
                              (iVar2,*(undefined1 *)((int)param_3 + 0x32),uVar3 & 0xffff);
            if (iVar2 != 0) {
              if (sensor_test_debug_switch != '\0') {
                printf("[SENSOR_TEST_DEBUG]%s()/%d deep_copy_test_unit_result ENTER\n",
                       "_sensor_test_db_deep_copy_test_unit_result",0xafa);
              }
              __dest = (void *)FUN_00408450(0x34,0xb04);
              if (__dest == (void *)0x0) {
                if (sensor_test_err_switch != '\0') {
                  printf("[SENSOR_TEST_ERROR]%s()/%d des_result_unit mem malloc fail\n",
                         "_sensor_test_db_deep_copy_test_unit_result",0xb07);
                }
                if (sensor_test_err_switch != '\0') {
                  printf("[SENSOR_TEST_ERROR]%s()/%d deep_copy_test_unit_result fail EXIT\n",
                         "_sensor_test_db_deep_copy_test_unit_result",0xb18);
                }
                sensor_test_db_result_unit_node_mem_free(0);
                if (sensor_test_err_switch != '\0') {
                  pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d deep_copy_test_unit_result fail\n";
                  uVar8 = 0x140e;
LAB_00507d14:
                  printf(pcVar7,"sensor_test_db_set_result",uVar8);
                }
              }
              else {
                memcpy(__dest,param_3,0x34);
                if (0x96 < (byte)(*(char *)((int)__dest + 0x25) + 0x78U)) {
                  *(undefined1 *)((int)__dest + 0x25) = 0x80;
                }
                *(undefined4 *)((int)__dest + 0x28) = 0;
                uVar8 = _sensor_test_db_deep_copy_detail_result
                                  (*(undefined4 *)((int)param_3 + 0x28));
                *(undefined4 *)((int)__dest + 0x28) = uVar8;
                iVar6 = FUN_00407fe0(iVar2);
                if (iVar6 < 1) {
LAB_00507be8:
                  FUN_004086b0(iVar2,__dest);
                  FUN_00407f30(l_sensor_test_db_mutex);
                  if (sensor_test_debug_switch == '\0') {
                    return 0;
                  }
                  printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_set_result success EXIT\n",
                         "sensor_test_db_set_result",0x145b);
                  return 0;
                }
                iVar9 = 0;
                if (0x14 < iVar6) {
                  for (; iVar9 < iVar6 + -0x14; iVar9 = iVar9 + 1) {
                    iVar5 = FUN_004081b0(iVar2);
                    if (iVar5 == 0) {
                      if (sensor_test_err_switch == '\0') goto LAB_00507ca4;
                      pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d get first node fail\n";
                      uVar8 = 0x1427;
                      goto LAB_00507d14;
                    }
                    FUN_00408500(iVar5);
                    sensor_test_db_result_unit_node_mem_free(iVar5);
                  }
                }
                iVar6 = FUN_00408610(iVar2);
                if (iVar6 != 0) {
                  if (*(int *)(iVar6 + 0x28) != 0) {
                    sensor_test_db_detail_result_nested_mem_free();
                    FUN_00407df0(*(undefined4 *)(iVar6 + 0x28));
                    *(undefined4 *)(iVar6 + 0x28) = 0;
                  }
                  iVar6 = *(int *)(*(int *)(l_sensor_test_case_list + param_1) + 4);
                  sVar1 = *(short *)(iVar6 + 2);
                  uVar8 = *(undefined4 *)(iVar6 + 4);
                  tVar4 = time((time_t *)0x0);
                  uVar3 = sensor_test_db_calc_aging_timestamp(uVar8,(int)sVar1,tVar4,10);
                  iVar6 = FUN_004081b0(iVar2);
                  while ((iVar6 != 0 &&
                         (iVar9 = FUN_00408680(iVar6), *(uint *)(iVar6 + 0x2c) < uVar3))) {
                    FUN_00408500(iVar6);
                    sensor_test_db_result_unit_node_mem_free(iVar6);
                    iVar6 = iVar9;
                  }
                  goto LAB_00507be8;
                }
                if (sensor_test_err_switch != '\0') {
                  pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d get last node fail\n";
                  uVar8 = 0x1436;
                  goto LAB_00507d14;
                }
              }
LAB_00507ca4:
              FUN_00407f30(l_sensor_test_db_mutex);
              goto LAB_00507cb0;
            }
            if (sensor_test_err_switch != '\0') {
              pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d get config_list from bssid result node fail\n";
              uVar8 = 0x1404;
              goto LAB_00507e14;
            }
          }
        }
      }
      __dest = (void *)0x0;
      FUN_00407f30(l_sensor_test_db_mutex);
      goto LAB_00507cb0;
    }
    __dest = (void *)0x0;
    if (sensor_test_err_switch == '\0') goto LAB_00507cb0;
    pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d case id illegal\n";
    uVar8 = 0x13df;
  }
  __dest = (void *)0x0;
  printf(pcVar7,"sensor_test_db_set_result",uVar8);
LAB_00507cb0:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d sensor_test_db_set_result fail EXIT\n",
           "sensor_test_db_set_result",0x145f);
  }
  sensor_test_db_result_unit_node_mem_free(__dest);
  return 0xffffffff;
}

