// func _wportal_jcs_del_callback @ 004254c8 size=3480

void _wportal_jcs_del_callback(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  FILE *pFVar4;
  undefined2 uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int local_130;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  char local_11c [39];
  undefined1 local_f5;
  undefined1 local_b8;
  char local_9c [4];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  
  iVar1 = json_object_object_get(param_1,"type");
  if (iVar1 == 0) {
LAB_00425524:
    if (jcs_err_switch == 0) {
      return;
    }
    pcVar6 = "[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n";
    pcVar7 = "_wportal_jcs_del_callback";
    uVar8 = 0x2469;
    goto LAB_00425560;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    iVar1 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 != 2) goto LAB_00425524;
    uVar9 = json_object_get_double(iVar1);
    iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
  }
  if (iVar1 == 8) {
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Del nsa by mode id\n","_wportal_jcs_del_callback",0x248c);
    }
    _wportal_nsa_del_by_mode_id(param_1);
    return;
  }
  if (iVar1 < 9) {
    if (iVar1 == 3) {
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Del authed user\n","_wportal_jcs_del_callback",0x2478);
      }
      _wportal_authed_user_del(param_1,1);
      return;
    }
    if (3 < iVar1) {
      if (iVar1 == 4) {
        if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Del nsa\n","_wportal_jcs_del_callback",0x2487);
        }
        _wportal_nsa_del(param_1,1);
        return;
      }
      if (iVar1 != 7) {
        return;
      }
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Del authed user by mode id\n","_wportal_jcs_del_callback",
               0x247d);
      }
      _wportal_authed_user_del_by_mode_id(param_1);
      return;
    }
    if (iVar1 == 1) {
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Del page\n","_wportal_jcs_del_callback",0x246e);
      }
      _wportal_page_del(param_1);
      return;
    }
    if (iVar1 != 2) {
      return;
    }
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Del free strategy\n","_wportal_jcs_del_callback",0x2473);
    }
    _wportal_free_strategy_del(param_1);
    return;
  }
  if (iVar1 == 0xca) {
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Del radius entry\n","_wportal_jcs_del_callback",0x2496);
    }
    _wportal_radius_del(param_1);
    return;
  }
  if (iVar1 < 0xcb) {
    if (iVar1 != 9) {
      if (iVar1 != 10) {
        return;
      }
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Del nsa by username\n","_wportal_jcs_del_callback",0x2491);
      }
      memset(local_11c,0,0x65);
      iVar1 = json_object_object_get(param_1,"username");
      if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_wportal_nsa_del_by_username",0x1191);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar1);
      }
      strncpy(local_11c,pcVar6,100);
      local_b8 = 0;
      wportal_db_nsa_del_by_username(local_11c,_wportal_nsa_del_cb,0);
      return;
    }
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Del authed user by username\n","_wportal_jcs_del_callback",
             0x2482);
    }
    memset(local_11c,0,0x65);
    memset(local_9c,0,0x80);
    iVar1 = json_object_new_array();
    if (iVar1 != 0) {
      local_12c = 0;
      local_128 = 0;
      local_130 = iVar1;
      iVar1 = json_object_object_get(param_1,"username");
      if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_wportal_authed_user_del_by_username",0xe87);
        }
        pcVar6 = "";
      }
      else {
        pcVar6 = (char *)json_object_get_string(iVar1);
      }
      strncpy(local_11c,pcVar6,100);
      local_b8 = 0;
      wportal_db_aut_del_by_username(local_11c,_wportal_authed_user_del_cb,&local_130);
      if (local_12c != 0) {
        pcVar6 = (char *)json_object_to_json_string_ext(local_130,0);
        if (pcVar6 == (char *)0x0) {
          if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_ERR]%s()/%d JSON_STRING_FROM_OBJ fail!\n",
                   "_wportal_authed_user_del_by_username",0xe90);
          }
        }
        else {
          sVar3 = strlen(pcVar6);
          sprintf(local_9c,"%s_%d_%d","/tmp/wportal_authed_list_by_mode_id",del_id,local_128);
          pFVar4 = fopen(local_9c,"w+");
          if (pFVar4 == (FILE *)0x0) {
            if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[WPORTAL_DBG]%s()/%d open get file[%s] fail!\n",
                     "_wportal_authed_user_del_by_username",0xe99,local_9c);
            }
          }
          else {
            sVar3 = fwrite(pcVar6,sVar3,1,pFVar4);
            if (sVar3 == 1) {
              fclose(pFVar4);
              iVar1 = json_object_new_object();
              uVar8 = json_object_new_int(2);
              json_object_object_add(iVar1,"type",uVar8);
              uVar8 = json_object_new_int(local_12c);
              json_object_object_add(iVar1,"count",uVar8);
              uVar8 = json_object_new_string(local_9c);
              json_object_object_add(iVar1,"filename",uVar8);
              wportal_send_to_nginx(iVar1);
              if (iVar1 != 0) {
                json_object_put(iVar1);
              }
            }
            else {
              if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[WPORTAL_DBG]%s()/%d write result to file fail!\n",
                       "_wportal_authed_user_del_by_username",0xe9f);
              }
              fclose(pFVar4);
            }
          }
        }
      }
      if (local_130 == 0) {
        return;
      }
      json_object_put();
      return;
    }
    if (wportal_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    pcVar6 = "[WPORTAL_ERR]%s()/%d malloc json obj failed.\n";
    pcVar7 = "_wportal_authed_user_del_by_username";
    uVar8 = 0xe7f;
    goto LAB_00425560;
  }
  if (iVar1 != 300) {
    if (iVar1 != 0x2bd) {
      return;
    }
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Del all resource\n","_wportal_jcs_del_callback",0x24a0);
    }
    _wportal_page_del_all();
    memset(local_11c,0,0x80);
    iVar1 = json_object_new_array();
    if (iVar1 == 0) {
      if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d malloc json obj failed.\n","_wportal_authed_user_del_all",0xed8
              );
      }
    }
    else {
      local_12c = 0;
      local_128 = 0;
      local_130 = iVar1;
      wportal_db_aut_del_all(_wportal_authed_user_del_cb,&local_130);
      if (local_12c != 0) {
        pcVar6 = (char *)json_object_to_json_string_ext(local_130,0);
        if (pcVar6 == (char *)0x0) {
          if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_ERR]%s()/%d JSON_STRING_FROM_OBJ fail!\n",
                   "_wportal_authed_user_del_all",0xee6);
          }
        }
        else {
          sVar3 = strlen(pcVar6);
          sprintf(local_11c,"%s_%d_%d","/tmp/wportal_authed_list_by_mode_id",del_id,local_128);
          pFVar4 = fopen(local_11c,"w");
          if (pFVar4 == (FILE *)0x0) {
            if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[WPORTAL_DBG]%s()/%d open get file[%s] fail!\n","_wportal_authed_user_del_all"
                     ,0xeef,local_11c);
            }
          }
          else {
            sVar3 = fwrite(pcVar6,sVar3,1,pFVar4);
            if (sVar3 == 1) {
              fclose(pFVar4);
              iVar1 = json_object_new_object();
              uVar8 = json_object_new_int(2);
              json_object_object_add(iVar1,"type",uVar8);
              uVar8 = json_object_new_int(local_12c);
              json_object_object_add(iVar1,"count",uVar8);
              uVar8 = json_object_new_string(local_11c);
              json_object_object_add(iVar1,"filename",uVar8);
              wportal_send_to_nginx(iVar1);
              if (iVar1 != 0) {
                json_object_put(iVar1);
              }
            }
            else {
              if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[WPORTAL_DBG]%s()/%d write result to file fail!\n",
                       "_wportal_authed_user_del_all",0xef5);
              }
              fclose(pFVar4);
            }
          }
        }
      }
      if (local_130 != 0) {
        json_object_put();
      }
    }
    wportal_db_nsa_del_all(_wportal_nsa_del_cb,0);
    return;
  }
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Send cmcc ntf logout\n","_wportal_jcs_del_callback",0x249b);
  }
  memset(local_11c,0,0x28);
  local_9c[0] = '\0';
  local_9c[1] = '\0';
  local_9c[2] = '\0';
  local_9c[3] = '\0';
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_130 = 0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  iVar1 = json_object_object_get(param_1,&DAT_00677c24);
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_cmcc_send_ntf_logout",0x18f2);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_11c,pcVar6,0x27);
  local_f5 = 0;
  FUN_0051a7a8(local_11c,local_9c);
  iVar1 = json_object_object_get(param_1,"cmccServerIp");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_cmcc_send_ntf_logout",0x18f6);
    }
    pcVar6 = "";
  }
  else {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_11c,pcVar6,0x27);
  local_f5 = 0;
  if (local_11c[0] != '\0') {
    FUN_0051a7a8(local_11c,&local_130);
  }
  iVar1 = json_object_object_get(param_1,"serialNo");
  if (iVar1 == 0) {
LAB_00425bec:
    uVar5 = 0xffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_cmcc_send_ntf_logout",0x18fe);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar5 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_00425bec;
      uVar9 = json_object_get_double(iVar1);
      uVar5 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  iVar1 = json_object_object_get(param_1,"useChap");
  if (iVar1 == 0) {
LAB_00425c3c:
    uVar8 = 0xffffffff;
    if (jcs_err_switch == 0) goto LAB_00425c4c;
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_cmcc_send_ntf_logout",0x1902);
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar8 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_00425c3c;
      uVar9 = json_object_get_double(iVar1);
      uVar8 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
LAB_00425c4c:
  }
  if (local_9c[0] != '\x02') {
    ac_cmcc_send_ntf_logout(local_98,local_130,local_12c,local_128,local_124,local_120,uVar5,uVar8);
    return;
  }
  if (wportal_debug_switch == 0) {
    return;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return;
  }
  pcVar6 = "[WPORTAL_DBG]%s()/%d Not support ipv6.\n";
  pcVar7 = "_wportal_cmcc_send_ntf_logout";
  uVar8 = 0x1906;
LAB_00425560:
  printf(pcVar6,pcVar7,uVar8);
  return;
}

