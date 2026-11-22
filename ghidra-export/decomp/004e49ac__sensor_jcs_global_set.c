// func _sensor_jcs_global_set @ 004e49ac size=3256

void _sensor_jcs_global_set(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  void *pvVar7;
  size_t __n;
  char *pcVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  int local_628;
  int local_624;
  void *local_620;
  undefined4 local_61c;
  undefined4 local_618;
  undefined4 local_614;
  uint local_610;
  char local_60c [256];
  undefined1 auStack_50c [300];
  int local_3e0;
  char acStack_3dc [49];
  undefined1 local_3ab;
  int local_3a2;
  char acStack_392 [64];
  undefined1 local_352;
  undefined1 auStack_300 [64];
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  iVar3 = g_sensor_enable;
  iVar10 = 0;
  memset(auStack_50c,0,0x205);
  iVar2 = json_object_object_get(param_1,"force_set");
  if (iVar2 != 0) {
    iVar10 = json_object_get_type(iVar2);
    iVar9 = 0;
    if (iVar10 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar9) {
            if (jcs_err_switch == 0) goto LAB_004e4a3c;
            pcVar8 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004e4d0c;
          }
          iVar10 = iVar9 * 0x10;
          pcVar8 = *(char **)(PTR__mt_onoff_00731f8c + iVar10);
          if (pcVar8 != (char *)0x0) break;
          iVar9 = iVar9 + 1;
        }
        pcVar5 = (char *)json_object_get_string(iVar2);
        iVar6 = strcmp(pcVar8,pcVar5);
        iVar9 = iVar9 + 1;
      } while (iVar6 != 0);
      iVar10 = *(int *)(PTR__mt_onoff_00731f8c + iVar10 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar8 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004e4d0c:
        printf(pcVar8,"_sensor_jcs_global_set",0x73f);
      }
LAB_004e4a3c:
      if (jcs_err_switch == 0) {
        iVar10 = -1;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_sensor_jcs_global_set"
               ,0x73f);
        iVar10 = -1;
      }
    }
  }
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if ((g_change_backhaul_wserv != 0) && (iVar10 == 0)) {
    memset(local_60c,0,0x100);
    snprintf(local_60c,0x100,"%d",0xfffffff3);
    uVar4 = json_object_new_string(local_60c);
    json_object_object_add(param_2,&DAT_00676a24,uVar4);
    goto LAB_004e4fd0;
  }
  iVar2 = json_object_object_get(param_1,"enable");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    iVar9 = 0;
    if (iVar3 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar9) {
            if (jcs_err_switch == 0) goto LAB_004e4ab0;
            pcVar8 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004e4e68;
          }
          iVar3 = iVar9 * 0x10;
          pcVar8 = *(char **)(PTR__mt_onoff_00731f8c + iVar3);
          if (pcVar8 != (char *)0x0) break;
          iVar9 = iVar9 + 1;
        }
        pcVar5 = (char *)json_object_get_string(iVar2);
        iVar6 = strcmp(pcVar8,pcVar5);
        iVar9 = iVar9 + 1;
      } while (iVar6 != 0);
      iVar3 = *(int *)(PTR__mt_onoff_00731f8c + iVar3 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar8 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004e4e68:
        printf(pcVar8,"_sensor_jcs_global_set",0x749);
      }
LAB_004e4ab0:
      if (jcs_err_switch == 0) {
        iVar3 = -1;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_sensor_jcs_global_set"
               ,0x749);
        iVar3 = -1;
      }
    }
  }
  iVar2 = json_object_object_get(param_1,"backhaul_wserv_id");
  if (iVar2 != 0) {
    iVar9 = json_object_get_type(iVar2);
    if (iVar9 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar2);
      g_backhaul_wserv_id = atoi(pcVar8);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "_sensor_jcs_global_set",0x74c);
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","_sensor_jcs_global_set"
               ,0x74c);
      }
      g_backhaul_wserv_id = -1;
    }
  }
  if (g_sensor_enable == iVar3) {
    if ((iVar3 != 0) && (iVar2 = json_object_object_get(param_1,"wserv_cfg_change"), iVar2 != 0)) {
      iVar10 = json_object_get_type(iVar2);
      if (iVar10 == 3) {
        iVar2 = json_object_get_int(iVar2);
LAB_004e5054:
        if (iVar2 == 0) goto LAB_004e4b28;
      }
      else {
        iVar10 = json_object_get_type();
        if (iVar10 == 2) {
          uVar11 = json_object_get_double(iVar2);
          iVar2 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
          goto LAB_004e5054;
        }
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_sensor_jcs_global_set",0x75e);
        }
      }
      iVar2 = wserv_db_get_entry_by_id(g_backhaul_wserv_id,auStack_50c);
      if (iVar2 != 0) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d Get backhaul wservice(%d) failed\n","_sensor_jcs_global_set"
                 ,0x763,g_backhaul_wserv_id);
        }
        iVar3 = FUN_00408340(2,0,_update_backhaul_to_wserv_cfg_immediately,0,0,
                             "_sensor_jcs_global_set",0x764);
        if (iVar3 == -1) {
          _clear_backhaul_wserv_cfg();
          memset(local_60c,0,0x100);
          snprintf(local_60c,0x100,"%d",0xffffffff);
          uVar4 = json_object_new_string(local_60c);
          json_object_object_add(param_2,&DAT_00676a24,uVar4);
        }
LAB_004e4fd0:
        FUN_00407f30(g_sensor_mngt_mutex);
        return;
      }
      iVar2 = json_object_object_get(param_1,"backhaul_ssid");
      if ((iVar2 == 0) || (iVar10 = json_object_get_type(iVar2), iVar10 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_sensor_jcs_global_set",0x76d);
        }
        pcVar8 = "";
      }
      else {
        pcVar8 = (char *)json_object_get_string(iVar2);
      }
      strncpy(acStack_3dc,pcVar8,0x31);
      local_3ab = 0;
      iVar2 = json_object_object_get(param_1,"backhaul_encode");
      if (iVar2 == 0) {
LAB_004e5194:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "_sensor_jcs_global_set",0x76f);
        }
        local_3e0 = -1;
      }
      else {
        iVar10 = json_object_get_type(iVar2);
        if (iVar10 != 6) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "_sensor_jcs_global_set",0x76f);
          }
          goto LAB_004e5194;
        }
        pcVar8 = (char *)json_object_get_string(iVar2);
        local_3e0 = atoi(pcVar8);
      }
      if ((local_3a2 == 1) || (local_3a2 == 4)) {
        iVar2 = json_object_object_get(param_1,"backhaul_key");
        if ((iVar2 == 0) || (iVar10 = json_object_get_type(iVar2), iVar10 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_sensor_jcs_global_set",0x773);
          }
          pcVar8 = "";
        }
        else {
          pcVar8 = (char *)json_object_get_string(iVar2);
        }
        strncpy(acStack_392,pcVar8,0x40);
        local_352 = 0;
      }
      local_628 = 0;
      local_624 = 0;
      local_620 = (void *)0x0;
      memset(auStack_300,0,0x2d8);
      local_60c[0] = '\0';
      local_60c[1] = '\0';
      local_60c[2] = '\0';
      local_60c[3] = '\0';
      local_60c[4] = '\0';
      local_60c[5] = '\0';
      local_60c[6] = '\0';
      local_60c[7] = '\0';
      local_60c[8] = '\0';
      local_60c[9] = '\0';
      local_60c[10] = '\0';
      local_60c[0xb] = '\0';
      local_60c[0xc] = '\0';
      local_60c[0xd] = '\0';
      local_60c[0xe] = '\0';
      local_60c[0xf] = '\0';
      local_60c[0x10] = '\0';
      local_60c[0x11] = '\0';
      local_60c[0x12] = '\0';
      local_60c[0x13] = '\0';
      local_60c[0x14] = '\0';
      local_60c[0x15] = '\0';
      local_60c[0x16] = '\0';
      local_60c[0x17] = '\0';
      local_61c = 0;
      local_618 = 0;
      local_614 = 0;
      local_610 = 0;
      local_624 = apmngr_db_get_sensor_max();
      local_620 = (void *)FUN_00408450(local_624 << 1,0x6e9);
      if (local_620 == (void *)0x0) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","_update_backhaul_to_sensor_all",0x6ec);
        }
      }
      else {
        memset(local_620,0,local_624 << 1);
        apmngr_db_foreach_proc(0x800000,_online_sensor_id_collect,&local_628);
        g_change_backhaul_wserv = 1;
        if ((local_620 != (void *)0x0) && (0 < local_628)) {
          iVar2 = apmngr_db_get_sensor_max();
          pvVar7 = (void *)FUN_00408450(iVar2 << 2,0x6f4);
          sensor_backhaul_set_pkt_id_list = pvVar7;
          if (pvVar7 != (void *)0x0) {
            iVar2 = apmngr_db_get_sensor_max();
            memset(pvVar7,-1,iVar2 << 2);
            uVar4 = apmngr_db_get_sensor_max();
            pvVar7 = (void *)FUN_00408450(uVar4,0x6fb);
            sensor_backhaul_set_id_map = pvVar7;
            if (pvVar7 != (void *)0x0) {
              __n = apmngr_db_get_sensor_max();
              iVar2 = 0;
              memset(pvVar7,-1,__n);
LAB_004e52ec:
              if (iVar2 < local_628) {
                iVar9 = iVar2 * 2;
                iVar10 = sensor_db_get(*(undefined2 *)((int)local_620 + iVar9),local_60c,0);
                if ((iVar10 == 0) &&
                   (iVar10 = apmngr_db_entry_get_by_id
                                       (*(undefined2 *)((int)local_620 + iVar9),auStack_300),
                   iVar10 == 0)) {
                  iVar10 = apdb_get_radio_extend_capability
                                     (local_2c0,auStack_e8,1,0xffffffff,&local_61c,0x10);
                  if (iVar10 == 0) {
                    if ((local_610 & 0x40) != 0) {
                      if (local_60c[4] != '\0') {
                        _sensor_backhaul_ssid_send
                                  (*(undefined2 *)((int)local_620 + iVar9),local_60c + 5,1,
                                   auStack_50c,2,0);
                      }
                      iVar10 = _sensor_backhaul_ssid_send
                                         ((uint)*(ushort *)((int)local_620 + iVar9),0,0,auStack_50c,
                                          2,(void *)((int)sensor_backhaul_set_pkt_id_list +
                                                    (*(ushort *)((int)local_620 + iVar9) - 50000) *
                                                    4));
                      iVar2 = iVar2 + 1;
                      if (iVar10 == 0) {
                        sensor_backhaul_set_total = sensor_backhaul_set_total + 1;
                        *(undefined1 *)
                         ((int)sensor_backhaul_set_id_map +
                         (*(ushort *)((int)local_620 + iVar9) - 50000)) = 0;
                      }
                      goto LAB_004e52ec;
                    }
                    if (sensor_warning_switch == '\0') {
                      iVar2 = iVar2 + 1;
                      goto LAB_004e52ec;
                    }
                    pcVar8 = "[SENSOR_WARNING]%s()/%d Sensor not support backhaul\n";
                    uVar4 = 0x70f;
                  }
                  else {
                    if (sensor_err_switch == '\0') {
                      iVar2 = iVar2 + 1;
                      goto LAB_004e52ec;
                    }
                    pcVar8 = "[SENSOR_ERROR]%s()/%d apdb_get_radio_extend_capability failed\n";
                    uVar4 = 0x70a;
                  }
LAB_004e533c:
                  iVar2 = iVar2 + 1;
                  printf(pcVar8,"_update_backhaul_to_sensor_all",uVar4);
                  goto LAB_004e52ec;
                }
                if (sensor_err_switch != '\0') {
                  uVar4 = 0x705;
                  pcVar8 = 
                  "[SENSOR_ERROR]%s()/%d sensor_db_get/apmngr_db_entry_get_by_id failed or role error or not firmed\n"
                  ;
                  goto LAB_004e533c;
                }
                iVar2 = iVar2 + 1;
                goto LAB_004e52ec;
              }
              if ((0 < sensor_backhaul_set_total) &&
                 (sensor_backhaul_set_timer =
                       FUN_00408340(0x3c,0,_update_backhaul_to_wserv_cfg_timeout,0,0,
                                    "_update_backhaul_to_sensor_all",0x71e),
                 sensor_backhaul_set_timer != -1)) {
                bVar1 = false;
                FUN_00407df0();
                goto LAB_004e4b2c;
              }
            }
          }
        }
      }
      if (local_620 != (void *)0x0) {
        FUN_00407df0();
      }
      bVar1 = false;
      FUN_00408340(2,0,_update_backhaul_to_wserv_cfg_immediately,0,0,
                   "_update_backhaul_to_sensor_all",0x733);
      goto LAB_004e4b2c;
    }
  }
  else {
    g_sensor_enable = iVar3;
    if (iVar3 == 0) {
      local_628 = 0;
      local_624 = 0;
      local_620 = (void *)0x0;
      local_624 = apmngr_db_get_sensor_max();
      local_620 = (void *)FUN_00408450(local_624 << 1,0x6b7);
      if (local_620 == (void *)0x0) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","_delete_all_sensor",0x6ba);
        }
      }
      else {
        memset(local_620,0,local_624 << 1);
        apmngr_db_foreach_proc(0x800000,_sensor_id_collect,&local_628);
        if (0 < local_628) {
          FUN_00407e80("_delete_all_sensor");
          apmngr_ap_delete(local_620,local_628,0,0,1);
          FUN_004082b0(1,"_delete_all_sensor");
        }
        FUN_00407df0(local_620);
      }
      bVar1 = true;
      _sensor_discover_reset(0);
      if ((iVar10 != 0) && (g_change_backhaul_wserv != 0)) {
        FUN_00408340(2,0,_update_backhaul_to_wserv_cfg_immediately,0,0,"_sensor_jcs_global_set",
                     0x756);
      }
      goto LAB_004e4b2c;
    }
  }
LAB_004e4b28:
  bVar1 = false;
LAB_004e4b2c:
  FUN_00407f30(g_sensor_mngt_mutex);
  if (bVar1) {
    if (sensor_debug_switch != '\0') {
      uVar4 = FUN_00407fe0(&l_status_change_callback_list);
      printf("[SENSOR_DEBUG]%s()/%d callback list length:%d\n",
             "_sensor_status_change_proc_callback_list",0x474,uVar4);
    }
    for (iVar2 = FUN_004081b0(&l_status_change_callback_list); iVar2 != 0;
        iVar2 = FUN_00408680(iVar2)) {
      if (((*(code **)(iVar2 + 0xc) != (code *)0x0) &&
          (iVar10 = (**(code **)(iVar2 + 0xc))(iVar3), iVar10 == -1)) &&
         (sensor_debug_switch != '\0')) {
        printf("[SENSOR_DEBUG]%s()/%d process callback update_all for module failed.\n",
               "_sensor_status_change_proc_callback_list",0x47e);
      }
    }
  }
  memset(local_60c,0,0x100);
  snprintf(local_60c,0x100,"%d",0);
  uVar4 = json_object_new_string(local_60c);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  return;
}

