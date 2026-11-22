// func _apmngr_jcs_entry_set @ 0054f094 size=5144

void _apmngr_jcs_entry_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  short sVar6;
  undefined4 uVar2;
  int iVar3;
  ushort uVar7;
  ushort uVar8;
  char *pcVar4;
  int iVar5;
  char *pcVar9;
  undefined *puVar10;
  int iVar11;
  undefined **ppuVar12;
  uint uVar13;
  undefined2 local_410 [2];
  char acStack_40c [127];
  undefined1 local_38d;
  char acStack_38c [127];
  undefined1 local_30d;
  undefined1 auStack_308 [12];
  int local_2fc;
  int local_2f4;
  short local_2f0;
  int local_2c8 [3];
  char acStack_2ba [153];
  undefined1 local_221;
  undefined1 local_220;
  undefined2 local_21e;
  int local_21c;
  undefined4 local_218;
  char acStack_214 [31];
  undefined1 local_1f5;
  char acStack_1f4 [15];
  undefined1 local_1e5;
  int local_1e4;
  undefined2 local_1e0 [4];
  undefined1 local_1d8;
  char local_1d7;
  char acStack_1d6 [64];
  undefined1 local_196;
  char acStack_195 [64];
  undefined1 local_155;
  undefined1 local_154;
  int local_150;
  undefined1 local_14c;
  undefined1 local_14b;
  undefined1 auStack_14a [3];
  undefined1 local_147;
  undefined1 auStack_146 [3];
  char acStack_143 [64];
  undefined1 local_103;
  undefined1 local_102;
  undefined1 auStack_f0 [153];
  char local_57;
  char local_37;
  int local_30;
  
  memset(acStack_38c,0,0x80);
  local_410[0] = 0xffff;
  memset(auStack_308,0,0x2d8);
  iVar1 = json_object_object_get(param_1,"multi_id_list");
  if (iVar1 == 0) {
    iVar1 = json_object_object_get(param_1,"entry_id");
    if ((iVar1 == 0) || (iVar3 = json_object_get_type(iVar1), iVar3 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_entry_set",0x4c7);
      }
      pcVar9 = "";
    }
    else {
      pcVar9 = (char *)json_object_get_string(iVar1);
    }
    uVar13 = 0xffff;
    strncpy(acStack_38c,pcVar9,0x7f);
    local_30d = 0;
    iVar1 = atoi(acStack_38c);
    local_410[0] = (undefined2)iVar1;
    iVar1 = json_object_object_get(param_1,"cap_id");
    if (iVar1 != 0) {
      iVar3 = json_object_get_type(iVar1);
      if (iVar3 == 6) {
        pcVar9 = (char *)json_object_get_string(iVar1);
        uVar13 = atoi(pcVar9);
        uVar13 = uVar13 & 0xffff;
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                 "_apmngr_jcs_entry_set",0x4ca);
        }
        if (jcs_err_switch == 0) {
          uVar13 = 0xffff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_apmngr_jcs_entry_set",0x4ca);
          uVar13 = 0xffff;
        }
      }
    }
    iVar1 = -1;
    iVar3 = apmngr_db_entry_get_by_id(local_410[0],auStack_308);
    if (iVar3 == 0) {
      local_30 = local_2fc;
      memset(acStack_40c,0,0x80);
      iVar1 = json_object_object_get(param_1,"entry_name");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x26f);
          }
          pcVar9 = "";
        }
        strncpy(acStack_2ba,pcVar9,0x99);
        local_221 = 0;
      }
      iVar1 = json_object_object_get(param_1,"model_id");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
          local_2c8[0] = atoi(pcVar9);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x272);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x272);
          }
          local_2c8[0] = -1;
        }
      }
      iVar1 = json_object_object_get(param_1,"ap_keep_alive");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
          iVar1 = atoi(pcVar9);
          local_220 = (undefined1)iVar1;
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x275);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x275);
          }
          local_220 = 0xff;
        }
      }
      iVar1 = json_object_object_get(param_1,"client_keep_alive");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
          iVar1 = atoi(pcVar9);
          local_21e = (undefined2)iVar1;
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x278);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x278);
          }
          local_21e = 0xffff;
        }
      }
      iVar1 = json_object_object_get(param_1,"client_idle");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
          local_21c = atoi(pcVar9);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x27b);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x27b);
          }
          local_21c = -1;
        }
      }
      iVar1 = json_object_object_get(param_1,"offline_selfmanage");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        iVar11 = 0;
        if (iVar3 == 6) {
          do {
            while( true ) {
              if (onoff_map <= iVar11) {
                if (jcs_err_switch == 0) goto LAB_0054f400;
                pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                goto LAB_0055020c;
              }
              iVar3 = iVar11 * 0x10;
              pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar3);
              if (pcVar9 != (char *)0x0) break;
              iVar11 = iVar11 + 1;
            }
            pcVar4 = (char *)json_object_get_string(iVar1);
            iVar5 = strcmp(pcVar9,pcVar4);
            iVar11 = iVar11 + 1;
          } while (iVar5 != 0);
          local_218 = *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 + 0xc);
        }
        else {
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_0055020c:
            printf(pcVar9,"_apmngr_jcs_cfg_parse_for_edit",0x27e);
          }
LAB_0054f400:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x27e);
          }
          local_218 = 0xffffffff;
        }
      }
      if (((local_30 == 0) || (iVar1 = apdb_is_hdap_by_id(local_2c8[0],auStack_f0), iVar1 == 0)) ||
         (iVar1 = apmngr_hdap_get_direct_by_name(acStack_2ba), iVar1 == 1)) {
        iVar1 = json_object_object_get(param_1,"led");
        if (iVar1 != 0) {
          iVar3 = json_object_get_type(iVar1);
          if (iVar3 == 6) {
            pcVar9 = (char *)json_object_get_string(iVar1);
            local_150 = atoi(pcVar9);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_cfg_parse_for_edit",0x283);
            }
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_apmngr_jcs_cfg_parse_for_edit",0x283);
            }
            local_150 = -1;
          }
        }
        iVar1 = json_object_object_get(param_1,"telnet_status");
        if (iVar1 != 0) {
          iVar3 = json_object_get_type(iVar1);
          if (iVar3 == 6) {
            pcVar9 = (char *)json_object_get_string(iVar1);
            iVar1 = atoi(pcVar9);
            local_102 = (undefined1)iVar1;
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_cfg_parse_for_edit",0x285);
            }
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_apmngr_jcs_cfg_parse_for_edit",0x285);
            }
            local_102 = 0xff;
          }
        }
      }
      iVar1 = json_object_object_get(param_1,"led_wifi_sync");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        iVar11 = 0;
        if (iVar3 == 6) {
          do {
            while( true ) {
              if (onoff_map <= iVar11) {
                if (jcs_err_switch == 0) goto LAB_0054f488;
                pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                goto LAB_00550228;
              }
              iVar3 = iVar11 * 0x10;
              pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar3);
              if (pcVar9 != (char *)0x0) break;
              iVar11 = iVar11 + 1;
            }
            pcVar4 = (char *)json_object_get_string(iVar1);
            iVar5 = strcmp(pcVar9,pcVar4);
            iVar11 = iVar11 + 1;
          } while (iVar5 != 0);
          local_1d8 = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 + 0xc);
        }
        else {
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00550228:
            printf(pcVar9,"_apmngr_jcs_cfg_parse_for_edit",0x289);
          }
LAB_0054f488:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x289);
          }
          local_1d8 = 0xff;
        }
      }
      iVar1 = json_object_object_get(param_1,"led_timer_enable");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        iVar11 = 0;
        if (iVar3 == 6) {
          do {
            while( true ) {
              if (onoff_map <= iVar11) {
                if (jcs_err_switch == 0) goto LAB_0054f4dc;
                pcVar9 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                goto LAB_00550244;
              }
              iVar3 = iVar11 * 0x10;
              pcVar9 = *(char **)(PTR__mt_onoff_00731f8c + iVar3);
              if (pcVar9 != (char *)0x0) break;
              iVar11 = iVar11 + 1;
            }
            pcVar4 = (char *)json_object_get_string(iVar1);
            iVar5 = strcmp(pcVar9,pcVar4);
            iVar11 = iVar11 + 1;
          } while (iVar5 != 0);
          local_14c = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 + 0xc);
        }
        else {
          if (jcs_err_switch != 0) {
            pcVar9 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00550244:
            printf(pcVar9,"_apmngr_jcs_cfg_parse_for_edit",0x28c);
          }
LAB_0054f4dc:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x28c);
          }
          local_14c = 0xff;
        }
      }
      iVar1 = json_object_object_get(param_1,"fit_fat_button_status");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
          iVar1 = atoi(pcVar9);
          local_154 = (undefined1)iVar1;
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x28f);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x28f);
          }
          local_154 = 0xff;
        }
      }
      iVar1 = json_object_object_get(param_1,"led_close_date");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x294);
          }
          pcVar9 = "";
        }
        strncpy(acStack_40c,pcVar9,0x7f);
        local_38d = 0;
        local_14b = apmngr_db_date_parse(acStack_40c);
      }
      iVar1 = json_object_object_get(param_1,"led_close_time");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x29b);
          }
          pcVar9 = "";
        }
        strncpy(acStack_40c,pcVar9,0x7f);
        local_38d = 0;
        apmngr_db_time_parse(acStack_40c,auStack_14a);
      }
      iVar1 = json_object_object_get(param_1,"led_open_date");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x2a2);
          }
          pcVar9 = "";
        }
        strncpy(acStack_40c,pcVar9,0x7f);
        local_38d = 0;
        local_147 = apmngr_db_date_parse(acStack_40c);
      }
      iVar1 = json_object_object_get(param_1,"led_open_time");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x2a9);
          }
          pcVar9 = "";
        }
        strncpy(acStack_40c,pcVar9,0x7f);
        local_38d = 0;
        apmngr_db_time_parse(acStack_40c,auStack_146);
      }
      if (local_1d7 != -1) {
        iVar1 = json_object_object_get(param_1,"bluetooth_enable");
        if (iVar1 != 0) {
          iVar3 = json_object_get_type(iVar1);
          if (iVar3 == 6) {
            pcVar9 = (char *)json_object_get_string(iVar1);
            iVar1 = atoi(pcVar9);
            local_1d7 = (char)iVar1;
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_cfg_parse_for_edit",0x2b0);
            }
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_apmngr_jcs_cfg_parse_for_edit",0x2b0);
            }
            local_1d7 = -1;
          }
        }
        iVar1 = json_object_object_get(param_1,"account_username");
        if (iVar1 != 0) {
          memset(acStack_1d6,0,0x41);
          iVar3 = json_object_get_type(iVar1);
          if (iVar3 == 6) {
            pcVar9 = (char *)json_object_get_string(iVar1);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_for_edit",0x2b6);
            }
            pcVar9 = "";
          }
          strncpy(acStack_1d6,pcVar9,0x40);
          local_196 = 0;
        }
        iVar1 = json_object_object_get(param_1,"account_password");
        if (iVar1 != 0) {
          memset(acStack_195,0,0x41);
          iVar3 = json_object_get_type(iVar1);
          if (iVar3 == 6) {
            pcVar9 = (char *)json_object_get_string(iVar1);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_apmngr_jcs_cfg_parse_for_edit",0x2bd);
            }
            pcVar9 = "";
          }
          strncpy(acStack_195,pcVar9,0x40);
          local_155 = 0;
        }
      }
      iVar1 = json_object_object_get(param_1,"username");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x2c2);
          }
          pcVar9 = "";
        }
        strncpy(acStack_214,pcVar9,0x1f);
        local_1f5 = 0;
      }
      iVar1 = json_object_object_get(param_1,"password");
      if (iVar1 != 0) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x2c5);
          }
          pcVar9 = "";
        }
        strncpy(acStack_1f4,pcVar9,0xf);
        local_1e5 = 0;
      }
      iVar1 = apdb_support_ap_trunk_by_id(local_2c8[0],auStack_f0);
      if (((iVar1 != 0) &&
          (((local_30 == 0 || (iVar1 = apdb_is_hdap_by_id(local_2c8[0],auStack_f0), iVar1 == 0)) ||
           (iVar1 = apmngr_hdap_get_direct_by_name(acStack_2ba), iVar1 == 1)))) &&
         (iVar1 = json_object_object_get(param_1,"ap_trunk"), iVar1 != 0)) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
          local_1e4 = atoi(pcVar9);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x2cc);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x2cc);
          }
          local_1e4 = -1;
        }
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
          local_150 = atoi(pcVar9);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x2cd);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x2cd);
          }
          local_150 = -1;
        }
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
          iVar1 = atoi(pcVar9);
          local_102 = (undefined1)iVar1;
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x2ce);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_cfg_parse_for_edit",0x2ce);
          }
          local_102 = 0xff;
        }
      }
      ppuVar12 = &APMNGR_CFG_PHY_WIRE_VLAN;
      puVar10 = APMNGR_CFG_PHY_WIRE_VLAN;
      iVar1 = 0;
      while (iVar3 = json_object_object_get(param_1,puVar10), iVar3 != 0) {
        iVar11 = json_object_get_type(iVar3);
        if (iVar11 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar3);
        }
        else {
          pcVar9 = "";
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x2d8);
          }
        }
        ppuVar12 = ppuVar12 + 1;
        strncpy(acStack_40c,pcVar9,0x7f);
        local_38d = 0;
        iVar3 = atoi(acStack_40c);
        *(short *)((int)local_1e0 + iVar1) = (short)iVar3;
        if (iVar1 + 2 == 8) break;
        puVar10 = *ppuVar12;
        iVar1 = iVar1 + 2;
      }
      if ((local_30 != 0) && (iVar1 = json_object_object_get(param_1,"cloud_config_id"), iVar1 != 0)
         ) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar9 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_cfg_parse_for_edit",0x2df);
          }
          pcVar9 = "";
        }
        strncpy(acStack_143,pcVar9,0x40);
        local_103 = 0;
      }
      if (local_2fc - 1U < 3) {
        if (((uVar13 != 0xffff) &&
            ((((local_2f4 == 4 || (local_2f4 == 8)) || (local_2f4 == 6)) || (local_2f4 == 5)))) &&
           ((int)local_2f0 != uVar13)) {
          apmngr_ap_disconnect(local_410,1,1);
        }
        uVar7 = apmngr_ap_cfg_edit(local_410[0],local_2c8);
        iVar1 = (int)(short)uVar7;
        if (iVar1 == 0) {
          if (local_37 != -1) {
            uVar7 = apmngr_ap_edit_region_code(local_410[0],param_1);
          }
          uVar8 = apmngr_ap_edit_mesh_switch(local_410[0],param_1);
          if (local_57 == -1) {
            uVar7 = uVar7 | uVar8;
          }
          else {
            uVar7 = apmngr_ap_edit_new_ap_trunk(local_410[0],param_1);
          }
          iVar1 = (int)(short)uVar7;
        }
        if (((uVar13 != 0xffff) &&
            (((local_2f4 == 4 || (local_2f4 == 8)) || ((local_2f4 == 6 || (local_2f4 == 5)))))) &&
           ((int)local_2f0 != uVar13)) {
          apmngr_ap_capid_update(local_410[0],uVar13);
        }
      }
      else if (local_2fc == 0) {
        apmngr_db_template_edit(local_410[0],local_2c8);
        iVar1 = 0;
      }
      else {
        iVar1 = -1;
        if (apmngr_err_switch != '\0') {
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            iVar1 = -1;
          }
          else {
            printf("[APMNGR_ERROR]%s()/%d Illegal ap type:%d\n","_apmngr_jcs_entry_set",0x4f7,
                   local_2fc);
            iVar1 = -1;
          }
        }
      }
    }
  }
  else {
    sVar6 = _apmngr_jsc_entry_multi_set(param_1,param_2);
    iVar1 = (int)sVar6;
  }
  uVar2 = json_object_new_int(iVar1);
  json_object_object_add(param_2,&DAT_00676a24,uVar2);
  return;
}

