// func apupd_jcs_callback_apupd_models_add @ 00647a8c size=5156

/* WARNING: Removing unreachable block (ram,0x00647bf0) */
/* WARNING: Type propagation algorithm not settling */

void apupd_jcs_callback_apupd_models_add(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  time_t tVar4;
  uint *puVar5;
  tm *__src;
  time_t tVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  char *pcVar11;
  undefined8 uVar12;
  time_t local_2598 [9];
  tm tStack_2574;
  tm tStack_2548;
  char acStack_251c [127];
  undefined1 local_249d;
  undefined1 auStack_249c [20];
  undefined1 auStack_2488 [412];
  undefined1 auStack_22ec [704];
  uint auStack_202c [6];
  undefined1 auStack_2014 [64];
  uint *local_1fd4;
  undefined1 local_1ef3;
  char local_1ef2;
  tm atStack_1edc [2];
  undefined1 auStack_1e78 [32];
  undefined1 auStack_1e58 [1560];
  int local_1840;
  int local_183c;
  undefined1 auStack_182c [196];
  undefined1 auStack_1768 [85];
  undefined1 auStack_1713 [19];
  int local_1700;
  int local_16fc;
  char local_16f4;
  int local_16ec;
  int local_1680;
  undefined2 local_102c;
  char local_1029 [4097];
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_jcs_callback_apupd_models_add\r\n",
           "apupd_jcs_callback_apupd_models_add",0x604);
  }
  local_2598[5] = 0;
  local_2598[6] = 0;
  local_2598[7] = 0;
  local_2598[8] = 0;
  memset(acStack_251c,0,0x80);
  local_2598[0] = 0;
  local_2598[1] = 0;
  local_2598[2] = 0;
  local_2598[3] = 0;
  local_2598[4] = 0;
  memset(&local_102c,0,0x1000);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callback_apupd_models_add",0x61f
          );
    return;
  }
  memset(auStack_182c,0,0x800);
  memset(auStack_202c,0,0x800);
  memset(auStack_22ec,0,0x2c0);
  iVar1 = json_object_object_get(param_1,"group_id");
  if (iVar1 == 0) {
    iVar2 = 1;
    local_102c = 0x2d31;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      pcVar11 = (char *)&local_102c;
      for (iVar2 = 0;
          (iVar3 = json_object_array_length(iVar1), iVar2 < iVar3 &&
          (iVar3 = apmngr_db_get_group_max(), iVar2 < iVar3)); iVar2 = iVar2 + 1) {
        iVar3 = json_object_array_get_idx(iVar1,iVar2);
        if ((iVar3 == 0) || (iVar8 = json_object_get_type(iVar3), iVar8 != 6)) {
          pcVar7 = "";
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"apupd_jcs_callback_apupd_models_add",0x62b);
          }
        }
        else {
          pcVar7 = (char *)json_object_get_string(iVar3);
        }
        strncpy(pcVar11,pcVar7,3);
        pcVar11[3] = '\0';
        pcVar11 = pcVar11 + 4;
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 4) {
        iVar1 = json_object_object_length(iVar1);
        iVar2 = 0;
        if (iVar1 == 0) goto LAB_00647ba0;
      }
      iVar2 = 0;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get stringArray with error obj or value type is unmatch.\n"
               ,"apupd_jcs_callback_apupd_models_add",0x62b);
      }
    }
  }
LAB_00647ba0:
  memset(auStack_2014,0,0x40);
  if ((iVar2 == 1) && (iVar1 = strcmp((char *)&local_102c,"-1"), iVar1 == 0)) {
    memset(auStack_2014,0xff,0x40);
  }
  else {
    pcVar11 = (char *)&local_102c;
    iVar1 = 0;
    while (iVar1 < iVar2) {
      iVar3 = atoi(pcVar11);
      iVar1 = iVar1 + 1;
      if (iVar3 < 0x200) {
        iVar8 = iVar3 + 1;
        iVar3 = iVar3 + 0x20;
        if (-1 < iVar8) {
          iVar3 = iVar8;
        }
        iVar3 = (iVar3 >> 5) + 6;
        auStack_202c[iVar3] = 1 << (iVar8 % 0x20 & 0x1fU) | auStack_202c[iVar3];
      }
      pcVar11 = pcVar11 + 4;
    }
  }
  iVar1 = json_object_object_get(param_1,"model_id");
  if (iVar1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar11 = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
      uVar9 = 0x645;
      goto LAB_00647ecc;
    }
    goto LAB_00647cb8;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    puVar5 = (uint *)json_object_get_int(iVar1);
LAB_00647ee8:
    if (puVar5 == (uint *)0xffffffff) goto LAB_00647cac;
    local_1fd4 = puVar5;
    iVar1 = json_object_object_get(param_1,"is_sys");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar10 = json_object_get_int(iVar1);
        uVar10 = uVar10 & 0xff;
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar12 = json_object_get_double(iVar1);
          uVar10 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          uVar10 = uVar10 & 0xff;
        }
        else {
          uVar10 = 0xff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_apupd_models_add",0x653);
          }
        }
      }
      local_1ef3 = (undefined1)uVar10;
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: model is_sys is %d.\r\n",
               "apupd_jcs_callback_apupd_models_add",0x655,uVar10);
      }
    }
    iVar1 = json_object_object_get(param_1,"is_large_fw");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar10 = json_object_get_int(iVar1);
        uVar10 = uVar10 & 0xff;
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar12 = json_object_get_double(iVar1);
          uVar10 = __fixunsdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
          uVar10 = uVar10 & 0xff;
        }
        else {
          uVar10 = 0xff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_apupd_models_add",0x65b);
          }
        }
      }
      local_1ef2 = (char)uVar10;
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: model is_large_fw is %d.\r\n",
               "apupd_jcs_callback_apupd_models_add",0x65d,uVar10);
      }
    }
    iVar1 = apupd_db_model_get_by_id(local_1fd4,auStack_182c);
    if (iVar1 == 0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar11 = "[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n";
        uVar9 = 0x663;
        goto LAB_00647ecc;
      }
      goto LAB_00647cb8;
    }
    if ((local_1ef2 == '\x01') && (local_16fc == 0)) {
      uVar9 = 0x17;
      if (g_apupd_error != 0) {
        iVar1 = is_target_debug_ap(0x17);
        if (iVar1 == 0) {
          uVar9 = 0x17;
        }
        else {
          printf("[APUPD_ERROR]%32s() %05d: not support large fw upgrade.\r\n",
                 "apupd_jcs_callback_apupd_models_add",0x668);
          uVar9 = 0x17;
        }
      }
      goto LAB_00647cc8;
    }
    if (local_16ec != 0) {
      uVar9 = 6;
      if (g_apupd_error != 0) {
        iVar1 = is_target_debug_ap(6);
        if (iVar1 == 0) {
          uVar9 = 6;
        }
        else {
          printf("[APUPD_ERROR]%32s() %05d: model state(%d) isn\'t right, it cann\'t import software.\r\n"
                 ,"apupd_jcs_callback_apupd_models_add",0x66f,local_16ec);
          uVar9 = 6;
        }
      }
      goto LAB_00647cc8;
    }
    iVar1 = json_object_object_get(param_1,"upgrade_type");
    if (iVar1 == 0) {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00647cb8;
      pcVar11 = "[APUPD_ERROR]%32s() %05d: get data from json failed.\r\n";
      uVar9 = 0x675;
      goto LAB_00647ecc;
    }
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_1840 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar12 = json_object_get_double(iVar1);
        local_1840 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_apupd_models_add",0x678);
        }
        local_1840 = -1;
      }
    }
    apupd_local_time_get(&tStack_2548);
    tVar4 = mktime(&tStack_2548);
    iVar1 = json_object_object_get(param_1,"upgrade_datetime_type");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_183c = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar12 = json_object_get_double(iVar1);
          local_183c = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_apupd_models_add",0x683);
          }
          local_183c = -1;
        }
      }
      if (local_183c != 1) {
        if (local_1ef2 == '\x01') {
          uVar9 = 0x18;
          if (g_apupd_error != 0) {
            iVar1 = is_target_debug_ap(0x18);
            if (iVar1 == 0) {
              uVar9 = 0x18;
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: large fw time only immediately support\r\n",
                     "apupd_jcs_callback_apupd_models_add",0x690);
              uVar9 = 0x18;
            }
          }
          goto LAB_00647cc8;
        }
        memset(acStack_251c,0,0x80);
        iVar1 = json_object_object_get(param_1,"upgrade_date");
        if (iVar1 == 0) {
          if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            pcVar11 = "[APUPD_ERROR]%32s() %05d: get data from json failed.\r\n";
            uVar9 = 0x698;
            goto LAB_00647ecc;
          }
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 6) {
            pcVar11 = (char *)json_object_get_string(iVar1);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"apupd_jcs_callback_apupd_models_add",0x69b);
            }
            pcVar11 = "";
          }
          strncpy(acStack_251c,pcVar11,0x7f);
          local_249d = 0;
          iVar1 = sscanf(acStack_251c,"%d/%d/%d",&atStack_1edc[0].tm_year,&atStack_1edc[0].tm_mon,
                         &atStack_1edc[0].tm_mday);
          if (iVar1 == 3) {
            atStack_1edc[0].tm_year = atStack_1edc[0].tm_year + -0x76c;
            atStack_1edc[0].tm_mon = atStack_1edc[0].tm_mon + -1;
            memset(acStack_251c,0,0x80);
            iVar1 = json_object_object_get(param_1,"upgrade_start_time");
            if (iVar1 == 0) {
              if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar11 = "[APUPD_ERROR]%32s() %05d: get time failed from json.\r\n";
                uVar9 = 0x6a8;
                goto LAB_00647ecc;
              }
            }
            else {
              iVar2 = json_object_get_type(iVar1);
              if (iVar2 == 6) {
                pcVar11 = (char *)json_object_get_string(iVar1);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"apupd_jcs_callback_apupd_models_add",0x6ab);
                }
                pcVar11 = "";
              }
              strncpy(acStack_251c,pcVar11,0x7f);
              local_249d = 0;
              iVar1 = sscanf(acStack_251c,"%d:%d:%d",&atStack_1edc[0].tm_hour,
                             &atStack_1edc[0].tm_min,atStack_1edc);
              if (iVar1 == 3) goto LAB_00648490;
              if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar11 = "[APUPD_ERROR]%32s() %05d: get time from string failed.\r\n";
                uVar9 = 0x6ae;
                goto LAB_00647ecc;
              }
            }
          }
          else if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            pcVar11 = "[APUPD_ERROR]%32s() %05d: get data from string failed.\r\n";
            uVar9 = 0x69e;
            goto LAB_00647ecc;
          }
        }
        goto LAB_00647cb8;
      }
      local_2598[0] = tVar4 + 2;
      __src = localtime_r(local_2598,&tStack_2574);
      memcpy(atStack_1edc,__src,0x2c);
LAB_00648490:
      tVar6 = mktime(atStack_1edc);
      if (tVar6 < tVar4) {
        uVar9 = 0xc;
        if (g_apupd_error != 0) {
          iVar1 = is_target_debug_ap(0xc);
          if (iVar1 == 0) {
            uVar9 = 0xc;
          }
          else {
            pcVar11 = asctime(atStack_1edc);
            pcVar7 = asctime(&tStack_2548);
            printf("[APUPD_ERROR]%32s() %05d: time(%s) of setting is before local time(%s).\r\n",
                   "apupd_jcs_callback_apupd_models_add",0x6b9,pcVar11,pcVar7);
            uVar9 = 0xc;
          }
        }
        goto LAB_00647cc8;
      }
      if (0x93a80 < tVar6 - tVar4) {
        uVar9 = 0xd;
        if (g_apupd_error != 0) {
          iVar1 = is_target_debug_ap(0xd);
          if (iVar1 == 0) {
            uVar9 = 0xd;
          }
          else {
            pcVar11 = asctime(atStack_1edc);
            pcVar7 = asctime(&tStack_2548);
            printf("[APUPD_ERROR]%32s() %05d: time(%s) of setting is more after local time(%s).\r\n"
                   ,"apupd_jcs_callback_apupd_models_add",0x6c1,pcVar11,pcVar7);
            uVar9 = 0xd;
          }
        }
        goto LAB_00647cc8;
      }
      if (local_1840 == 2) {
        if (local_1ef2 == '\0') {
          iVar2 = apupd_image_size_get("/tmp/apupd.bin");
          if (iVar2 == 0) {
            uVar9 = 0xf;
            if (g_apupd_error != 0) {
              iVar1 = is_target_debug_ap(0xf);
              if (iVar1 == 0) {
                uVar9 = 0xf;
              }
              else {
                printf("[APUPD_ERROR]%32s() %05d: APUPD_JCS_RET_IMAGE_NOT_EXIST.\r\n",
                       "apupd_jcs_callback_apupd_models_add",0x6ce);
                uVar9 = 0xf;
              }
            }
            goto LAB_00647cc8;
          }
          iVar1 = FUN_00408450(iVar2,0x6d2);
          if (iVar1 == 0) {
            if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar11 = "[APUPD_ERROR]%32s() %05d: out of memory.\r\n";
              uVar9 = 0x6d4;
              goto LAB_00647ecc;
            }
            goto LAB_00647cb8;
          }
          iVar3 = apupd_image_file_read("/tmp/apupd.bin",iVar1,iVar2);
          if (iVar2 != iVar3) {
            if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar11 = "[APUPD_ERROR]%32s() %05d: read image file failed.\r\n";
              uVar9 = 0x6d9;
              goto LAB_00648ac4;
            }
            goto LAB_006489f0;
          }
          if ((((local_16f4 != '\x01') && (local_16f4 != '\x03')) &&
              (iVar3 = memcmp(auStack_1713,local_2598 + 1,0x10), iVar3 == 0)) &&
             (iVar3 = apupd_image_md5_check(iVar1,iVar2), iVar3 == -1)) {
            uVar9 = 5;
            if (g_apupd_error == 0) goto LAB_00648c00;
            iVar2 = is_target_debug_ap(5);
            if (iVar2 == 0) {
              uVar9 = 5;
              goto LAB_00648c00;
            }
            uVar9 = 0x6e1;
LAB_00648d0c:
            printf("[APUPD_ERROR]%32s() %05d: image file is wrong.\r\n",
                   "apupd_jcs_callback_apupd_models_add",uVar9);
            uVar9 = 5;
LAB_00648c00:
            uVar9 = json_object_new_int(uVar9);
            json_object_object_add(param_2,&DAT_00676a24,uVar9);
            FUN_00407df0(iVar1);
            return;
          }
          apupd_md5_calc(iVar1,iVar2,auStack_1e78,5);
          if (local_1680 == 0) {
            uVar9 = 7;
            if (APUPD_IMPORT_SOFTWARE_NUM_MAX <=
                (apupd_mult_online_model_entry_num != 0) + apupd_mult_manual_model_entry_num)
            goto LAB_00648c00;
            iVar3 = apupd_db_software_number_max_check(7);
            if (iVar3 == 1) {
              uVar9 = 7;
              goto LAB_00648c00;
            }
          }
          if ((local_16f4 == '\x01') || (local_16f4 == '\x03')) {
LAB_00648c98:
            iVar2 = apupd_model_image_infor_set(auStack_202c,iVar1,iVar2,local_2598 + 5);
            if (iVar2 != -1) goto LAB_00648a60;
            if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar11 = "[APUPD_ERROR]%32s() %05d: set model image information failed.\r\n";
              uVar9 = 0x72f;
              goto LAB_00648ac4;
            }
          }
          else {
            iVar3 = memcmp(auStack_1713,local_2598 + 1,0x10);
            if (iVar3 != 0) {
              memset(auStack_249c,0,0x1ae);
              iVar3 = dkmgt_firmwareInfo_check(iVar1,iVar2,auStack_249c);
              if (iVar3 != 0) {
                uVar9 = 5;
                if (g_apupd_error == 0) goto LAB_00648c00;
                iVar2 = is_target_debug_ap(5);
                if (iVar2 == 0) {
                  uVar9 = 5;
                  goto LAB_00648c00;
                }
                uVar9 = 0x715;
                goto LAB_00648d0c;
              }
              apupd_cloud_image_dump(auStack_249c);
              iVar3 = apupd_cloud_image_file_check(auStack_249c,auStack_1713);
              if (iVar3 != 0) {
                uVar9 = 4;
                if (g_apupd_error == 0) goto LAB_00648c00;
                iVar2 = is_target_debug_ap(4);
                if (iVar2 == 0) {
                  uVar9 = 4;
                  goto LAB_00648c00;
                }
                uVar9 = 0x71e;
                goto LAB_00648d68;
              }
              iVar3 = apupd_transfer_softver_str_to_softver_struct(auStack_2488,local_2598 + 5);
              if (iVar3 != 0) {
                if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  pcVar11 = 
                  "[APUPD_ERROR]%32s() %05d: apupd_transfer_softver_str_to_softver_struct failed.\r\n"
                  ;
                  uVar9 = 0x725;
                  goto LAB_00648ac4;
                }
                goto LAB_006489f0;
              }
              apupd_get_cloud_image_info_from_firmware_info(auStack_249c,auStack_1e58);
              goto LAB_00648c98;
            }
            iVar3 = apupd_image_hard_ver_get(iVar1,iVar2,auStack_22ec);
            if (iVar3 == -1) {
              if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_006489f0;
              pcVar11 = "[APUPD_ERROR]%32s() %05d: get hardware version support list failed.\r\n";
              uVar9 = 0x6f9;
              goto LAB_00648ac4;
            }
            iVar3 = apupd_image_hw_check(auStack_182c,auStack_22ec);
            if (iVar3 == -1) {
              uVar9 = 4;
              if (g_apupd_error == 0) goto LAB_00648c00;
              iVar2 = is_target_debug_ap(4);
              if (iVar2 == 0) {
                uVar9 = 4;
                goto LAB_00648c00;
              }
              uVar9 = 0x701;
LAB_00648d68:
              printf("[APUPD_ERROR]%32s() %05d: model don\'t support image\'s hardware version.\r\n"
                     ,"apupd_jcs_callback_apupd_models_add",uVar9);
              uVar9 = 4;
              goto LAB_00648c00;
            }
            iVar3 = apupd_image_soft_ver_get(iVar1,iVar2,local_2598 + 5);
            if (iVar3 != -1) goto LAB_00648c98;
            if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar11 = "[APUPD_ERROR]%32s() %05d: get image information failed.\r\n";
              uVar9 = 0x70a;
              goto LAB_00648ac4;
            }
          }
        }
        else {
          iVar1 = apupd_jcs_callback_apupd_models_large_fw_info_set(param_1,auStack_202c);
          if (iVar1 != 0) goto LAB_00647cb8;
          iVar1 = 0;
          if (local_1680 == 0) {
            uVar9 = 7;
            if (APUPD_IMPORT_SOFTWARE_NUM_MAX <=
                (apupd_mult_online_model_entry_num != 0) + apupd_mult_manual_model_entry_num)
            goto LAB_00647cc8;
            iVar2 = apupd_db_software_number_max_check(7);
            uVar9 = 7;
            if (iVar2 == 1) goto LAB_00647cc8;
          }
LAB_00648a60:
          iVar2 = apupd_db_model_set(auStack_202c,5);
          puVar5 = auStack_202c;
          if (iVar2 != -1) {
            iVar2 = apupd_db_model_set(auStack_202c,4);
            puVar5 = auStack_202c;
            if ((iVar2 != -1) &&
               (iVar2 = apupd_db_model_set(auStack_202c,7), puVar5 = local_1fd4, iVar2 != -1)) {
LAB_006487d0:
              iVar2 = apupd_db_model_set_for_uilist(local_1fd4,1);
              if (iVar2 == 0) {
                if (local_1840 == 2) {
                  apupd_mult_manual_model_entry_num = apupd_mult_manual_model_entry_num + 1;
                }
                else {
                  apupd_mult_online_model_entry_num = apupd_mult_online_model_entry_num + 1;
                }
                uVar9 = json_object_new_string(auStack_1768);
                json_object_object_add(param_2,"file_name",uVar9);
                uVar9 = json_object_new_int(0);
                json_object_object_add(param_2,&DAT_00676a24,uVar9);
                memset(auStack_2014,0,0x40);
                return;
              }
              if (iVar1 != 0) {
                FUN_00407df0(iVar1);
              }
              if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar11 = "[APUPD_ERROR]%32s() %05d: import image failed.\r\n";
                uVar9 = 0x76d;
                goto LAB_00647ecc;
              }
              goto LAB_00647cb8;
            }
          }
          if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(puVar5), iVar2 != 0)) {
            pcVar11 = "[APUPD_ERROR]%32s() %05d: import image failed.\r\n";
            uVar9 = 0x74a;
LAB_00648ac4:
            printf(pcVar11,"apupd_jcs_callback_apupd_models_add",uVar9);
          }
        }
LAB_006489f0:
        FUN_00407df0(iVar1);
        goto LAB_00647cb8;
      }
      if (local_1700 == 0) {
        uVar9 = 0x10;
        if (g_apupd_error != 0) {
          iVar1 = is_target_debug_ap(0x10);
          if (iVar1 == 0) {
            uVar9 = 0x10;
          }
          else {
            printf("[APUPD_ERROR]%32s() %05d: not support cloud.\r\n",
                   "apupd_jcs_callback_apupd_models_add",0x753);
            uVar9 = 0x10;
          }
        }
        goto LAB_00647cc8;
      }
      if (((local_1680 == 0) && (apupd_mult_online_model_entry_num == 0)) &&
         (uVar9 = 7, APUPD_IMPORT_SOFTWARE_NUM_MAX <= apupd_mult_manual_model_entry_num))
      goto LAB_00647cc8;
      iVar1 = apupd_db_model_set(auStack_202c,5);
      if (iVar1 != -1) {
        iVar1 = apupd_db_model_set(auStack_202c,7);
        if ((iVar1 != -1) && (iVar1 = apupd_db_model_set(auStack_202c,2), iVar1 != -1)) {
          iVar1 = 0;
          apupd_db_model_set(auStack_202c,6);
          goto LAB_006487d0;
        }
      }
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00647cb8;
      pcVar11 = "[APUPD_ERROR]%32s() %05d: import image failed.\r\n";
      uVar9 = 0x762;
      goto LAB_00647ecc;
    }
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar11 = "[APUPD_ERROR]%32s() %05d: get datetime type from json failed.\r\n";
      uVar9 = 0x680;
      goto LAB_00647ecc;
    }
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar12 = json_object_get_double(iVar1);
      puVar5 = (uint *)__fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      goto LAB_00647ee8;
    }
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "apupd_jcs_callback_apupd_models_add",0x648);
    }
LAB_00647cac:
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar11 = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
      uVar9 = 0x64b;
LAB_00647ecc:
      printf(pcVar11,"apupd_jcs_callback_apupd_models_add",uVar9);
    }
  }
LAB_00647cb8:
  memset(auStack_2014,0,0x40);
  uVar9 = 1;
LAB_00647cc8:
  uVar9 = json_object_new_int(uVar9);
  json_object_object_add(param_2,&DAT_00676a24,uVar9);
  return;
}

