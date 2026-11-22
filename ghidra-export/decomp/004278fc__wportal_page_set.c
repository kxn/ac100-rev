// func _wportal_page_set @ 004278fc size=4832

int _wportal_page_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *__s2;
  int iVar4;
  void *__src;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  char local_5b0 [240];
  uint local_4c0;
  undefined4 local_4bc;
  undefined4 local_4b8;
  int local_4b4;
  undefined4 local_4b0;
  undefined4 local_4ac;
  uint local_4a0;
  size_t local_49c;
  char local_498 [16];
  uint local_488;
  char acStack_484 [127];
  undefined1 local_405;
  char acStack_404 [127];
  undefined1 local_385;
  char local_384 [127];
  undefined1 local_305;
  char local_304 [128];
  char local_284 [180];
  undefined4 local_1d0;
  uint local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  char local_188 [289];
  undefined1 local_67;
  uint local_64 [7];
  undefined1 local_45;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  uint local_30;
  
  memset(local_384,0,0x80);
  memset(acStack_404,0,0x80);
  memset(acStack_484,0,0x80);
  local_49c = 0;
  local_498[0] = '\0';
  local_498[1] = '\0';
  local_498[2] = '\0';
  local_498[3] = '\0';
  local_498[4] = '\0';
  local_498[5] = '\0';
  local_498[6] = '\0';
  local_498[7] = '\0';
  local_498[8] = '\0';
  local_498[9] = '\0';
  local_498[10] = '\0';
  local_498[0xb] = '\0';
  local_498[0xc] = '\0';
  local_498[0xd] = '\0';
  local_498[0xe] = '\0';
  local_498[0xf] = '\0';
  local_488 = 0;
  memset(&local_198,0,0x16c);
  memset(local_304,0,0x16c);
  if (g_portal_auth_mode == 1) {
    iVar1 = json_object_object_get(param_1,"vlan_id");
    if (iVar1 == 0) {
LAB_00427c30:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x208e);
      }
      local_64[0] = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_64[0] = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00427c30;
        uVar10 = json_object_get_double(iVar1);
        local_64[0] = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
    }
    if (local_64[0] == 0) {
      local_64[0] = 0xfff;
    }
    iVar1 = json_object_object_get(param_1,"old_vlan_id");
    if (iVar1 == 0) {
LAB_00427c98:
      if (jcs_err_switch == 0) {
        uVar9 = 0xffffffff;
      }
      else {
        uVar9 = 0xffffffff;
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x2092);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar9 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00427c98;
        uVar10 = json_object_get_double(iVar1);
        uVar9 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
      if (uVar9 == 0) {
        uVar9 = 0xfff;
      }
    }
  }
  else if (g_portal_auth_mode == 0) {
    iVar1 = json_object_object_get(param_1,"serv_id");
    if (iVar1 == 0) {
LAB_00427b2c:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x2098);
      }
      local_64[0] = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_64[0] = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00427b2c;
        uVar10 = json_object_get_double(iVar1);
        local_64[0] = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
    }
    uVar9 = 0;
  }
  else {
    uVar9 = 0;
    if (g_portal_auth_mode == 2) {
      iVar1 = json_object_object_get(param_1,"interface");
      if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_wportal_page_set",0x209d);
        }
        uVar9 = 0;
        strncpy((char *)local_64,"",0x1f);
        local_45 = 0;
      }
      else {
        pcVar3 = (char *)json_object_get_string(iVar1);
        strncpy((char *)local_64,pcVar3,0x1f);
        local_45 = 0;
      }
    }
  }
  iVar1 = json_object_object_get(param_1,"is_escape");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar7 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar10 = json_object_get_double(iVar1);
        uVar7 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
      else {
        uVar7 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_wportal_page_set",0x20a4);
        }
      }
    }
    if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Do escape change: %d\n\n","_wportal_page_set",0x20a5,uVar7);
    }
    if (1 < uVar7) {
      return -1;
    }
    local_4a0 = 0;
    if (g_portal_auth_mode == 1) {
      if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Set rdt entry for vlan: %d\n\n","_wportal_page_set",0x2141,
               local_64[0]);
      }
      wportal_db_rdt_get_by_vlan(uVar9,local_304);
      if (local_1a0 == uVar7) {
        return -1;
      }
      local_1a0 = uVar7;
      wportal_db_rdt_set(local_304);
      local_4a0 = (uint)(local_1a0 == 0);
      uVar9 = local_64[0];
      if (local_64[0] == 0xfff) {
        uVar9 = 0;
      }
      uac_wservice_for_each_bind_vlan(uVar9,_wportal_wserv_modify_rdt_for_escape_exit,&local_4a0);
      return -1;
    }
    if (g_portal_auth_mode != 0) {
      return 0;
    }
    if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(local_64[0]), iVar1 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Set rdt entry for ssid: %d\n\n","_wportal_page_set",0x2158,
             local_64[0]);
    }
    iVar1 = wportal_db_ssid_rdt_get(local_64[0],local_304);
    if (iVar1 == 0) {
      if (local_1a0 == uVar7) {
        return 0;
      }
      local_1a0 = uVar7;
      wportal_db_ssid_rdt_set(local_64[0],local_304);
      local_4a0 = (uint)(local_1a0 == 0);
      if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        local_5b0[0] = '\0';
        local_5b0[1] = '\0';
        local_5b0[2] = '\0';
        local_5b0[3] = '\0';
        printf("[WPORTAL_DBG]%s()/%d op: %d WPORTAL_AP_EVENT_ADD_USER is %d \n\n",
               "_wportal_page_set",0x2171,local_4a0);
      }
      wserv_db_entry_for_each_rd(local_64[0],_wportal_wserv_modify_rdt_for_escape_exit,&local_4a0);
      return 0;
    }
    if (wportal_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    uVar6 = 0x215d;
    goto LAB_00427f04;
  }
  iVar1 = json_object_object_get(param_1,"fail_url");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_page_set",0x20ab);
    }
    pcVar3 = "";
  }
  else {
    pcVar3 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_384,pcVar3,0x7f);
  local_305 = 0;
  if (local_384[0] != '\0') {
    memcpy(&local_198,local_384,0x80);
    iVar1 = json_object_object_get(param_1,"fail_id");
    if (iVar1 == 0) {
LAB_00428010:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20b1);
      }
      local_44 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_44 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00428010;
        uVar10 = json_object_get_double(iVar1);
        local_44 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
    }
  }
  iVar1 = json_object_object_get(param_1,"auth_type");
  if (iVar1 == 0) {
LAB_00427e08:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_page_set",0x20b5);
    }
    local_3c = -1;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_3c = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_00427e08;
      uVar10 = json_object_get_double(iVar1);
      local_3c = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
    }
  }
  if (local_3c == 0x10) {
    iVar1 = json_object_object_get(param_1,"id");
    if (iVar1 == 0) {
LAB_00428444:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20ba);
      }
      local_40 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_40 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00428444;
        uVar10 = json_object_get_double(iVar1);
        local_40 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
    }
    iVar1 = json_object_object_get(param_1,"remote_url");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20bd);
      }
      pcVar3 = "";
    }
    else {
      pcVar3 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_404,pcVar3,0x7f);
    local_385 = 0;
    memcpy(local_188 + 0x70,acStack_404,0x80);
  }
  else if (local_3c == 0x20) {
    iVar1 = json_object_object_get(param_1,"id");
    if (iVar1 == 0) {
LAB_00428558:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20c3);
      }
      local_40 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_40 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00428558;
        uVar10 = json_object_get_double(iVar1);
        local_40 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
    }
    iVar1 = json_object_object_get(param_1,"cmcc_url");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20c6);
      }
      pcVar3 = "";
    }
    else {
      pcVar3 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_484,pcVar3,0x7f);
    local_405 = 0;
    __src = (void *)wportal_url_get_domain(acStack_484,&local_49c);
    memcpy(local_188 + 0x70,__src,local_49c);
    iVar1 = json_object_object_get(param_1,"cmcc_auth_server_type");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20cb);
      }
      pcVar3 = "";
    }
    else {
      pcVar3 = (char *)json_object_get_string(iVar1);
    }
    strncpy(local_498,pcVar3,0x13);
    local_488 = local_488 & 0xffffff00;
    local_38 = _wportal_auth_server_type_str2int(local_498);
    iVar1 = json_object_object_get(param_1,"cmcc_ac_name");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20cf);
      }
      pcVar3 = "";
    }
    else {
      pcVar3 = (char *)json_object_get_string(iVar1);
    }
    strncpy(local_188 + 0xf0,pcVar3,0x31);
    local_67 = 0;
  }
  else if (local_3c == 0x40) {
    iVar1 = json_object_object_get(param_1,"id");
    if (iVar1 == 0) {
LAB_00428110:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20d5);
      }
      local_40 = 0xffffffff;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_40 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00428110;
        uVar10 = json_object_get_double(iVar1);
        local_40 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
    }
    iVar1 = json_object_object_get(param_1,"cloud_portal_url");
    if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_set",0x20d8);
      }
      pcVar3 = "";
    }
    else {
      pcVar3 = (char *)json_object_get_string(iVar1);
    }
    strncpy(acStack_404,pcVar3,0x7f);
    local_385 = 0;
    memcpy(local_188 + 0x70,acStack_404,0x80);
    wportal_update_cloud_portal_url(acStack_404);
  }
  iVar1 = json_object_object_get(param_1,"portal_page_switch");
  local_30 = 1;
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    iVar8 = 0;
    if (iVar2 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar8) {
            if (jcs_err_switch == 0) goto LAB_00427e88;
            pcVar3 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004283f0;
          }
          iVar2 = iVar8 * 0x10;
          pcVar3 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
          if (pcVar3 != (char *)0x0) break;
          iVar8 = iVar8 + 1;
        }
        __s2 = (char *)json_object_get_string(iVar1);
        iVar4 = strcmp(pcVar3,__s2);
        iVar8 = iVar8 + 1;
      } while (iVar4 != 0);
      local_30 = *(uint *)(PTR__mt_onoff_00731f8c + iVar2 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar3 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004283f0:
        printf(pcVar3,"_wportal_page_set",0x20e1);
      }
LAB_00427e88:
      if (jcs_err_switch == 0) {
        local_30 = 0xffffffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_wportal_page_set",
               0x20e1);
        local_30 = 0xffffffff;
      }
    }
  }
  if (g_portal_auth_mode == 1) {
    if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Set rdt entry for vlan: %d\n\n","_wportal_page_set",0x20ea,
             local_64[0]);
    }
    wportal_db_rdt_get_by_vlan(uVar9,local_304);
    _wportal_update_portal_to_ap(local_304,3);
    wportal_db_rdt_del(uVar9);
    iVar1 = wportal_db_rdt_add(&local_198);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = _wportal_update_portal_to_ap(&local_198,2);
    uVar7 = local_64[0];
    if (iVar1 != 0) {
      return -1;
    }
    if ((local_64[0] != uVar9) || (iVar1 = strcmp((char *)&local_198,local_304), iVar1 != 0)) {
      if (local_304[0] != '\0') {
        for (uVar5 = 0; uVar5 < 0x80; uVar5 = uVar5 + 1) {
          local_5b0[uVar5 + 0x70] = local_188[uVar5 + 0x70];
        }
        local_4c0 = uVar7;
        local_4bc = local_44;
        local_4b8 = local_40;
        local_4b4 = local_3c;
        local_4b0 = 1;
        local_4ac = 2;
        for (uVar7 = 0; uVar7 < 0x70; uVar7 = uVar7 + 1) {
          local_5b0[uVar7] = local_188[uVar7];
        }
        FUN_00416a5c(local_198,local_194,local_190,local_18c);
      }
      uVar7 = 0;
      if (local_198._0_1_ != '\0') {
        for (; uVar7 < 0x80; uVar7 = uVar7 + 1) {
          local_5b0[uVar7 + 0x70] = local_188[uVar7 + 0x70];
        }
        local_4c0 = local_64[0];
        local_4bc = local_44;
        local_4b8 = local_40;
        local_4b4 = local_3c;
        local_4b0 = 1;
        local_4ac = 1;
        for (uVar7 = 0; uVar7 < 0x70; uVar7 = uVar7 + 1) {
          local_5b0[uVar7] = local_188[uVar7];
        }
        FUN_00416a5c(local_198,local_194,local_190,local_18c);
      }
    }
    uVar7 = local_64[0];
    if ((local_64[0] == uVar9) && (iVar1 = strcmp(local_188 + 0x70,local_284), iVar1 == 0)) {
      return 0;
    }
    if (local_284[0] != '\0') {
      for (uVar9 = 0; uVar9 < 0x80; uVar9 = uVar9 + 1) {
        local_5b0[uVar9 + 0x70] = local_188[uVar9 + 0x70];
      }
      local_4bc = local_44;
      local_4b8 = local_40;
      local_4b4 = local_3c;
      local_4b0 = 2;
      local_4ac = 2;
      for (uVar9 = 0; uVar9 < 0x70; uVar9 = uVar9 + 1) {
        local_5b0[uVar9] = local_188[uVar9];
      }
      local_4c0 = uVar7;
      FUN_00416a5c(local_198,local_194,local_190,local_18c);
    }
    if (local_188[0x70] == '\0') {
      return 0;
    }
    for (uVar9 = 0; uVar9 < 0x80; uVar9 = uVar9 + 1) {
      local_5b0[uVar9 + 0x70] = local_188[uVar9 + 0x70];
    }
    local_4c0 = local_64[0];
    local_4bc = local_44;
    local_4b8 = local_40;
    local_4b4 = local_3c;
    local_4b0 = 2;
    local_4ac = 1;
    for (uVar9 = 0; uVar9 < 0x70; uVar9 = uVar9 + 1) {
      local_5b0[uVar9] = local_188[uVar9];
    }
    FUN_00416a5c(local_198,local_194,local_190,local_18c);
    return 0;
  }
  if (g_portal_auth_mode != 0) {
    if (g_portal_auth_mode != 2) {
      return -1;
    }
    iVar1 = wportal_db_iface_set(&local_198);
    if (wportal_debug_switch == 0) {
      return iVar1;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return iVar1;
    }
    printf("[WPORTAL_DBG]%s()/%d wportal_db_iface_del ret is : %d\n\n","_wportal_page_set",0x2137,
           iVar1);
    return iVar1;
  }
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(local_64[0]), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Set rdt entry for ssid: %d\n\n","_wportal_page_set",0x211d,
           local_64[0]);
  }
  iVar1 = wportal_db_ssid_rdt_get(local_64[0],local_304);
  if (iVar1 == 0) {
    wserv_db_entry_for_each_rd(local_1d0,_wportal_wserv_del_rdt_ftt,local_304);
    iVar1 = wportal_db_ssid_rdt_set(local_1d0,&local_198);
    if (iVar1 != 0) {
      return iVar1;
    }
    wserv_db_entry_set_ssid_portal_switch(local_64[0] & 0xff,local_30 & 0xff);
    iVar1 = wserv_db_entry_for_each_rd(local_64[0],_wportal_wserv_update_rdt,&local_198);
    return iVar1;
  }
  if (wportal_err_switch == 0) {
    return -1;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return -1;
  }
  uVar6 = 0x2122;
LAB_00427f04:
  printf("[WPORTAL_ERR]%s()/%d Could not find wserv for setting page.\n","_wportal_page_set",uVar6);
  return -1;
}

