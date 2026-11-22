// func apupd_jcs_callback_apupd_set_for_ap @ 00645d44 size=3676

/* WARNING: Removing unreachable block (ram,0x006465ac) */

void apupd_jcs_callback_apupd_set_for_ap(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined4 local_1ba0;
  undefined4 local_1b9c;
  undefined4 local_1b98;
  undefined4 local_1b94;
  undefined4 local_1b90;
  undefined4 local_1b8c;
  undefined4 local_1b88;
  undefined2 local_1b84;
  undefined4 local_1b80;
  undefined4 local_1b7c;
  undefined4 local_1b78;
  undefined4 local_1b74;
  undefined4 local_1b70;
  undefined4 local_1b6c;
  undefined4 local_1b68;
  undefined4 local_1b64;
  char local_1b60 [16];
  uint local_1b50;
  undefined1 auStack_1b4c [52];
  undefined4 local_1b18;
  undefined1 auStack_1b14 [16];
  int local_1b04;
  undefined1 auStack_1aac [20];
  undefined1 auStack_1a98 [412];
  undefined1 auStack_18fc [704];
  undefined1 auStack_163c [1560];
  undefined1 auStack_1024 [24];
  undefined1 auStack_100c [64];
  undefined4 local_fcc;
  undefined1 local_eea;
  undefined1 auStack_ed4 [81];
  undefined1 local_e83;
  undefined1 auStack_e70 [16];
  undefined1 auStack_e60 [1576];
  undefined4 local_838;
  undefined1 auStack_824 [196];
  undefined1 auStack_760 [85];
  undefined1 auStack_70b [19];
  int local_6f8;
  int local_6f4;
  char local_6ec;
  int local_6e4;
  int local_678;
  int local_38;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_jcs_callback_apupd_set_for_ap\r\n",
           "apupd_jcs_callback_apupd_set_for_ap",0x93c);
  }
  local_1b60[0] = '\0';
  local_1b60[1] = '\0';
  local_1b60[2] = '\0';
  local_1b60[3] = '\0';
  local_1b60[4] = '\0';
  local_1b60[5] = '\0';
  local_1b60[6] = '\0';
  local_1b60[7] = '\0';
  local_1b60[8] = '\0';
  local_1b60[9] = '\0';
  local_1b60[10] = '\0';
  local_1b60[0xb] = '\0';
  local_1b60[0xc] = '\0';
  local_1b60[0xd] = '\0';
  local_1b60[0xe] = '\0';
  local_1b60[0xf] = '\0';
  local_1b50 = 0;
  local_1b88 = 0;
  local_1b84 = 0;
  local_1b8c = 0;
  local_1b90 = 0;
  local_1b94 = 0;
  local_1b98 = 0;
  local_1b9c = 0;
  local_1ba0 = 0;
  memset(auStack_1b4c,0,0xa0);
  local_1b70 = 0;
  local_1b6c = 0;
  local_1b68 = 0;
  local_1b64 = 0;
  memset(auStack_163c,0,0x618);
  local_1b80 = 0;
  local_1b7c = 0;
  local_1b78 = 0;
  local_1b74 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callback_apupd_set_for_ap",0x953
          );
    return;
  }
  memset(auStack_824,0,0x800);
  memset(auStack_1024,0,0x800);
  memset(auStack_18fc,0,0x2c0);
  iVar1 = json_object_object_get(param_1,"mac");
  if (iVar1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar6 = "[APUPD_ERROR]%32s() %05d: get mac from json failed.\r\n";
      uVar5 = 0x95f;
LAB_006461a4:
      printf(pcVar6,"apupd_jcs_callback_apupd_set_for_ap",uVar5);
    }
    goto LAB_00646108;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 6) {
    pcVar6 = (char *)json_object_get_string(iVar1);
  }
  else {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "apupd_jcs_callback_apupd_set_for_ap",0x962);
    }
    pcVar6 = "";
  }
  strncpy(local_1b60,pcVar6,0x13);
  local_1b50 = local_1b50 & 0xffffff00;
  sscanf(local_1b60,"%X-%X-%X-%X-%X-%X",&local_1b8c,&local_1b90,&local_1b94,&local_1b98,&local_1b9c,
         &local_1ba0);
  local_1b88 = CONCAT31(CONCAT21(CONCAT11((char)local_1b8c,(char)local_1b90),(char)local_1b94),
                        (char)local_1b98);
  local_1b84 = CONCAT11((char)local_1b9c,(char)local_1ba0);
  iVar1 = apupd_db_wtp_get_by_mac(&local_1b88,auStack_1b4c);
  if ((iVar1 == 0) && (iVar1 = FUN_00408430(&local_1b88), iVar1 == 0)) {
    local_fcc = local_1b18;
    memset(auStack_100c,0,0x40);
    memset(auStack_100c,0xff,0x40);
    iVar1 = apupd_db_model_get_by_id(local_1b18,auStack_824);
    if (iVar1 == 0) {
      uVar5 = 0x12;
      if (g_apupd_error != 0) {
        iVar1 = is_target_debug_ap(0x12);
        if (iVar1 != 0) {
          pcVar6 = "[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n";
          uVar5 = 0x97c;
          goto LAB_00645fe8;
        }
        uVar5 = 0x12;
      }
    }
    else {
      iVar1 = json_object_object_get(param_1,"is_large_fw");
      if (iVar1 == 0) {
        uVar7 = 0;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          uVar7 = json_object_get_int(iVar1);
          uVar7 = uVar7 & 0xff;
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 == 2) {
            uVar9 = json_object_get_double(iVar1);
            uVar7 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
            uVar7 = uVar7 & 0xff;
          }
          else {
            uVar7 = 0xff;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "apupd_jcs_callback_apupd_set_for_ap",0x984);
            }
          }
        }
        local_eea = (undefined1)uVar7;
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: model is_large_fw is %d.\r\n",
                 "apupd_jcs_callback_apupd_set_for_ap",0x986,uVar7);
        }
        if ((uVar7 == 1) && (local_6f4 == 0)) {
          uVar5 = 0x17;
          if (g_apupd_error != 0) {
            iVar1 = is_target_debug_ap(0x17);
            if (iVar1 == 0) {
              uVar5 = 0x17;
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: model not support large fw upgrade.\r\n",
                     "apupd_jcs_callback_apupd_set_for_ap",0x98a);
              uVar5 = 0x17;
            }
          }
          goto LAB_00645f08;
        }
      }
      if ((local_6e4 == 0) || (local_38 == 3)) {
        if ((local_38 == 3) && ((local_1b04 - 1U < 7 || (local_1b04 - 0x13U < 4)))) {
          uVar5 = 9;
          if (g_apupd_error != 0) {
            iVar1 = is_target_debug_ap(9);
            if (iVar1 == 0) {
              uVar5 = 9;
            }
            else {
              printf("[APUPD_ERROR]%32s() %05d: model state(%d) or wtp state(%d) isn\'t right, it cann\'t import software.\r\n"
                     ,"apupd_jcs_callback_apupd_set_for_ap",0x999,local_6e4,local_1b04);
              uVar5 = 9;
            }
          }
        }
        else {
          iVar1 = json_object_object_get(param_1,"upgrade_type");
          if (iVar1 == 0) {
            if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar6 = "[APUPD_ERROR]%32s() %05d: get data from json failed.\r\n";
              uVar5 = 0x99f;
              goto LAB_006461a4;
            }
            goto LAB_00646108;
          }
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
            iVar1 = json_object_get_int(iVar1);
LAB_0064656c:
            if (iVar1 != 2) goto LAB_006462b8;
            if (uVar7 == 0) {
              iVar2 = access("/tmp/apupd.bin",0);
              if (iVar2 != 0) {
                iVar1 = apupd_image_size_get("/tmp/apupd_tmp.bin");
                uVar8 = (iVar1 * 100) / 0x700000;
                uVar7 = 99;
                if (100 < uVar8) {
                  uVar7 = uVar8;
                }
                uVar5 = json_object_new_int(uVar7);
                json_object_object_add(param_2,"percent",uVar5);
                uVar5 = 3;
                goto LAB_00645f08;
              }
              iVar3 = apupd_image_size_get("/tmp/apupd.bin");
              iVar2 = FUN_00408450(iVar3,0x9b7);
              if (iVar2 == 0) {
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar6 = "[APUPD_ERROR]%32s() %05d: out of memory.\r\n";
                  uVar5 = 0x9b9;
                  goto LAB_006461a4;
                }
                goto LAB_00646108;
              }
              iVar4 = apupd_image_file_read("/tmp/apupd.bin",iVar2,iVar3);
              if (iVar3 != iVar4) {
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar6 = "[APUPD_ERROR]%32s() %05d: read image file failed.\r\n";
                  uVar5 = 0x9be;
                  goto LAB_006466d8;
                }
                goto LAB_006464b0;
              }
              if ((((local_6ec != '\x01') && (local_6ec != '\x03')) &&
                  (iVar4 = memcmp(auStack_70b,&local_1b80,0x10), iVar4 == 0)) &&
                 (iVar4 = apupd_image_md5_check(iVar2,iVar3), iVar4 == -1)) {
                uVar5 = 5;
                if (g_apupd_error != 0) {
                  iVar1 = is_target_debug_ap(5);
                  if (iVar1 == 0) {
                    uVar5 = 5;
                  }
                  else {
                    uVar5 = 0x9c6;
LAB_006469f4:
                    printf("[APUPD_ERROR]%32s() %05d: image file is wrong.\r\n",
                           "apupd_jcs_callback_apupd_set_for_ap",uVar5);
                    uVar5 = 5;
                  }
                }
LAB_00646878:
                uVar5 = json_object_new_int(uVar5);
                json_object_object_add(param_2,&DAT_00676a24,uVar5);
                goto LAB_00646354;
              }
              apupd_md5_calc(iVar2,iVar3,auStack_e70,5);
              if (local_678 == 0) {
                iVar4 = apupd_db_software_number_max_check();
                uVar5 = 7;
                if (iVar4 == 1) goto LAB_00646878;
              }
              if ((local_6ec == '\x01') || (local_6ec == '\x03')) {
LAB_006468c4:
                iVar3 = apupd_model_image_infor_set(auStack_1024,iVar2,iVar3,&local_1b70);
                if (iVar3 == -1) {
                  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar6 = "[APUPD_ERROR]%32s() %05d: set model image information failed.\r\n";
                    uVar5 = 0xa16;
LAB_006466d8:
                    printf(pcVar6,"apupd_jcs_callback_apupd_set_for_ap",uVar5);
                  }
                  goto LAB_006464b0;
                }
                if (((local_6ec == '\x01') || (local_6ec == '\x03')) ||
                   (iVar3 = memcmp(auStack_e60,auStack_1b14,0x10), iVar3 != 0)) goto LAB_006462f0;
                uVar5 = 8;
                if (g_apupd_error != 0) {
                  iVar1 = is_target_debug_ap(8);
                  if (iVar1 == 0) {
                    uVar5 = 8;
                  }
                  else {
                    printf("[APUPD_ERROR]%32s() %05d: no need to upgrade.\r\n",
                           "apupd_jcs_callback_apupd_set_for_ap",0xa1b);
                    uVar5 = 8;
                  }
                }
                goto LAB_00646878;
              }
              iVar4 = memcmp(auStack_70b,&local_1b80,0x10);
              if (iVar4 != 0) {
                memset(auStack_1aac,0,0x1ae);
                iVar4 = dkmgt_firmwareInfo_check(iVar2,iVar3,auStack_1aac);
                if (iVar4 == 0) {
                  apupd_cloud_image_dump(auStack_1aac);
                  iVar4 = apupd_cloud_image_file_check(auStack_1aac,auStack_70b);
                  if (iVar4 == 0) {
                    iVar4 = apupd_transfer_softver_str_to_softver_struct(auStack_1a98,&local_1b70);
                    if (iVar4 == 0) {
                      apupd_get_cloud_image_info_from_firmware_info(auStack_1aac,auStack_163c);
                      iVar4 = apupd_db_wtp_firmware_id_match(auStack_1b4c,auStack_163c);
                      if (iVar4 != 0) goto LAB_006468c4;
                      uVar5 = 0x11;
                      if (g_apupd_error != 0) {
                        iVar1 = is_target_debug_ap(0x11);
                        if (iVar1 == 0) {
                          uVar5 = 0x11;
                        }
                        else {
                          printf("[APUPD_ERROR]%32s() %05d: can not upgrade,becase firmware list do not support.\r\n"
                                 ,"apupd_jcs_callback_apupd_set_for_ap",0xa0c);
                          uVar5 = 0x11;
                        }
                      }
                    }
                    else {
                      uVar5 = 4;
                      if (g_apupd_error != 0) {
                        iVar1 = is_target_debug_ap(4);
                        if (iVar1 != 0) {
                          pcVar6 = 
                          "[APUPD_ERROR]%32s() %05d: can not transfer software version.\r\n";
                          uVar5 = 0xa05;
                          goto LAB_00646a78;
                        }
                        uVar5 = 4;
                      }
                    }
                  }
                  else {
                    uVar5 = 4;
                    if (g_apupd_error != 0) {
                      iVar1 = is_target_debug_ap(4);
                      if (iVar1 == 0) {
                        uVar5 = 4;
                      }
                      else {
                        pcVar6 = 
                        "[APUPD_ERROR]%32s() %05d: model don\'t support image\'s hardware version.\r\n"
                        ;
                        uVar5 = 0x9fe;
LAB_00646a78:
                        printf(pcVar6,"apupd_jcs_callback_apupd_set_for_ap",uVar5);
                        uVar5 = 4;
                      }
                    }
                  }
                }
                else {
                  uVar5 = 5;
                  if (g_apupd_error != 0) {
                    iVar1 = is_target_debug_ap(5);
                    if (iVar1 != 0) {
                      uVar5 = 0x9f6;
                      goto LAB_006469f4;
                    }
                    uVar5 = 5;
                  }
                }
                goto LAB_00646878;
              }
              iVar4 = apupd_image_hard_ver_get(iVar2,iVar3,auStack_18fc);
              if (iVar4 == -1) {
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar6 = "[APUPD_ERROR]%32s() %05d: get hardware version support list failed.\r\n"
                  ;
                  uVar5 = 0x9da;
                  goto LAB_006466d8;
                }
              }
              else {
                iVar4 = apupd_image_hw_check(auStack_824,auStack_18fc);
                if (iVar4 == -1) {
                  uVar5 = 4;
                  if (g_apupd_error != 0) {
                    iVar1 = is_target_debug_ap(4);
                    if (iVar1 != 0) {
                      pcVar6 = 
                      "[APUPD_ERROR]%32s() %05d: model don\'t support image\'s hardware version.\r\n"
                      ;
                      uVar5 = 0x9e1;
                      goto LAB_00646a78;
                    }
                    uVar5 = 4;
                  }
                  goto LAB_00646878;
                }
                iVar4 = apupd_image_soft_ver_get(iVar2,iVar3,&local_1b70);
                if (iVar4 != -1) goto LAB_006468c4;
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar6 = "[APUPD_ERROR]%32s() %05d: get image information failed.\r\n";
                  uVar5 = 0x9e9;
                  goto LAB_006466d8;
                }
              }
LAB_006464b0:
              FUN_00407df0(iVar2);
            }
            else {
              iVar2 = apupd_jcs_callback_apupd_models_large_fw_info_set(param_1,auStack_1024);
              if (iVar2 == 0) {
                iVar2 = 0;
                local_e83 = 0;
                if (local_678 == 0) {
                  uVar5 = 7;
                  if (APUPD_IMPORT_SOFTWARE_NUM_MAX <=
                      (apupd_mult_online_model_entry_num != 0) + apupd_mult_manual_model_entry_num)
                  goto LAB_00646118;
                  iVar3 = apupd_db_software_number_max_check(7);
                  if (iVar3 == 1) {
                    uVar5 = 7;
                    goto LAB_00646118;
                  }
                }
                goto LAB_006462f0;
              }
            }
LAB_00646108:
            memset(auStack_100c,0,0x40);
            uVar5 = 1;
LAB_00646118:
            uVar5 = json_object_new_int(uVar5);
            json_object_object_add(param_2,&DAT_00676a24,uVar5);
            return;
          }
          iVar2 = json_object_get_type();
          if (iVar2 == 2) {
            uVar9 = json_object_get_double(iVar1);
            iVar1 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
            goto LAB_0064656c;
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_apupd_set_for_ap",0x9a2);
          }
          iVar1 = -1;
LAB_006462b8:
          uVar5 = 0x10;
          if (local_6f8 != 0) {
            iVar2 = 0;
            if ((apupd_mult_online_model_entry_num != 0) ||
               (iVar2 = 0, apupd_mult_manual_model_entry_num < APUPD_IMPORT_SOFTWARE_NUM_MAX)) {
LAB_006462f0:
              apupd_local_time_get(auStack_ed4);
              local_838 = 3;
              iVar1 = apupd_db_model_set_for_ap(auStack_1024,&local_1b88,iVar1);
              if (iVar1 == -1) {
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar6 = "[APUPD_ERROR]%32s() %05d: apupd_db_model_set_for_ap failed.\r\n";
                  uVar5 = 0xa43;
                  goto LAB_006464e0;
                }
              }
              else {
                if (iVar1 == -2) {
                  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    printf("[APUPD_ERROR]%32s() %05d: import software exceeds.\r\n",
                           "apupd_jcs_callback_apupd_set_for_ap",0xa48);
                  }
                  uVar5 = json_object_new_int(7);
                  json_object_object_add(param_2,&DAT_00676a24,uVar5);
                  if (iVar2 == 0) goto LAB_00645f24;
LAB_00646354:
                  FUN_00407df0(iVar2);
                  goto LAB_00645f24;
                }
                iVar1 = apupd_db_model_set(auStack_1024,7);
                if (iVar1 == -1) {
                  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar6 = 
                    "[APUPD_ERROR]%32s() %05d: apupd db model set islarge field failed.\r\n";
                    uVar5 = 0xa4e;
LAB_006464e0:
                    printf(pcVar6,"apupd_jcs_callback_apupd_set_for_ap",uVar5);
                  }
                }
                else {
                  iVar1 = apupd_db_model_set(auStack_1024,8);
                  if (iVar1 != -1) {
                    uVar5 = json_object_new_string(auStack_760);
                    json_object_object_add(param_2,"file_name",uVar5);
                    uVar5 = json_object_new_int(100);
                    json_object_object_add(param_2,"percent",uVar5);
                    uVar5 = 0;
                    goto LAB_00645f08;
                  }
                  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar6 = "[APUPD_ERROR]%32s() %05d: set can_down_sub_image failed.\r\n";
                    uVar5 = 0xa54;
                    goto LAB_006464e0;
                  }
                }
              }
              if (iVar2 != 0) goto LAB_006464b0;
              goto LAB_00646108;
            }
            uVar5 = 7;
          }
        }
      }
      else {
        uVar5 = 6;
        if (g_apupd_error != 0) {
          iVar1 = is_target_debug_ap(6);
          if (iVar1 == 0) {
            uVar5 = 6;
          }
          else {
            printf("[APUPD_ERROR]%32s() %05d: model state(%d) isn\'t right, it cann\'t import software.\r\n"
                   ,"apupd_jcs_callback_apupd_set_for_ap",0x992,local_6e4);
            uVar5 = 6;
          }
        }
      }
    }
  }
  else {
    uVar5 = 0x12;
    if (g_apupd_error != 0) {
      iVar1 = is_target_debug_ap(0x12);
      if (iVar1 == 0) {
        uVar5 = 0x12;
      }
      else {
        pcVar6 = "[APUPD_ERROR]%32s() %05d: get wtp failed.\r\n";
        uVar5 = 0x96e;
LAB_00645fe8:
        printf(pcVar6,"apupd_jcs_callback_apupd_set_for_ap",uVar5);
        uVar5 = 0x12;
      }
    }
  }
LAB_00645f08:
  uVar5 = json_object_new_int(uVar5);
  json_object_object_add(param_2,&DAT_00676a24,uVar5);
LAB_00645f24:
  memset(auStack_100c,0,0x40);
  return;
}

