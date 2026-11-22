// func _wportal_wserv_bind_notify @ 004148e0 size=1480

undefined4 _wportal_wserv_bind_notify(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *__format;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_3d8;
  int local_3d4;
  char local_368 [128];
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined4 local_2e0;
  uint local_2dc;
  undefined4 local_2d8;
  undefined4 local_2d4;
  int local_2d0;
  undefined4 local_2c0;
  undefined4 local_2bc;
  int *local_2b8;
  int *local_2b4;
  int local_2b0;
  char acStack_2ac [128];
  int local_22c;
  char acStack_228 [128];
  char local_1a8;
  undefined1 auStack_1a4 [12];
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  char local_188 [292];
  int local_64;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d enter _wportal_wserv_bind_notify\n","_wportal_wserv_bind_notify",
           0x2d5a);
  }
  memset(&local_198,0,0x16c);
  local_2c0 = 0;
  local_2bc = 0;
  local_2b8 = (int *)0x0;
  local_2b4 = (int *)0x0;
  iVar3 = 0;
  if ((g_portal_auth_mode == 1) && (iVar3 = 0xfff, param_2 != 0)) {
    iVar3 = param_2;
  }
  iVar1 = apmngr_db_get_ap_max();
  if (iVar1 <= (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((int)param_1 < iVar1 + iVar2) {
      return 0;
    }
  }
  memset(&local_198,0,0x16c);
  local_2c0 = 0;
  local_2bc = 0;
  local_2b8 = (int *)0x0;
  local_2b4 = (int *)0x0;
  memset(&local_2b0,0,0x84);
  memset(&local_22c,0,0x94);
  if (g_portal_auth_mode == 1) {
    if (1 < param_4) {
      return 0;
    }
    iVar1 = 0xfff;
    if (param_2 != 0) {
      iVar1 = param_2;
    }
    iVar1 = wportal_db_rdt_get_by_vlan(iVar1,&local_198);
    if (iVar1 != 0) {
      return 0;
    }
    if (local_64 == 0) {
      return 0;
    }
    local_3d8 = 100;
    snprintf(acStack_2ac,0x80,"http://192.168.1.253:%d/wportal/?pagetype=%d",g_portal_port);
    local_3d8 = 100;
    snprintf(acStack_228,0x80,"http://192.168.1.253:%d/wportal/?pagetype=%d",g_portal_port);
    FUN_0051ad88(auStack_1a4);
    local_1a8 = -1;
    local_2bc = 0x19;
LAB_00414c44:
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      local_3d8 = param_2;
      local_3d4 = param_3;
      printf("[WPORTAL_INFO]%s()/%d ap_id %d bind vlan_id %d wserv_id %d\n",
             "_wportal_wserv_bind_notify",0x2da8,param_1);
    }
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d url %s\n","_wportal_wserv_bind_notify",0x2da9,acStack_2ac);
    }
    local_2b0 = 0xfff;
    if (param_2 != 0) {
      local_2b0 = param_2;
    }
    local_2b8 = &local_2b0;
    local_2b4 = &local_22c;
    local_2c0 = 2;
    local_22c = local_2b0;
    iVar1 = _wportal_update_wportal_cb(param_1,&local_2c0);
    if (iVar1 == 0) {
      if (local_198._0_1_ != '\0') {
        for (uVar4 = 0; uVar4 < 0x80; uVar4 = uVar4 + 1) {
          local_368[uVar4] = local_188[uVar4 + 0x70];
        }
        local_2e8 = local_44;
        local_2e4 = local_40;
        local_2e0 = local_3c;
        local_2d8 = 1;
        local_2d4 = 1;
        for (uVar4 = 0; uVar4 < 0x70; uVar4 = uVar4 + 1) {
          *(char *)((int)&local_3d8 + uVar4) = local_188[uVar4];
        }
        local_2dc = param_1;
        local_2d0 = iVar3;
        FUN_00413e94(local_198,local_194,local_190,local_18c);
      }
      if (local_188[0x70] != '\0') {
        for (uVar4 = 0; uVar4 < 0x80; uVar4 = uVar4 + 1) {
          local_368[uVar4] = local_188[uVar4 + 0x70];
        }
        local_2e8 = local_44;
        local_2e4 = local_40;
        local_2e0 = local_3c;
        local_2d8 = 2;
        local_2d4 = 1;
        for (uVar4 = 0; uVar4 < 0x70; uVar4 = uVar4 + 1) {
          *(char *)((int)&local_3d8 + uVar4) = local_188[uVar4];
        }
        local_2dc = param_1;
        local_2d0 = iVar3;
        FUN_00413e94(local_198,local_194,local_190,local_18c);
      }
      if (g_portal_auth_mode == 0) {
        uac_wserv_ssid_portal_switch_to_ap(param_1);
      }
    }
    _wportal_refresh_port(param_1 & 0xffff);
    uVar6 = 0;
  }
  else {
    if (g_portal_auth_mode == 0) {
      if (-1 < param_3) {
        memset(&local_198,0,0x16c);
        iVar1 = wportal_db_ssid_rdt_get(param_3,&local_198);
        if (iVar1 != 0) {
          if (wportal_debug_switch == 0) {
            return 0;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0;
          }
          printf("[WPORTAL_DBG]%s()/%d Not get rdt entry\n","_wportal_wserv_bind_notify",0x2d90);
          return 0;
        }
        if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d get rdt entry\n","_wportal_wserv_bind_notify",0x2d95);
        }
        local_3d8 = 100;
        snprintf(acStack_2ac,0x80,"http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",
                 g_portal_port);
        local_3d8 = 100;
        snprintf(acStack_228,0x80,"http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",
                 g_portal_port);
        FUN_0051ad88(auStack_1a4);
        iVar1 = 0;
        if (param_2 != 0xfff) {
          iVar1 = param_2;
        }
        uac_wservice_for_ap_bind_vlan(iVar1,param_1,_wportal_collect_ssid_info_cb,auStack_1a4);
        local_1a8 = FUN_00407fe0(auStack_1a4);
        local_2bc = 0x1a;
        if (local_1a8 != '\0') {
          local_2bc = 0x19;
        }
        goto LAB_00414c44;
      }
      if (wportal_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      __format = "[WPORTAL_DBG]%s()/%d wserv_id is error %d\n";
      uVar5 = 0x2d89;
    }
    else {
      if (wportal_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      __format = "[WPORTAL_DBG]%s()/%d Portal mode error: %d\n";
      uVar5 = 0x2da4;
      param_3 = g_portal_auth_mode;
    }
    uVar6 = 0xffffffff;
    printf(__format,"_wportal_wserv_bind_notify",uVar5,param_3);
  }
  return uVar6;
}

