// func _wportal_station_access_notify @ 00423de0 size=3012

int _wportal_station_access_notify(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined1 uVar5;
  int iVar4;
  undefined2 uVar7;
  char *__format;
  uint uVar6;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  void *__src;
  uint local_9a0;
  undefined4 local_99c;
  uint local_998;
  char local_994 [20];
  undefined1 auStack_980 [8];
  uint local_978;
  undefined1 auStack_958 [296];
  uint local_830;
  undefined1 auStack_7f0 [308];
  int local_6bc;
  undefined1 auStack_680 [20];
  uint local_66c;
  uint local_64c;
  undefined2 local_648;
  undefined1 auStack_500 [304];
  undefined1 auStack_3d0 [216];
  undefined1 auStack_2f8 [20];
  uint local_2e4;
  uint local_2b0;
  undefined2 local_2ac;
  
  memset(auStack_680,0,0x180);
  memset(auStack_958,0,0x168);
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_500,0,0x205);
  local_994[0] = '\0';
  local_994[1] = '\0';
  local_994[2] = '\0';
  local_994[3] = '\0';
  local_994[4] = '\0';
  local_994[5] = '\0';
  local_994[6] = '\0';
  local_994[7] = '\0';
  local_994[8] = '\0';
  local_994[9] = '\0';
  local_994[10] = '\0';
  local_994[0xb] = '\0';
  local_994[0xc] = '\0';
  local_994[0xd] = '\0';
  local_994[0xe] = '\0';
  local_994[0xf] = '\0';
  local_994[0x10] = '\0';
  local_994[0x11] = '\0';
  iVar3 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_2f8);
  if (iVar3 == -1) {
    iVar3 = -1;
    if (wportal_debug_switch == 0) {
      return -1;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return -1;
    }
    __format = "[WPORTAL_DBG]%s()/%d Get ap entry error\n";
    uVar8 = 0x266b;
LAB_0042403c:
    printf(__format,"_wportal_station_access_notify",uVar8);
    return iVar3;
  }
  if (((((1 < local_2e4) && (local_2e4 != 3)) && (local_2e4 != 2)) &&
      ((local_2e4 != 4 && (local_2e4 != 8)))) && (local_2e4 != 6)) {
    iVar3 = 0;
    if (wportal_debug_switch == 0) {
      return 0;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0;
    }
    __format = "[WPORTAL_DBG]%s()/%d No need to handle for non-AP\n";
    uVar8 = 0x2670;
    goto LAB_0042403c;
  }
  uVar11 = 0xffffffff;
  if (g_authen_capability != 0) {
    uVar11 = uac_wservice_get_wserv_id
                       (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                        *(undefined1 *)(param_1 + 0x25));
    if (uVar11 == 0xffffffff) {
      if (wportal_debug_switch == 0) {
        return -1;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return -1;
      }
      bVar1 = *(byte *)(param_1 + 0x24);
      uVar9 = *(undefined4 *)(param_1 + 0x20);
      bVar2 = *(byte *)(param_1 + 0x25);
      uVar8 = 0x2678;
      goto LAB_0042419c;
    }
    memset(auStack_500,0,0x205);
    iVar3 = uac_wservice_get_entry_by_id(uVar11,auStack_500);
    if (iVar3 != 0) {
      if (wportal_info_switch == 0) {
        return -1;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return -1;
      }
      printf("[WPORTAL_INFO]%s()/%d Get wserv entry of wserv id = %d fail.\n",
             "_wportal_station_access_notify",0x2680,uVar11);
      return -1;
    }
    local_994[0] = '\0';
    local_994[1] = '\0';
    local_994[2] = '\0';
    local_994[3] = '\0';
    local_994[4] = '\0';
    local_994[5] = '\0';
    local_994[6] = '\0';
    local_994[7] = '\0';
    local_994[8] = '\0';
    local_994[9] = '\0';
    local_994[10] = '\0';
    local_994[0xb] = '\0';
    local_994[0xc] = '\0';
    local_994[0xd] = '\0';
    local_994[0xe] = '\0';
    local_994[0xf] = '\0';
    local_994[0x10] = '\0';
    local_994[0x11] = '\0';
    snprintf(local_994,0x12,"%02X:%02X:%02X:%02X:%02X:%02X",(uint)*(byte *)(param_1 + 0x68),
             (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
             (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
             (uint)*(byte *)(param_1 + 0x6d));
    uVar8 = json_object_new_object();
    uVar9 = json_object_new_int(0x25e);
    json_object_object_add(uVar8,"type",uVar9);
    uVar9 = json_object_new_string(local_994);
    json_object_object_add(uVar8,"mac",uVar9);
    uVar9 = json_object_new_string(auStack_3d0);
    json_object_object_add(uVar8,"ssid",uVar9);
    uVar9 = json_object_new_int(uVar11);
    json_object_object_add(uVar8,"serv_id",uVar9);
    wportal_send_to_wifidog(uVar8,0x25e);
  }
  if ((g_portal_auth_mode == 0) &&
     (uVar11 = uac_wservice_get_wserv_id
                         (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                          *(undefined1 *)(param_1 + 0x25)), uVar11 == 0xffffffff)) {
    if (wportal_debug_switch == 0) {
      return -1;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return -1;
    }
    bVar1 = *(byte *)(param_1 + 0x24);
    uVar9 = *(undefined4 *)(param_1 + 0x20);
    bVar2 = *(byte *)(param_1 + 0x25);
    uVar8 = 0x2696;
LAB_0042419c:
    printf("[WPORTAL_DBG]%s()/%d Get wserv id error, entry->ap_id[%d], entry->rd_id[%d], entry->wlan_id[%d] invalid!\n"
           ,"_wportal_station_access_notify",uVar8,uVar9,(uint)bVar1,(uint)bVar2);
    return -1;
  }
  uVar10 = (uint)*(ushort *)(param_1 + 0x2e);
  if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Station access notify apid: %d rdid: %d wlanid: %d, get vlan: %d\n"
           ,"_wportal_station_access_notify",0x269f,*(undefined4 *)(param_1 + 0x20),
           (uint)*(byte *)(param_1 + 0x24),(uint)*(byte *)(param_1 + 0x25),uVar10);
  }
  if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Sta access: vlan: %d, mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n",
           "_wportal_station_access_notify",0x26a0,uVar10,(uint)*(byte *)(param_1 + 0x68),
           (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
           (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
           (uint)*(byte *)(param_1 + 0x6d));
  }
  __src = (void *)(param_1 + 0x68);
  if (DAT_007cca38 != 0) {
    iVar3 = FUN_0041181c(*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                         *(undefined1 *)(param_1 + 0x25),__src);
    if (iVar3 != 0) {
      memset(auStack_980,0,0x28);
      local_978 = 0xfff;
      if (uVar10 != 0) {
        local_978 = uVar10;
      }
      memcpy(auStack_980,__src,6);
      if (wportal_debug_switch == 0) {
        uVar8 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          uVar8 = *(undefined4 *)(param_1 + 0x20);
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d Allow sta access: %d\n\n","_wportal_station_access_notify",
                 0x26a8,uVar11);
          uVar8 = *(undefined4 *)(param_1 + 0x20);
        }
      }
      goto LAB_00424128;
    }
  }
  if (wportal_debug_switch == 0) {
    uVar7 = *(undefined2 *)(param_1 + 0x22);
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      uVar7 = *(undefined2 *)(param_1 + 0x22);
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d station roam =%d, ap-id=%d\n\n","_wportal_station_access_notify",
             0x26ae,(uint)*(byte *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x20));
      uVar7 = *(undefined2 *)(param_1 + 0x22);
    }
  }
  iVar3 = apmngr_db_capacity_support(uVar7,1,0x38);
  if ((iVar3 == 1) && (*(char *)(param_1 + 0x34) != '\0')) {
    local_9a0 = 0;
    local_99c = 0;
    local_998 = 0;
    memcpy(&local_9a0,(void *)(param_1 + 0x68),6);
    if (wportal_debug_switch == 0) {
      uVar5 = *(undefined1 *)(param_1 + 0x24);
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        uVar5 = *(undefined1 *)(param_1 + 0x24);
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d rStaEntry.mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n",
               "_wportal_station_access_notify",0x26b7,local_9a0 >> 0x18,local_9a0 >> 0x10 & 0xff,
               local_9a0 >> 8 & 0xff,local_9a0 & 0xff,local_99c >> 0x18,local_99c >> 0x10 & 0xff);
        uVar5 = *(undefined1 *)(param_1 + 0x24);
      }
    }
    local_99c._2_2_ = CONCAT11(uVar5,(undefined1)local_99c);
    local_998 = (uint)*(ushort *)(param_1 + 0x2e);
    if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d rStaEntry.rd_id : %d, rStaEntry.vlan_id :%d \n",
             "_wportal_station_access_notify",0x26ba,local_99c >> 8 & 0xff,local_998);
    }
    if (g_portal_auth_mode == 1) {
      memset(auStack_7f0,0,0x16c);
      uVar6 = local_998;
      if (local_998 == 0) {
        uVar6 = 0xfff;
      }
      iVar3 = wportal_db_rdt_get_by_vlan(uVar6,auStack_7f0);
      if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d wportal_db_rdt_get_by_vlan ret=%d, vlan-id=%d\n\n",
               "_wportal_station_access_notify",0x26c0,iVar3,local_6bc);
      }
      if (iVar3 != 0) {
        if (wportal_err_switch == 0) {
          local_99c = local_99c & 0xffffff00;
        }
        else {
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            local_99c = local_99c & 0xffffff00;
          }
          else {
            printf("[WPORTAL_ERR]%s()/%d get rdtEntry error!\n","_wportal_station_access_notify",
                   0x26c3);
            local_99c = local_99c & 0xffffff00;
          }
        }
      }
      if (local_6bc == 0) {
        if (wportal_debug_switch == 0) {
          local_99c = (uint)local_99c._0_3_ << 8;
        }
        else {
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            local_99c = local_99c & 0xffffff00;
          }
          else {
            printf("[WPORTAL_DBG]%s()/%d get portal entry by vlan :%d failed!\n",
                   "_wportal_station_access_notify",0x26c9,local_998);
            local_99c = local_99c & 0xffffff00;
          }
        }
        goto LAB_004243d0;
      }
      local_99c = CONCAT31(local_99c._0_3_,1);
      if (wportal_debug_switch == 0) {
        uVar8 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          uVar8 = *(undefined4 *)(param_1 + 0x20);
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d pre-station vlan portal entry exist,update roam sta to ap\n",
                 "_wportal_station_access_notify",0x26cf);
          uVar8 = *(undefined4 *)(param_1 + 0x20);
        }
      }
    }
    else {
      if (g_portal_auth_mode == 0) {
        uVar8 = uac_wservice_get_wserv_id
                          (*(undefined4 *)(param_1 + 0x28),*(undefined1 *)(param_1 + 0x2c),
                           *(undefined1 *)(param_1 + 0x2d));
        if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d ssid mode, ori_wserv_id : %d\n",
                 "_wportal_station_access_notify",0x26d5,uVar8);
        }
        memset(auStack_7f0,0,0x16c);
        iVar3 = wportal_db_ssid_rdt_get(uVar8,auStack_7f0);
        if (iVar3 == 0) {
          if ((wportal_debug_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) {
            local_99c = CONCAT31(local_99c._0_3_,1);
          }
          else {
            printf("[WPORTAL_DBG]%s()/%d pre-station ssid portal entry exist,update roam sta to ap\n"
                   ,"_wportal_station_access_notify",0x26e1);
            local_99c = CONCAT31(local_99c._0_3_,1);
          }
        }
        else if (wportal_debug_switch == 0) {
          local_99c = local_99c & 0xffffff00;
        }
        else {
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            local_99c = local_99c & 0xffffff00;
          }
          else {
            printf("[WPORTAL_DBG]%s()/%d get portal entry by ssid failed\n",
                   "_wportal_station_access_notify",0x26dc);
            local_99c = local_99c & 0xffffff00;
          }
        }
      }
LAB_004243d0:
      uVar8 = *(undefined4 *)(param_1 + 0x20);
    }
    iVar3 = wportal_update_roam_sta_to_ap_by_id(uVar8,&local_9a0,0x15);
    if (((iVar3 != 0) && (wportal_err_switch != 0)) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d update roam sta to ap failed\n","_wportal_station_access_notify",
             0x26e9);
    }
  }
  if (g_portal_auth_mode == 0) {
    memset(auStack_980,0,0x28);
    local_978 = 0xfff;
    if (uVar10 != 0) {
      local_978 = uVar10;
    }
    memcpy(auStack_980,(void *)(param_1 + 0x68),6);
    memset(auStack_7f0,0,0x16c);
    iVar3 = wportal_db_ssid_rdt_get(uVar11,auStack_7f0);
    if (iVar3 != 0) {
      if (wportal_debug_switch == 0) {
        uVar8 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          uVar8 = *(undefined4 *)(param_1 + 0x20);
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d Not bound rdt entry add user entry: %d\n\n",
                 "_wportal_station_access_notify",0x26fa,uVar11);
          uVar8 = *(undefined4 *)(param_1 + 0x20);
        }
      }
      iVar4 = _wportal_db_support_new_portal_by_id(uVar8);
      if (iVar4 != 0) {
        return iVar3;
      }
      uVar8 = *(undefined4 *)(param_1 + 0x20);
LAB_00424128:
      iVar3 = wportal_update_user_to_ap_by_id(uVar8,auStack_980,0);
      return iVar3;
    }
    wportal_update_user_to_ap_by_id(*(undefined4 *)(param_1 + 0x20),auStack_980,1);
  }
  memset(auStack_680,0,0x180);
  iVar3 = wportal_db_aut_get(__src,auStack_680);
  if (iVar3 == 0) {
    if (g_portal_auth_mode == 1) {
      uVar6 = 0xfff;
      if (uVar10 != 0) {
        uVar6 = uVar10;
      }
    }
    else {
      uVar6 = uVar11;
      if (g_portal_auth_mode != 0) goto LAB_00423fac;
    }
    if (uVar6 == local_66c) {
      if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        uVar11 = 0xfff;
        if (uVar10 != 0) {
          uVar11 = uVar10;
        }
        printf("[WPORTAL_DBG]%s()/%d Already authed MAC: %02x:%02x:%02x:%02x:%02x:%02x vlan: %d\n",
               "_wportal_station_access_notify",0x270e,(uint)*(byte *)(param_1 + 0x68),
               (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
               (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
               (uint)*(byte *)(param_1 + 0x6d),uVar11);
      }
      local_648 = local_2ac;
      if ((wportal_debug_switch != 0) &&
         (local_64c = local_2b0, iVar3 = is_target_debug_ap(auStack_680), iVar3 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Refresh ap mac: %02x:%02x:%02x:%02x:%02x:%02x\n",
               "_wportal_station_access_notify",0x2714,local_64c >> 0x18,local_64c >> 0x10 & 0xff,
               local_64c >> 8 & 0xff,local_64c & 0xff,(uint)local_648._0_1_,(uint)(byte)local_648);
      }
      wportal_db_aut_set(auStack_680);
      wportal_update_user_to_ap(auStack_680,0);
      return 0;
    }
  }
LAB_00423fac:
  memset(auStack_958,0,0x168);
  iVar3 = wportal_db_nsa_get(__src,auStack_958);
  if (iVar3 != 0) {
    return 0;
  }
  if (g_portal_auth_mode == 1) {
    uVar11 = 0xfff;
    if (uVar10 != 0) {
      uVar11 = uVar10;
    }
  }
  else if (g_portal_auth_mode != 0) goto LAB_00423ff0;
  if (uVar11 != local_830) {
    return 0;
  }
LAB_00423ff0:
  if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(auStack_958), iVar3 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Start non sense auth\n","_wportal_station_access_notify",0x2727);
  }
  _wportal_nonsense_auth(auStack_958,auStack_2f8);
  return 0;
}

