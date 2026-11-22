// func _sensor_test_sqlite_test_case_init_cb @ 004ff07c size=7840

undefined4
_sensor_test_sqlite_test_case_init_cb
          (int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint *__s;
  void *pvVar1;
  int iVar2;
  long lVar3;
  undefined1 uVar9;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  undefined2 uVar8;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  size_t __n;
  char *pcVar13;
  undefined2 *puVar14;
  char *pcVar15;
  char *pcVar16;
  ushort *puVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  char *local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  undefined4 *local_38;
  undefined4 *local_30;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_sqlite_test_case_init_cb ENTER\n",
           "_sensor_test_sqlite_test_case_init_cb",0x480);
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d column cnt is %d\n","_sensor_test_sqlite_test_case_init_cb",
           0x48a,param_2);
  }
  if (param_1 == 0) {
    uVar12 = 0;
    if (sensor_test_err_switch == '\0') {
      return 0;
    }
    pcVar15 = "[SENSOR_TEST_ERROR]%s()/%d para is null.\n";
    uVar11 = 0x48d;
  }
  else {
    __s = (uint *)FUN_00408450(8,0x493);
    if (__s != (uint *)0x0) {
      memset(__s,0,8);
      *__s = 0xffffffff;
      pvVar1 = (void *)FUN_00408450(0x5c,0x49d);
      __s[1] = (uint)pvVar1;
      if (pvVar1 == (void *)0x0) {
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc case_tmp->setting fail\n",
                 "_sensor_test_sqlite_test_case_init_cb",0x4a0);
        }
LAB_004ff3c0:
        FUN_00407df0(__s);
        return 1;
      }
      memset(pvVar1,0,0x5c);
      local_3c = 0;
      local_38 = param_3;
      local_30 = param_4;
      do {
        if (param_2 <= local_3c) {
          if (sensor_test_debug_switch == '\0') {
            uVar10 = *__s;
          }
          else {
            printf("[SENSOR_TEST_DEBUG]%s()/%d init case successful,test_case_id=%d\n",
                   "_sensor_test_sqlite_test_case_init_cb",0x58c,*__s);
            uVar10 = *__s;
          }
          *(uint **)(param_1 + uVar10 * 4) = __s;
          return 0;
        }
        pcVar15 = (char *)*local_38;
        if ((pcVar15 == (char *)0x0) || (pcVar13 = (char *)*local_30, pcVar13 == (char *)0x0)) {
          uVar12 = 1;
          if (sensor_test_err_switch == '\0') {
            return 1;
          }
          pcVar15 = "[SENSOR_TEST_ERROR]%s()/%d column value or name is null.\n";
          uVar11 = 0x4ac;
          goto LAB_004ff2fc;
        }
        iVar2 = strcmp(pcVar13,"test_case_id");
        if (iVar2 == 0) {
          pcVar13 = (char *)atoi(pcVar15);
          *__s = (uint)pcVar13;
          if (((int)pcVar13 < 0) || (g_sensor_test_case_num_max <= pcVar13)) {
            if (sensor_test_err_switch != '\0') {
              pcVar15 = "[SENSOR_TEST_ERROR]%s()/%d invalid test_case_id=%d\n";
              uVar12 = 0x4b5;
LAB_004ff484:
              printf(pcVar15,"_sensor_test_sqlite_test_case_init_cb",uVar12,pcVar13);
            }
            goto LAB_004ff4ec;
          }
          sensor_test_db_case_id_cost(pcVar13);
        }
        else {
          iVar2 = strcmp(pcVar13,"test_case_name");
          if (iVar2 == 0) {
            strncpy((char *)(__s[1] + 0xd),pcVar15,0x20);
          }
          else {
            iVar2 = strcmp(pcVar13,"sch_type");
            if (iVar2 == 0) {
              puVar14 = (undefined2 *)__s[1];
              iVar2 = atoi(pcVar15);
              *puVar14 = (short)iVar2;
            }
            else {
              iVar2 = strcmp(pcVar13,"sch_period");
              if (iVar2 == 0) {
                uVar10 = __s[1];
                iVar2 = atoi(pcVar15);
                *(short *)(uVar10 + 2) = (short)iVar2;
              }
              else {
                iVar2 = strcmp(pcVar13,"sch_time");
                if (iVar2 == 0) {
                  uVar10 = __s[1];
                  lVar3 = atol(pcVar15);
                  *(long *)(uVar10 + 4) = lVar3;
                }
                else {
                  iVar2 = strcmp(pcVar13,"change_id");
                  if (iVar2 == 0) {
                    uVar10 = __s[1];
                    iVar2 = atoi(pcVar15);
                    *(char *)(uVar10 + 8) = (char)iVar2;
                  }
                  else {
                    iVar2 = strcmp(pcVar13,"rssi_threshold");
                    if (iVar2 != 0) {
                      iVar2 = strcmp(pcVar13,"group_id");
                      if (iVar2 == 0) {
                        iVar2 = cJSON_Parse(pcVar15);
                        if (iVar2 != 0) {
                          uVar10 = __s[1];
                          uVar9 = cJSON_GetArraySize(iVar2);
                          *(undefined1 *)(uVar10 + 9) = uVar9;
                          uVar10 = __s[1];
                          *(undefined4 *)(uVar10 + 0x30) = 0;
                          if (*(char *)(uVar10 + 9) != '\0') {
                            uVar10 = __s[1];
                            uVar12 = FUN_00408450((uint)*(byte *)(uVar10 + 9) << 1,0x4de);
                            *(undefined4 *)(uVar10 + 0x30) = uVar12;
                            pvVar1 = *(void **)(__s[1] + 0x30);
                            if (pvVar1 == (void *)0x0) {
                              if (sensor_test_err_switch != '\0') {
                                pcVar15 = 
                                "[SENSOR_TEST_ERROR]%s()/%d case_tmp->setting->group_list mem malloc fail\n"
                                ;
                                uVar12 = 0x4e1;
                                goto LAB_005002a8;
                              }
                              goto LAB_004ff4ec;
                            }
                            iVar18 = 0;
                            memset(pvVar1,0,(uint)*(byte *)(__s[1] + 9) << 1);
                            while (iVar18 < (int)(uint)*(byte *)(__s[1] + 9)) {
                              iVar19 = cJSON_GetArrayItem(iVar2,iVar18);
                              uVar7 = *(ushort *)(iVar19 + 0x16);
                              *(ushort *)(*(int *)(__s[1] + 0x30) + iVar18 * 2) = uVar7;
                              if (sensor_test_debug_switch == '\0') {
                                iVar18 = iVar18 + 1;
                              }
                              else {
                                printf("[SENSOR_TEST_DEBUG]%s()/%d sql init cb group list\'s group_id=%d, success,idx=%d\n"
                                       ,"_sensor_test_sqlite_test_case_init_cb",0x4ea,(uint)uVar7,
                                       iVar18);
                                iVar18 = iVar18 + 1;
                              }
                            }
                          }
                          goto LAB_004ff5f8;
                        }
                        if (sensor_test_err_switch == '\0') goto LAB_004ff4ec;
                        pcVar15 = 
                        "[SENSOR_TEST_ERROR]%s()/%d case_tmp->setting->group_list cJSON_Parse is null\n"
                        ;
                        uVar12 = 0x4d7;
LAB_005002a8:
                        printf(pcVar15,"_sensor_test_sqlite_test_case_init_cb",uVar12);
                      }
                      else {
                        iVar2 = strcmp(pcVar13,"join_test_sensor");
                        if (iVar2 == 0) {
                          iVar2 = cJSON_Parse(pcVar15);
                          if (iVar2 == 0) {
                            if (sensor_test_err_switch != '\0') {
                              pcVar15 = 
                              "[SENSOR_TEST_ERROR]%s()/%d case_tmp->setting->join_test_sensor_list cJSON_Parse is null\n"
                              ;
                              uVar12 = 0x4f9;
                              goto LAB_005002a8;
                            }
                            goto LAB_004ff4ec;
                          }
                          uVar10 = __s[1];
                          uVar9 = cJSON_GetArraySize(iVar2);
                          *(undefined1 *)(uVar10 + 10) = uVar9;
                          uVar10 = __s[1];
                          *(undefined4 *)(uVar10 + 0x34) = 0;
                          if (*(char *)(uVar10 + 10) != '\0') {
                            uVar10 = __s[1];
                            uVar12 = FUN_00408450((uint)*(byte *)(uVar10 + 10) << 2,0x501);
                            *(undefined4 *)(uVar10 + 0x34) = uVar12;
                            pvVar1 = *(void **)(__s[1] + 0x34);
                            if (pvVar1 == (void *)0x0) {
                              if (sensor_test_err_switch != '\0') {
                                pcVar15 = 
                                "[SENSOR_TEST_ERROR]%s()/%d case_tmp->setting->join_test_sensor_list mem malloc fail\n"
                                ;
                                uVar12 = 0x504;
                                goto LAB_005002a8;
                              }
                              goto LAB_004ff4ec;
                            }
                            iVar18 = 0;
                            memset(pvVar1,0,(uint)*(byte *)(__s[1] + 10) << 2);
                            while (iVar18 < (int)(uint)*(byte *)(__s[1] + 10)) {
                              iVar19 = cJSON_GetArrayItem(iVar2,iVar18);
                              uVar7 = *(ushort *)(iVar19 + 0x16);
                              *(ushort *)(*(int *)(__s[1] + 0x34) + iVar18 * 4) = uVar7;
                              *(undefined1 *)(*(int *)(__s[1] + 0x34) + iVar18 * 4 + 2) = 0;
                              if (sensor_test_debug_switch == '\0') {
                                iVar18 = iVar18 + 1;
                              }
                              else {
                                printf("[SENSOR_TEST_DEBUG]%s()/%d sql init cb join_test_sensor_list\'s sensor_id=%d, success,idx=%d\n"
                                       ,"_sensor_test_sqlite_test_case_init_cb",0x50e,(uint)uVar7,
                                       iVar18);
                                iVar18 = iVar18 + 1;
                              }
                            }
                          }
LAB_004ff5f8:
                          cJSON_Delete(iVar2);
                          goto LAB_004ff1b4;
                        }
                        iVar2 = strcmp(pcVar13,"ssid_info");
                        if (iVar2 == 0) {
                          iVar2 = cJSON_Parse(pcVar15);
                          if (iVar2 != 0) {
                            uVar10 = __s[1];
                            uVar9 = cJSON_GetArraySize(iVar2);
                            *(undefined1 *)(uVar10 + 0xb) = uVar9;
                            uVar10 = __s[1];
                            *(undefined4 *)(uVar10 + 0x38) = 0;
                            if (*(char *)(uVar10 + 0xb) != '\0') {
                              uVar10 = __s[1];
                              uVar12 = FUN_00408450((uint)*(byte *)(uVar10 + 0xb) * 0x220,0x526);
                              *(undefined4 *)(uVar10 + 0x38) = uVar12;
                              pvVar1 = *(void **)(__s[1] + 0x38);
                              if (pvVar1 == (void *)0x0) {
                                if (sensor_test_err_switch != '\0') {
                                  pcVar15 = 
                                  "[SENSOR_TEST_ERROR]%s()/%d case_tmp->setting->ssid_info_list mem malloc fail\n"
                                  ;
                                  uVar12 = 0x529;
                                  goto LAB_005002a8;
                                }
                                goto LAB_004ff4ec;
                              }
                              iVar18 = 0;
                              iVar19 = 0;
                              memset(pvVar1,0,(uint)*(byte *)(__s[1] + 0xb) * 0x220);
                              while (iVar19 < (int)(uint)*(byte *)(__s[1] + 0xb)) {
                                uVar12 = cJSON_GetArrayItem(iVar2,iVar19);
                                iVar20 = cJSON_GetObjectItem(uVar12,"serv_id");
                                if (iVar20 != 0) {
                                  *(undefined4 *)(*(int *)(__s[1] + 0x38) + iVar18) =
                                       *(undefined4 *)(iVar20 + 0x14);
                                }
                                iVar20 = cJSON_GetObjectItem(uVar12,"freqband");
                                if (iVar20 != 0) {
                                  *(undefined4 *)(*(int *)(__s[1] + 0x38) + iVar18 + 4) =
                                       *(undefined4 *)(iVar20 + 0x14);
                                }
                                iVar20 = cJSON_GetObjectItem(uVar12,"encryption");
                                if (iVar20 != 0) {
                                  *(undefined4 *)(*(int *)(__s[1] + 0x38) + iVar18 + 0xc) =
                                       *(undefined4 *)(iVar20 + 0x14);
                                }
                                iVar20 = cJSON_GetObjectItem(uVar12,"radius_type");
                                if ((iVar20 != 0) && (*(char **)(iVar20 + 0x10) != (char *)0x0)) {
                                  strncpy((char *)(*(int *)(__s[1] + 0x38) + iVar18 + 0x10),
                                          *(char **)(iVar20 + 0x10),0x20);
                                }
                                iVar20 = cJSON_GetObjectItem(uVar12,"radius_key");
                                if ((iVar20 != 0) && (*(char **)(iVar20 + 0x10) != (char *)0x0)) {
                                  strncpy((char *)(*(int *)(__s[1] + 0x38) + iVar18 + 0x30),
                                          *(char **)(iVar20 + 0x10),0x78);
                                }
                                iVar20 = cJSON_GetObjectItem(uVar12,"radius_name");
                                if ((iVar20 != 0) && (*(char **)(iVar20 + 0x10) != (char *)0x0)) {
                                  strncpy((char *)(*(int *)(__s[1] + 0x38) + iVar18 + 0xa8),
                                          *(char **)(iVar20 + 0x10),0x100);
                                }
                                iVar20 = cJSON_GetObjectItem(uVar12,"ssid_key");
                                if ((iVar20 != 0) && (*(char **)(iVar20 + 0x10) != (char *)0x0)) {
                                  strncpy((char *)(*(int *)(__s[1] + 0x38) + iVar18 + 0x1a8),
                                          *(char **)(iVar20 + 0x10),0x78);
                                }
                                iVar20 = cJSON_GetObjectItem(uVar12,"support_freqband");
                                iVar19 = iVar19 + 1;
                                if (iVar20 != 0) {
                                  *(undefined4 *)(*(int *)(__s[1] + 0x38) + iVar18 + 8) =
                                       *(undefined4 *)(iVar20 + 0x14);
                                }
                                iVar18 = iVar18 + 0x220;
                              }
                            }
                            goto LAB_004ff5f8;
                          }
                          if (sensor_test_err_switch != '\0') {
                            pcVar15 = 
                            "[SENSOR_TEST_ERROR]%s()/%d case_tmp->setting->ssid_info_list cJSON_Parse is null\n"
                            ;
                            uVar12 = 0x51f;
                            goto LAB_005002a8;
                          }
                        }
                        else {
                          iVar2 = strcmp(pcVar13,"service");
                          if (iVar2 == 0) {
                            iVar2 = cJSON_Parse(pcVar15);
                            uVar10 = __s[1];
                            if (sensor_test_debug_switch != '\0') {
                              printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_sqlite_service_info_init ENTER\n"
                                     ,"_sensor_test_sqlite_service_info_init",0x278);
                            }
                            if ((iVar2 != 0) &&
                               (puVar17 = (ushort *)(uVar10 + 0x3c), puVar17 != (ushort *)0x0)) {
                              pcVar15 = (char *)cJSON_GetArraySize();
                              if (0 < (int)pcVar15) {
                                iVar20 = 0;
                                *(undefined2 *)(uVar10 + 0x3c) = 0;
                                iVar19 = 0;
                                local_48 = 0;
                                iVar18 = 0;
                                local_4c = 0;
                                pcVar13 = (char *)0x0;
                                local_40 = 0;
                                local_50 = 0;
                                do {
                                  iVar4 = cJSON_GetArrayItem(iVar2,pcVar13);
                                  if (iVar4 == 0) {
                                    if (sensor_test_warning_switch != '\0') {
                                      pcVar16 = 
                                      "[SENSOR_TEST_WARNING]%s()/%d get service_array item fail,idx=%d\n"
                                      ;
                                      uVar12 = 0x29f;
LAB_004ffe14:
                                      printf(pcVar16,"_sensor_test_sqlite_service_info_init",uVar12,
                                             pcVar13);
                                    }
                                  }
                                  else {
                                    iVar5 = cJSON_GetObjectItem(iVar4,"ser_name");
                                    if (iVar5 == 0) {
                                      if (sensor_test_warning_switch != '\0') {
                                        pcVar16 = 
                                        "[SENSOR_TEST_WARNING]%s()/%d service array item has no ser_name,with idx=%d\n"
                                        ;
                                        uVar12 = 0x2a6;
                                        goto LAB_004ffe14;
                                      }
                                    }
                                    else {
                                      iVar4 = cJSON_GetObjectItem(iVar4,"params");
                                      if (iVar4 == 0) {
                                        if (sensor_test_warning_switch != '\0') {
                                          pcVar16 = 
                                          "[SENSOR_TEST_WARNING]%s()/%d service array item has no params,with idx=%d\n"
                                          ;
                                          uVar12 = 0x2ae;
                                          goto LAB_004ffe14;
                                        }
                                      }
                                      else if ((*(int *)(iVar5 + 0x10) != 0) &&
                                              (iVar6 = cJSON_GetArraySize(iVar4), 0 < iVar6)) {
                                        pcVar16 = *(char **)(iVar5 + 0x10);
                                        iVar5 = strcmp(pcVar16,"onboarding");
                                        if (iVar5 == 0) {
                                          uVar7 = *puVar17 | 1;
LAB_004ffadc:
                                          *puVar17 = uVar7;
                                        }
                                        else {
                                          iVar5 = strcmp(pcVar16,"dns");
                                          if (iVar5 == 0) {
                                            *puVar17 = *puVar17 | 2;
                                            iVar18 = cJSON_GetArraySize(iVar4);
                                          }
                                          else {
                                            iVar5 = strcmp(pcVar16,"hostaccess");
                                            if (iVar5 == 0) {
                                              *puVar17 = *puVar17 | 4;
                                              local_50 = cJSON_GetArraySize(iVar4);
                                            }
                                            else {
                                              iVar5 = strcmp(pcVar16,"radius");
                                              if (iVar5 == 0) {
                                                *puVar17 = *puVar17 | 8;
                                                iVar19 = cJSON_GetArraySize(iVar4);
                                              }
                                              else {
                                                iVar5 = strcmp(pcVar16,"mail");
                                                if (iVar5 == 0) {
                                                  *puVar17 = *puVar17 | 0x10;
                                                  local_40 = cJSON_GetArraySize(iVar4);
                                                }
                                                else {
                                                  iVar5 = strcmp(pcVar16,"web");
                                                  if (iVar5 == 0) {
                                                    *puVar17 = *puVar17 | 0x20;
                                                    local_4c = cJSON_GetArraySize(iVar4);
                                                  }
                                                  else {
                                                    iVar5 = strcmp(pcVar16,"ftp");
                                                    if (iVar5 == 0) {
                                                      *puVar17 = *puVar17 | 0x40;
                                                      local_48 = cJSON_GetArraySize(iVar4);
                                                    }
                                                    else {
                                                      iVar5 = strcmp(pcVar16,"speed");
                                                      if (iVar5 == 0) {
                                                        *puVar17 = *puVar17 | 0x80;
                                                        iVar20 = cJSON_GetArraySize(iVar4);
                                                      }
                                                      else {
                                                        iVar4 = strcmp(pcVar16,"delayloss");
                                                        if (iVar4 == 0) {
                                                          uVar7 = *puVar17 | 0x100;
                                                          goto LAB_004ffadc;
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  pcVar13 = pcVar13 + 1;
                                } while (pcVar13 != pcVar15);
                                if (iVar18 != 0) {
                                  *(undefined4 *)(uVar10 + 0x40) = 0;
                                  pvVar1 = (void *)FUN_00408450(0x102,0x2fe);
                                  *(void **)(uVar10 + 0x40) = pvVar1;
                                  if (pvVar1 != (void *)0x0) {
                                    memset(pvVar1,0,0x102);
                                    goto LAB_004ffafc;
                                  }
                                  if (sensor_test_err_switch != '\0') {
                                    uVar12 = 0x301;
                                    goto LAB_00500ac4;
                                  }
                                  goto LAB_0050027c;
                                }
LAB_004ffafc:
                                if (local_50 != 0) {
                                  *(undefined4 *)(uVar10 + 0x44) = 0;
                                  pvVar1 = (void *)FUN_00408450(8,0x309);
                                  *(void **)(uVar10 + 0x44) = pvVar1;
                                  if (pvVar1 == (void *)0x0) {
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x30c;
                                      goto LAB_00500ac4;
                                    }
                                  }
                                  else {
                                    memset(pvVar1,0,8);
                                    **(int **)(uVar10 + 0x44) = local_50;
                                    *(undefined4 *)(*(int *)(uVar10 + 0x44) + 4) = 0;
                                    if (sensor_test_debug_switch != '\0') {
                                      printf("[SENSOR_TEST_DEBUG]%s()/%d hostaccess_config_cnt=%d\n"
                                             ,"_sensor_test_sqlite_service_info_init",0x313,local_50
                                            );
                                    }
                                    iVar18 = *(int *)(uVar10 + 0x44);
                                    uVar12 = FUN_00408450(local_50 * 0x102,0x314);
                                    *(undefined4 *)(iVar18 + 4) = uVar12;
                                    pvVar1 = *(void **)(*(int *)(uVar10 + 0x44) + 4);
                                    if (pvVar1 != (void *)0x0) {
                                      memset(pvVar1,0,local_50 * 0x102);
                                      goto LAB_004ffb04;
                                    }
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x317;
                                      goto LAB_00500ac4;
                                    }
                                  }
                                  goto LAB_0050027c;
                                }
LAB_004ffb04:
                                if (iVar19 != 0) {
                                  *(undefined4 *)(uVar10 + 0x48) = 0;
                                  pvVar1 = (void *)FUN_00408450(0x38c,799);
                                  *(void **)(uVar10 + 0x48) = pvVar1;
                                  if (pvVar1 == (void *)0x0) {
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x322;
                                      goto LAB_00500ac4;
                                    }
                                    goto LAB_0050027c;
                                  }
                                  memset(pvVar1,0,0x38c);
                                }
                                if (local_40 != 0) {
                                  *(undefined4 *)(uVar10 + 0x4c) = 0;
                                  pvVar1 = (void *)FUN_00408450(8,0x32a);
                                  *(void **)(uVar10 + 0x4c) = pvVar1;
                                  if (pvVar1 == (void *)0x0) {
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x32d;
                                      goto LAB_00500ac4;
                                    }
                                  }
                                  else {
                                    memset(pvVar1,0,8);
                                    **(int **)(uVar10 + 0x4c) = local_40;
                                    *(undefined4 *)(*(int *)(uVar10 + 0x4c) + 4) = 0;
                                    iVar18 = *(int *)(uVar10 + 0x4c);
                                    uVar12 = FUN_00408450(local_40 * 0x28c,0x333);
                                    *(undefined4 *)(iVar18 + 4) = uVar12;
                                    pvVar1 = *(void **)(*(int *)(uVar10 + 0x4c) + 4);
                                    if (pvVar1 != (void *)0x0) {
                                      memset(pvVar1,0,local_40 * 0x28c);
                                      goto LAB_004ffb14;
                                    }
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x336;
                                      goto LAB_00500ac4;
                                    }
                                  }
                                  goto LAB_0050027c;
                                }
LAB_004ffb14:
                                if (local_4c != 0) {
                                  *(undefined4 *)(uVar10 + 0x50) = 0;
                                  pvVar1 = (void *)FUN_00408450(8,0x33e);
                                  *(void **)(uVar10 + 0x50) = pvVar1;
                                  if (pvVar1 == (void *)0x0) {
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x341;
                                      goto LAB_00500ac4;
                                    }
                                  }
                                  else {
                                    memset(pvVar1,0,8);
                                    **(int **)(uVar10 + 0x50) = local_4c;
                                    *(undefined4 *)(*(int *)(uVar10 + 0x50) + 4) = 0;
                                    iVar18 = *(int *)(uVar10 + 0x50);
                                    uVar12 = FUN_00408450(local_4c * 0x104,0x348);
                                    *(undefined4 *)(iVar18 + 4) = uVar12;
                                    pvVar1 = *(void **)(*(int *)(uVar10 + 0x50) + 4);
                                    if (pvVar1 != (void *)0x0) {
                                      memset(pvVar1,0,local_4c * 0x104);
                                      goto LAB_004ffb1c;
                                    }
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x34b;
                                      goto LAB_00500ac4;
                                    }
                                  }
                                  goto LAB_0050027c;
                                }
LAB_004ffb1c:
                                if (local_48 != 0) {
                                  *(undefined4 *)(uVar10 + 0x54) = 0;
                                  pvVar1 = (void *)FUN_00408450(8,0x353);
                                  *(void **)(uVar10 + 0x54) = pvVar1;
                                  if (pvVar1 == (void *)0x0) {
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x356;
LAB_00500ac4:
                                      printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",
                                             "_sensor_test_sqlite_service_info_init",uVar12);
                                    }
                                  }
                                  else {
                                    memset(pvVar1,0,8);
                                    **(int **)(uVar10 + 0x54) = local_48;
                                    *(undefined4 *)(*(int *)(uVar10 + 0x54) + 4) = 0;
                                    iVar18 = *(int *)(uVar10 + 0x54);
                                    uVar12 = FUN_00408450(local_48 * 0xa8e,0x35d);
                                    *(undefined4 *)(iVar18 + 4) = uVar12;
                                    pvVar1 = *(void **)(*(int *)(uVar10 + 0x54) + 4);
                                    if (pvVar1 != (void *)0x0) {
                                      memset(pvVar1,0,local_48 * 0xa8e);
                                      goto LAB_004ffb24;
                                    }
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x360;
                                      goto LAB_00500ac4;
                                    }
                                  }
LAB_0050027c:
                                  sensor_test_db_service_nested_mem_free(puVar17);
                                  goto LAB_0050028c;
                                }
LAB_004ffb24:
                                if (iVar20 != 0) {
                                  *(undefined4 *)(uVar10 + 0x58) = 0;
                                  pvVar1 = (void *)FUN_00408450(0x804,0x368);
                                  *(void **)(uVar10 + 0x58) = pvVar1;
                                  if (pvVar1 == (void *)0x0) {
                                    if (sensor_test_err_switch != '\0') {
                                      uVar12 = 0x36b;
                                      goto LAB_00500ac4;
                                    }
                                    goto LAB_0050027c;
                                  }
                                  memset(pvVar1,0,0x804);
                                }
                                local_54 = (char *)0x0;
                                do {
                                  iVar18 = cJSON_GetArrayItem(iVar2,local_54);
                                  pcVar13 = local_54;
                                  if (iVar18 == 0) {
                                    if (sensor_test_warning_switch != '\0') {
                                      pcVar16 = 
                                      "[SENSOR_TEST_WARNING]%s()/%d get service_array item fail,idx=%d\n"
                                      ;
                                      uVar12 = 0x378;
LAB_004ffe4c:
                                      printf(pcVar16,"_sensor_test_sqlite_service_info_init",uVar12,
                                             pcVar13);
                                    }
                                  }
                                  else {
                                    iVar19 = cJSON_GetObjectItem(iVar18,"ser_name");
                                    if (iVar19 == 0) {
                                      if (sensor_test_warning_switch != '\0') {
                                        pcVar16 = 
                                        "[SENSOR_TEST_WARNING]%s()/%d service array item has no ser_name,with idx=%d\n"
                                        ;
                                        uVar12 = 0x37f;
                                        goto LAB_004ffe4c;
                                      }
                                    }
                                    else {
                                      iVar18 = cJSON_GetObjectItem(iVar18,"params");
                                      if (iVar18 == 0) {
                                        if (sensor_test_warning_switch != '\0') {
                                          pcVar16 = 
                                          "[SENSOR_TEST_WARNING]%s()/%d service array item has no params,with idx=%d\n"
                                          ;
                                          uVar12 = 0x387;
                                          goto LAB_004ffe4c;
                                        }
                                      }
                                      else if ((*(int *)(iVar19 + 0x10) != 0) &&
                                              (iVar20 = cJSON_GetArraySize(iVar18), 0 < iVar20)) {
                                        pcVar13 = *(char **)(iVar19 + 0x10);
                                        iVar19 = strcmp(pcVar13,"onboarding");
                                        if (iVar19 == 0) {
                                          iVar18 = cJSON_GetArrayItem(iVar18,0);
                                          if (((iVar18 != 0) &&
                                              (iVar19 = cJSON_GetObjectItem(iVar18,"ser_index"),
                                              iVar19 != 0)) &&
                                             (iVar18 = cJSON_GetObjectItem(iVar18,"ser_index"),
                                             iVar18 != 0)) {
                                            *(short *)(uVar10 + 0x3e) =
                                                 (short)*(undefined4 *)(iVar18 + 0x14);
                                          }
                                        }
                                        else {
                                          iVar19 = strcmp(pcVar13,"dns");
                                          if (iVar19 == 0) {
                                            iVar18 = cJSON_GetArrayItem(iVar18,0);
                                            if (((iVar18 == 0) ||
                                                (iVar19 = cJSON_GetObjectItem(iVar18,"ser_index"),
                                                iVar19 == 0)) ||
                                               (iVar19 = cJSON_GetObjectItem(iVar18,"domain"),
                                               iVar19 == 0)) {
                                              if (sensor_test_err_switch != '\0') {
                                                uVar12 = 0x3b0;
                                                pcVar15 = "dns";
LAB_00500788:
                                                printf(
                                                  "[SENSOR_TEST_ERROR]%s()/%d sql init service fail, no requried field,by service_name=%s\n"
                                                  ,"_sensor_test_sqlite_service_info_init",uVar12,
                                                  pcVar15);
                                              }
                                              goto LAB_0050027c;
                                            }
                                            iVar19 = cJSON_GetObjectItem(iVar18,"ser_index");
                                            if (iVar19 == 0) goto LAB_004ffc8c;
                                            *(short *)(*(int *)(uVar10 + 0x40) + 0x100) =
                                                 (short)*(undefined4 *)(iVar19 + 0x14);
                                            pcVar13 = *(char **)(uVar10 + 0x40);
                                            iVar18 = cJSON_GetObjectItem(iVar18,"domain");
                                            __n = 0x100;
                                            pcVar16 = *(char **)(iVar18 + 0x10);
LAB_0050025c:
                                            strncpy(pcVar13,pcVar16,__n);
                                          }
                                          else {
                                            iVar20 = 0;
                                            iVar19 = strcmp(pcVar13,"hostaccess");
                                            if (iVar19 == 0) {
                                              for (; iVar20 < local_50; iVar20 = iVar20 + 1) {
                                                iVar19 = cJSON_GetArrayItem(iVar18,iVar20);
                                                if ((iVar19 == 0) ||
                                                   (iVar4 = cJSON_GetObjectItem(iVar19,"ser_index"),
                                                   iVar4 == 0)) {
LAB_0050026c:
                                                  if (sensor_test_err_switch == '\0')
                                                  goto LAB_0050027c;
                                                  uVar12 = 0x3c2;
                                                  pcVar15 = "hostaccess";
                                                  goto LAB_00500788;
                                                }
                                                iVar4 = cJSON_GetObjectItem(iVar19,&DAT_0068376c);
                                                if (iVar4 == 0) goto LAB_0050026c;
                                                iVar5 = *(int *)(*(int *)(uVar10 + 0x44) + 4);
                                                iVar4 = cJSON_GetObjectItem(iVar19,"ser_index");
                                                *(short *)(iVar5 + iVar20 * 0x102 + 0x100) =
                                                     (short)*(undefined4 *)(iVar4 + 0x14);
                                                iVar4 = *(int *)(*(int *)(uVar10 + 0x44) + 4);
                                                iVar19 = cJSON_GetObjectItem(iVar19,&DAT_0068376c);
                                                strncpy((char *)(iVar4 + iVar20 * 0x102),
                                                        *(char **)(iVar19 + 0x10),0x100);
                                              }
                                            }
                                            else {
                                              iVar19 = strcmp(pcVar13,"radius");
                                              if (iVar19 == 0) {
                                                iVar18 = cJSON_GetArrayItem(iVar18,0);
                                                if ((((((iVar18 != 0) &&
                                                       (iVar19 = cJSON_GetObjectItem(iVar18,
                                                  "ser_index"), iVar19 != 0)) &&
                                                  (iVar19 = cJSON_GetObjectItem(iVar18,&DAT_0068376c
                                                                               ), iVar19 != 0)) &&
                                                  ((iVar19 = cJSON_GetObjectItem(iVar18,"port"),
                                                   iVar19 != 0 &&
                                                   (iVar19 = cJSON_GetObjectItem(iVar18,"user_name")
                                                   , iVar19 != 0)))) &&
                                                  (iVar19 = cJSON_GetObjectItem(iVar18,"share_key"),
                                                  iVar19 != 0)) &&
                                                  (iVar19 = cJSON_GetObjectItem(iVar18,"auth_type"),
                                                  iVar19 != 0)) {
                                                  iVar20 = *(int *)(uVar10 + 0x48);
                                                  iVar19 = cJSON_GetObjectItem(iVar18,"ser_index");
                                                  *(short *)(iVar20 + 0x38a) =
                                                       (short)*(undefined4 *)(iVar19 + 0x14);
                                                  pcVar13 = *(char **)(uVar10 + 0x48);
                                                  iVar19 = cJSON_GetObjectItem(iVar18,&DAT_0068376c)
                                                  ;
                                                  strncpy(pcVar13,*(char **)(iVar19 + 0x10),0x100);
                                                  iVar19 = cJSON_GetObjectItem(iVar18,"port");
                                                  if (*(int *)(iVar19 + 0x10) == 0) {
                                                    iVar19 = cJSON_GetObjectItem(iVar18,"port");
                                                    iVar20 = *(int *)(uVar10 + 0x48);
                                                    if (*(int *)(iVar19 + 0x14) != 0) {
                                                      iVar19 = cJSON_GetObjectItem(iVar18,"port");
                                                      uVar8 = (undefined2)
                                                              *(undefined4 *)(iVar19 + 0x14);
                                                      goto LAB_005006a8;
                                                    }
                                                    *(undefined2 *)(iVar20 + 0x388) = 0;
                                                  }
                                                  else {
                                                    iVar20 = *(int *)(uVar10 + 0x48);
                                                    iVar19 = cJSON_GetObjectItem(iVar18,"port");
                                                    iVar19 = atoi(*(char **)(iVar19 + 0x10));
                                                    uVar8 = (undefined2)iVar19;
LAB_005006a8:
                                                    *(undefined2 *)(iVar20 + 0x388) = uVar8;
                                                  }
                                                  iVar20 = *(int *)(uVar10 + 0x48);
                                                  iVar19 = cJSON_GetObjectItem(iVar18,"user_name");
                                                  strncpy((char *)(iVar20 + 0x100),
                                                          *(char **)(iVar19 + 0x10),0x100);
                                                  iVar20 = *(int *)(uVar10 + 0x48);
                                                  iVar19 = cJSON_GetObjectItem(iVar18,"passwd");
                                                  strncpy((char *)(iVar20 + 0x200),
                                                          *(char **)(iVar19 + 0x10),0x78);
                                                  iVar20 = *(int *)(uVar10 + 0x48);
                                                  iVar19 = cJSON_GetObjectItem(iVar18,"share_key");
                                                  strncpy((char *)(iVar20 + 0x278),
                                                          *(char **)(iVar19 + 0x10),0x100);
                                                  iVar19 = *(int *)(uVar10 + 0x48);
                                                  iVar18 = cJSON_GetObjectItem(iVar18,"auth_type");
                                                  __n = 0x10;
                                                  pcVar16 = *(char **)(iVar18 + 0x10);
                                                  pcVar13 = (char *)(iVar19 + 0x378);
                                                  goto LAB_0050025c;
                                                }
                                                if (sensor_test_err_switch != '\0') {
                                                  uVar12 = 0x3e4;
                                                  pcVar15 = "radius";
                                                  goto LAB_00500788;
                                                }
                                                goto LAB_0050027c;
                                              }
                                              iVar20 = 0;
                                              iVar19 = strcmp(pcVar13,"mail");
                                              if (iVar19 == 0) {
                                                for (; iVar20 < local_40; iVar20 = iVar20 + 1) {
                                                  iVar19 = cJSON_GetArrayItem(iVar18,iVar20);
                                                  if (((iVar19 == 0) ||
                                                      (iVar4 = cJSON_GetObjectItem(iVar19,
                                                  "ser_index"), iVar4 == 0)) ||
                                                  ((iVar4 = cJSON_GetObjectItem(iVar19,&DAT_0068376c
                                                                               ), iVar4 == 0 ||
                                                   ((iVar4 = cJSON_GetObjectItem(iVar19,"port"),
                                                    iVar4 == 0 ||
                                                    (iVar4 = cJSON_GetObjectItem(iVar19,"protocol"),
                                                    iVar4 == 0)))))) {
                                                    if (sensor_test_err_switch == '\0')
                                                    goto LAB_0050027c;
                                                    uVar12 = 0x40b;
                                                    pcVar15 = "mail";
                                                    goto LAB_00500788;
                                                  }
                                                  iVar6 = iVar20 * 0x28c;
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x4c) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"ser_index");
                                                  *(short *)(iVar5 + iVar6 + 0x28a) =
                                                       (short)*(undefined4 *)(iVar4 + 0x14);
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x4c) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,&DAT_0068376c);
                                                  strncpy((char *)(iVar5 + iVar6),
                                                          *(char **)(iVar4 + 0x10),0x100);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                  if (*(int *)(iVar4 + 0x10) == 0) {
                                                    iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                    if (*(int *)(iVar4 + 0x14) != 0) {
                                                      iVar5 = *(int *)(*(int *)(uVar10 + 0x4c) + 4);
                                                      iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                      uVar8 = (undefined2)
                                                              *(undefined4 *)(iVar4 + 0x14);
                                                      goto LAB_00500128;
                                                    }
                                                    *(undefined2 *)
                                                     (*(int *)(*(int *)(uVar10 + 0x4c) + 4) + iVar6
                                                     + 0x288) = 0;
                                                  }
                                                  else {
                                                    iVar5 = *(int *)(*(int *)(uVar10 + 0x4c) + 4);
                                                    iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                    iVar4 = atoi(*(char **)(iVar4 + 0x10));
                                                    uVar8 = (undefined2)iVar4;
LAB_00500128:
                                                    *(undefined2 *)(iVar5 + iVar6 + 0x288) = uVar8;
                                                  }
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x4c) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"protocol");
                                                  strncpy((char *)(iVar5 + iVar6 + 0x100),
                                                          *(char **)(iVar4 + 0x10),0x10);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"user_name");
                                                  if (iVar4 != 0) {
                                                    iVar5 = *(int *)(*(int *)(uVar10 + 0x4c) + 4);
                                                    iVar4 = cJSON_GetObjectItem(iVar19,"user_name");
                                                    strncpy((char *)(iVar5 + iVar6 + 0x110),
                                                            *(char **)(iVar4 + 0x10),0x100);
                                                  }
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"passwd");
                                                  if (iVar4 != 0) {
                                                    iVar4 = *(int *)(*(int *)(uVar10 + 0x4c) + 4);
                                                    iVar19 = cJSON_GetObjectItem(iVar19,"passwd");
                                                    strncpy((char *)(iVar4 + iVar6 + 0x210),
                                                            *(char **)(iVar19 + 0x10),0x78);
                                                  }
                                                }
                                              }
                                              else {
                                                iVar20 = 0;
                                                iVar19 = strcmp(pcVar13,"web");
                                                if (iVar19 == 0) {
                                                  while (iVar20 < local_4c) {
                                                    iVar19 = cJSON_GetArrayItem(iVar18,iVar20);
                                                    if (((iVar19 == 0) ||
                                                        (iVar4 = cJSON_GetObjectItem(iVar19,
                                                  "ser_index"), iVar4 == 0)) ||
                                                  (iVar4 = cJSON_GetObjectItem(iVar19,&DAT_00677ca8)
                                                  , iVar4 == 0)) {
                                                    if (sensor_test_err_switch == '\0')
                                                    goto LAB_0050027c;
                                                    uVar12 = 0x42e;
                                                    pcVar15 = "web";
                                                    goto LAB_00500788;
                                                  }
                                                  iVar6 = iVar20 * 0x104;
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x50) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"ser_index");
                                                  *(short *)(iVar5 + iVar6 + 0x102) =
                                                       (short)*(undefined4 *)(iVar4 + 0x14);
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x50) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,&DAT_00677ca8);
                                                  strncpy((char *)(iVar5 + iVar6),
                                                          *(char **)(iVar4 + 0x10),0x100);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                  if (iVar4 == 0) {
LAB_005003d4:
                                                    iVar20 = iVar20 + 1;
                                                  }
                                                  else {
                                                    iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                    if (*(int *)(iVar4 + 0x10) != 0) {
                                                      iVar4 = *(int *)(*(int *)(uVar10 + 0x50) + 4);
                                                      iVar19 = cJSON_GetObjectItem(iVar19,"port");
                                                      iVar19 = atoi(*(char **)(iVar19 + 0x10));
                                                      *(short *)(iVar4 + iVar6 + 0x100) =
                                                           (short)iVar19;
                                                      goto LAB_005003d4;
                                                    }
                                                    iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                    iVar6 = *(int *)(*(int *)(uVar10 + 0x50) + 4) +
                                                            iVar6;
                                                    if (*(int *)(iVar4 + 0x14) == 0) {
                                                      *(undefined2 *)(iVar6 + 0x100) = 0;
                                                      iVar20 = iVar20 + 1;
                                                    }
                                                    else {
                                                      iVar19 = cJSON_GetObjectItem(iVar19,"port");
                                                      iVar20 = iVar20 + 1;
                                                      *(short *)(iVar6 + 0x100) =
                                                           (short)*(undefined4 *)(iVar19 + 0x14);
                                                    }
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar20 = 0;
                                                  iVar19 = strcmp(pcVar13,"ftp");
                                                  if (iVar19 == 0) {
                                                    for (; iVar20 < local_48; iVar20 = iVar20 + 1) {
                                                      iVar19 = cJSON_GetArrayItem(iVar18,iVar20);
                                                      if (((((iVar19 == 0) ||
                                                            (iVar4 = cJSON_GetObjectItem(iVar19,
                                                  "ser_index"), iVar4 == 0)) ||
                                                  ((iVar4 = cJSON_GetObjectItem(iVar19,&DAT_0068376c
                                                                               ), iVar4 == 0 ||
                                                   ((iVar4 = cJSON_GetObjectItem(iVar19,"port"),
                                                    iVar4 == 0 ||
                                                    (iVar4 = cJSON_GetObjectItem(iVar19,"user_name")
                                                    , iVar4 == 0)))))) ||
                                                  (iVar4 = cJSON_GetObjectItem(iVar19,"passwd"),
                                                  iVar4 == 0)) ||
                                                  ((iVar4 = cJSON_GetObjectItem(iVar19,"trans_type")
                                                   , iVar4 == 0 ||
                                                   (iVar4 = cJSON_GetObjectItem(iVar19,"path"),
                                                   iVar4 == 0)))) {
                                                    if (sensor_test_err_switch == '\0')
                                                    goto LAB_0050027c;
                                                    uVar12 = 0x453;
                                                    pcVar15 = "ftp";
                                                    goto LAB_00500788;
                                                  }
                                                  iVar6 = iVar20 * 0xa8e;
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x54) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"ser_index");
                                                  *(short *)(iVar5 + iVar6 + 0xa8c) =
                                                       (short)*(undefined4 *)(iVar4 + 0x14);
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x54) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,&DAT_0068376c);
                                                  strncpy((char *)(iVar5 + iVar6),
                                                          *(char **)(iVar4 + 0x10),0x100);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                  if (*(int *)(iVar4 + 0x10) == 0) {
                                                    iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                    if (*(int *)(iVar4 + 0x14) != 0) {
                                                      iVar5 = *(int *)(*(int *)(uVar10 + 0x54) + 4);
                                                      iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                      uVar8 = (undefined2)
                                                              *(undefined4 *)(iVar4 + 0x14);
                                                      goto LAB_00500940;
                                                    }
                                                    *(undefined2 *)
                                                     (*(int *)(*(int *)(uVar10 + 0x54) + 4) + iVar6
                                                     + 0xa8a) = 0;
                                                  }
                                                  else {
                                                    iVar5 = *(int *)(*(int *)(uVar10 + 0x54) + 4);
                                                    iVar4 = cJSON_GetObjectItem(iVar19,"port");
                                                    iVar4 = atoi(*(char **)(iVar4 + 0x10));
                                                    uVar8 = (undefined2)iVar4;
LAB_00500940:
                                                    *(undefined2 *)(iVar5 + iVar6 + 0xa8a) = uVar8;
                                                  }
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x54) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"user_name");
                                                  strncpy((char *)(iVar5 + iVar6 + 0x100),
                                                          *(char **)(iVar4 + 0x10),0x100);
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x54) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"passwd");
                                                  strncpy((char *)(iVar5 + iVar6 + 0x200),
                                                          *(char **)(iVar4 + 0x10),0x78);
                                                  iVar5 = *(int *)(*(int *)(uVar10 + 0x54) + 4);
                                                  iVar4 = cJSON_GetObjectItem(iVar19,"trans_type");
                                                  strncpy((char *)(iVar5 + iVar6 + 0x278),
                                                          *(char **)(iVar4 + 0x10),0x10);
                                                  iVar4 = *(int *)(*(int *)(uVar10 + 0x54) + 4);
                                                  iVar19 = cJSON_GetObjectItem(iVar19,"path");
                                                  strncpy((char *)(iVar4 + iVar6 + 0x288),
                                                          *(char **)(iVar19 + 0x10),0x801);
                                                  }
                                                  }
                                                  else {
                                                    iVar19 = strcmp(pcVar13,"speed");
                                                    if (iVar19 == 0) {
                                                      iVar18 = cJSON_GetArrayItem(iVar18,0);
                                                      if (((iVar18 != 0) &&
                                                          (iVar19 = cJSON_GetObjectItem(iVar18,
                                                  "ser_index"), iVar19 != 0)) &&
                                                  (iVar19 = cJSON_GetObjectItem(iVar18,&DAT_00677ca8
                                                                               ), iVar19 != 0)) {
                                                    iVar20 = *(int *)(uVar10 + 0x58);
                                                    iVar19 = cJSON_GetObjectItem(iVar18,"ser_index")
                                                    ;
                                                    *(short *)(iVar20 + 0x802) =
                                                         (short)*(undefined4 *)(iVar19 + 0x14);
                                                    pcVar13 = *(char **)(uVar10 + 0x58);
                                                    iVar18 = cJSON_GetObjectItem(iVar18,&
                                                  DAT_00677ca8);
                                                  __n = 0x801;
                                                  pcVar16 = *(char **)(iVar18 + 0x10);
                                                  goto LAB_0050025c;
                                                  }
                                                  if (sensor_test_err_switch != '\0') {
                                                    uVar12 = 0x465;
                                                    pcVar15 = "speed";
                                                    goto LAB_00500788;
                                                  }
                                                  goto LAB_0050027c;
                                                  }
                                                  iVar18 = strcmp(pcVar13,"delayloss");
                                                  if ((iVar18 != 0) &&
                                                     (sensor_test_warning_switch != '\0')) {
                                                    pcVar16 = 
                                                  "[SENSOR_TEST_WARNING]%s()/%d find invalid test item name=%s\n"
                                                  ;
                                                  uVar12 = 0x471;
                                                  goto LAB_004ffe4c;
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
LAB_004ffc8c:
                                  local_54 = local_54 + 1;
                                } while (local_54 != pcVar15);
                              }
                              if (sensor_test_debug_switch != '\0') {
                                printf("[SENSOR_TEST_DEBUG]%s()/%d db_init_service_info success\n",
                                       "_sensor_test_sqlite_service_info_init",0x475);
                              }
                              goto LAB_004ff5f8;
                            }
LAB_0050028c:
                            if (sensor_test_err_switch != '\0') {
                              pcVar15 = "[SENSOR_TEST_ERROR]%s()/%d init service info fail\n";
                              uVar12 = 0x57a;
                              goto LAB_005002a8;
                            }
                          }
                          else {
                            iVar2 = strcmp(pcVar13,"key");
                            if (iVar2 == 0) goto LAB_004ff1b4;
                            if (sensor_test_err_switch != '\0') {
                              pcVar15 = "[SENSOR_TEST_ERROR]%s()/%d Invalid column_name[%s]\n";
                              uVar12 = 0x587;
                              goto LAB_004ff484;
                            }
                          }
                        }
                      }
LAB_004ff4ec:
                      if (sensor_test_err_switch == '\0') {
                        uVar10 = __s[1];
                      }
                      else {
                        printf("[SENSOR_TEST_ERROR]%s()/%d init case fail,test_case_id=%d\n",
                               "_sensor_test_sqlite_test_case_init_cb",0x593,*__s);
                        uVar10 = __s[1];
                      }
                      sensor_test_db_service_nested_mem_free(uVar10 + 0x3c);
                      uVar10 = __s[1];
                      if (uVar10 != 0) {
                        if (*(int *)(uVar10 + 0x38) == 0) {
                          iVar2 = *(int *)(uVar10 + 0x34);
                        }
                        else {
                          FUN_00407df0();
                          *(undefined4 *)(__s[1] + 0x38) = 0;
                          iVar2 = *(int *)(__s[1] + 0x34);
                        }
                        if (iVar2 == 0) {
                          uVar10 = __s[1];
                        }
                        else {
                          FUN_00407df0();
                          *(undefined4 *)(__s[1] + 0x34) = 0;
                          uVar10 = __s[1];
                        }
                        if (*(int *)(uVar10 + 0x30) != 0) {
                          FUN_00407df0();
                          *(undefined4 *)(__s[1] + 0x30) = 0;
                        }
                        FUN_00407df0(__s[1]);
                        __s[1] = 0;
                      }
                      goto LAB_004ff3c0;
                    }
                    uVar10 = __s[1];
                    iVar2 = atoi(pcVar15);
                    *(char *)(uVar10 + 0xc) = (char)iVar2;
                  }
                }
              }
            }
          }
        }
LAB_004ff1b4:
        local_3c = local_3c + 1;
        local_30 = local_30 + 1;
        local_38 = local_38 + 1;
      } while( true );
    }
    uVar12 = 1;
    if (sensor_test_err_switch == '\0') {
      return 1;
    }
    pcVar15 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc case_tmp fail\n";
    uVar11 = 0x496;
  }
LAB_004ff2fc:
  printf(pcVar15,"_sensor_test_sqlite_test_case_init_cb",uVar11);
  return uVar12;
}

