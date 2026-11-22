// func jcs_deep_inspection_multi_chnl_rssi @ 004d9164 size=2696

void jcs_deep_inspection_multi_chnl_rssi(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  FILE *__s;
  char *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  int iVar15;
  int iVar16;
  short local_1c0 [2];
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  char acStack_1a8 [120];
  char acStack_130 [256];
  int local_30;
  int local_2c;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_multi_chnl_rssi ENTER\n",
           "jcs_deep_inspection_multi_chnl_rssi",0xf0e);
  }
  local_1c0[0] = 0;
  local_1bc = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = 0;
  memset(acStack_1a8,0,0x78);
  iVar2 = _jcs_parse_sensor_id(param_1);
  if (iVar2 == -1) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid entry_id\n",
             "jcs_deep_inspection_multi_chnl_rssi",0xf22);
    }
    __s = (FILE *)0x0;
    pcVar10 = (char *)0x0;
    iVar2 = 0;
    iVar12 = 0;
    psVar14 = (short *)0x0;
  }
  else {
    psVar14 = (short *)sensor_di_db_get_ssid_chnl_info(iVar2,local_1c0);
    if (psVar14 == (short *)0x0) {
      if (sensor_di_debug_switch != 0) {
        pcVar10 = "[SENSOR_DI_DEBUG]%s()/line %d : get_ssid_chnl_info fail\n";
        uVar5 = 0xf29;
LAB_004d94f0:
        printf(pcVar10,"jcs_deep_inspection_multi_chnl_rssi",uVar5);
      }
    }
    else {
      if (0 < local_1c0[0]) {
        iVar12 = json_object_new_object();
        if (iVar12 == 0) {
          if (sensor_di_err_switch != 0) {
            printf("[SENSOR_DI_ERROR]%s()/line %d : Create json object ret_obj failed\n",
                   "jcs_deep_inspection_multi_chnl_rssi",0xf36);
          }
          pcVar10 = (char *)0x0;
          __s = (FILE *)0x0;
          iVar2 = 0;
        }
        else {
          iVar2 = json_object_new_array();
          if (iVar2 == 0) {
            if (sensor_di_err_switch == 0) {
LAB_004d9920:
              __s = (FILE *)0x0;
              pcVar10 = (char *)0x0;
            }
            else {
              pcVar10 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n";
              uVar5 = 0xf3d;
LAB_004d9938:
              __s = (FILE *)0x0;
              printf(pcVar10,"jcs_deep_inspection_multi_chnl_rssi",uVar5);
              pcVar10 = (char *)0x0;
            }
          }
          else {
            psVar9 = psVar14;
            for (local_2c = 0; local_2c < local_1c0[0]; local_2c = local_2c + 1) {
              if ((*psVar9 != 0) && (iVar15 = 0, *(int *)(psVar9 + 2) != 0)) {
LAB_004d925c:
                if (iVar15 < *psVar9) {
                  iVar13 = *(int *)(psVar9 + 2);
                  iVar11 = iVar15 * 0x28;
                  iVar16 = iVar13 + iVar11;
                  iVar6 = 0;
                  if (*(short *)(iVar16 + 0x10) < 1) {
                    for (; iVar6 < iVar15; iVar6 = iVar6 + 1) {
                      iVar3 = 0;
                      iVar8 = iVar16;
                      if (iVar13 != -0x1c) {
                        while (iVar7 = iVar13 + iVar3, iVar3 = iVar3 + 1,
                              *(char *)(iVar8 + 0x1c) == *(char *)(iVar7 + 0x1c)) {
                          iVar8 = iVar16 + iVar3;
                          if (iVar3 == 6) {
                            iVar15 = iVar15 + 1;
                            goto LAB_004d925c;
                          }
                        }
                      }
                      iVar13 = iVar13 + 0x28;
                    }
                    if (*(short *)(iVar16 + 0x18) == 4) {
                      local_30 = 0;
                      do {
                        iVar13 = json_object_new_object();
                        if (iVar13 == 0) {
                          if (sensor_di_err_switch == 0) goto LAB_004d9920;
                          pcVar10 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE fail\n";
                          uVar5 = 0xf64;
                          goto LAB_004d9938;
                        }
                        memset(acStack_130,0,0x100);
                        snprintf(acStack_130,0x100,"%d",
                                 (int)*(short *)(*(int *)(psVar9 + 2) + iVar11 + 0x10));
                        uVar5 = json_object_new_string(acStack_130);
                        json_object_object_add(iVar13,"rssi",uVar5);
                        if (local_30 == 0) {
                          memset(acStack_130,0,0x100);
                          uVar1 = *(ushort *)(*(int *)(psVar9 + 2) + iVar11 + 0x14);
                        }
                        else {
                          memset(acStack_130,0,0x100);
                          uVar1 = *(ushort *)(*(int *)(psVar9 + 2) + iVar11 + 0x16);
                        }
                        snprintf(acStack_130,0x100,"%d",(uint)uVar1);
                        uVar5 = json_object_new_string(acStack_130);
                        json_object_object_add(iVar13,"center_chnl",uVar5);
                        memset(acStack_130,0,0x100);
                        snprintf(acStack_130,0x100,"%d",
                                 (uint)*(ushort *)(*(int *)(psVar9 + 2) + iVar11 + 0x12));
                        uVar5 = json_object_new_string(acStack_130);
                        json_object_object_add(iVar13,"primary_chnl",uVar5);
                        memset(acStack_130,0,0x100);
                        snprintf(acStack_130,0x100,"%d",2);
                        uVar5 = json_object_new_string(acStack_130);
                        json_object_object_add(iVar13,"band_width",uVar5);
                        local_1bc = 0;
                        local_1b8 = 0;
                        local_1b4 = 0;
                        local_1b0 = 0;
                        local_1ac = 0;
                        FUN_004d7d34(*(int *)(psVar9 + 2) + iVar11 + 0x1c,&local_1bc);
                        uVar5 = json_object_new_string(&local_1bc);
                        json_object_object_add(iVar13,"bssid",uVar5);
                        if (*(char *)((int)psVar9 + 0x39) == '\0') {
                          uVar5 = json_object_new_string(psVar9 + 4);
                          json_object_object_add(iVar13,"ssid",uVar5);
                        }
                        json_object_array_add(iVar2,iVar13);
                        local_30 = local_30 + 1;
                      } while (local_30 != 2);
                      iVar15 = iVar15 + 1;
                    }
                    else {
                      iVar13 = json_object_new_object();
                      if (iVar13 == 0) {
                        if (sensor_di_err_switch == 0) goto LAB_004d9920;
                        pcVar10 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE fail\n";
                        uVar5 = 0xf87;
                        goto LAB_004d9938;
                      }
                      memset(acStack_130,0,0x100);
                      snprintf(acStack_130,0x100,"%d",
                               (int)*(short *)(*(int *)(psVar9 + 2) + iVar11 + 0x10));
                      uVar5 = json_object_new_string(acStack_130);
                      json_object_object_add(iVar13,"rssi",uVar5);
                      memset(acStack_130,0,0x100);
                      snprintf(acStack_130,0x100,"%d",
                               (uint)*(ushort *)(*(int *)(psVar9 + 2) + iVar11 + 0x14));
                      uVar5 = json_object_new_string(acStack_130);
                      json_object_object_add(iVar13,"center_chnl",uVar5);
                      memset(acStack_130,0,0x100);
                      snprintf(acStack_130,0x100,"%d",
                               (uint)*(ushort *)(*(int *)(psVar9 + 2) + iVar11 + 0x12));
                      uVar5 = json_object_new_string(acStack_130);
                      json_object_object_add(iVar13,"primary_chnl",uVar5);
                      memset(acStack_130,0,0x100);
                      snprintf(acStack_130,0x100,"%d",
                               (uint)*(ushort *)(*(int *)(psVar9 + 2) + iVar11 + 0x18));
                      uVar5 = json_object_new_string(acStack_130);
                      json_object_object_add(iVar13,"band_width",uVar5);
                      local_1bc = 0;
                      local_1b8 = 0;
                      local_1b4 = 0;
                      local_1b0 = 0;
                      local_1ac = 0;
                      FUN_004d7d34(*(int *)(psVar9 + 2) + iVar11 + 0x1c,&local_1bc);
                      uVar5 = json_object_new_string(&local_1bc);
                      json_object_object_add(iVar13,"bssid",uVar5);
                      if (*(char *)((int)psVar9 + 0x39) == '\0') {
                        uVar5 = json_object_new_string(psVar9 + 4);
                        json_object_object_add(iVar13,"ssid",uVar5);
                      }
                      json_object_array_add(iVar2,iVar13);
                      iVar15 = iVar15 + 1;
                    }
                  }
                  else {
                    iVar15 = iVar15 + 1;
                  }
                  goto LAB_004d925c;
                }
              }
              psVar9 = psVar9 + 0x1e;
            }
            json_object_object_add(iVar12,"deep_inspection_multi_chnl_rssi",iVar2);
            iVar15 = 0;
            iVar2 = (int)local_1c0[0];
            psVar9 = psVar14;
            if (iVar2 != 0) {
              for (; iVar15 < iVar2; iVar15 = iVar15 + 1) {
                if ((*psVar9 != 0) && (iVar2 = 0, *(int *)(psVar9 + 2) != 0)) {
                  while (iVar2 < *psVar9) {
                    iVar13 = iVar2 * 0x28;
                    iVar2 = iVar2 + 1;
                    if (*(int *)(*(int *)(psVar9 + 2) + iVar13 + 0x24) != 0) {
                      FUN_00407df0();
                      *(undefined4 *)(*(int *)(psVar9 + 2) + iVar13 + 0x24) = 0;
                    }
                  }
                  FUN_00407df0(*(undefined4 *)(psVar9 + 2));
                  psVar9[2] = 0;
                  psVar9[3] = 0;
                }
                psVar9 = psVar9 + 0x1e;
                iVar2 = (int)local_1c0[0];
              }
              FUN_00407df0(psVar14);
              psVar14 = (short *)0x0;
              local_1c0[0] = 0;
            }
            pcVar10 = (char *)json_object_to_json_string_ext(iVar12,0);
            pcVar10 = strdup(pcVar10);
            if (pcVar10 == (char *)0x0) {
              if (sensor_di_err_switch == 0) {
                __s = (FILE *)0x0;
                iVar2 = 0;
              }
              else {
                __s = (FILE *)0x0;
                printf("[SENSOR_DI_ERROR]%s()/line %d : generate result_str failed\n",
                       "jcs_deep_inspection_multi_chnl_rssi",0xfbf);
                iVar2 = 0;
              }
            }
            else {
              json_object_put(iVar12);
              sVar4 = strlen(pcVar10);
              l_sensor_di_file_write_counter = l_sensor_di_file_write_counter + 1;
              snprintf(acStack_1a8,0x78,"/tmp/deep_checkup_result_%d");
              __s = fopen(acStack_1a8,"w+");
              if (__s == (FILE *)0x0) {
                iVar2 = 0;
                if (sensor_di_err_switch != 0) {
                  printf("[SENSOR_DI_ERROR]%s()/line %d : open result file failed.\n",
                         "jcs_deep_inspection_multi_chnl_rssi",0xfcc);
                  iVar2 = 0;
                }
              }
              else {
                sVar4 = fwrite(pcVar10,(int)(short)sVar4,1,__s);
                if (sVar4 == 1) {
                  free(pcVar10);
                  fclose(__s);
                  if (sensor_di_debug_switch != 0) {
                    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_multi_chnl_rssi success EXIT\n"
                           ,"jcs_deep_inspection_multi_chnl_rssi",0xfe1);
                  }
                  uVar5 = json_object_new_string(acStack_1a8);
                  json_object_object_add(param_2,"file_name",uVar5);
                  uVar5 = 0;
                  goto LAB_004d93ac;
                }
                iVar2 = 0;
                if (sensor_di_err_switch != 0) {
                  printf("[SENSOR_DI_ERROR]%s()/line %d : write result to file failed.\n",
                         "jcs_deep_inspection_multi_chnl_rssi",0xfd2);
                }
              }
            }
          }
        }
        goto LAB_004d92b4;
      }
      if (sensor_di_err_switch != 0) {
        pcVar10 = "[SENSOR_DI_ERROR]%s()/line %d : param invalid\n";
        uVar5 = 0xf2f;
        goto LAB_004d94f0;
      }
    }
    pcVar10 = (char *)0x0;
    __s = (FILE *)0x0;
    iVar2 = 0;
    iVar12 = 0;
  }
LAB_004d92b4:
  if (sensor_di_warning_switch != 0) {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_inspection_multi_chnl_rssi fail EXIT\n",
           "jcs_deep_inspection_multi_chnl_rssi",0xfe7);
  }
  if ((local_1c0[0] != 0) && (iVar15 = 0, psVar9 = psVar14, psVar14 != (short *)0x0)) {
    for (; iVar15 < local_1c0[0]; iVar15 = iVar15 + 1) {
      if ((*psVar9 != 0) && (iVar13 = 0, *(int *)(psVar9 + 2) != 0)) {
        while (iVar13 < *psVar9) {
          iVar16 = iVar13 * 0x28;
          iVar13 = iVar13 + 1;
          if (*(int *)(*(int *)(psVar9 + 2) + iVar16 + 0x24) != 0) {
            FUN_00407df0();
            *(undefined4 *)(*(int *)(psVar9 + 2) + iVar16 + 0x24) = 0;
          }
        }
        FUN_00407df0(*(undefined4 *)(psVar9 + 2));
        psVar9[2] = 0;
        psVar9[3] = 0;
      }
      psVar9 = psVar9 + 0x1e;
    }
    FUN_00407df0(psVar14);
    local_1c0[0] = 0;
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (iVar12 != 0) {
    json_object_put(iVar12);
  }
  if (pcVar10 != (char *)0x0) {
    free(pcVar10);
  }
  uVar5 = 1;
  if (__s != (FILE *)0x0) {
    fclose(__s);
    uVar5 = 1;
  }
LAB_004d93ac:
  uVar5 = json_object_new_int(uVar5);
  json_object_object_add(param_2,&DAT_00676a24,uVar5);
  return;
}

