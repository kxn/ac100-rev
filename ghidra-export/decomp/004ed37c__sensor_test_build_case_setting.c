// func _sensor_test_build_case_setting @ 004ed37c size=12960

undefined2 * _sensor_test_build_case_setting(undefined4 param_1)

{
  undefined2 *__s;
  int iVar1;
  int iVar2;
  byte bVar11;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar9;
  undefined1 uVar12;
  int iVar6;
  int iVar7;
  ushort uVar10;
  int iVar8;
  undefined4 extraout_v1;
  char *pcVar13;
  char *pcVar14;
  undefined4 uVar15;
  size_t sVar16;
  undefined2 uVar17;
  ushort *puVar18;
  undefined2 *puVar19;
  uint uVar20;
  undefined8 uVar21;
  char acStack_258 [31];
  undefined1 local_239;
  char local_238 [12];
  uint local_22c;
  undefined1 local_1c1;
  char acStack_1c0 [119];
  undefined1 local_149;
  char acStack_148 [255];
  undefined1 local_49;
  undefined2 *local_48;
  int local_44;
  int local_40;
  char *local_3c;
  int local_38;
  int local_34;
  char *local_30;
  undefined4 local_2c;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_build_case_setting ENTER\n",
           "_sensor_test_build_case_setting",0xb2e);
  }
  __s = (undefined2 *)FUN_00408450(0x5c,0xb37);
  if (__s == (undefined2 *)0x0) {
    if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
    pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d build case setting  mem melloc setting fail\n";
    uVar15 = 0xb3a;
  }
  else {
    memset(__s,0,0x5c);
    iVar1 = json_object_object_get(param_1,"test_case_name");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_sensor_test_build_case_setting",0xb42);
      }
      pcVar13 = "";
    }
    else {
      pcVar13 = (char *)json_object_get_string(iVar1);
    }
    strncpy((char *)((int)__s + 0xd),pcVar13,0x1f);
    *(undefined1 *)(__s + 0x16) = 0;
    iVar1 = json_object_object_get(param_1,"sch_type");
    if (iVar1 == 0) {
LAB_004ed470:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_build_case_setting",0xb45);
      }
      uVar9 = 0xffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar9 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_004ed470;
        uVar21 = json_object_get_double(iVar1);
        uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
      }
    }
    *__s = uVar9;
    iVar1 = json_object_object_get(param_1,"sch_period");
    if (iVar1 == 0) {
LAB_004ed4c8:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_build_case_setting",0xb48);
      }
      uVar9 = 0xffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar9 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_004ed4c8;
        uVar21 = json_object_get_double(iVar1);
        uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
      }
    }
    __s[1] = uVar9;
    iVar1 = json_object_object_get(param_1,"change_id");
    if (iVar1 == 0) {
LAB_004ed520:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_build_case_setting",0xb4b);
      }
      uVar12 = 0xff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar12 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_004ed520;
        uVar21 = json_object_get_double(iVar1);
        uVar12 = __fixunsdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
      }
    }
    *(undefined1 *)(__s + 4) = uVar12;
    iVar1 = json_object_object_get(param_1,"sch_time");
    if (iVar1 == 0) {
      *(undefined4 *)(__s + 2) = 0;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        json_object_get_int64(iVar1);
        *(undefined4 *)(__s + 2) = extraout_v1;
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar21 = json_object_get_double(iVar1);
          uVar15 = __fixunsdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
          *(undefined4 *)(__s + 2) = uVar15;
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int64 with error obj or value type is unmatch.\n",
                   "_sensor_test_build_case_setting",0xb50);
          }
          *(undefined4 *)(__s + 2) = 0xffffffff;
        }
      }
    }
    iVar1 = json_object_object_get(param_1,"rssi_threshold");
    uVar12 = 0xa6;
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar12 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar21 = json_object_get_double(iVar1);
          uVar12 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
        }
        else if (jcs_err_switch == 0) {
          uVar12 = 0xff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_sensor_test_build_case_setting",0xb5a);
          uVar12 = 0xff;
        }
      }
    }
    *(undefined1 *)(__s + 6) = uVar12;
    iVar1 = json_object_object_get(param_1,"group_id");
    bVar11 = json_object_array_length(iVar1);
    *(undefined4 *)(__s + 0x18) = 0;
    *(byte *)((int)__s + 9) = bVar11;
    if (bVar11 != 0) {
      pvVar3 = (void *)FUN_00408450((uint)bVar11 << 1,0xb66);
      *(void **)(__s + 0x18) = pvVar3;
      if (pvVar3 == (void *)0x0) {
        if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
        pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d group_list mem melloc fail\n";
        uVar15 = 0xb69;
        goto LAB_004ed8f8;
      }
      memset(pvVar3,0,(uint)*(byte *)((int)__s + 9) << 1);
      if (iVar1 == 0) {
LAB_004ed670:
        uVar20 = 0;
        if (jcs_err_switch == 0) goto LAB_004ed67c;
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "_sensor_test_build_case_setting",0xb6e);
        bVar11 = *(byte *)((int)__s + 9);
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 != 5) {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 4) {
            iVar1 = json_object_object_length(iVar1);
            uVar20 = 0;
            if (iVar1 == 0) goto LAB_004ed67c;
          }
          goto LAB_004ed670;
        }
        iVar2 = 0;
        uVar20 = 0;
        while (iVar4 = json_object_array_length(iVar1), (int)uVar20 < iVar4) {
          if ((int)(uint)*(byte *)((int)__s + 9) <= (int)uVar20) {
            uVar20 = uVar20 & 0xff;
            goto LAB_004ed67c;
          }
          iVar4 = json_object_array_get_idx(iVar1,uVar20);
          if (iVar4 == 0) {
LAB_004edc0c:
            if (jcs_err_switch == 0) {
              iVar4 = *(int *)(__s + 0x18);
            }
            else {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_sensor_test_build_case_setting",0xb6e);
              iVar4 = *(int *)(__s + 0x18);
            }
            uVar20 = uVar20 + 1;
            puVar19 = (undefined2 *)(iVar4 + iVar2);
            iVar2 = iVar2 + 2;
            *puVar19 = 0xffff;
          }
          else {
            iVar6 = json_object_get_type(iVar4);
            if (iVar6 == 3) {
              iVar6 = *(int *)(__s + 0x18);
              uVar9 = json_object_get_int(iVar4);
              *(undefined2 *)(iVar6 + iVar2) = uVar9;
            }
            else {
              iVar6 = json_object_get_type(iVar4);
              if (iVar6 != 2) goto LAB_004edc0c;
              iVar6 = *(int *)(__s + 0x18);
              uVar21 = json_object_get_double(iVar4);
              uVar9 = __fixunsdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
              *(undefined2 *)(iVar6 + iVar2) = uVar9;
            }
            uVar20 = uVar20 + 1;
            iVar2 = iVar2 + 2;
          }
        }
        uVar20 = uVar20 & 0xff;
LAB_004ed67c:
        bVar11 = *(byte *)((int)__s + 9);
      }
      if (bVar11 < uVar20) {
        if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
        pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d n > group_list\n";
        uVar15 = 0xb71;
        goto LAB_004ed8f8;
      }
    }
    uVar15 = json_object_object_get(param_1,"join_test_sensor");
    bVar11 = json_object_array_length(uVar15);
    *(undefined4 *)(__s + 0x1a) = 0;
    *(byte *)(__s + 5) = bVar11;
    if (bVar11 != 0) {
      pvVar3 = (void *)FUN_00408450((uint)bVar11 << 2,0xb7b);
      *(void **)(__s + 0x1a) = pvVar3;
      if (pvVar3 == (void *)0x0) {
        if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
        pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d join_test_sensor_list mem melloc fail\n";
        uVar15 = 0xb7e;
        goto LAB_004ed8f8;
      }
      memset(pvVar3,0,(uint)*(byte *)(__s + 5) << 2);
      iVar2 = 0;
      for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(__s + 5); iVar1 = iVar1 + 1) {
        iVar4 = json_object_array_get_idx(uVar15,iVar1);
        if (iVar4 == 0) {
LAB_004ed788:
          iVar4 = json_object_array_get_idx(uVar15,iVar1);
          if (iVar4 != 0) {
            uVar5 = json_object_array_get_idx(uVar15,iVar1);
            iVar4 = json_object_get_type(uVar5);
            if (iVar4 == 2) {
              iVar4 = *(int *)(__s + 0x1a);
              uVar5 = json_object_array_get_idx(uVar15,iVar1);
              uVar21 = json_object_get_double(uVar5);
              uVar9 = __fixunsdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
              *(undefined2 *)(iVar4 + iVar2) = uVar9;
              goto LAB_004ed734;
            }
          }
          if (jcs_err_switch == 0) {
            iVar4 = *(int *)(__s + 0x1a);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_build_case_setting",0xb84);
            iVar4 = *(int *)(__s + 0x1a);
          }
          *(undefined2 *)(iVar4 + iVar2) = 0xffff;
        }
        else {
          uVar5 = json_object_array_get_idx(uVar15,iVar1);
          iVar4 = json_object_get_type(uVar5);
          if (iVar4 != 3) goto LAB_004ed788;
          iVar4 = *(int *)(__s + 0x1a);
          uVar5 = json_object_array_get_idx(uVar15,iVar1);
          uVar9 = json_object_get_int(uVar5);
          *(undefined2 *)(iVar4 + iVar2) = uVar9;
        }
LAB_004ed734:
        iVar4 = *(int *)(__s + 0x1a) + iVar2;
        iVar2 = iVar2 + 4;
        *(undefined1 *)(iVar4 + 2) = 0;
      }
    }
    iVar1 = json_object_object_get(param_1,"ssid_info");
    if (((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 5)) ||
       (iVar2 = json_object_array_length(iVar1), iVar2 < 1)) {
      if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
      pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d parse ssid_info fail, not an array or it is empty\n";
      uVar15 = 0xb8d;
    }
    else {
      bVar11 = json_object_array_length(iVar1);
      *(undefined4 *)(__s + 0x1c) = 0;
      *(byte *)((int)__s + 0xb) = bVar11;
      if (bVar11 == 0) {
LAB_004ee060:
        puVar18 = __s + 0x1e;
        local_2c = json_object_object_get(param_1,"service");
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_build_case_setting_service ENTER\n",
                 "_sensor_test_build_case_setting_service",0x92f);
        }
        local_238[0] = '\0';
        local_238[1] = '\0';
        local_238[2] = '\0';
        local_238[3] = '\0';
        local_238[4] = '\0';
        local_238[5] = '\0';
        local_238[6] = '\0';
        local_238[7] = '\0';
        local_238[8] = '\0';
        local_238[9] = '\0';
        local_238[10] = '\0';
        local_238[0xb] = '\0';
        local_22c = 0;
        local_30 = (char *)json_object_array_length(local_2c);
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d service_array_cnt=%d\n",
                 "_sensor_test_build_case_setting_service",0x938,local_30);
        }
        iVar1 = 0;
        puVar19 = __s;
        if ((int)local_30 < 1) {
LAB_004eedd8:
          if (sensor_test_debug_switch == '\0') {
            return puVar19;
          }
          printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_build_case_setting success EXIT\n",
                 "_sensor_test_build_case_setting",0xbf9);
          return puVar19;
        }
        __s[0x1e] = 0;
        iVar2 = 0;
        local_48 = (undefined2 *)0x0;
        pcVar13 = (char *)0x0;
        local_40 = 0;
        local_44 = 0;
        local_34 = 0;
        local_38 = 0;
        do {
          uVar15 = json_object_array_get_idx(local_2c,pcVar13);
          iVar4 = json_object_object_get(uVar15,"ser_name");
          if (iVar4 == 0) {
            if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
            pcVar14 = 
            "[SENSOR_TEST_ERROR]%s()/%d get service_array item fail,no ser_name with idx=%d\n";
            uVar15 = 0x955;
            goto LAB_004eef5c;
          }
          local_238[0] = '\0';
          local_238[1] = '\0';
          local_238[2] = '\0';
          local_238[3] = '\0';
          local_238[4] = '\0';
          local_238[5] = '\0';
          local_238[6] = '\0';
          local_238[7] = '\0';
          local_238[8] = '\0';
          local_238[9] = '\0';
          local_238[10] = '\0';
          local_238[0xb] = '\0';
          local_22c = 0;
          iVar6 = json_object_get_type(iVar4);
          if (iVar6 == 6) {
            pcVar14 = (char *)json_object_get_string(iVar4);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_sensor_test_build_case_setting_service",0x959);
            }
            pcVar14 = "";
          }
          strncpy(local_238,pcVar14,0xf);
          local_22c = local_22c & 0xffffff00;
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d ser_name[%d] str is = %s\n",
                   "_sensor_test_build_case_setting_service",0x95a,pcVar13,local_238);
          }
          iVar4 = json_object_object_get(uVar15,"params");
          if (iVar4 == 0) {
            if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
            pcVar14 = "[SENSOR_TEST_ERROR]%s()/%d get service array\'s params fail, with idx=%d\n";
            uVar15 = 0x95f;
            goto LAB_004eef5c;
          }
          iVar6 = json_object_array_length(iVar4);
          if (iVar6 < 1) {
            if (sensor_test_err_switch != '\0') {
              printf("[SENSOR_TEST_ERROR]%s()/%d param array is empty\n",
                     "_sensor_test_build_case_setting_service",0x964);
            }
          }
          else {
            iVar6 = strcmp(local_238,"onboarding");
            if (iVar6 == 0) {
              uVar10 = *puVar18 | 1;
LAB_004ee1b0:
              *puVar18 = uVar10;
            }
            else {
              iVar6 = strcmp(local_238,"dns");
              if (iVar6 == 0) {
                *puVar18 = *puVar18 | 2;
                iVar2 = json_object_array_length(iVar4);
              }
              else {
                iVar6 = strcmp(local_238,"hostaccess");
                if (iVar6 == 0) {
                  *puVar18 = *puVar18 | 4;
                  local_38 = json_object_array_length(iVar4);
                }
                else {
                  iVar6 = strcmp(local_238,"radius");
                  if (iVar6 == 0) {
                    *puVar18 = *puVar18 | 8;
                    iVar1 = json_object_array_length(iVar4);
                  }
                  else {
                    iVar6 = strcmp(local_238,"mail");
                    if (iVar6 == 0) {
                      *puVar18 = *puVar18 | 0x10;
                      local_34 = json_object_array_length(iVar4);
                    }
                    else {
                      iVar6 = strcmp(local_238,"web");
                      if (iVar6 == 0) {
                        *puVar18 = *puVar18 | 0x20;
                        local_44 = json_object_array_length(iVar4);
                      }
                      else {
                        iVar6 = strcmp(local_238,"ftp");
                        if (iVar6 == 0) {
                          *puVar18 = *puVar18 | 0x40;
                          local_40 = json_object_array_length(iVar4);
                        }
                        else {
                          iVar6 = strcmp(local_238,"speed");
                          if (iVar6 == 0) {
                            *puVar18 = *puVar18 | 0x80;
                            local_48 = (undefined2 *)json_object_array_length(iVar4);
                          }
                          else {
                            iVar4 = strcmp(local_238,"delayloss");
                            if (iVar4 == 0) {
                              uVar10 = *puVar18 | 0x100;
                              goto LAB_004ee1b0;
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
        } while (pcVar13 != local_30);
        if (0 < iVar2) {
          *(undefined4 *)(__s + 0x20) = 0;
          pvVar3 = (void *)FUN_00408450(0x102,0x9ac);
          *(void **)(__s + 0x20) = pvVar3;
          if (pvVar3 != (void *)0x0) {
            memset(pvVar3,0,0x102);
            goto LAB_004ee1f4;
          }
          if (sensor_test_err_switch != '\0') {
            pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc dns fail\n";
            uVar15 = 0x9af;
            goto LAB_004f01d8;
          }
          goto LAB_004eeee4;
        }
LAB_004ee1f4:
        if (0 < local_38) {
          *(undefined4 *)(__s + 0x22) = 0;
          pvVar3 = (void *)FUN_00408450(8,0x9b7);
          *(void **)(__s + 0x22) = pvVar3;
          if (pvVar3 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc hostaccess fail\n";
              uVar15 = 0x9ba;
              goto LAB_004f01d8;
            }
          }
          else {
            memset(pvVar3,0,8);
            **(int **)(__s + 0x22) = local_38;
            sVar16 = local_38 * 0x102;
            *(undefined4 *)(*(int *)(__s + 0x22) + 4) = 0;
            iVar2 = *(int *)(__s + 0x22);
            uVar15 = FUN_00408450(sVar16,0x9c1);
            *(undefined4 *)(iVar2 + 4) = uVar15;
            if (*(void **)(*(int *)(__s + 0x22) + 4) != (void *)0x0) {
              memset(*(void **)(*(int *)(__s + 0x22) + 4),0,sVar16);
              goto LAB_004ee270;
            }
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc hostaccess->addr_array fail\n";
              uVar15 = 0x9c4;
              goto LAB_004f01d8;
            }
          }
          goto LAB_004eeee4;
        }
LAB_004ee270:
        if (0 < iVar1) {
          *(undefined4 *)(__s + 0x24) = 0;
          pvVar3 = (void *)FUN_00408450(0x38c,0x9cc);
          *(void **)(__s + 0x24) = pvVar3;
          if (pvVar3 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc radius fail\n";
              uVar15 = 0x9cf;
              goto LAB_004f01d8;
            }
            goto LAB_004eeee4;
          }
          memset(pvVar3,0,0x38c);
        }
        if (0 < local_34) {
          *(undefined4 *)(__s + 0x26) = 0;
          pvVar3 = (void *)FUN_00408450(8,0x9d7);
          *(void **)(__s + 0x26) = pvVar3;
          if (pvVar3 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc mail fail\n";
              uVar15 = 0x9da;
              goto LAB_004f01d8;
            }
          }
          else {
            memset(pvVar3,0,8);
            **(int **)(__s + 0x26) = local_34;
            sVar16 = local_34 * 0x28c;
            *(undefined4 *)(*(int *)(__s + 0x26) + 4) = 0;
            iVar1 = *(int *)(__s + 0x26);
            uVar15 = FUN_00408450(sVar16,0x9e1);
            *(undefined4 *)(iVar1 + 4) = uVar15;
            if (*(void **)(*(int *)(__s + 0x26) + 4) != (void *)0x0) {
              memset(*(void **)(*(int *)(__s + 0x26) + 4),0,sVar16);
              goto LAB_004ee31c;
            }
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc mail->mail_array fail\n";
              uVar15 = 0x9e4;
              goto LAB_004f01d8;
            }
          }
          goto LAB_004eeee4;
        }
LAB_004ee31c:
        if (0 < local_44) {
          *(undefined4 *)(__s + 0x28) = 0;
          pvVar3 = (void *)FUN_00408450(8,0x9ec);
          *(void **)(__s + 0x28) = pvVar3;
          if (pvVar3 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc web fail\n";
              uVar15 = 0x9ef;
              goto LAB_004f01d8;
            }
          }
          else {
            memset(pvVar3,0,8);
            **(int **)(__s + 0x28) = local_44;
            sVar16 = local_44 * 0x104;
            *(undefined4 *)(*(int *)(__s + 0x28) + 4) = 0;
            iVar1 = *(int *)(__s + 0x28);
            uVar15 = FUN_00408450(sVar16,0x9f6);
            *(undefined4 *)(iVar1 + 4) = uVar15;
            if (*(void **)(*(int *)(__s + 0x28) + 4) != (void *)0x0) {
              memset(*(void **)(*(int *)(__s + 0x28) + 4),0,sVar16);
              goto LAB_004ee398;
            }
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc web->web_array fail\n";
              uVar15 = 0x9f9;
              goto LAB_004f01d8;
            }
          }
          goto LAB_004eeee4;
        }
LAB_004ee398:
        if (local_40 < 1) {
LAB_004ee414:
          if (0 < (int)local_48) {
            *(undefined4 *)(__s + 0x2c) = 0;
            pvVar3 = (void *)FUN_00408450(0x804,0xa16);
            *(void **)(__s + 0x2c) = pvVar3;
            if (pvVar3 == (void *)0x0) {
              if (sensor_test_err_switch != '\0') {
                pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc speed fail\n";
                uVar15 = 0xa19;
                goto LAB_004f01d8;
              }
              goto LAB_004eeee4;
            }
            memset(pvVar3,0,0x804);
          }
          local_3c = (char *)0x0;
          local_48 = __s;
LAB_004ee454:
          uVar15 = json_object_array_get_idx(local_2c,local_3c);
          iVar1 = json_object_object_get(uVar15,"ser_name");
          if (iVar1 == 0) {
            __s = local_48;
            if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
            pcVar14 = "[SENSOR_TEST_ERROR]%s()/%d get obj item fail=%s\n";
            uVar15 = 0xa27;
            pcVar13 = "ser_name";
            goto LAB_004eef5c;
          }
          local_238[0] = '\0';
          local_238[1] = '\0';
          local_238[2] = '\0';
          local_238[3] = '\0';
          local_238[4] = '\0';
          local_238[5] = '\0';
          local_238[6] = '\0';
          local_238[7] = '\0';
          local_238[8] = '\0';
          local_238[9] = '\0';
          local_238[10] = '\0';
          local_238[0xb] = '\0';
          local_22c = 0;
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 6) {
            pcVar13 = (char *)json_object_get_string(iVar1);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_sensor_test_build_case_setting_service",0xa2b);
            }
            pcVar13 = "";
          }
          strncpy(local_238,pcVar13,0xf);
          local_22c = local_22c & 0xffffff00;
          iVar1 = json_object_object_get(uVar15,"params");
          if (iVar1 == 0) {
            __s = local_48;
            if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
            pcVar14 = "[SENSOR_TEST_ERROR]%s()/%d get service array\'s params fail, with idx=%d\n";
            uVar15 = 0xa30;
            pcVar13 = local_3c;
            goto LAB_004eef5c;
          }
          iVar2 = strcmp(local_238,"onboarding");
          if (iVar2 == 0) {
            iVar1 = json_object_array_get_idx(iVar1,0);
            if ((iVar1 != 0) && (iVar2 = json_object_object_get(iVar1,"ser_index"), iVar2 != 0)) {
              iVar1 = json_object_object_get(iVar1,"ser_index");
              if (iVar1 == 0) {
LAB_004ef0a0:
                if (jcs_err_switch == 0) {
                  __s[0x1f] = 0xffff;
                }
                else {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_test_build_case_setting_service",0xa3b);
                  __s[0x1f] = 0xffff;
                }
              }
              else {
                iVar2 = json_object_get_type(iVar1);
                if (iVar2 == 3) {
                  uVar9 = json_object_get_int(iVar1);
                }
                else {
                  iVar2 = json_object_get_type();
                  if (iVar2 != 2) goto LAB_004ef0a0;
                  uVar21 = json_object_get_double(iVar1);
                  uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                }
                __s[0x1f] = uVar9;
              }
              goto LAB_004eedc4;
            }
            __s = local_48;
            if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
            pcVar14 = 
            "[SENSOR_TEST_ERROR]%s()/%d build service fail,no requried field,by service_name=%s\n";
            uVar15 = 0xa40;
            pcVar13 = "onboarding";
            goto LAB_004eef5c;
          }
          iVar2 = strcmp(local_238,"dns");
          if (iVar2 == 0) {
            iVar1 = json_object_array_get_idx(iVar1,0);
            if (((iVar1 == 0) || (iVar2 = json_object_object_get(iVar1,"ser_index"), iVar2 == 0)) ||
               (iVar2 = json_object_object_get(iVar1,"domain"), iVar2 == 0)) {
              __s = local_48;
              if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
              pcVar14 = 
              "[SENSOR_TEST_ERROR]%s()/%d build service fail,no requried field,by service_name=%s\n"
              ;
              uVar15 = 0xa54;
              pcVar13 = "dns";
              goto LAB_004eef5c;
            }
            iVar2 = json_object_object_get(iVar1,"ser_index");
            if (iVar2 == 0) {
LAB_004ef6d8:
              uVar17 = 0xffff;
              uVar9 = 0xffff;
              if (jcs_err_switch == 0) goto LAB_004ef6e8;
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_sensor_test_build_case_setting_service",0xa4c);
              iVar2 = *(int *)(__s + 0x20);
            }
            else {
              iVar4 = json_object_get_type(iVar2);
              if (iVar4 == 3) {
                uVar9 = json_object_get_int(iVar2);
              }
              else {
                iVar4 = json_object_get_type();
                if (iVar4 != 2) goto LAB_004ef6d8;
                uVar21 = json_object_get_double(iVar2);
                uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
              }
LAB_004ef6e8:
              uVar17 = uVar9;
              iVar2 = *(int *)(__s + 0x20);
            }
            *(undefined2 *)(iVar2 + 0x100) = uVar17;
            iVar1 = json_object_object_get(iVar1,"domain");
            if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting_service",0xa50);
              }
              pcVar14 = *(char **)(__s + 0x20);
              pcVar13 = "";
            }
            else {
              pcVar14 = *(char **)(__s + 0x20);
              pcVar13 = (char *)json_object_get_string(iVar1);
            }
            strncpy(pcVar14,pcVar13,0xff);
            *(undefined1 *)(*(int *)(__s + 0x20) + 0xff) = 0;
LAB_004eedc4:
            local_3c = local_3c + 1;
            puVar19 = local_48;
            if (local_3c == local_30) goto LAB_004eedd8;
            goto LAB_004ee454;
          }
          iVar4 = 0;
          iVar2 = strcmp(local_238,"hostaccess");
          if (iVar2 == 0) {
            for (; iVar4 < local_38; iVar4 = iVar4 + 1) {
              iVar2 = json_object_array_get_idx(iVar1,iVar4);
              if (((iVar2 == 0) || (iVar6 = json_object_object_get(iVar2,"ser_index"), iVar6 == 0))
                 || (iVar6 = json_object_object_get(iVar2,&DAT_0068376c), iVar6 == 0)) {
                __s = local_48;
                if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
                pcVar14 = 
                "[SENSOR_TEST_ERROR]%s()/%d build service fail,no requried field,by service_name=%s\n"
                ;
                uVar15 = 0xa6a;
                pcVar13 = "hostaccess";
                goto LAB_004eef5c;
              }
              iVar6 = json_object_object_get(iVar2,"ser_index");
              if (iVar6 == 0) {
LAB_004ee5ec:
                uVar9 = 0xffff;
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_test_build_case_setting_service",0xa62);
                  uVar9 = 0xffff;
                }
              }
              else {
                iVar7 = json_object_get_type(iVar6);
                if (iVar7 == 3) {
                  uVar9 = json_object_get_int(iVar6);
                }
                else {
                  iVar7 = json_object_get_type();
                  if (iVar7 != 2) goto LAB_004ee5ec;
                  uVar21 = json_object_get_double(iVar6);
                  uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                }
              }
              iVar6 = iVar4 * 0x102;
              *(undefined2 *)(*(int *)(*(int *)(__s + 0x22) + 4) + iVar6 + 0x100) = uVar9;
              iVar2 = json_object_object_get(iVar2,&DAT_0068376c);
              if ((iVar2 == 0) || (iVar7 = json_object_get_type(iVar2), iVar7 != 6)) {
                if (jcs_err_switch == 0) {
                  iVar2 = *(int *)(__s + 0x22);
                }
                else {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_sensor_test_build_case_setting_service",0xa66);
                  iVar2 = *(int *)(__s + 0x22);
                }
                pcVar13 = "";
                iVar7 = *(int *)(iVar2 + 4);
              }
              else {
                iVar7 = *(int *)(*(int *)(__s + 0x22) + 4);
                pcVar13 = (char *)json_object_get_string(iVar2);
              }
              strncpy((char *)(iVar7 + iVar6),pcVar13,0xff);
              *(undefined1 *)(*(int *)(*(int *)(__s + 0x22) + 4) + iVar6 + 0xff) = 0;
            }
            goto LAB_004eedc4;
          }
          iVar2 = strcmp(local_238,"radius");
          if (iVar2 != 0) {
            iVar4 = 0;
            iVar2 = strcmp(local_238,"mail");
            if (iVar2 == 0) {
              for (; iVar4 < local_34; iVar4 = iVar4 + 1) {
                iVar2 = json_object_array_get_idx(iVar1,iVar4);
                if ((((iVar2 == 0) ||
                     (iVar6 = json_object_object_get(iVar2,"ser_index"), iVar6 == 0)) ||
                    (iVar6 = json_object_object_get(iVar2,&DAT_0068376c), iVar6 == 0)) ||
                   ((iVar6 = json_object_object_get(iVar2,"port"), iVar6 == 0 ||
                    (iVar6 = json_object_object_get(iVar2,"protocol"), iVar6 == 0)))) {
                  __s = local_48;
                  if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
                  pcVar14 = 
                  "[SENSOR_TEST_ERROR]%s()/%d build service fail,no requried field,by service_name=%s\n"
                  ;
                  uVar15 = 0xab8;
                  pcVar13 = "mail";
                  goto LAB_004eef5c;
                }
                iVar6 = json_object_object_get(iVar2,"ser_index");
                if (iVar6 == 0) {
LAB_004ef3d8:
                  uVar9 = 0xffff;
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                           ,"_sensor_test_build_case_setting_service",0xa9d);
                    uVar9 = 0xffff;
                  }
                }
                else {
                  iVar7 = json_object_get_type(iVar6);
                  if (iVar7 == 3) {
                    uVar9 = json_object_get_int(iVar6);
                  }
                  else {
                    iVar7 = json_object_get_type();
                    if (iVar7 != 2) goto LAB_004ef3d8;
                    uVar21 = json_object_get_double(iVar6);
                    uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                  }
                }
                iVar7 = iVar4 * 0x28c;
                *(undefined2 *)(*(int *)(*(int *)(__s + 0x26) + 4) + iVar7 + 0x28a) = uVar9;
                iVar6 = json_object_object_get(iVar2,&DAT_0068376c);
                if ((iVar6 == 0) || (iVar8 = json_object_get_type(iVar6), iVar8 != 6)) {
                  if (jcs_err_switch == 0) {
                    iVar6 = *(int *)(__s + 0x26);
                  }
                  else {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_sensor_test_build_case_setting_service",0xaa1);
                    iVar6 = *(int *)(__s + 0x26);
                  }
                  pcVar13 = "";
                  iVar8 = *(int *)(iVar6 + 4);
                }
                else {
                  iVar8 = *(int *)(*(int *)(__s + 0x26) + 4);
                  pcVar13 = (char *)json_object_get_string(iVar6);
                }
                strncpy((char *)(iVar8 + iVar7),pcVar13,0xff);
                *(undefined1 *)(*(int *)(*(int *)(__s + 0x26) + 4) + iVar7 + 0xff) = 0;
                memset(acStack_258,0,0x20);
                iVar6 = json_object_object_get(iVar2,"port");
                if (iVar6 == 0) {
LAB_004ef4b0:
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_sensor_test_build_case_setting_service",0xaa4);
                  }
                  pcVar13 = "";
                }
                else {
                  uVar15 = json_object_object_get(iVar2,"port");
                  iVar6 = json_object_get_type(uVar15);
                  if (iVar6 != 6) goto LAB_004ef4b0;
                  uVar15 = json_object_object_get(iVar2,"port");
                  pcVar13 = (char *)json_object_get_string(uVar15);
                }
                strncpy(acStack_258,pcVar13,0x1f);
                local_239 = 0;
                iVar8 = *(int *)(*(int *)(__s + 0x26) + 4);
                iVar6 = atoi(acStack_258);
                *(short *)(iVar8 + iVar7 + 0x288) = (short)iVar6;
                iVar6 = json_object_object_get(iVar2,"protocol");
                if ((iVar6 == 0) || (iVar8 = json_object_get_type(iVar6), iVar8 != 6)) {
                  if (jcs_err_switch == 0) {
                    iVar6 = *(int *)(__s + 0x26);
                  }
                  else {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_sensor_test_build_case_setting_service",0xaa8);
                    iVar6 = *(int *)(__s + 0x26);
                  }
                  pcVar13 = "";
                  iVar8 = *(int *)(iVar6 + 4);
                }
                else {
                  iVar8 = *(int *)(*(int *)(__s + 0x26) + 4);
                  pcVar13 = (char *)json_object_get_string(iVar6);
                }
                strncpy((char *)(iVar8 + iVar7 + 0x100),pcVar13,0xf);
                *(undefined1 *)(*(int *)(*(int *)(__s + 0x26) + 4) + iVar7 + 0x10f) = 0;
                iVar6 = json_object_object_get(iVar2,"user_name");
                if (iVar6 != 0) {
                  iVar8 = json_object_get_type(iVar6);
                  if (iVar8 == 6) {
                    iVar8 = *(int *)(*(int *)(__s + 0x26) + 4);
                    pcVar13 = (char *)json_object_get_string(iVar6);
                  }
                  else {
                    if (jcs_err_switch == 0) {
                      iVar6 = *(int *)(__s + 0x26);
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                             ,"_sensor_test_build_case_setting_service",0xaad);
                      iVar6 = *(int *)(__s + 0x26);
                    }
                    pcVar13 = "";
                    iVar8 = *(int *)(iVar6 + 4);
                  }
                  strncpy((char *)(iVar8 + iVar7 + 0x110),pcVar13,0xff);
                  *(undefined1 *)(*(int *)(*(int *)(__s + 0x26) + 4) + iVar7 + 0x20f) = 0;
                }
                iVar2 = json_object_object_get(iVar2,"passwd");
                if (iVar2 != 0) {
                  iVar6 = json_object_get_type(iVar2);
                  if (iVar6 == 6) {
                    iVar6 = *(int *)(*(int *)(__s + 0x26) + 4);
                    pcVar13 = (char *)json_object_get_string(iVar2);
                  }
                  else {
                    if (jcs_err_switch == 0) {
                      iVar2 = *(int *)(__s + 0x26);
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                             ,"_sensor_test_build_case_setting_service",0xab3);
                      iVar2 = *(int *)(__s + 0x26);
                    }
                    pcVar13 = "";
                    iVar6 = *(int *)(iVar2 + 4);
                  }
                  strncpy((char *)(iVar6 + iVar7 + 0x210),pcVar13,0x77);
                  *(undefined1 *)(*(int *)(*(int *)(__s + 0x26) + 4) + iVar7 + 0x287) = 0;
                }
              }
            }
            else {
              iVar4 = 0;
              iVar2 = strcmp(local_238,"web");
              if (iVar2 == 0) {
                for (; iVar4 < local_44; iVar4 = iVar4 + 1) {
                  iVar2 = json_object_array_get_idx(iVar1,iVar4);
                  if (((iVar2 == 0) ||
                      (iVar6 = json_object_object_get(iVar2,"ser_index"), iVar6 == 0)) ||
                     (iVar6 = json_object_object_get(iVar2,&DAT_00677ca8), iVar6 == 0)) {
                    __s = local_48;
                    if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
                    pcVar14 = 
                    "[SENSOR_TEST_ERROR]%s()/%d build service fail,no requried field,by service_name=%s\n"
                    ;
                    uVar15 = 0xad6;
                    pcVar13 = "web";
                    goto LAB_004eef5c;
                  }
                  iVar6 = json_object_object_get(iVar2,"ser_index");
                  if (iVar6 == 0) {
LAB_004ef1fc:
                    uVar9 = 0xffff;
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                             ,"_sensor_test_build_case_setting_service",0xac7);
                      uVar9 = 0xffff;
                    }
                  }
                  else {
                    iVar7 = json_object_get_type(iVar6);
                    if (iVar7 == 3) {
                      uVar9 = json_object_get_int(iVar6);
                    }
                    else {
                      iVar7 = json_object_get_type();
                      if (iVar7 != 2) goto LAB_004ef1fc;
                      uVar21 = json_object_get_double(iVar6);
                      uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                    }
                  }
                  iVar7 = iVar4 * 0x104;
                  *(undefined2 *)(*(int *)(*(int *)(__s + 0x28) + 4) + iVar7 + 0x102) = uVar9;
                  iVar6 = json_object_object_get(iVar2,&DAT_00677ca8);
                  if ((iVar6 == 0) || (iVar8 = json_object_get_type(iVar6), iVar8 != 6)) {
                    if (jcs_err_switch == 0) {
                      iVar6 = *(int *)(__s + 0x28);
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                             ,"_sensor_test_build_case_setting_service",0xacb);
                      iVar6 = *(int *)(__s + 0x28);
                    }
                    pcVar13 = "";
                    iVar8 = *(int *)(iVar6 + 4);
                  }
                  else {
                    iVar8 = *(int *)(*(int *)(__s + 0x28) + 4);
                    pcVar13 = (char *)json_object_get_string(iVar6);
                  }
                  strncpy((char *)(iVar8 + iVar7),pcVar13,0xff);
                  *(undefined1 *)(*(int *)(*(int *)(__s + 0x28) + 4) + iVar7 + 0xff) = 0;
                  memset(acStack_258,0,0x20);
                  iVar6 = json_object_object_get(iVar2,"port");
                  if (iVar6 != 0) {
                    iVar6 = json_object_object_get(iVar2,"port");
                    if (iVar6 == 0) {
LAB_004ef2e0:
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xad0);
                      }
                      pcVar13 = "";
                    }
                    else {
                      uVar15 = json_object_object_get(iVar2,"port");
                      iVar6 = json_object_get_type(uVar15);
                      if (iVar6 != 6) goto LAB_004ef2e0;
                      uVar15 = json_object_object_get(iVar2,"port");
                      pcVar13 = (char *)json_object_get_string(uVar15);
                    }
                    strncpy(acStack_258,pcVar13,0x1f);
                    local_239 = 0;
                    iVar6 = *(int *)(*(int *)(__s + 0x28) + 4);
                    iVar2 = atoi(acStack_258);
                    *(short *)(iVar6 + iVar7 + 0x100) = (short)iVar2;
                  }
                }
              }
              else {
                iVar4 = 0;
                iVar2 = strcmp(local_238,"ftp");
                if (iVar2 == 0) {
                  for (; iVar4 < local_40; iVar4 = iVar4 + 1) {
                    iVar2 = json_object_array_get_idx(iVar1,iVar4);
                    if ((((iVar2 == 0) ||
                         (iVar6 = json_object_object_get(iVar2,"ser_index"), iVar6 == 0)) ||
                        (iVar6 = json_object_object_get(iVar2,&DAT_0068376c), iVar6 == 0)) ||
                       (((iVar6 = json_object_object_get(iVar2,"user_name"), iVar6 == 0 ||
                         (iVar6 = json_object_object_get(iVar2,"passwd"), iVar6 == 0)) ||
                        ((iVar6 = json_object_object_get(iVar2,"trans_type"), iVar6 == 0 ||
                         (iVar6 = json_object_object_get(iVar2,"path"), iVar6 == 0)))))) {
                      __s = local_48;
                      if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
                      pcVar14 = 
                      "[SENSOR_TEST_ERROR]%s()/%d build service fail,no requried field,by service_name=%s\n"
                      ;
                      uVar15 = 0xafe;
                      pcVar13 = "ftp";
                      goto LAB_004eef5c;
                    }
                    iVar6 = json_object_object_get(iVar2,"ser_index");
                    if (iVar6 == 0) {
LAB_004efac0:
                      uVar9 = 0xffff;
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xae5);
                        uVar9 = 0xffff;
                      }
                    }
                    else {
                      iVar7 = json_object_get_type(iVar6);
                      if (iVar7 == 3) {
                        uVar9 = json_object_get_int();
                      }
                      else {
                        iVar7 = json_object_get_type(iVar6);
                        if (iVar7 != 2) goto LAB_004efac0;
                        uVar21 = json_object_get_double(iVar6);
                        uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                      }
                    }
                    iVar7 = iVar4 * 0xa8e;
                    *(undefined2 *)(*(int *)(*(int *)(__s + 0x2a) + 4) + iVar7 + 0xa8c) = uVar9;
                    iVar6 = json_object_object_get(iVar2,&DAT_0068376c);
                    if ((iVar6 == 0) || (iVar8 = json_object_get_type(iVar6), iVar8 != 6)) {
                      if (jcs_err_switch == 0) {
                        iVar6 = *(int *)(__s + 0x2a);
                      }
                      else {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xae9);
                        iVar6 = *(int *)(__s + 0x2a);
                      }
                      pcVar13 = "";
                      iVar8 = *(int *)(iVar6 + 4);
                    }
                    else {
                      iVar8 = *(int *)(*(int *)(__s + 0x2a) + 4);
                      pcVar13 = (char *)json_object_get_string(iVar6);
                    }
                    strncpy((char *)(iVar8 + iVar7),pcVar13,0xff);
                    *(undefined1 *)(*(int *)(*(int *)(__s + 0x2a) + 4) + iVar7 + 0xff) = 0;
                    memset(acStack_258,0,0x20);
                    iVar6 = json_object_object_get(iVar2,"port");
                    if (iVar6 == 0) {
LAB_004efb98:
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xaec);
                      }
                      pcVar13 = "";
                    }
                    else {
                      uVar15 = json_object_object_get(iVar2,"port");
                      iVar6 = json_object_get_type(uVar15);
                      if (iVar6 != 6) goto LAB_004efb98;
                      uVar15 = json_object_object_get(iVar2,"port");
                      pcVar13 = (char *)json_object_get_string(uVar15);
                    }
                    strncpy(acStack_258,pcVar13,0x1f);
                    local_239 = 0;
                    iVar8 = *(int *)(*(int *)(__s + 0x2a) + 4);
                    iVar6 = atoi(acStack_258);
                    *(short *)(iVar8 + iVar7 + 0xa8a) = (short)iVar6;
                    iVar6 = json_object_object_get(iVar2,"user_name");
                    if ((iVar6 == 0) || (iVar8 = json_object_get_type(iVar6), iVar8 != 6)) {
                      if (jcs_err_switch == 0) {
                        iVar6 = *(int *)(__s + 0x2a);
                      }
                      else {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xaf0);
                        iVar6 = *(int *)(__s + 0x2a);
                      }
                      pcVar13 = "";
                      iVar8 = *(int *)(iVar6 + 4);
                    }
                    else {
                      iVar8 = *(int *)(*(int *)(__s + 0x2a) + 4);
                      pcVar13 = (char *)json_object_get_string(iVar6);
                    }
                    strncpy((char *)(iVar8 + iVar7 + 0x100),pcVar13,0xff);
                    *(undefined1 *)(*(int *)(*(int *)(__s + 0x2a) + 4) + iVar7 + 0x1ff) = 0;
                    iVar6 = json_object_object_get(iVar2,"passwd");
                    if ((iVar6 == 0) || (iVar8 = json_object_get_type(iVar6), iVar8 != 6)) {
                      if (jcs_err_switch == 0) {
                        iVar6 = *(int *)(__s + 0x2a);
                      }
                      else {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xaf3);
                        iVar6 = *(int *)(__s + 0x2a);
                      }
                      pcVar13 = "";
                      iVar8 = *(int *)(iVar6 + 4);
                    }
                    else {
                      iVar8 = *(int *)(*(int *)(__s + 0x2a) + 4);
                      pcVar13 = (char *)json_object_get_string(iVar6);
                    }
                    strncpy((char *)(iVar8 + iVar7 + 0x200),pcVar13,0x77);
                    *(undefined1 *)(*(int *)(*(int *)(__s + 0x2a) + 4) + iVar7 + 0x277) = 0;
                    iVar6 = json_object_object_get(iVar2,"trans_type");
                    if ((iVar6 == 0) || (iVar8 = json_object_get_type(iVar6), iVar8 != 6)) {
                      if (jcs_err_switch == 0) {
                        iVar6 = *(int *)(__s + 0x2a);
                      }
                      else {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xaf6);
                        iVar6 = *(int *)(__s + 0x2a);
                      }
                      pcVar13 = "";
                      iVar8 = *(int *)(iVar6 + 4);
                    }
                    else {
                      iVar8 = *(int *)(*(int *)(__s + 0x2a) + 4);
                      pcVar13 = (char *)json_object_get_string(iVar6);
                    }
                    strncpy((char *)(iVar8 + iVar7 + 0x278),pcVar13,0xf);
                    *(undefined1 *)(*(int *)(*(int *)(__s + 0x2a) + 4) + iVar7 + 0x287) = 0;
                    iVar2 = json_object_object_get(iVar2,"path");
                    if ((iVar2 == 0) || (iVar6 = json_object_get_type(iVar2), iVar6 != 6)) {
                      if (jcs_err_switch == 0) {
                        iVar2 = *(int *)(__s + 0x2a);
                      }
                      else {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xaf9);
                        iVar2 = *(int *)(__s + 0x2a);
                      }
                      pcVar13 = "";
                      iVar6 = *(int *)(iVar2 + 4);
                    }
                    else {
                      iVar6 = *(int *)(*(int *)(__s + 0x2a) + 4);
                      pcVar13 = (char *)json_object_get_string(iVar2);
                    }
                    strncpy((char *)(iVar6 + iVar7 + 0x288),pcVar13,0x800);
                    *(undefined1 *)(*(int *)(*(int *)(__s + 0x2a) + 4) + iVar7 + 0xa88) = 0;
                  }
                }
                else {
                  iVar2 = strcmp(local_238,"speed");
                  if (iVar2 == 0) {
                    iVar1 = json_object_array_get_idx(iVar1,0);
                    if (((iVar1 == 0) ||
                        (iVar2 = json_object_object_get(iVar1,"ser_index"), iVar2 == 0)) ||
                       (iVar2 = json_object_object_get(iVar1,&DAT_00677ca8), iVar2 == 0)) {
                      __s = local_48;
                      if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
                      pcVar14 = 
                      "[SENSOR_TEST_ERROR]%s()/%d build service fail,no requried field,by service_name=%s\n"
                      ;
                      uVar15 = 0xb13;
                      pcVar13 = "speed";
                      goto LAB_004eef5c;
                    }
                    iVar2 = json_object_object_get(iVar1,"ser_index");
                    if (iVar2 == 0) {
LAB_004f042c:
                      uVar9 = 0xffff;
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xb0b);
                      }
                    }
                    else {
                      iVar4 = json_object_get_type(iVar2);
                      if (iVar4 == 3) {
                        uVar9 = json_object_get_int(iVar2);
                      }
                      else {
                        iVar4 = json_object_get_type();
                        if (iVar4 != 2) goto LAB_004f042c;
                        uVar21 = json_object_get_double(iVar2);
                        uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                      }
                    }
                    *(undefined2 *)(*(int *)(__s + 0x2c) + 0x802) = uVar9;
                    iVar1 = json_object_object_get(iVar1,&DAT_00677ca8);
                    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_sensor_test_build_case_setting_service",0xb0f);
                      }
                      pcVar14 = *(char **)(__s + 0x2c);
                      pcVar13 = "";
                    }
                    else {
                      pcVar14 = *(char **)(__s + 0x2c);
                      pcVar13 = (char *)json_object_get_string(iVar1);
                    }
                    strncpy(pcVar14,pcVar13,0x800);
                    *(undefined1 *)(*(int *)(__s + 0x2c) + 0x800) = 0;
                  }
                  else {
                    iVar1 = strcmp(local_238,"delayloss");
                    if ((iVar1 != 0) && (sensor_test_debug_switch != '\0')) {
                      printf("[SENSOR_TEST_DEBUG]%s()/%d find invalid test item name=%s\n",
                             "_sensor_test_build_case_setting_service",0xb1f,local_238);
                    }
                  }
                }
              }
            }
            goto LAB_004eedc4;
          }
          iVar1 = json_object_array_get_idx(iVar1,0);
          if (((iVar1 != 0) && (iVar2 = json_object_object_get(iVar1,"ser_index"), iVar2 != 0)) &&
             ((iVar2 = json_object_object_get(iVar1,&DAT_0068376c), iVar2 != 0 &&
              ((((iVar2 = json_object_object_get(iVar1,"user_name"), iVar2 != 0 &&
                 (iVar2 = json_object_object_get(iVar1,"passwd"), iVar2 != 0)) &&
                (iVar2 = json_object_object_get(iVar1,"share_key"), iVar2 != 0)) &&
               (iVar2 = json_object_object_get(iVar1,"auth_type"), iVar2 != 0)))))) {
            iVar2 = json_object_object_get(iVar1,"ser_index");
            if (iVar2 == 0) {
LAB_004eeac4:
              uVar9 = 0xffff;
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting_service",0xa77);
              }
            }
            else {
              iVar4 = json_object_get_type(iVar2);
              if (iVar4 == 3) {
                uVar9 = json_object_get_int(iVar2);
              }
              else {
                iVar4 = json_object_get_type();
                if (iVar4 != 2) goto LAB_004eeac4;
                uVar21 = json_object_get_double(iVar2);
                uVar9 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
              }
            }
            *(undefined2 *)(*(int *)(__s + 0x24) + 0x38a) = uVar9;
            iVar2 = json_object_object_get(iVar1,&DAT_0068376c);
            if ((iVar2 == 0) || (iVar4 = json_object_get_type(iVar2), iVar4 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting_service",0xa7b);
              }
              pcVar14 = *(char **)(__s + 0x24);
              pcVar13 = "";
            }
            else {
              pcVar14 = *(char **)(__s + 0x24);
              pcVar13 = (char *)json_object_get_string(iVar2);
            }
            strncpy(pcVar14,pcVar13,0xff);
            *(undefined1 *)(*(int *)(__s + 0x24) + 0xff) = 0;
            memset(acStack_258,0,0x20);
            iVar2 = json_object_object_get(iVar1,"port");
            if (iVar2 == 0) {
LAB_004eebac:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting_service",0xa7e);
              }
              pcVar13 = "";
            }
            else {
              uVar15 = json_object_object_get(iVar1,"port");
              iVar2 = json_object_get_type(uVar15);
              if (iVar2 != 6) goto LAB_004eebac;
              uVar15 = json_object_object_get(iVar1,"port");
              pcVar13 = (char *)json_object_get_string(uVar15);
            }
            strncpy(acStack_258,pcVar13,0x1f);
            local_239 = 0;
            iVar4 = *(int *)(__s + 0x24);
            iVar2 = atoi(acStack_258);
            *(short *)(iVar4 + 0x388) = (short)iVar2;
            iVar2 = json_object_object_get(iVar1,"passwd");
            if ((iVar2 == 0) || (iVar4 = json_object_get_type(iVar2), iVar4 != 6)) {
              if (jcs_err_switch == 0) {
                iVar4 = *(int *)(__s + 0x24);
              }
              else {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting_service",0xa82);
                iVar4 = *(int *)(__s + 0x24);
              }
              pcVar13 = "";
            }
            else {
              iVar4 = *(int *)(__s + 0x24);
              pcVar13 = (char *)json_object_get_string(iVar2);
            }
            strncpy((char *)(iVar4 + 0x200),pcVar13,0x77);
            *(undefined1 *)(*(int *)(__s + 0x24) + 0x277) = 0;
            iVar2 = json_object_object_get(iVar1,"user_name");
            if ((iVar2 == 0) || (iVar4 = json_object_get_type(iVar2), iVar4 != 6)) {
              if (jcs_err_switch == 0) {
                iVar4 = *(int *)(__s + 0x24);
              }
              else {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting_service",0xa85);
                iVar4 = *(int *)(__s + 0x24);
              }
              pcVar13 = "";
            }
            else {
              iVar4 = *(int *)(__s + 0x24);
              pcVar13 = (char *)json_object_get_string(iVar2);
            }
            strncpy((char *)(iVar4 + 0x100),pcVar13,0xff);
            *(undefined1 *)(*(int *)(__s + 0x24) + 0x1ff) = 0;
            iVar2 = json_object_object_get(iVar1,"share_key");
            if ((iVar2 == 0) || (iVar4 = json_object_get_type(iVar2), iVar4 != 6)) {
              if (jcs_err_switch == 0) {
                iVar4 = *(int *)(__s + 0x24);
              }
              else {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting_service",0xa88);
                iVar4 = *(int *)(__s + 0x24);
              }
              pcVar13 = "";
            }
            else {
              iVar4 = *(int *)(__s + 0x24);
              pcVar13 = (char *)json_object_get_string(iVar2);
            }
            strncpy((char *)(iVar4 + 0x278),pcVar13,0xff);
            *(undefined1 *)(*(int *)(__s + 0x24) + 0x377) = 0;
            iVar1 = json_object_object_get(iVar1,"auth_type");
            if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
              if (jcs_err_switch == 0) {
                iVar2 = *(int *)(__s + 0x24);
              }
              else {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting_service",0xa8b);
                iVar2 = *(int *)(__s + 0x24);
              }
              pcVar13 = "";
            }
            else {
              iVar2 = *(int *)(__s + 0x24);
              pcVar13 = (char *)json_object_get_string(iVar1);
            }
            strncpy((char *)(iVar2 + 0x378),pcVar13,0xf);
            *(undefined1 *)(*(int *)(__s + 0x24) + 0x387) = 0;
            goto LAB_004eedc4;
          }
          __s = local_48;
          if (sensor_test_err_switch == '\0') goto LAB_004eeee4;
          pcVar14 = 
          "[SENSOR_TEST_ERROR]%s()/%d build service fail,no requried field,by service_name=%s\n";
          uVar15 = 0xa8f;
          pcVar13 = "radius";
LAB_004eef5c:
          printf(pcVar14,"_sensor_test_build_case_setting_service",uVar15,pcVar13);
        }
        else {
          *(undefined4 *)(__s + 0x2a) = 0;
          pvVar3 = (void *)FUN_00408450(8,0xa01);
          *(void **)(__s + 0x2a) = pvVar3;
          if (pvVar3 == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc ftp fail\n";
              uVar15 = 0xa04;
LAB_004f01d8:
              printf(pcVar13,"_sensor_test_build_case_setting_service",uVar15);
            }
          }
          else {
            memset(pvVar3,0,8);
            **(int **)(__s + 0x2a) = local_40;
            sVar16 = local_40 * 0xa8e;
            *(undefined4 *)(*(int *)(__s + 0x2a) + 4) = 0;
            iVar1 = *(int *)(__s + 0x2a);
            uVar15 = FUN_00408450(sVar16,0xa0b);
            *(undefined4 *)(iVar1 + 4) = uVar15;
            if (*(void **)(*(int *)(__s + 0x2a) + 4) != (void *)0x0) {
              memset(*(void **)(*(int *)(__s + 0x2a) + 4),0,sVar16);
              goto LAB_004ee414;
            }
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc ftp->ftp_array fail\n";
              uVar15 = 0xa0e;
              goto LAB_004f01d8;
            }
          }
        }
LAB_004eeee4:
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d _sensor_test_build_case_setting_service ERROR EXIT\n",
                 "_sensor_test_build_case_setting_service",0xb27);
        }
        sensor_test_db_service_nested_mem_free(puVar18);
        if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
        pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d _sensor_test_build_case_setting_service ERROR\n";
        uVar15 = 0xbf6;
      }
      else {
        pvVar3 = (void *)FUN_00408450((uint)bVar11 * 0x220,0xb94);
        *(void **)(__s + 0x1c) = pvVar3;
        if (pvVar3 != (void *)0x0) {
          iVar2 = 0;
          memset(pvVar3,0,(uint)*(byte *)((int)__s + 0xb) * 0x220);
          memset(acStack_258,0,0x20);
          memset(acStack_1c0,0,0x78);
          memset(acStack_148,0,0x100);
          memset(local_238,0,0x78);
LAB_004edd28:
          do {
            bVar11 = *(byte *)((int)__s + 0xb);
            while( true ) {
              if ((int)(uint)bVar11 <= iVar2) goto LAB_004ee060;
              uVar15 = json_object_array_get_idx(iVar1,iVar2);
              iVar4 = json_object_object_get(uVar15,"serv_id");
              if (iVar4 != 0) break;
              iVar2 = iVar2 + 1;
              if (sensor_test_err_switch == '\0') goto LAB_004edd28;
              printf("[SENSOR_TEST_ERROR]%s()/%d parse json error, no serv_id field\n",
                     "_sensor_test_build_case_setting",0xbab);
              bVar11 = *(byte *)((int)__s + 0xb);
            }
            iVar6 = json_object_get_type(iVar4);
            if (iVar6 == 3) {
              uVar5 = json_object_get_int(iVar4);
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 == 2) {
                uVar21 = json_object_get_double(iVar4);
                uVar5 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
              }
              else {
                uVar5 = 0xffffffff;
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_test_build_case_setting",0xbae);
                }
              }
            }
            iVar6 = iVar2 * 0x220;
            *(undefined4 *)(*(int *)(__s + 0x1c) + iVar6) = uVar5;
            iVar4 = json_object_object_get(uVar15,"freqband");
            if (iVar4 == 0) {
              if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d parse json error, no freqband field\n";
              uVar15 = 0xbb6;
              goto LAB_004ed8f8;
            }
            iVar7 = json_object_get_type(iVar4);
            if (iVar7 == 3) {
              uVar5 = json_object_get_int(iVar4);
LAB_004eddf8:
              iVar4 = *(int *)(__s + 0x1c);
            }
            else {
              iVar7 = json_object_get_type();
              if (iVar7 == 2) {
                uVar21 = json_object_get_double(iVar4);
                uVar5 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                goto LAB_004eddf8;
              }
              uVar5 = 0xffffffff;
              if (jcs_err_switch == 0) goto LAB_004eddf8;
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_sensor_test_build_case_setting",0xbb9);
              iVar4 = *(int *)(__s + 0x1c);
            }
            *(undefined4 *)(iVar4 + iVar6 + 4) = uVar5;
            iVar4 = json_object_object_get(uVar15,"encryption");
            if (iVar4 == 0) {
              if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d parse json error, no encryption field\n";
              uVar15 = 0xbc1;
              goto LAB_004ed8f8;
            }
            iVar7 = json_object_get_type(iVar4);
            if (iVar7 == 3) {
              uVar5 = json_object_get_int(iVar4);
LAB_004ede54:
              iVar4 = *(int *)(__s + 0x1c);
            }
            else {
              iVar7 = json_object_get_type();
              if (iVar7 == 2) {
                uVar21 = json_object_get_double(iVar4);
                uVar5 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                goto LAB_004ede54;
              }
              uVar5 = 0xffffffff;
              if (jcs_err_switch == 0) goto LAB_004ede54;
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_sensor_test_build_case_setting",0xbc4);
              iVar4 = *(int *)(__s + 0x1c);
            }
            *(undefined4 *)(iVar4 + iVar6 + 0xc) = uVar5;
            iVar4 = json_object_object_get(uVar15,"radius_type");
            if ((iVar4 != 0) && (iVar7 = json_object_get_type(iVar4), iVar7 == 6)) {
              iVar7 = json_object_get_type(iVar4);
              if (iVar7 == 6) {
                pcVar13 = (char *)json_object_get_string(iVar4);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_sensor_test_build_case_setting",0xbcc);
                }
                pcVar13 = "";
              }
              strncpy(acStack_258,pcVar13,0x1f);
              local_239 = 0;
              memcpy((void *)(*(int *)(__s + 0x1c) + iVar6 + 0x10),acStack_258,0x20);
            }
            iVar4 = json_object_object_get(uVar15,"radius_key");
            if ((iVar4 != 0) && (iVar7 = json_object_get_type(iVar4), iVar7 == 6)) {
              iVar7 = json_object_get_type(iVar4);
              if (iVar7 == 6) {
                pcVar13 = (char *)json_object_get_string(iVar4);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_sensor_test_build_case_setting",0xbd4);
                }
                pcVar13 = "";
              }
              strncpy(acStack_1c0,pcVar13,0x77);
              local_149 = 0;
              memcpy((void *)(*(int *)(__s + 0x1c) + iVar6 + 0x30),acStack_1c0,0x78);
            }
            iVar4 = json_object_object_get(uVar15,"radius_name");
            if ((iVar4 != 0) && (iVar7 = json_object_get_type(iVar4), iVar7 == 6)) {
              iVar7 = json_object_get_type(iVar4);
              if (iVar7 == 6) {
                pcVar13 = (char *)json_object_get_string(iVar4);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_sensor_test_build_case_setting",0xbdc);
                }
                pcVar13 = "";
              }
              strncpy(acStack_148,pcVar13,0xff);
              local_49 = 0;
              memcpy((void *)(*(int *)(__s + 0x1c) + iVar6 + 0xa8),acStack_148,0x100);
            }
            iVar4 = json_object_object_get(uVar15,"ssid_key");
            if ((iVar4 != 0) && (iVar7 = json_object_get_type(iVar4), iVar7 == 6)) {
              iVar7 = json_object_get_type(iVar4);
              if (iVar7 == 6) {
                pcVar13 = (char *)json_object_get_string(iVar4);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_sensor_test_build_case_setting",0xbe4);
                }
                pcVar13 = "";
              }
              strncpy(local_238,pcVar13,0x77);
              local_1c1 = 0;
              memcpy((void *)(*(int *)(__s + 0x1c) + iVar6 + 0x1a8),local_238,0x78);
            }
            iVar4 = json_object_object_get(uVar15,"support_freqband");
            if ((iVar4 == 0) ||
               ((iVar7 = json_object_get_type(iVar4), iVar7 != 3 &&
                (iVar7 = json_object_get_type(iVar4), iVar7 != 2)))) {
              iVar2 = iVar2 + 1;
            }
            else {
              iVar7 = json_object_get_type(iVar4);
              if (iVar7 == 3) {
                uVar15 = json_object_get_int(iVar4);
LAB_004edfa0:
                iVar4 = *(int *)(__s + 0x1c);
              }
              else {
                iVar7 = json_object_get_type();
                if (iVar7 == 2) {
                  uVar21 = json_object_get_double(iVar4);
                  uVar15 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
                  goto LAB_004edfa0;
                }
                uVar15 = 0xffffffff;
                if (jcs_err_switch == 0) goto LAB_004edfa0;
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_sensor_test_build_case_setting",0xbec);
                iVar4 = *(int *)(__s + 0x1c);
              }
              iVar2 = iVar2 + 1;
              *(undefined4 *)(iVar4 + iVar6 + 8) = uVar15;
            }
          } while( true );
        }
        if (sensor_test_err_switch == '\0') goto LAB_004ed81c;
        pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d ssid_info_list mem melloc fail\n";
        uVar15 = 0xb97;
      }
    }
  }
LAB_004ed8f8:
  printf(pcVar13,"_sensor_test_build_case_setting",uVar15);
LAB_004ed81c:
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_build_case_setting fail EXIT\n",
           "_sensor_test_build_case_setting",0xbfd);
  }
  puVar19 = __s;
  if (__s != (undefined2 *)0x0) {
    if (*(int *)(__s + 0x1a) == 0) {
      iVar1 = *(int *)(__s + 0x1c);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(__s + 0x1a) = 0;
      iVar1 = *(int *)(__s + 0x1c);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(__s + 0x18);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(__s + 0x1c) = 0;
      iVar1 = *(int *)(__s + 0x18);
    }
    if (iVar1 != 0) {
      FUN_00407df0();
      *(undefined4 *)(__s + 0x18) = 0;
    }
    puVar19 = (undefined2 *)0x0;
    FUN_00407df0(__s);
  }
  return puVar19;
}

