// func _wportal_wserv_unbind_notify @ 00415208 size=1632

undefined4 _wportal_wserv_unbind_notify(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char local_6b0 [240];
  int local_5c0;
  int local_5bc;
  undefined4 local_5b8;
  uint local_5b4;
  undefined4 local_5b0;
  undefined4 local_5ac;
  int local_5a8;
  undefined4 local_598;
  undefined4 local_594;
  int *local_590;
  int *local_58c;
  int local_588;
  char acStack_584 [128];
  int local_504;
  char acStack_500 [128];
  char local_480;
  undefined1 auStack_47c [12];
  undefined4 local_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 local_464;
  char local_460 [292];
  int local_33c;
  int local_31c;
  int local_318;
  undefined4 local_314;
  undefined1 auStack_300 [64];
  undefined4 local_2c0;
  undefined1 auStack_e8 [196];
  
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d enter _wportal_wserv_unbind_notify\n",
           "_wportal_wserv_unbind_notify",0x2de8);
  }
  local_598 = 0;
  local_594 = 0;
  local_590 = (int *)0x0;
  local_58c = (int *)0x0;
  memset(&local_588,0,0x84);
  memset(&local_470,0,0x16c);
  memset(auStack_300,0,0x2d8);
  iVar1 = apmngr_db_get_ap_max();
  if (iVar1 <= (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((int)param_1 < iVar1 + iVar2) {
      return 0;
    }
  }
  memset(&local_470,0,0x16c);
  local_598 = 0;
  local_594 = 0;
  local_590 = (int *)0x0;
  local_58c = (int *)0x0;
  memset(&local_588,0,0x84);
  memset(&local_504,0,0x94);
  local_5b4 = param_1;
  if (g_portal_auth_mode == 1) {
    if (0 < param_4) {
      return 0;
    }
    iVar1 = 0xfff;
    if (param_2 != 0) {
      iVar1 = param_2;
    }
    iVar2 = wportal_db_rdt_get_by_vlan(iVar1,&local_470);
    if (iVar2 != 0) {
      return 0;
    }
    if (local_33c == 0) {
      return 0;
    }
    local_6b0[0] = '\0';
    local_6b0[1] = '\0';
    local_6b0[2] = '\0';
    local_6b0[3] = 'd';
    snprintf(acStack_584,0x80,"http://192.168.1.253:%d/wportal/?pagetype=%d",g_portal_port);
    local_6b0[0] = '\0';
    local_6b0[1] = '\0';
    local_6b0[2] = '\0';
    local_6b0[3] = 'd';
    snprintf(acStack_500,0x80,"http://192.168.1.253:%d/wportal/?pagetype=%d",g_portal_port);
    local_590 = &local_588;
    local_598 = 3;
    local_588 = iVar1;
    local_504 = iVar1;
    FUN_0051ad88(auStack_47c);
    local_480 = -1;
    local_594 = 0x19;
    local_58c = &local_504;
    _wportal_update_wportal_cb(param_1,&local_598);
    if ((local_318 != 0) && (uVar3 = 0, local_460[0x70] != '\0')) {
      for (; uVar3 < 0x80; uVar3 = uVar3 + 1) {
        local_6b0[uVar3 + 0x70] = local_460[uVar3 + 0x70];
      }
      local_5bc = local_318;
      local_5b8 = local_314;
      local_5c0 = local_31c;
      local_5b0 = 2;
      local_5ac = 2;
      local_5a8 = local_33c;
      for (uVar3 = 0; uVar3 < 0x70; uVar3 = uVar3 + 1) {
        local_6b0[uVar3] = local_460[uVar3];
      }
      FUN_00413e94(local_470,local_46c,local_468,local_464);
    }
    if (local_31c == 0) {
      return 0;
    }
    if (local_470._0_1_ == '\0') {
      return 0;
    }
    for (uVar3 = 0; uVar3 < 0x80; uVar3 = uVar3 + 1) {
      local_6b0[uVar3 + 0x70] = local_460[uVar3 + 0x70];
    }
    local_5bc = local_318;
    local_5b8 = local_314;
    local_5b0 = 1;
    local_5a8 = local_33c;
    for (uVar3 = 0; local_5c0 = local_31c, uVar3 < 0x70; uVar3 = uVar3 + 1) {
      local_6b0[uVar3] = local_460[uVar3];
    }
    goto LAB_00415740;
  }
  iVar1 = wportal_db_ssid_rdt_get(param_3,&local_470);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = _wportal_db_support_new_portal_by_id(param_1);
  if ((iVar1 == 0) && (param_4 == 0)) {
    local_6b0[0] = '\0';
    local_6b0[1] = '\0';
    local_6b0[2] = '\0';
    local_6b0[3] = 'd';
    snprintf(acStack_584,0x80,"http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",
             g_portal_port);
    local_590 = &local_588;
    local_588 = 0xfff;
    if (param_2 != 0) {
      local_588 = param_2;
    }
    local_598 = 3;
LAB_00415540:
    _wportal_update_wportal_cb(param_1,&local_598);
  }
  else {
    iVar1 = _wportal_db_support_new_portal_by_id(param_1);
    if (iVar1 != 0) {
      if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d _wportal_db_support_new_portal_by_id is true\n",
               "_wportal_wserv_unbind_notify",0x2e3f);
      }
      local_6b0[0] = '\0';
      local_6b0[1] = '\0';
      local_6b0[2] = '\0';
      local_6b0[3] = 'd';
      snprintf(acStack_500,0x80,"http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",
               g_portal_port);
      local_504 = 0xfff;
      if (param_2 != 0) {
        local_504 = param_2;
      }
      FUN_0051ad88(auStack_47c);
      if (param_2 == 0xfff) {
        param_2 = 0;
      }
      uac_wservice_for_ap_bind_vlan(param_2,param_1,_wportal_collect_ssid_info_cb,auStack_47c);
      local_480 = FUN_00407fe0(auStack_47c);
      local_594 = 0x1a;
      if (local_480 != '\0') {
        local_594 = 0x19;
      }
      local_58c = &local_504;
      goto LAB_00415540;
    }
  }
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_300);
  if (iVar1 == 0) {
    uVar3 = 1;
    iVar1 = apdb_radio_count_by_id(local_2c0,auStack_e8);
    while ((int)uVar3 <= iVar1) {
      iVar2 = uac_wservice_is_wserv_bind_to_rd(param_1,uVar3 & 0xff,param_3);
      uVar3 = uVar3 + 1;
      if (iVar2 == 1) {
        return 0;
      }
    }
  }
  else {
  }
  if (local_470._0_1_ != '\0') {
    for (uVar3 = 0; uVar3 < 0x80; uVar3 = uVar3 + 1) {
      local_6b0[uVar3 + 0x70] = local_460[uVar3 + 0x70];
    }
    local_5c0 = local_31c;
    local_5bc = local_318;
    local_5b8 = local_314;
    local_5b0 = 1;
    local_5ac = 2;
    local_5a8 = 0xffffffff;
    for (uVar3 = 0; uVar3 < 0x70; uVar3 = uVar3 + 1) {
      local_6b0[uVar3] = local_460[uVar3];
    }
    FUN_00413e94(local_470,local_46c,local_468,local_464);
  }
  if (local_460[0x70] == '\0') {
    return 0;
  }
  for (uVar3 = 0; uVar3 < 0x80; uVar3 = uVar3 + 1) {
    local_6b0[uVar3 + 0x70] = local_460[uVar3 + 0x70];
  }
  local_5c0 = local_31c;
  local_5bc = local_318;
  local_5b8 = local_314;
  local_5b0 = 2;
  local_5a8 = -1;
  for (uVar3 = 0; uVar3 < 0x70; uVar3 = uVar3 + 1) {
    local_6b0[uVar3] = local_460[uVar3];
  }
LAB_00415740:
  local_5ac = 2;
  local_5b4 = param_1;
  FUN_00413e94(local_470,local_46c,local_468,local_464);
  return 0;
}

