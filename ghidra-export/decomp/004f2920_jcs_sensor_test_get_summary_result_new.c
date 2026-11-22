// func jcs_sensor_test_get_summary_result_new @ 004f2920 size=3164

void jcs_sensor_test_get_summary_result_new(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  FILE *__s;
  undefined8 uVar14;
  short local_360 [2];
  undefined4 local_35c;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  uint local_34c;
  ushort local_348;
  char acStack_344 [100];
  char acStack_2e0 [256];
  undefined4 local_1e0 [100];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  time_t local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_get_summary_result_new ENTER\n",
           "jcs_sensor_test_get_summary_result_new",0x16d2);
  }
  local_34c = 0;
  local_348 = 0;
  local_350 = 0xffffffff;
  memset(local_1e0,0,400);
  memset(acStack_344,0,100);
  local_354 = 0;
  local_360[0] = 0;
  local_358 = 0;
  local_35c = 0;
  iVar1 = json_object_object_get(param_1,"test_case_id");
  local_4c = 0;
  iVar2 = local_4c;
  if ((iVar1 != 0) &&
     ((iVar2 = json_object_get_type(iVar1), iVar2 == 5 ||
      ((iVar3 = json_object_get_type(iVar1), iVar2 = local_4c, iVar3 == 4 &&
       (iVar3 = json_object_object_length(iVar1), iVar2 = local_4c, iVar3 == 0)))))) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      puVar13 = local_1e0;
      for (iVar2 = 0; iVar3 = json_object_array_length(iVar1), iVar2 < iVar3; iVar2 = iVar2 + 1) {
        if (iVar2 == 100) {
          local_4c = 100;
          iVar2 = local_4c;
          break;
        }
        iVar3 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar3 == 0) {
LAB_004f3124:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_sensor_test_get_summary_result_new",0x16f7);
          }
          *puVar13 = 0xffffffff;
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            uVar10 = json_object_get_int(iVar3);
            *puVar13 = uVar10;
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_004f3124;
            uVar14 = json_object_get_double(iVar3);
            uVar10 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
            *puVar13 = uVar10;
          }
        }
        puVar13 = puVar13 + 1;
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 4) {
        iVar1 = json_object_object_length(iVar1);
        local_4c = 0;
        iVar2 = local_4c;
        if (iVar1 == 0) goto LAB_004f29e8;
      }
      local_4c = 0;
      iVar2 = local_4c;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "jcs_sensor_test_get_summary_result_new",0x16f7);
        iVar2 = local_4c;
      }
    }
  }
LAB_004f29e8:
  local_4c = iVar2;
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d n=%d\n","jcs_sensor_test_get_summary_result_new",0x16fa,
           local_4c);
  }
  local_44 = json_object_new_object();
  if (local_44 == 0) {
    if (sensor_test_err_switch == '\0') {
      uVar10 = 1;
    }
    else {
      printf("[SENSOR_TEST_ERROR]%s()/%d ret_obj create fail\n",
             "jcs_sensor_test_get_summary_result_new",0x1700);
      uVar10 = 1;
    }
    goto LAB_004f2e98;
  }
  local_50 = json_object_new_array();
  if (local_50 == 0) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d case_list_obj create fail\n",
             "jcs_sensor_test_get_summary_result_new",0x1707);
    }
    pcVar12 = (char *)0x0;
    __s = (FILE *)0x0;
    iVar7 = 0;
    iVar6 = 0;
    iVar5 = 0;
    iVar4 = 0;
    iVar3 = 0;
    iVar1 = 0;
    iVar2 = 0;
  }
  else {
    puVar13 = local_1e0;
    local_38 = time((time_t *)0x0);
    for (local_40 = 0; local_40 < local_4c; local_40 = local_40 + 1) {
      iVar2 = json_object_new_object();
      if (iVar2 != 0) {
        iVar1 = json_object_new_array();
        if (iVar1 == 0) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d type_list_obj create fail\n",
                   "jcs_sensor_test_get_summary_result_new",0x1719);
          }
        }
        else {
          uVar10 = *puVar13;
          iVar3 = sensor_test_db_get_case_start_time(uVar10,&local_354,local_360);
          if (iVar3 != -1) {
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d case_start_time=%d, case_period=%d\n",
                     "jcs_sensor_test_get_summary_result_new",0x1723,local_354,(int)local_360[0]);
            }
            local_3c = 1;
            if (local_360[0] != 0) {
              local_3c = _sensor_test_calc_total_test_round(local_354,(int)local_360[0],local_38);
            }
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d case_id=%d, test_round=%d\n",
                     "jcs_sensor_test_get_summary_result_new",0x172c,uVar10,local_3c);
            }
            local_30 = sensor_test_db_get_case_service_type(uVar10);
            uVar11 = 0;
            local_48 = iVar2;
            do {
              if ((local_30 >> (uVar11 & 0x1f) & 1U) != 0) {
                iVar3 = json_object_new_object();
                iVar2 = local_48;
                if (iVar3 == 0) {
                  if (sensor_test_err_switch != '\0') {
                    printf("[SENSOR_TEST_ERROR]%s()/%d type_item_obj create fail\n",
                           "jcs_sensor_test_get_summary_result_new",0x1739);
                  }
                  pcVar12 = (char *)0x0;
                  __s = (FILE *)0x0;
                  iVar7 = 0;
                  iVar6 = 0;
                  iVar5 = 0;
                  iVar4 = 0;
                }
                else {
                  iVar4 = json_object_new_array();
                  iVar2 = local_48;
                  if (iVar4 == 0) {
                    if (sensor_test_err_switch != '\0') {
                      printf("[SENSOR_TEST_ERROR]%s()/%d time_array_obj create fail\n",
                             "jcs_sensor_test_get_summary_result_new",0x1740);
                    }
                    pcVar12 = (char *)0x0;
                    __s = (FILE *)0x0;
                    iVar7 = 0;
                    iVar6 = 0;
                    iVar5 = 0;
                  }
                  else {
                    iVar5 = json_object_new_array();
                    iVar2 = local_48;
                    if (iVar5 == 0) {
                      if (sensor_test_err_switch != '\0') {
                        printf("[SENSOR_TEST_ERROR]%s()/%d success_array_obj create fail\n",
                               "jcs_sensor_test_get_summary_result_new",0x1747);
                      }
                      pcVar12 = (char *)0x0;
                      __s = (FILE *)0x0;
                      iVar7 = 0;
                      iVar6 = 0;
                    }
                    else {
                      iVar6 = json_object_new_array();
                      iVar2 = local_48;
                      if (iVar6 == 0) {
                        if (sensor_test_err_switch != '\0') {
                          printf("[SENSOR_TEST_ERROR]%s()/%d fail_array_obj create fail\n",
                                 "jcs_sensor_test_get_summary_result_new",0x174e);
                        }
                        pcVar12 = (char *)0x0;
                        __s = (FILE *)0x0;
                        iVar7 = 0;
                      }
                      else {
                        iVar7 = json_object_new_array();
                        if (iVar7 == 0) {
                          if (sensor_test_err_switch == '\0') {
LAB_004f3228:
                            pcVar12 = (char *)0x0;
                            __s = (FILE *)0x0;
                            iVar2 = local_48;
                            goto LAB_004f2de8;
                          }
                          pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d slow_array_obj create fail\n";
                          uVar10 = 0x1755;
                        }
                        else {
                          local_34 = json_object_new_array();
                          if (local_34 != 0) {
                            local_2c = iVar3;
                            iVar2 = local_2c;
                            for (iVar3 = local_3c; local_2c = iVar2, 0 < iVar3; iVar3 = iVar3 + -1)
                            {
                              if (local_360[0] < 1) {
                                sensor_test_db_get_summary_result
                                          (*puVar13,uVar11,0xffffffff,0,local_38,&local_350,
                                           &local_34c);
                                uVar10 = local_354;
                              }
                              else {
                                _sensor_test_calc_time_interval
                                          (local_354,(int)local_360[0],local_38,iVar3,&local_358,
                                           &local_35c);
                                sensor_test_db_get_summary_result
                                          (*puVar13,uVar11,0xffffffff,local_358,local_35c,&local_350
                                           ,&local_34c);
                                uVar10 = local_358;
                              }
                              memset(acStack_2e0,0,0x100);
                              snprintf(acStack_2e0,0x100,"%d",uVar10);
                              uVar10 = json_object_new_string(acStack_2e0);
                              json_object_array_add(iVar4,uVar10);
                              memset(acStack_2e0,0,0x100);
                              snprintf(acStack_2e0,0x100,"%d",local_34c >> 0x10);
                              uVar10 = json_object_new_string(acStack_2e0);
                              json_object_array_add(iVar5,uVar10);
                              memset(acStack_2e0,0,0x100);
                              snprintf(acStack_2e0,0x100,"%d",(uint)local_348);
                              uVar10 = json_object_new_string(acStack_2e0);
                              json_object_array_add(iVar7,uVar10);
                              memset(acStack_2e0,0,0x100);
                              snprintf(acStack_2e0,0x100,"%d",local_34c & 0xffff);
                              uVar10 = json_object_new_string(acStack_2e0);
                              json_object_array_add(iVar6,uVar10);
                              memset(acStack_2e0,0,0x100);
                              snprintf(acStack_2e0,0x100,"%d",local_350);
                              uVar10 = json_object_new_string(acStack_2e0);
                              json_object_array_add(local_34,uVar10);
                              iVar2 = local_2c;
                            }
                            json_object_object_add(iVar2,"sch_start_time",iVar4);
                            json_object_object_add(iVar2,"success_cnt",iVar5);
                            json_object_object_add(iVar2,"slow_cnt",iVar7);
                            json_object_object_add(iVar2,"fail_cnt",iVar6);
                            json_object_object_add(iVar2,"result",local_34);
                            memset(acStack_2e0,0,0x100);
                            snprintf(acStack_2e0,0x100,"%d",uVar11);
                            uVar10 = json_object_new_string(acStack_2e0);
                            json_object_object_add(iVar2,"test_type",uVar10);
                            json_object_array_add(iVar1,iVar2);
                            goto LAB_004f2ad4;
                          }
                          if (sensor_test_err_switch == '\0') goto LAB_004f3228;
                          pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d result_array_obj create fail\n";
                          uVar10 = 0x175c;
                        }
                        iVar2 = local_48;
                        pcVar12 = (char *)0x0;
                        printf(pcVar9,"jcs_sensor_test_get_summary_result_new",uVar10);
                        __s = (FILE *)0x0;
                      }
                    }
                  }
                }
                goto LAB_004f2de8;
              }
LAB_004f2ad4:
              iVar2 = local_48;
              uVar11 = uVar11 + 1;
            } while (uVar11 != 9);
            memset(acStack_2e0,0,0x100);
            snprintf(acStack_2e0,0x100,"%d",*puVar13);
            uVar10 = json_object_new_string(acStack_2e0);
            json_object_object_add(iVar2,"test_case_id",uVar10);
            json_object_object_add(iVar2,"test_type_summary",iVar1);
            json_object_array_add(local_50,iVar2);
            goto LAB_004f2f78;
          }
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d get_case_start_time fail, id=%d\n",
                   "jcs_sensor_test_get_summary_result_new",0x1720,uVar10);
          }
        }
        pcVar12 = (char *)0x0;
        __s = (FILE *)0x0;
        iVar7 = 0;
        iVar6 = 0;
        iVar5 = 0;
        iVar4 = 0;
        iVar3 = 0;
        goto LAB_004f2de8;
      }
LAB_004f2f78:
      puVar13 = puVar13 + 1;
    }
    json_object_object_add(local_44,"sensor_test_summary_new",local_50);
    l_sensor_test_write_file_counter = l_sensor_test_write_file_counter + 1;
    snprintf(acStack_344,100,"/tmp/st_summary_result_%d");
    __s = fopen(acStack_344,"w+");
    if (__s == (FILE *)0x0) {
      if (sensor_test_err_switch == '\0') {
        pcVar12 = (char *)0x0;
      }
      else {
        pcVar12 = (char *)0x0;
        printf("[SENSOR_TEST_ERROR]%s()/%d open result file failed.\n",
               "jcs_sensor_test_get_summary_result_new",0x179a);
      }
    }
    else {
      pcVar12 = (char *)json_object_to_json_string_ext(local_44,0);
      pcVar12 = strdup(pcVar12);
      if (pcVar12 == (char *)0x0) {
        if (sensor_test_err_switch != '\0') {
          pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d generate result_str fail\n";
          uVar10 = 0x17a1;
LAB_004f34d0:
          printf(pcVar9,"jcs_sensor_test_get_summary_result_new",uVar10);
        }
      }
      else {
        sVar8 = strlen(pcVar12);
        sVar8 = fwrite(pcVar12,sVar8,1,__s);
        if (sVar8 == 1) {
          free(pcVar12);
          fclose(__s);
          json_object_put(local_44);
          uVar10 = json_object_new_string(acStack_344);
          json_object_object_add(param_2,"file_name",uVar10);
          memset(acStack_2e0,0,0x100);
          snprintf(acStack_2e0,0x100,"%d",local_4c);
          uVar10 = json_object_new_string(acStack_2e0);
          json_object_object_add(param_2,"total_num",uVar10);
          uVar10 = 0;
          goto LAB_004f2e98;
        }
        if (sensor_test_err_switch != '\0') {
          pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d write result to file failed.\n";
          uVar10 = 0x17a7;
          goto LAB_004f34d0;
        }
      }
    }
    local_50 = 0;
    iVar7 = 0;
    iVar6 = 0;
    iVar5 = 0;
    iVar4 = 0;
    iVar3 = 0;
    iVar1 = 0;
    iVar2 = 0;
  }
LAB_004f2de8:
  json_object_put(local_44);
  if (local_50 != 0) {
    json_object_put(local_50);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  if (iVar4 != 0) {
    json_object_put(iVar4);
  }
  if (iVar5 != 0) {
    json_object_put(iVar5);
  }
  if (iVar6 != 0) {
    json_object_put(iVar6);
  }
  if (iVar7 != 0) {
    json_object_put(iVar7);
  }
  if (pcVar12 != (char *)0x0) {
    free(pcVar12);
  }
  uVar10 = 1;
  if (__s != (FILE *)0x0) {
    fclose(__s);
    uVar10 = 1;
  }
LAB_004f2e98:
  uVar10 = json_object_new_int(uVar10);
  json_object_object_add(param_2,&DAT_00676a24,uVar10);
  return;
}

