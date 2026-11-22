// func _apmngr_jsc_entry_multi_set @ 0054daa0 size=5620

int _apmngr_jsc_entry_multi_set(undefined4 param_1,undefined4 param_2)

{
  char *__s;
  char *__dest;
  int iVar1;
  int iVar2;
  int iVar3;
  ushort uVar8;
  ushort uVar9;
  char *pcVar4;
  char cVar10;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar11;
  ushort *puVar12;
  uint uVar13;
  undefined8 uVar14;
  char local_b88 [4];
  int local_b84;
  char local_b80 [8];
  char acStack_b78 [127];
  undefined1 local_af9;
  undefined2 auStack_af8 [6];
  int local_aec;
  int local_ae4;
  short local_ae0;
  int local_abc;
  int local_ab8 [2];
  char acStack_aad [156];
  undefined1 local_a11;
  undefined1 local_a10;
  undefined2 local_a0e;
  int local_a0c;
  undefined4 local_a08;
  char acStack_a04 [31];
  undefined1 local_9e5;
  char acStack_9e4 [15];
  undefined1 local_9d5;
  int local_9d4;
  undefined1 local_9c8;
  char local_9c7;
  char acStack_9c6 [64];
  undefined1 local_986;
  char acStack_985 [64];
  undefined1 local_945;
  undefined1 local_944;
  int local_940;
  undefined1 local_93c;
  undefined1 local_93b;
  undefined1 auStack_93a [3];
  undefined1 local_937;
  undefined1 auStack_936 [3];
  char acStack_933 [64];
  undefined1 local_8f3;
  undefined1 auStack_8e0 [185];
  char local_827;
  ushort local_820 [1012];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  memset(local_820,0,0x7e4);
  memset(auStack_af8,0,0x2d8);
  local_b88[0] = '\0';
  local_b88[1] = '\0';
  local_b88[2] = 0;
  local_b80[0] = '\0';
  local_b80[1] = '\0';
  local_b80[2] = '\0';
  local_b80[3] = '\0';
  local_b80[4] = 0;
  __s = (char *)FUN_00408450(0x1c16,0x450);
  if ((__s == (char *)0x0) || (__dest = (char *)FUN_00408450(0x1c16,0x451), __dest == (char *)0x0))
  {
    if ((apmngr_err_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d no memory!\n","_apmngr_jsc_entry_multi_set",0x453);
    }
    iVar3 = -1;
    if (__s == (char *)0x0) {
      return -1;
    }
    __dest = (char *)0x0;
  }
  else {
    memset(__s,0,0x1c16);
    memset(__dest,0,0x1c16);
    iVar1 = json_object_object_get(param_1,"multi_ids");
    local_30 = 0;
    iVar3 = local_30;
    if (((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar3 = local_30, iVar2 == 5)) &&
       (iVar2 = json_object_array_length(iVar1), iVar3 = local_30, 0 < iVar2)) {
      iVar3 = json_object_get_type(iVar1);
      if (iVar3 == 5) {
        puVar12 = local_820;
        for (iVar3 = 0; iVar2 = json_object_array_length(iVar1), iVar3 < iVar2; iVar3 = iVar3 + 1) {
          if (iVar3 == 0x3f2) {
            local_30 = 0x3f2;
            iVar3 = local_30;
            break;
          }
          iVar2 = json_object_array_get_idx(iVar1,iVar3);
          if (iVar2 == 0) {
LAB_0054f010:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_apmngr_jsc_entry_multi_set",0x45c);
            }
            *puVar12 = 0xffff;
          }
          else {
            iVar7 = json_object_get_type(iVar2);
            if (iVar7 == 3) {
              uVar8 = json_object_get_int(iVar2);
              *puVar12 = uVar8;
            }
            else {
              iVar7 = json_object_get_type();
              if (iVar7 != 2) goto LAB_0054f010;
              uVar14 = json_object_get_double(iVar2);
              uVar8 = __fixunsdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
              *puVar12 = uVar8;
            }
          }
          puVar12 = puVar12 + 1;
        }
      }
      else {
        iVar3 = json_object_get_type(iVar1);
        if (((iVar3 != 4) ||
            (iVar1 = json_object_object_length(iVar1), iVar3 = local_30, iVar1 != 0)) &&
           (local_30 = 0, iVar3 = local_30, jcs_err_switch != 0)) {
          printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                 ,"_apmngr_jsc_entry_multi_set",0x45c);
          iVar3 = local_30;
        }
      }
    }
    local_30 = iVar3;
    uVar13 = 0xffff;
    iVar3 = json_object_object_get(param_1,"cap_id");
    if (iVar3 != 0) {
      iVar1 = json_object_get_type(iVar3);
      if (iVar1 == 6) {
        pcVar11 = (char *)json_object_get_string(iVar3);
        uVar13 = atoi(pcVar11);
        uVar13 = uVar13 & 0xffff;
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                 "_apmngr_jsc_entry_multi_set",0x460);
        }
        if (jcs_err_switch == 0) {
          uVar13 = 0xffff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_apmngr_jsc_entry_multi_set",0x460);
          uVar13 = 0xffff;
        }
      }
    }
    puVar12 = local_820;
    iVar3 = -1;
    for (local_2c = 0; local_2c < local_30; local_2c = local_2c + 1) {
      iVar1 = apmngr_db_entry_get_by_id(*puVar12,auStack_af8);
      if (iVar1 == 0) {
        local_34 = local_aec;
        if ((local_aec != 0) && (local_abc == 0)) {
          cVar10 = *__s;
          goto LAB_0054ebb4;
        }
        local_b88[0] = '\0';
        local_b88[1] = '\0';
        local_b88[2] = 0;
        memset(acStack_b78,0,0x80);
        local_b84 = 0;
        iVar3 = json_object_object_get(param_1,"model_id");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
            local_ab8[0] = atoi(pcVar11);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3b9);
            }
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3b9);
            }
            local_ab8[0] = -1;
          }
        }
        iVar3 = json_object_object_get(param_1,"ap_keep_alive");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
            iVar3 = atoi(pcVar11);
            local_a10 = (undefined1)iVar3;
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3bc);
            }
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3bc);
            }
            local_a10 = 0xff;
          }
        }
        iVar3 = json_object_object_get(param_1,"client_keep_alive");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
            iVar3 = atoi(pcVar11);
            local_a0e = (undefined2)iVar3;
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3bf);
            }
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3bf);
            }
            local_a0e = 0xffff;
          }
        }
        iVar3 = json_object_object_get(param_1,"client_idle");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
            local_a0c = atoi(pcVar11);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3c2);
            }
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3c2);
            }
            local_a0c = -1;
          }
        }
        iVar3 = json_object_object_get(param_1,"offline_selfmanage");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            iVar1 = 0;
            while (iVar1 < onoff_map) {
              local_38 = iVar1 * 0x10;
              pcVar11 = *(char **)(PTR__mt_onoff_00731f8c + local_38);
              if (pcVar11 == (char *)0x0) {
                iVar1 = iVar1 + 1;
              }
              else {
                pcVar4 = (char *)json_object_get_string(iVar3);
                iVar2 = strcmp(pcVar11,pcVar4);
                if (iVar2 == 0) {
                  local_a08 = *(undefined4 *)(PTR__mt_onoff_00731f8c + local_38 + 0xc);
                  goto LAB_0054ddb8;
                }
                iVar1 = iVar1 + 1;
              }
            }
            if (jcs_err_switch != 0) {
              pcVar11 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0054ea00:
              printf(pcVar11,"_apmngr_jcs_cfg_parse_multi",0x3c5);
            }
          }
          else if (jcs_err_switch != 0) {
            pcVar11 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
            goto LAB_0054ea00;
          }
          if (jcs_err_switch == 0) {
            local_a08 = 0xffffffff;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_multi",0x3c5);
            local_a08 = 0xffffffff;
          }
        }
LAB_0054ddb8:
        if (((local_34 == 0) || (iVar3 = apdb_is_hdap_by_id(local_ab8[0],auStack_8e0), iVar3 == 0))
           || (iVar3 = apmngr_hdap_get_direct_by_name(acStack_aad + 3), iVar3 == 1)) {
          local_b88[2] = 1;
          iVar3 = json_object_object_get(param_1,"led");
          if (iVar3 != 0) {
            iVar1 = json_object_get_type(iVar3);
            if (iVar1 == 6) {
              pcVar11 = (char *)json_object_get_string(iVar3);
              local_940 = atoi(pcVar11);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "_apmngr_jcs_cfg_parse_multi",0x3cb);
              }
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                       "_apmngr_jcs_cfg_parse_multi",0x3cb);
              }
              local_940 = -1;
            }
          }
        }
        iVar3 = json_object_object_get(param_1,"led_wifi_sync");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            iVar1 = 0;
            while (iVar1 < onoff_map) {
              local_38 = iVar1 * 0x10;
              pcVar11 = *(char **)(PTR__mt_onoff_00731f8c + local_38);
              if (pcVar11 == (char *)0x0) {
                iVar1 = iVar1 + 1;
              }
              else {
                pcVar4 = (char *)json_object_get_string(iVar3);
                iVar2 = strcmp(pcVar11,pcVar4);
                if (iVar2 == 0) {
                  local_9c8 = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + local_38 + 0xc);
                  goto LAB_0054de7c;
                }
                iVar1 = iVar1 + 1;
              }
            }
            if (jcs_err_switch != 0) {
              pcVar11 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0054ea38:
              printf(pcVar11,"_apmngr_jcs_cfg_parse_multi",0x3ce);
            }
          }
          else if (jcs_err_switch != 0) {
            pcVar11 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
            goto LAB_0054ea38;
          }
          if (jcs_err_switch == 0) {
            local_9c8 = 0xff;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_multi",0x3ce);
            local_9c8 = 0xff;
          }
        }
LAB_0054de7c:
        iVar3 = json_object_object_get(param_1,"led_timer_enable");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            iVar1 = 0;
            while (iVar1 < onoff_map) {
              local_38 = iVar1 * 0x10;
              pcVar11 = *(char **)(PTR__mt_onoff_00731f8c + local_38);
              if (pcVar11 == (char *)0x0) {
                iVar1 = iVar1 + 1;
              }
              else {
                pcVar4 = (char *)json_object_get_string(iVar3);
                iVar2 = strcmp(pcVar11,pcVar4);
                if (iVar2 == 0) {
                  local_93c = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + local_38 + 0xc);
                  goto LAB_0054ded0;
                }
                iVar1 = iVar1 + 1;
              }
            }
            if (jcs_err_switch != 0) {
              pcVar11 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0054ea1c:
              printf(pcVar11,"_apmngr_jcs_cfg_parse_multi",0x3d1);
            }
          }
          else if (jcs_err_switch != 0) {
            pcVar11 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
            goto LAB_0054ea1c;
          }
          if (jcs_err_switch == 0) {
            local_93c = 0xff;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_multi",0x3d1);
            local_93c = 0xff;
          }
        }
LAB_0054ded0:
        iVar3 = json_object_object_get(param_1,"fit_fat_button_status");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
            iVar3 = atoi(pcVar11);
            local_944 = (undefined1)iVar3;
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3d4);
            }
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_apmngr_jcs_cfg_parse_multi",0x3d4);
            }
            local_944 = 0xff;
          }
        }
        iVar3 = json_object_object_get(param_1,"led_close_date");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_multi",0x3d9);
            }
            pcVar11 = "";
          }
          strncpy(acStack_b78,pcVar11,0x7f);
          local_af9 = 0;
          local_93b = apmngr_db_date_parse(acStack_b78);
        }
        iVar3 = json_object_object_get(param_1,"led_close_time");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_multi",0x3e0);
            }
            pcVar11 = "";
          }
          strncpy(acStack_b78,pcVar11,0x7f);
          local_af9 = 0;
          apmngr_db_time_parse(acStack_b78,auStack_93a);
        }
        iVar3 = json_object_object_get(param_1,"led_open_date");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_multi",999);
            }
            pcVar11 = "";
          }
          strncpy(acStack_b78,pcVar11,0x7f);
          local_af9 = 0;
          local_937 = apmngr_db_date_parse(acStack_b78);
        }
        iVar3 = json_object_object_get(param_1,"led_open_time");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_multi",0x3ee);
            }
            pcVar11 = "";
          }
          strncpy(acStack_b78,pcVar11,0x7f);
          local_af9 = 0;
          apmngr_db_time_parse(acStack_b78,auStack_936);
        }
        if (local_9c7 != -1) {
          iVar3 = json_object_object_get(param_1,"bluetooth_enable");
          if (iVar3 != 0) {
            iVar1 = json_object_get_type(iVar3);
            if (iVar1 == 6) {
              pcVar11 = (char *)json_object_get_string(iVar3);
              iVar3 = atoi(pcVar11);
              local_9c7 = (char)iVar3;
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "_apmngr_jcs_cfg_parse_multi",0x3f5);
              }
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                       "_apmngr_jcs_cfg_parse_multi",0x3f5);
              }
              local_9c7 = -1;
            }
          }
          iVar3 = json_object_object_get(param_1,"account_username");
          if (iVar3 != 0) {
            memset(acStack_9c6,0,0x41);
            iVar1 = json_object_get_type(iVar3);
            if (iVar1 == 6) {
              pcVar11 = (char *)json_object_get_string(iVar3);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_apmngr_jcs_cfg_parse_multi",0x3fb);
              }
              pcVar11 = "";
            }
            strncpy(acStack_9c6,pcVar11,0x40);
            local_986 = 0;
          }
          iVar3 = json_object_object_get(param_1,"account_password");
          if (iVar3 != 0) {
            memset(acStack_985,0,0x41);
            iVar1 = json_object_get_type(iVar3);
            if (iVar1 == 6) {
              pcVar11 = (char *)json_object_get_string(iVar3);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_apmngr_jcs_cfg_parse_multi",0x402);
              }
              pcVar11 = "";
            }
            strncpy(acStack_985,pcVar11,0x40);
            local_945 = 0;
          }
        }
        iVar3 = json_object_object_get(param_1,"username");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_multi",0x407);
            }
            pcVar11 = "";
          }
          strncpy(acStack_a04,pcVar11,0x1f);
          local_9e5 = 0;
        }
        iVar3 = json_object_object_get(param_1,"password");
        if (iVar3 != 0) {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_multi",0x40a);
            }
            pcVar11 = "";
          }
          strncpy(acStack_9e4,pcVar11,0xf);
          local_9d5 = 0;
        }
        iVar3 = apdb_support_ap_trunk_by_id(local_ab8[0],auStack_8e0);
        if ((iVar3 != 0) &&
           (((local_34 == 0 || (iVar3 = apdb_is_hdap_by_id(local_ab8[0],auStack_8e0), iVar3 == 0))
            || (iVar3 = apmngr_hdap_get_direct_by_name(acStack_aad + 3), iVar3 == 1)))) {
          local_b88[0] = 1;
          iVar3 = json_object_object_get(param_1,"ap_trunk");
          if (iVar3 != 0) {
            iVar1 = json_object_get_type(iVar3);
            if (iVar1 == 6) {
              pcVar11 = (char *)json_object_get_string(iVar3);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_apmngr_jcs_cfg_parse_multi",0x413);
              }
              pcVar11 = "";
            }
            strncpy(acStack_b78,pcVar11,0x7f);
            local_af9 = 0;
            local_9d4 = atoi(acStack_b78);
          }
        }
        iVar3 = apdb_get_ext_wire_phy_by_id(local_ab8[0],auStack_8e0,&local_b84);
        if (iVar3 == 0) {
          local_b88[1] = (char)local_b84;
          iVar3 = local_b84;
          while (local_b84 = iVar3 + -1, 0 < iVar3) {
            iVar3 = local_b84;
            if ((local_b84 < 4) &&
               (iVar1 = json_object_object_get(param_1,(&APMNGR_CFG_PHY_WIRE_VLAN)[local_b84]),
               iVar3 = local_b84, iVar1 != 0)) {
              iVar3 = json_object_get_type(iVar1);
              if (iVar3 == 6) {
                pcVar11 = (char *)json_object_get_string(iVar1);
              }
              else {
                pcVar11 = "";
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_apmngr_jcs_cfg_parse_multi",0x422);
                }
              }
              strncpy(acStack_b78,pcVar11,0x7f);
              iVar3 = local_b84;
              local_af9 = 0;
              iVar1 = atoi(acStack_b78);
              auStack_af8[iVar3 + 0x94] = (short)iVar1;
              iVar3 = local_b84;
            }
          }
        }
        iVar3 = json_object_object_get(param_1,"entry_name");
        if (iVar3 == 0) {
          if (local_34 != 0) {
            iVar3 = apdb_is_hdap_by_id(local_ab8[0],auStack_8e0);
            if ((iVar3 != 0) && (sVar5 = strlen(acStack_aad + 3), 3 < (int)sVar5)) {
              iVar3 = memcmp(acStack_aad + sVar5,&DAT_006cd69c,3);
              if ((iVar3 != 0) || (iVar3 = memcmp(acStack_aad + sVar5,&DAT_006cd6a0,3), iVar3 != 0))
              {
                acStack_aad[sVar5] = '\0';
                acStack_aad[sVar5 + 1] = '\0';
                acStack_aad[sVar5 + 2] = '\0';
              }
            }
            goto LAB_0054e770;
          }
        }
        else {
          iVar1 = json_object_get_type(iVar3);
          if (iVar1 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar3);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_multi",0x42d);
            }
            pcVar11 = "";
          }
          strncpy(acStack_aad + 3,pcVar11,0x99);
          local_a11 = 0;
          if (local_34 != 0) {
LAB_0054e770:
            iVar3 = json_object_object_get(param_1,"cloud_config_id");
            if (iVar3 != 0) {
              iVar1 = json_object_get_type(iVar3);
              if (iVar1 == 6) {
                pcVar11 = (char *)json_object_get_string(iVar3);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_apmngr_jcs_cfg_parse_multi",0x43d);
                }
                pcVar11 = "";
              }
              strncpy(acStack_933,pcVar11,0x40);
              local_8f3 = 0;
            }
          }
        }
        if (local_aec == 0) {
          apmngr_db_template_edit(*puVar12,local_ab8);
        }
        else {
          if (((uVar13 == 0xffff) ||
              ((((local_ae4 != 4 && (local_ae4 != 8)) && (local_ae4 != 6)) && (local_ae4 != 5)))) ||
             ((int)local_ae0 == uVar13)) {
            uVar8 = *puVar12;
          }
          else {
            apmngr_ap_disconnect(local_820 + local_2c,1,1);
            uVar8 = *puVar12;
          }
          uVar8 = apmngr_ap_cfg_edit(uVar8,local_ab8);
          iVar3 = (int)(short)uVar8;
          if (iVar3 == 0) {
            uVar9 = *puVar12;
            if (local_827 != -1) {
              uVar8 = apmngr_ap_edit_region_code(uVar9,param_1);
              uVar9 = *puVar12;
            }
            uVar9 = apmngr_ap_edit_mesh_switch(uVar9,param_1);
            iVar3 = (int)(short)(uVar8 | uVar9);
          }
          if (((uVar13 != 0xffff) &&
              (((local_ae4 == 4 || (local_ae4 == 8)) || ((local_ae4 == 6 || (local_ae4 == 5)))))) &&
             ((int)local_ae0 != uVar13)) {
            apmngr_ap_capid_update(*puVar12,uVar13);
          }
          if (iVar3 != 0) {
            if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[APMNGR_WARNING]%s()/%d id[%d] edit failed.\n","_apmngr_jsc_entry_multi_set",
                     0x493,(uint)*puVar12);
            }
            goto LAB_0054e6d8;
          }
        }
        snprintf(local_b80,4,"%d,",local_aec);
        sVar5 = strlen(__s);
        iVar3 = 0;
        strcpy(__s + sVar5,local_b80);
        do {
          pcVar11 = local_b88 + iVar3;
          iVar3 = iVar3 + 1;
          snprintf(local_b80,4,"%d",(int)*pcVar11);
          sVar5 = strlen(local_b80);
          strncat(__dest,local_b80,sVar5);
        } while (iVar3 != 3);
        iVar3 = 0;
        strcat(__dest,",");
      }
LAB_0054e6d8:
      puVar12 = puVar12 + 1;
    }
    cVar10 = *__s;
LAB_0054ebb4:
    if (cVar10 == '\0') {
      cVar10 = *__dest;
    }
    else {
      sVar5 = strlen(__s);
      if (sVar5 < 0x1c15) {
        __s[sVar5 - 1] = '\0';
        uVar6 = json_object_new_string(__s);
        json_object_object_add(param_2,"type_multi_list",uVar6);
        cVar10 = *__dest;
      }
      else {
        cVar10 = *__dest;
      }
    }
    if ((cVar10 != '\0') && (sVar5 = strlen(__dest), sVar5 < 0x1c15)) {
      __dest[sVar5 - 1] = '\0';
      uVar6 = json_object_new_string(__dest);
      json_object_object_add(param_2,"capa_multi_list",uVar6);
    }
  }
  FUN_00407df0(__s);
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  return iVar3;
}

