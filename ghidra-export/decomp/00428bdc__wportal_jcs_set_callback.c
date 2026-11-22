// func _wportal_jcs_set_callback @ 00428bdc size=3176

void _wportal_jcs_set_callback(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__s2;
  int iVar4;
  undefined4 *__s;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  char cVar8;
  undefined8 uVar9;
  char local_40 [4];
  char local_3c [4];
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  
  iVar1 = json_object_object_get(param_1,"type");
  if (iVar1 == 0) {
LAB_00428c48:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_jcs_set_callback",0x24bf);
      uVar7 = 0;
      goto LAB_00428c5c;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_00428c48;
      uVar9 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
    if (iVar1 == 0x11) {
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(local_40), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Set https enable\n","_wportal_jcs_set_callback",0x2511);
      }
      local_40[0] = '\0';
      wportal_db_https_enable_get(local_40);
      iVar1 = json_object_object_get(param_1,"https_enable");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        iVar5 = 0;
        if (iVar2 == 6) {
          do {
            while( true ) {
              if (onoff_map <= iVar5) {
                if (jcs_err_switch == 0) goto LAB_00428eb8;
                pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                goto LAB_00429718;
              }
              iVar2 = iVar5 * 0x10;
              pcVar6 = *(char **)(PTR__mt_onoff_00731f8c + iVar2);
              if (pcVar6 != (char *)0x0) break;
              iVar5 = iVar5 + 1;
            }
            __s2 = (char *)json_object_get_string(iVar1);
            iVar4 = strcmp(pcVar6,__s2);
            iVar5 = iVar5 + 1;
          } while (iVar4 != 0);
          cVar8 = PTR__mt_onoff_00731f8c[iVar2 + 0xf];
        }
        else {
          if (jcs_err_switch != 0) {
            pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00429718:
            printf(pcVar6,"_wportal_https_enable_set",0x12bf);
          }
LAB_00428eb8:
          if (jcs_err_switch == 0) {
            cVar8 = -1;
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_wportal_https_enable_set",0x12bf);
            cVar8 = -1;
          }
        }
        if (local_40[0] != cVar8) {
          wportal_db_https_enable_set(cVar8);
          wportal_update_https_enable_to_ap(0,cVar8,1);
        }
      }
LAB_00428ef0:
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Set default portal page switch\n","_wportal_jcs_set_callback",
               0x2514);
      }
      _wportal_portal_page_switch_set_default(param_1);
      uVar7 = 0;
      goto LAB_00428c5c;
    }
    if (0x11 < iVar1) {
      if (iVar1 == 0xc9) {
        if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Set radius entry\n","_wportal_jcs_set_callback",0x24f9);
        }
        _wportal_radius_set(param_1);
        uVar7 = 0;
        goto LAB_00428c5c;
      }
      if (0xc9 < iVar1) {
        if (iVar1 == 0x191) {
          if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d Set sso config\n","_wportal_jcs_set_callback",0x250d);
          }
          _wportal_auth_para_sso_config_set(param_1);
          uVar7 = 0;
          goto LAB_00428c5c;
        }
        if (iVar1 != 0x192) {
          uVar7 = 0;
          if (iVar1 == 400) {
            if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[WPORTAL_INFO]%s()/%d Set auth mode\n","_wportal_jcs_set_callback",0x2508);
            }
            iVar1 = g_portal_auth_mode;
            local_3c[0] = '\0';
            local_3c[1] = '\0';
            local_3c[2] = '\0';
            local_3c[3] = '\0';
            local_38 = 0;
            local_34 = 0;
            local_30 = 0;
            local_2c = 0;
            iVar2 = json_object_object_get(param_1,"auth_mode");
            if ((iVar2 == 0) || (iVar5 = json_object_get_type(iVar2), iVar5 != 6)) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_wportal_auth_para_auth_mode_set",0x1244);
              }
              pcVar6 = "";
            }
            else {
              pcVar6 = (char *)json_object_get_string(iVar2);
            }
            iVar5 = 0;
            strncpy(local_3c,pcVar6,0x13);
            local_2c = local_2c & 0xffffff00;
            iVar2 = strcmp(local_3c,"ssid");
            if (iVar2 != 0) {
              iVar5 = 1;
              iVar2 = strcmp(local_3c,"vlan");
              if (iVar2 != 0) {
                iVar5 = 2;
                iVar2 = strcmp(local_3c,"interface");
                if (iVar2 != 0) {
                  iVar5 = -1;
                  iVar2 = strcmp(local_3c,"interface_ssid");
                  if (iVar2 == 0) {
                    iVar5 = 0;
                  }
                }
              }
            }
            uVar7 = 0;
            if (iVar1 != iVar5) {
              apmngr_reboot_all_ap(1,0);
              g_portal_auth_mode = iVar5;
            }
          }
          goto LAB_00428c5c;
        }
        goto LAB_00428ef0;
      }
      if (iVar1 == 0x65) {
        if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Set wechatlist update\n","_wportal_jcs_set_callback",0x24ea)
          ;
        }
        uVar7 = 0;
        wportal_wechatlist_getByNet();
        goto LAB_00428c5c;
      }
      if (iVar1 != 0x66) {
        uVar7 = 0;
        if (iVar1 == 100) {
          if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d Set wechatlist upload\n","_wportal_jcs_set_callback",
                   0x24e5);
          }
          iVar1 = wportal_wechatlist_getByFile();
          uVar7 = (uint)(iVar1 == -1);
        }
        goto LAB_00428c5c;
      }
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Set wechatlist mode\n","_wportal_jcs_set_callback",0x24cf);
      }
      iVar1 = json_object_object_get(param_1,&DAT_0067b7d8);
      if (iVar1 == 0) {
LAB_00429160:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_wportal_jcs_set_callback",0x24d2);
        }
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          iVar1 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_00429160;
          uVar9 = json_object_get_double(iVar1);
          iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
        }
        if (iVar1 == 1) {
          uVar7 = 0;
          wportal_wechatlist_start_autoupdate();
          goto LAB_00428c5c;
        }
      }
      uVar7 = 0;
      wportal_wechatlist_stop_autoupdate();
      goto LAB_00428c5c;
    }
    if (iVar1 != 0xb) {
      if (iVar1 < 0xc) {
        if (iVar1 == 2) {
          if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d Set free strategy\n","_wportal_jcs_set_callback",0x24c9);
          }
          _wportal_free_strategy_set(param_1);
          uVar7 = 0;
          goto LAB_00428c5c;
        }
        if (iVar1 != 5) {
          uVar7 = 0;
          if (iVar1 == 1) {
            if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[WPORTAL_INFO]%s()/%d Set page\n","_wportal_jcs_set_callback",0x24c4);
            }
            _wportal_page_set(param_1);
            uVar7 = 0;
          }
          goto LAB_00428c5c;
        }
        if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Set portal port\n","_wportal_jcs_set_callback",0x24e0);
        }
        iVar1 = json_object_object_get(param_1,"portal_port");
        if (iVar1 == 0) {
LAB_0042905c:
          uVar3 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_wportal_auth_para_port_set",0x11cd);
          }
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
            uVar3 = json_object_get_int(iVar1);
          }
          else {
            iVar2 = json_object_get_type();
            if (iVar2 != 2) goto LAB_0042905c;
            uVar9 = json_object_get_double(iVar1);
            uVar3 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
          }
        }
        uVar7 = 0;
        g_portal_port = uVar3;
        __s = (undefined4 *)FUN_00408450(0x18,0x11d3);
        if (__s != (undefined4 *)0x0) {
          memset(__s,0,0x18);
          __s[1] = uVar3;
          *__s = 8;
          serv_wtp_address_arg_init(local_3c);
          apmngr_db_get_all_addr_by_capacity(local_3c,1,1,0x15f0000,0);
          _wportal_update_to_ap(__s,0x18,local_3c,1);
          FUN_00407df0(__s);
          serv_wtp_address_arg_destroy(local_3c);
        }
        goto LAB_00428c5c;
      }
      if (iVar1 != 0xf) {
        if (iVar1 < 0x10) {
          uVar7 = 0;
          if (iVar1 != 0xd) goto LAB_00428c5c;
          if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d Set age enable\n","_wportal_jcs_set_callback",0x24f4);
          }
          local_3c[0] = '\0';
          local_3c[1] = '\0';
          local_3c[2] = '\0';
          local_3c[3] = '\0';
          local_38 = 0;
          iVar1 = json_object_object_get(param_1,"age_enable");
          if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_wportal_auth_para_age_enable_set",0x1226);
            }
            pcVar6 = "";
          }
          else {
            pcVar6 = (char *)json_object_get_string(iVar1);
          }
          strncpy(local_3c,pcVar6,7);
          local_38 = local_38 & 0xffffff00;
          iVar1 = strcmp(local_3c,"on");
          g_portal_age_enable = (uint)(iVar1 == 0);
          goto LAB_00428c58;
        }
        if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Set cmcc portal port\n","_wportal_jcs_set_callback",0x2503);
        }
        iVar1 = json_object_object_get(param_1,"cmcc_portal_port");
        if (iVar1 == 0) {
LAB_00429398:
          uVar3 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_wportal_auth_para_cmcc_portal_port_set",0x1266);
          }
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
            uVar3 = json_object_get_int(iVar1);
          }
          else {
            iVar2 = json_object_get_type();
            if (iVar2 != 2) goto LAB_00429398;
            uVar9 = json_object_get_double(iVar1);
            uVar3 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
          }
        }
        ac_cmcc_portal_port_set(uVar3);
        uVar7 = 0;
        goto LAB_00428c5c;
      }
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Set cmcc port\n","_wportal_jcs_set_callback",0x24fe);
      }
      iVar1 = json_object_object_get(param_1,"cmcc_port");
      if (iVar1 == 0) {
LAB_0042941c:
        uVar3 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_wportal_auth_para_cmcc_port_set",0x1280);
        }
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          uVar3 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0042941c;
          uVar9 = json_object_get_double(iVar1);
          uVar3 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
        }
      }
      uVar7 = ac_cmcc_port_set(uVar3);
      goto LAB_00428c5c;
    }
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Set age time\n","_wportal_jcs_set_callback",0x24ef);
    }
    iVar1 = json_object_object_get(param_1,"age_time");
    if (iVar1 == 0) {
LAB_00428da8:
      iVar1 = -1;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_auth_para_age_time_set",0x120a);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar1 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00428da8;
        uVar9 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
    }
    g_portal_age_time = iVar1 * 0x3c;
  }
LAB_00428c58:
  uVar7 = 0;
LAB_00428c5c:
  uVar3 = json_object_new_int(uVar7);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return;
}

