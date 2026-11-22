// func jcs_sensor_test_get_ssid_list @ 004f4c80 size=3840

void jcs_sensor_test_get_ssid_list(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar11;
  int iVar8;
  undefined2 uVar12;
  size_t sVar9;
  int iVar10;
  char *pcVar13;
  char *__format;
  undefined4 uVar14;
  void *__src;
  FILE *__s;
  ushort *puVar15;
  undefined2 *puVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
  undefined4 local_1320;
  int local_131c;
  int local_1318;
  int local_1314;
  int local_1310;
  undefined4 local_130c;
  uint local_1308;
  undefined2 local_1304;
  char acStack_1300 [100];
  char local_129c [12];
  undefined4 local_1290;
  int local_128c;
  undefined4 local_1288;
  undefined2 local_119c [200];
  undefined1 auStack_100c [362];
  int local_ea2;
  undefined1 auStack_e04 [300];
  undefined4 local_cd8;
  undefined1 auStack_cd4 [58];
  int local_c9a;
  ushort local_bfc [300];
  undefined1 auStack_9a4 [4];
  undefined4 auStack_9a0 [600];
  undefined2 *local_40;
  int local_3c;
  ushort *local_38;
  int local_34;
  int local_30;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_get_ssid_list ENTER\n",
           "jcs_sensor_test_get_ssid_list",0x1486);
  }
  memset(local_119c,0,400);
  memset(local_bfc,0,600);
  memset(auStack_9a4,0,0x960);
  local_1318 = 0;
  memset(acStack_1300,0,100);
  iVar2 = json_object_object_get(param_1,"start");
  if (iVar2 == 0) {
    iVar2 = 0;
    bVar1 = false;
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      bVar1 = true;
      iVar2 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar18 = json_object_get_double(iVar2);
        iVar2 = __fixdfsi((int)((ulonglong)uVar18 >> 0x20),(int)uVar18);
      }
      else {
        if (jcs_err_switch != 0) {
          iVar2 = -1;
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "jcs_sensor_test_get_ssid_list",0x14a4);
          bVar1 = true;
          goto LAB_004f4d5c;
        }
        iVar2 = -1;
      }
      bVar1 = true;
    }
  }
LAB_004f4d5c:
  iVar3 = json_object_object_get(param_1,"end");
  if (iVar3 == 0) {
    iVar3 = 0;
    bVar1 = false;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      iVar3 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 == 2) {
        uVar18 = json_object_get_double(iVar3);
        iVar3 = __fixdfsi((int)((ulonglong)uVar18 >> 0x20),(int)uVar18);
      }
      else {
        iVar3 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "jcs_sensor_test_get_ssid_list",0x14af);
        }
      }
    }
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d start=%d, end=%d\n","jcs_sensor_test_get_ssid_list",0x14b5,
           iVar2,iVar3);
  }
  iVar4 = json_object_object_get(param_1,"sensor_list");
  if (((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 5)) ||
     (iVar5 = json_object_array_length(iVar4), iVar5 < 1)) {
    if (sensor_test_err_switch != '\0') {
      pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d sensor_id list is empty\n";
      uVar14 = 0x14bc;
LAB_004f4f44:
      printf(pcVar13,"jcs_sensor_test_get_ssid_list",uVar14);
    }
  }
  else {
    iVar5 = json_object_array_length(iVar4);
    if (iVar5 < 1) {
      if (sensor_test_err_switch != '\0') {
        pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d input sensor list len <= 0\n";
        uVar14 = 0x14c3;
        goto LAB_004f4f44;
      }
    }
    else {
      local_3c = 300;
      if (iVar5 < 0x12d) {
        local_3c = iVar5;
      }
      puVar15 = local_bfc;
      iVar5 = 0;
      do {
        iVar6 = json_object_array_get_idx(iVar4,iVar5);
        if (iVar6 == 0) {
LAB_004f4fe4:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_sensor_test_get_ssid_list",0x14cb);
          }
          *puVar15 = 0xffff;
        }
        else {
          iVar7 = json_object_get_type(iVar6);
          if (iVar7 == 3) {
            uVar11 = json_object_get_int(iVar6);
            *puVar15 = uVar11;
          }
          else {
            iVar7 = json_object_get_type();
            if (iVar7 != 2) goto LAB_004f4fe4;
            uVar18 = json_object_get_double(iVar6);
            uVar11 = __fixunsdfsi((int)((ulonglong)uVar18 >> 0x20),(int)uVar18);
            *puVar15 = uVar11;
          }
        }
        iVar5 = iVar5 + 1;
        puVar15 = puVar15 + 1;
      } while (iVar5 < local_3c);
      iVar4 = json_object_object_get(param_1,"group_list");
      if (((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 5)) ||
         (iVar5 = json_object_array_length(iVar4), iVar5 < 1)) {
        if (sensor_test_err_switch != '\0') {
          pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d group_id list is empty\n";
          uVar14 = 0x14d4;
          goto LAB_004f4f44;
        }
      }
      else {
        iVar5 = json_object_array_length(iVar4);
        if (0 < iVar5) {
          iVar6 = 200;
          if (iVar5 < 0xc9) {
            iVar6 = iVar5;
          }
          puVar16 = local_119c;
          iVar5 = 0;
          do {
            iVar7 = json_object_array_get_idx(iVar4,iVar5);
            if (iVar7 == 0) {
LAB_004f5194:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"jcs_sensor_test_get_ssid_list",0x14e1);
              }
              uVar12 = 0xffff;
LAB_004f51ac:
              *puVar16 = uVar12;
            }
            else {
              iVar8 = json_object_get_type(iVar7);
              if (iVar8 != 3) {
                iVar8 = json_object_get_type();
                if (iVar8 != 2) goto LAB_004f5194;
                uVar18 = json_object_get_double(iVar7);
                uVar12 = __fixunsdfsi((int)((ulonglong)uVar18 >> 0x20),(int)uVar18);
                goto LAB_004f51ac;
              }
              uVar12 = json_object_get_int(iVar7);
              *puVar16 = uVar12;
            }
            iVar5 = iVar5 + 1;
            puVar16 = puVar16 + 1;
          } while (iVar5 < iVar6);
          iVar5 = -0x5a;
          iVar4 = json_object_object_get(param_1,"rssi_threshold");
          if (iVar4 != 0) {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 == 3) {
              iVar5 = json_object_get_int(iVar4);
            }
            else {
              iVar5 = json_object_get_type();
              if (iVar5 == 2) {
                uVar18 = json_object_get_double(iVar4);
                iVar5 = __fixdfsi((int)((ulonglong)uVar18 >> 0x20),(int)uVar18);
              }
              else {
                iVar5 = -1;
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"jcs_sensor_test_get_ssid_list",0x14e8);
                }
              }
            }
            if (0x37 < iVar5 + 0x5aU) {
              iVar5 = -0x5a;
            }
          }
          iVar4 = json_object_new_array();
          if (iVar4 == 0) {
            if (sensor_test_err_switch != '\0') {
              pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d create serv_list_obj fail\n";
              uVar14 = 0x14f8;
              goto LAB_004f5968;
            }
          }
          else {
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_generate_serv_list_by_scanned_bssid ENTER, sensor_list_len=%d, group_list_len=%d\n"
                     ,"_sensor_test_generate_serv_list_by_scanned_bssid",0x2d1,local_3c,iVar6);
            }
            local_38 = local_bfc;
            local_131c = 0;
            local_1320 = 0;
            local_1318 = 0;
            local_129c[0] = '\0';
            local_129c[1] = '\0';
            local_129c[2] = '\0';
            local_129c[3] = '\0';
            local_129c[4] = '\0';
            local_129c[5] = '\0';
            local_129c[6] = '\0';
            local_129c[7] = '\0';
            local_129c[8] = '\0';
            local_129c[9] = '\0';
            local_129c[10] = '\0';
            local_129c[0xb] = '\0';
            local_1290 = 0;
            local_128c = 0;
            local_1288 = 0;
            local_34 = 0;
            do {
              uVar11 = *local_38;
              iVar7 = sensor_db_get((uint)uVar11,local_129c,1);
              if (iVar7 == -1) {
                if (sensor_test_warning_switch != '\0') {
                  printf("[SENSOR_TEST_WARNING]%s()/%d sensor_db_get fail, sensor_id=%d\n",
                         "_sensor_test_generate_serv_list_by_scanned_bssid",0x2f0,(uint)uVar11);
                }
              }
              else {
                if (sensor_test_debug_switch != '\0') {
                  printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_id=%d, scanned_bssid_num=%d\n",
                         "_sensor_test_generate_serv_list_by_scanned_bssid",0x2f3,(uint)*local_38,
                         (int)local_1290._0_2_);
                }
                iVar7 = 0;
                if (local_1290._0_2_ != 0) {
LAB_004f5334:
                  if (iVar7 < local_1290._0_2_) {
                    local_130c = 0;
                    local_30 = iVar7 * 0x14;
                    local_1308 = 0;
                    local_1304 = 0;
                    __src = (void *)(local_128c + local_30);
                    memcpy(&local_130c,__src,6);
                    if (*(char *)((int)__src + 6) < iVar5) {
LAB_004f5384:
                      iVar7 = iVar7 + 1;
                    }
                    else {
                      iVar8 = stats_db_bssid_get(&local_130c);
                      if (iVar8 == 0) {
                        local_40 = local_119c;
                        iVar8 = 0;
                        local_1314 = 0;
                        local_1310 = local_1308 << 0x10;
                        do {
                          apmngr_db_foreach_proc_by_group
                                    (*local_40,0x15f0000,_sensor_test_ap_exists_cb,&local_1314);
                          local_40 = local_40 + 1;
                          if (local_1314 == 1) {
                            uVar14 = rdmngr_db_generate_rd_id(local_1308 & 0xffff,local_1304._0_1_);
                            rdmngr_db_get_freq_band_idx(uVar14,&local_131c,&local_1320);
                            local_40 = (undefined2 *)0x1;
                            if ((local_131c != 0) &&
                               (local_40 = (undefined2 *)0x10, local_131c != 1)) {
                              local_40 = (undefined2 *)0x0;
                            }
                            iVar8 = wserv_db_rd_get_wserv_id(uVar14,(undefined1)local_1304);
                            if (iVar8 == -1) {
                              if (sensor_test_warning_switch != '\0') {
                                printf("[SENSOR_TEST_WARNING]%s()/%d get serv_id fail\n",
                                       "_sensor_test_generate_serv_list_by_scanned_bssid",0x317);
                              }
                              printmac(local_128c + local_30);
                            }
                            else {
                              memset(auStack_100c,0,0x205);
                              iVar10 = wserv_db_get_entry_by_id(iVar8,auStack_100c);
                              if ((iVar10 == 0) && (local_ea2 == 2)) {
                                if (sensor_test_debug_switch == '\0') {
                                  iVar7 = iVar7 + 1;
                                  goto LAB_004f5334;
                                }
                                printf("[SENSOR_TEST_DEBUG]%s()/%d not support WPA sec_type\n",
                                       "_sensor_test_generate_serv_list_by_scanned_bssid",0x321);
                              }
                              else {
                                iVar10 = sensor_get_default_backhaul_wserv_id();
                                if (iVar8 == iVar10) {
                                  iVar7 = iVar7 + 1;
                                  goto LAB_004f5334;
                                }
                                iVar10 = sensor_get_backhaul_wserv_id();
                                if (iVar8 == iVar10) goto LAB_004f5384;
                                _sensor_test_insert_serv_id_into_list
                                          (iVar8,local_40,&local_1318,auStack_9a4);
                              }
                            }
                            iVar7 = iVar7 + 1;
                            goto LAB_004f5334;
                          }
                          iVar8 = iVar8 + 1;
                        } while (iVar8 < iVar6);
                        iVar7 = iVar7 + 1;
                      }
                      else {
                        iVar7 = iVar7 + 1;
                      }
                    }
                    goto LAB_004f5334;
                  }
                  sensor_db_entry_free(local_129c);
                }
                local_129c[0] = '\0';
                local_129c[1] = '\0';
                local_129c[2] = '\0';
                local_129c[3] = '\0';
                local_129c[4] = '\0';
                local_129c[5] = '\0';
                local_129c[6] = '\0';
                local_129c[7] = '\0';
                local_129c[8] = '\0';
                local_129c[9] = '\0';
                local_129c[10] = '\0';
                local_129c[0xb] = '\0';
                local_1290 = 0;
                local_128c = 0;
                local_1288 = 0;
              }
              local_34 = local_34 + 1;
              local_38 = local_38 + 1;
            } while (local_34 < local_3c);
            if (local_1318 < 1) {
              if (sensor_test_err_switch != '\0') {
                pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d generate serv_list_len <= 0\n";
                uVar14 = 0x1511;
                goto LAB_004f5968;
              }
            }
            else {
              if ((-1 < iVar2) && (iVar2 <= iVar3)) {
                if (bVar1) {
                  if (local_1318 <= iVar3) {
                    iVar3 = local_1318 + -1;
                  }
                }
                else {
                  iVar2 = 0;
                  iVar3 = local_1318 + -1;
                }
                puVar17 = auStack_9a0 + iVar2 * 2;
LAB_004f5558:
                do {
                  if (iVar3 < iVar2) goto LAB_004f57cc;
                  iVar5 = json_object_new_object();
                  if (iVar5 == 0) {
                    if (sensor_warning_switch != '\0') {
                      printf("[SENSOR_WARNING]%s()/%d mem malloc sensor_item_obj fail\n",
                             "jcs_sensor_test_get_ssid_list",0x1534);
                    }
                  }
                  else {
                    memset(local_129c,0,0x100);
                    snprintf(local_129c,0x100,"%d",puVar17[-1]);
                    uVar14 = json_object_new_string(local_129c);
                    json_object_object_add(iVar5,"serv_id",uVar14);
                    memset(auStack_e04,0,0x205);
                    iVar6 = wserv_db_get_entry_by_id(puVar17[-1],auStack_e04);
                    if (iVar6 != -1) {
                      uVar14 = json_object_new_string(auStack_cd4);
                      json_object_object_add(iVar5,"ssid_name",uVar14);
                      memset(local_129c,0,0x100);
                      snprintf(local_129c,0x100,"%d",local_cd8);
                      uVar14 = json_object_new_string(local_129c);
                      json_object_object_add(iVar5,"ssid_code_type",uVar14);
                      if (sensor_test_debug_switch != '\0') {
                        printf("[SENSOR_TEST_DEBUG]%s()/%d %s\'s scanned freqband is = %d\n",
                               "jcs_sensor_test_get_ssid_list",0x1545,auStack_cd4,*puVar17);
                      }
                      memset(local_129c,0,0x100);
                      snprintf(local_129c,0x100,"%d",*puVar17);
                      uVar14 = json_object_new_string(local_129c);
                      json_object_object_add(iVar5,"freqband",uVar14);
                      if (local_c9a == 0) {
                        memset(local_129c,0,0x100);
                        uVar14 = 0;
                      }
                      else if (local_c9a == 1) {
                        memset(local_129c,0,0x100);
                        uVar14 = 1;
                      }
                      else if (local_c9a == 2) {
                        memset(local_129c,0,0x100);
                        uVar14 = 2;
                      }
                      else if (local_c9a == 3) {
                        memset(local_129c,0,0x100);
                        uVar14 = 3;
                      }
                      else if (local_c9a == 4) {
                        memset(local_129c,0,0x100);
                        uVar14 = 4;
                      }
                      else {
                        memset(local_129c,0,0x100);
                        uVar14 = 0xffffffff;
                      }
                      iVar2 = iVar2 + 1;
                      snprintf(local_129c,0x100,"%d",uVar14);
                      uVar14 = json_object_new_string(local_129c);
                      json_object_object_add(iVar5,"encryption",uVar14);
                      json_object_array_add(iVar4,iVar5);
                      puVar17 = puVar17 + 2;
                      goto LAB_004f5558;
                    }
                    if (sensor_err_switch != '\0') {
                      printf("[SENSOR_ERROR]%s()/%d wserv_db_get_entry_by_id fail id=%d\n",
                             "jcs_sensor_test_get_ssid_list",0x153b,puVar17[-1]);
                    }
                    json_object_put(iVar5);
                  }
                  iVar2 = iVar2 + 1;
                  puVar17 = puVar17 + 2;
                } while( true );
              }
              if (sensor_test_err_switch != '\0') {
                pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d start or end invalid\n";
                uVar14 = 0x151b;
LAB_004f5968:
                __s = (FILE *)0x0;
                printf(pcVar13,"jcs_sensor_test_get_ssid_list",uVar14);
                pcVar13 = (char *)0x0;
                goto LAB_004f4e08;
              }
            }
          }
          __s = (FILE *)0x0;
          pcVar13 = (char *)0x0;
          goto LAB_004f4e08;
        }
        if (sensor_test_err_switch != '\0') {
          pcVar13 = "[SENSOR_TEST_ERROR]%s()/%d input group list len <= 0\n";
          uVar14 = 0x14da;
          goto LAB_004f4f44;
        }
      }
    }
  }
  __s = (FILE *)0x0;
  pcVar13 = (char *)0x0;
  iVar4 = 0;
LAB_004f4e08:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d jcs_sensor_test_get_ssid_list fail EXIT\n",
           "jcs_sensor_test_get_ssid_list",0x1598);
  }
  if (iVar4 != 0) {
    json_object_put(iVar4);
  }
  if (pcVar13 != (char *)0x0) {
    free(pcVar13);
  }
  uVar14 = 1;
  if (__s != (FILE *)0x0) {
    fclose(__s);
    uVar14 = 1;
  }
LAB_004f4e48:
  uVar14 = json_object_new_int(uVar14);
  json_object_object_add(param_2,&DAT_00676a24,uVar14);
  return;
LAB_004f57cc:
  pcVar13 = (char *)json_object_to_json_string_ext(iVar4,0);
  pcVar13 = strdup(pcVar13);
  if (pcVar13 == (char *)0x0) {
    __s = (FILE *)0x0;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d generate ret_str failed\n","jcs_sensor_test_get_ssid_list",
             0x156e);
      __s = (FILE *)0x0;
    }
  }
  else {
    json_object_put(iVar4);
    sVar9 = strlen(pcVar13);
    l_sensor_test_write_file_counter = l_sensor_test_write_file_counter + 1;
    snprintf(acStack_1300,100,"/tmp/st_ssid_list_%d");
    __s = fopen(acStack_1300,"w+");
    if (__s == (FILE *)0x0) {
      iVar4 = 0;
      if (sensor_test_err_switch != '\0') {
        __format = "[SENSOR_TEST_ERROR]%s()/%d open result file failed.\n";
        uVar14 = 0x157d;
LAB_004f5874:
        iVar4 = 0;
        printf(__format,"jcs_sensor_test_get_ssid_list",uVar14);
      }
    }
    else {
      sVar9 = fwrite(pcVar13,(int)(short)sVar9,1,__s);
      if (sVar9 == 1) {
        free(pcVar13);
        fclose(__s);
        uVar14 = json_object_new_string(acStack_1300);
        json_object_object_add(param_2,"file_name",uVar14);
        memset(local_129c,0,0x100);
        snprintf(local_129c,0x100,"%d",local_1318);
        uVar14 = json_object_new_string(local_129c);
        json_object_object_add(param_2,"total_num",uVar14);
        uVar14 = 0;
        goto LAB_004f4e48;
      }
      iVar4 = 0;
      if (sensor_test_err_switch != '\0') {
        __format = "[SENSOR_TEST_ERROR]%s()/%d write result to file failed.\n";
        uVar14 = 0x1583;
        goto LAB_004f5874;
      }
    }
  }
  goto LAB_004f4e08;
}

