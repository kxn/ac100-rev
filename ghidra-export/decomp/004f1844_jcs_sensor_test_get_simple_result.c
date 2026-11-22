// func jcs_sensor_test_get_simple_result @ 004f1844 size=4316

void jcs_sensor_test_get_simple_result(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar12;
  int iVar8;
  char *pcVar9;
  undefined4 uVar10;
  size_t sVar11;
  FILE *__s;
  int extraout_v1;
  char *__format;
  uint uVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  short local_a18 [2];
  int local_a14;
  int local_a10;
  undefined4 local_a0c;
  undefined4 local_a08;
  uint local_a04;
  undefined2 local_a00;
  char local_9fc [116];
  char acStack_988 [153];
  undefined1 local_8ef;
  char local_8ec [256];
  char local_7ec [256];
  char acStack_6ec [260];
  undefined1 auStack_5e8 [78];
  undefined1 auStack_59a [650];
  undefined1 auStack_310 [78];
  char acStack_2c2 [650];
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_get_simple_result ENTER\n",
           "jcs_sensor_test_get_simple_result",0x1805);
  }
  local_a0c = 0;
  local_a10 = 0;
  memset(local_9fc + 0x10,0,100);
  local_9fc[0] = '\0';
  local_9fc[1] = '\0';
  local_9fc[2] = '\0';
  local_9fc[3] = '\0';
  local_9fc[4] = '\0';
  local_9fc[5] = '\0';
  local_9fc[6] = '\0';
  local_9fc[7] = '\0';
  local_9fc[8] = '\0';
  local_9fc[9] = '\0';
  local_9fc[10] = '\0';
  local_9fc[0xb] = '\0';
  local_9fc[0xc] = '\0';
  local_9fc[0xd] = '\0';
  local_9fc[0xe] = '\0';
  local_9fc[0xf] = '\0';
  memset(auStack_310,0,0x2d8);
  memset(auStack_5e8,0,0x2d8);
  memset(acStack_988,0,0x9a);
  local_a08 = 0;
  local_a04 = 0;
  local_a00 = 0;
  local_a14 = 0;
  local_a18[0] = 0;
  local_2c = sensor_test_db_get_case_num_max();
  iVar3 = json_object_object_get(param_1,"test_case_id");
  if (iVar3 == 0) {
LAB_004f1938:
    uVar13 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_sensor_test_get_simple_result",0x182f);
    }
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      uVar13 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_004f1938;
      uVar15 = json_object_get_double(iVar3);
      uVar13 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  iVar3 = json_object_object_get(param_1,"test_type");
  if (iVar3 == 0) {
LAB_004f1988:
    iVar3 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_sensor_test_get_simple_result",0x1833);
    }
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      iVar3 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_004f1988;
      uVar15 = json_object_get_double(iVar3);
      iVar3 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  iVar4 = json_object_object_get(param_1,"ser_index");
  local_38 = -1;
  if (iVar4 != 0) {
    iVar5 = json_object_get_type(iVar4);
    if (iVar5 == 3) {
      sVar12 = json_object_get_int(iVar4);
      local_38 = (int)sVar12;
    }
    else {
      iVar5 = json_object_get_type();
      if (iVar5 == 2) {
        uVar15 = json_object_get_double(iVar4);
        sVar12 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
        local_38 = (int)sVar12;
      }
      else if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "jcs_sensor_test_get_simple_result",0x1839);
      }
    }
  }
  iVar4 = json_object_object_get(param_1,"sch_start_time");
  if (iVar4 == 0) {
LAB_004f1a30:
    iVar4 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int64 with error obj or value type is unmatch.\n",
             "jcs_sensor_test_get_simple_result",0x1842);
    }
  }
  else {
    iVar5 = json_object_get_type(iVar4);
    if (iVar5 == 3) {
      json_object_get_int64(iVar4);
      iVar4 = extraout_v1;
    }
    else {
      iVar5 = json_object_get_type();
      if (iVar5 != 2) goto LAB_004f1a30;
      uVar15 = json_object_get_double(iVar4);
      iVar4 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  iVar5 = json_object_object_get(param_1,"start");
  local_34 = 0xffffffff;
  if (iVar5 != 0) {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_34 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar15 = json_object_get_double(iVar5);
        local_34 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
      }
      else if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "jcs_sensor_test_get_simple_result",0x1848);
      }
    }
  }
  uVar14 = 0xffffffff;
  iVar5 = json_object_object_get(param_1,"end");
  if (iVar5 != 0) {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      uVar14 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar15 = json_object_get_double(iVar5);
        uVar14 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
      }
      else if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "jcs_sensor_test_get_simple_result",0x1853);
      }
    }
  }
  iVar5 = json_object_object_get(param_1,"sensor_name");
  local_30 = 0;
  if (iVar5 != 0) {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 6) {
      pcVar9 = (char *)json_object_get_string(iVar5);
      strncpy(acStack_988,pcVar9,0x99);
      local_8ef = 0;
      local_30 = 1;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "jcs_sensor_test_get_simple_result",0x185e);
      }
      strncpy(acStack_988,"",0x99);
      local_8ef = 0;
      local_30 = 1;
    }
  }
  iVar5 = json_object_object_get(param_1,"result");
  if (iVar5 == 0) {
    bVar1 = false;
LAB_004f1ba0:
    iVar5 = -1;
  }
  else {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      bVar1 = true;
      iVar5 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar15 = json_object_get_double(iVar5);
        bVar1 = true;
        iVar5 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
      }
      else {
        if (jcs_err_switch == 0) {
          bVar1 = true;
          goto LAB_004f1ba0;
        }
        bVar1 = true;
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "jcs_sensor_test_get_simple_result",0x1866);
        iVar5 = -1;
      }
    }
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d parse test_case_id=%d, test_type=%d, serindex=%d, sch_start_time=%d, start=%d, end=%d\n"
           ,"jcs_sensor_test_get_simple_result",0x186a,uVar13,iVar3,local_38,iVar4,local_34,uVar14);
  }
  if (((((int)uVar13 < 0) || (local_2c <= uVar13)) || (iVar3 < 0)) || (8 < iVar3)) {
    if (sensor_test_err_switch == '\0') {
      uVar14 = 1;
    }
    else {
      printf("[SENSOR_TEST_ERROR]%s()/%d invalid test_case_id or test_type\n",
             "jcs_sensor_test_get_simple_result",0x186e);
      uVar14 = 1;
    }
    goto LAB_004f1bec;
  }
  iVar6 = sensor_test_db_get_case_start_time(uVar13,&local_a14,local_a18);
  if (iVar6 == -1) {
    if (sensor_test_err_switch == '\0') {
      uVar14 = 1;
    }
    else {
      printf("[SENSOR_TEST_ERROR]%s()/%d get_case_start_time fail, id=%d\n",
             "jcs_sensor_test_get_simple_result",0x1875,uVar13);
      uVar14 = 1;
    }
    goto LAB_004f1bec;
  }
  iVar6 = local_a14;
  if ((iVar4 == 0) || (iVar6 = iVar4, local_a18[0] == 0)) {
    iVar8 = time((time_t *)0x0);
    iVar4 = iVar6;
  }
  else {
    iVar8 = iVar4 + local_a18[0] * 0x3c;
  }
  uVar7 = sensor_test_db_get_simple_result
                    (uVar13,iVar3,local_38,iVar4,iVar8,local_34,uVar14,&local_a10,&local_a0c);
  if ((uVar7 == 0) || (local_a10 == 0)) {
    if (sensor_test_warning_switch == '\0') {
      uVar14 = 1;
      if (uVar7 == 0) goto LAB_004f1bec;
    }
    else {
      printf("[SENSOR_TEST_WARNING]%s()/%d get simple result fail\n",
             "jcs_sensor_test_get_simple_result",0x1890);
      if (uVar7 == 0) {
        uVar14 = 1;
        goto LAB_004f1bec;
      }
    }
  }
  else {
    iVar4 = json_object_new_array();
    if (iVar4 != 0) {
      local_34 = uVar7;
      local_2c = uVar7;
      for (local_38 = 0; uVar2 = local_2c, local_38 < local_a10; local_38 = local_38 + 1) {
        iVar6 = apmngr_db_entry_get_by_id(*(undefined2 *)(uVar7 + 0x32),auStack_310);
        if (iVar6 == -1) {
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d Get sensor_entry by id fail\n",
                   "jcs_sensor_test_get_simple_result",0x18a0);
          }
        }
        else if ((local_30 == 0) ||
                (pcVar9 = strstr(acStack_2c2,acStack_988), pcVar9 != (char *)0x0)) {
          if (bVar1) {
            iVar6 = 1;
            if (*(int *)(uVar7 + 0x4c) == 0) {
              iVar8 = sensor_test_db_is_test_result_slow
                                (*(undefined1 *)(uVar7 + 0x6e),*(undefined4 *)(uVar7 + 0x48));
              iVar6 = 2;
              if (iVar8 != 1) {
                iVar6 = 0;
              }
            }
            if (iVar6 != iVar5) goto LAB_004f20d0;
          }
          iVar6 = json_object_new_object();
          if (iVar6 == 0) {
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d Create json object result_list_item_obj failed,with idx=%d\n"
                     ,"jcs_sensor_test_get_simple_result",0x18ca,local_38);
            }
          }
          else {
            memset(acStack_6ec,0,0x100);
            uVar14 = *(undefined4 *)(uVar7 + 0x68);
            uVar16 = 0;
            snprintf(acStack_6ec,0x100,"%lld");
            uVar10 = json_object_new_string(acStack_6ec);
            json_object_object_add(iVar6,"start_time",uVar10);
            memset(acStack_6ec,0,0x100);
            snprintf(acStack_6ec,0x100,"%d",(int)*(char *)(uVar7 + 0x61),uVar16,uVar14);
            uVar14 = json_object_new_string(acStack_6ec);
            json_object_object_add(iVar6,"rssi",uVar14);
            memset(acStack_6ec,0,0x100);
            snprintf(acStack_6ec,0x100,"%d",(int)*(short *)(uVar7 + 0x58));
            uVar14 = json_object_new_string(acStack_6ec);
            json_object_object_add(iVar6,&DAT_00698ce4,uVar14);
            uVar14 = json_object_new_string(uVar7);
            json_object_object_add(iVar6,"ssid_name",uVar14);
            local_9fc[0] = '\0';
            local_9fc[1] = '\0';
            local_9fc[2] = '\0';
            local_9fc[3] = '\0';
            local_9fc[4] = '\0';
            local_9fc[5] = '\0';
            local_9fc[6] = '\0';
            local_9fc[7] = '\0';
            local_9fc[8] = '\0';
            local_9fc[9] = '\0';
            local_9fc[10] = '\0';
            local_9fc[0xb] = '\0';
            local_9fc[0xc] = '\0';
            local_9fc[0xd] = '\0';
            local_9fc[0xe] = '\0';
            local_9fc[0xf] = '\0';
            iVar8 = sensor_test_db_get_stage_type_str_from_enum
                              (*(undefined1 *)(uVar7 + 0x60),local_9fc);
            pcVar9 = local_9fc;
            if (iVar8 != 0) {
              if (sensor_test_err_switch != '\0') {
                printf("[SENSOR_TEST_ERROR]%s()/%d get_stage_type_str_from_enum fail\n",
                       "jcs_sensor_test_get_simple_result",0x18d9);
              }
              pcVar9 = "--";
            }
            uVar14 = json_object_new_string(pcVar9);
            json_object_object_add(iVar6,"fail_stage",uVar14);
            if (*(char *)(uVar7 + 0x62) == '\x01') {
              pcVar9 = "2.4G";
            }
            else if (*(char *)(uVar7 + 0x62) == '\x02') {
              pcVar9 = "5G";
            }
            else {
              pcVar9 = "--";
            }
            uVar14 = json_object_new_string(pcVar9);
            json_object_object_add(iVar6,"freq_type",uVar14);
            if (*(int *)(uVar7 + 0x4c) == 0) {
              uVar14 = json_object_new_string("0");
              json_object_object_add(iVar6,"reason",uVar14);
              iVar8 = sensor_test_db_is_test_result_slow
                                (*(undefined1 *)(uVar7 + 0x6e),*(undefined4 *)(uVar7 + 0x48));
              if (iVar8 == 1) {
                memset(acStack_6ec,0,0x100);
                uVar14 = 2;
              }
              else {
                memset(acStack_6ec,0,0x100);
                uVar14 = 0;
              }
            }
            else {
              local_7ec[0] = '\0';
              local_7ec[1] = '\0';
              local_7ec[2] = '\0';
              local_7ec[3] = '\0';
              local_7ec[4] = '\0';
              local_7ec[5] = '\0';
              local_7ec[6] = '\0';
              local_7ec[7] = '\0';
              local_7ec[8] = '\0';
              local_7ec[9] = '\0';
              local_7ec[10] = '\0';
              local_7ec[0xb] = '\0';
              local_7ec[0xc] = '\0';
              local_7ec[0xd] = '\0';
              local_7ec[0xe] = '\0';
              local_7ec[0xf] = '\0';
              snprintf(local_7ec,0x10,"%d");
              uVar14 = json_object_new_string(local_7ec);
              json_object_object_add(iVar6,"reason",uVar14);
              memset(acStack_6ec,0,0x100);
              uVar14 = 1;
            }
            snprintf(acStack_6ec,0x100,"%d",uVar14);
            uVar14 = json_object_new_string(acStack_6ec);
            json_object_object_add(iVar6,"result",uVar14);
            memset(local_7ec,0,0x100);
            snprintf(local_7ec,0x100,"%d",(uint)*(ushort *)(uVar7 + 0x6c));
            uVar14 = json_object_new_string(local_7ec);
            json_object_object_add(iVar6,"ser_index",uVar14);
            local_8ec[0] = '\0';
            local_8ec[1] = '\0';
            local_8ec[2] = '\0';
            local_8ec[3] = '\0';
            local_8ec[4] = '\0';
            local_8ec[5] = '\0';
            local_8ec[6] = '\0';
            local_8ec[7] = '\0';
            local_8ec[8] = '\0';
            local_8ec[9] = '\0';
            local_8ec[10] = '\0';
            local_8ec[0xb] = '\0';
            local_8ec[0xc] = '\0';
            local_8ec[0xd] = '\0';
            local_8ec[0xe] = '\0';
            local_8ec[0xf] = '\0';
            local_8ec[0x10] = '\0';
            local_8ec[0x11] = '\0';
            local_8ec[0x12] = '\0';
            local_8ec[0x13] = '\0';
            snprintf(local_8ec,0x14,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)*(byte *)(uVar7 + 0x34),
                     (uint)*(byte *)(uVar7 + 0x35),(uint)*(byte *)(uVar7 + 0x36),
                     (uint)*(byte *)(uVar7 + 0x37),(uint)*(byte *)(uVar7 + 0x38),
                     (uint)*(byte *)(uVar7 + 0x39));
            uVar14 = json_object_new_string(local_8ec);
            json_object_object_add(iVar6,"bssid",uVar14);
            memset(local_7ec,0,0x100);
            snprintf(local_7ec,0x100,"%d",uVar13);
            uVar14 = json_object_new_string(local_7ec);
            json_object_object_add(iVar6,"test_case_id",uVar14);
            memset(local_7ec,0,0x100);
            snprintf(local_7ec,0x100,"%d",iVar3);
            uVar14 = json_object_new_string(local_7ec);
            json_object_object_add(iVar6,"test_type",uVar14);
            uVar14 = json_object_new_string(acStack_2c2);
            json_object_object_add(iVar6,"sensor_name",uVar14);
            local_a08 = 0;
            local_a04 = 0;
            local_a00 = 0;
            memset(auStack_5e8,0,0x2d8);
            memcpy(&local_a08,(void *)(uVar7 + 0x34),6);
            stats_db_bssid_get(&local_a08);
            apmngr_db_entry_get_by_id(local_a04 & 0xffff,auStack_5e8);
            uVar14 = json_object_new_string(auStack_59a);
            json_object_object_add(iVar6,"ap_name",uVar14);
            if (iVar3 == 7) {
              memset(local_7ec,0,0x100);
              snprintf(local_7ec,0x100,"%d",(uint)*(ushort *)(uVar7 + 0x5a));
              uVar14 = json_object_new_string(local_7ec);
              json_object_object_add(iVar6,"up_speed",uVar14);
              memset(local_7ec,0,0x100);
              snprintf(local_7ec,0x100,"%d",(uint)*(ushort *)(uVar7 + 0x5c));
              uVar14 = json_object_new_string(local_7ec);
              json_object_object_add(iVar6,"down_speed",uVar14);
              memset(local_7ec,0,0x100);
              snprintf(local_7ec,0x100,"%d",(uint)*(ushort *)(uVar7 + 0x5e));
              uVar14 = json_object_new_string(local_7ec);
              json_object_object_add(iVar6,"relay",uVar14);
            }
            json_object_array_add(iVar4,iVar6);
          }
        }
LAB_004f20d0:
        uVar7 = uVar7 + 0x70;
      }
      uVar13 = local_34;
      for (iVar3 = 0; iVar3 < local_a10; iVar3 = iVar3 + 1) {
        sensor_test_db_result_ret_nested_mem_free(uVar13);
        uVar13 = uVar13 + 0x70;
      }
      FUN_00407df0(uVar2);
      pcVar9 = (char *)json_object_to_json_string_ext(iVar4,0);
      pcVar9 = strdup(pcVar9);
      if (pcVar9 == (char *)0x0) {
        __s = (FILE *)0x0;
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d generate result_str failed\n",
                 "jcs_sensor_test_get_simple_result",0x192b);
          __s = (FILE *)0x0;
        }
      }
      else {
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d The result_str is=%s\n",
                 "jcs_sensor_test_get_simple_result",0x192e,pcVar9);
        }
        json_object_put(iVar4);
        sVar11 = strlen(pcVar9);
        l_sensor_test_write_file_counter = l_sensor_test_write_file_counter + 1;
        snprintf(local_9fc + 0x10,100,"/tmp/st_simple_result_%d");
        __s = fopen(local_9fc + 0x10,"w+");
        if (__s == (FILE *)0x0) {
          if (sensor_test_err_switch != '\0') {
            __format = "[SENSOR_TEST_ERROR]%s()/%d open sensor test simple result file failed.\n";
            uVar14 = 0x1939;
LAB_004f26a0:
            printf(__format,"jcs_sensor_test_get_simple_result",uVar14);
          }
        }
        else {
          sVar11 = fwrite(pcVar9,(int)(short)sVar11,1,__s);
          if (sVar11 == 1) {
            free(pcVar9);
            fclose(__s);
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d jcs get simple result success and write it into tmp file\n"
                     ,"jcs_sensor_test_get_simple_result",0x194d);
            }
            uVar14 = json_object_new_string(local_9fc + 0x10);
            json_object_object_add(param_2,"file_name",uVar14);
            memset(local_8ec,0,0x100);
            snprintf(local_8ec,0x100,"%d",local_a0c);
            uVar14 = json_object_new_string(local_8ec);
            json_object_object_add(param_2,"total_num",uVar14);
            uVar14 = 0;
            goto LAB_004f1bec;
          }
          if (sensor_test_err_switch != '\0') {
            __format = 
            "[SENSOR_TEST_ERROR]%s()/%d write sensor test simple result to file failed.\n";
            uVar14 = 0x193f;
            goto LAB_004f26a0;
          }
        }
      }
      if (iVar4 != 0) {
        json_object_put(iVar4);
      }
      if (pcVar9 != (char *)0x0) {
        free(pcVar9);
      }
      if (__s == (FILE *)0x0) {
        uVar14 = 1;
      }
      else {
        fclose(__s);
        uVar14 = 1;
      }
      goto LAB_004f1bec;
    }
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d Create json object result_list_obj failed\n",
             "jcs_sensor_test_get_simple_result",0x1898);
    }
  }
  uVar13 = uVar7;
  for (iVar3 = 0; iVar3 < local_a10; iVar3 = iVar3 + 1) {
    sensor_test_db_result_ret_nested_mem_free(uVar13);
    uVar13 = uVar13 + 0x70;
  }
  FUN_00407df0(uVar7);
  uVar14 = 1;
LAB_004f1bec:
  uVar14 = json_object_new_int(uVar14);
  json_object_object_add(param_2,&DAT_00676a24,uVar14);
  return;
}

