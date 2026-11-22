// func _wportal_station_leave_notify @ 004233e8 size=2552

undefined4 _wportal_station_leave_notify(int param_1)

{
  undefined1 uVar5;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 uVar6;
  short sVar7;
  char *__format;
  undefined4 uVar8;
  uint uVar9;
  ushort local_3d8 [2];
  uint local_3d4;
  undefined4 local_3d0;
  uint local_3cc;
  char local_3c8 [20];
  undefined1 auStack_3b4 [8];
  uint local_3ac;
  undefined1 auStack_38c [308];
  int local_258;
  undefined1 auStack_220 [304];
  undefined1 auStack_f0 [220];
  
  memset(auStack_220,0,0x205);
  local_3c8[0] = '\0';
  local_3c8[1] = '\0';
  local_3c8[2] = '\0';
  local_3c8[3] = '\0';
  local_3c8[4] = '\0';
  local_3c8[5] = '\0';
  local_3c8[6] = '\0';
  local_3c8[7] = '\0';
  local_3c8[8] = '\0';
  local_3c8[9] = '\0';
  local_3c8[10] = '\0';
  local_3c8[0xb] = '\0';
  local_3c8[0xc] = '\0';
  local_3c8[0xd] = '\0';
  local_3c8[0xe] = '\0';
  local_3c8[0xf] = '\0';
  local_3c8[0x10] = '\0';
  local_3c8[0x11] = '\0';
  local_3d8[0] = 0;
  if (g_authen_capability != 0) {
    iVar1 = uac_wservice_get_wserv_id
                      (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                       *(undefined1 *)(param_1 + 0x25));
    if (iVar1 == -1) {
      if (wportal_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      uVar9 = (uint)*(byte *)(param_1 + 0x24);
      uVar8 = *(undefined4 *)(param_1 + 0x20);
      uVar2 = (uint)*(byte *)(param_1 + 0x25);
      uVar3 = 0x279a;
      goto LAB_004237e4;
    }
    memset(auStack_220,0,0x205);
    iVar4 = uac_wservice_get_entry_by_id(iVar1,auStack_220);
    if (iVar4 == 0) {
      uVar9 = (uint)*(byte *)(param_1 + 0x69);
    }
    else if (wportal_debug_switch == 0) {
      uVar9 = (uint)*(byte *)(param_1 + 0x69);
    }
    else {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        uVar9 = (uint)*(byte *)(param_1 + 0x69);
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d Get wserv entry of wserv_id = %d fail.\n",
               "_wportal_station_leave_notify",0x27a2,iVar1);
        uVar9 = (uint)*(byte *)(param_1 + 0x69);
      }
    }
    local_3c8[0] = '\0';
    local_3c8[1] = '\0';
    local_3c8[2] = '\0';
    local_3c8[3] = '\0';
    local_3c8[4] = '\0';
    local_3c8[5] = '\0';
    local_3c8[6] = '\0';
    local_3c8[7] = '\0';
    local_3c8[8] = '\0';
    local_3c8[9] = '\0';
    local_3c8[10] = '\0';
    local_3c8[0xb] = '\0';
    local_3c8[0xc] = '\0';
    local_3c8[0xd] = '\0';
    local_3c8[0xe] = '\0';
    local_3c8[0xf] = '\0';
    local_3c8[0x10] = '\0';
    local_3c8[0x11] = '\0';
    snprintf(local_3c8,0x12,"%02X:%02X:%02X:%02X:%02X:%02X",(uint)*(byte *)(param_1 + 0x68),uVar9,
             (uint)*(byte *)(param_1 + 0x6a),(uint)*(byte *)(param_1 + 0x6b),
             (uint)*(byte *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x6d));
    uVar3 = json_object_new_object();
    uVar8 = json_object_new_int(0x263);
    json_object_object_add(uVar3,"type",uVar8);
    uVar8 = json_object_new_string(local_3c8);
    json_object_object_add(uVar3,"mac",uVar8);
    uVar8 = json_object_new_string(auStack_f0);
    json_object_object_add(uVar3,"ssid",uVar8);
    uVar8 = json_object_new_int(iVar1);
    json_object_object_add(uVar3,"serv_id",uVar8);
    wportal_send_to_wifidog(uVar3,0x263);
  }
  if ((DAT_007cca38 != 0) &&
     (iVar1 = FUN_0041181c(*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                           *(undefined1 *)(param_1 + 0x25),param_1 + 0x68), iVar1 != 0)) {
    iVar1 = uac_wservice_get_wserv_id
                      (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                       *(undefined1 *)(param_1 + 0x25));
    if (iVar1 != -1) {
      uac_wservice_get_vlan
                (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                 *(undefined1 *)(param_1 + 0x25),local_3d8);
      if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Sta leave: vlan: %d, mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n",
               "_wportal_station_leave_notify",0x27bc,(uint)local_3d8[0],
               (uint)*(byte *)(param_1 + 0x68),(uint)*(byte *)(param_1 + 0x69),
               (uint)*(byte *)(param_1 + 0x6a),(uint)*(byte *)(param_1 + 0x6b),
               (uint)*(byte *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x6d));
      }
      memset(auStack_3b4,0,0x28);
      local_3ac = 0xfff;
      if (local_3d8[0] != 0) {
        local_3ac = (uint)local_3d8[0];
      }
      memcpy(auStack_3b4,(void *)(param_1 + 0x68),6);
      if (wportal_debug_switch == 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x20);
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d Allow sta access: %d\n\n","_wportal_station_leave_notify",
                 0x27c2,iVar1);
          uVar3 = *(undefined4 *)(param_1 + 0x20);
        }
      }
      uVar3 = wportal_update_user_to_ap_by_id(uVar3,auStack_3b4,1);
      return uVar3;
    }
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    uVar9 = (uint)*(byte *)(param_1 + 0x24);
    uVar8 = *(undefined4 *)(param_1 + 0x20);
    uVar2 = (uint)*(byte *)(param_1 + 0x25);
    uVar3 = 0x27b5;
LAB_004237e4:
    printf("[WPORTAL_DBG]%s()/%d Get wserv id error, entry->ap_id[%d], entry->rd_id[%d], entry->wlan_id[%d] invalid!\n"
           ,"_wportal_station_leave_notify",uVar3,uVar8,uVar9,uVar2);
    return 0xffffffff;
  }
  if (g_portal_auth_mode == 0) {
    iVar1 = uac_wservice_get_wserv_id
                      (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                       *(undefined1 *)(param_1 + 0x25));
    if (iVar1 == -1) {
      if (wportal_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      uVar9 = (uint)*(byte *)(param_1 + 0x24);
      uVar8 = *(undefined4 *)(param_1 + 0x20);
      uVar2 = (uint)*(byte *)(param_1 + 0x25);
      uVar3 = 0x27cc;
      goto LAB_004237e4;
    }
    local_3d8[0] = *(ushort *)(param_1 + 0x2e);
    if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Sta leave: vlan: %d, mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n",
             "_wportal_station_leave_notify",0x27d6,(uint)local_3d8[0],
             (uint)*(byte *)(param_1 + 0x68),(uint)*(byte *)(param_1 + 0x69),
             (uint)*(byte *)(param_1 + 0x6a),(uint)*(byte *)(param_1 + 0x6b),
             (uint)*(byte *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x6d));
    }
    memset(auStack_38c,0,0x16c);
    iVar1 = wportal_db_ssid_rdt_get(iVar1,auStack_38c);
    if (iVar1 == 0) {
      uVar6 = *(undefined2 *)(param_1 + 0x22);
    }
    else {
      memset(auStack_3b4,0,0x28);
      local_3ac = 0xfff;
      if (local_3d8[0] != 0) {
        local_3ac = (uint)local_3d8[0];
      }
      memcpy(auStack_3b4,(void *)(param_1 + 0x68),6);
      wportal_update_user_to_ap_by_id(*(undefined4 *)(param_1 + 0x20),auStack_3b4,1);
      uVar6 = *(undefined2 *)(param_1 + 0x22);
    }
  }
  else if (g_portal_auth_mode == 1) {
    memset(auStack_38c,0,0x16c);
    sVar7 = *(short *)(param_1 + 0x2e);
    if (sVar7 == 0) {
      sVar7 = 0xfff;
    }
    iVar1 = wportal_db_rdt_get_by_vlan(sVar7,auStack_38c);
    if ((iVar1 == 0) && (local_258 != 0)) {
      memset(auStack_3b4,0,0x28);
      local_3ac = (uint)*(ushort *)(param_1 + 0x2e);
      memcpy(auStack_3b4,(void *)(param_1 + 0x68),6);
      if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d leave sta delete aut entry\n","_wportal_station_leave_notify",
               0x27f3);
      }
      if (wportal_debug_switch == 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x20);
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d ap_id:%d, vlan_id:%d\n","_wportal_station_leave_notify",
                 0x27f4,*(undefined4 *)(param_1 + 0x20),local_3ac);
          uVar3 = *(undefined4 *)(param_1 + 0x20);
        }
      }
      iVar1 = wportal_update_user_to_ap_by_id(uVar3,auStack_3b4,1);
      if (iVar1 == -1) {
        if (wportal_err_switch == 0) {
          uVar6 = *(undefined2 *)(param_1 + 0x22);
        }
        else {
          iVar1 = is_target_debug_ap();
          if (iVar1 != 0) {
            __format = "[WPORTAL_ERR]%s()/%d leave sta delete aut entry failed!\n\n";
            uVar3 = 0x27f8;
            goto LAB_004238fc;
          }
          uVar6 = *(undefined2 *)(param_1 + 0x22);
        }
      }
      else {
        uVar6 = *(undefined2 *)(param_1 + 0x22);
      }
    }
    else if (wportal_info_switch == 0) {
      uVar6 = *(undefined2 *)(param_1 + 0x22);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar6 = *(undefined2 *)(param_1 + 0x22);
      }
      else {
        __format = "[WPORTAL_INFO]%s()/%d leave sta get rdt entry fail\n";
        uVar3 = 0x27eb;
LAB_004238fc:
        printf(__format,"_wportal_station_leave_notify",uVar3);
        uVar6 = *(undefined2 *)(param_1 + 0x22);
      }
    }
  }
  else {
    uVar6 = *(undefined2 *)(param_1 + 0x22);
  }
  iVar1 = apmngr_db_capacity_support(uVar6,1,0x38);
  if (iVar1 != 1) {
    return 0;
  }
  if (*(char *)(param_1 + 0x34) == '\0') {
    return 0;
  }
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d leave sta is roam sta\n","_wportal_station_leave_notify",0x2801);
  }
  local_3d4 = 0;
  local_3d0 = 0;
  local_3cc = 0;
  memcpy(&local_3d4,(void *)(param_1 + 0x68),6);
  if (wportal_debug_switch == 0) {
    uVar5 = *(undefined1 *)(param_1 + 0x24);
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      uVar5 = *(undefined1 *)(param_1 + 0x24);
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d rStaEntry.mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n",
             "_wportal_station_leave_notify",0x2804,local_3d4 >> 0x18,local_3d4 >> 0x10 & 0xff,
             local_3d4 >> 8 & 0xff,local_3d4 & 0xff,local_3d0 >> 0x18,local_3d0 >> 0x10 & 0xff);
      uVar5 = *(undefined1 *)(param_1 + 0x24);
    }
  }
  uVar9 = (uint)*(ushort *)(param_1 + 0x2e);
  local_3d0._2_2_ = CONCAT11(uVar5,(undefined1)local_3d0);
  local_3cc = uVar9;
  if (g_portal_auth_mode == 1) {
    memset(auStack_38c,0,0x16c);
    uVar2 = 0xfff;
    if (uVar9 != 0) {
      uVar2 = uVar9;
    }
    iVar1 = wportal_db_rdt_get_by_vlan(uVar2,auStack_38c);
    if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d wportal_db_rdt_get_by_vlan ret=%d, vlan-id=%d\n\n",
             "_wportal_station_leave_notify",0x280d,iVar1,local_258);
    }
    if (iVar1 != 0) {
      if (wportal_err_switch == 0) {
        local_3d0 = local_3d0 & 0xffffff00;
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          local_3d0 = local_3d0 & 0xffffff00;
        }
        else {
          printf("[WPORTAL_ERR]%s()/%d get rdtEntry error!\n","_wportal_station_leave_notify",0x2810
                );
          local_3d0 = local_3d0 & 0xffffff00;
        }
      }
    }
    if (local_258 != 0) {
      local_3d0 = CONCAT31(local_3d0._0_3_,1);
      if (wportal_debug_switch == 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x20);
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d pre-station vlan portal entry exist,update roam sta to ap\n",
                 "_wportal_station_leave_notify",0x281c);
          uVar3 = *(undefined4 *)(param_1 + 0x20);
        }
      }
      goto LAB_004236f0;
    }
    if (wportal_debug_switch == 0) {
      local_3d0 = (uint)local_3d0._0_3_ << 8;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        local_3d0 = local_3d0 & 0xffffff00;
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d get portal entry by vlan :%d failed!\n",
               "_wportal_station_leave_notify",0x2816,local_3cc);
        local_3d0 = local_3d0 & 0xffffff00;
      }
    }
  }
  else if (g_portal_auth_mode == 0) {
    uVar3 = uac_wservice_get_wserv_id
                      (*(undefined4 *)(param_1 + 0x28),*(undefined1 *)(param_1 + 0x2c),
                       *(undefined1 *)(param_1 + 0x2d));
    if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d ssid mode, ori_wserv_id : %d\n","_wportal_station_leave_notify",
             0x2822,uVar3);
    }
    memset(auStack_38c,0,0x16c);
    iVar1 = wportal_db_ssid_rdt_get(uVar3,auStack_38c);
    if (iVar1 == 0) {
      if ((wportal_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
        local_3d0 = CONCAT31(local_3d0._0_3_,1);
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d pre-station ssid portal entry exist,update roam sta to ap\n",
               "_wportal_station_leave_notify",0x282e);
        local_3d0 = CONCAT31(local_3d0._0_3_,1);
      }
    }
    else if (wportal_debug_switch == 0) {
      local_3d0 = local_3d0 & 0xffffff00;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        local_3d0 = local_3d0 & 0xffffff00;
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d get portal entry by ssid failed\n",
               "_wportal_station_leave_notify",0x2829);
        local_3d0 = local_3d0 & 0xffffff00;
      }
    }
  }
  uVar3 = *(undefined4 *)(param_1 + 0x20);
LAB_004236f0:
  wportal_update_roam_sta_to_ap_by_id(uVar3,&local_3d4,0x16);
  return 0;
}

