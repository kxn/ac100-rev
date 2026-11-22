// func jcs_sensor_test_set_test_case @ 004fc740 size=1852

void jcs_sensor_test_set_test_case(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  void *__ptr;
  time_t tVar8;
  char *pcVar9;
  ushort *puVar10;
  short *psVar11;
  undefined4 *__s;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined8 uVar15;
  undefined4 local_330;
  uint local_32c;
  short *local_328;
  undefined4 local_324;
  undefined4 local_320;
  undefined4 local_31c;
  uint local_318;
  undefined4 local_314;
  undefined4 local_310;
  uint local_30c;
  int local_308;
  int local_304;
  undefined1 auStack_300 [64];
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_add_test_case ENTER\n",
           "jcs_sensor_test_set_test_case",0x1a06);
  }
  local_32c = 0;
  local_328 = (short *)0x0;
  local_324 = 0;
  local_320 = 0;
  local_31c = 0;
  local_318 = 0;
  memset(auStack_300,0,0x2d8);
  local_330 = 0;
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  uVar3 = sensor_test_db_get_case_num_max();
  iVar4 = json_object_object_get(param_1,"test_case_id");
  if (iVar4 == 0) {
LAB_004fc808:
    uVar12 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "jcs_sensor_test_set_test_case",0x1a1a);
    }
  }
  else {
    iVar5 = json_object_get_type(iVar4);
    if (iVar5 == 3) {
      uVar12 = json_object_get_int(iVar4);
    }
    else {
      iVar5 = json_object_get_type();
      if (iVar5 != 2) goto LAB_004fc808;
      uVar15 = json_object_get_double(iVar4);
      uVar12 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d set_test_case, case_id=%d\n","jcs_sensor_test_set_test_case",
           0x1a1b,uVar12);
  }
  if (((int)uVar12 < 0) || (uVar3 <= uVar12)) {
    if (sensor_test_err_switch != '\0') {
      pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d test case id ERROR\n";
      uVar6 = 0x1a20;
LAB_004fc930:
      __s = (undefined4 *)0x0;
      printf(pcVar9,"jcs_sensor_test_set_test_case",uVar6);
      psVar11 = (short *)0x0;
      goto LAB_004fc850;
    }
  }
  else {
    uVar6 = json_object_object_get(param_1,"join_test_sensor");
    iVar4 = json_object_array_length(uVar6);
    if (0 < iVar4) {
      psVar11 = (short *)_sensor_test_build_case_setting(param_1);
      if (psVar11 == (short *)0x0) {
        __s = (undefined4 *)0x0;
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d build_case_setting fail\n",
                 "jcs_sensor_test_set_test_case",0x1a31);
          __s = (undefined4 *)0x0;
        }
        goto LAB_004fc850;
      }
      iVar4 = sensor_test_db_get_case_brief_info(uVar12,&local_314);
      if (iVar4 == -1) {
        __s = (undefined4 *)0x0;
        if (sensor_test_err_switch == '\0') goto LAB_004fc850;
        pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d get brief info fail\n";
        uVar6 = 0x1a38;
      }
      else {
        uVar3 = local_30c >> 8 & 0xff;
        if ((local_308 == 0) || (uVar3 == 0)) {
          iVar4 = 0;
          __s = (undefined4 *)0x0;
        }
        else {
          __s = (undefined4 *)FUN_00408450(uVar3 << 2,0x1a3e);
          if (__s == (undefined4 *)0x0) {
            if (sensor_test_err_switch == '\0') goto LAB_004fc850;
            pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d no sensor to test\n";
            uVar6 = 0x1a40;
            goto LAB_004fcc4c;
          }
          iVar4 = 0;
          memset(__s,0,(local_30c >> 8 & 0xff) << 2);
          iVar7 = 0;
          iVar5 = 0;
LAB_004fcafc:
          if (iVar5 < (int)(local_30c >> 8 & 0xff)) {
            for (iVar13 = 0; uVar3 = (uint)*(ushort *)(local_308 + iVar7),
                iVar13 < (int)(uint)*(byte *)(psVar11 + 5); iVar13 = iVar13 + 1) {
              puVar10 = (ushort *)(*(int *)(psVar11 + 0x1a) + iVar13 * 4);
              if (uVar3 == *puVar10) {
                if (*(char *)((ushort *)(local_308 + iVar7) + 1) == '\0') goto LAB_004fcb58;
                *(undefined1 *)(puVar10 + 1) = 1;
                iVar7 = iVar7 + 4;
                iVar5 = iVar5 + 1;
                goto LAB_004fcafc;
              }
            }
            __s[iVar4] = uVar3;
            iVar4 = iVar4 + 1;
LAB_004fcb58:
            iVar7 = iVar7 + 4;
            iVar5 = iVar5 + 1;
            goto LAB_004fcafc;
          }
          FUN_00407df0();
          local_308 = 0;
        }
        if (local_304 == 0) {
          cVar1 = *(char *)(psVar11 + 5);
        }
        else {
          FUN_00407df0();
          local_304 = 0;
          cVar1 = *(char *)(psVar11 + 5);
        }
        iVar5 = 0;
        if (cVar1 != '\0') {
LAB_004fca08:
          do {
            bVar2 = *(byte *)(psVar11 + 5);
LAB_004fca0c:
            if ((int)(uint)bVar2 <= iVar5) {
              iVar5 = sensor_test_deployment_case(2,uVar12,psVar11,&local_330);
              if (iVar5 != -1) {
                if ((iVar4 != 0) && (__s != (undefined4 *)0x0)) {
                  iVar5 = 0;
                  puVar14 = __s;
                  do {
                    local_32c = uVar12;
                    local_328 = psVar11;
                    __ptr = (void *)sensor_test_send_packet_json_generate(1,&local_32c,0);
                    if (__ptr == (void *)0x0) {
                      if (sensor_test_err_switch != '\0') {
                        printf("[SENSOR_TEST_ERROR]%s()/%d generate packet_json fail\n",
                               "jcs_sensor_test_set_test_case",0x1a92);
                      }
                    }
                    else {
                      sensor_pkt_tdcp_send(*(undefined2 *)((int)puVar14 + 2),__ptr);
                      if (sensor_test_debug_switch != '\0') {
                        printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_id=%d, pkt_json_str is:%s\n",
                               "jcs_sensor_test_set_test_case",0x1a96,*puVar14,__ptr);
                      }
                      free(__ptr);
                    }
                    iVar5 = iVar5 + 1;
                    puVar14 = puVar14 + 1;
                  } while (iVar5 < iVar4);
                }
                iVar4 = sensor_test_db_set_case(uVar12,psVar11);
                if (iVar4 != -1) {
                  if (*psVar11 == 0) {
                    tVar8 = time((time_t *)0x0);
                    senosr_test_db_set_case_start_time(uVar12,tVar8);
                  }
                  sensor_test_db_case_setting_mem_free(psVar11);
                  if (sensor_test_debug_switch != '\0') {
                    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs set test case success EXIT\n",
                           "jcs_sensor_test_set_test_case",0x1ab0);
                  }
                  uVar6 = json_object_new_int(0);
                  json_object_object_add(param_2,&DAT_00676a24,uVar6);
                  if (__s == (undefined4 *)0x0) {
                    return;
                  }
                  FUN_00407df0(__s);
                  return;
                }
                if (sensor_test_err_switch == '\0') goto LAB_004fc850;
                pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d set case to db fail\n";
                uVar6 = 0x1a9f;
                goto LAB_004fcc4c;
              }
              if (sensor_test_err_switch == '\0') goto LAB_004fc850;
              pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d set case fail at deploy stage\n";
              uVar6 = 0x1a82;
              goto LAB_004fcc4c;
            }
            iVar13 = iVar5 * 4;
            iVar7 = apmngr_db_entry_get_by_id
                              (*(undefined2 *)(*(int *)(psVar11 + 0x1a) + iVar13),auStack_300);
            if ((iVar7 == 0) &&
               (iVar7 = apdb_get_radio_extend_capability
                                  (local_2c0,auStack_e8,1,0xffffffff,&local_324,0x10), iVar7 == 0))
            {
              if ((local_318 & 1) != 0) {
                iVar5 = iVar5 + 1;
                goto LAB_004fca08;
              }
              if (sensor_test_err_switch == '\0') {
                local_330 = 0xfffffffd;
              }
              else {
                printf("[SENSOR_TEST_ERROR]%s()/%d sensor_id=%d not support sensor_test, add_case fail\n"
                       ,"jcs_sensor_test_set_test_case",0x1a72,
                       (uint)*(ushort *)(*(int *)(psVar11 + 0x1a) + iVar13));
                local_330 = 0xfffffffd;
              }
              goto LAB_004fc850;
            }
            if (sensor_test_err_switch != '\0') goto LAB_004fca3c;
            iVar5 = iVar5 + 1;
          } while( true );
        }
        if (sensor_test_err_switch == '\0') goto LAB_004fc850;
        pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d sensor_cnt <= 0\n";
        uVar6 = 0x1a7a;
      }
LAB_004fcc4c:
      printf(pcVar9,"jcs_sensor_test_set_test_case",uVar6);
      goto LAB_004fc850;
    }
    if (sensor_test_err_switch != '\0') {
      pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d no sensor to test\n";
      uVar6 = 0x1a29;
      goto LAB_004fc930;
    }
  }
  __s = (undefined4 *)0x0;
  psVar11 = (short *)0x0;
LAB_004fc850:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d jcs set test case fail EXIT\n",
           "jcs_sensor_test_set_test_case",0x1aba);
  }
  if (psVar11 != (short *)0x0) {
    sensor_test_db_case_setting_mem_free(psVar11);
  }
  if (__s != (undefined4 *)0x0) {
    FUN_00407df0(__s);
  }
  uVar6 = json_object_new_int(1);
  json_object_object_add(param_2,&DAT_00676a24,uVar6);
  uVar6 = json_object_new_int(local_330);
  json_object_object_add(param_2,"err_code",uVar6);
  return;
LAB_004fca3c:
  iVar5 = iVar5 + 1;
  printf("[SENSOR_TEST_ERROR]%s()/%d apdb_get_radio_extend_capability failed,entry_id=%d\n",
         "jcs_sensor_test_set_test_case",0x1a6c,(uint)*(ushort *)(*(int *)(psVar11 + 0x1a) + iVar13)
        );
  bVar2 = *(byte *)(psVar11 + 5);
  goto LAB_004fca0c;
}

