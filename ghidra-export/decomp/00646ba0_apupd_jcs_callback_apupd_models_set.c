// func apupd_jcs_callback_apupd_models_set @ 00646ba0 size=3820

/* WARNING: Type propagation algorithm not settling */

void apupd_jcs_callback_apupd_models_set(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  time_t tVar3;
  tm *__src;
  time_t tVar4;
  char *pcVar5;
  size_t sVar6;
  void *__dest;
  size_t __n;
  undefined4 uVar7;
  char *pcVar8;
  undefined8 uVar9;
  time_t local_1590 [9];
  tm tStack_156c;
  tm tStack_1540;
  char acStack_1514 [127];
  undefined1 local_1495;
  undefined1 auStack_1494 [20];
  undefined1 auStack_1480 [412];
  undefined1 auStack_12e4 [704];
  undefined1 auStack_1024 [88];
  int local_fcc;
  tm atStack_ed4 [2];
  undefined1 auStack_e70 [32];
  undefined1 auStack_e50 [1560];
  int local_838;
  int local_834;
  undefined1 auStack_824 [196];
  undefined1 auStack_760 [85];
  undefined1 auStack_70b [19];
  int local_6f8;
  char local_6ec;
  char local_6ea;
  int local_6e4;
  size_t local_678;
  void *local_674;
  int local_38;
  
  local_1590[5] = 0;
  local_1590[6] = 0;
  local_1590[7] = 0;
  local_1590[8] = 0;
  memset(acStack_1514,0,0x80);
  local_1590[0] = 0;
  local_1590[1] = 0;
  local_1590[2] = 0;
  local_1590[3] = 0;
  local_1590[4] = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callback_apupd_models_set",0x7a2
          );
    return;
  }
  memset(auStack_824,0,0x800);
  memset(auStack_1024,0,0x800);
  memset(auStack_12e4,0,0x2c0);
  iVar1 = json_object_object_get(param_1,"model_id");
  if (iVar1 == 0) {
    uVar7 = 1;
    if (g_apupd_error == 0) goto LAB_00646c9c;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar7 = 1;
      goto LAB_00646c9c;
    }
    pcVar8 = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
    uVar7 = 0x7ae;
    goto LAB_00646d90;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    iVar1 = json_object_get_int(iVar1);
LAB_00646dac:
    if (iVar1 == -1) goto LAB_00646c90;
    local_fcc = iVar1;
    iVar1 = apupd_db_model_get_by_id(iVar1,auStack_824);
    if (iVar1 == 0) {
      uVar7 = 1;
      if (g_apupd_error == 0) goto LAB_00646c9c;
      iVar1 = is_target_debug_ap(1);
      if (iVar1 == 0) {
        uVar7 = 1;
        goto LAB_00646c9c;
      }
      pcVar8 = "[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n";
      uVar7 = 0x7bc;
      goto LAB_00646d90;
    }
    if (local_6ea == '\x01') {
      uVar7 = 0x19;
      if (g_apupd_error != 0) {
        iVar1 = is_target_debug_ap(0x19);
        if (iVar1 == 0) {
          uVar7 = 0x19;
        }
        else {
          printf("[APUPD_ERROR]%32s() %05d: large fw upgrade model no support modify.\r\n",
                 "apupd_jcs_callback_apupd_models_set",0x7c1);
          uVar7 = 0x19;
        }
      }
      goto LAB_00646c9c;
    }
    if (1 < local_38 - 1U) {
      uVar7 = 1;
      if (g_apupd_error != 0) {
        iVar1 = is_target_debug_ap(1);
        if (iVar1 == 0) {
          uVar7 = 1;
        }
        else {
          printf("[APUPD_ERROR]%32s() %05d: get model by id(%d) failed.\r\n",
                 "apupd_jcs_callback_apupd_models_set",0x7c8,local_fcc);
          uVar7 = 1;
        }
      }
      goto LAB_00646c9c;
    }
    if (local_6e4 == 3) {
      uVar7 = 6;
      if (g_apupd_error != 0) {
        iVar1 = is_target_debug_ap(6);
        if (iVar1 == 0) {
          uVar7 = 6;
        }
        else {
          printf("[APUPD_ERROR]%32s() %05d: model state(%d) isn\'t right, it cann\'t import software.\r\n"
                 ,"apupd_jcs_callback_apupd_models_set",0x7ce,local_6e4);
          uVar7 = 6;
        }
      }
      goto LAB_00646c9c;
    }
    iVar1 = json_object_object_get(param_1,"upgrade_type");
    if (iVar1 == 0) {
      uVar7 = 1;
      if (g_apupd_error == 0) goto LAB_00646c9c;
      iVar1 = is_target_debug_ap(1);
      if (iVar1 == 0) {
        uVar7 = 1;
        goto LAB_00646c9c;
      }
      pcVar8 = "[APUPD_ERROR]%32s() %05d: get data from json failed.\r\n";
      uVar7 = 0x7d4;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_838 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar9 = json_object_get_double(iVar1);
          local_838 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_apupd_models_set",0x7d7);
          }
          local_838 = -1;
        }
      }
      apupd_local_time_get(&tStack_1540);
      tVar3 = mktime(&tStack_1540);
      iVar1 = json_object_object_get(param_1,"upgrade_datetime_type");
      if (iVar1 == 0) {
        uVar7 = 1;
        if (g_apupd_error == 0) goto LAB_00646c9c;
        iVar1 = is_target_debug_ap(1);
        if (iVar1 == 0) {
          uVar7 = 1;
          goto LAB_00646c9c;
        }
        pcVar8 = "[APUPD_ERROR]%32s() %05d: get datetime type from json failed.\r\n";
        uVar7 = 0x7df;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          local_834 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 == 2) {
            uVar9 = json_object_get_double(iVar1);
            local_834 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "apupd_jcs_callback_apupd_models_set",0x7e2);
            }
            local_834 = -1;
          }
        }
        if (local_834 == 1) {
          local_1590[0] = tVar3 + 2;
          __src = localtime_r(local_1590,&tStack_156c);
          memcpy(atStack_ed4,__src,0x2c);
LAB_006470f8:
          tVar4 = mktime(atStack_ed4);
          if (tVar4 < tVar3) {
            uVar7 = 0xc;
            if (g_apupd_error != 0) {
              iVar1 = is_target_debug_ap(0xc);
              if (iVar1 == 0) {
                uVar7 = 0xc;
              }
              else {
                pcVar8 = asctime(atStack_ed4);
                pcVar5 = asctime(&tStack_1540);
                printf("[APUPD_ERROR]%32s() %05d: time(%s) of setting is before local time(%s).\r\n"
                       ,"apupd_jcs_callback_apupd_models_set",0x812,pcVar8,pcVar5);
                uVar7 = 0xc;
              }
            }
            goto LAB_00646c9c;
          }
          if (0x93a80 < tVar4 - tVar3) {
            uVar7 = 0xd;
            if (g_apupd_error != 0) {
              iVar1 = is_target_debug_ap(0xd);
              if (iVar1 == 0) {
                uVar7 = 0xd;
              }
              else {
                pcVar8 = asctime(atStack_ed4);
                pcVar5 = asctime(&tStack_1540);
                printf("[APUPD_ERROR]%32s() %05d: time(%s) of setting is more after local time(%s).\r\n"
                       ,"apupd_jcs_callback_apupd_models_set",0x81a,pcVar8,pcVar5);
                uVar7 = 0xd;
              }
            }
            goto LAB_00646c9c;
          }
          if (local_838 != 2) {
            uVar7 = 0x10;
            if (local_6f8 == 0) goto LAB_00646c9c;
            iVar1 = apupd_db_model_set(auStack_1024,4);
            if (iVar1 == -1) {
              uVar7 = 1;
              if (g_apupd_error == 0) goto LAB_00646c9c;
              iVar1 = is_target_debug_ap(1);
              if (iVar1 == 0) {
                uVar7 = 1;
                goto LAB_00646c9c;
              }
              pcVar8 = "[APUPD_ERROR]%32s() %05d: import image failed.\r\n";
              uVar7 = 0x8ae;
              goto LAB_00646d90;
            }
            apupd_db_model_set(auStack_1024,6);
            if (local_38 == 2) {
              if (apupd_mult_manual_model_entry_num != 0) {
                apupd_mult_manual_model_entry_num = apupd_mult_manual_model_entry_num + -1;
              }
              apupd_mult_online_model_entry_num = apupd_mult_online_model_entry_num + 1;
            }
LAB_0064747c:
            uVar7 = json_object_new_string(auStack_760);
            json_object_object_add(param_2,"file_name",uVar7);
            uVar7 = 0;
            goto LAB_00646c9c;
          }
          sVar6 = apupd_image_size_get("/tmp/apupd.bin");
          __n = local_678;
          if (sVar6 == 0) {
            if (local_38 == 1) {
              uVar7 = 0xf;
              if (g_apupd_error != 0) {
                iVar1 = is_target_debug_ap(0xf);
                if (iVar1 == 0) {
                  uVar7 = 0xf;
                }
                else {
                  printf("[APUPD_ERROR]%32s() %05d: APUPD_JCS_RET_IMAGE_NOT_EXIST.\r\n",
                         "apupd_jcs_callback_apupd_models_set",0x825);
                  uVar7 = 0xf;
                }
              }
              goto LAB_00646c9c;
            }
            __dest = (void *)FUN_00408450(local_678,0x82e);
            if (__dest != (void *)0x0) {
              memcpy(__dest,local_674,__n);
              sVar6 = __n;
              goto LAB_006474ec;
            }
            uVar7 = 1;
            if (g_apupd_error == 0) goto LAB_00646c9c;
            iVar1 = is_target_debug_ap(1);
            if (iVar1 == 0) {
              uVar7 = 1;
              goto LAB_00646c9c;
            }
            pcVar8 = "[APUPD_ERROR]%32s() %05d: out of memory.\r\n";
            uVar7 = 0x830;
          }
          else {
            __dest = (void *)FUN_00408450(sVar6,0x837);
            if (__dest != (void *)0x0) {
              __n = apupd_image_file_read("/tmp/apupd.bin",__dest,sVar6);
              if (sVar6 != __n) {
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar8 = "[APUPD_ERROR]%32s() %05d: read image file failed.\r\n";
                  uVar7 = 0x83e;
                  goto LAB_00647638;
                }
                goto LAB_00647594;
              }
LAB_006474ec:
              if ((((local_6ec != '\x01') && (local_6ec != '\x03')) &&
                  (iVar1 = memcmp(auStack_70b,local_1590 + 1,0x10), iVar1 == 0)) &&
                 (iVar1 = apupd_image_md5_check(__dest,__n), iVar1 == -1)) {
                uVar7 = 5;
                if (g_apupd_error == 0) goto LAB_00647718;
                iVar1 = is_target_debug_ap(5);
                if (iVar1 == 0) {
                  uVar7 = 5;
                  goto LAB_00647718;
                }
                uVar7 = 0x847;
LAB_006477cc:
                printf("[APUPD_ERROR]%32s() %05d: image file is wrong.\r\n",
                       "apupd_jcs_callback_apupd_models_set",uVar7);
                uVar7 = 5;
LAB_00647718:
                uVar7 = json_object_new_int(uVar7);
                json_object_object_add(param_2,&DAT_00676a24,uVar7);
                FUN_00407df0(__dest);
                return;
              }
              apupd_md5_calc(__dest,__n,auStack_e70,5);
              if (((local_38 == 1) && (local_678 == 0)) &&
                 ((iVar1 = apupd_db_software_number_max_check(), iVar1 == 1 ||
                  ((1 < apupd_mult_online_model_entry_num &&
                   (APUPD_IMPORT_SOFTWARE_NUM_MAX <= apupd_mult_manual_model_entry_num + 1U)))))) {
                uVar7 = 7;
                goto LAB_00647718;
              }
              if ((local_6ec == '\x01') || (local_6ec == '\x03')) {
LAB_006478a0:
                iVar1 = apupd_model_image_infor_set(auStack_1024,__dest,sVar6,local_1590 + 5);
                if (iVar1 == -1) {
                  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar8 = "[APUPD_ERROR]%32s() %05d: set model image information failed.\r\n";
                    uVar7 = 0x892;
LAB_00647638:
                    printf(pcVar8,"apupd_jcs_callback_apupd_models_set",uVar7);
                  }
                }
                else {
                  iVar1 = apupd_db_model_set(auStack_1024,4);
                  if (iVar1 != -1) {
                    if (local_38 == 1) {
                      apupd_mult_manual_model_entry_num = apupd_mult_manual_model_entry_num + 1;
                      if (apupd_mult_online_model_entry_num != 0) {
                        apupd_mult_online_model_entry_num = apupd_mult_online_model_entry_num - 1;
                      }
                    }
                    goto LAB_0064747c;
                  }
                  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar8 = "[APUPD_ERROR]%32s() %05d: import image failed.\r\n";
                    uVar7 = 0x898;
                    goto LAB_00647638;
                  }
                }
              }
              else {
                iVar1 = memcmp(auStack_70b,local_1590 + 1,0x10);
                if (iVar1 != 0) {
                  memset(auStack_1494,0,0x1ae);
                  iVar1 = dkmgt_firmwareInfo_check(__dest,__n,auStack_1494);
                  if (iVar1 != 0) {
                    uVar7 = 5;
                    if (g_apupd_error == 0) goto LAB_00647718;
                    iVar1 = is_target_debug_ap(5);
                    if (iVar1 == 0) {
                      uVar7 = 5;
                      goto LAB_00647718;
                    }
                    uVar7 = 0x879;
                    goto LAB_006477cc;
                  }
                  apupd_cloud_image_dump(auStack_1494);
                  iVar1 = apupd_cloud_image_file_check(auStack_1494,auStack_70b);
                  if (iVar1 != 0) {
                    uVar7 = 4;
                    if (g_apupd_error == 0) goto LAB_00647718;
                    iVar1 = is_target_debug_ap(4);
                    if (iVar1 == 0) {
                      uVar7 = 4;
                      goto LAB_00647718;
                    }
                    uVar7 = 0x882;
                    goto LAB_00647880;
                  }
                  iVar1 = apupd_transfer_softver_str_to_softver_struct(auStack_1480,local_1590 + 5);
                  if (iVar1 != 0) {
                    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                      pcVar8 = 
                      "[APUPD_ERROR]%32s() %05d: apupd_transfer_softver_str_to_softver_struct failed.\r\n"
                      ;
                      uVar7 = 0x889;
                      goto LAB_00647638;
                    }
                    goto LAB_00647594;
                  }
                  apupd_get_cloud_image_info_from_firmware_info(auStack_1494,auStack_e50);
                  goto LAB_006478a0;
                }
                iVar1 = apupd_image_hard_ver_get(__dest,__n,auStack_12e4);
                if (iVar1 == -1) {
                  if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
                  goto LAB_00647594;
                  pcVar8 = "[APUPD_ERROR]%32s() %05d: get hardware version support list failed.\r\n"
                  ;
                  uVar7 = 0x85f;
                  goto LAB_00647638;
                }
                iVar1 = apupd_image_hw_check(auStack_824,auStack_12e4);
                if (iVar1 == -1) {
                  uVar7 = 4;
                  if (g_apupd_error == 0) goto LAB_00647718;
                  iVar1 = is_target_debug_ap(4);
                  if (iVar1 == 0) {
                    uVar7 = 4;
                    goto LAB_00647718;
                  }
                  uVar7 = 0x865;
LAB_00647880:
                  printf("[APUPD_ERROR]%32s() %05d: model don\'t support image\'s hardware version.\r\n"
                         ,"apupd_jcs_callback_apupd_models_set",uVar7);
                  uVar7 = 4;
                  goto LAB_00647718;
                }
                iVar1 = apupd_image_soft_ver_get(__dest,__n,local_1590 + 5);
                if (iVar1 != -1) goto LAB_006478a0;
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar8 = "[APUPD_ERROR]%32s() %05d: get image information failed.\r\n";
                  uVar7 = 0x86e;
                  goto LAB_00647638;
                }
              }
LAB_00647594:
              FUN_00407df0(__dest);
              uVar7 = 1;
              goto LAB_00646c9c;
            }
            uVar7 = 1;
            if (g_apupd_error == 0) goto LAB_00646c9c;
            iVar1 = is_target_debug_ap(1);
            if (iVar1 == 0) {
              uVar7 = 1;
              goto LAB_00646c9c;
            }
            pcVar8 = "[APUPD_ERROR]%32s() %05d: out of memory.\r\n";
            uVar7 = 0x839;
          }
        }
        else {
          memset(acStack_1514,0,0x80);
          iVar1 = json_object_object_get(param_1,"upgrade_date");
          if (iVar1 == 0) {
            uVar7 = 1;
            if (g_apupd_error == 0) goto LAB_00646c9c;
            iVar1 = is_target_debug_ap(1);
            if (iVar1 == 0) {
              uVar7 = 1;
              goto LAB_00646c9c;
            }
            pcVar8 = "[APUPD_ERROR]%32s() %05d: get data from json failed.\r\n";
            uVar7 = 0x7f1;
          }
          else {
            iVar2 = json_object_get_type(iVar1);
            if (iVar2 == 6) {
              pcVar8 = (char *)json_object_get_string(iVar1);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"apupd_jcs_callback_apupd_models_set",0x7f4);
              }
              pcVar8 = "";
            }
            strncpy(acStack_1514,pcVar8,0x7f);
            local_1495 = 0;
            iVar1 = sscanf(acStack_1514,"%d/%d/%d",&atStack_ed4[0].tm_year,&atStack_ed4[0].tm_mon,
                           &atStack_ed4[0].tm_mday);
            if (iVar1 == 3) {
              atStack_ed4[0].tm_year = atStack_ed4[0].tm_year + -0x76c;
              atStack_ed4[0].tm_mon = atStack_ed4[0].tm_mon + -1;
              memset(acStack_1514,0,0x80);
              iVar1 = json_object_object_get(param_1,"upgrade_start_time");
              if (iVar1 == 0) {
                uVar7 = 1;
                if (g_apupd_error == 0) goto LAB_00646c9c;
                iVar1 = is_target_debug_ap(1);
                if (iVar1 == 0) {
                  uVar7 = 1;
                  goto LAB_00646c9c;
                }
                pcVar8 = "[APUPD_ERROR]%32s() %05d: get time failed from json.\r\n";
                uVar7 = 0x801;
              }
              else {
                iVar2 = json_object_get_type(iVar1);
                if (iVar2 == 6) {
                  pcVar8 = (char *)json_object_get_string(iVar1);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"apupd_jcs_callback_apupd_models_set",0x804);
                  }
                  pcVar8 = "";
                }
                strncpy(acStack_1514,pcVar8,0x7f);
                local_1495 = 0;
                iVar1 = sscanf(acStack_1514,"%d:%d:%d",&atStack_ed4[0].tm_hour,
                               &atStack_ed4[0].tm_min,atStack_ed4);
                if (iVar1 == 3) goto LAB_006470f8;
                uVar7 = 1;
                if (g_apupd_error == 0) goto LAB_00646c9c;
                iVar1 = is_target_debug_ap(1);
                if (iVar1 == 0) {
                  uVar7 = 1;
                  goto LAB_00646c9c;
                }
                pcVar8 = "[APUPD_ERROR]%32s() %05d: get time from string failed.\r\n";
                uVar7 = 0x807;
              }
            }
            else {
              uVar7 = 1;
              if (g_apupd_error == 0) goto LAB_00646c9c;
              iVar1 = is_target_debug_ap(1);
              if (iVar1 == 0) {
                uVar7 = 1;
                goto LAB_00646c9c;
              }
              pcVar8 = "[APUPD_ERROR]%32s() %05d: get data from string failed.\r\n";
              uVar7 = 0x7f7;
            }
          }
        }
      }
    }
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar9 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      goto LAB_00646dac;
    }
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "apupd_jcs_callback_apupd_models_set",0x7b1);
    }
LAB_00646c90:
    uVar7 = 1;
    if (g_apupd_error == 0) goto LAB_00646c9c;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar7 = 1;
      goto LAB_00646c9c;
    }
    pcVar8 = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
    uVar7 = 0x7b4;
  }
LAB_00646d90:
  printf(pcVar8,"apupd_jcs_callback_apupd_models_set",uVar7);
  uVar7 = 1;
LAB_00646c9c:
  uVar7 = json_object_new_int(uVar7);
  json_object_object_add(param_2,&DAT_00676a24,uVar7);
  return;
}

