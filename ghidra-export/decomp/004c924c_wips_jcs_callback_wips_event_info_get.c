// func wips_jcs_callback_wips_event_info_get @ 004c924c size=3640

void wips_jcs_callback_wips_event_info_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  FILE *__s;
  size_t sVar5;
  uint uVar6;
  char *__needle;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined4 local_7e0;
  undefined4 local_7dc;
  undefined4 local_7d8;
  undefined4 local_7d4;
  undefined2 local_7d0;
  char local_7cc [63];
  undefined1 local_78d;
  char local_78c [153];
  undefined1 local_6f3;
  char acStack_6f0 [256];
  undefined1 auStack_5f0 [18];
  ushort local_5de;
  undefined1 auStack_5a2 [650];
  undefined1 auStack_318 [78];
  undefined1 auStack_2ca [650];
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  
  memset(local_7cc,0,0x40);
  memset(local_78c,0,0x9a);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (sensor_err_switch == '\0') goto LAB_004c9328;
    pcVar11 = "[SENSOR_ERROR]%s()/%d inputs error.\n";
    uVar3 = 0x61f;
  }
  else {
    iVar1 = json_object_object_get(param_1,"wips_info_id");
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar1 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar14 = json_object_get_double(iVar1);
          iVar1 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
        }
        else {
          iVar1 = -1;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "wips_jcs_callback_wips_event_info_get",0x627);
          }
        }
      }
      iVar2 = FUN_004086a0(g_wips_id_allocator,iVar1);
      if (iVar2 == 0) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d wips event[id=%d] not found\n",
                 "wips_jcs_callback_wips_event_info_get",0x62a,iVar1);
        }
        goto LAB_004c9328;
      }
    }
    iVar2 = json_object_object_get(param_1,"entry_name");
    if (iVar2 == 0) {
      strcpy(local_78c,"");
    }
    else {
      iVar4 = json_object_get_type(iVar2);
      if (iVar4 == 6) {
        pcVar11 = (char *)json_object_get_string(iVar2);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "wips_jcs_callback_wips_event_info_get",0x632);
        }
        pcVar11 = "";
      }
      strncpy(local_78c,pcVar11,0x99);
      local_6f3 = 0;
    }
    iVar2 = json_object_object_get(param_1,"wips_threat_classname");
    if (iVar2 == 0) {
      strcpy(local_7cc,"");
    }
    else {
      iVar4 = json_object_get_type(iVar2);
      if (iVar4 == 6) {
        pcVar11 = (char *)json_object_get_string(iVar2);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "wips_jcs_callback_wips_event_info_get",0x63c);
        }
        pcVar11 = "";
      }
      strncpy(local_7cc,pcVar11,0x3f);
      local_78d = 0;
    }
    iVar2 = json_object_object_get(param_1,"wips_threat_level");
    local_3c = 0;
    if (iVar2 != 0) {
      iVar4 = json_object_get_type(iVar2);
      if (iVar4 == 3) {
        local_3c = json_object_get_int(iVar2);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 == 2) {
          uVar14 = json_object_get_double(iVar2);
          local_3c = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
        }
        else {
          local_3c = -1;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "wips_jcs_callback_wips_event_info_get",0x646);
          }
        }
      }
    }
    local_38 = json_object_new_array();
    if (local_38 != 0) {
      uVar13 = 0;
      iVar2 = json_object_object_get(param_1,"start");
      if (iVar2 != 0) {
        iVar4 = json_object_get_type(iVar2);
        if (iVar4 == 3) {
          uVar13 = json_object_get_int(iVar2);
        }
        else {
          iVar4 = json_object_get_type();
          if (iVar4 == 2) {
            uVar14 = json_object_get_double(iVar2);
            uVar13 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
          }
          else {
            uVar13 = 0xffffffff;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "wips_jcs_callback_wips_event_info_get",0x651);
            }
          }
        }
      }
      iVar2 = json_object_object_get(param_1,"size");
      if (iVar2 == 0) {
        local_34 = (uint)g_wips_info_max_size;
      }
      else {
        iVar4 = json_object_get_type(iVar2);
        if (iVar4 == 3) {
          local_34 = json_object_get_int(iVar2);
        }
        else {
          iVar4 = json_object_get_type();
          if (iVar4 == 2) {
            uVar14 = json_object_get_double(iVar2);
            local_34 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
          }
          else {
            local_34 = 0xffffffff;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "wips_jcs_callback_wips_event_info_get",0x653);
            }
          }
        }
      }
      FUN_004082d0(wips_global_mutex,0xffffffff);
      iVar2 = FUN_004081b0(&g_wips_list);
      local_40 = 0;
      for (; iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
        if ((iVar1 == -1) || (iVar1 == *(int *)(iVar2 + 0xc))) {
          if (local_7cc[0] != '\0') {
            uVar6 = *(int *)(iVar2 + 0x98) - 1;
            if (uVar6 < 6) {
              pcVar11 = (&PTR_DAT_006a83b8)[uVar6];
            }
            else {
              pcVar11 = "invalid type";
            }
            iVar4 = strcmp(local_7cc,pcVar11);
            if (iVar4 != 0) goto LAB_004c95a8;
          }
          if ((local_3c == 0) || (local_3c == *(int *)(iVar2 + 0x94))) {
            if (local_78c[0] != '\0') {
              memset(auStack_318,0,0x2d8);
              iVar4 = FUN_004081b0(iVar2 + 0x9c);
              apmngr_db_entry_get_by_id(*(undefined2 *)(iVar4 + 0x38),auStack_318);
              pcVar11 = (char *)FUN_00408150(auStack_2ca);
              __needle = (char *)FUN_00408150(local_78c);
              pcVar11 = strstr(pcVar11,__needle);
              if (pcVar11 == (char *)0x0) goto LAB_004c95a8;
            }
            if ((uVar13 <= local_40) && (local_40 < local_34 + uVar13)) {
              iVar4 = json_object_new_object();
              if (iVar4 == 0) {
                __s = (FILE *)0x0;
                if (sensor_err_switch == '\0') goto LAB_004c962c;
                pcVar11 = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
                uVar3 = 0x666;
                goto LAB_004c9e84;
              }
              local_7e0 = 0;
              local_7dc = 0;
              local_7d8 = 0;
              local_7d4 = 0;
              uVar6 = 0;
              local_7d0 = 0;
              memset(auStack_5f0,0,0x2d8);
              iVar7 = wips_local_time_get();
              local_30 = iVar2 + 0x9c;
              iVar8 = FUN_004081b0(local_30);
              memset(acStack_6f0,0,0x100);
              snprintf(acStack_6f0,0x100,"%d",*(undefined4 *)(iVar2 + 0xc));
              uVar3 = json_object_new_string(acStack_6f0);
              json_object_object_add(iVar4,"id",uVar3);
              memset(acStack_6f0,0,0x100);
              snprintf(acStack_6f0,0x100,"%d",*(undefined4 *)(iVar2 + 0x94));
              uVar3 = json_object_new_string(acStack_6f0);
              json_object_object_add(iVar4,"wips_threat_level",uVar3);
              if (*(int *)(iVar8 + 0x28) + 0xfecea807U < 0xd) {
                uVar6 = (uint)*(byte *)(*(int *)(iVar8 + 0x28) + -0xc6d429);
              }
              memset(acStack_6f0,0,0x100);
              snprintf(acStack_6f0,0x100,"%d",uVar6);
              uVar3 = json_object_new_string(acStack_6f0);
              json_object_object_add(iVar4,"wips_threat_class_id",uVar3);
              if (uVar6 - 1 < 6) {
                pcVar11 = (&PTR_DAT_006a83b8)[uVar6 - 1];
              }
              else {
                pcVar11 = "invalid type";
              }
              uVar3 = json_object_new_string(pcVar11);
              json_object_object_add(iVar4,"wips_threat_classname",uVar3);
              uVar3 = json_object_new_string(iVar2 + 0x10);
              json_object_object_add(iVar4,"ssid",uVar3);
              memset(acStack_6f0,0,0x100);
              snprintf(acStack_6f0,0x100,"%d",*(undefined4 *)(iVar2 + 0x44));
              uVar3 = json_object_new_string(acStack_6f0);
              json_object_object_add(iVar4,"ssid_encode",uVar3);
              iVar10 = iVar2 + 0x4e;
              if (uVar6 != 2) {
                iVar10 = iVar2 + 0x48;
              }
              wips_mac2str(iVar10,&local_7e0);
              uVar3 = json_object_new_string(&local_7e0);
              json_object_object_add(iVar4,"dev_mac",uVar3);
              wips_mac2str(iVar2 + 0x4e,&local_7e0);
              uVar3 = json_object_new_string(&local_7e0);
              json_object_object_add(iVar4,"target_mac",uVar3);
              uVar3 = json_object_new_string(iVar2 + 0x54);
              json_object_object_add(iVar4,"criterion",uVar3);
              if (*(short *)(iVar8 + 0x38) == -1) {
                uVar3 = json_object_new_string("---");
                json_object_object_add(iVar4,"entry_name",uVar3);
                memset(acStack_6f0,0,0x100);
                uVar6 = 0xffffffff;
              }
              else {
                apmngr_db_entry_get_by_id(*(short *)(iVar8 + 0x38),auStack_5f0);
                uVar3 = json_object_new_string(auStack_5a2);
                json_object_object_add(iVar4,"entry_name",uVar3);
                memset(acStack_6f0,0,0x100);
                uVar6 = (uint)local_5de;
              }
              snprintf(acStack_6f0,0x100,"%d",uVar6);
              uVar3 = json_object_new_string(acStack_6f0);
              json_object_object_add(iVar4,"group_id",uVar3);
              memset(acStack_6f0,0,0x100);
              snprintf(acStack_6f0,0x100,"%d",*(undefined4 *)(iVar8 + 0x30));
              uVar3 = json_object_new_string(acStack_6f0);
              json_object_object_add(iVar4,"rssi",uVar3);
              local_2c = json_object_new_array();
              if (local_2c == 0) {
                if (sensor_err_switch != '\0') {
                  printf("[SENSOR_ERROR]%s()/%d malloc json obj failed.\n","wips_info_to_json",0x1e5
                        );
                }
                json_object_put(iVar4);
              }
              else {
                iVar8 = FUN_004081b0(local_30);
                iVar10 = iVar7 + -0x15180;
                for (; iVar8 != 0; iVar8 = FUN_00408680(iVar8)) {
                  iVar9 = json_object_new_object();
                  if (iVar9 == 0) {
                    if (sensor_err_switch != '\0') {
                      printf("[SENSOR_ERROR]%s()/%d malloc json obj failed.\n","wips_info_to_json",
                             0x1ed);
                    }
                  }
                  else {
                    if (*(int *)(iVar8 + 0x20) < iVar10) {
                      memset(acStack_6f0,0,0x100);
                      iVar12 = iVar10;
                    }
                    else if (iVar7 < *(int *)(iVar8 + 0x20)) {
                      memset(acStack_6f0,0,0x100);
                      iVar12 = iVar7;
                    }
                    else {
                      memset(acStack_6f0,0,0x100);
                      iVar12 = *(int *)(iVar8 + 0x20);
                    }
                    snprintf(acStack_6f0,0x100,"%d",iVar12);
                    uVar3 = json_object_new_string(acStack_6f0);
                    json_object_object_add(iVar9,"start",uVar3);
                    if (*(int *)(iVar8 + 0x24) < iVar10) {
                      memset(acStack_6f0,0,0x100);
                      iVar12 = iVar10;
                    }
                    else if (iVar7 < *(int *)(iVar8 + 0x24)) {
                      memset(acStack_6f0,0,0x100);
                      iVar12 = iVar7;
                    }
                    else {
                      memset(acStack_6f0,0,0x100);
                      iVar12 = *(int *)(iVar8 + 0x24);
                    }
                    snprintf(acStack_6f0,0x100,"%d",iVar12);
                    uVar3 = json_object_new_string(acStack_6f0);
                    json_object_object_add(iVar9,"end",uVar3);
                    json_object_array_add(local_2c,iVar9);
                  }
                }
                json_object_object_add(iVar4,"discover_time_list",local_2c);
                memset(acStack_6f0,0,0x100);
                iVar7 = FUN_004081b0(local_30);
                uVar3 = 0xffffffff;
                if (iVar7 != 0) {
                  uVar3 = *(undefined4 *)(iVar7 + 0x24);
                }
                snprintf(acStack_6f0,0x100,"%d",uVar3);
                uVar3 = json_object_new_string(acStack_6f0);
                json_object_object_add(iVar4,"last_discover_time",uVar3);
                if (*(int *)(iVar2 + 0xa8) == 1) {
                  pcVar11 = "0";
                }
                else {
                  pcVar11 = "1";
                }
                uVar3 = json_object_new_string(pcVar11);
                json_object_object_add(iVar4,"wips_status",uVar3);
                uVar3 = 0;
                if (*(int *)(iVar2 + 0xa8) != 2) {
                  uVar3 = *(undefined4 *)(iVar2 + 0xac);
                }
                uVar3 = wips_counter_status2str(uVar3);
                uVar3 = json_object_new_string(uVar3);
                json_object_object_add(iVar4,"counter_status",uVar3);
                json_object_array_add(local_38,iVar4);
              }
            }
            local_40 = local_40 + 1;
          }
        }
LAB_004c95a8:
      }
      FUN_00407f30(wips_global_mutex);
      __s = fopen("/tmp/wips_info_tmp_file","w+");
      if (__s == (FILE *)0x0) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d open file[%s] fail.\n",
                 "wips_jcs_callback_wips_event_info_get",0x67b,"/tmp/wips_info_tmp_file");
        }
      }
      else {
        pcVar11 = (char *)json_object_to_json_string_ext(local_38,0);
        if (pcVar11 == (char *)0x0) {
          if (sensor_err_switch != '\0') {
            pcVar11 = "[SENSOR_ERROR]%s()/%d JSON_STRING_FROM_OBJ fail!\n";
            uVar3 = 0x681;
            goto LAB_004c9e84;
          }
        }
        else {
          sVar5 = strlen(pcVar11);
          sVar5 = fwrite(pcVar11,sVar5,1,__s);
          if (sVar5 == 1) {
            uVar3 = json_object_new_string("/tmp/wips_info_tmp_file");
            json_object_object_add(param_2,"file_name",uVar3);
            uVar3 = json_object_new_int(local_40);
            json_object_object_add(param_2,"count",uVar3);
            uVar3 = json_object_new_int(0);
            json_object_object_add(param_2,&DAT_00676a24,uVar3);
            fclose(__s);
            json_object_put(local_38);
            return;
          }
          if (sensor_err_switch != '\0') {
            pcVar11 = "[SENSOR_ERROR]%s()/%d write result to file fail!\n";
            uVar3 = 0x689;
LAB_004c9e84:
            printf(pcVar11,"wips_jcs_callback_wips_event_info_get",uVar3);
          }
        }
      }
LAB_004c962c:
      json_object_put(local_38);
      if (__s != (FILE *)0x0) {
        fclose(__s);
      }
      goto LAB_004c9328;
    }
    if (sensor_err_switch == '\0') goto LAB_004c9328;
    pcVar11 = "[SENSOR_ERROR]%s()/%d malloc json obj failed.\n";
    uVar3 = 0x64c;
  }
  printf(pcVar11,"wips_jcs_callback_wips_event_info_get",uVar3);
LAB_004c9328:
  uVar3 = json_object_new_int(0xffffffff);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return;
}

