// func _wportal_authed_user_timer_handler @ 004222a8 size=2764

void _wportal_authed_user_timer_handler(byte *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  size_t sVar8;
  uint uVar9;
  uint uVar10;
  char *__format;
  int iVar11;
  timespec local_7a8;
  char local_7a0 [20];
  undefined1 auStack_78c [32];
  uint local_76c;
  undefined1 local_768;
  undefined1 local_767;
  ushort local_75e;
  undefined1 auStack_70c [121];
  undefined1 auStack_693 [101];
  char acStack_62e [50];
  int local_5fc;
  undefined1 auStack_5ec [20];
  undefined1 auStack_5d8 [296];
  uint local_4b0;
  undefined1 auStack_470 [12];
  undefined1 auStack_464 [8];
  uint local_45c;
  undefined1 auStack_43c [8];
  uint local_434;
  uint local_428;
  uint local_424;
  uint local_420;
  uint local_41c;
  char acStack_418 [75];
  char acStack_3cd [157];
  int local_330;
  uint local_32c;
  int local_328;
  int local_31c;
  undefined4 local_318;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined1 auStack_2f0 [732];
  
  memset(auStack_470,0,0x180);
  memset(auStack_5d8,0,0x168);
  memset(auStack_78c,0,0x80);
  memset(auStack_2f0,0,0x2d8);
  local_7a0[0] = '\0';
  local_7a0[1] = '\0';
  local_7a0[2] = '\0';
  local_7a0[3] = '\0';
  local_7a0[4] = '\0';
  local_7a0[5] = '\0';
  local_7a0[6] = '\0';
  local_7a0[7] = '\0';
  local_7a0[8] = '\0';
  local_7a0[9] = '\0';
  local_7a0[10] = '\0';
  local_7a0[0xb] = '\0';
  local_7a0[0xc] = '\0';
  local_7a0[0xd] = '\0';
  local_7a0[0xe] = '\0';
  local_7a0[0xf] = '\0';
  local_7a0[0x10] = '\0';
  local_7a0[0x11] = '\0';
  if (param_1 == (byte *)0x0) {
    if (wportal_err_switch == 0) {
      return;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return;
    }
    __format = "[WPORTAL_ERR]%s()/%d Timer arg error\n";
    uVar5 = 0x722;
    goto LAB_00422550;
  }
  memset(auStack_470,0,0x180);
  if ((*(int *)param_1 == 0) && ((*(uint *)(param_1 + 4) & 0xffff0000) == 0)) {
    iVar6 = wportal_db_aut_get_by_ip(param_1 + 0x20,auStack_470);
    if (iVar6 != 0) {
      return;
    }
    iVar6 = *(int *)(param_1 + 0x18);
  }
  else {
    if ((wportal_debug_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d get by mac\n","_wportal_authed_user_timer_handler",0x72a);
    }
    iVar6 = wportal_db_aut_get(param_1,auStack_470);
    if (iVar6 != 0) {
      return;
    }
    iVar6 = *(int *)(param_1 + 0x18);
  }
  if (iVar6 == 0) {
    if (wportal_info_switch == 0) {
      uVar3 = (uint)param_1[1];
    }
    else {
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        uVar3 = (uint)param_1[1];
      }
      else {
        printf("[WPORTAL_INFO]%s()/%d Auth entry time out, age auth entry\n",
               "_wportal_authed_user_timer_handler",0x73e);
        uVar3 = (uint)param_1[1];
      }
    }
    iVar11 = -1;
    snprintf(local_7a0,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,uVar3,(uint)param_1[2],
             (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    iVar6 = wportal_db_nsa_get(param_1,auStack_5d8);
    if (iVar6 == 0) {
      iVar11 = wsta_db_get_entry_by_mac(param_1,auStack_78c);
    }
    iVar4 = json_object_new_object();
    uVar5 = json_object_new_int(1);
    json_object_object_add(iVar4,"type",uVar5);
    uVar5 = json_object_new_string(local_7a0);
    json_object_object_add(iVar4,"mac",uVar5);
    bVar1 = false;
    uVar5 = json_object_new_string(param_1 + 0x20);
    json_object_object_add(iVar4,&DAT_00677c24,uVar5);
    uVar5 = json_object_new_int(5);
    json_object_object_add(iVar4,"terminate_type",uVar5);
    if (iVar11 == 0 && iVar6 == 0) {
      if (g_portal_auth_mode == 1) {
        uVar10 = (uint)local_75e;
        uVar3 = 0xffffffff;
      }
      else {
        uVar5 = rdmngr_db_generate_rd_id(local_76c,local_768);
        uVar3 = wserv_db_rd_get_wserv_id(uVar5,local_767);
        uVar10 = 0;
      }
      if (g_portal_auth_mode == 1) {
        if (local_4b0 == 0xfff) {
          local_4b0 = 0;
        }
        bVar1 = false;
        if (uVar10 != local_4b0) goto LAB_004224b4;
      }
      else {
        bVar1 = false;
        if (((g_portal_auth_mode != 0) || (uVar3 == 0xffffffff)) || (uVar3 != local_4b0))
        goto LAB_004224b4;
      }
      bVar1 = true;
      uVar5 = json_object_new_int(1);
      json_object_object_add(iVar4,"online_nsa_auth",uVar5);
    }
LAB_004224b4:
    wportal_send_to_nginx(iVar4);
    if (iVar4 != 0) {
      json_object_put(iVar4);
    }
    if (!bVar1) {
      return;
    }
    apmngr_db_entry_get_by_id(local_76c & 0xffff,auStack_2f0);
    _wportal_nonsense_auth(auStack_5d8,auStack_2f0);
    return;
  }
  if (iVar6 == 1) {
    if ((g_portal_age_enable == 1) && (g_portal_auth_mode != 2)) {
      iVar6 = wsta_db_get_entry_by_mac(auStack_464,auStack_78c);
      if (iVar6 == 0) {
        if (g_portal_auth_mode == 1) {
          uVar10 = (uint)local_75e;
          uVar3 = 0xffffffff;
        }
        else {
          uVar5 = rdmngr_db_generate_rd_id(local_76c,local_768);
          uVar3 = wserv_db_rd_get_wserv_id(uVar5,local_767);
          uVar10 = 0;
        }
        if (g_portal_auth_mode == 1) {
          uVar3 = local_45c;
          if (local_45c == 0xfff) {
            uVar3 = 0;
          }
        }
        else if ((g_portal_auth_mode != 0) || (uVar10 = local_45c, uVar3 == 0xffffffff))
        goto LAB_00422958;
        if (uVar3 == uVar10) {
          local_330 = 0;
          if ((wportal_info_switch == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
          goto LAB_004227c0;
          printf("[WPORTAL_INFO]%s()/%d Check station ok\n","_wportal_authed_user_timer_handler",
                 0x7a7);
          bVar2 = false;
          bVar1 = true;
          goto LAB_0042257c;
        }
      }
LAB_00422958:
      if (ac_datasync_status == 1) {
        local_330 = local_330 + *(int *)(param_1 + 0x14);
      }
      else {
        local_330 = 0;
      }
      if ((wportal_info_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Check station time: %d, check time: %d\n\n",
               "_wportal_authed_user_timer_handler",0x7b5,local_330,g_portal_age_time);
      }
      if (g_portal_age_time <= local_330) {
        if (wportal_debug_switch == 0) {
          uVar3 = (uint)param_1[1];
        }
        else {
          iVar6 = is_target_debug_ap();
          if (iVar6 == 0) {
            uVar3 = (uint)param_1[1];
          }
          else {
            printf("[WPORTAL_DBG]%s()/%d Station out, age auth entry\n",
                   "_wportal_authed_user_timer_handler",0x7b9);
            uVar3 = (uint)param_1[1];
          }
        }
        snprintf(local_7a0,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,uVar3,
                 (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
        iVar6 = json_object_new_object();
        uVar5 = json_object_new_int(1);
        json_object_object_add(iVar6,"type",uVar5);
        uVar5 = json_object_new_string(local_7a0);
        json_object_object_add(iVar6,"mac",uVar5);
        uVar5 = json_object_new_int(0x16);
        json_object_object_add(iVar6,"terminate_type",uVar5);
        wportal_send_to_nginx(iVar6);
        if (iVar6 == 0) {
          return;
        }
        json_object_put(iVar6);
        return;
      }
    }
LAB_004227c0:
    bVar2 = false;
    bVar1 = true;
  }
  else {
    if (iVar6 == 2) {
      if ((wportal_info_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Update accounting\n","_wportal_authed_user_timer_handler",
               0x7db);
      }
      memset(auStack_70c,0,0x134);
      iVar6 = wportal_db_rds_srv_get_by_index(local_318,auStack_70c);
      if ((iVar6 == -1) || (local_5fc == 0)) {
        if (wportal_debug_switch == 0) goto LAB_00422aa4;
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          bVar2 = true;
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d No radius server\n","_wportal_authed_user_timer_handler",
                 0x832);
          bVar2 = true;
        }
      }
      else {
        pvVar7 = (void *)FUN_00408450(0x1f8,0x7e6);
        if (pvVar7 == (void *)0x0) {
LAB_00422aa4:
          bVar2 = true;
        }
        else {
          memset(pvVar7,0,0x1f8);
          *(int *)((int)pvVar7 + 0x19c) = local_5fc;
          memcpy((void *)((int)pvVar7 + 0x6b),auStack_43c,6);
          sVar8 = strlen(acStack_62e);
          memcpy((void *)((int)pvVar7 + 0xd6),acStack_62e,sVar8 + 1);
          memcpy((void *)((int)pvVar7 + 0x71),auStack_693,100);
          clock_gettime(1,&local_7a8);
          *(__time_t *)((int)pvVar7 + 0x180) = local_7a8.tv_sec - local_31c;
          *(undefined4 *)((int)pvVar7 + 0x17c) = local_30c;
          *(undefined4 *)((int)pvVar7 + 0x178) = local_310;
          FUN_0051a7a8(acStack_418,(int)pvVar7 + 0x184);
          memcpy((void *)((int)pvVar7 + 0x65),auStack_464,6);
          sVar8 = strlen(acStack_3cd);
          memcpy(pvVar7,acStack_3cd,sVar8 + 1);
          if ((g_portal_auth_mode == 1) || (g_portal_auth_mode == 0)) {
            *(uint *)((int)pvVar7 + 0x1a0) = local_45c;
          }
          memcpy((void *)((int)pvVar7 + 0xfe),auStack_70c,0x78);
          memcpy((void *)((int)pvVar7 + 0x1c8),auStack_5ec,0x14);
          *(undefined4 *)((int)pvVar7 + 0x1e4) = local_2fc;
          *(undefined4 *)((int)pvVar7 + 0x1e0) = local_300;
          *(undefined4 *)((int)pvVar7 + 0x1ec) = local_2f4;
          *(undefined4 *)((int)pvVar7 + 0x1e8) = local_2f8;
          FUN_00407d70(pvVar7);
          FUN_00407df0(pvVar7);
          bVar2 = true;
        }
      }
    }
    else {
      bVar2 = false;
    }
    bVar1 = false;
  }
LAB_0042257c:
  uVar3 = *(uint *)(param_1 + 0x10);
  uVar10 = *(uint *)(param_1 + 0x14);
  if (uVar3 == 0) {
    if (local_434 < uVar10) {
      local_434 = 0;
    }
    else {
      local_434 = local_434 - uVar10;
    }
  }
  else {
    local_434 = 0;
  }
  uVar9 = 0x3c;
  if (!bVar1) {
    if ((uint)((int)local_32c >> 0x1f) < uVar3) {
      uVar9 = 0x3c;
    }
    else if (uVar3 == (int)local_32c >> 0x1f) {
      if (local_32c < uVar10) {
        uVar9 = 0x3c;
      }
      else {
        uVar9 = local_32c - uVar10;
      }
    }
    else {
      uVar9 = local_32c - uVar10;
    }
  }
  if (((bVar2) || (local_420 < uVar3)) || ((uVar3 == local_420 && (local_41c < uVar10)))) {
    local_41c = local_424;
    local_420 = local_428;
  }
  else {
    local_420 = (local_420 - uVar3) - (uint)(local_41c < local_41c - uVar10);
    local_41c = local_41c - uVar10;
  }
  local_32c = uVar9;
  pvVar7 = (void *)FUN_00408450(0x48,0x856);
  if (pvVar7 == (void *)0x0) {
    return;
  }
  if ((wportal_debug_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Check timer: expire: %u, station check: %d, radius acct update: %llu\n\n"
           ,"_wportal_authed_user_timer_handler",0x85e,local_434,local_32c);
  }
  memcpy(pvVar7,auStack_464,6);
  strncpy((char *)((int)pvVar7 + 0x20),acStack_418,0x28);
  *(uint *)((int)pvVar7 + 8) = local_45c;
  uVar3 = (int)local_32c >> 0x1f;
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (local_32c < local_434) {
LAB_00422688:
      if (((local_32c <= local_434) && (uVar3 <= local_420)) &&
         ((local_420 != uVar3 || (local_32c <= local_41c)))) goto LAB_0042281c;
      *(undefined4 *)((int)pvVar7 + 0x18) = 2;
      *(uint *)((int)pvVar7 + 0x14) = local_41c;
      uVar3 = local_420;
      goto LAB_004226d0;
    }
    if (local_420 == 0) {
      if (local_41c < local_434) goto LAB_00422688;
      *(undefined4 *)((int)pvVar7 + 0x18) = 0;
    }
    else {
      *(undefined4 *)((int)pvVar7 + 0x18) = 0;
    }
LAB_0042280c:
    *(undefined4 *)((int)pvVar7 + 0x10) = 0;
    *(uint *)((int)pvVar7 + 0x14) = local_434;
  }
  else {
    if (local_434 <= local_32c) {
      *(undefined4 *)((int)pvVar7 + 0x18) = 0;
      goto LAB_0042280c;
    }
LAB_0042281c:
    *(undefined4 *)((int)pvVar7 + 0x18) = 1;
    *(uint *)((int)pvVar7 + 0x14) = local_32c;
LAB_004226d0:
    *(uint *)((int)pvVar7 + 0x10) = uVar3;
  }
  *(undefined4 *)((int)pvVar7 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  if ((wportal_info_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Add authed user timer: %llu, type: %d\n\n",
           "_wportal_authed_user_timer_handler",0x88d);
  }
  local_328 = FUN_00408340(*(undefined4 *)((int)pvVar7 + 0x14),0,_wportal_authed_user_timer_handler,
                           pvVar7,_wportal_authed_user_timer_handler_free,
                           "_wportal_authed_user_timer_handler",0x88e);
  if (local_328 != -1) {
    wportal_db_aut_set(auStack_470);
    return;
  }
  FUN_00407df0(pvVar7);
  if (wportal_debug_switch == 0) {
    return;
  }
  iVar6 = is_target_debug_ap();
  if (iVar6 == 0) {
    return;
  }
  __format = "[WPORTAL_DBG]%s()/%d Add timer error\n";
  uVar5 = 0x896;
LAB_00422550:
  printf(__format,"_wportal_authed_user_timer_handler",uVar5);
  return;
}

