// func ucl_auth_db_init @ 004a8478 size=1144

/* WARNING: Type propagation algorithm not settling */

undefined4 ucl_auth_db_init(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int local_88;
  int local_84 [2];
  undefined1 *local_7c;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  char *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  int *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  char *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  int *local_18;
  undefined4 local_14;
  
  local_84[0] = 0;
  uac_list_init(&g_first_report_list);
  uac_list_init(&g_offline_station_list);
  iVar1 = uac_profile_get_int("wportal","sessmngr_max",local_84);
  if (iVar1 != 0) {
    local_84[0] = 100000;
  }
  g_offline_station_hash =
       uac_hash_new_fixed(_ucl_auth_offline_station_obj_func,_ucl_auth_offline_station_key_func,
                          _ucl_auth_offline_station_cmp_func,local_84[0] >> 3);
  if (g_offline_station_hash == 0) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x275;
    pcVar3 = "[UCL_AUTH_ERR]%s()/%d Create g_offline_station_hash failed.\n";
    goto LAB_004a86d0;
  }
  g_first_report_mutex = uac_mutex_create("ucl_auth_first_report",1);
  if (g_first_report_mutex == 0) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x27c;
    pcVar3 = "[UCL_AUTH_ERR]%s()/%d Create mutex error\n";
    goto LAB_004a86d0;
  }
  g_offline_station_mutex = uac_mutex_create("ucl_auth_offline",1);
  if (g_offline_station_mutex == 0) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x283;
    pcVar3 = "[UCL_AUTH_ERR]%s()/%d Create mutex error\n";
    goto LAB_004a86d0;
  }
  local_88 = 0;
  memcpy(auStack_78,PTR_DAT_007591ac + 0x18a0,0x20);
  local_18 = &local_88;
  local_84[1] = 2;
  local_48 = local_84 + 1;
  local_30 = "bind_status";
  pcVar3 = "enable";
  local_34 = 0;
  local_1a = 4;
  local_3e = 4;
  local_3c = &local_88;
  local_2c = 0;
  local_28 = 1;
  local_24 = 0;
  local_20 = 10;
  local_1c = 1;
  local_14 = 0;
  local_58 = 0;
  local_50 = 0;
  local_4c = 1;
  local_44 = 10;
  local_40 = 1;
  local_38 = 0;
  local_7c = auStack_78;
  local_54 = pcVar3;
  iVar1 = uac_com_uci_parse_req("cloud_config","bind_info",&local_34,1);
  if (iVar1 == 0) {
    ucl_auth_db_set_bind_status(local_88);
    if (ucl_info_switch != 0) {
      if (local_88 != 1) {
        pcVar3 = "disable";
      }
      printf("[UCL_AUTH_INFO]%s()/%d Set bind status %s.\n","ucl_auth_db_global_config_read",0x244,
             pcVar3);
    }
    iVar1 = uac_com_uci_parse_req("ucl_auth","settings",&local_58,1);
    if (iVar1 == 0) {
      ucl_auth_db_set_switch_status(local_88);
      if (ucl_info_switch != 0) {
        pcVar3 = "enable";
        if (local_88 != 1) {
          pcVar3 = "disable";
        }
        printf("[UCL_AUTH_INFO]%s()/%d Set ucl auth %s.\n","ucl_auth_db_global_config_read",0x250,
               pcVar3);
      }
      iVar1 = access("/tmp/ucl_cloud_online",0);
      if (iVar1 == 0) {
        ucl_auth_db_set_cloud_status(1);
      }
      iVar1 = ucl_auth_db_get_bind_status();
      if (iVar1 != 1) {
        return 0;
      }
      iVar1 = ucl_auth_db_get_switch_status();
      if (iVar1 != 1) {
        return 0;
      }
      ucl_auth_db_set_station_report_switch_enable(1);
      iVar1 = ucl_auth_db_get_cloud_status();
      if (iVar1 != 1) {
        return 0;
      }
      ucl_auth_db_set_first_report_finish(0);
      ucl_auth_db_set_notify_first_report(2);
      return 0;
    }
    if (ucl_err_switch != 0) {
      uVar2 = 0x24b;
      pcVar3 = "[UCL_AUTH_ERR]%s()/%d uci req parse failed.\n";
      goto LAB_004a86f4;
    }
  }
  else if (ucl_err_switch != 0) {
    uVar2 = 0x23f;
    pcVar3 = "[UCL_AUTH_ERR]%s()/%d uci cloud req parse failed.\n";
LAB_004a86f4:
    printf(pcVar3,"ucl_auth_db_global_config_read",uVar2);
  }
  if (ucl_err_switch == 0) {
    return 0xffffffff;
  }
  uVar2 = 0x289;
  pcVar3 = "[UCL_AUTH_ERR]%s()/%d Ucl auth read global config failed.\n";
LAB_004a86d0:
  printf(pcVar3,"ucl_auth_db_init",uVar2);
  return 0xffffffff;
}

