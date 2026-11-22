// func _apmngr_jcs_entry_add @ 005504ac size=6824

void _apmngr_jcs_entry_add(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  undefined *puVar7;
  char cVar9;
  undefined4 uVar8;
  uint uVar10;
  char cVar11;
  undefined **ppuVar12;
  undefined4 local_420;
  undefined2 local_41c;
  char local_418 [16];
  uint local_408;
  char acStack_404 [127];
  undefined1 local_385;
  byte local_384 [127];
  undefined1 local_305;
  undefined1 auStack_300 [18];
  undefined2 local_2ee;
  int local_2ec;
  undefined2 local_2e8;
  undefined4 local_2c4;
  int local_2c0;
  char local_2b8 [6];
  char acStack_2b2 [153];
  undefined1 local_219;
  undefined1 local_218;
  undefined2 local_216;
  int local_214;
  undefined4 local_210;
  char acStack_20c [31];
  undefined1 local_1ed;
  char acStack_1ec [15];
  undefined1 local_1dd;
  int local_1dc;
  undefined2 local_1d8 [4];
  undefined1 local_1d0;
  char local_1cf;
  char acStack_1ce [64];
  undefined1 local_18e;
  char acStack_18d [64];
  undefined1 local_14d;
  undefined1 local_14c;
  int local_148;
  char local_144;
  undefined1 local_143;
  undefined2 local_142;
  undefined1 local_140;
  undefined1 local_13f;
  undefined2 local_13e;
  undefined1 local_13c;
  undefined1 local_fa;
  undefined1 local_f9;
  undefined1 auStack_e8 [153];
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  char acStack_4c [36];
  
  memset(auStack_300,0,0x2d8);
  memset(local_384,0,0x80);
  local_420 = 0;
  local_41c = 0;
  local_418[0] = '\0';
  local_418[1] = '\0';
  local_418[2] = '\0';
  local_418[3] = '\0';
  local_418[4] = '\0';
  local_418[5] = '\0';
  local_418[6] = '\0';
  local_418[7] = '\0';
  local_418[8] = '\0';
  local_418[9] = '\0';
  local_418[10] = '\0';
  local_418[0xb] = '\0';
  local_418[0xc] = '\0';
  local_418[0xd] = '\0';
  local_418[0xe] = '\0';
  local_418[0xf] = '\0';
  local_408 = 0;
  memset(auStack_300,0,0x2d8);
  iVar1 = json_object_object_get(param_1,"group_id");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_entry_add",0x323);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy((char *)local_384,pcVar6,0x7f);
  local_305 = 0;
  iVar1 = atoi((char *)local_384);
  local_2ee = (undefined2)iVar1;
  iVar1 = json_object_object_get(param_1,"ap_role");
  if (iVar1 == 0) {
    local_2ec = 0;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      iVar2 = 0;
      while (iVar2 < ap_role_map) {
        pcVar6 = *(char **)(PTR__mt_ap_role_0074bf1c + iVar2 * 0x10);
        if (pcVar6 == (char *)0x0) {
          iVar2 = iVar2 + 1;
        }
        else {
          pcVar3 = (char *)json_object_get_string(iVar1);
          iVar4 = strcmp(pcVar6,pcVar3);
          if (iVar4 == 0) {
            local_2ec = *(int *)(PTR__mt_ap_role_0074bf1c + iVar2 * 0x10 + 0xc);
            goto LAB_005505e0;
          }
          iVar2 = iVar2 + 1;
        }
      }
      if (jcs_err_switch != 0) {
        pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_00551660:
        printf(pcVar6,"_apmngr_jcs_entry_add",0x327);
      }
    }
    else if (jcs_err_switch != 0) {
      pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
      goto LAB_00551660;
    }
    if (jcs_err_switch == 0) {
      local_2ec = -1;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_entry_add",
             0x327);
      local_2ec = -1;
    }
  }
LAB_005505e0:
  iVar1 = json_object_object_get(param_1,"lag_mode");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
      iVar1 = atoi(pcVar6);
      local_4e = (undefined1)iVar1;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_entry_add",0x32a);
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_entry_add",
               0x32a);
      }
      local_4e = 0xff;
    }
  }
  iVar1 = json_object_object_get(param_1,"new_ap_trunk");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
      iVar1 = atoi(pcVar6);
      local_4f = (undefined1)iVar1;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_entry_add",0x32d);
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_entry_add",
               0x32d);
      }
      local_4f = 0xff;
    }
  }
  iVar1 = json_object_object_get(param_1,"lag_phy_num");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
      iVar1 = atoi(pcVar6);
      local_4d = (undefined1)iVar1;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_entry_add",0x330);
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_entry_add",
               0x330);
      }
      local_4d = 0xff;
    }
  }
  iVar1 = json_object_object_get(param_1,"lag_phy_list");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_entry_add",0x333);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_418,pcVar6,0x13);
  local_408 = local_408 & 0xffffff00;
  strncpy(acStack_4c,local_418,0x14);
  iVar1 = json_object_object_get(param_1,"firmware_id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_entry_add",0x339);
      }
      pcVar6 = "";
    }
    strncpy((char *)local_384,pcVar6,0x7f);
    local_305 = 0;
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(auStack_e8), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d the firmware_id is %s\n","_apmngr_jcs_entry_add",0x33a,local_384
            );
    }
    FUN_00408280(auStack_e8,local_384,0x20);
  }
  memset(acStack_404,0,0x80);
  iVar1 = json_object_object_get(param_1,"entry_name");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_cfg_parse",0x1f9);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_2b2,pcVar6,0x99);
  local_219 = 0;
  iVar1 = json_object_object_get(param_1,"model_id");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_cfg_parse",0x1fc);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_404,pcVar6,0x7f);
  local_385 = 0;
  local_2c0 = atoi(acStack_404);
  iVar1 = json_object_object_get(param_1,"ap_keep_alive");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_cfg_parse",0x200);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_404,pcVar6,0x7f);
  local_385 = 0;
  iVar1 = atoi(acStack_404);
  local_218 = (undefined1)iVar1;
  iVar1 = json_object_object_get(param_1,"client_keep_alive");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_cfg_parse",0x204);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_404,pcVar6,0x7f);
  local_385 = 0;
  iVar1 = atoi(acStack_404);
  local_216 = (undefined2)iVar1;
  iVar1 = json_object_object_get(param_1,"client_idle");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_cfg_parse",0x208);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_404,pcVar6,0x7f);
  local_385 = 0;
  local_214 = atoi(acStack_404);
  iVar1 = json_object_object_get(param_1,"offline_selfmanage");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      iVar2 = 0;
      while (iVar2 < onoff_map) {
        pcVar6 = *(char **)(PTR__mt_onoff_00731f8c + iVar2 * 0x10);
        if (pcVar6 == (char *)0x0) {
          iVar2 = iVar2 + 1;
        }
        else {
          pcVar3 = (char *)json_object_get_string(iVar1);
          iVar4 = strcmp(pcVar6,pcVar3);
          if (iVar4 == 0) {
            local_210 = *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 * 0x10 + 0xc);
            goto LAB_005509cc;
          }
          iVar2 = iVar2 + 1;
        }
      }
      if (jcs_err_switch != 0) {
        pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_00551858:
        printf(pcVar6,"_apmngr_jcs_cfg_parse",0x20c);
      }
    }
    else if (jcs_err_switch != 0) {
      pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
      goto LAB_00551858;
    }
  }
  if (jcs_err_switch == 0) {
    local_210 = 0xffffffff;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_cfg_parse",
           0x20c);
    local_210 = 0xffffffff;
  }
LAB_005509cc:
  iVar1 = json_object_object_get(param_1,"led");
  local_148 = 1;
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
      local_148 = atoi(pcVar6);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_cfg_parse",0x20f);
      }
      if (jcs_err_switch == 0) {
        local_148 = -1;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_cfg_parse",
               0x20f);
        local_148 = -1;
      }
    }
  }
  iVar1 = json_object_object_get(param_1,"telnet_status");
  if (iVar1 == 0) {
LAB_00550a68:
    local_fa = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_cfg_parse",0x212);
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_cfg_parse",
               0x212);
      }
      goto LAB_00550a68;
    }
    pcVar6 = (char *)json_object_get_string(iVar1);
    iVar1 = atoi(pcVar6);
    local_fa = (undefined1)iVar1;
  }
  iVar1 = json_object_object_get(param_1,"led_wifi_sync");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_cfg_parse",0x215);
    }
    strncpy(acStack_404,"",0x7f);
    local_385 = 0;
    if (iVar1 != 0) goto LAB_00550ac4;
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
    strncpy(acStack_404,pcVar6,0x7f);
LAB_00550ac4:
    local_385 = 0;
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      iVar2 = 0;
      while (iVar2 < onoff_map) {
        pcVar6 = *(char **)(PTR__mt_onoff_00731f8c + iVar2 * 0x10);
        if (pcVar6 == (char *)0x0) {
          iVar2 = iVar2 + 1;
        }
        else {
          pcVar3 = (char *)json_object_get_string(iVar1);
          iVar4 = strcmp(pcVar6,pcVar3);
          if (iVar4 == 0) {
            local_1d0 = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 * 0x10 + 0xc);
            goto LAB_00550afc;
          }
          iVar2 = iVar2 + 1;
        }
      }
      if (jcs_err_switch != 0) {
        pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0055183c:
        printf(pcVar6,"_apmngr_jcs_cfg_parse",0x216);
      }
    }
    else if (jcs_err_switch != 0) {
      pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
      goto LAB_0055183c;
    }
  }
  if (jcs_err_switch == 0) {
    local_1d0 = 0xff;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_cfg_parse",
           0x216);
    local_1d0 = 0xff;
  }
LAB_00550afc:
  iVar1 = json_object_object_get(param_1,"led_timer_enable");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      iVar2 = 0;
      while (iVar2 < onoff_map) {
        pcVar6 = *(char **)(PTR__mt_onoff_00731f8c + iVar2 * 0x10);
        if (pcVar6 == (char *)0x0) {
          iVar2 = iVar2 + 1;
        }
        else {
          pcVar3 = (char *)json_object_get_string(iVar1);
          iVar4 = strcmp(pcVar6,pcVar3);
          if (iVar4 == 0) {
            local_144 = (char)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar2 * 0x10 + 0xc);
            goto LAB_00550b50;
          }
          iVar2 = iVar2 + 1;
        }
      }
      if (jcs_err_switch != 0) {
        pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_00551820:
        printf(pcVar6,"_apmngr_jcs_cfg_parse",0x219);
      }
    }
    else if (jcs_err_switch != 0) {
      pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
      goto LAB_00551820;
    }
  }
  if (jcs_err_switch == 0) {
    local_144 = -1;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_cfg_parse",
           0x219);
    local_144 = -1;
  }
LAB_00550b50:
  if (local_144 == '\0') {
    local_142 = 0;
    local_140 = 0;
    local_143 = 7;
    local_13f = 7;
    local_13e = 0;
    local_13c = 0;
  }
  else {
    iVar1 = json_object_object_get(param_1,"led_close_date");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_cfg_parse",0x21e);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_404,pcVar6,0x7f);
    local_385 = 0;
    local_143 = apmngr_db_date_parse(acStack_404);
    iVar1 = json_object_object_get(param_1,"led_close_time");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_cfg_parse",0x222);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_404,pcVar6,0x7f);
    local_385 = 0;
    apmngr_db_time_parse(acStack_404,&local_142);
    iVar1 = json_object_object_get(param_1,"led_open_date");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_cfg_parse",0x226);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_404,pcVar6,0x7f);
    local_385 = 0;
    local_13f = apmngr_db_date_parse(acStack_404);
    iVar1 = json_object_object_get(param_1,"led_open_time");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_cfg_parse",0x22a);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_404,pcVar6,0x7f);
    local_385 = 0;
    apmngr_db_time_parse(acStack_404,&local_13e);
  }
  iVar1 = json_object_object_get(param_1,"bluetooth_enable");
  if (iVar1 == 0) {
LAB_00550d28:
    local_1cf = -1;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_cfg_parse",0x236);
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_cfg_parse",
               0x236);
      }
      goto LAB_00550d28;
    }
    pcVar6 = (char *)json_object_get_string(iVar1);
    iVar1 = atoi(pcVar6);
    local_1cf = (char)iVar1;
  }
  iVar1 = json_object_object_get(param_1,"fit_fat_button_status");
  if (iVar1 == 0) {
LAB_00550d74:
    local_14c = 0xff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_cfg_parse",0x239);
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_cfg_parse",
               0x239);
      }
      goto LAB_00550d74;
    }
    pcVar6 = (char *)json_object_get_string(iVar1);
    iVar1 = atoi(pcVar6);
    local_14c = (undefined1)iVar1;
  }
  if (local_1cf == '\x01') {
    iVar1 = json_object_object_get(param_1,"account_username");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_cfg_parse",0x23e);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_1ce,pcVar6,0x40);
    local_18e = 0;
    iVar1 = json_object_object_get(param_1,"account_password");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_cfg_parse",0x241);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_18d,pcVar6,0x40);
    local_14d = 0;
  }
  else {
    iVar1 = json_object_object_get(param_1,"account_username");
    if (iVar1 == 0) {
      pcVar6 = "admin";
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar6 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_apmngr_jcs_cfg_parse",0x246);
        }
        pcVar6 = "";
      }
    }
    strncpy(acStack_1ce,pcVar6,0x40);
    local_18e = 0;
  }
  iVar1 = json_object_object_get(param_1,"username");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_cfg_parse",0x24a);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_20c,pcVar6,0x1f);
  local_1ed = 0;
  iVar1 = json_object_object_get(param_1,"password");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_cfg_parse",0x24d);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_1ec,pcVar6,0xf);
  local_1dd = 0;
  local_1dc = -1;
  iVar1 = json_object_object_get(param_1,"ap_trunk");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_cfg_parse",0x252);
      }
      pcVar6 = "";
    }
    strncpy(acStack_404,pcVar6,0x7f);
    local_385 = 0;
    local_1dc = atoi(acStack_404);
  }
  ppuVar12 = &APMNGR_CFG_PHY_WIRE_VLAN;
  puVar7 = APMNGR_CFG_PHY_WIRE_VLAN;
  iVar1 = 0;
  while (iVar2 = json_object_object_get(param_1,puVar7), iVar2 != 0) {
    iVar4 = json_object_get_type(iVar2);
    if (iVar4 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar2);
    }
    else {
      pcVar6 = "";
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_cfg_parse",0x25d);
      }
    }
    ppuVar12 = ppuVar12 + 1;
    strncpy(acStack_404,pcVar6,0x7f);
    local_385 = 0;
    iVar2 = atoi(acStack_404);
    *(short *)((int)local_1d8 + iVar1) = (short)iVar2;
    if (iVar1 + 2 == 8) break;
    puVar7 = *ppuVar12;
    iVar1 = iVar1 + 2;
  }
  iVar1 = json_object_object_get(param_1,"ap_mesh_switch");
  if (iVar1 == 0) {
    local_f9 = 0;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
      iVar1 = atoi(pcVar6);
      local_f9 = (undefined1)iVar1;
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_apmngr_jcs_cfg_parse",0x263);
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_apmngr_jcs_cfg_parse",
               0x263);
      }
      local_f9 = 0xff;
    }
  }
  iVar1 = json_object_object_get(param_1,"entry_type");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_entry_add",0x341);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy((char *)local_384,pcVar6,0x7f);
  local_305 = 0;
  local_2c4 = 1;
  local_2e8 = 0xffff;
  FUN_00407e80("_apmngr_jcs_entry_add");
  iVar1 = strcmp((char *)local_384,"ap");
  if (iVar1 == 0) {
    iVar1 = json_object_object_get(param_1,"mac");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_entry_add",0x34a);
      }
      pcVar6 = "";
    }
    else {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    strncpy((char *)local_384,pcVar6,0x7f);
    pbVar5 = local_384;
    local_305 = 0;
    iVar1 = 0;
    do {
      pcVar6 = local_2b8 + iVar1;
      uVar10 = *pbVar5 - 0x31 & 0xff;
      cVar9 = '\0';
      if (uVar10 < 0x36) {
        cVar9 = (&DAT_006cefd4)[uVar10];
      }
      *pcVar6 = cVar9 * '\x10';
      uVar10 = pbVar5[1] - 0x31 & 0xff;
      cVar11 = '\0';
      if (uVar10 < 0x36) {
        cVar11 = (&DAT_006cefd4)[uVar10];
      }
      iVar1 = iVar1 + 1;
      *pcVar6 = cVar11 + cVar9 * '\x10';
      pbVar5 = pbVar5 + 3;
    } while (iVar1 != 6);
    iVar1 = apdb_is_hdap_by_id(local_2c0,auStack_e8);
    if (iVar1 == 0) {
      iVar1 = 1;
      if (local_2ec == 7) {
        iVar1 = 3;
      }
    }
    else {
      iVar1 = 2;
      apmngr_hdap_peer_mac_get(local_2b8,&local_420);
    }
    iVar2 = apmngr_db_is_ap_exceed(iVar1,1);
    if (iVar2 == 0) {
      iVar2 = apmngr_db_entry_get_by_mac(local_2b8,0);
      if (iVar2 == 0) {
        if (apmngr_warning_switch != '\0') {
          iVar1 = is_target_debug_ap();
          uVar8 = 0x36b;
          if (iVar1 != 0) {
            pcVar6 = 
            "[APMNGR_WARNING]%s()/%d Cannot create ap entry because mac conflict with an existed entry.\n"
            ;
LAB_00551eb8:
            printf(pcVar6,"_apmngr_jcs_entry_add",uVar8);
          }
        }
      }
      else {
        if (iVar1 != 2) {
          iVar2 = apmngr_ap_add(auStack_300,auStack_e8,0,0,1);
          goto LAB_0055108c;
        }
        iVar1 = apmngr_db_entry_get_by_mac(&local_420,0);
        if (iVar1 != 0) {
          iVar2 = apmngr_hdap_add(auStack_300,auStack_e8,&local_420,0,1);
          goto LAB_0055108c;
        }
        if (apmngr_warning_switch != '\0') {
          iVar1 = is_target_debug_ap();
          uVar8 = 0x374;
          if (iVar1 != 0) {
            pcVar6 = 
            "[APMNGR_WARNING]%s()/%d Cannot create ap entry because hdap-peer-mac conflict with an existed entry.\n"
            ;
            goto LAB_00551eb8;
          }
        }
      }
      uVar8 = json_object_new_int(1);
      pcVar6 = "mac_conflict";
    }
    else {
      if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar6 = "[APMNGR_WARNING]%s()/%d Cannot create ap entry because ap is too many.\n";
        uVar8 = 0x363;
LAB_00551260:
        printf(pcVar6,"_apmngr_jcs_entry_add",uVar8);
      }
LAB_005514cc:
      uVar8 = json_object_new_int(1);
      pcVar6 = "ap_too_many";
    }
LAB_005514e0:
    json_object_object_add(param_2,pcVar6,uVar8);
    iVar2 = 0xffff;
  }
  else {
    iVar1 = strcmp((char *)local_384,"template");
    if (iVar1 == 0) {
      iVar1 = apmngr_db_is_template_exceed();
      if (iVar1 != 0) {
        if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar6 = 
          "[APMNGR_WARNING]%s()/%d Cannot create template entry because template is too many.\n";
          uVar8 = 0x38c;
          goto LAB_00551260;
        }
        goto LAB_005514cc;
      }
      iVar1 = apmngr_db_template_get(local_2c0,0);
      if (iVar1 == 0) {
        uVar8 = json_object_new_int(1);
        pcVar6 = "model_conflict";
        goto LAB_005514e0;
      }
      iVar2 = apmngr_template_add(auStack_300);
      iVar1 = json_object_object_get(param_1,"hardware_ver");
      if ((iVar1 == 0) || (iVar4 = json_object_get_type(iVar1), iVar4 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_apmngr_jcs_entry_add",0x399);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar1);
      }
      strncpy((char *)local_384,pcVar6,0x7f);
      local_305 = 0;
      apmngr_db_template_hwver_update(iVar2,0,local_384);
      apmngr_db_sync_template_hwver(iVar2,0,local_384);
      apmngr_db_datasync_template_hwver(iVar2,0,local_384);
      if (iVar2 != 0xffff) goto LAB_0055108c;
    }
    else if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Illegal ap type.\n","_apmngr_jcs_entry_add",0x3a2);
    }
    iVar2 = 0xffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Failed to create entry via jcs.\n","_apmngr_jcs_entry_add",0x3a7
            );
    }
  }
LAB_0055108c:
  uVar8 = json_object_new_int(iVar2);
  json_object_object_add(param_2,"entry_id",uVar8);
  FUN_004082b0(iVar2 != 0xffff,"_apmngr_jcs_entry_add");
  return;
}

