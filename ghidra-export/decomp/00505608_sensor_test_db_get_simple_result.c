// func sensor_test_db_get_simple_result @ 00505608 size=3284

void * sensor_test_db_get_simple_result
                 (int param_1,uint param_2,short param_3,uint param_4,uint param_5,int param_6,
                 int param_7,int *param_8,int *param_9)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  undefined4 uVar12;
  void *__s;
  void *pvVar13;
  int local_34;
  
  iVar1 = sensor_test_db_is_test_case_id_legal();
  if (iVar1 == 0) {
    __s = (void *)0x0;
    if (sensor_test_debug_switch == '\0') {
      return (void *)0x0;
    }
    pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d input case_id invalid\n";
    uVar12 = 0x1594;
    goto LAB_0050575c;
  }
  if (8 < param_2) {
    __s = (void *)0x0;
    if (sensor_test_debug_switch == '\0') {
      return (void *)0x0;
    }
    pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d input test_type invalid\n";
    uVar12 = 0x159a;
    goto LAB_0050575c;
  }
  if ((param_8 == (int *)0x0) || (param_9 == (int *)0x0)) {
    __s = (void *)0x0;
    if (sensor_test_debug_switch == '\0') {
      return (void *)0x0;
    }
    pcVar7 = 
    "[SENSOR_TEST_DEBUG]%s()/%d result_num is null  or  total_num is null  or  sch_start_time is 0\n"
    ;
    uVar12 = 0x15a0;
    goto LAB_0050575c;
  }
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  iVar5 = param_1 * 0xc;
  iVar1 = FUN_00407fe0(l_sensor_test_result_list + iVar5);
  if (iVar1 == 0) {
    __s = (void *)0x0;
    FUN_00407f30(l_sensor_test_db_mutex);
    if (sensor_test_debug_switch == '\0') {
      return (void *)0x0;
    }
    pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d no result available\n";
    uVar12 = 0x15a9;
    goto LAB_0050575c;
  }
  FUN_00407f30(l_sensor_test_db_mutex);
  if (param_3 == -1) {
    iVar1 = sensor_test_db_is_test_case_id_legal(param_1);
    uVar12 = l_sensor_test_db_mutex;
    if (iVar1 == 0) {
      if (sensor_test_debug_switch == '\0') goto LAB_005058cc;
      pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d input case_id invalid\n";
      pcVar10 = "_sensor_test_db_get_simple_result_by_test_type";
      uVar12 = 0x88f;
    }
    else {
      *param_9 = 0;
      param_1 = param_1 * 4;
      FUN_004082d0(uVar12,0xffffffff);
      iVar2 = _sensor_test_db_get_config_cnt
                        (*(undefined4 *)(l_sensor_test_case_list + param_1),param_2);
      iVar1 = l_sensor_test_result_list;
      if (iVar2 == 0) {
        if (sensor_test_debug_switch != '\0') {
          pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d config_cnt=0\n";
          pcVar10 = "_sensor_test_db_get_simple_result_by_test_type";
          uVar12 = 0x8ab;
LAB_0050616c:
          printf(pcVar7,pcVar10,uVar12);
        }
LAB_00505e2c:
        __s = (void *)0x0;
        FUN_00407f30(l_sensor_test_db_mutex);
        goto LAB_005058d0;
      }
      *param_8 = 0;
      if (param_6 < 0 || param_7 < param_6) {
        for (iVar1 = FUN_004081b0(iVar1 + iVar5); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
          for (uVar3 = 0; (int)uVar3 < iVar2; uVar3 = uVar3 + 1) {
            iVar8 = _sensor_test_db_get_result_unit_node_num_by_real_idx
                              (iVar1,param_2,uVar3 & 0xffff,param_4,param_5,
                               *(int *)(*(int *)(l_sensor_test_case_list + param_1) + 4) + 0x3c);
            *param_8 = *param_8 + iVar8;
            *param_9 = *param_9 + iVar8;
          }
        }
        if (sensor_test_debug_switch == '\0') {
          iVar1 = *param_8;
        }
        else {
          printf("[SENSOR_TEST_DEBUG]%s()/%d result_num=%d\n",
                 "_sensor_test_db_get_simple_result_by_test_type",0x8f7,*param_8);
          iVar1 = *param_8;
        }
        if (iVar1 != 0) {
          __s = (void *)FUN_00408450(iVar1 * 0x70,0x900);
          if (__s == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              pcVar7 = "_sensor_test_db_get_simple_result_by_test_type";
              uVar12 = 0x903;
LAB_00505ce8:
              printf("[SENSOR_TEST_ERROR]%s()/%d get_simple_result mem malloc result fail\n",pcVar7,
                     uVar12);
            }
          }
          else {
            param_6 = 0;
            memset(__s,0,*param_8 * 0x70);
            iVar1 = *param_8;
LAB_00505e90:
            iVar8 = -1;
            for (iVar5 = FUN_004081b0(l_sensor_test_result_list + iVar5); iVar5 != 0;
                iVar5 = FUN_00408680(iVar5)) {
              uVar3 = 0;
LAB_00505ecc:
              if ((int)uVar3 < iVar2) {
                iVar9 = _sensor_test_db_get_sepcified_list_from_bssid_result_node
                                  (iVar5,param_2 & 0xff,uVar3 & 0xffff);
                if (iVar9 == 0) {
                  uVar3 = uVar3 + 1;
                }
                else {
                  for (iVar9 = FUN_004081b0(iVar9); iVar9 != 0; iVar9 = FUN_00408680(iVar9)) {
                    uVar4 = *(uint *)(iVar9 + 0x2c);
                    if (param_4 <= uVar4) {
                      if (uVar4 < param_5) {
                        iVar8 = iVar8 + 1;
                        if (iVar8 < param_6) {
                          uVar4 = *(uint *)(iVar9 + 0x2c);
                        }
                        else if (iVar1 + -1 < iVar8) {
                          uVar4 = *(uint *)(iVar9 + 0x2c);
                        }
                        else {
                          pvVar13 = (void *)((int)__s + (iVar8 - param_6) * 0x70);
                          *(undefined2 *)((int)pvVar13 + 0x32) = *(undefined2 *)(iVar5 + 0x44);
                          memcpy((void *)((int)pvVar13 + 0x34),(void *)(iVar5 + 0x3e),6);
                          memcpy(pvVar13,(void *)(iVar5 + 0xc),0x32);
                          *(undefined4 *)((int)pvVar13 + 0x68) = *(undefined4 *)(iVar9 + 0x2c);
                          *(undefined2 *)((int)pvVar13 + 0x6c) = *(undefined2 *)(iVar9 + 0x30);
                          *(undefined1 *)((int)pvVar13 + 0x6e) = *(undefined1 *)(iVar9 + 0x32);
                          memcpy((void *)((int)pvVar13 + 0x48),(void *)(iVar9 + 0xc),0x1c);
                          uVar4 = *(uint *)(iVar9 + 0x2c);
                        }
                      }
                      else {
                        uVar4 = *(uint *)(iVar9 + 0x2c);
                      }
                    }
                    if (param_5 < uVar4) {
                      uVar3 = uVar3 + 1;
                      goto LAB_00505ecc;
                    }
                  }
                  uVar3 = uVar3 + 1;
                }
                goto LAB_00505ecc;
              }
            }
          }
LAB_00505cf0:
          FUN_00407f30(l_sensor_test_db_mutex);
          goto LAB_005058d0;
        }
        FUN_00407f30(l_sensor_test_db_mutex);
        if (sensor_test_debug_switch == '\0') goto LAB_005058cc;
        pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d no result available\n";
        pcVar10 = "_sensor_test_db_get_simple_result_by_test_type";
        uVar12 = 0x8fb;
      }
      else {
        iVar1 = FUN_004081b0(iVar1 + iVar5);
        local_34 = -1;
        for (; iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
          uVar3 = 0;
          while ((int)uVar3 < iVar2) {
            iVar8 = _sensor_test_db_get_result_unit_node_num_by_real_idx
                              (iVar1,param_2,uVar3 & 0xffff,param_4,param_5,
                               *(int *)(*(int *)(l_sensor_test_case_list + param_1) + 4) + 0x3c);
            if (iVar8 == 0) {
              uVar3 = uVar3 + 1;
            }
            else {
              iVar9 = local_34;
              for (iVar6 = 0; iVar9 = iVar9 + 1, iVar6 < iVar8; iVar6 = iVar6 + 1) {
                if (iVar9 < param_6) {
                  iVar11 = *param_9;
                }
                else if (*param_8 < (param_7 - param_6) + 1) {
                  *param_8 = *param_8 + 1;
                  iVar11 = *param_9;
                }
                else {
                  iVar11 = *param_9;
                }
                *param_9 = iVar11 + 1;
              }
              if (iVar8 < 0) {
                iVar8 = 0;
              }
              local_34 = local_34 + iVar8;
              uVar3 = uVar3 + 1;
            }
          }
        }
        if (sensor_test_debug_switch == '\0') {
          iVar1 = *param_8;
        }
        else {
          printf("[SENSOR_TEST_DEBUG]%s()/%d result_num=%d\n",
                 "_sensor_test_db_get_simple_result_by_test_type",0x8d1,*param_8);
          iVar1 = *param_8;
        }
        if (iVar1 != 0) {
          __s = (void *)FUN_00408450(iVar1 * 0x70,0x8da);
          if (__s != (void *)0x0) {
            memset(__s,0,*param_8 * 0x70);
            iVar1 = param_6 + *param_8;
            goto LAB_00505e90;
          }
          if (sensor_test_err_switch != '\0') {
            pcVar7 = "_sensor_test_db_get_simple_result_by_test_type";
            uVar12 = 0x8dd;
            goto LAB_00505ce8;
          }
          goto LAB_00505cf0;
        }
        FUN_00407f30(l_sensor_test_db_mutex);
        if (sensor_test_debug_switch == '\0') goto LAB_005058cc;
        pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d no result available\n";
        pcVar10 = "_sensor_test_db_get_simple_result_by_test_type";
        uVar12 = 0x8d5;
      }
    }
LAB_00505a30:
    __s = (void *)0x0;
    printf(pcVar7,pcVar10,uVar12);
  }
  else {
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_simple_result_by_serindex ENTER\n",
             "_sensor_test_db_get_simple_result_by_serindex",0x7aa);
    }
    iVar1 = sensor_test_db_is_test_case_id_legal(param_1);
    uVar12 = l_sensor_test_db_mutex;
    if (iVar1 == 0) {
      if (sensor_test_debug_switch == '\0') {
LAB_005058cc:
        __s = (void *)0x0;
        goto LAB_005058d0;
      }
      pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d input case_id invalid\n";
      pcVar10 = "_sensor_test_db_get_simple_result_by_serindex";
      uVar12 = 0x7bc;
      goto LAB_00505a30;
    }
    if (param_3 < 0) {
      if (sensor_test_debug_switch == '\0') goto LAB_005058cc;
      pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d input test_type or ser_index invalid\n";
      pcVar10 = "_sensor_test_db_get_simple_result_by_serindex";
      uVar12 = 0x7c2;
      goto LAB_00505a30;
    }
    param_1 = param_1 * 4;
    *param_9 = 0;
    FUN_004082d0(uVar12,0xffffffff);
    iVar2 = _sensor_test_db_get_config_cnt
                      (*(undefined4 *)(l_sensor_test_case_list + param_1),param_2);
    iVar1 = l_sensor_test_result_list;
    if (iVar2 == 0) {
      if (sensor_test_debug_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d config_cnt=0\n";
        pcVar10 = "_sensor_test_db_get_simple_result_by_serindex";
        uVar12 = 0x7d9;
        goto LAB_0050616c;
      }
      goto LAB_00505e2c;
    }
    *param_8 = 0;
    if (param_6 < 0 || param_7 < param_6) {
      for (iVar1 = FUN_004081b0(iVar1 + iVar5); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        iVar2 = _sensor_test_db_get_result_unit_node_num_by_serindex
                          (iVar1,param_2,param_3,param_4,param_5,
                           *(int *)(*(int *)(l_sensor_test_case_list + param_1) + 4) + 0x3c);
        *param_8 = *param_8 + iVar2;
        *param_9 = *param_9 + iVar2;
      }
      if (sensor_test_debug_switch == '\0') {
        iVar1 = *param_8;
      }
      else {
        printf("[SENSOR_TEST_DEBUG]%s()/%d result_num=%d\n",
               "_sensor_test_db_get_simple_result_by_serindex",0x81d,*param_8);
        iVar1 = *param_8;
      }
      if (iVar1 != 0) {
        __s = (void *)FUN_00408450(iVar1 * 0x70,0x826);
        if (__s == (void *)0x0) {
          if (sensor_test_err_switch != '\0') {
            pcVar7 = "_sensor_test_db_get_simple_result_by_serindex";
            uVar12 = 0x829;
            goto LAB_00505ce8;
          }
        }
        else {
          iVar2 = -1;
          param_6 = 0;
          memset(__s,0,*param_8 * 0x70);
          iVar1 = *param_8;
LAB_00505b40:
          iVar5 = FUN_004081b0(l_sensor_test_result_list + iVar5);
          for (; iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
            if ((*(int *)(l_sensor_test_case_list + param_1) == 0) ||
               (iVar8 = *(int *)(*(int *)(l_sensor_test_case_list + param_1) + 4), iVar8 == 0)) {
              if (sensor_test_err_switch == '\0') goto LAB_00505e2c;
              pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d case_ptr or setting is null\n";
              pcVar10 = "_sensor_test_db_get_simple_result_by_serindex";
              uVar12 = 0x845;
              goto LAB_0050616c;
            }
            uVar3 = _sensor_test_db_get_idx_of_serindex(iVar8 + 0x3c,param_2,param_3);
            if (uVar3 == 0xffffffff) {
              if (sensor_test_err_switch == '\0') goto LAB_00505e2c;
              pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d get index of serindex fail\n";
              pcVar10 = "_sensor_test_db_get_simple_result_by_serindex";
              uVar12 = 0x84c;
              goto LAB_0050616c;
            }
            iVar8 = _sensor_test_db_get_sepcified_list_from_bssid_result_node
                              (iVar5,param_2 & 0xff,uVar3 & 0xffff);
            if (iVar8 != 0) {
              iVar8 = FUN_004081b0(iVar8);
              for (; iVar8 != 0; iVar8 = FUN_00408680(iVar8)) {
                uVar3 = *(uint *)(iVar8 + 0x2c);
                if (param_4 <= uVar3) {
                  if (uVar3 < param_5) {
                    iVar2 = iVar2 + 1;
                    if (iVar2 < param_6) {
                      uVar3 = *(uint *)(iVar8 + 0x2c);
                    }
                    else if (iVar1 + -1 < iVar2) {
                      uVar3 = *(uint *)(iVar8 + 0x2c);
                    }
                    else {
                      pvVar13 = (void *)((int)__s + (iVar2 - param_6) * 0x70);
                      *(undefined2 *)((int)pvVar13 + 0x32) = *(undefined2 *)(iVar5 + 0x44);
                      memcpy((void *)((int)pvVar13 + 0x34),(void *)(iVar5 + 0x3e),6);
                      memcpy(pvVar13,(void *)(iVar5 + 0xc),0x32);
                      *(undefined4 *)((int)pvVar13 + 0x68) = *(undefined4 *)(iVar8 + 0x2c);
                      *(undefined2 *)((int)pvVar13 + 0x6c) = *(undefined2 *)(iVar8 + 0x30);
                      *(undefined1 *)((int)pvVar13 + 0x6e) = *(undefined1 *)(iVar8 + 0x32);
                      memcpy((void *)((int)pvVar13 + 0x48),(void *)(iVar8 + 0xc),0x1c);
                      uVar3 = *(uint *)(iVar8 + 0x2c);
                    }
                  }
                  else {
                    uVar3 = *(uint *)(iVar8 + 0x2c);
                  }
                }
                if (param_5 <= uVar3) break;
              }
            }
          }
        }
        goto LAB_00505cf0;
      }
      __s = (void *)0x0;
      FUN_00407f30(l_sensor_test_db_mutex);
      if (sensor_test_debug_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d no result available\n";
        pcVar10 = "_sensor_test_db_get_simple_result_by_serindex";
        uVar12 = 0x821;
        goto LAB_00505a30;
      }
    }
    else {
      iVar2 = -1;
      for (iVar1 = FUN_004081b0(iVar1 + iVar5); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        iVar8 = _sensor_test_db_get_result_unit_node_num_by_serindex
                          (iVar1,param_2,param_3,param_4,param_5,
                           *(int *)(*(int *)(l_sensor_test_case_list + param_1) + 4) + 0x3c);
        if (iVar8 != 0) {
          iVar9 = iVar2;
          for (iVar6 = 0; iVar6 < iVar8; iVar6 = iVar6 + 1) {
            iVar9 = iVar9 + 1;
            if (iVar9 < param_6) {
              iVar11 = *param_9;
            }
            else if (*param_8 < (param_7 - param_6) + 1) {
              *param_8 = *param_8 + 1;
              iVar11 = *param_9;
            }
            else {
              iVar11 = *param_9;
            }
            *param_9 = iVar11 + 1;
          }
          if (iVar8 < 0) {
            iVar8 = 0;
          }
          iVar2 = iVar2 + iVar8;
        }
      }
      if (sensor_test_debug_switch == '\0') {
        iVar1 = *param_8;
      }
      else {
        printf("[SENSOR_TEST_DEBUG]%s()/%d result_num=%d\n",
               "_sensor_test_db_get_simple_result_by_serindex",0x7f9,*param_8);
        iVar1 = *param_8;
      }
      if (iVar1 != 0) {
        __s = (void *)FUN_00408450(iVar1 * 0x70,0x802);
        if (__s != (void *)0x0) {
          memset(__s,0,*param_8 * 0x70);
          iVar1 = param_6 + *param_8;
          goto LAB_00505b40;
        }
        if (sensor_test_err_switch != '\0') {
          pcVar7 = "_sensor_test_db_get_simple_result_by_serindex";
          uVar12 = 0x805;
          goto LAB_00505ce8;
        }
        goto LAB_00505cf0;
      }
      __s = (void *)0x0;
      FUN_00407f30(l_sensor_test_db_mutex);
      if (sensor_test_debug_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d no result available\n";
        pcVar10 = "_sensor_test_db_get_simple_result_by_serindex";
        uVar12 = 0x7fd;
        goto LAB_00505a30;
      }
    }
  }
LAB_005058d0:
  if (sensor_test_debug_switch == '\0') {
    return __s;
  }
  pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_simple_result success EXIT\n";
  uVar12 = 0x15b9;
LAB_0050575c:
  printf(pcVar7,"sensor_test_db_get_simple_result",uVar12);
  return __s;
}

