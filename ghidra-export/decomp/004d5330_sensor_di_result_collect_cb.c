// func sensor_di_result_collect_cb @ 004d5330 size=10568

/* WARNING: Removing unreachable block (ram,0x004d57a0) */
/* WARNING: Removing unreachable block (ram,0x004d5bc8) */
/* WARNING: Removing unreachable block (ram,0x004d5c34) */
/* WARNING: Removing unreachable block (ram,0x004d580c) */

undefined4 sensor_di_result_collect_cb(ushort *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  short sVar13;
  short sVar14;
  undefined2 *__s;
  undefined2 uVar15;
  int iVar8;
  void *pvVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined1 uVar16;
  short extraout_v1;
  undefined4 uVar17;
  char *pcVar18;
  uint uVar19;
  undefined4 uVar20;
  size_t __n;
  char cVar23;
  void *pvVar21;
  int iVar22;
  int iVar24;
  undefined8 uVar25;
  byte local_148;
  byte local_147 [3];
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  uint local_134;
  char local_130 [16];
  uint local_120;
  undefined2 local_11c;
  undefined1 local_11a;
  undefined4 local_118;
  undefined4 local_114;
  uint local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined2 local_104;
  undefined1 local_102;
  char acStack_100 [5];
  byte local_fb;
  undefined1 local_d0;
  int local_58;
  int local_54;
  uint *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  ushort *local_30;
  
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 0xc) == 0)) {
    uVar17 = 0xffffffff;
    if (sensor_di_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : find input data or data->param is null\n";
    pcVar18 = "sensor_di_result_collect_cb";
    uVar20 = 0x1148;
    goto LAB_004d5450;
  }
  if (sensor_di_debug_switch == 0) {
    uVar17 = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_result_collect_cb ENTER, operation_id=%d, sensor_id=%d\n"
           ,"sensor_di_result_collect_cb",0x114b,*(undefined4 *)(param_1 + 2),(uint)*param_1);
    uVar17 = *(undefined4 *)(param_1 + 0xc);
  }
  pcVar3 = (char *)json_object_to_json_string_ext(uVar17,0);
  pcVar3 = strdup(pcVar3);
  if (pcVar3 == (char *)0x0) {
    uVar17 = 0;
    if (sensor_di_err_switch == 0) {
      return 0;
    }
    pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : Malloc json_str failed\n";
    pcVar18 = "sensor_di_result_collect_cb";
    uVar20 = 0x1153;
    goto LAB_004d5450;
  }
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : RECEIVED JSON IS:%s\n","sensor_di_result_collect_cb",
           0x1156,pcVar3);
  }
  free(pcVar3);
  uVar17 = *(undefined4 *)(param_1 + 0xc);
  iVar4 = _sensor_di_get_cur_status();
  if (iVar4 == 0) {
    uVar17 = 0;
    if (sensor_di_debug_switch == 0) {
      return 0;
    }
    pcVar3 = "[SENSOR_DI_DEBUG]%s()/line %d : cur_status is off, result_collect exit\n";
    pcVar18 = "sensor_di_result_collect_cb";
    uVar20 = 0x1161;
    goto LAB_004d5450;
  }
  if (*(int *)(param_1 + 2) != 1) {
    uVar17 = 0;
    if (sensor_di_debug_switch == 0) {
      return 0;
    }
    pcVar3 = "[SENSOR_DI_DEBUG]%s()/line %d : operation_id not match, stop result collect\n";
    pcVar18 = "sensor_di_result_collect_cb";
    uVar20 = 0x1167;
    goto LAB_004d5450;
  }
  iVar4 = json_object_object_get(uVar17,&DAT_006aa504);
  if (iVar4 == 0) {
LAB_004d5528:
    iVar4 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "sensor_di_result_collect_cb",0x116c);
    }
  }
  else {
    iVar5 = json_object_get_type(iVar4);
    if (iVar5 == 3) {
      iVar4 = json_object_get_int(iVar4);
    }
    else {
      iVar5 = json_object_get_type();
      if (iVar5 != 2) goto LAB_004d5528;
      uVar25 = json_object_get_double(iVar4);
      iVar4 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
    }
  }
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : item is=%d\n","sensor_di_result_collect_cb",0x116d,iVar4
          );
  }
  if (iVar4 != 1) {
    if (iVar4 == 4) {
      iVar4 = sensor_di_db_is_sensor_exists_in_cached_list(*param_1);
      if (iVar4 == 0) {
        uVar17 = 0;
        if (sensor_di_debug_switch == 0) {
          return 0;
        }
        pcVar3 = "[SENSOR_DI_DEBUG]%s()/line %d : sensor not exists in cached list, abandon data\n";
        pcVar18 = "sensor_di_result_collect_cb";
        uVar20 = 0x1179;
        goto LAB_004d5450;
      }
      if (sensor_di_debug_switch == 0) {
        iVar4 = *(int *)(param_1 + 0xc);
      }
      else {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_collect_chnls_scan_data ENTER,sensor_id=%d\n"
               ,"_sensor_di_collect_chnls_scan_data",0x5d6,(uint)*param_1);
        iVar4 = *(int *)(param_1 + 0xc);
      }
      if (iVar4 == 0) {
        puVar7 = (uint *)0x0;
        puVar6 = puVar7;
        if (sensor_di_err_switch == 0) goto LAB_004d5ec8;
        pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : data->param is null\n";
        uVar17 = 0x5e4;
      }
      else {
        FUN_0051ad88(&local_118);
        local_58 = json_object_object_get(iVar4,"data");
        if (((local_58 == 0) || (iVar4 = json_object_get_type(local_58), iVar4 != 5)) ||
           ((iVar4 = json_object_array_length(local_58), iVar4 < 1 ||
            (iVar4 = json_object_array_length(local_58), iVar4 < 1)))) {
          puVar7 = (uint *)0x0;
          puVar6 = puVar7;
          if (sensor_di_err_switch == 0) goto LAB_004d5ec8;
          pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : get data fail\n";
          uVar17 = 0x5ec;
        }
        else {
          local_40 = json_object_array_length(local_58);
          __n = local_40 * 10;
          puVar7 = (uint *)FUN_00408450(__n,0x5f1);
          if (puVar7 == (uint *)0x0) {
            puVar6 = puVar7;
            if (sensor_di_err_switch == 0) goto LAB_004d5ec8;
            pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
            uVar17 = 0x5f4;
          }
          else {
            memset(puVar7,0,__n);
            local_50 = puVar7;
            local_30 = param_1;
            for (local_4c = 0; puVar2 = local_30, puVar6 = local_50, local_4c < local_40;
                local_4c = local_4c + 1) {
              uVar17 = json_object_array_get_idx(local_58,local_4c);
              iVar4 = json_object_object_get(uVar17,"channel");
              if (iVar4 == 0) {
LAB_004d5b50:
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_di_collect_chnls_scan_data",0x5fe);
                }
                uVar16 = 0xff;
              }
              else {
                iVar5 = json_object_get_type(iVar4);
                if (iVar5 == 3) {
                  uVar16 = json_object_get_int(iVar4);
                }
                else {
                  iVar5 = json_object_get_type();
                  if (iVar5 != 2) goto LAB_004d5b50;
                  uVar25 = json_object_get_double(iVar4);
                  uVar16 = __fixunsdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                }
              }
              *(undefined1 *)puVar7 = uVar16;
              iVar4 = json_object_object_get(uVar17,"wifiUtil");
              if (iVar4 == 0) {
LAB_004d5ba4:
                iVar4 = -1;
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_di_collect_chnls_scan_data",0x601);
                }
              }
              else {
                iVar5 = json_object_get_type(iVar4);
                if (iVar5 == 3) {
                  iVar4 = json_object_get_int(iVar4);
                }
                else {
                  iVar5 = json_object_get_type();
                  if (iVar5 != 2) goto LAB_004d5ba4;
                  uVar25 = json_object_get_double(iVar4);
                  iVar4 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                }
              }
              *(char *)((int)puVar7 + 1) = (char)((iVar4 * 100) / 10000);
              iVar4 = json_object_object_get(uVar17,"nonWifiUtil");
              if (iVar4 == 0) {
LAB_004d5c0c:
                iVar4 = -1;
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_di_collect_chnls_scan_data",0x605);
                }
              }
              else {
                iVar5 = json_object_get_type(iVar4);
                if (iVar5 == 3) {
                  iVar4 = json_object_get_int(iVar4);
                }
                else {
                  iVar5 = json_object_get_type();
                  if (iVar5 != 2) goto LAB_004d5c0c;
                  uVar25 = json_object_get_double(iVar4);
                  iVar4 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                }
              }
              cVar23 = (char)((iVar4 * 100) / 10000);
              *(char *)((int)puVar7 + 2) = cVar23;
              *(char *)((int)puVar7 + 3) = ('d' - *(char *)((int)puVar7 + 1)) - cVar23;
              local_54 = json_object_object_get(uVar17,"ssidInfo");
              if (local_54 == 0) {
                if (sensor_di_warning_switch != 0) {
                  printf("[SENSOR_DI_WARNING]%s()/line %d : ssidInfo is null\n",
                         "_sensor_di_collect_chnls_scan_data",0x60d);
                }
              }
              else {
                if (sensor_di_debug_switch != 0) {
                  printf("[SENSOR_DI_DEBUG]%s()/line %d : chnls_scan_data_parse_ssidinfo ENTER\n",
                         "_sensor_di_collect_chnls_scan_data_parse_ssidinfo",0x57e);
                }
                memset(acStack_100,0,0x31);
                iVar4 = json_object_get_type(local_54);
                if ((iVar4 != 5) &&
                   ((iVar4 = json_object_get_type(local_54), iVar4 != 4 ||
                    (iVar4 = json_object_object_length(local_54), iVar4 != 0)))) {
                  iVar4 = 0;
                  puVar6 = local_50;
                  if (sensor_di_err_switch != 0) {
                    pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : get ssid_info_obj fail\n";
                    uVar17 = 0x587;
LAB_004d667c:
                    printf(pcVar3,"_sensor_di_collect_chnls_scan_data_parse_ssidinfo",uVar17);
                  }
LAB_004d5ea8:
                  if (sensor_di_err_switch != 0) {
                    printf("[SENSOR_DI_ERROR]%s()/line %d : chnls_scan_data_parse_ssidinfo fail EXIT\n"
                           ,"_sensor_di_collect_chnls_scan_data_parse_ssidinfo",0x5cf);
                  }
                  _sensor_di_ssidinfo_node_free(iVar4);
                  if (sensor_di_err_switch == 0) goto LAB_004d5ec8;
                  pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : parse_ssidinfo fail\n";
                  uVar17 = 0x613;
                  puVar7 = puVar6;
                  goto LAB_004d7370;
                }
                *(undefined2 *)(puVar7 + 1) = 0;
                *(undefined2 *)(puVar7 + 2) = 0;
                sVar13 = json_object_array_length(local_54);
                local_48 = 0;
                *(short *)((int)puVar7 + 6) = sVar13;
                if (sVar13 != 0) {
                  for (; local_48 < (int)(uint)*(ushort *)((int)puVar7 + 6); local_48 = local_48 + 1
                      ) {
                    cVar23 = '\x01';
                    uVar17 = json_object_array_get_idx(local_54,local_48);
                    iVar4 = json_object_object_get(uVar17,"ssid");
                    if ((iVar4 != 0) && (iVar5 = json_object_get_type(iVar4), iVar5 != 0)) {
                      iVar5 = json_object_get_type(iVar4);
                      if (iVar5 == 6) {
                        pcVar3 = (char *)json_object_get_string(iVar4);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                 ,"_sensor_di_collect_chnls_scan_data_parse_ssidinfo",0x5a1);
                        }
                        pcVar3 = "";
                      }
                      cVar23 = '\0';
                      strncpy(acStack_100,pcVar3,0x30);
                      local_d0 = 0;
                      iVar4 = FUN_00407e60(acStack_100);
                      if (iVar4 == 0) {
                        FUN_00408710(acStack_100,0x31);
                      }
                    }
                    for (iVar4 = FUN_004081b0(&local_118); iVar4 != 0; iVar4 = FUN_00408680(iVar4))
                    {
                      if ((*(char *)(iVar4 + 0x49) == cVar23) &&
                         ((cVar23 != '\0' ||
                          (iVar5 = strcmp(acStack_100,(char *)(iVar4 + 0x18)), iVar5 == 0))))
                      goto LAB_004d5df4;
                    }
                    iVar4 = FUN_00408450(0x4c,0x5ad);
                    if (iVar4 == 0) {
                      puVar6 = local_50;
                      if (sensor_di_err_switch == 0) goto LAB_004d5ea8;
                      pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                      uVar17 = 0x5b0;
                      goto LAB_004d667c;
                    }
                    FUN_004086b0(&local_118,iVar4);
                    FUN_0051ad88(iVar4 + 0xc);
                    memcpy((void *)(iVar4 + 0x18),acStack_100,0x31);
                    *(char *)(iVar4 + 0x49) = cVar23;
LAB_004d5df4:
                    iVar5 = json_object_object_get(uVar17,"bssidInfo");
                    if (iVar5 == 0) {
                      if (sensor_di_warning_switch != 0) {
                        printf("[SENSOR_DI_WARNING]%s()/line %d : bssidInfo is null\n",
                               "_sensor_di_collect_chnls_scan_data_parse_ssidinfo",0x5bc);
                      }
                    }
                    else {
                      local_34 = iVar4 + 0xc;
                      local_130[0] = '\0';
                      local_130[1] = '\0';
                      local_130[2] = '\0';
                      local_130[3] = '\0';
                      local_130[4] = '\0';
                      local_130[5] = '\0';
                      local_130[6] = '\0';
                      local_130[7] = '\0';
                      local_130[8] = '\0';
                      local_130[9] = '\0';
                      local_130[10] = '\0';
                      local_130[0xb] = '\0';
                      local_130[0xc] = '\0';
                      local_130[0xd] = '\0';
                      local_130[0xe] = '\0';
                      local_130[0xf] = '\0';
                      local_120 = 0;
                      iVar8 = json_object_get_type(iVar5);
                      if ((iVar8 != 5) &&
                         ((iVar8 = json_object_get_type(iVar5), iVar8 != 4 ||
                          (iVar8 = json_object_object_length(iVar5), iVar8 != 0)))) {
                        pvVar21 = (void *)0x0;
                        puVar6 = local_50;
                        if (sensor_di_err_switch != 0) {
                          pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : get bssid_info_obj fail\n";
                          uVar17 = 0x534;
LAB_004d5fcc:
                          printf(pcVar3,"_sensor_di_collect_chnls_scan_data_parse_bssidinfo",uVar17)
                          ;
                        }
LAB_004d5e64:
                        if (sensor_di_err_switch != 0) {
                          printf("[SENSOR_DI_ERROR]%s()/line %d : chnls_scan_data_parse_bssidinfo fail EXIT\n"
                                 ,"_sensor_di_collect_chnls_scan_data_parse_bssidinfo",0x576);
                        }
                        if (pvVar21 != (void *)0x0) {
                          if (*(int *)((int)pvVar21 + 0x24) != 0) {
                            FUN_00407df0();
                            *(undefined4 *)((int)pvVar21 + 0x24) = 0;
                          }
                          FUN_00407df0(pvVar21);
                        }
                        if (sensor_di_err_switch == 0) goto LAB_004d5ea8;
                        pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : parse bssidinfo fail\n";
                        uVar17 = 0x5c2;
                        goto LAB_004d667c;
                      }
                      local_3c = json_object_array_length(iVar5);
                      if (local_3c != 0) {
                        local_44 = 0;
                        *(short *)(puVar7 + 1) = (short)local_3c + *(short *)(puVar7 + 1);
                        local_38 = iVar4;
                        for (; local_44 < local_3c; local_44 = local_44 + 1) {
                          pvVar21 = (void *)FUN_00408450(0x28,0x543);
                          if (pvVar21 == (void *)0x0) {
                            iVar4 = local_38;
                            puVar6 = local_50;
                            if (sensor_di_err_switch == 0) goto LAB_004d5e64;
                            pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                            uVar17 = 0x546;
                            goto LAB_004d5fcc;
                          }
                          memset(pvVar21,0,0x28);
                          uVar17 = json_object_array_get_idx(iVar5,local_44);
                          iVar4 = json_object_object_get(uVar17,"bssid");
                          if ((iVar4 == 0) || (iVar8 = json_object_get_type(iVar4), iVar8 != 6)) {
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                     ,"_sensor_di_collect_chnls_scan_data_parse_bssidinfo",0x54e);
                            }
                            pcVar3 = "";
                          }
                          else {
                            pcVar3 = (char *)json_object_get_string(iVar4);
                          }
                          strncpy(local_130,pcVar3,0x13);
                          local_120 = local_120 & 0xffffff00;
                          _str2mac(local_130,(int)pvVar21 + 0x1c);
                          iVar4 = json_object_object_get(uVar17,"rssi");
                          if (iVar4 == 0) {
LAB_004d60fc:
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                     ,"_sensor_di_collect_chnls_scan_data_parse_bssidinfo",0x552);
                            }
                            uVar15 = 0xffff;
                          }
                          else {
                            iVar8 = json_object_get_type(iVar4);
                            if (iVar8 == 3) {
                              uVar15 = json_object_get_int(iVar4);
                            }
                            else {
                              iVar8 = json_object_get_type();
                              if (iVar8 != 2) goto LAB_004d60fc;
                              uVar25 = json_object_get_double(iVar4);
                              uVar15 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                            }
                          }
                          *(undefined2 *)((int)pvVar21 + 0x10) = uVar15;
                          iVar4 = json_object_object_get(uVar17,"bandwidth");
                          if (iVar4 == 0) {
LAB_004d6150:
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                     ,"_sensor_di_collect_chnls_scan_data_parse_bssidinfo",0x555);
                            }
                            uVar15 = 0xffff;
                          }
                          else {
                            iVar8 = json_object_get_type(iVar4);
                            if (iVar8 == 3) {
                              uVar15 = json_object_get_int(iVar4);
                            }
                            else {
                              iVar8 = json_object_get_type();
                              if (iVar8 != 2) goto LAB_004d6150;
                              uVar25 = json_object_get_double(iVar4);
                              uVar15 = __fixunsdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                            }
                          }
                          *(undefined2 *)((int)pvVar21 + 0x18) = uVar15;
                          iVar4 = json_object_object_get(uVar17,"primaryCh");
                          if (iVar4 == 0) {
LAB_004d61a4:
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                     ,"_sensor_di_collect_chnls_scan_data_parse_bssidinfo",0x558);
                            }
                            uVar15 = 0xffff;
                          }
                          else {
                            iVar8 = json_object_get_type(iVar4);
                            if (iVar8 == 3) {
                              uVar15 = json_object_get_int(iVar4);
                            }
                            else {
                              iVar8 = json_object_get_type();
                              if (iVar8 != 2) goto LAB_004d61a4;
                              uVar25 = json_object_get_double(iVar4);
                              uVar15 = __fixunsdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                            }
                          }
                          *(undefined2 *)((int)pvVar21 + 0x12) = uVar15;
                          iVar4 = json_object_object_get(uVar17,"centerCh");
                          if (iVar4 == 0) {
LAB_004d61f8:
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                     ,"_sensor_di_collect_chnls_scan_data_parse_bssidinfo",0x55b);
                            }
                            uVar15 = 0xffff;
                          }
                          else {
                            iVar8 = json_object_get_type(iVar4);
                            if (iVar8 == 3) {
                              uVar15 = json_object_get_int(iVar4);
                            }
                            else {
                              iVar8 = json_object_get_type();
                              if (iVar8 != 2) goto LAB_004d61f8;
                              uVar25 = json_object_get_double(iVar4);
                              uVar15 = __fixunsdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                            }
                          }
                          *(undefined2 *)((int)pvVar21 + 0x14) = uVar15;
                          iVar4 = json_object_object_get(uVar17,"sec80Ch");
                          if (iVar4 == 0) {
LAB_004d624c:
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                     ,"_sensor_di_collect_chnls_scan_data_parse_bssidinfo",0x55e);
                            }
                            uVar15 = 0xffff;
                          }
                          else {
                            iVar8 = json_object_get_type(iVar4);
                            if (iVar8 == 3) {
                              uVar15 = json_object_get_int(iVar4);
                            }
                            else {
                              iVar8 = json_object_get_type();
                              if (iVar8 != 2) goto LAB_004d624c;
                              uVar25 = json_object_get_double(iVar4);
                              uVar15 = __fixunsdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                            }
                          }
                          *(undefined2 *)((int)pvVar21 + 0x16) = uVar15;
                          iVar8 = json_object_object_get(uVar17,"staInfo");
                          if (iVar8 == 0) {
                            *(undefined2 *)((int)pvVar21 + 0x1a) = 0;
                            *(undefined4 *)((int)pvVar21 + 0x24) = 0;
                          }
                          else {
                            local_144 = 0;
                            local_140 = 0;
                            local_13c = 0;
                            local_138 = 0;
                            local_134 = 0;
                            iVar4 = json_object_get_type(iVar8);
                            if ((iVar4 == 5) ||
                               ((iVar4 = json_object_get_type(iVar8), iVar4 == 4 &&
                                (iVar4 = json_object_object_length(iVar8), iVar4 == 0)))) {
                              uVar11 = json_object_array_length(iVar8);
                              if (uVar11 != 0) {
                                *(short *)((int)pvVar21 + 0x1a) = (short)uVar11;
                                iVar24 = FUN_00408450((uVar11 & 0xffff) * 6,0x510);
                                iVar4 = local_38;
                                puVar6 = local_50;
                                *(int *)((int)pvVar21 + 0x24) = iVar24;
                                if (iVar24 == 0) {
                                  if (sensor_di_err_switch != 0) {
                                    printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n",
                                           "_sensor_di_collect_chnls_scan_data_parase_stainfo",0x513
                                          );
                                  }
                                  if (sensor_di_err_switch == 0) {
                                    iVar5 = *(int *)((int)pvVar21 + 0x24);
                                  }
                                  else {
                                    printf("[SENSOR_DI_ERROR]%s()/line %d : chnls_scan_data_parase_staInfo fail EXIT\n"
                                           ,"_sensor_di_collect_chnls_scan_data_parase_stainfo",
                                           0x521);
                                    iVar5 = *(int *)((int)pvVar21 + 0x24);
                                  }
                                  if (iVar5 != 0) {
                                    FUN_00407df0();
                                    *(undefined4 *)((int)pvVar21 + 0x24) = 0;
                                  }
                                  if (sensor_di_err_switch == 0) goto LAB_004d5e64;
                                  pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : parase_staInfo fail\n";
                                  uVar17 = 0x56a;
                                  goto LAB_004d5fcc;
                                }
                                *(short *)(puVar7 + 2) = (short)uVar11 + *(short *)(puVar7 + 2);
                                for (iVar4 = 0; iVar4 < (int)uVar11; iVar4 = iVar4 + 1) {
                                  iVar24 = json_object_array_get_idx(iVar8,iVar4);
                                  if ((iVar24 == 0) ||
                                     (iVar12 = json_object_get_type(iVar24), iVar12 != 6)) {
                                    if (jcs_err_switch != 0) {
                                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                             ,"_sensor_di_collect_chnls_scan_data_parase_stainfo",
                                             0x51a);
                                    }
                                    pcVar3 = "";
                                  }
                                  else {
                                    pcVar3 = (char *)json_object_get_string(iVar24);
                                  }
                                  strncpy((char *)&local_144,pcVar3,0x13);
                                  local_134 = local_134 & 0xffffff00;
                                  _str2mac(&local_144,*(int *)((int)pvVar21 + 0x24) + iVar4 * 6);
                                }
                              }
                            }
                            else {
                              if (sensor_di_debug_switch != 0) {
                                printf("[SENSOR_DI_DEBUG]%s()/line %d : sta_info_obj is null\n",
                                       "_sensor_di_collect_chnls_scan_data_parase_stainfo",0x4ff);
                              }
                              iVar4 = sensor_di_debug_switch;
                              *(undefined2 *)((int)pvVar21 + 0x1a) = 0;
                              *(undefined4 *)((int)pvVar21 + 0x24) = 0;
                              if (iVar4 != 0) {
                                printf("[SENSOR_DI_DEBUG]%s()/line %d : chnls_scan_data_parase_staInfo success EXIT\n"
                                       ,"_sensor_di_collect_chnls_scan_data_parase_stainfo",0x502);
                              }
                            }
                          }
                          FUN_004086b0(local_34,pvVar21);
                        }
                      }
                    }
                  }
                }
              }
              puVar7 = (uint *)((int)puVar7 + 10);
            }
            iVar4 = sensor_di_db_set_ssid_chnl_info(*local_30,&local_118);
            puVar7 = puVar6;
            if (iVar4 == -1) {
              if (sensor_di_err_switch == 0) goto LAB_004d5ec8;
              pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : set ssid_chnl_info fail\n";
              uVar17 = 0x61c;
            }
            else {
              iVar4 = sensor_di_db_set_chnls_util_info(*puVar2,local_40,puVar6);
              if (iVar4 != -1) {
                FUN_00407df0(puVar6);
                uVar17 = 0;
                _sensor_di_ssidinfo_list_free(&local_118);
                if (sensor_di_debug_switch == 0) {
                  return 0;
                }
                pcVar3 = 
                "[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_collect_chnls_scan_data success EXIT\n";
                pcVar18 = "_sensor_di_collect_chnls_scan_data";
                uVar20 = 0x62d;
                goto LAB_004d5450;
              }
              if (sensor_di_err_switch == 0) goto LAB_004d5ec8;
              pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : set_chnls_util_info fail\n";
              uVar17 = 0x621;
            }
          }
        }
      }
LAB_004d7370:
      printf(pcVar3,"_sensor_di_collect_chnls_scan_data",uVar17);
      puVar6 = puVar7;
LAB_004d5ec8:
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : _sensor_di_collect_chnls_scan_data fail EXIT\n",
               "_sensor_di_collect_chnls_scan_data",0x631);
      }
      if (puVar6 != (uint *)0x0) {
        FUN_00407df0(puVar6);
      }
      _sensor_di_ssidinfo_list_free(&local_118);
      return 0xffffffff;
    }
    if (iVar4 != 2) {
      uVar17 = 0xffffffff;
      if (sensor_di_err_switch == 0) {
        return 0xffffffff;
      }
      pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : item not match\n";
      pcVar18 = "sensor_di_result_collect_cb";
      uVar20 = 0x1189;
      goto LAB_004d5450;
    }
    iVar4 = sensor_di_db_is_sensor_exists_in_cached_list(*param_1);
    if (iVar4 == 0) {
      uVar17 = 0;
      if (sensor_di_debug_switch == 0) {
        return 0;
      }
      pcVar3 = "[SENSOR_DI_DEBUG]%s()/line %d : sensor not exists in cached list, abandon data\n";
      pcVar18 = "sensor_di_result_collect_cb";
      uVar20 = 0x1182;
      goto LAB_004d5450;
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_collect_freq_analy_data ENTER,sensor_id=%d\n"
             ,"_sensor_di_collect_freq_analy_data",0x63f,(uint)*param_1);
    }
    memset(acStack_100,0,0xa4);
    iVar4 = *(int *)(param_1 + 0xc);
    if (iVar4 == 0) {
      __s = (undefined2 *)0x0;
      if (sensor_di_err_switch == 0) goto LAB_004d689c;
      pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : data->param is null\n";
      uVar17 = 0x64d;
    }
    else {
      sVar13 = _sensor_di_get_cur_running_time();
      sVar14 = _sensor_di_get_freq_analy_data_last_refresh_time();
      if (sensor_di_debug_switch != 0) {
        uVar17 = _sensor_di_get_cur_running_time();
        uVar20 = _sensor_di_get_freq_analy_data_last_refresh_time();
        printf("[SENSOR_DI_DEBUG]%s()/line %d : freq_analy_data current_time=%d, last_refresh_time=%d\n"
               ,"_sensor_di_collect_freq_analy_data",0x653,uVar17,uVar20);
      }
      if ((short)(sVar13 - sVar14) < 2) {
        uVar17 = 0;
        if (sensor_di_debug_switch == 0) {
          return 0;
        }
        pcVar3 = 
        "[SENSOR_DI_DEBUG]%s()/line %d : time_interval not satisfied, do not refresh freq_analy_data\n"
        ;
        pcVar18 = "_sensor_di_collect_freq_analy_data";
        uVar20 = 0x656;
        goto LAB_004d5450;
      }
      uVar17 = _sensor_di_get_cur_running_time();
      _sensor_di_set_freq_analy_data_last_refresh_time(uVar17);
      __s = (undefined2 *)FUN_00408450(0x188,0x65c);
      if (__s == (undefined2 *)0x0) {
        if (sensor_di_err_switch == 0) goto LAB_004d689c;
        pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
        uVar17 = 0x65f;
      }
      else {
        memset(__s,0,0x188);
        uVar15 = _sensor_di_get_cur_running_time();
        *__s = uVar15;
        iVar5 = json_object_object_get(iVar4,"start");
        if (iVar5 == 0) {
LAB_004d67e8:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_di_collect_freq_analy_data",0x668);
          }
          uVar15 = 0xffff;
        }
        else {
          iVar8 = json_object_get_type(iVar5);
          if (iVar8 == 3) {
            uVar15 = json_object_get_int(iVar5);
          }
          else {
            iVar8 = json_object_get_type();
            if (iVar8 != 2) goto LAB_004d67e8;
            uVar25 = json_object_get_double(iVar5);
            uVar15 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
          }
        }
        __s[1] = uVar15;
        iVar5 = json_object_object_get(iVar4,"end");
        if (iVar5 == 0) {
LAB_004d6840:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_di_collect_freq_analy_data",0x66b);
          }
          uVar15 = 0xffff;
        }
        else {
          iVar8 = json_object_get_type(iVar5);
          if (iVar8 == 3) {
            uVar15 = json_object_get_int(iVar5);
          }
          else {
            iVar8 = json_object_get_type();
            if (iVar8 != 2) goto LAB_004d6840;
            uVar25 = json_object_get_double(iVar5);
            uVar15 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
          }
        }
        __s[2] = uVar15;
        iVar4 = json_object_object_get(iVar4,"data");
        if ((((iVar4 != 0) && (iVar5 = json_object_get_type(iVar4), iVar5 == 5)) &&
            (iVar5 = json_object_array_length(iVar4), 0 < iVar5)) &&
           (iVar5 = json_object_array_length(iVar4), 0 < iVar5)) {
          uVar15 = json_object_array_length(iVar4);
          __s[3] = uVar15;
          iVar5 = sensor_di_db_get_specified_di_setting(*param_1,acStack_100);
          if (iVar5 != -1) {
            uVar11 = (uint)local_fb;
            iVar5 = 4;
            if (((uVar11 != 2) && (uVar11 != 3)) &&
               ((iVar5 = 2, uVar11 != 4 && ((iVar5 = 4, uVar11 != 5 && (uVar11 == 1)))))) {
              iVar5 = 2;
            }
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : step=%d, band_type=%d\n",
                     "_sensor_di_collect_freq_analy_data",0x696,iVar5,uVar11);
            }
            iVar24 = 0;
            iVar8 = 0;
LAB_004d78d4:
            do {
              if (((short)__s[3] <= iVar24) || (iVar8 == 0x180)) goto LAB_004d79c8;
              iVar12 = json_object_array_get_idx(iVar4,iVar24);
              if (iVar12 != 0) {
                uVar17 = json_object_array_get_idx(iVar4,iVar24);
                iVar12 = json_object_get_type(uVar17);
                if (iVar12 == 3) {
                  uVar17 = json_object_array_get_idx(iVar4,iVar24);
                  iVar24 = iVar24 + iVar5;
                  uVar16 = json_object_get_int(uVar17);
                  *(undefined1 *)((int)__s + iVar8 + 8) = uVar16;
                  iVar8 = iVar8 + 1;
                  goto LAB_004d78d4;
                }
              }
              iVar12 = json_object_array_get_idx(iVar4,iVar24);
              if (iVar12 == 0) {
LAB_004d7950:
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_di_collect_freq_analy_data",0x6a0);
                }
                *(undefined1 *)((int)__s + iVar8 + 8) = 0xff;
                iVar24 = iVar24 + iVar5;
                iVar8 = iVar8 + 1;
              }
              else {
                uVar17 = json_object_array_get_idx(iVar4,iVar24);
                iVar12 = json_object_get_type(uVar17);
                if (iVar12 != 2) goto LAB_004d7950;
                uVar17 = json_object_array_get_idx(iVar4,iVar24);
                uVar25 = json_object_get_double(uVar17);
                uVar16 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                *(undefined1 *)((int)__s + iVar8 + 8) = uVar16;
                iVar24 = iVar24 + iVar5;
                iVar8 = iVar8 + 1;
              }
            } while( true );
          }
          if (sensor_di_err_switch != 0) {
            printf("[SENSOR_DI_ERROR]%s()/line %d : get specified_di_setting fail,sensor_id=%d\n",
                   "_sensor_di_collect_freq_analy_data",0x67a,(uint)*param_1);
          }
          goto LAB_004d689c;
        }
        if (sensor_di_err_switch == 0) goto LAB_004d689c;
        pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : get data fail\n";
        uVar17 = 0x671;
      }
    }
LAB_004d73c0:
    printf(pcVar3,"_sensor_di_collect_freq_analy_data",uVar17);
LAB_004d689c:
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : _sensor_di_collect_freq_analy_data fail EXIT\n",
             "_sensor_di_collect_freq_analy_data",0x6bb);
    }
    if (__s == (undefined2 *)0x0) {
      return 0xffffffff;
    }
    FUN_00407df0(__s);
    return 0xffffffff;
  }
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_collect_pkt_stat_data ENTER,sensor_id=%d\n",
           "_sensor_di_collect_pkt_stat_data",0x458,(uint)*param_1);
  }
  local_147[0] = 0;
  local_148 = 0;
  local_144 = 0;
  iVar4 = json_object_object_get(*(undefined4 *)(param_1 + 0xc),"data");
  if (((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 5)) ||
     (iVar5 = json_object_array_length(iVar4), iVar5 < 1)) {
    puVar6 = (uint *)0x0;
    if (sensor_di_err_switch == 0) goto LAB_004d66e0;
    pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : data is empty\n";
    uVar17 = 0x46a;
  }
  else {
    uVar17 = json_object_array_get_idx(iVar4,0);
    puVar6 = (uint *)FUN_00408450(0x18,0x470);
    if (puVar6 == (uint *)0x0) {
      if (sensor_di_err_switch == 0) goto LAB_004d66e0;
      pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
      uVar17 = 0x473;
    }
    else {
      memset(puVar6,0,0x18);
      *puVar6 = (uint)*param_1;
      iVar4 = json_object_object_get(uVar17,"channel");
      if (iVar4 == 0) {
LAB_004d570c:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_sensor_di_collect_pkt_stat_data",0x47f);
        }
        uVar15 = 0xffff;
LAB_004d5724:
        *(undefined2 *)(puVar6 + 1) = uVar15;
      }
      else {
        iVar5 = json_object_get_type(iVar4);
        if (iVar5 != 3) {
          iVar5 = json_object_get_type();
          if (iVar5 != 2) goto LAB_004d570c;
          uVar25 = json_object_get_double(iVar4);
          uVar15 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
          goto LAB_004d5724;
        }
        uVar15 = json_object_get_int(iVar4);
        *(undefined2 *)(puVar6 + 1) = uVar15;
      }
      uVar20 = json_object_object_get(uVar17,"classInfo");
      iVar4 = json_object_object_get(uVar20,"wifiUtil");
      if (iVar4 == 0) {
LAB_004d5778:
        iVar4 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_sensor_di_collect_pkt_stat_data",0x484);
        }
      }
      else {
        iVar5 = json_object_get_type(iVar4);
        if (iVar5 == 3) {
          iVar4 = json_object_get_int(iVar4);
        }
        else {
          iVar5 = json_object_get_type();
          if (iVar5 != 2) goto LAB_004d5778;
          uVar25 = json_object_get_double(iVar4);
          iVar4 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
        }
      }
      local_144._2_2_ = CONCAT11((char)((iVar4 * 100) / 10000),(char)local_144);
      iVar4 = json_object_object_get(uVar20,"nonWifiUtil");
      if (iVar4 == 0) {
LAB_004d57e4:
        iVar4 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_sensor_di_collect_pkt_stat_data",0x488);
        }
      }
      else {
        iVar5 = json_object_get_type(iVar4);
        if (iVar5 == 3) {
          iVar4 = json_object_get_int(iVar4);
        }
        else {
          iVar5 = json_object_get_type();
          if (iVar5 != 2) goto LAB_004d57e4;
          uVar25 = json_object_get_double(iVar4);
          iVar4 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
        }
      }
      local_144 = CONCAT31(local_144._0_3_,(char)((iVar4 * 100) / 10000));
      iVar4 = json_object_object_get(uVar20,"scanTime");
      if (iVar4 == 0) {
        puVar6[4] = 0;
      }
      else {
        iVar5 = json_object_get_type(iVar4);
        if (iVar5 == 3) {
          uVar11 = json_object_get_int(iVar4);
          puVar6[4] = uVar11;
        }
        else {
          iVar5 = json_object_get_type();
          if (iVar5 == 2) {
            uVar25 = json_object_get_double(iVar4);
            uVar11 = __fixdfsi((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
            puVar6[4] = uVar11;
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_sensor_di_collect_pkt_stat_data",0x492);
            }
            puVar6[4] = 0xffffffff;
          }
        }
      }
      __divdi3(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 10),0,1000);
      local_144 = CONCAT22(extraout_v1 - (short)l_sensor_di_start_utc_timestamp,local_144._2_2_);
      iVar4 = sensor_di_db_get_scan_mode(*param_1,local_147,&local_148);
      if (iVar4 == -1) {
        if (sensor_di_err_switch == 0) goto LAB_004d66e0;
        pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : sensor_di_db_get_scan_mode fail\n";
        uVar17 = 0x49c;
      }
      else {
        iVar4 = sensor_di_db_set_chnl_util_time(*param_1,(int)*(short *)(puVar6 + 1),local_144);
        if (iVar4 != -1) {
          uVar11 = (uint)local_147[0];
          if (uVar11 == 1) {
            uVar11 = (uint)local_148;
            if (uVar11 == (int)*(short *)(puVar6 + 1)) {
              local_54 = json_object_object_get(uVar17,"pktData");
              if (local_54 == 0) {
                if (sensor_di_warning_switch != 0) {
                  pcVar3 = "[SENSOR_DI_WARNING]%s()/line %d : data\'s pkData is null\n";
                  pcVar18 = "_sensor_di_collect_pkt_stat_data";
                  uVar17 = 0x4b9;
                  goto LAB_004d6a54;
                }
              }
              else {
                iVar4 = json_object_array_length(local_54);
                if (sensor_di_debug_switch != 0) {
                  printf("[SENSOR_DI_DEBUG]%s()/line %d : ssid_cnt=%d\n",
                         "_sensor_di_collect_pkt_stat_data",0x4be,iVar4);
                }
                if (iVar4 != 0) {
                  if (sensor_di_debug_switch != 0) {
                    printf("[SENSOR_DI_DEBUG]%s()/line %d : parse_ssidpkt ENTER\n",
                           "_sensor_di_collect_pkt_stat_data_parse_ssidpkt",0x3fd);
                  }
                  memset(acStack_100,0,0x31);
                  local_4c = json_object_array_length(local_54);
                  if (local_4c < 1) {
                    if (sensor_di_debug_switch != 0) {
                      pcVar3 = 
                      "[SENSOR_DI_DEBUG]%s()/line %d : ssid_cnt <= 0 parse_ssidpkt success EXIT\n";
                      pcVar18 = "_sensor_di_collect_pkt_stat_data_parse_ssidpkt";
                      uVar17 = 0x40f;
LAB_004d6a54:
                      printf(pcVar3,pcVar18,uVar17);
                    }
                  }
                  else {
                    *(short *)((int)puVar6 + 6) = (short)local_4c;
                    pvVar21 = (void *)FUN_00408450((short)local_4c * 0x44,0x415);
                    puVar6[5] = (uint)pvVar21;
                    if (pvVar21 == (void *)0x0) {
                      if (sensor_di_err_switch != 0) {
                        pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                        uVar17 = 0x418;
LAB_004d7bcc:
                        printf(pcVar3,"_sensor_di_collect_pkt_stat_data_parse_ssidpkt",uVar17);
                      }
LAB_004d752c:
                      if (sensor_di_err_switch == 0) {
                        uVar11 = puVar6[5];
                      }
                      else {
                        printf("[SENSOR_DI_ERROR]%s()/line %d : parse_ssidpkt fail EXIT\n",
                               "_sensor_di_collect_pkt_stat_data_parse_ssidpkt",0x44d);
                        uVar11 = puVar6[5];
                      }
                      if (uVar11 != 0) {
                        FUN_00407df0();
                        puVar6[5] = 0;
                      }
                      if (sensor_di_err_switch == 0) goto LAB_004d66e0;
                      pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : parse_ssidpkt fail\n";
                      uVar17 = 0x4c4;
                      goto LAB_004d7324;
                    }
                    iVar4 = 0;
                    memset(pvVar21,0,*(short *)((int)puVar6 + 6) * 0x44);
                    do {
                      uVar17 = json_object_array_get_idx(local_54,iVar4);
                      pvVar21 = (void *)(puVar6[5] + iVar4 * 0x44);
                      iVar5 = json_object_object_get(uVar17,"ssid");
                      if ((iVar5 == 0) || (iVar8 = json_object_get_type(iVar5), iVar8 == 0)) {
                        *(undefined1 *)((int)pvVar21 + 0x31) = 1;
                      }
                      else {
                        iVar8 = json_object_get_type(iVar5);
                        if (iVar8 == 6) {
                          pcVar3 = (char *)json_object_get_string(iVar5);
                        }
                        else {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                   ,"_sensor_di_collect_pkt_stat_data_parse_ssidpkt",0x42a);
                          }
                          pcVar3 = "";
                        }
                        strncpy(acStack_100,pcVar3,0x30);
                        local_d0 = 0;
                        iVar5 = FUN_00407e60(acStack_100);
                        if (iVar5 == 0) {
                          FUN_00408710(acStack_100,0x31);
                        }
                        memcpy(pvVar21,acStack_100,0x31);
                      }
                      *(short *)((int)pvVar21 + 0x32) = (short)iVar4;
                      *(undefined4 *)((int)pvVar21 + 0x38) = 0;
                      *(undefined4 *)((int)pvVar21 + 0x34) = 0;
                      local_48 = json_object_object_get(uVar17,"pktData");
                      if (local_48 == 0) {
                        if (sensor_di_warning_switch == 0) {
                          uVar11 = puVar6[2];
                        }
                        else {
                          pcVar3 = "[SENSOR_DI_WARNING]%s()/line %d : ssid\'s pktData is null\n";
                          pcVar18 = "_sensor_di_collect_pkt_stat_data_parse_ssidpkt";
                          uVar17 = 0x439;
LAB_004d72e0:
                          printf(pcVar3,pcVar18,uVar17);
                          uVar11 = puVar6[2];
                        }
                      }
                      else {
                        local_118 = 0;
                        local_114 = 0;
                        local_110 = 0;
                        local_10c = 0;
                        local_108 = 0;
                        local_104 = 0;
                        local_102 = 0;
                        local_44 = json_object_array_length(local_48);
                        if (local_44 < 1) {
                          if (sensor_di_debug_switch != 0) {
                            pcVar3 = 
                            "[SENSOR_DI_DEBUG]%s()/line %d : bssid_cnt <= 0 parse_bssidpkt success EXIT\n"
                            ;
                            pcVar18 = "_sensor_di_collect_pkt_stat_data_parse_bssidpkt";
                            uVar17 = 0x3a3;
                            goto LAB_004d72e0;
                          }
                          uVar11 = puVar6[2];
                        }
                        else {
                          *(short *)((int)pvVar21 + 0x3c) = (short)local_44;
                          pvVar9 = (void *)FUN_00408450((short)local_44 * 0xf8,0x3a9);
                          *(void **)((int)pvVar21 + 0x40) = pvVar9;
                          if (pvVar9 == (void *)0x0) {
                            if (sensor_di_err_switch != 0) {
                              pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                              uVar17 = 0x3ac;
LAB_004d76d8:
                              printf(pcVar3,"_sensor_di_collect_pkt_stat_data_parse_bssidpkt",uVar17
                                    );
                            }
LAB_004d74f8:
                            if (sensor_di_err_switch == 0) {
                              iVar4 = *(int *)((int)pvVar21 + 0x40);
                            }
                            else {
                              printf("[SENSOR_DI_ERROR]%s()/line %d : parse_bssidpkt fail EXIT\n",
                                     "_sensor_di_collect_pkt_stat_data_parse_bssidpkt",0x3f1);
                              iVar4 = *(int *)((int)pvVar21 + 0x40);
                            }
                            if (iVar4 != 0) {
                              FUN_00407df0();
                              *(undefined4 *)((int)pvVar21 + 0x40) = 0;
                            }
                            if (sensor_di_err_switch == 0) goto LAB_004d752c;
                            pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : parse_bssidpkt fail\n";
                            uVar17 = 0x43f;
                            goto LAB_004d7bcc;
                          }
                          memset(pvVar9,0,*(short *)((int)pvVar21 + 0x3c) * 0xf8);
                          local_58 = 0;
                          local_50 = puVar6;
                          local_3c = iVar4;
                          do {
                            uVar17 = json_object_array_get_idx(local_48,local_58);
                            iVar5 = *(int *)((int)pvVar21 + 0x40) + local_58 * 0xf8;
                            *(undefined4 *)(iVar5 + 0xc) = 0;
                            *(undefined4 *)(iVar5 + 8) = 0;
                            *(undefined4 *)(iVar5 + 0x10) = 0;
                            *(undefined4 *)(iVar5 + 0x14) = 0;
                            iVar4 = json_object_object_get(uVar17,"bssid");
                            if ((iVar4 == 0) || (iVar8 = json_object_get_type(iVar4), iVar8 != 6)) {
                              if (jcs_err_switch != 0) {
                                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                       ,"_sensor_di_collect_pkt_stat_data_parse_bssidpkt",0x3bc);
                              }
                              pcVar3 = "";
                            }
                            else {
                              pcVar3 = (char *)json_object_get_string(iVar4);
                            }
                            strncpy((char *)&local_118,pcVar3,0x16);
                            local_102 = 0;
                            _str2mac(&local_118,iVar5);
                            iVar4 = json_object_object_get(uVar17,"classInfo");
                            if (iVar4 == 0) {
                              if (sensor_di_warning_switch == 0) {
                                iVar4 = *(int *)(iVar5 + 0x20);
                              }
                              else {
                                pcVar3 = 
                                "[SENSOR_DI_WARNING]%s()/line %d : bssid\'s classInfo is null\n";
                                uVar20 = 0x3c3;
LAB_004d7220:
                                printf(pcVar3,"_sensor_di_collect_pkt_stat_data_parse_bssidpkt",
                                       uVar20);
                                iVar4 = *(int *)(iVar5 + 0x20);
                              }
                            }
                            else {
                              iVar4 = json_object_object_get(iVar4,"pktData");
                              if (iVar4 == 0) {
                                if (sensor_di_warning_switch != 0) {
                                  pcVar3 = 
                                  "[SENSOR_DI_WARNING]%s()/line %d : bssid\'s classInfo\'s pktData is null\n"
                                  ;
                                  uVar20 = 0x3ca;
                                  goto LAB_004d7220;
                                }
                                iVar4 = *(int *)(iVar5 + 0x20);
                              }
                              else {
                                iVar4 = _sensor_di_collect_pkt_stat_data_parse_pktdata
                                                  (iVar4,iVar5 + 0x1c,iVar5 + 0x84,iVar5 + 0xc4);
                                if (iVar4 == -1) {
                                  puVar6 = local_50;
                                  if (sensor_di_err_switch == 0) goto LAB_004d74f8;
                                  pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : parse_pktdata fail\n";
                                  uVar17 = 0x3d0;
                                  goto LAB_004d76d8;
                                }
                                iVar4 = *(int *)(iVar5 + 0x20);
                              }
                            }
                            *(int *)(iVar5 + 0xc) =
                                 iVar4 + *(int *)(iVar5 + 0x88) + *(int *)(iVar5 + 200);
                            *(int *)(iVar5 + 8) =
                                 *(int *)(iVar5 + 0x1c) + *(int *)(iVar5 + 0x84) +
                                 *(int *)(iVar5 + 0xc4);
                            iVar4 = json_object_object_get(uVar17,"pktData");
                            if (iVar4 == 0) {
                              *(undefined4 *)(iVar5 + 0x14) = 0;
                              *(undefined4 *)(iVar5 + 0x10) = 0;
LAB_004d715c:
                              iVar4 = *(int *)((int)pvVar21 + 0x38);
                            }
                            else {
                              local_130[0] = '\0';
                              local_130[1] = '\0';
                              local_130[2] = '\0';
                              local_130[3] = '\0';
                              local_130[4] = '\0';
                              local_130[5] = '\0';
                              local_130[6] = '\0';
                              local_130[7] = '\0';
                              local_130[8] = '\0';
                              local_130[9] = '\0';
                              local_130[10] = '\0';
                              local_130[0xb] = '\0';
                              local_130[0xc] = '\0';
                              local_130[0xd] = '\0';
                              local_130[0xe] = '\0';
                              local_130[0xf] = '\0';
                              local_120 = 0;
                              local_11c = 0;
                              local_11a = 0;
                              iVar8 = json_object_array_length(iVar4);
                              if (0 < iVar8) {
                                *(short *)(iVar5 + 0x18) = (short)iVar8;
                                pvVar9 = (void *)FUN_00408450((short)iVar8 * 0xe8,0x34f);
                                *(void **)(iVar5 + 0xf4) = pvVar9;
                                if (pvVar9 != (void *)0x0) {
                                  iVar24 = 0;
                                  memset(pvVar9,0,*(short *)(iVar5 + 0x18) * 0xe8);
                                  *(undefined4 *)(iVar5 + 0x10) = 0;
                                  *(undefined4 *)(iVar5 + 0x14) = 0;
                                  do {
                                    local_40 = json_object_array_get_idx(iVar4,iVar24);
                                    iVar22 = *(int *)(iVar5 + 0xf4) + iVar24 * 0xe8;
                                    *(undefined4 *)(iVar22 + 8) = 0;
                                    *(undefined4 *)(iVar22 + 0xc) = 0;
                                    iVar12 = json_object_object_get(local_40,"staMac");
                                    if ((iVar12 == 0) ||
                                       (iVar10 = json_object_get_type(iVar12), iVar10 != 6)) {
                                      if (jcs_err_switch != 0) {
                                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                               ,"_sensor_di_collect_pkt_stat_data_parse_stapkt",
                                               0x361);
                                      }
                                      pcVar3 = "";
                                    }
                                    else {
                                      pcVar3 = (char *)json_object_get_string(iVar12);
                                    }
                                    strncpy(local_130,pcVar3,0x16);
                                    local_11a = 0;
                                    _str2mac(local_130,iVar22);
                                    iVar12 = json_object_object_get(local_40,"pktData");
                                    if (iVar12 == 0) {
                                      if (sensor_di_warning_switch == 0) {
                                        iVar12 = *(int *)(iVar22 + 0x10);
                                      }
                                      else {
                                        printf("[SENSOR_DI_WARNING]%s()/line %d : staMac\'s pktData is null\n"
                                               ,"_sensor_di_collect_pkt_stat_data_parse_stapkt",
                                               0x367);
                                        iVar12 = *(int *)(iVar22 + 0x10);
                                      }
                                    }
                                    else {
                                      iVar12 = _sensor_di_collect_pkt_stat_data_parse_pktdata
                                                         (iVar12,iVar22 + 0x10,iVar22 + 0x78,
                                                          iVar22 + 0xb8);
                                      if (iVar12 == -1) {
                                        puVar6 = local_50;
                                        if (sensor_di_err_switch == 0) goto LAB_004d74c4;
                                        pcVar3 = 
                                        "[SENSOR_DI_ERROR]%s()/line %d : parse_pktdata fail\n";
                                        uVar17 = 0x36d;
                                        goto LAB_004d779c;
                                      }
                                      iVar12 = *(int *)(iVar22 + 0x10);
                                    }
                                    *(int *)(iVar22 + 8) =
                                         iVar12 + *(int *)(iVar22 + 0x78) + *(int *)(iVar22 + 0xb8);
                                    *(int *)(iVar22 + 0xc) =
                                         *(int *)(iVar22 + 0x14) + *(int *)(iVar22 + 0x7c) +
                                         *(int *)(iVar22 + 0xbc);
                                    if (sensor_di_debug_switch == 0) {
                                      iVar12 = *(int *)(iVar5 + 0x10);
                                    }
                                    else {
                                      printf("[SENSOR_DI_DEBUG]%s()/line %d : add sta\'s mngt=%d, cntl=%d, data=%d\n"
                                             ,"_sensor_di_collect_pkt_stat_data_parse_stapkt",0x373,
                                             iVar12,*(int *)(iVar22 + 0x78),*(int *)(iVar22 + 0xb8))
                                      ;
                                      iVar12 = *(int *)(iVar5 + 0x10);
                                    }
                                    *(int *)(iVar5 + 0x10) = iVar12 + *(int *)(iVar22 + 8);
                                    *(int *)(iVar5 + 0x14) =
                                         *(int *)(iVar5 + 0x14) + *(int *)(iVar22 + 0xc);
                                    if (sensor_di_debug_switch != 0) {
                                      printf("[SENSOR_DI_DEBUG]%s()/line %d : sta_airtime=%d\n",
                                             "_sensor_di_collect_pkt_stat_data_parse_stapkt",0x377,
                                             *(undefined4 *)(iVar22 + 8));
                                    }
                                    iVar24 = iVar24 + 1;
                                  } while (iVar24 != iVar8);
                                  goto LAB_004d715c;
                                }
                                puVar6 = local_50;
                                if (sensor_di_err_switch != 0) {
                                  pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                                  uVar17 = 0x352;
LAB_004d779c:
                                  puVar6 = local_50;
                                  printf(pcVar3,"_sensor_di_collect_pkt_stat_data_parse_stapkt",
                                         uVar17);
                                }
LAB_004d74c4:
                                if (sensor_di_err_switch == 0) {
                                  iVar4 = *(int *)(iVar5 + 0xf4);
                                }
                                else {
                                  printf("[SENSOR_DI_ERROR]%s()/line %d : parse_stapkt fail EXIT\n",
                                         "_sensor_di_collect_pkt_stat_data_parse_stapkt",0x37e);
                                  iVar4 = *(int *)(iVar5 + 0xf4);
                                }
                                if (iVar4 != 0) {
                                  FUN_00407df0();
                                  *(undefined4 *)(iVar5 + 0xf4) = 0;
                                }
                                if (sensor_di_err_switch == 0) goto LAB_004d74f8;
                                pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : parse_stapkt fail\n";
                                uVar17 = 0x3e4;
                                goto LAB_004d76d8;
                              }
                              if (sensor_di_debug_switch == 0) {
                                iVar4 = *(int *)((int)pvVar21 + 0x38);
                              }
                              else {
                                printf("[SENSOR_DI_DEBUG]%s()/line %d : bssid_cnt <= 0 parse_bssidpkt success EXIT\n"
                                       ,"_sensor_di_collect_pkt_stat_data_parse_stapkt",0x349);
                                iVar4 = *(int *)((int)pvVar21 + 0x38);
                              }
                            }
                            *(int *)((int)pvVar21 + 0x38) =
                                 iVar4 + *(int *)(iVar5 + 0xc) + *(int *)(iVar5 + 0x14);
                            *(int *)((int)pvVar21 + 0x34) =
                                 *(int *)((int)pvVar21 + 0x34) + *(int *)(iVar5 + 8) +
                                 *(int *)(iVar5 + 0x10);
                            local_58 = local_58 + 1;
                          } while (local_58 != local_44);
                          uVar11 = local_50[2];
                          puVar6 = local_50;
                          iVar4 = local_3c;
                        }
                      }
                      iVar4 = iVar4 + 1;
                      puVar6[2] = uVar11 + *(int *)((int)pvVar21 + 0x38);
                      puVar6[3] = puVar6[3] + *(int *)((int)pvVar21 + 0x34);
                    } while (iVar4 != local_4c);
                    if (sensor_di_debug_switch != 0) {
                      pcVar3 = "[SENSOR_DI_DEBUG]%s()/line %d : parse_ssidpkt success EXIT\n";
                      pcVar18 = "_sensor_di_collect_pkt_stat_data_parse_ssidpkt";
                      uVar17 = 0x449;
                      goto LAB_004d6a54;
                    }
                  }
                }
              }
              if (sensor_di_debug_switch == 0) {
                uVar11 = puVar6[3];
              }
              else {
                printf("[SENSOR_DI_DEBUG]%s()/line %d : before set,pkt_stat\'s total_airtime=%d, pkt_stat\'s total_pkt_num=%d\n"
                       ,"_sensor_di_collect_pkt_stat_data",0x4ca,puVar6[3],puVar6[2]);
                uVar11 = puVar6[3];
              }
              if (((uVar11 - 1 < 10000000) && (0 < (int)puVar6[2])) && ((int)puVar6[2] < 0x989681))
              {
                iVar4 = sensor_di_db_set_pkt_stat(puVar6);
                uVar11 = local_110;
                if (iVar4 != -1) {
                  uVar1 = *(ushort *)((int)puVar6 + 6);
                  if (uVar1 != 0) {
                    local_110 = local_110 & 0xffff;
                    local_114 = (uint)uVar1;
                    local_118 = CONCAT31(CONCAT12((char)*(undefined2 *)(puVar6 + 1),(short)local_144
                                                 ),'d' - (local_144._2_1_ + (char)local_144));
                    sVar13 = 0;
                    if (puVar6[5] != 0) {
                      uVar19 = 0;
                      iVar4 = 0;
                      while (iVar4 < *(short *)((int)puVar6 + 6)) {
                        iVar5 = puVar6[5] + iVar4 * 0x44;
                        iVar8 = (int)*(short *)(iVar5 + 0x3c);
                        iVar5 = *(int *)(iVar5 + 0x40);
                        uVar19 = uVar19 + iVar8 & 0xffff;
                        if ((iVar5 == 0) || (iVar24 = 0, iVar8 == 0)) {
                          iVar4 = iVar4 + 1;
                        }
                        else {
                          for (; iVar24 < iVar8; iVar24 = iVar24 + 1) {
                            sVar13 = sVar13 + *(short *)(iVar5 + iVar24 * 0xf8 + 0x18);
                          }
                          iVar4 = iVar4 + 1;
                        }
                      }
                      local_114 = CONCAT22((short)uVar19,uVar1);
                      local_110 = CONCAT22(sVar13,(short)uVar11);
                    }
                    if (*(short *)((int)puVar6 + 6) != 0) {
                      sensor_di_db_set_single_chnl_util_info(*puVar6,local_118,local_114,local_110);
                    }
                  }
                  sensor_id_db_pkt_stat_mem_free(puVar6);
                  uVar17 = 0;
                  if (sensor_di_debug_switch == 0) {
                    return 0;
                  }
                  pcVar3 = 
                  "[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_collect_pkt_stat_data success EXIT\n";
                  pcVar18 = "_sensor_di_collect_pkt_stat_data";
                  uVar20 = 0x4e5;
LAB_004d5450:
                  printf(pcVar3,pcVar18,uVar20);
                  return uVar17;
                }
                if (sensor_di_err_switch == 0) goto LAB_004d66e0;
                pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : set_pkt_stat fail\n";
                uVar17 = 0x4d6;
              }
              else {
                if (sensor_di_warning_switch == 0) goto LAB_004d66e0;
                pcVar3 = "[SENSOR_DI_WARNING]%s()/line %d : pkt stat data invalid\n";
                uVar17 = 0x4ce;
              }
              goto LAB_004d7324;
            }
            if (sensor_di_err_switch == 0) goto LAB_004d66e0;
            uVar1 = *param_1;
            pcVar3 = 
            "[SENSOR_DI_ERROR]%s()/line %d : sensor_id=%d \'s settting chnl is=%d, reported pkt_stat chnl is=%d\n"
            ;
            uVar17 = 0x4b1;
          }
          else {
            if (sensor_di_err_switch == 0) goto LAB_004d66e0;
            uVar1 = *param_1;
            pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : sensor_id=%d \'s scan_mode is=%d\n";
            uVar17 = 0x4aa;
          }
          printf(pcVar3,"_sensor_di_collect_pkt_stat_data",uVar17,(uint)uVar1,uVar11);
          goto LAB_004d66e0;
        }
        if (sensor_di_err_switch == 0) goto LAB_004d66e0;
        pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : set_chnl_util_time fail\n";
        uVar17 = 0x4a3;
      }
    }
  }
LAB_004d7324:
  printf(pcVar3,"_sensor_di_collect_pkt_stat_data",uVar17);
LAB_004d66e0:
  if (sensor_di_err_switch != 0) {
    printf("[SENSOR_DI_ERROR]%s()/line %d : _sensor_di_collect_pkt_stat_data fail EXIT\n",
           "_sensor_di_collect_pkt_stat_data",0x4e9);
  }
  sensor_id_db_pkt_stat_mem_free(puVar6);
  return 0xffffffff;
LAB_004d79c8:
  if (sensor_di_debug_switch == 0) {
    __s[3] = (short)iVar8;
  }
  else {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : pre_length=%d, new_length=%d\n",
           "_sensor_di_collect_freq_analy_data",0x6a4,(int)(short)__s[3],iVar8);
    __s[3] = (short)iVar8;
  }
  iVar4 = sensor_di_db_set_rssi_freq_time(*param_1,__s);
  if (iVar4 != -1) {
    FUN_00407df0(__s);
    uVar17 = 0;
    if (sensor_di_debug_switch == 0) {
      return 0;
    }
    pcVar3 = "[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_collect_freq_analy_data success EXIT\n";
    pcVar18 = "_sensor_di_collect_freq_analy_data";
    uVar20 = 0x6b7;
    goto LAB_004d5450;
  }
  if (sensor_di_err_switch == 0) goto LAB_004d689c;
  pcVar3 = "[SENSOR_DI_ERROR]%s()/line %d : db_set_rssi_freq_time fail\n";
  uVar17 = 0x6ac;
  goto LAB_004d73c0;
}

