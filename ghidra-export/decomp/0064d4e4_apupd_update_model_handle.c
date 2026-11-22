// func apupd_update_model_handle @ 0064d4e4 size=7628

undefined4 apupd_update_model_handle(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  FILE *__stream;
  int iVar10;
  int iVar11;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  undefined4 extraout_v1_01;
  undefined4 extraout_v1_02;
  undefined4 extraout_v1_03;
  uint uVar12;
  undefined4 extraout_v1_04;
  char *pcVar13;
  char cVar15;
  undefined4 uVar14;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  ushort *puVar20;
  int iVar21;
  uint auStack_6e8 [18];
  undefined1 auStack_6a0 [128];
  char acStack_620 [128];
  char acStack_5a0 [128];
  char acStack_520 [512];
  undefined1 auStack_320 [16];
  ushort local_310;
  undefined1 auStack_2d2 [650];
  char *local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int *local_38;
  int local_34;
  int local_30;
  
  if ((g_apupd_debug != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_model_handle, size = %d\r\n",
           "apupd_update_model_handle",0x10e7,param_2);
  }
  auStack_6e8[0xe] = 0;
  auStack_6e8[0xf] = 0;
  auStack_6e8[0x10] = 0;
  auStack_6e8[0x11] = 0;
  memset(auStack_320,0,0x2d8);
  iVar10 = -(APUPD_UPDATING_WTP_NUM_MAX * 4 + 0xeU & 0xfffffff8);
  local_38 = (int *)((int)auStack_6e8 + iVar10 + 0x30);
  if (((param_1 == 0) || (param_2 == 0)) || (iVar18 = *(int *)(param_1 + 0x10), iVar18 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar10 = is_target_debug_ap();
    if (iVar10 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_update_model_handle",0x10fd);
    return 0xffffffff;
  }
  if ((*(int *)(iVar18 + 0x7ec) == 1) || (*(int *)(iVar18 + 0x7ec) == 3)) {
    iVar5 = FUN_004081b0(param_1 + 0x30);
    local_44 = 0;
    iVar21 = 0;
LAB_0064db38:
    iVar19 = iVar5;
    if (iVar19 != 0) {
      if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: wtp_list->state = %d\r\n","apupd_update_model_handle",
               0x1109,*(undefined4 *)(iVar19 + 0x38));
      }
      local_34 = FUN_00408680(iVar19);
      iVar6 = *(int *)(iVar19 + 0x38);
      iVar5 = local_34;
      if (iVar6 == 0) {
        if (apupd_get_version_num < APUPD_GET_VERSION_NUM_MAX) {
          apupd_get_version_num = apupd_get_version_num + 1;
          *(undefined4 *)(iVar19 + 0x38) = 1;
          FUN_00407e70();
          *(undefined4 *)(iVar19 + 0x160) = extraout_v1_00;
          iVar5 = *(int *)(iVar19 + 0x3c);
          while (iVar5 != 0) {
            iVar6 = FUN_00408680(iVar5);
            *(undefined4 *)(*(int *)(iVar5 + 0x30) + 0x48) = 3;
            iVar5 = iVar6;
          }
          apupd_get_newest_firmware(*(int *)(param_1 + 0x10) + 0x119,iVar19 + 0x18);
          iVar5 = local_34;
        }
      }
      else if ((((iVar6 != 1) && (iVar6 != 3)) && (iVar6 != 6)) && ((iVar6 != 9 && (iVar6 != 7)))) {
        if (iVar6 == 2) {
          iVar6 = *(int *)(iVar19 + 0x3c);
          if ((apupd_import_software_num < APUPD_IMPORT_SOFTWARE_NUM_MAX) &&
             (apupd_download_software_num < APUPD_DOWNLOAD_SOFTWARE_NUM_MAX)) {
            while (iVar6 != 0) {
              iVar5 = FUN_00408680(iVar6);
              *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x48) = 5;
              iVar6 = iVar5;
            }
            local_40 = iVar19 + 0x5c;
            memset(acStack_520,0,0x200);
            memset(auStack_6a0,0,0x80);
            snprintf(acStack_520,0x1ff,
                     "ubus call cloudclient get_download_fw_size  \'{\"download_url_for_ap\":\"%s\"}\'"
                     ,local_40);
            if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[APUPD_DEBUG]%32s() %05d: %s\r\n","apupd_get_download_firmware_size",0x134,
                     acStack_520);
            }
            __stream = popen(acStack_520,"r");
            if (__stream == (FILE *)0x0) {
              if ((g_apupd_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                printf("[APUPD_ERROR]%32s() %05d: popen exe [%s] failed\n\r\n",
                       "apupd_get_download_firmware_size",0x139,acStack_520);
              }
LAB_0064ed50:
              if ((g_apupd_error == 0) || (iVar5 = is_target_debug_ap(iVar19), iVar5 == 0)) {
                uVar14 = 0x1a;
              }
              else {
                printf("[APUPD_ERROR]%32s() %05d: apupd_get_download_firmware_size fail.\r\n",
                       "apupd_update_model_handle",0x114a);
                uVar14 = 0x1a;
              }
            }
            else {
              memset(auStack_6a0,0,0x80);
              fread(auStack_6a0,1,0x80,__stream);
              pclose(__stream);
              iVar5 = cJSON_Parse(auStack_6a0);
              if (iVar5 == 0) {
                if ((g_apupd_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                  printf("[APUPD_ERROR]%32s() %05d: get jsonrpc obj failed.\n\r\n",
                         "apupd_get_download_firmware_size",0x144);
                }
                goto LAB_0064ed50;
              }
              iVar6 = cJSON_GetObjectItem(iVar5,"filesize");
              if ((iVar6 == 0) || (local_3c = *(int *)(iVar6 + 0xc), local_3c != 3)) {
                if ((g_apupd_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                  printf("[APUPD_ERROR]%32s() %05d: get filesize from json failed.\r\n",
                         "apupd_get_download_firmware_size",0x150);
                }
                cJSON_Delete(iVar5);
                goto LAB_0064ed50;
              }
              uVar7 = *(uint *)(iVar6 + 0x14);
              cJSON_Delete(iVar5);
              FUN_00407e70();
              *(undefined4 *)(iVar19 + 0x160) = extraout_v1_02;
              apupd_import_software_num = apupd_import_software_num + 1;
              *(int *)(iVar19 + 0x38) = local_3c;
              if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                       "apupd_update_model_handle",0x1153,apupd_import_software_num);
              }
              apupd_download_software_num = apupd_download_software_num + 1;
              if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                *(uint *)((int)auStack_6e8 + iVar10) = uVar7;
                printf("[APUPD_DEBUG]%32s() %05d: g_large_firmware_threshold = %d, file_size = %d\r\n"
                       ,"apupd_update_model_handle",0x1156,g_large_firmware_threshold);
              }
              if (uVar7 <= g_large_firmware_threshold) {
LAB_0064efb4:
                iVar6 = local_40;
                iVar11 = 0;
                if (g_large_firmware_threshold < uVar7) {
                  uVar7 = *(int *)(iVar19 + 0x178) - *(int *)(iVar19 + 0x194);
                  iVar11 = g_large_firmware_sub_file_size - 1;
                  if (uVar7 <= g_large_firmware_sub_file_size) {
                    iVar11 = uVar7 - 1;
                  }
                }
                iVar5 = *(int *)(iVar19 + 0x194);
                *(int *)((int)auStack_6e8 + iVar10) = iVar11;
                goto LAB_0064ebb4;
              }
              if (*(int *)(iVar18 + 0x130) == 1) {
                if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                  printf("[APUPD_DEBUG]%32s() %05d: total_image_size = %d\r\n",
                         "apupd_update_model_handle",0x115b,uVar7);
                }
                *(uint *)(iVar19 + 0x178) = uVar7;
                *(undefined1 *)(iVar19 + 400) = 0;
                uVar12 = g_large_firmware_sub_file_size;
                *(undefined1 *)(iVar19 + 0x174) = 1;
                if (uVar12 == 0) {
                  trap(7);
                }
                *(uint *)(iVar19 + 0x17c) = (uVar7 - 1) / uVar12 + 1;
                memcpy((void *)(iVar19 + 0x180),&DAT_00719dd0,0x10);
                *(uint *)(iVar18 + 0x188) = uVar7;
                *(undefined1 *)(iVar18 + 0x13a) = 1;
                uVar14 = *(undefined4 *)(iVar19 + 0x17c);
                *(undefined1 *)(iVar18 + 0x1a0) = 0;
                *(undefined4 *)(iVar18 + 0x18c) = uVar14;
                memcpy((void *)(iVar18 + 400),&DAT_00719dd0,0x10);
                goto LAB_0064efb4;
              }
              if ((g_apupd_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                *(uint *)((int)auStack_6e8 + iVar10) = g_large_firmware_threshold;
                printf("[APUPD_ERROR]%32s() %05d: file_size(%d) is larger than g_large_firmware_threshold(%d), but model not spuuprt large firmware upgrade\r\n"
                       ,"apupd_update_model_handle",0x1169,uVar7);
              }
              uVar14 = 0x1b;
            }
            apupd_update_wtp_upd_list_clear_wtp(iVar19,uVar14);
            iVar5 = local_34;
          }
          else {
            while (iVar5 = local_34, iVar6 != 0) {
              iVar5 = FUN_00408680(iVar6);
              *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x48) = 4;
              iVar6 = iVar5;
            }
          }
          goto LAB_0064db38;
        }
        iVar11 = iVar21;
        if (iVar6 == 4) {
          if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[APUPD_DEBUG]%32s() %05d: wtp_list->state == APUPD_UPDATE_WTP_LIST_STATE_TYPE_DOWNLOAD_FINISH\r\n"
                   ,"apupd_update_model_handle",0x1180);
          }
          iVar5 = *(int *)(iVar19 + 0x3c);
          *(undefined4 *)(iVar19 + 0x3c) = 0;
          while (iVar6 = iVar5, iVar6 != 0) {
            iVar5 = FUN_00408680(iVar6);
            iVar16 = memcmp((void *)(*(int *)(iVar6 + 0x30) + 0x38),(void *)(iVar19 + 0x164),0x10);
            if (iVar16 == 0) {
              if (g_apupd_debug == 0) {
                iVar16 = *(int *)(iVar6 + 0x30);
              }
              else {
                iVar9 = is_target_debug_ap();
                iVar16 = *(int *)(iVar6 + 0x30);
                if (iVar9 != 0) {
                  bVar1 = *(byte *)(iVar16 + 0x2e);
                  *(uint *)((int)auStack_6e8 + iVar10) = (uint)*(byte *)(iVar16 + 0x2f);
                  *(uint *)((int)auStack_6e8 + iVar10 + 4) = (uint)*(byte *)(iVar16 + 0x30);
                  *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uint)*(byte *)(iVar16 + 0x31);
                  *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = (uint)*(byte *)(iVar16 + 0x32);
                  *(uint *)((int)auStack_6e8 + iVar10 + 0x10) = (uint)*(byte *)(iVar16 + 0x33);
                  printf("[APUPD_DEBUG]%32s() %05d: wtp[%02X-%02X-%02X-%02X-%02X-%02X] no need upgrade\r\n"
                         ,"apupd_update_model_handle",0x1189,(uint)bVar1);
                  iVar16 = *(int *)(iVar6 + 0x30);
                }
              }
              *(undefined4 *)(iVar16 + 0x48) = 0xf;
              iVar6 = apupd_update_wtp_entry_delete_only(iVar6);
              if (iVar6 == -1) {
                if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
                goto LAB_0064e440;
                pcVar13 = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
                uVar14 = 0x118e;
                goto LAB_0064e508;
              }
            }
            else if (*(int *)(iVar19 + 0x3c) == 0) {
              *(int *)(iVar19 + 0x3c) = iVar6;
            }
          }
          if (*(int *)(iVar19 + 0x3c) == 0) {
            if (*(int *)(iVar19 + 0x38) < 3) {
              iVar5 = *(int *)(iVar19 + 0x38);
            }
            else {
              apupd_import_software_num = apupd_import_software_num - 1;
              if (g_apupd_debug == 0) {
                iVar5 = *(int *)(iVar19 + 0x38);
              }
              else {
                iVar5 = is_target_debug_ap();
                if (iVar5 == 0) {
                  iVar5 = *(int *)(iVar19 + 0x38);
                }
                else {
                  printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                         "apupd_update_model_handle",0x119f,apupd_import_software_num);
                  iVar5 = *(int *)(iVar19 + 0x38);
                }
              }
            }
            if (iVar5 == 1) {
              apupd_get_version_num = apupd_get_version_num - 1;
              apupd_delete_info_in_uci(*(int *)(param_1 + 0x10) + 0x119,iVar19 + 0x18);
              iVar5 = *(int *)(iVar19 + 0x38);
            }
            else {
              iVar5 = *(int *)(iVar19 + 0x38);
            }
            if ((iVar5 == 3) || (iVar5 == 9)) {
              apupd_download_software_num = apupd_download_software_num - 1;
              apupd_delete_info_in_uci(*(int *)(param_1 + 0x10) + 0x119,iVar19 + 0x18);
              iVar5 = *(int *)(iVar19 + 0x48);
            }
            else {
              iVar5 = *(int *)(iVar19 + 0x48);
            }
            if (iVar5 == 0) {
              uVar14 = *(undefined4 *)(param_1 + 0x2c);
            }
            else {
              FUN_00407df0();
              *(undefined4 *)(iVar19 + 0x48) = 0;
              uVar14 = *(undefined4 *)(param_1 + 0x2c);
            }
            FUN_00407f40(uVar14,iVar19);
            FUN_00408500(iVar19);
            FUN_00407df0(iVar19);
            iVar5 = local_34;
            goto LAB_0064db38;
          }
          *(undefined4 *)(iVar19 + 0x38) = 5;
        }
        else if (iVar6 != 5) {
          if (iVar6 == 8) {
            if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[APUPD_DEBUG]%32s() %05d: wtp_list->state == APUPD_UPDATE_WTP_LIST_STATE_TYPE_SUB_SEND_FINISH\r\n"
                     ,"apupd_update_model_handle",0x124f);
            }
            if ((apupd_import_software_num < APUPD_IMPORT_SOFTWARE_NUM_MAX) &&
               (apupd_download_software_num < APUPD_DOWNLOAD_SOFTWARE_NUM_MAX)) {
              iVar5 = *(int *)(iVar19 + 0x40);
              while (iVar5 != 0) {
                iVar6 = FUN_00408680(iVar5);
                *(undefined4 *)(*(int *)(iVar5 + 0x30) + 0x48) = 0x15;
                iVar5 = iVar6;
              }
              FUN_00407e70();
              *(undefined4 *)(iVar19 + 0x160) = extraout_v1_03;
              *(undefined4 *)(iVar19 + 0x38) = 9;
              apupd_import_software_num = apupd_import_software_num + 1;
              apupd_download_software_num = apupd_download_software_num + 1;
              if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: **start new sub image download*\r\n",
                       "apupd_update_model_handle",0x126c);
              }
              if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                       "apupd_update_model_handle",0x126d,apupd_import_software_num);
              }
              iVar5 = *(int *)(iVar19 + 0x194);
              uVar12 = *(int *)(iVar19 + 0x178) - iVar5;
              uVar7 = g_large_firmware_sub_file_size;
              if (uVar12 <= g_large_firmware_sub_file_size) {
                uVar7 = uVar12;
              }
              iVar6 = iVar19 + 0x5c;
              *(uint *)((int)auStack_6e8 + iVar10) = uVar7 - 1;
LAB_0064ebb4:
              apupd_download_firmware(iVar6,iVar18 + 0x119,iVar19 + 0x18,iVar5);
              iVar5 = local_34;
            }
            else {
              if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                *(uint *)((int)auStack_6e8 + iVar10) = apupd_download_software_num;
                printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d, apupd_download_software_num = %d, \r\n"
                       ,"apupd_update_model_handle",0x1252,apupd_import_software_num);
              }
              if (g_apupd_debug == 0) {
                iVar19 = *(int *)(iVar19 + 0x40);
              }
              else {
                iVar5 = is_target_debug_ap();
                if (iVar5 == 0) {
                  iVar19 = *(int *)(iVar19 + 0x40);
                }
                else {
                  *(uint *)((int)auStack_6e8 + iVar10) = APUPD_DOWNLOAD_SOFTWARE_NUM_MAX;
                  printf("[APUPD_DEBUG]%32s() %05d: APUPD_IMPORT_SOFTWARE_NUM_MAX = %d, APUPD_DOWNLOAD_SOFTWARE_NUM_MAX = %d, \r\n"
                         ,"apupd_update_model_handle",0x1253,APUPD_IMPORT_SOFTWARE_NUM_MAX);
                  iVar19 = *(int *)(iVar19 + 0x40);
                }
              }
              while (iVar5 = local_34, iVar19 != 0) {
                iVar5 = FUN_00408680(iVar19);
                *(undefined4 *)(*(int *)(iVar19 + 0x30) + 0x48) = 0x14;
                iVar19 = iVar5;
              }
            }
          }
          else if (iVar6 == 10) {
            if (g_apupd_debug == 0) {
              iVar5 = *(int *)(iVar19 + 0x40);
            }
            else {
              iVar5 = is_target_debug_ap();
              if (iVar5 == 0) {
                iVar5 = *(int *)(iVar19 + 0x40);
              }
              else {
                printf("[APUPD_DEBUG]%32s() %05d: wtp_list->state == APUPD_UPDATE_WTP_LIST_STATE_TYPE_SUB_DOWNLOAD_FINISH\r\n"
                       ,"apupd_update_model_handle",0x1275);
                iVar5 = *(int *)(iVar19 + 0x40);
              }
            }
            local_3c = 0;
            local_40 = iVar21;
            while (iVar5 != 0) {
              if ((g_apupd_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: tmp_update_wtp != NULL)\r\n",
                       "apupd_update_model_handle",0x1279);
              }
              local_30 = FUN_00408680(iVar5);
              *(undefined4 *)(*(int *)(iVar5 + 0x30) + 0x48) = 0x16;
              apmngr_db_entry_get_by_mac(*(int *)(iVar5 + 0x30) + 0x2e,auStack_320);
              iVar6 = apupd_sub_image_info_send
                                (local_310,*(undefined1 *)(iVar19 + 400),
                                 *(undefined4 *)(iVar19 + 0x44),iVar19 + 0x4c);
              if (((iVar6 == -1) && (g_apupd_error != 0)) &&
                 (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                printf("[APUPD_ERROR]%32s() %05d: send to ap(%d) sub image action packet failed.\r\n"
                       ,"apupd_update_model_handle",0x1280,(uint)local_310);
              }
              *(undefined4 *)(iVar5 + 0x20) = 1;
              *(undefined4 *)(iVar5 + 0x24) = 4;
              puVar8 = (undefined1 *)FUN_00408450(6,0x1284);
              iVar11 = local_40;
              *(undefined1 **)((int)local_38 + local_3c + iVar21 * 4) = puVar8;
              if (puVar8 == (undefined1 *)0x0) {
                iVar21 = iVar11;
                if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
                goto LAB_0064e440;
                pcVar13 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
                uVar14 = 0x1286;
                goto LAB_0064e508;
              }
              *puVar8 = 0;
              puVar8[1] = 0;
              puVar8[2] = 0;
              puVar8[3] = 0;
              puVar8[4] = 0;
              puVar8[5] = 0;
              memcpy(puVar8,(void *)(iVar5 + 0x18),6);
              if (*(int *)(iVar5 + 0x28) != -1) {
                FUN_00408060();
                *(undefined4 *)(iVar5 + 0x28) = 0xffffffff;
              }
              *(code **)((int)auStack_6e8 + iVar10) = apupd_update_wtp_argv_callback;
              *(char **)((int)auStack_6e8 + iVar10 + 4) = "apupd_update_model_handle";
              *(undefined4 *)((int)auStack_6e8 + iVar10 + 8) = 0x1292;
              iVar6 = FUN_00408340(0x1e,0,apupd_update_wtp_sub_image_info_timer_callback,puVar8);
              iVar11 = local_40;
              *(int *)(iVar5 + 0x28) = iVar6;
              local_3c = local_3c + 4;
              if (iVar6 == -1) {
                iVar21 = iVar11;
                if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
                goto LAB_0064e440;
                pcVar13 = "[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n";
                uVar14 = 0x1295;
                goto LAB_0064e508;
              }
              local_40 = local_40 + 1;
              iVar5 = local_30;
            }
            FUN_00407e70();
            *(undefined4 *)(iVar19 + 0x160) = extraout_v1_04;
            *(undefined4 *)(iVar19 + 0x38) = 7;
            iVar5 = local_34;
            iVar21 = local_40;
          }
          goto LAB_0064db38;
        }
        if (g_apupd_debug == 0) {
          iVar5 = *(int *)(iVar19 + 0x3c);
        }
        else {
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            iVar5 = *(int *)(iVar19 + 0x3c);
          }
          else {
            printf("[APUPD_DEBUG]%32s() %05d: **wtp_list->state == APUPD_UPDATE_WTP_LIST_STATE_TYPE_UPGRADING**\r\n"
                   ,"apupd_update_model_handle",0x11bd);
            iVar5 = *(int *)(iVar19 + 0x3c);
          }
        }
        if (iVar5 != 0) {
          *(int *)(iVar19 + 0x40) = iVar5;
        }
        iVar6 = serv_wtp_address_arg_init(auStack_6e8 + 0xe);
        if (iVar6 == -1) {
          if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
          goto LAB_0064e440;
          pcVar13 = "[APUPD_ERROR]%32s() %05d: init service argv failed.\r\n";
          uVar14 = 0x11c6;
          goto LAB_0064e508;
        }
        while (iVar5 != 0) {
          if ((g_apupd_debug != 0) && (iVar6 = is_target_debug_ap(), uVar7 = local_44, iVar6 != 0))
          {
            *(uint *)((int)auStack_6e8 + iVar10) = param_2;
            printf("[APUPD_DEBUG]%32s() %05d: size_cnt = %d, size = %d\r\n",
                   "apupd_update_model_handle",0x11cc,uVar7);
          }
          iVar6 = *(int *)(iVar5 + 0x30);
          if (param_2 <= local_44) {
            cVar15 = *(char *)(iVar19 + 0x174);
            goto LAB_0064e694;
          }
          if (*(int *)(iVar5 + 0x20) != 0) {
            if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
            goto LAB_0064e440;
            uVar7 = *(uint *)(iVar5 + 0x20);
            pcVar13 = "[APUPD_ERROR]%32s() %05d: update wtp state(%d) is wrong\r\n";
            uVar14 = 0x11d7;
            goto LAB_0064e958;
          }
          *(undefined4 *)(iVar5 + 0x20) = 1;
          FUN_00407e70();
          *(undefined4 *)(iVar5 + 0x2c) = extraout_v1_01;
          if ((*(int *)(iVar6 + 0x48) != 5) && (*(int *)(iVar6 + 0x48) != 2)) {
            if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
            goto LAB_0064e440;
            uVar7 = *(uint *)(iVar6 + 0x48);
            pcVar13 = "[APUPD_ERROR]%32s() %05d: update wtp state(%d) is wrong\r\n";
            uVar14 = 0x11e0;
            goto LAB_0064e958;
          }
          *(undefined4 *)(iVar6 + 0x48) = 6;
          apmngr_db_entry_get_by_mac(iVar6 + 0x2e,auStack_320);
          apmngr_db_ap_run_state_update(local_310,3);
          uVar3 = local_310;
          *(undefined4 *)((int)auStack_6e8 + iVar10) = 0xffffffff;
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 4) = 0;
          iVar16 = apmngr_db_get_addr_by_capacity(uVar3,auStack_6e8 + 0xe,1,1);
          if (iVar16 != 0) {
            if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
            goto LAB_0064e440;
            pcVar13 = "[APUPD_ERROR]%32s() %05d: add service argv failed.\r\n";
            uVar14 = 0x11eb;
            goto LAB_0064e508;
          }
          if (*(char *)(iVar18 + 0x13a) == '\x01') {
            uVar14 = *(undefined4 *)(iVar19 + 0x178);
LAB_0064df60:
            iVar16 = apupd_large_image_info_send
                               (local_310,uVar14,*(undefined4 *)(iVar19 + 0x17c),iVar19 + 0x180);
            if (iVar16 == -1) {
              if ((g_apupd_debug == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
              goto LAB_0064e440;
              uVar7 = (uint)local_310;
              pcVar13 = "[APUPD_DEBUG]%32s() %05d: AP[%d] send large image info fail\r\n";
              uVar14 = 0x11f4;
              goto LAB_0064e958;
            }
            *(undefined4 *)(iVar5 + 0x24) = 1;
            puVar8 = (undefined1 *)FUN_00408450(6,0x11f8);
            local_38[iVar21] = (int)puVar8;
            if (puVar8 == (undefined1 *)0x0) {
              if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
              goto LAB_0064e440;
              pcVar13 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
              uVar14 = 0x11fa;
              goto LAB_0064e508;
            }
            *puVar8 = 0;
            puVar8[1] = 0;
            puVar8[2] = 0;
            puVar8[3] = 0;
            puVar8[4] = 0;
            puVar8[5] = 0;
            memcpy(puVar8,(void *)(iVar5 + 0x18),6);
            if (*(int *)(iVar5 + 0x28) != -1) {
              FUN_00408060();
              *(undefined4 *)(iVar5 + 0x28) = 0xffffffff;
            }
            *(char **)((int)auStack_6e8 + iVar10 + 4) = "apupd_update_model_handle";
            *(code **)((int)auStack_6e8 + iVar10) = apupd_update_wtp_argv_callback;
            *(undefined4 *)((int)auStack_6e8 + iVar10 + 8) = 0x1206;
            iVar16 = FUN_00408340(0x1e,0,apupd_update_wtp_large_image_info_timer_callback,puVar8);
            *(int *)(iVar5 + 0x28) = iVar16;
            if (iVar16 == -1) {
              if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
              goto LAB_0064e440;
              pcVar13 = "[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n";
              uVar14 = 0x1209;
              goto LAB_0064e508;
            }
          }
          else if (*(char *)(iVar19 + 0x174) != '\0') {
            uVar14 = *(undefined4 *)(iVar19 + 0x178);
            goto LAB_0064df60;
          }
          local_44 = local_44 + 1;
          iVar5 = FUN_00408680(iVar5);
          *(int *)(iVar19 + 0x3c) = iVar5;
          apupd_updating_wtp_num = apupd_updating_wtp_num + 1;
          memset(acStack_520,0,0x80);
          memset(acStack_5a0,0,0x80);
          uVar7 = *(uint *)(iVar6 + 0x40);
          uVar3 = *(ushort *)(iVar6 + 0x38);
          uVar4 = *(ushort *)(iVar6 + 0x3a);
          *(uint *)((int)auStack_6e8 + iVar10) = (uint)*(ushort *)(iVar6 + 0x3c);
          *(uint *)((int)auStack_6e8 + iVar10 + 4) = uVar7 >> 0x10;
          *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uVar7 << 0x10) >> 0x18;
          *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = uVar7 & 0xff;
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x10) = *(undefined4 *)(iVar6 + 0x44);
          sprintf(acStack_520,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)uVar3,(uint)uVar4);
          if (*(char *)(iVar18 + 0x13a) == '\x01') {
            iVar16 = *(int *)(param_1 + 0x10);
LAB_0064e0e4:
            uVar7 = *(uint *)(iVar16 + 0x1cc);
            uVar3 = *(ushort *)(iVar16 + 0x1c4);
            uVar4 = *(ushort *)(iVar16 + 0x1c6);
            *(uint *)((int)auStack_6e8 + iVar10) = (uint)*(ushort *)(iVar16 + 0x1c8);
            *(uint *)((int)auStack_6e8 + iVar10 + 4) = uVar7 >> 0x10;
            *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uVar7 << 0x10) >> 0x18;
            *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = uVar7 & 0xff;
            *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x10) = *(undefined4 *)(iVar16 + 0x1d0);
          }
          else {
            if (*(char *)(iVar19 + 0x174) != '\0') {
              iVar16 = *(int *)(param_1 + 0x10);
              goto LAB_0064e0e4;
            }
            uVar7 = *(uint *)(iVar19 + 0x16c);
            uVar3 = *(ushort *)(iVar19 + 0x164);
            uVar4 = *(ushort *)(iVar19 + 0x166);
            *(uint *)((int)auStack_6e8 + iVar10) = (uint)*(ushort *)(iVar19 + 0x168);
            *(uint *)((int)auStack_6e8 + iVar10 + 4) = uVar7 >> 0x10;
            *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uVar7 << 0x10) >> 0x18;
            *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = uVar7 & 0xff;
            *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x10) = *(undefined4 *)(iVar19 + 0x170);
          }
          sprintf(acStack_5a0,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)uVar3,(uint)uVar4);
          memset(acStack_620,0,0x80);
          bVar1 = *(byte *)(iVar6 + 0x2f);
          bVar2 = *(byte *)(iVar6 + 0x2e);
          *(uint *)((int)auStack_6e8 + iVar10) = (uint)*(byte *)(iVar6 + 0x30);
          *(uint *)((int)auStack_6e8 + iVar10 + 4) = (uint)*(byte *)(iVar6 + 0x31);
          *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uint)*(byte *)(iVar6 + 0x32);
          *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = (uint)*(byte *)(iVar6 + 0x33);
          sprintf(acStack_620,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)bVar2,(uint)bVar1);
          memset(auStack_6a0,0,0x40);
          *(undefined1 **)((int)auStack_6e8 + iVar10 + 4) = auStack_6a0;
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 8) = 0x40;
          *(char **)((int)auStack_6e8 + iVar10 + 0xc) = "---";
          *(undefined4 *)((int)auStack_6e8 + iVar10) = *(undefined4 *)(iVar6 + 0x28);
          FUN_00408190(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x1c),
                       *(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x24));
          uVar14 = apmngr_db_product_type_str(*(undefined1 *)(iVar18 + 0x138));
          pcVar13 = "---";
          if (*(char *)(iVar18 + 0x138) != '\x01') {
            pcVar13 = acStack_5a0;
            if (*(char *)(iVar18 + 0x138) == '\x03') {
              pcVar13 = "---";
            }
          }
          *(char **)((int)auStack_6e8 + iVar10 + 0x24) = pcVar13;
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x28) = 0;
          *(undefined1 **)((int)auStack_6e8 + iVar10 + 4) = auStack_2d2;
          *(undefined4 *)((int)auStack_6e8 + iVar10) = 1;
          *(undefined1 **)((int)auStack_6e8 + iVar10 + 0xc) = auStack_6a0;
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 8) = 1;
          *(char **)((int)auStack_6e8 + iVar10 + 0x14) = acStack_620;
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x10) = 1;
          *(char **)((int)auStack_6e8 + iVar10 + 0x1c) = acStack_520;
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x18) = 1;
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x20) = 1;
          loggerk_reg(0x54,0x380f,1,uVar14);
        }
        cVar15 = *(char *)(iVar19 + 0x174);
LAB_0064e694:
        if ((cVar15 == '\0') && (auStack_6e8[0x10] != 0)) {
          if (g_apupd_debug == 0) {
            cVar15 = *(char *)(iVar18 + 0x138);
          }
          else {
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              cVar15 = *(char *)(iVar18 + 0x138);
            }
            else {
              printf("[APUPD_DEBUG]%32s() %05d: apupd_config_update_request_send\r\n",
                     "apupd_update_model_handle",0x1244);
              cVar15 = *(char *)(iVar18 + 0x138);
            }
          }
          iVar5 = apupd_config_update_request_send
                            (auStack_6e8 + 0xe,iVar19 + 0x164,cVar15 == '\x02');
          if (iVar5 == -1) {
            if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
            goto LAB_0064e440;
            pcVar13 = "[APUPD_ERROR]%32s() %05d: send config update request failed.\r\n";
            uVar14 = 0x1247;
            goto LAB_0064e508;
          }
        }
        serv_wtp_address_arg_destroy(auStack_6e8 + 0xe);
        iVar5 = local_34;
      }
      goto LAB_0064db38;
    }
    iVar5 = *(int *)(param_1 + 0x10);
  }
  else {
    iVar21 = 0;
    local_44 = 0;
    iVar5 = *(int *)(param_1 + 0x10);
  }
  if (1 < *(int *)(iVar5 + 0x7ec) - 2U) {
    return 0;
  }
  iVar19 = *(int *)(param_1 + 0x3c);
  if ((*(int *)(iVar5 + 0x7ec) != 2) ||
     (iVar5 = serv_wtp_address_arg_init(auStack_6e8 + 0xe), iVar5 != -1)) {
LAB_0064d678:
    iVar11 = iVar21;
    if (iVar19 == 0) goto LAB_0064d678;
    if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: tmp_update_wtp:%p\r\n","apupd_update_model_handle",0x12b1,
             iVar19);
    }
    iVar5 = *(int *)(iVar19 + 0x30);
    if (param_2 <= local_44) {
      cVar15 = *(char *)(iVar18 + 0x13a);
      goto LAB_0064e5cc;
    }
    if (*(int *)(*(int *)(param_1 + 0x10) + 0x7ec) == 3) {
      iVar6 = serv_wtp_address_arg_init(auStack_6e8 + 0xe);
      if (iVar6 == -1) {
        if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) goto LAB_0064e440;
        pcVar13 = "[APUPD_ERROR]%32s() %05d: init service argv failed.\r\n";
        uVar14 = 0x12bd;
        goto LAB_0064e508;
      }
      iVar6 = *(int *)(iVar19 + 0x20);
    }
    else {
      iVar6 = *(int *)(iVar19 + 0x20);
    }
    if (iVar6 != 0) {
      if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) goto LAB_0064e440;
      uVar7 = *(uint *)(iVar19 + 0x20);
      pcVar13 = "[APUPD_ERROR]%32s() %05d: update wtp state(%d) is wrong\r\n";
      uVar14 = 0x12c4;
      goto LAB_0064e958;
    }
    *(undefined4 *)(iVar19 + 0x20) = 1;
    FUN_00407e70();
    *(undefined4 *)(iVar19 + 0x2c) = extraout_v1;
    if (*(int *)(iVar5 + 0x48) != 2) {
      if ((g_apupd_error != 0) && (iVar18 = is_target_debug_ap(), iVar18 != 0)) {
        bVar1 = *(byte *)(iVar5 + 0x2e);
        *(uint *)((int)auStack_6e8 + iVar10) = (uint)*(byte *)(iVar5 + 0x2f);
        *(uint *)((int)auStack_6e8 + iVar10 + 4) = (uint)*(byte *)(iVar5 + 0x30);
        *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uint)*(byte *)(iVar5 + 0x31);
        *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = (uint)*(byte *)(iVar5 + 0x32);
        *(uint *)((int)auStack_6e8 + iVar10 + 0x10) = (uint)*(byte *)(iVar5 + 0x33);
        *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x14) = *(undefined4 *)(iVar5 + 0x48);
        printf("[APUPD_ERROR]%32s() %05d: update wtp(%02x-%02x-%02x-%02x-%02x-%02x) state(%d) is wrong\r\n"
               ,"apupd_update_model_handle",0x12ce,(uint)bVar1);
      }
      goto LAB_0064e440;
    }
    *(undefined4 *)(iVar5 + 0x48) = 6;
    apmngr_db_entry_get_by_mac(iVar5 + 0x2e,auStack_320);
    apmngr_db_ap_run_state_update(local_310,3);
    uVar3 = local_310;
    *(undefined4 *)((int)auStack_6e8 + iVar10) = 0xffffffff;
    *(undefined4 *)((int)auStack_6e8 + iVar10 + 4) = 0;
    iVar6 = apmngr_db_get_addr_by_capacity(uVar3,auStack_6e8 + 0xe,1,1);
    if (iVar6 != 0) {
      if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) goto LAB_0064e440;
      pcVar13 = "[APUPD_ERROR]%32s() %05d: add service argv failed.\r\n";
      uVar14 = 0x12d9;
      goto LAB_0064e508;
    }
    if (*(char *)(iVar18 + 0x13a) == '\x01') {
      if (g_apupd_debug == 0) {
        iVar16 = *(int *)(param_1 + 0x10);
      }
      else {
        iVar6 = is_target_debug_ap();
        iVar16 = *(int *)(param_1 + 0x10);
        if (iVar6 != 0) {
          *(undefined4 *)((int)auStack_6e8 + iVar10) = *(undefined4 *)(iVar16 + 0x7ec);
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 4) = *(undefined4 *)(iVar16 + 0x188);
          *(undefined4 *)((int)auStack_6e8 + iVar10 + 8) = *(undefined4 *)(iVar18 + 0x18c);
          printf("[APUPD_DEBUG]%32s() %05d: model(%s) upd_type = %d, total_image_size = %d, total_image_piece = %d\r\n"
                 ,"apupd_update_model_handle",0x12df,iVar16 + 0x5c);
          iVar16 = *(int *)(param_1 + 0x10);
        }
      }
      iVar6 = apupd_large_image_info_send
                        (local_310,*(undefined4 *)(iVar16 + 0x188),*(undefined4 *)(iVar16 + 0x18c),
                         iVar16 + 400);
      if (iVar6 == -1) {
        if ((g_apupd_debug == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) goto LAB_0064e440;
        uVar7 = (uint)local_310;
        pcVar13 = "[APUPD_DEBUG]%32s() %05d: AP[%d] send large image info fail\r\n";
        uVar14 = 0x12e3;
LAB_0064e958:
        printf(pcVar13,"apupd_update_model_handle",uVar14,uVar7);
        goto LAB_0064e440;
      }
      *(undefined4 *)(iVar19 + 0x24) = 1;
      puVar8 = (undefined1 *)FUN_00408450(6,0x12e7);
      local_38[iVar21] = (int)puVar8;
      if (puVar8 == (undefined1 *)0x0) {
        if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) goto LAB_0064e440;
        pcVar13 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
        uVar14 = 0x12e9;
        goto LAB_0064e508;
      }
      *puVar8 = 0;
      puVar8[1] = 0;
      puVar8[2] = 0;
      puVar8[3] = 0;
      puVar8[4] = 0;
      puVar8[5] = 0;
      memcpy(puVar8,(void *)(iVar19 + 0x18),6);
      if (*(int *)(iVar19 + 0x28) != -1) {
        FUN_00408060();
        *(undefined4 *)(iVar19 + 0x28) = 0xffffffff;
      }
      *(code **)((int)auStack_6e8 + iVar10) = apupd_update_wtp_argv_callback;
      *(char **)((int)auStack_6e8 + iVar10 + 4) = "apupd_update_model_handle";
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 8) = 0x12f5;
      iVar6 = FUN_00408340(0x1e,0,apupd_update_wtp_large_image_info_timer_callback,puVar8);
      *(int *)(iVar19 + 0x28) = iVar6;
      if (iVar6 == -1) {
        if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) goto LAB_0064e440;
        pcVar13 = "[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n";
        uVar14 = 0x12f8;
        goto LAB_0064e508;
      }
    }
    local_44 = local_44 + 1;
    puVar20 = (ushort *)(iVar18 + 0x1c4);
    if (*(int *)(*(int *)(param_1 + 0x10) + 0x7ec) != 2) {
      puVar20 = (ushort *)(iVar19 + 0x3c);
    }
    iVar19 = FUN_00408680(iVar19);
    *(int *)(param_1 + 0x3c) = iVar19;
    apupd_updating_wtp_num = apupd_updating_wtp_num + 1;
    if (*(char *)(iVar18 + 0x13a) == '\x01') {
      if (g_apupd_error == 0) {
        iVar21 = iVar21 + 1;
      }
      else {
        iVar5 = is_target_debug_ap();
        iVar21 = iVar21 + 1;
        if (iVar5 != 0) {
          printf("[APUPD_ERROR]%32s() %05d: large fw upgrade create log when first sub file recevie\r\n"
                 ,"apupd_update_model_handle",0x1311);
        }
      }
    }
    else {
      memset(acStack_620,0,0x80);
      local_48 = acStack_5a0;
      memset(local_48,0,0x80);
      uVar7 = *(uint *)(iVar5 + 0x40);
      uVar3 = *(ushort *)(iVar5 + 0x38);
      uVar4 = *(ushort *)(iVar5 + 0x3a);
      *(uint *)((int)auStack_6e8 + iVar10) = (uint)*(ushort *)(iVar5 + 0x3c);
      *(uint *)((int)auStack_6e8 + iVar10 + 4) = uVar7 >> 0x10;
      *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uVar7 << 0x10) >> 0x18;
      *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = uVar7 & 0xff;
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x10) = *(undefined4 *)(iVar5 + 0x44);
      sprintf(acStack_620,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)uVar3,(uint)uVar4);
      uVar7 = *(uint *)(puVar20 + 4);
      uVar3 = puVar20[1];
      uVar4 = *puVar20;
      *(uint *)((int)auStack_6e8 + iVar10) = (uint)puVar20[2];
      *(uint *)((int)auStack_6e8 + iVar10 + 4) = uVar7 >> 0x10;
      *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uVar7 << 0x10) >> 0x18;
      *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = uVar7 & 0xff;
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x10) = *(undefined4 *)(puVar20 + 6);
      sprintf(acStack_5a0,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)uVar4,(uint)uVar3);
      memset(acStack_520,0,0x80);
      bVar1 = *(byte *)(iVar5 + 0x2f);
      bVar2 = *(byte *)(iVar5 + 0x2e);
      *(uint *)((int)auStack_6e8 + iVar10) = (uint)*(byte *)(iVar5 + 0x30);
      *(uint *)((int)auStack_6e8 + iVar10 + 4) = (uint)*(byte *)(iVar5 + 0x31);
      *(uint *)((int)auStack_6e8 + iVar10 + 8) = (uint)*(byte *)(iVar5 + 0x32);
      *(uint *)((int)auStack_6e8 + iVar10 + 0xc) = (uint)*(byte *)(iVar5 + 0x33);
      sprintf(acStack_520,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)bVar2,(uint)bVar1);
      memset(auStack_6a0,0,0x40);
      *(undefined1 **)((int)auStack_6e8 + iVar10 + 4) = auStack_6a0;
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 8) = 0x40;
      *(char **)((int)auStack_6e8 + iVar10 + 0xc) = "---";
      *(undefined4 *)((int)auStack_6e8 + iVar10) = *(undefined4 *)(iVar5 + 0x28);
      FUN_00408190(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                   *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24));
      uVar14 = apmngr_db_product_type_str(*(undefined1 *)(iVar18 + 0x138));
      pcVar13 = "---";
      if ((*(char *)(iVar18 + 0x138) != '\x01') &&
         (pcVar13 = "---", *(char *)(iVar18 + 0x138) != '\x03')) {
        pcVar13 = local_48;
      }
      *(char **)((int)auStack_6e8 + iVar10 + 0x24) = pcVar13;
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x28) = 0;
      *(undefined1 **)((int)auStack_6e8 + iVar10 + 4) = auStack_2d2;
      *(undefined4 *)((int)auStack_6e8 + iVar10) = 1;
      *(undefined1 **)((int)auStack_6e8 + iVar10 + 0xc) = auStack_6a0;
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 8) = 1;
      *(char **)((int)auStack_6e8 + iVar10 + 0x14) = acStack_520;
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x10) = 1;
      *(char **)((int)auStack_6e8 + iVar10 + 0x1c) = acStack_620;
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x18) = 1;
      *(undefined4 *)((int)auStack_6e8 + iVar10 + 0x20) = 1;
      loggerk_reg(0x54,0x380f,1,uVar14);
      if (*(int *)(*(int *)(param_1 + 0x10) + 0x7ec) == 3) {
        if (g_apupd_debug == 0) {
          cVar15 = *(char *)(iVar18 + 0x138);
        }
        else {
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            cVar15 = *(char *)(iVar18 + 0x138);
          }
          else {
            printf("[APUPD_DEBUG]%32s() %05d: apupd_config_update_request_send\r\n",
                   "apupd_update_model_handle",0x1335);
            cVar15 = *(char *)(iVar18 + 0x138);
          }
        }
        iVar5 = apupd_config_update_request_send(auStack_6e8 + 0xe,puVar20,cVar15 == '\x02');
        if (iVar5 == -1) {
          if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
          goto LAB_0064e440;
          pcVar13 = "[APUPD_ERROR]%32s() %05d: send config update request failed.\r\n";
          uVar14 = 0x1338;
          goto LAB_0064e508;
        }
        serv_wtp_address_arg_destroy(auStack_6e8 + 0xe);
      }
    }
    goto LAB_0064d678;
  }
  if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) goto LAB_0064e440;
  pcVar13 = "[APUPD_ERROR]%32s() %05d: init service argv failed.\r\n";
  uVar14 = 0x12ab;
  iVar11 = iVar21;
  goto LAB_0064e508;
LAB_0064d678:
  cVar15 = *(char *)(iVar18 + 0x13a);
LAB_0064e5cc:
  if (((cVar15 != '\0') || (*(int *)(*(int *)(param_1 + 0x10) + 0x7ec) != 2)) ||
     (auStack_6e8[0x10] == 0)) {
LAB_0064e5ec:
    serv_wtp_address_arg_destroy(auStack_6e8 + 0xe);
    return 0;
  }
  if (g_apupd_debug == 0) {
    cVar15 = *(char *)(iVar18 + 0x138);
  }
  else {
    iVar10 = is_target_debug_ap(auStack_6e8 + 0xe);
    if (iVar10 == 0) {
      cVar15 = *(char *)(iVar18 + 0x138);
    }
    else {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_config_update_request_send\r\n",
             "apupd_update_model_handle",0x1342);
      cVar15 = *(char *)(iVar18 + 0x138);
    }
  }
  iVar10 = apupd_config_update_request_send(auStack_6e8 + 0xe,iVar18 + 0x1c4,cVar15 == '\x02');
  if (iVar10 != -1) goto LAB_0064e5ec;
  if ((g_apupd_error == 0) || (iVar10 = is_target_debug_ap(auStack_6e8 + 0xe), iVar10 == 0))
  goto LAB_0064e440;
  pcVar13 = "[APUPD_ERROR]%32s() %05d: send config update request failed.\r\n";
  uVar14 = 0x1345;
LAB_0064e508:
  printf(pcVar13,"apupd_update_model_handle",uVar14);
  iVar21 = iVar11;
LAB_0064e440:
  iVar10 = 0;
  piVar17 = local_38;
  while (iVar10 < iVar21) {
    iVar10 = iVar10 + 1;
    if (*piVar17 != 0) {
      FUN_00407df0();
    }
    piVar17 = piVar17 + 1;
  }
  serv_wtp_address_arg_destroy(auStack_6e8 + 0xe);
  return 0xffffffff;
}

