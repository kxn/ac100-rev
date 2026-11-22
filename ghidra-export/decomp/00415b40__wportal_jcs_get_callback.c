// func _wportal_jcs_get_callback @ 00415b40 size=3868

/* WARNING: Type propagation algorithm not settling */

void _wportal_jcs_get_callback(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  FILE *pFVar3;
  undefined4 uVar4;
  char *pcVar5;
  size_t sVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  char *pcVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  uint local_1c0;
  undefined4 local_1bc;
  undefined2 local_1b8;
  char local_1b4 [16];
  uint local_1a4;
  undefined4 local_1a0 [6];
  undefined1 auStack_188 [112];
  undefined1 auStack_118 [112];
  undefined1 auStack_a8 [128];
  
  iVar1 = json_object_object_get(param_1,"type");
  if (iVar1 == 0) {
LAB_00415bb0:
    if (jcs_err_switch == 0) {
      return;
    }
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_jcs_get_callback",0x23e5);
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    iVar1 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 != 2) goto LAB_00415bb0;
    uVar12 = json_object_get_double(iVar1);
    iVar1 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
  }
  if (iVar1 == 0x138) {
    _wportal_get_ssid_by_serv_id(param_1,param_2);
    return;
  }
  if (0x138 < iVar1) {
    if (iVar1 == 0x13a) {
      local_1b4[0] = '\0';
      local_1b4[1] = '\0';
      local_1b4[2] = '\0';
      local_1b4[3] = '\0';
      local_1b4[4] = '\0';
      local_1b4[5] = '\0';
      local_1b4[6] = '\0';
      local_1b4[7] = '\0';
      local_1b4[8] = '\0';
      local_1b4[9] = '\0';
      local_1b4[10] = '\0';
      local_1b4[0xb] = '\0';
      local_1b4[0xc] = '\0';
      local_1b4[0xd] = '\0';
      local_1b4[0xe] = '\0';
      local_1b4[0xf] = '\0';
      local_1a4 = 0;
      local_1bc = 0;
      local_1b8 = 0;
      local_1a0[0] = 0;
      local_1a0[1] = 0;
      local_1a0[2] = 0;
      local_1a0[3] = 0;
      local_1a0[4] = 0;
      local_1a0[5] = 0;
      memset(auStack_a8,0,0x80);
      iVar1 = json_object_object_get(param_1,"mac");
      if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_wportal_get_is_online_by_mac",0x23ad);
        }
        pcVar5 = "";
      }
      else {
        pcVar5 = (char *)json_object_get_string(iVar1);
      }
      strncpy(local_1b4,pcVar5,0x13);
      local_1a4 = local_1a4 & 0xffffff00;
      if (local_1b4[0] != '\0') {
        sscanf(local_1b4,"%2X-%2X-%2X-%2X-%2X-%2X",local_1a0,local_1a0 + 1,local_1a0 + 2,
               local_1a0 + 3,local_1a0 + 4,local_1a0 + 5);
        puVar7 = local_1a0;
        iVar1 = 0;
        do {
          puVar8 = (undefined1 *)((int)&local_1bc + iVar1);
          uVar11 = *puVar7;
          iVar1 = iVar1 + 1;
          puVar7 = puVar7 + 1;
          *puVar8 = (char)uVar11;
        } while (iVar1 != 6);
      }
      iVar1 = wsta_db_get_entry_by_mac(&local_1bc,auStack_a8);
      uVar11 = json_object_new_int(iVar1 == 0);
      pcVar5 = "is_online";
      goto LAB_004160c0;
    }
    if (iVar1 < 0x13a) {
      _wportal_get_stream_load_by_mac(param_1,param_2);
      return;
    }
    if (iVar1 != 0x13b) {
      return;
    }
    local_1c0 = 0;
    uVar10 = wportal_db_authed_list_size_get();
    local_1c0 = uVar10;
    pFVar3 = fopen("/tmp/wportal_authed_stream_list","w+");
    if (pFVar3 == (FILE *)0x0) {
      uVar11 = 0;
      if (wportal_debug_switch != 0) {
        iVar1 = is_target_debug_ap(0);
        if (iVar1 == 0) {
          uVar11 = 0;
        }
        else {
          printf("[WPORTAL_DBG]%s()/%d open get file[%s] fail!\n","_wportal_get_all_stream_load",
                 0x2266,"/tmp/wportal_authed_stream_list");
          uVar11 = 0;
        }
      }
      goto LAB_00416220;
    }
    iVar1 = json_object_new_array();
    if (iVar1 == 0) {
      if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
        if (pFVar3 != (FILE *)0x0) goto LAB_0041662c;
        uVar11 = 0;
      }
      else {
        printf("[WPORTAL_ERR]%s()/%d malloc json obj failed.\n","_wportal_get_all_stream_load",
               0x226c);
        if (pFVar3 != (FILE *)0x0) goto LAB_0041662c;
        uVar11 = 0;
      }
    }
    else {
      iVar2 = wportal_db_authed_list_range_handle
                        (0,uVar10,_wportal_authed_user_stream_json_add_callback,iVar1,0,0,0,
                         &local_1c0);
      if (iVar2 == -1) {
        if (wportal_err_switch != 0) {
          iVar2 = is_target_debug_ap();
          uVar11 = 0x2284;
          if (iVar2 != 0) {
            pcVar5 = "[WPORTAL_ERR]%s()/%d get authed list failed\n";
LAB_00416778:
            printf(pcVar5,"_wportal_get_all_stream_load",uVar11);
          }
        }
      }
      else {
        pcVar5 = (char *)json_object_to_json_string_ext(iVar1,0);
        if (pcVar5 == (char *)0x0) {
          if (wportal_err_switch != 0) {
            iVar2 = is_target_debug_ap();
            uVar11 = 0x228b;
            if (iVar2 != 0) {
              pcVar5 = "[WPORTAL_ERR]%s()/%d JSON_STRING_FROM_OBJ fail!\n";
              goto LAB_00416778;
            }
          }
        }
        else {
          sVar6 = strlen(pcVar5);
          sVar6 = fwrite(pcVar5,sVar6,1,pFVar3);
          if (sVar6 == 1) {
            fclose(pFVar3);
            json_object_put(iVar1);
            uVar11 = json_object_new_string("/tmp/wportal_authed_stream_list");
            json_object_object_add(param_2,"file_name",uVar11);
            uVar11 = json_object_new_int(local_1c0);
            json_object_object_add(param_2,"totalNum",uVar11);
            uVar11 = 1;
            goto LAB_00416220;
          }
          if (wportal_err_switch != 0) {
            iVar2 = is_target_debug_ap();
            uVar11 = 0x2293;
            if (iVar2 != 0) {
              pcVar5 = "[WPORTAL_ERR]%s()/%d write result to file fail!\n";
              goto LAB_00416778;
            }
          }
        }
      }
      json_object_put(iVar1);
LAB_0041662c:
      fclose(pFVar3);
      uVar11 = 0;
    }
LAB_00416220:
    uVar11 = json_object_new_int(uVar11);
    pcVar5 = "ret";
    goto LAB_004160c0;
  }
  if (iVar1 == 4) {
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Get nsa user\n","_wportal_jcs_get_callback",0x23ef);
    }
    memset(auStack_188,0,0x70);
    local_1c0 = wportal_db_nsa_list_size_get();
    iVar1 = json_object_object_get(param_1,"start");
    if (iVar1 == 0) {
LAB_00415ec4:
      uVar10 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_get",0xfe5);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar10 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00415ec4;
        uVar12 = json_object_get_double(iVar1);
        uVar10 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
    }
    iVar1 = json_object_object_get(param_1,"size");
    if (iVar1 == 0) {
LAB_00415f14:
      uVar11 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_get",0xfe7);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar11 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00415f14;
        uVar12 = json_object_get_double(iVar1);
        uVar11 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
    }
    iVar1 = json_object_object_get(param_1,"search");
    if (iVar1 == 0) {
LAB_00415f64:
      iVar1 = -1;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_nsa_get",0xfe9);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar1 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00415f64;
        uVar12 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
    }
    if (local_1c0 <= uVar10) {
      uVar10 = 0;
    }
    pFVar3 = fopen("/tmp/wportal_nsa_list","w+");
    if (pFVar3 == (FILE *)0x0) {
      uVar11 = 0;
      if (wportal_debug_switch != 0) {
        iVar1 = is_target_debug_ap(0);
        if (iVar1 != 0) {
          pcVar5 = "_wportal_nsa_get";
          uVar11 = 0xff2;
          pcVar9 = "/tmp/wportal_nsa_list";
          goto LAB_00416844;
        }
        uVar11 = 0;
      }
    }
    else {
      iVar2 = json_object_new_array();
      if (iVar2 != 0) {
        if (iVar1 == 0) {
          iVar1 = wportal_db_nsa_list_range_handle
                            (uVar10,uVar11,_wportal_nsa_user_json_add_callback,iVar2,0,0,0,
                             &local_1c0);
          if (iVar1 == -1) {
            if ((wportal_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_00416370;
            pcVar5 = "[WPORTAL_DBG]%s()/%d get nsa list failed\n";
            pcVar9 = "_wportal_nsa_get";
            uVar11 = 0x1010;
            goto LAB_00416368;
          }
LAB_00416024:
          pcVar5 = (char *)json_object_to_json_string_ext(iVar2,0);
          if (pcVar5 == (char *)0x0) {
            if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar5 = "[WPORTAL_ERR]%s()/%d JSON_STRING_FROM_OBJ fail!\n";
              pcVar9 = "_wportal_nsa_get";
              uVar11 = 0x1017;
              goto LAB_00416368;
            }
          }
          else {
            sVar6 = strlen(pcVar5);
            sVar6 = fwrite(pcVar5,sVar6,1,pFVar3);
            if (sVar6 == 1) {
              fclose(pFVar3);
              json_object_put(iVar2);
              pcVar5 = "/tmp/wportal_nsa_list";
              goto LAB_00416074;
            }
            if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar5 = "[WPORTAL_DBG]%s()/%d write result to file fail!\n";
              pcVar9 = "_wportal_nsa_get";
              uVar11 = 0x101f;
              goto LAB_00416368;
            }
          }
        }
        else {
          uVar4 = json_object_object_get(param_1,"search_arg");
          iVar1 = _wportal_search_arg_parse(auStack_188,uVar4);
          if (iVar1 != -1) {
            iVar1 = wportal_db_nsa_list_range_handle
                              (uVar10,uVar11,_wportal_nsa_user_json_add_callback,iVar2,1,
                               _wportal_nsa_match_callback,auStack_188,&local_1c0);
            if (iVar1 != -1) goto LAB_00416024;
            if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar5 = "[WPORTAL_DBG]%s()/%d get nsa list failed\n";
              pcVar9 = "_wportal_nsa_get";
              uVar11 = 0x1007;
              goto LAB_00416368;
            }
          }
        }
        goto LAB_00416370;
      }
      if ((wportal_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_00416980;
      pcVar5 = "_wportal_nsa_get";
      uVar11 = 0xff8;
LAB_004169b0:
      printf("[WPORTAL_ERR]%s()/%d malloc json obj failed.\n",pcVar5,uVar11);
      if (pFVar3 != (FILE *)0x0) goto LAB_00416378;
      uVar11 = 0;
    }
  }
  else {
    if (iVar1 == 0x136) {
      _wportal_get_ssid_page(param_1,param_2);
      return;
    }
    if (iVar1 != 3) {
      return;
    }
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Get authed user\n","_wportal_jcs_get_callback",0x23ea);
    }
    local_1c0 = 0;
    memset(auStack_118,0,0x70);
    iVar1 = json_object_object_get(param_1,"start");
    if (iVar1 == 0) {
LAB_00415ca4:
      uVar10 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_authed_user_get",0xaa2);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar10 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00415ca4;
        uVar12 = json_object_get_double(iVar1);
        uVar10 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
    }
    iVar1 = json_object_object_get(param_1,"size");
    if (iVar1 == 0) {
LAB_00415cf4:
      uVar11 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_authed_user_get",0xaa4);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar11 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00415cf4;
        uVar12 = json_object_get_double(iVar1);
        uVar11 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
    }
    iVar1 = json_object_object_get(param_1,"search");
    if (iVar1 == 0) {
LAB_00415d44:
      iVar1 = -1;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_authed_user_get",0xaa6);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar1 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_00415d44;
        uVar12 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
    }
    local_1c0 = wportal_db_authed_list_size_get();
    if (local_1c0 <= uVar10) {
      uVar10 = 0;
    }
    pFVar3 = fopen("/tmp/wportal_authed_list","w+");
    if (pFVar3 == (FILE *)0x0) {
      uVar11 = 0;
      if (wportal_debug_switch != 0) {
        iVar1 = is_target_debug_ap(0);
        if (iVar1 == 0) {
          uVar11 = 0;
        }
        else {
          pcVar5 = "_wportal_authed_user_get";
          uVar11 = 0xab1;
          pcVar9 = "/tmp/wportal_authed_list";
LAB_00416844:
          printf("[WPORTAL_DBG]%s()/%d open get file[%s] fail!\n",pcVar5,uVar11,pcVar9);
          uVar11 = 0;
        }
      }
    }
    else {
      iVar2 = json_object_new_array();
      if (iVar2 == 0) {
        if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar5 = "_wportal_authed_user_get";
          uVar11 = 0xab7;
          goto LAB_004169b0;
        }
LAB_00416980:
        if (pFVar3 != (FILE *)0x0) goto LAB_00416378;
        uVar11 = 0;
      }
      else {
        if (iVar1 == 0) {
          iVar1 = wportal_db_authed_list_range_handle
                            (uVar10,uVar11,_wportal_authed_user_json_add_callback,iVar2,0,0,0,
                             &local_1c0);
          if (iVar1 == -1) {
            if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar5 = "[WPORTAL_ERR]%s()/%d get authed list failed\n";
              pcVar9 = "_wportal_authed_user_get";
              uVar11 = 0xacf;
LAB_00416368:
              printf(pcVar5,pcVar9,uVar11);
            }
          }
          else {
LAB_00415e08:
            pcVar5 = (char *)json_object_to_json_string_ext(iVar2,0);
            if (pcVar5 == (char *)0x0) {
              if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar5 = "[WPORTAL_ERR]%s()/%d JSON_STRING_FROM_OBJ fail!\n";
                pcVar9 = "_wportal_authed_user_get";
                uVar11 = 0xad6;
                goto LAB_00416368;
              }
            }
            else {
              sVar6 = strlen(pcVar5);
              sVar6 = fwrite(pcVar5,sVar6,1,pFVar3);
              if (sVar6 == 1) {
                fclose(pFVar3);
                json_object_put(iVar2);
                pcVar5 = "/tmp/wportal_authed_list";
LAB_00416074:
                uVar11 = json_object_new_string(pcVar5);
                json_object_object_add(param_2,"file_name",uVar11);
                uVar11 = json_object_new_int(local_1c0);
                json_object_object_add(param_2,"totalNum",uVar11);
                uVar11 = 1;
                goto LAB_004160b0;
              }
              if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar5 = "[WPORTAL_ERR]%s()/%d write result to file fail!\n";
                pcVar9 = "_wportal_authed_user_get";
                uVar11 = 0xade;
                goto LAB_00416368;
              }
            }
          }
        }
        else {
          uVar4 = json_object_object_get(param_1,"search_arg");
          iVar1 = _wportal_search_arg_parse(auStack_118,uVar4);
          if (iVar1 != -1) {
            iVar1 = wportal_db_authed_list_range_handle
                              (uVar10,uVar11,_wportal_authed_user_json_add_callback,iVar2,1,
                               _wportal_authed_user_match_callback,auStack_118,&local_1c0);
            if (iVar1 != -1) goto LAB_00415e08;
            if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar5 = "[WPORTAL_DBG]%s()/%d get authed list failed\n";
              pcVar9 = "_wportal_authed_user_get";
              uVar11 = 0xac6;
              goto LAB_00416368;
            }
          }
        }
LAB_00416370:
        json_object_put(iVar2);
LAB_00416378:
        fclose(pFVar3);
        uVar11 = 0;
      }
    }
  }
LAB_004160b0:
  uVar11 = json_object_new_int(uVar11);
  pcVar5 = "ret";
LAB_004160c0:
  json_object_object_add(param_2,pcVar5,uVar11);
  return;
}

