// func _wportal_page_add @ 00429844 size=3520

int _wportal_page_add(undefined4 param_1)

{
  char *__s2;
  int iVar1;
  uint uVar2;
  void *__src;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  char local_438 [240];
  uint local_348;
  undefined4 local_344;
  undefined4 local_340;
  int local_33c;
  undefined4 local_338;
  undefined4 local_334;
  undefined4 local_328;
  size_t local_324;
  char local_320 [16];
  uint local_310;
  char acStack_30c [127];
  undefined1 local_28d;
  char acStack_28c [127];
  undefined1 local_20d;
  char local_20c [127];
  undefined1 local_18d;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  char local_17c [289];
  undefined1 local_5b;
  uint local_58 [7];
  undefined1 local_39;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  uint local_24;
  
  memset(local_20c,0,0x80);
  memset(acStack_28c,0,0x80);
  memset(acStack_30c,0,0x80);
  local_324 = 0;
  local_320[0] = '\0';
  local_320[1] = '\0';
  local_320[2] = '\0';
  local_320[3] = '\0';
  local_320[4] = '\0';
  local_320[5] = '\0';
  local_320[6] = '\0';
  local_320[7] = '\0';
  local_320[8] = '\0';
  local_320[9] = '\0';
  local_320[10] = '\0';
  local_320[0xb] = '\0';
  local_320[0xc] = '\0';
  local_320[0xd] = '\0';
  local_320[0xe] = '\0';
  local_320[0xf] = '\0';
  local_310 = 0;
  local_328 = 0;
  if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Add portal page for mode: %d\n","_wportal_page_add",0x1e8b,
           g_portal_auth_mode);
  }
  memset(&local_18c,0,0x16c);
  if (g_portal_auth_mode == 1) {
    iVar3 = json_object_object_get(param_1,"vlan_id");
    if (iVar3 == 0) {
LAB_00429ea8:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_add",0x1e94);
      }
      local_58[0] = 0xffffffff;
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 3) {
        local_58[0] = json_object_get_int(iVar3);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 2) goto LAB_00429ea8;
        uVar8 = json_object_get_double(iVar3);
        local_58[0] = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      }
    }
    if (local_58[0] == 0) {
      local_58[0] = 0xfff;
    }
  }
  else if (g_portal_auth_mode == 0) {
    iVar3 = json_object_object_get(param_1,"serv_id");
    if (iVar3 == 0) {
LAB_00429bf0:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_add",0x1e9a);
      }
      local_58[0] = 0xffffffff;
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 3) {
        local_58[0] = json_object_get_int(iVar3);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 2) goto LAB_00429bf0;
        uVar8 = json_object_get_double(iVar3);
        local_58[0] = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      }
    }
  }
  else if (g_portal_auth_mode == 2) {
    iVar3 = json_object_object_get(param_1,"interface");
    if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_add",0x1e9f);
      }
      pcVar5 = "";
    }
    else {
      pcVar5 = (char *)json_object_get_string(iVar3);
    }
    strncpy((char *)local_58,pcVar5,0x1f);
    local_39 = 0;
  }
  iVar3 = json_object_object_get(param_1,"fail_url");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_page_add",0x1ea4);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar3);
  }
  strncpy(local_20c,pcVar5,0x7f);
  local_18d = 0;
  if (local_20c[0] != '\0') {
    memcpy(&local_18c,local_20c,0x80);
    iVar3 = json_object_object_get(param_1,"fail_id");
    if (iVar3 == 0) {
LAB_00429b7c:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_add",0x1eab);
      }
      local_38 = 0xffffffff;
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 3) {
        local_38 = json_object_get_int(iVar3);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 2) goto LAB_00429b7c;
        uVar8 = json_object_get_double(iVar3);
        local_38 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      }
    }
  }
  iVar3 = json_object_object_get(param_1,"auth_type");
  if (iVar3 == 0) {
LAB_00429998:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_page_add",0x1eaf);
    }
    local_30 = -1;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      local_30 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_00429998;
      uVar8 = json_object_get_double(iVar3);
      local_30 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  if (local_30 != 0x10) {
    if (local_30 != 0x20) {
      if (local_30 != 0x40) goto LAB_004299dc;
      iVar3 = json_object_object_get(param_1,"id");
      if (iVar3 == 0) {
LAB_0042a0c0:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_wportal_page_add",0x1ece);
        }
        local_34 = 0xffffffff;
      }
      else {
        iVar4 = json_object_get_type(iVar3);
        if (iVar4 == 3) {
          local_34 = json_object_get_int(iVar3);
        }
        else {
          iVar4 = json_object_get_type();
          if (iVar4 != 2) goto LAB_0042a0c0;
          uVar8 = json_object_get_double(iVar3);
          local_34 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
      }
      iVar3 = json_object_object_get(param_1,"cloud_portal_url");
      if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_wportal_page_add",0x1ed1);
        }
        pcVar5 = "";
      }
      else {
        pcVar5 = (char *)json_object_get_string(iVar3);
      }
      strncpy(acStack_28c,pcVar5,0x7f);
      local_20d = 0;
      memcpy(local_17c + 0x70,acStack_28c,0x80);
      wportal_update_cloud_portal_url(acStack_28c);
      goto LAB_004299dc;
    }
    iVar3 = json_object_object_get(param_1,"id");
    if (iVar3 == 0) {
LAB_00429f44:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_page_add",0x1ebd);
      }
      local_34 = 0xffffffff;
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 3) {
        local_34 = json_object_get_int(iVar3);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 2) goto LAB_00429f44;
        uVar8 = json_object_get_double(iVar3);
        local_34 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      }
    }
    iVar3 = json_object_object_get(param_1,"cmcc_url");
    if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_add",0x1ec0);
      }
      pcVar5 = "";
    }
    else {
      pcVar5 = (char *)json_object_get_string(iVar3);
    }
    strncpy(acStack_30c,pcVar5,0x7f);
    local_28d = 0;
    __src = (void *)wportal_url_get_domain(acStack_30c,&local_324);
    memcpy(local_17c + 0x70,__src,local_324);
    iVar3 = json_object_object_get(param_1,"cmcc_auth_server_type");
    if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_add",0x1ec5);
      }
      pcVar5 = "";
    }
    else {
      pcVar5 = (char *)json_object_get_string(iVar3);
    }
    strncpy(local_320,pcVar5,0x13);
    local_310 = local_310 & 0xffffff00;
    local_2c = _wportal_auth_server_type_str2int(local_320);
    iVar3 = json_object_object_get(param_1,"cmcc_ac_name");
    if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_page_add",0x1ec9);
      }
      pcVar5 = "";
    }
    else {
      pcVar5 = (char *)json_object_get_string(iVar3);
    }
    strncpy(local_17c + 0xf0,pcVar5,0x31);
    local_5b = 0;
    goto LAB_004299dc;
  }
  iVar3 = json_object_object_get(param_1,"id");
  if (iVar3 == 0) {
LAB_00429d7c:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_page_add",0x1eb4);
    }
    local_34 = 0xffffffff;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      local_34 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_00429d7c;
      uVar8 = json_object_get_double(iVar3);
      local_34 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
  }
  iVar3 = json_object_object_get(param_1,"remote_url");
  if ((iVar3 == 0) || (iVar4 = json_object_get_type(iVar3), iVar4 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_page_add",0x1eb7);
    }
    pcVar5 = "";
  }
  else {
    pcVar5 = (char *)json_object_get_string(iVar3);
  }
  strncpy(acStack_28c,pcVar5,0x7f);
  local_20d = 0;
  memcpy(local_17c + 0x70,acStack_28c,0x80);
LAB_004299dc:
  iVar3 = json_object_object_get(param_1,"portal_page_switch");
  local_24 = 1;
  if (iVar3 != 0) {
    iVar4 = json_object_get_type(iVar3);
    iVar7 = 0;
    if (iVar4 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar7) {
            if (jcs_err_switch == 0) goto LAB_00429a1c;
            pcVar5 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_00429c2c;
          }
          iVar4 = iVar7 * 0x10;
          pcVar5 = *(char **)(PTR__mt_onoff_00731f8c + iVar4);
          if (pcVar5 != (char *)0x0) break;
          iVar7 = iVar7 + 1;
        }
        __s2 = (char *)json_object_get_string(iVar3);
        iVar1 = strcmp(pcVar5,__s2);
        iVar7 = iVar7 + 1;
      } while (iVar1 != 0);
      local_24 = *(uint *)(PTR__mt_onoff_00731f8c + iVar4 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar5 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00429c2c:
        printf(pcVar5,"_wportal_page_add",0x1eda);
      }
LAB_00429a1c:
      if (jcs_err_switch == 0) {
        local_24 = 0xffffffff;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_wportal_page_add",
               0x1eda);
        local_24 = 0xffffffff;
      }
    }
  }
  if (g_portal_auth_mode == 1) {
    iVar3 = wportal_db_rdt_add(&local_18c);
    if (iVar3 == 0) {
      FUN_00419130(&local_18c,1);
      _wportal_update_portal_to_ap(&local_18c,2);
      if (local_18c._0_1_ != '\0') {
        for (uVar2 = 0; uVar2 < 0x80; uVar2 = uVar2 + 1) {
          local_438[uVar2 + 0x70] = local_17c[uVar2 + 0x70];
        }
        local_348 = local_58[0];
        local_344 = local_38;
        local_340 = local_34;
        local_33c = local_30;
        local_338 = 1;
        local_334 = 1;
        for (uVar2 = 0; uVar2 < 0x70; uVar2 = uVar2 + 1) {
          local_438[uVar2] = local_17c[uVar2];
        }
        FUN_00416a5c(local_18c,local_188,local_184,local_180);
      }
      if (local_17c[0x70] != '\0') {
        for (uVar2 = 0; uVar2 < 0x80; uVar2 = uVar2 + 1) {
          local_438[uVar2 + 0x70] = local_17c[uVar2 + 0x70];
        }
        local_348 = local_58[0];
        local_344 = local_38;
        local_340 = local_34;
        local_33c = local_30;
        local_338 = 2;
        local_334 = 1;
        for (uVar2 = 0; uVar2 < 0x70; uVar2 = uVar2 + 1) {
          local_438[uVar2] = local_17c[uVar2];
        }
        FUN_00416a5c(local_18c,local_188,local_184,local_180);
      }
    }
  }
  else if (g_portal_auth_mode == 0) {
    if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Add rdt entry for ssid: %d\n\n","_wportal_page_add",0x1efb,
             local_58[0]);
    }
    local_328 = 1;
    wserv_db_entry_for_each_rd(local_58[0],_wportal_wserv_modify_rdt,&local_328);
    iVar3 = wportal_db_ssid_rdt_add(&local_18c);
    if (iVar3 == 0) {
      wserv_db_entry_set_ssid_portal_switch(local_58[0] & 0xff,local_24 & 0xff);
      iVar3 = wserv_db_entry_for_each_rd(local_58[0],_wportal_wserv_update_rdt,&local_18c);
    }
  }
  else {
    iVar3 = 0;
    if (g_portal_auth_mode == 2) {
      if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Add rdt entry for interface: %s\n\n","_wportal_page_add",0x1f0c
               ,local_58);
      }
      iVar3 = wportal_db_iface_add(&local_18c);
      if (iVar3 == 0) {
        if (wportal_debug_switch == 0) {
          return 0;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0;
        }
        pcVar5 = "[WPORTAL_DBG]%s()/%d Add iface entry for interface success \n\n";
        uVar6 = 0x1f15;
      }
      else {
        if (wportal_debug_switch == 0) {
          return iVar3;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return iVar3;
        }
        pcVar5 = "[WPORTAL_DBG]%s()/%d Add iface entry for interface error \n\n";
        uVar6 = 0x1f11;
      }
      printf(pcVar5,"_wportal_page_add",uVar6);
    }
  }
  return iVar3;
}

