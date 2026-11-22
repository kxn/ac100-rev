// func sensor_test_deployment_case @ 004fa9e4 size=5544

undefined4 sensor_test_deployment_case(uint param_1,uint param_2,int param_3,undefined4 *param_4)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint *__s;
  void *pvVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar11;
  int *__s_00;
  uint uVar12;
  char *pcVar13;
  undefined4 uVar14;
  int *piVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  ushort local_368 [2];
  undefined4 local_364;
  uint local_360;
  int local_35c;
  int local_358;
  int local_354;
  undefined1 auStack_350 [6];
  undefined2 local_34a;
  undefined1 local_348;
  undefined1 local_347;
  int *local_344;
  int local_340;
  undefined4 local_33c;
  uint local_338 [3];
  uint local_32c;
  int local_328;
  undefined4 local_324;
  undefined1 auStack_320 [32];
  int local_300;
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_deployment_case ENTER, op_type=%d, test_case_id=%d\n"
           ,"sensor_test_deployment_case",0x1d56,param_1,param_2);
  }
  local_364 = 0;
  local_358 = 0;
  local_354 = 0;
  local_338[0] = 0;
  local_338[1] = 0;
  local_338[2] = 0;
  local_32c = 0;
  local_328 = 0;
  local_324 = 0;
  memset(auStack_320,0,0x2d8);
  local_344 = (int *)0x0;
  local_340 = 0;
  local_33c = 0;
  uVar6 = sensor_test_db_get_case_num_max();
  if ((((param_3 == 0) || ((int)param_2 < 0)) || (uVar6 <= param_2)) ||
     (param_4 == (undefined4 *)0x0)) {
    uVar16 = 0xffffffff;
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d input setting_ptr or test_case_id is invalid\n";
    uVar14 = 0x1d78;
    goto LAB_004fab50;
  }
  if (*(char *)(param_3 + 10) == '\0') {
    uVar16 = 0;
    if (sensor_test_warning_switch == '\0') {
      return 0;
    }
    pcVar13 = "[SENSOR_TEST_WARNING]%s()/%d no sensor to deploy\n";
    uVar14 = 0x1d7d;
    goto LAB_004fab50;
  }
  if (2 < param_1) {
    uVar16 = 0xffffffff;
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d op_type invalid\n";
    uVar14 = 0x1d83;
    goto LAB_004fab50;
  }
  cVar1 = *(char *)(param_3 + 0xc);
  local_358 = 0;
  local_354 = 0;
  local_360 = param_2;
  local_35c = param_3;
  if (param_1 == 1) {
    iVar7 = 0;
    while( true ) {
      if ((int)(uint)*(byte *)(param_3 + 10) <= iVar7) {
        return 0;
      }
      pvVar8 = (void *)sensor_test_send_packet_json_generate(1,&local_360,0);
      if (pvVar8 == (void *)0x0) break;
      sensor_pkt_tdcp_send(*(undefined2 *)(*(int *)(param_3 + 0x34) + iVar7 * 4),pvVar8);
      if (sensor_test_debug_switch != '\0') {
        printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_id=%d, pkt_json_str is:%s\n",
               "sensor_test_deployment_case",0x1da4,
               (uint)*(ushort *)(*(int *)(param_3 + 0x34) + iVar7 * 4),pvVar8);
      }
      iVar7 = iVar7 + 1;
      free(pvVar8);
    }
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d generate packet_json fail\n","sensor_test_deployment_case",
             0x1da0);
      __s = (uint *)0x0;
      iVar7 = 0;
      goto LAB_004faf1c;
    }
LAB_004faf14:
    iVar7 = 0;
    __s = (uint *)0x0;
    goto LAB_004faf1c;
  }
  if (param_1 != 0) {
    if (param_1 == 2) {
      iVar7 = *(int *)(param_3 + 0x38);
      goto LAB_004fac70;
    }
LAB_004fabb0:
    uVar16 = 0;
    if (sensor_test_debug_switch == '\0') {
      return 0;
    }
    pcVar13 = "[SENSOR_TEST_DEBUG]%s()/%d deployment_case success\n";
    uVar14 = 0x1eaf;
LAB_004fab50:
    printf(pcVar13,"sensor_test_deployment_case",uVar14);
    return uVar16;
  }
  iVar7 = *(int *)(param_3 + 0x38);
LAB_004fac70:
  if ((iVar7 == 0) || (*(char *)(param_3 + 0xb) == '\0')) {
    uVar16 = 0;
    if (sensor_test_warning_switch == '\0') {
      return 0;
    }
    pcVar13 = "[SENSOR_TEST_WARNING]%s()/%d no ssid to deploy\n";
    uVar14 = 0x1db4;
    goto LAB_004fab50;
  }
  if ((*(char *)(param_3 + 9) == '\0') || (*(int *)(param_3 + 0x30) == 0)) {
    if (sensor_test_err_switch != '\0') {
      iVar7 = 0;
      printf("[SENSOR_TEST_ERROR]%s()/%d case\'s group_cnt<=0 or group_list is null\n",
             "sensor_test_deployment_case",0x1dba);
      __s = (uint *)0x0;
      goto LAB_004faf1c;
    }
    goto LAB_004faf14;
  }
  __s = (uint *)FUN_00408450(0x14,0x1dc0);
  if (__s == (uint *)0x0) {
    iVar7 = 0;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n","sensor_test_deployment_case",0x1dc3);
      iVar7 = 0;
    }
    goto LAB_004faf1c;
  }
  memset(__s,0,0x14);
  if (sensor_test_debug_switch == '\0') {
    cVar2 = *(char *)(param_3 + 9);
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_build_ssid_alloc_list ENTER\n",
           "_sensor_test_build_ssid_alloc_list",0x70d);
    cVar2 = *(char *)(param_3 + 9);
  }
  if (((cVar2 == '\0') || (*(int *)(param_3 + 0x30) == 0)) ||
     ((*(byte *)(param_3 + 0xb) == 0 || (*(char *)(param_3 + 10) == '\0')))) {
    if (sensor_test_err_switch != '\0') {
      pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d case\'s group_cnt<=0 or group_list is null\n";
      uVar16 = 0x719;
LAB_004fb0dc:
      printf(pcVar13,"_sensor_test_build_ssid_alloc_list",uVar16);
    }
LAB_004fb04c:
    iVar7 = 0;
    if (sensor_test_err_switch == '\0') goto LAB_004faf1c;
    pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d build_ssid_alloc fail\n";
    uVar16 = 0x1dca;
  }
  else {
    __s[1] = (uint)*(byte *)(param_3 + 0xb);
    if (sensor_test_debug_switch == '\0') {
      uVar6 = __s[1];
    }
    else {
      printf("[SENSOR_TEST_DEBUG]%s()/%d ssid_alloc_list->ssid_cnt=%d\n",
             "_sensor_test_build_ssid_alloc_list",0x71e);
      uVar6 = __s[1];
    }
    __s[2] = 0;
    if ((int)uVar6 < 1) {
      if (sensor_test_warning_switch != '\0') {
        pcVar13 = "[SENSOR_TEST_WARNING]%s()/%d no ssid_alloc_list to build\n";
        uVar16 = 0x72c;
        goto LAB_004fb0dc;
      }
      goto LAB_004fb04c;
    }
    pvVar8 = (void *)FUN_00408450(uVar6 * 0x14,0x722);
    __s[2] = (uint)pvVar8;
    if (pvVar8 == (void *)0x0) {
      if (sensor_test_err_switch != '\0') {
        pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
        uVar16 = 0x725;
        goto LAB_004fb0dc;
      }
      goto LAB_004fb04c;
    }
    memset(pvVar8,0,__s[1] * 0x14);
    __s[3] = 0;
    uVar6 = FUN_004080a0(_sensor_test_bssid_alloc_hash_obj,_sensor_test_bssid_alloc_hash_key,
                         _sensor_test_bssid_alloc_hash_cmp,1000);
    __s[3] = uVar6;
    if (uVar6 == 0) {
      if (sensor_test_err_switch != '\0') {
        uVar16 = 0x734;
LAB_004fbeb8:
        printf("[SENSOR_TEST_ERROR]%s()/%d hash create fail\n","_sensor_test_build_ssid_alloc_list",
               uVar16);
      }
LAB_004fbe60:
      if (sensor_test_err_switch == '\0') {
        uVar6 = __s[2];
      }
      else {
        printf("[SENSOR_TEST_ERROR]%s()/%d _sensor_test_build_ssid_alloc_list fail EXIT\n",
               "_sensor_test_build_ssid_alloc_list",0x761);
        uVar6 = __s[2];
      }
      if (uVar6 != 0) {
        FUN_00407df0();
        __s[2] = 0;
        __s[1] = 0;
        __s[3] = 0;
      }
      goto LAB_004fb04c;
    }
    *__s = param_2;
    for (iVar7 = 0; iVar7 < (int)__s[1]; iVar7 = iVar7 + 1) {
      iVar10 = iVar7 * 0x14;
      *(undefined4 *)(__s[2] + iVar10) = *(undefined4 *)(*(int *)(param_3 + 0x38) + iVar7 * 0x220);
      *(undefined4 *)(__s[2] + iVar10 + 4) =
           *(undefined4 *)(*(int *)(param_3 + 0x38) + iVar7 * 0x220 + 4);
      FUN_0051ad88(__s[2] + iVar10 + 8);
    }
    for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(param_3 + 9); iVar7 = iVar7 + 1) {
      apmngr_db_foreach_proc_by_group
                (*(undefined2 *)(*(int *)(param_3 + 0x30) + iVar7 * 2),0x15f0000,
                 _sensor_test_build_bssid_cb,__s);
    }
    __s[4] = 0;
    iVar7 = 0;
    uVar6 = FUN_004080a0(_sensor_test_sensor_alloc_hash_obj,_sensor_test_sensor_alloc_hash_key,
                         _sensor_test_sensor_alloc_hash_cmp,1000);
    __s[4] = uVar6;
    if (uVar6 == 0) {
      if (sensor_test_err_switch != '\0') {
        uVar16 = 0x74c;
        goto LAB_004fbeb8;
      }
      goto LAB_004fbe60;
    }
    while (iVar7 < (int)(uint)*(byte *)(param_3 + 10)) {
      puVar9 = (undefined2 *)FUN_00408450(4,0x752);
      if (puVar9 == (undefined2 *)0x0) {
        if (sensor_test_err_switch == '\0') {
          iVar7 = iVar7 + 1;
        }
        else {
          printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n","_sensor_test_build_ssid_alloc_list"
                 ,0x755);
          iVar7 = iVar7 + 1;
        }
      }
      else {
        *(undefined1 *)puVar9 = 0;
        *(undefined1 *)((int)puVar9 + 1) = 0;
        *(undefined1 *)(puVar9 + 1) = 0;
        *(undefined1 *)((int)puVar9 + 3) = 0;
        uVar4 = *(undefined2 *)(*(int *)(param_3 + 0x34) + iVar7 * 4);
        puVar9[1] = 0;
        *puVar9 = uVar4;
        FUN_00408380(__s[4],puVar9);
        iVar7 = iVar7 + 1;
      }
    }
    iVar10 = FUN_004080a0(_sensor_test_temp_alloc_hash_obj,_sensor_test_temp_alloc_hash_key,
                          _sensor_test_temp_alloc_hash_cmp,1000);
    if (iVar10 != 0) {
      local_48 = 0;
      local_3c = -0x5a;
      if ((int)cVar1 + 0x5aU < 0x38) {
        local_3c = (int)cVar1;
      }
      iVar7 = 0;
      iVar18 = 0;
      for (; (int)local_48 < (int)(uint)*(byte *)(param_3 + 10); local_48 = local_48 + 1) {
        iVar17 = local_48 * 4;
        iVar11 = apmngr_db_entry_get_by_id
                           (*(undefined2 *)(*(int *)(param_3 + 0x34) + iVar17),auStack_320);
        if (iVar11 != -1) {
          if (local_300 == 0) {
            if (sensor_test_warning_switch != '\0') {
              iVar11 = *(int *)(param_3 + 0x34);
              pcVar13 = "[SENSOR_TEST_WARNING]%s()/%d sensor_id=%d offline,continue\n";
              uVar16 = 0x1de1;
LAB_004fb42c:
              printf(pcVar13,"sensor_test_deployment_case",uVar16,(uint)*(ushort *)(iVar11 + iVar17)
                    );
            }
          }
          else {
            iVar11 = sensor_db_get(*(undefined2 *)(*(int *)(param_3 + 0x34) + iVar17),local_338,1);
            if (iVar11 == -1) {
              if (sensor_test_warning_switch != '\0') {
                iVar11 = *(int *)(param_3 + 0x34);
                pcVar13 = "[SENSOR_TEST_WARNING]%s()/%d sensor_db_get fail, sensor_id=%d\n";
                uVar16 = 0x1de8;
                goto LAB_004fb42c;
              }
            }
            else {
              if (sensor_test_debug_switch != '\0') {
                printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_id=%d, scanned_bssid_num=%d\n",
                       "sensor_test_deployment_case",0x1dec,
                       (uint)*(ushort *)(*(int *)(param_3 + 0x34) + iVar17),(int)local_32c._0_2_);
              }
              if (local_32c._0_2_ != 0) {
                if (sensor_test_debug_switch == '\0') {
                  uVar6 = __s[2];
                }
                else {
                  printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_update_ssid_alloc_list_by_scan_ssid ENTER\n"
                         ,"_sensor_test_update_ssid_alloc_list_by_scan_ssid",0x586);
                  uVar6 = __s[2];
                }
                if ((uVar6 == 0) || (__s[3] == 0)) {
                  if (sensor_test_err_switch != '\0') {
                    pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d input invalid\n";
                    uVar16 = 0x58f;
LAB_004fba9c:
                    printf(pcVar13,"_sensor_test_update_ssid_alloc_list_by_scan_ssid",uVar16);
                  }
LAB_004fb734:
                  iVar7 = 0;
                  if (sensor_test_err_switch == '\0') goto LAB_004faf1c;
                  pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d update ssid alloc fail\n";
                  uVar16 = 0x1df2;
                  goto LAB_004fb06c;
                }
                if ((local_32c._0_2_ == 0) || (__s[1] == 0)) {
                  if (sensor_test_debug_switch == '\0') {
                    iVar18 = 1;
                  }
                  else {
                    printf("[SENSOR_TEST_DEBUG]%s()/%d no bssid scanned or no ssid_allco_cnt\n",
                           "_sensor_test_update_ssid_alloc_list_by_scan_ssid",0x595);
                    iVar18 = 1;
                  }
                }
                else {
                  if (local_328 == 0) {
                    if (sensor_test_err_switch != '\0') {
                      pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d scan_bssid or ssid_list is null\n";
                      uVar16 = 0x59b;
                      goto LAB_004fba9c;
                    }
                    goto LAB_004fb734;
                  }
                  local_44 = 0;
                  while( true ) {
                    iVar18 = 1;
                    if (local_32c._0_2_ <= local_44) break;
                    local_40 = local_44 * 0x14;
                    if (local_3c <= *(char *)((int)(local_328 + local_40) + 6)) {
                      memcpy(auStack_350,(void *)(local_328 + local_40),6);
                      iVar18 = stats_db_bssid_get(auStack_350);
                      if (iVar18 == 0) {
                        iVar11 = 0;
                        uVar16 = rdmngr_db_generate_rd_id(local_34a,local_348);
                        iVar18 = wserv_db_rd_get_wserv_id(uVar16,local_347);
                        if (iVar18 != -1) {
                          for (; iVar11 < (int)__s[1]; iVar11 = iVar11 + 1) {
                            if ((*(int *)(__s[2] + iVar11 * 0x14) == iVar18) &&
                               (iVar17 = FUN_00407fa0(__s[3],local_328 + local_40), iVar17 != 0)) {
                              uVar6 = local_338[0] >> 0x10;
                              iVar7 = local_328 + local_40;
                              local_40 = uVar6;
                              if (iVar7 == 0) {
                                if (sensor_test_err_switch != '\0') {
                                  pcVar13 = 
                                  "[SENSOR_TEST_ERROR]%s()/%d dynamic_alloc_strategy input invalid\n"
                                  ;
                                  uVar16 = 0x541;
LAB_004fbdd8:
                                  iVar7 = 1;
                                  printf(pcVar13,"_sensor_test_add_candidate_sensor_strategy",uVar16
                                        );
                                  break;
                                }
                              }
                              else {
                                iVar18 = FUN_00407fa0(iVar10,(void *)(iVar17 + 0xc));
                                if (iVar18 == 0) {
                                  pvVar8 = (void *)FUN_00408450(0x1c,0x55a);
                                  if (pvVar8 != (void *)0x0) {
                                    memset(pvVar8,0,0x1c);
                                    memcpy(pvVar8,(void *)(iVar17 + 0xc),6);
                                    *(undefined1 *)((int)pvVar8 + 7) = 1;
                                    *(short *)((int)pvVar8 + 8) = (short)local_40;
                                    *(undefined1 *)((int)pvVar8 + 10) = *(undefined1 *)(iVar7 + 6);
                                    *(undefined1 *)((int)pvVar8 + 6) = *(undefined1 *)(iVar7 + 6);
                                    FUN_00408380(iVar10,pvVar8);
                                    cVar1 = *(char *)(iVar17 + 0x22);
                                    goto LAB_004fb3bc;
                                  }
                                  if (sensor_test_err_switch != '\0') {
                                    pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
                                    uVar16 = 0x55d;
                                    goto LAB_004fbdd8;
                                  }
                                }
                                else {
                                  bVar3 = *(byte *)(iVar18 + 7);
                                  if (bVar3 < 5) {
                                    if (*(char *)(iVar18 + 6) < *(char *)(iVar7 + 6)) {
                                      *(char *)(iVar18 + 6) = *(char *)(iVar7 + 6);
                                    }
                                    puVar9 = (undefined2 *)(iVar18 + (bVar3 + 2) * 4);
                                    *puVar9 = (short)local_40;
                                    *(undefined1 *)(puVar9 + 1) = *(undefined1 *)(iVar7 + 6);
                                    *(byte *)(iVar18 + 7) = bVar3 + 1;
                                    cVar1 = *(char *)(iVar17 + 0x22);
LAB_004fb3bc:
                                    if (cVar1 == '\0') {
                                      *(undefined1 *)(iVar17 + 0x22) = 1;
                                    }
                                  }
                                }
                              }
                              iVar7 = 1;
                              break;
                            }
                          }
                        }
                      }
                    }
                    local_44 = local_44 + 1;
                  }
                }
              }
              sensor_db_entry_free(local_338);
              local_338[0] = 0;
              local_338[1] = 0;
              local_338[2] = 0;
              local_32c = 0;
              local_328 = 0;
              local_324 = 0;
            }
          }
        }
      }
      if (((iVar18 != 0) && (iVar7 == iVar18)) && (iVar7 = FUN_00407ed0(iVar10), iVar7 != 0)) {
        __s_00 = (int *)FUN_00408450(iVar7 << 2,0x1dff);
        if (__s_00 == (int *)0x0) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d temp_alloc_array mem malloc fail\n",
                   "sensor_test_deployment_case",0x1e02);
          }
          FUN_00408570(iVar10,_sensor_test_delete_temp_alloc_hash_cb,iVar10);
          iVar7 = 0;
          FUN_00408310(iVar10);
          goto LAB_004faf1c;
        }
        memset(__s_00,0,iVar7 << 2);
        local_33c = 0;
        local_344 = __s_00;
        local_340 = iVar7;
        FUN_00408570(iVar10,_sensor_test_temp_alloc_hash_cb,&local_344);
        if (1 < iVar7) {
          if (iVar7 == 2) {
            iVar18 = *__s_00;
            if (*(char *)(__s_00[1] + 6) < *(char *)(iVar18 + 6)) {
              *__s_00 = __s_00[1];
              __s_00[1] = iVar18;
            }
          }
          __quick_sort(__s_00,0,iVar7 + -1);
        }
        local_48 = (uint)*(short *)(param_3 + 2);
        local_368[0] = 0;
        uVar6 = sensor_test_db_get_case_num_max();
        if ((0 < iVar7) && (param_2 < uVar6)) {
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d ======cur_sch_period=%d\n",
                   "_sensor_test_bssid_alloc_proc",0x4be,local_48);
          }
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d array_size=%d\n","_sensor_test_bssid_alloc_proc",
                   0x4c1,iVar7);
          }
          local_38 = 0;
          piVar15 = __s_00;
          do {
            iVar18 = *piVar15;
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d BSSID\'s best_rssi=%d\n",
                     "_sensor_test_bssid_alloc_proc",0x4c4,(int)*(char *)(iVar18 + 6));
              iVar18 = *piVar15;
            }
            if (*(char *)(iVar18 + 7) != '\0') {
              local_368[0] = *(ushort *)(iVar18 + 8);
              local_34 = (int)*(char *)(*piVar15 + 10);
              if (1 < *(byte *)(*piVar15 + 7)) {
                if (sensor_test_debug_switch != '\0') {
                  printf("[SENSOR_TEST_DEBUG]%s()/%d more than 1 candidate\n",
                         "_sensor_test_bssid_alloc_proc",0x4ce);
                }
                for (local_44 = 1; local_44 < (int)(uint)*(byte *)(*piVar15 + 7);
                    local_44 = local_44 + 1) {
                  local_40 = FUN_00407fa0(__s[4],local_368);
                  local_30 = (local_44 + 2) * 4;
                  local_3c = FUN_00407fa0(__s[4],*piVar15 + local_30);
                  if ((int)local_48 < 1) {
                    uVar6 = 0;
                    if (local_40 != 0) {
                      uVar6 = (uint)*(ushort *)(local_40 + 2);
                    }
                    uVar12 = 0;
                    if (local_3c != 0) {
                      uVar12 = (uint)*(ushort *)(local_3c + 2);
                    }
                  }
                  else {
                    uVar6 = _sensor_test_get_allocated_bssid_num(local_368[0],param_2);
                    uVar12 = _sensor_test_get_allocated_bssid_num
                                       (*(undefined2 *)(*piVar15 + local_30),param_2);
                    if (local_40 != 0) {
                      if (local_48 == 0) {
                        trap(7);
                      }
                      uVar6 = uVar6 + ((uint)*(ushort *)(local_40 + 2) * 0x5a0) / local_48;
                    }
                    if (local_3c != 0) {
                      if (local_48 == 0) {
                        trap(7);
                      }
                      uVar12 = uVar12 + ((uint)*(ushort *)(local_3c + 2) * 0x5a0) / local_48;
                    }
                  }
                  if ((int)uVar12 < (int)uVar6) {
                    iVar18 = (local_44 + 2) * 4;
                    local_368[0] = *(ushort *)(*piVar15 + iVar18);
                    local_34 = (int)*(char *)(*piVar15 + iVar18 + 2);
                  }
                }
              }
              if (sensor_test_debug_switch != '\0') {
                printf("[SENSOR_TEST_DEBUG]%s()/%d selected sensor_id=%d\n",
                       "_sensor_test_bssid_alloc_proc",0x501,(uint)local_368[0]);
              }
              if ((int)local_48 < 1) {
                iVar18 = FUN_00407fa0(__s[4],local_368);
                if (iVar18 != 0) {
                  bVar5 = *(ushort *)(iVar18 + 2) + 1 < 0x19;
                  goto LAB_004fbcd0;
                }
                uVar6 = __s[3];
              }
              else {
                iVar18 = FUN_00407fa0(__s[4],local_368);
                iVar11 = _sensor_test_get_allocated_bssid_num(local_368[0],param_2);
                if (iVar18 != 0) {
                  if (local_48 == 0) {
                    trap(7);
                  }
                  iVar11 = iVar11 + ((*(ushort *)(iVar18 + 2) + 1) * 0x5a0) / local_48;
                }
                bVar5 = iVar11 < 0x481;
LAB_004fbcd0:
                if (!bVar5) goto LAB_004fbd4c;
                uVar6 = __s[3];
              }
              iVar18 = FUN_00407fa0(uVar6,*piVar15);
              if (iVar18 != 0) {
                *(ushort *)(iVar18 + 0x20) = local_368[0];
                *(char *)(iVar18 + 0x23) = (char)local_34;
                *(undefined1 *)(iVar18 + 0x22) = 2;
                iVar18 = FUN_00407fa0(__s[4],local_368);
                if ((iVar18 != 0) &&
                   (*(short *)(iVar18 + 2) = *(short *)(iVar18 + 2) + 1,
                   sensor_test_debug_switch != '\0')) {
                  printf("[SENSOR_TEST_DEBUG]%s()/%d updated bssid_num=%d\n",
                         "_sensor_test_bssid_alloc_proc",0x534);
                }
              }
            }
LAB_004fbd4c:
            piVar15 = piVar15 + 1;
            local_38 = local_38 + 1;
          } while (local_38 != iVar7);
        }
        piVar15 = __s_00;
        for (iVar18 = 0; iVar18 < iVar7; iVar18 = iVar18 + 1) {
          if (*piVar15 != 0) {
            FUN_00407f40(iVar10);
            FUN_00407df0(*piVar15);
            *piVar15 = 0;
          }
          piVar15 = piVar15 + 1;
        }
        FUN_00407df0(__s_00);
        FUN_00408310(iVar10);
      }
      local_48 = 0;
      bVar5 = true;
      iVar7 = 0;
      while (iVar7 < (int)(uint)*(byte *)(param_3 + 10)) {
        iVar18 = iVar7 * 4;
        iVar10 = _sensor_test_generate_ssid_info_to_deploy
                           (&local_358,__s,*(undefined2 *)(*(int *)(param_3 + 0x34) + iVar18));
        if (iVar10 == -1) {
          iVar7 = 0;
          if (sensor_test_err_switch == '\0') goto LAB_004faf1c;
          pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d _sensor_test_generate_ssid_info_to_deploy fail\n";
          uVar16 = 0x1e2e;
          goto LAB_004fb06c;
        }
        if ((local_358 == 0) || (local_354 == 0)) {
          if (sensor_test_warning_switch != '\0') {
            printf("[SENSOR_TEST_WARNING]%s()/%d sensor_id=%d, has no ssid_info_to_deploy\n",
                   "sensor_test_deployment_case",0x1e34,
                   (uint)*(ushort *)(*(int *)(param_3 + 0x34) + iVar18));
          }
          if (param_1 == 2) {
            *(undefined1 *)(*(int *)(param_3 + 0x34) + iVar18 + 2) = 0;
            pvVar8 = (void *)sensor_test_send_packet_json_generate(1,&local_360,0);
            if (pvVar8 == (void *)0x0) {
              iVar7 = 0;
              if (sensor_test_err_switch == '\0') goto LAB_004faf1c;
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d generate packet_json fail\n";
              uVar16 = 0x1e3c;
              goto LAB_004fb06c;
            }
            sensor_pkt_tdcp_send(*(undefined2 *)(*(int *)(param_3 + 0x34) + iVar18),pvVar8);
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_id=%d, pkt_json_str is:%s\n",
                     "sensor_test_deployment_case",0x1e40,
                     (uint)*(ushort *)(*(int *)(param_3 + 0x34) + iVar18),pvVar8);
            }
            free(pvVar8);
            iVar7 = iVar7 + 1;
          }
          else {
            iVar7 = iVar7 + 1;
          }
        }
        else {
          param_1 = 2;
          if (*(char *)(*(int *)(param_3 + 0x34) + iVar18 + 2) == '\0') {
            param_1 = 0;
          }
          pvVar8 = (void *)sensor_test_send_packet_json_generate(param_1,&local_360,&local_358);
          if (pvVar8 == (void *)0x0) {
            iVar7 = 0;
            if (sensor_test_err_switch == '\0') goto LAB_004faf1c;
            pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d generate packet_json fail\n";
            uVar16 = 0x1e59;
            goto LAB_004fb06c;
          }
          sensor_pkt_tdcp_send(*(undefined2 *)(*(int *)(param_3 + 0x34) + iVar18),pvVar8);
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_id=%d, pkt_json_str is:%s\n",
                   "sensor_test_deployment_case",0x1e5d,
                   (uint)*(ushort *)(*(int *)(param_3 + 0x34) + iVar18),pvVar8);
          }
          free(pvVar8);
          if (local_48 == 0) {
            sensor_test_db_case_result_init(param_2);
            local_48 = 1;
          }
          iVar10 = 0;
          if (local_354 != 0) {
            local_40 = param_3 + 0x3c;
            while (iVar10 < local_358) {
              local_44 = iVar10 * 0x254;
              for (iVar11 = 0; iVar17 = local_354 + local_44, iVar11 < *(int *)(iVar17 + 8);
                  iVar11 = iVar11 + 1) {
                sensor_test_db_add_bssid_to_result_list_with_service
                          (param_2,local_40,*(int *)(iVar17 + 0x250) + iVar11 * 0x18 + 0xc);
              }
              iVar10 = iVar10 + 1;
              if (*(int *)(iVar17 + 0x250) != 0) {
                FUN_00407df0();
                *(undefined4 *)(local_354 + local_44 + 0x250) = 0;
              }
            }
            FUN_00407df0(local_354);
            local_354 = 0;
            local_358 = 0;
          }
          bVar5 = false;
          iVar7 = iVar7 + 1;
          *(undefined1 *)(*(int *)(param_3 + 0x34) + iVar18 + 2) = 1;
        }
      }
      if (bVar5) {
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d no sensor is deployed, please check neighbor scan bssid is available or other setting params\n"
                 ,"sensor_test_deployment_case",0x1e83);
        }
        iVar7 = 0;
        *param_4 = 0xfffffffc;
        goto LAB_004faf1c;
      }
      iVar7 = param_2 * 4;
      sensor_test_db_set_case_join_test_sensor_list(param_2,*(undefined4 *)(param_3 + 0x34));
      FUN_004082d0(0,0xffffffff);
      _sensor_test_ssid_alloc_list_mem_free(*(undefined4 *)(l_sensor_test_ssid_alloc_list + iVar7));
      *(undefined4 *)(l_sensor_test_ssid_alloc_list + iVar7) = 0;
      sensor_test_sql_del_bssid_alloc_table(param_2);
      *(uint **)(l_sensor_test_ssid_alloc_list + iVar7) = __s;
      iVar7 = _sensor_test_build_bssid_alloc_list(param_2,__s,&local_364);
      if ((iVar7 == 0) ||
         (iVar10 = sensor_test_sql_add_bssid_alloc_table(param_2,iVar7,local_364), iVar10 == -1)) {
        FUN_00407f30(0);
        __s = (uint *)0x0;
        goto LAB_004faf1c;
      }
      FUN_00407df0(iVar7);
      FUN_00407f30(0);
      goto LAB_004fabb0;
    }
    iVar7 = 0;
    if (sensor_test_err_switch == '\0') goto LAB_004faf1c;
    pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d hash create fail\n";
    uVar16 = 0x1dd3;
  }
LAB_004fb06c:
  iVar7 = 0;
  printf(pcVar13,"sensor_test_deployment_case",uVar16);
LAB_004faf1c:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d deployment_case fail, op_type=%d, test_case_id=%d\n",
           "sensor_test_deployment_case",0x1eb3,param_1,param_2);
  }
  iVar10 = 0;
  local_35c = 0;
  if (local_354 != 0) {
    while (iVar10 < local_358) {
      iVar18 = iVar10 * 0x254;
      iVar10 = iVar10 + 1;
      if (*(int *)(local_354 + iVar18 + 0x250) != 0) {
        FUN_00407df0();
        *(undefined4 *)(local_354 + iVar18 + 0x250) = 0;
      }
    }
    FUN_00407df0();
    local_354 = 0;
  }
  if (local_328 != 0) {
    FUN_00407df0();
    local_328 = 0;
    local_32c = local_32c & 0xffff;
  }
  if (__s != (uint *)0x0) {
    _sensor_test_ssid_alloc_list_mem_free(__s);
  }
  if (iVar7 == 0) {
    return 0xffffffff;
  }
  FUN_00407df0(iVar7);
  return 0xffffffff;
}

