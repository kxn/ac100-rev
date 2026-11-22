// func jcs_sensor_test_get_detail_result @ 004f0c30 size=3092

void jcs_sensor_test_get_detail_result(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  size_t sVar8;
  FILE *__s;
  undefined4 uVar9;
  char *__format;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined8 uVar15;
  undefined4 local_1b8;
  undefined2 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  char local_1a0 [16];
  uint local_190;
  char acStack_18c [100];
  char acStack_128 [256];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_get_detail_result ENTER\n",
           "jcs_sensor_test_get_detail_result",0x1975);
  }
  memset(acStack_18c,0,100);
  local_1a0[0] = '\0';
  local_1a0[1] = '\0';
  local_1a0[2] = '\0';
  local_1a0[3] = '\0';
  local_1a0[4] = '\0';
  local_1a0[5] = '\0';
  local_1a0[6] = '\0';
  local_1a0[7] = '\0';
  local_1a0[8] = '\0';
  local_1a0[9] = '\0';
  local_1a0[10] = '\0';
  local_1a0[0xb] = '\0';
  local_1a0[0xc] = '\0';
  local_1a0[0xd] = '\0';
  local_1a0[0xe] = '\0';
  local_1a0[0xf] = '\0';
  local_190 = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  uVar1 = sensor_test_db_get_case_num_max();
  iVar2 = json_object_object_get(param_1,"test_case_id");
  if (iVar2 == 0) {
LAB_004f0ce4:
    uVar11 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_sensor_test_get_detail_result",0x1987);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar11 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_004f0ce4;
      uVar15 = json_object_get_double(iVar2);
      uVar11 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  iVar2 = json_object_object_get(param_1,"test_type");
  if (iVar2 == 0) {
LAB_004f0d34:
    uVar13 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_sensor_test_get_detail_result",0x198a);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar13 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_004f0d34;
      uVar15 = json_object_get_double(iVar2);
      uVar13 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  iVar2 = json_object_object_get(param_1,"ser_index");
  if (iVar2 == 0) {
LAB_004f0d84:
    uVar12 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_sensor_test_get_detail_result",0x198d);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar12 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_004f0d84;
      uVar15 = json_object_get_double(iVar2);
      uVar12 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  iVar2 = json_object_object_get(param_1,"bssid");
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "jcs_sensor_test_get_detail_result",0x1990);
    }
    pcVar10 = "";
  }
  else {
    pcVar10 = (char *)json_object_get_string(iVar2);
  }
  strncpy(local_1a0,pcVar10,0x13);
  local_190 = local_190 & 0xffffff00;
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d begin str2mac, bssid_str=%s\n",
           "jcs_sensor_test_get_detail_result",0x1991,local_1a0);
  }
  _str2mac(local_1a0,&local_1b8);
  printmac(&local_1b8);
  if ((((8 < uVar13) || ((int)uVar11 < 0)) || (uVar1 <= uVar11)) || ((int)uVar12 < 0)) {
    if (sensor_test_debug_switch == '\0') {
      uVar9 = 1;
    }
    else {
      printf("[SENSOR_TEST_DEBUG]%s()/%d invalid input params,case_id=%d, test_type=%d, ser_index=%d\n"
             ,"jcs_sensor_test_get_detail_result",0x1997,uVar11,uVar13,uVar12);
      uVar9 = 1;
    }
    goto LAB_004f10a0;
  }
  iVar2 = sensor_test_db_get_detail_result(uVar11,&local_1b8,uVar13,uVar12 & 0xffff);
  if (iVar2 == 0) {
    if (sensor_test_debug_switch == '\0') {
      uVar9 = 1;
    }
    else {
      printf("[SENSOR_TEST_DEBUG]%s()/%d jcs get detail result fail or result is null\n",
             "jcs_sensor_test_get_detail_result",0x19a1);
      uVar9 = 1;
    }
    goto LAB_004f10a0;
  }
  if (sensor_test_debug_switch == '\0') {
    iVar3 = *(int *)(iVar2 + 100);
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_detail_result_object_add ENTER\n",
           "_sensor_test_detail_result_object_add",0xe95);
    iVar3 = *(int *)(iVar2 + 100);
  }
  local_1b0 = 0;
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  if (iVar3 == 0) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d result ptr or detail_result ptr is null\n",
             "_sensor_test_detail_result_object_add",0xea4);
    }
    iVar4 = 0;
    iVar3 = 0;
LAB_004f1288:
    iVar5 = 0;
  }
  else {
    iVar3 = json_object_new_object();
    if (iVar3 == 0) {
      if (sensor_test_debug_switch == '\0') {
LAB_004f135c:
        iVar4 = 0;
      }
      else {
        pcVar10 = "[SENSOR_TEST_DEBUG]%s()/%d JSON_OBJ_CREATE fail\n";
        uVar9 = 0xeab;
LAB_004f1374:
        printf(pcVar10,"_sensor_test_detail_result_object_add",uVar9);
        iVar4 = 0;
      }
      goto LAB_004f1288;
    }
    iVar4 = json_object_new_object();
    if (iVar4 == 0) {
      if (sensor_test_debug_switch == '\0') goto LAB_004f1288;
      printf("[SENSOR_TEST_DEBUG]%s()/%d JSON_OBJ_CREATE fail\n",
             "_sensor_test_detail_result_object_add",0xeb2);
      iVar5 = 0;
    }
    else {
      iVar5 = json_object_new_array();
      if (iVar5 == 0) {
        if (sensor_test_debug_switch != '\0') {
          uVar9 = 0xeb9;
LAB_004f13f0:
          printf("[SENSOR_TEST_DEBUG]%s()/%d JSON_ARRAY_CREATE fail\n",
                 "_sensor_test_detail_result_object_add",uVar9);
        }
      }
      else {
        iVar6 = json_object_new_array();
        if (iVar6 != 0) {
          json_object_object_add(iVar4,"test",iVar6);
          json_object_object_add(iVar4,"diagnosis",iVar5);
          memset(acStack_128,0,0x100);
          uVar9 = *(undefined4 *)(iVar2 + 0x68);
          snprintf(acStack_128,0x100,"%lld");
          uVar7 = json_object_new_string(acStack_128);
          json_object_object_add(iVar3,"startTime",uVar7);
          json_object_object_add(iVar3,"details",iVar4);
          uVar1 = (uint)*(byte *)(*(int *)(iVar2 + 100) + 8);
          uVar11 = (uint)*(byte *)(*(int *)(iVar2 + 100) + 9);
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d test_stage_cnt=%d, diagnosis_stage_cnt=%d\n",
                   "_sensor_test_detail_result_object_add",0xecf,uVar1,uVar11,uVar9);
          }
          if (uVar1 != 0) {
            iVar4 = 0;
            do {
              iVar5 = json_object_new_object();
              if (iVar5 == 0) {
                if (sensor_test_debug_switch == '\0') goto LAB_004f135c;
                uVar9 = 0xeda;
                goto LAB_004f17ac;
              }
              local_1ac = 0;
              iVar14 = iVar4 * 0x14;
              local_1a8 = 0;
              local_1a4 = 0;
              local_1b0 = 0;
              iVar6 = sensor_test_db_get_stage_type_str_from_enum
                                (*(undefined1 *)(**(int **)(iVar2 + 100) + iVar14 + 0x10),&local_1b0
                                );
              if ((iVar6 == -1) && (sensor_test_err_switch != '\0')) {
                printf("[SENSOR_TEST_ERROR]%s()/%d invalid stage type enum=%d\n",
                       "_sensor_test_detail_result_object_add",0xee0,
                       (uint)*(byte *)(**(int **)(iVar2 + 100) + iVar14 + 0x10));
              }
              uVar9 = json_object_new_string(&local_1b0);
              json_object_object_add(iVar5,"stage",uVar9);
              memset(acStack_128,0,0x100);
              snprintf(acStack_128,0x100,"%d",(uint)*(ushort *)(**(int **)(iVar2 + 100) + iVar14));
              uVar9 = json_object_new_string(acStack_128);
              json_object_object_add(iVar5,"time",uVar9);
              iVar6 = _sensor_test_detail_result_data_object_add(**(int **)(iVar2 + 100) + iVar14);
              if (iVar6 == 0) {
                if (sensor_test_err_switch == '\0') goto LAB_004f135c;
                pcVar10 = "[SENSOR_TEST_ERROR]%s()/%d data object add fail\n";
                uVar9 = 0xee8;
                goto LAB_004f1374;
              }
              json_object_object_add(iVar5,"data",iVar6);
              iVar4 = iVar4 + 1;
              json_object_array_add(0,iVar5);
            } while (iVar4 < (int)uVar1);
          }
          iVar4 = 0;
          if (uVar11 != 0) {
LAB_004f14c4:
            iVar5 = json_object_new_object();
            if (iVar5 == 0) {
              if (sensor_test_debug_switch != '\0') {
                uVar9 = 0xefb;
LAB_004f17ac:
                iVar5 = 0;
                iVar4 = 0;
                printf("[SENSOR_TEST_DEBUG]%s()/%d JSON_ARRAY_CREATE fail\n",
                       "_sensor_test_detail_result_object_add",uVar9);
                goto LAB_004f128c;
              }
              goto LAB_004f135c;
            }
            local_1ac = 0;
            iVar14 = iVar4 * 0x14;
            local_1a8 = 0;
            local_1a4 = 0;
            local_1b0 = 0;
            iVar6 = sensor_test_db_get_stage_type_str_from_enum
                              (*(undefined1 *)(*(int *)(*(int *)(iVar2 + 100) + 4) + iVar14 + 0x10),
                               &local_1b0);
            if ((iVar6 == -1) && (sensor_test_err_switch != '\0')) {
              printf("[SENSOR_TEST_ERROR]%s()/%d invalid stage type enum=%d\n",
                     "_sensor_test_detail_result_object_add",0xf01,
                     (uint)*(byte *)(*(int *)(*(int *)(iVar2 + 100) + 4) + iVar14 + 0x10));
            }
            uVar9 = json_object_new_string(&local_1b0);
            json_object_object_add(iVar5,"stage",uVar9);
            memset(acStack_128,0,0x100);
            snprintf(acStack_128,0x100,"%d",
                     (uint)*(ushort *)(*(int *)(*(int *)(iVar2 + 100) + 4) + iVar14));
            uVar9 = json_object_new_string(acStack_128);
            json_object_object_add(iVar5,"time",uVar9);
            iVar6 = _sensor_test_detail_result_data_object_add
                              (*(int *)(*(int *)(iVar2 + 100) + 4) + iVar14);
            if (iVar6 != 0) goto code_r0x004f1494;
            if (sensor_test_err_switch == '\0') goto LAB_004f135c;
            pcVar10 = "[SENSOR_TEST_ERROR]%s()/%d data object add fail\n";
            uVar9 = 0xf09;
            goto LAB_004f1374;
          }
LAB_004f15a8:
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_detail_result_object_add success EXIT\n"
                   ,"_sensor_test_detail_result_object_add",0xf13);
          }
          sensor_test_db_result_ret_nested_mem_free(iVar2);
          FUN_00407df0(iVar2);
          pcVar10 = (char *)json_object_to_json_string_ext(iVar3,0);
          pcVar10 = strdup(pcVar10);
          if (pcVar10 == (char *)0x0) {
            if (sensor_test_err_switch != '\0') {
              printf("[SENSOR_TEST_ERROR]%s()/%d generate result_str failed\n",
                     "jcs_sensor_test_get_detail_result",0x19ba);
            }
            if (iVar3 == 0) {
              uVar9 = 1;
            }
            else {
              json_object_put(iVar3);
              uVar9 = 1;
            }
            goto LAB_004f10a0;
          }
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d The result_str is=%s\n",
                   "jcs_sensor_test_get_detail_result",0x19bd,pcVar10);
          }
          json_object_put(iVar3);
          sVar8 = strlen(pcVar10);
          l_sensor_test_write_file_counter = l_sensor_test_write_file_counter + 1;
          snprintf(acStack_18c,100,"/tmp/st_detail_result_%d");
          __s = fopen(acStack_18c,"w+");
          if (__s == (FILE *)0x0) {
            if (sensor_test_err_switch != '\0') {
              __format = "[SENSOR_TEST_ERROR]%s()/%d open sensor test detail result file failed.\n";
              uVar9 = 0x19cf;
LAB_004f169c:
              printf(__format,"jcs_sensor_test_get_detail_result",uVar9);
            }
          }
          else {
            sVar8 = fwrite(pcVar10,(int)(short)sVar8,1,__s);
            if (sVar8 == 1) {
              free(pcVar10);
              fclose(__s);
              if (sensor_test_debug_switch != '\0') {
                printf("[SENSOR_TEST_DEBUG]%s()/%d jcs get detail result success and write it into tmp file\n"
                       ,"jcs_sensor_test_get_detail_result",0x19e5);
              }
              uVar9 = json_object_new_string(acStack_18c);
              json_object_object_add(param_2,"file_name",uVar9);
              uVar9 = 0;
              goto LAB_004f10a0;
            }
            if (sensor_test_err_switch != '\0') {
              __format = 
              "[SENSOR_TEST_ERROR]%s()/%d write sensor test simple result to file failed.\n";
              uVar9 = 0x19d5;
              goto LAB_004f169c;
            }
          }
          if (pcVar10 != (char *)0x0) {
            free(pcVar10);
          }
          if (__s == (FILE *)0x0) {
            uVar9 = 1;
          }
          else {
            fclose(__s);
            uVar9 = 1;
          }
          goto LAB_004f10a0;
        }
        if (sensor_test_debug_switch != '\0') {
          uVar9 = 0xebf;
          goto LAB_004f13f0;
        }
      }
    }
  }
LAB_004f128c:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d _sensor_test_detail_result_object_add fail EXIT\n",
           "_sensor_test_detail_result_object_add",0xf17);
  }
  if (iVar5 != 0) {
    json_object_put(iVar5);
  }
  if (iVar4 != 0) {
    json_object_put(iVar4);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d generate detail_result_obj fail.\n",
           "jcs_sensor_test_get_detail_result",0x19aa);
  }
  sensor_test_db_result_ret_nested_mem_free(iVar2);
  FUN_00407df0(iVar2);
  uVar9 = 1;
LAB_004f10a0:
  uVar9 = json_object_new_int(uVar9);
  json_object_object_add(param_2,&DAT_00676a24,uVar9);
  return;
code_r0x004f1494:
  json_object_object_add(iVar5,"data",iVar6);
  iVar4 = iVar4 + 1;
  json_object_array_add(0,iVar5);
  if ((int)uVar11 <= iVar4) goto LAB_004f15a8;
  goto LAB_004f14c4;
}

