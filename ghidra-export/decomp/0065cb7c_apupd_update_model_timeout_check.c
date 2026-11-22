// func apupd_update_model_timeout_check @ 0065cb7c size=5244

undefined4 apupd_update_model_timeout_check(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  size_t __n;
  void *__s;
  size_t sVar11;
  uint extraout_v1;
  char *pcVar12;
  undefined4 uVar13;
  int iVar14;
  char *__s_00;
  int iVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int local_478;
  char *local_474;
  undefined4 local_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 local_464;
  undefined1 auStack_44c [64];
  char acStack_40c [128];
  char acStack_38c [156];
  char acStack_2f0 [256];
  undefined1 auStack_1f0 [20];
  undefined1 auStack_1dc [412];
  int local_40;
  char *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar19 = 0;
  uVar18 = 0xffffffff;
  iVar15 = 0;
  local_474 = (char *)0x0;
  local_478 = 0;
  memset(acStack_2f0,0,0x100);
  memset(auStack_1f0,0,0x1ae);
  iVar4 = FUN_004081b0(apupd_update_model_list);
  local_38 = -1;
  if (iVar4 != 0) {
    iVar5 = *(int *)(iVar4 + 0x10);
    do {
      if (((*(int *)(iVar5 + 0x7ec) != 2) && (*(int *)(iVar5 + 0x140) == 3)) &&
         (iVar5 = FUN_00407fe0(iVar4 + 0x30), iVar5 != 0)) {
        iVar5 = FUN_004081b0(iVar4 + 0x30);
LAB_0065ccb4:
        do {
          iVar9 = iVar5;
          if (iVar9 == 0) goto LAB_0065cc1c;
          local_2c = FUN_00408680(iVar9);
          FUN_00407e70();
          iVar6 = *(int *)(iVar9 + 0x38);
          if (iVar6 == 1) {
            if ((*(uint *)(iVar9 + 0x160) < extraout_v1) &&
               (200 < extraout_v1 - *(uint *)(iVar9 + 0x160))) goto LAB_0065d00c;
            break;
          }
          if (iVar6 == 3) {
            uVar7 = *(uint *)(iVar9 + 0x160);
LAB_0065ccf8:
            if ((extraout_v1 <= uVar7) || (extraout_v1 - uVar7 < 0x3e9)) break;
LAB_0065d00c:
            iVar6 = FUN_004081b0(iVar9 + 0xc);
            while (iVar5 = local_2c, iVar6 != 0) {
              local_40 = FUN_00408680(iVar6);
              if (*(int *)(*(int *)(iVar4 + 0x10) + 0x7ec) != 3) {
                uVar13 = 4;
                if (*(int *)(iVar9 + 0x38) != 1) {
                  uVar13 = 5;
                }
                iVar5 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar6 + 0x30),uVar13);
                if (iVar5 == -1) {
                  if (g_apupd_error == 0) {
                    return 0xffffffff;
                  }
                  iVar19 = is_target_debug_ap();
                  if (iVar19 == 0) {
                    return 0xffffffff;
                  }
                  printf("[APUPD_ERROR]%32s() %05d: add log failed.\r\n",
                         "apupd_update_model_timeout_check",0x145d);
                  return 0xffffffff;
                }
              }
              iVar5 = *(int *)(iVar6 + 0x30);
              uVar13 = 0x3815;
              memset(acStack_40c,0,0x80);
              sprintf(acStack_40c,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar5 + 0x2e),
                      (uint)*(byte *)(iVar5 + 0x2f),(uint)*(byte *)(iVar5 + 0x30),
                      (uint)*(byte *)(iVar5 + 0x31),(uint)*(byte *)(iVar5 + 0x32),
                      (uint)*(byte *)(iVar5 + 0x33));
              memset(auStack_44c,0,0x40);
              memset(acStack_38c,0,0x9a);
              FUN_00408190(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                           *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                           *(undefined4 *)(iVar5 + 0x28),auStack_44c,0x40,"---");
              if (*(int *)(iVar9 + 0x38) != 1) {
                uVar13 = 0x3816;
              }
              local_3c = (char *)apmngr_db_product_type_str
                                           (*(undefined1 *)(*(int *)(iVar4 + 0x10) + 0x138));
              uVar8 = FUN_006505b0(iVar5 + 0x2e,acStack_38c);
              loggerk_reg(0x54,uVar13,1,local_3c,1,uVar8,1,auStack_44c,1,acStack_40c,0);
              uVar13 = 0xd;
              if (*(int *)(iVar9 + 0x38) != 1) {
                uVar13 = 0xe;
              }
              *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x48) = uVar13;
              if (*(int *)(iVar9 + 0x38) == 9) {
                apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
              }
              iVar5 = apupd_update_wtp_entry_delete(iVar6);
              iVar6 = local_40;
              if (iVar5 == -1) {
                if ((g_apupd_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                goto LAB_0065d3c4;
                pcVar12 = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
                uVar13 = 0x1473;
                goto LAB_0065d5d8;
              }
            }
            goto LAB_0065ccb4;
          }
          if (iVar6 == 9) {
            uVar7 = *(uint *)(iVar9 + 0x160);
            goto LAB_0065ccf8;
          }
        } while ((iVar6 != 3) && (iVar5 = local_2c, iVar6 != 9));
        if (iVar15 == 0) {
          iVar15 = uci_alloc_context();
          if (iVar15 == 0) {
            uVar13 = 0xffffffff;
            if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("[APUPD_ERROR]%32s() %05d: alloc uci context failed.\r\n",
                     "apupd_update_model_timeout_check",0x1481);
              uVar13 = 0xffffffff;
            }
            goto LAB_0065cc4c;
          }
          iVar5 = uci_load(iVar15,"cloud_status_ap",&local_474);
          if (iVar5 == 0) {
            local_34 = *(int *)(iVar9 + 0x38);
            goto LAB_0065cd1c;
          }
        }
        else {
          local_34 = *(int *)(iVar9 + 0x38);
LAB_0065cd1c:
          iVar5 = *(int *)(iVar4 + 0x10);
          local_3c = local_474;
          memset(&local_470,0,0x21);
          memset(auStack_44c,0,0x21);
          memset(acStack_40c,0,100);
          memset(acStack_38c,0,100);
          iVar5 = iVar5 + 0x119;
          if ((local_3c == (char *)0x0) || (iVar5 == 0)) {
LAB_0065cfe0:
            iVar5 = local_2c;
            if ((g_apupd_error != 0) && (iVar9 = is_target_debug_ap(), iVar5 = local_2c, iVar9 != 0)
               ) {
              printf("[APUPD_ERROR]%32s() %05d: apupd_get_check_status_from_uci failed.\r\n",
                     "apupd_update_model_timeout_check",0x1566);
              iVar5 = local_2c;
            }
            goto LAB_0065ccb4;
          }
          local_40 = iVar9 + 0x18;
          FUN_004084f0(iVar5,0x10,&local_470);
          FUN_004084f0(local_40,0x10,auStack_44c);
          if (local_34 == 1) {
            sprintf(acStack_40c,"check_fw_ver_%s_%s",auStack_44c,&local_470);
          }
          else {
            sprintf(acStack_40c,"download_fw_%s_%s",auStack_44c,&local_470);
            sprintf(acStack_38c,"client_info_%s_%s",auStack_44c,&local_470);
            local_38 = -1;
          }
          if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[APUPD_DEBUG]%32s() %05d: uci_name:%s\r\n","apupd_get_check_status_from_uci",
                   0x13be,acStack_40c);
          }
          local_30 = 0;
          piVar16 = *(int **)(local_3c + 0x10);
          while (piVar16 != (int *)(local_3c + 0x10)) {
            if (g_apupd_debug == 0) {
              pcVar12 = (char *)piVar16[3];
            }
            else {
              iVar5 = is_target_debug_ap();
              if (iVar5 == 0) {
                pcVar12 = (char *)piVar16[3];
              }
              else {
                printf("[APUPD_DEBUG]%32s() %05d: uci_name:%s\r\n","apupd_get_check_status_from_uci"
                       ,0x13c2,piVar16[3]);
                pcVar12 = (char *)piVar16[3];
              }
            }
            iVar5 = strcmp(acStack_40c,pcVar12);
            if (iVar5 == 0) {
              pcVar12 = (char *)uci_lookup_option_string(iVar15,piVar16,"action_status");
              if (pcVar12 == (char *)0x0) goto LAB_0065cfe0;
              uVar7 = atoi(pcVar12);
              local_30 = 1;
              if (g_apupd_debug == 0) {
LAB_0065ce58:
                piVar16 = (int *)*piVar16;
                uVar18 = uVar7;
              }
              else {
                iVar5 = is_target_debug_ap();
                uVar18 = uVar7;
                if (iVar5 == 0) {
                  piVar16 = (int *)*piVar16;
                }
                else {
                  pcVar12 = "[APUPD_DEBUG]%32s() %05d: action_status:%d\r\n";
                  uVar13 = 0x13c9;
LAB_0065cf40:
                  printf(pcVar12,"apupd_get_check_status_from_uci",uVar13,uVar7);
                  piVar16 = (int *)*piVar16;
                }
              }
            }
            else {
              uVar7 = uVar18;
              if ((local_34 == 1) || (iVar5 = strcmp(acStack_38c,pcVar12), iVar5 != 0))
              goto LAB_0065ce58;
              pcVar12 = (char *)uci_lookup_option_string(iVar15,piVar16,"fw_download_status");
              if (pcVar12 == (char *)0x0) goto LAB_0065cfe0;
              local_38 = atoi(pcVar12);
              if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: fw_download_status:%d\r\n",
                       "apupd_get_check_status_from_uci",0x13d5,local_38);
              }
              pcVar12 = (char *)uci_lookup_option_string(iVar15,piVar16,"fw_download_progress");
              if (pcVar12 == (char *)0x0) goto LAB_0065ce58;
              if (g_apupd_debug == 0) {
                piVar16 = (int *)*piVar16;
              }
              else {
                iVar5 = is_target_debug_ap();
                if (iVar5 != 0) {
                  uVar7 = atoi(pcVar12);
                  pcVar12 = "[APUPD_DEBUG]%32s() %05d: fw_download_progress:%d\r\n";
                  uVar13 = 0x13dd;
                  goto LAB_0065cf40;
                }
                piVar16 = (int *)*piVar16;
              }
            }
          }
          if (local_30 == 0) {
            if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[APUPD_DEBUG]%32s() %05d: get action status of %s failed\r\n",
                     "apupd_get_check_status_from_uci",0x13e5,acStack_40c);
            }
            goto LAB_0065cfe0;
          }
          if (uVar18 < 2) {
            iVar5 = *(int *)(iVar4 + 0x10);
LAB_0065d3e8:
            apupd_delete_info_in_uci(iVar5 + 0x119,local_40);
            iVar6 = FUN_004081b0(iVar9 + 0xc);
            while (iVar5 = local_2c, iVar6 != 0) {
              local_40 = FUN_00408680(iVar6);
              if (*(int *)(*(int *)(iVar4 + 0x10) + 0x7ec) != 3) {
                uVar13 = 4;
                if (*(int *)(iVar9 + 0x38) != 1) {
                  uVar13 = 5;
                }
                iVar5 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar6 + 0x30),uVar13);
                if (iVar5 == -1) {
                  if ((g_apupd_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                  goto LAB_0065d3c4;
                  pcVar12 = "[APUPD_ERROR]%32s() %05d: add log failed.\r\n";
                  uVar13 = 0x149d;
                  goto LAB_0065d5d8;
                }
              }
              iVar5 = *(int *)(iVar6 + 0x30);
              uVar13 = 0x3815;
              memset(acStack_40c,0,0x80);
              sprintf(acStack_40c,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar5 + 0x2e),
                      (uint)*(byte *)(iVar5 + 0x2f),(uint)*(byte *)(iVar5 + 0x30),
                      (uint)*(byte *)(iVar5 + 0x31),(uint)*(byte *)(iVar5 + 0x32),
                      (uint)*(byte *)(iVar5 + 0x33));
              memset(auStack_44c,0,0x40);
              memset(acStack_38c,0,0x9a);
              FUN_00408190(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                           *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                           *(undefined4 *)(iVar5 + 0x28),auStack_44c,0x40,"---");
              if (*(int *)(iVar9 + 0x38) != 1) {
                uVar13 = 0x3816;
              }
              local_3c = (char *)apmngr_db_product_type_str
                                           (*(undefined1 *)(*(int *)(iVar4 + 0x10) + 0x138));
              uVar8 = FUN_006505b0(iVar5 + 0x2e,acStack_38c);
              loggerk_reg(0x54,uVar13,1,local_3c,1,uVar8,1,auStack_44c,1,acStack_40c,0);
              uVar13 = 0xd;
              if (*(int *)(iVar9 + 0x38) != 1) {
                uVar13 = 0xe;
              }
              *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x48) = uVar13;
              if (*(int *)(iVar9 + 0x38) == 9) {
                apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
              }
              iVar5 = apupd_update_wtp_entry_delete(iVar6);
              iVar6 = local_40;
              if (iVar5 == -1) {
                if ((g_apupd_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                goto LAB_0065d3c4;
                pcVar12 = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
                uVar13 = 0x14b3;
                goto LAB_0065d5d8;
              }
            }
            goto LAB_0065ccb4;
          }
          if (uVar18 == 5) {
            iVar5 = *(int *)(iVar4 + 0x10);
            goto LAB_0065d3e8;
          }
          iVar5 = local_2c;
          if (uVar18 != 4) goto LAB_0065ccb4;
          if (local_38 == 0) {
            iVar5 = *(int *)(iVar4 + 0x10);
            goto LAB_0065d3e8;
          }
          if ((*(int *)(iVar9 + 0x38) != 1) && (local_38 != 2)) goto LAB_0065ccb4;
          if (g_apupd_debug == 0) {
            iVar5 = *(int *)(iVar9 + 0x38);
          }
          else {
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              iVar5 = *(int *)(iVar9 + 0x38);
            }
            else {
              printf("[APUPD_DEBUG]%32s() %05d: wtp list status get successful\r\n",
                     "apupd_update_model_timeout_check",0x14bc);
              iVar5 = *(int *)(iVar9 + 0x38);
            }
          }
          if (iVar5 == 1) {
            iVar6 = iVar19;
            if (iVar19 != 0) {
LAB_0065d22c:
              iVar3 = local_478;
              local_3c = (char *)(iVar9 + 0x5c);
              iVar14 = *(int *)(iVar4 + 0x10);
              memset(auStack_44c,0,0x21);
              memset(&local_470,0,0x21);
              memset(acStack_38c,0,100);
              memset(acStack_40c,0,100);
              iVar5 = local_2c;
              iVar19 = iVar6;
              if (iVar3 != 0) {
                iVar17 = 0;
                FUN_004084f0(iVar14 + 0x119,0x10,auStack_44c);
                bVar2 = false;
                FUN_004084f0(local_40,0x10,&local_470);
                sprintf(acStack_38c,"new_firmware_%s_%s",&local_470,auStack_44c);
                sprintf(acStack_40c,"upgrade_info_%s_%s",&local_470,auStack_44c);
                piVar16 = *(int **)(iVar3 + 0x10);
                local_34 = iVar3 + 0x10;
                local_40 = 0;
                while (piVar16 != (int *)local_34) {
                  pcVar12 = (char *)piVar16[3];
                  iVar5 = strcmp(acStack_38c,pcVar12);
                  if (iVar5 == 0) {
                    pcVar12 = (char *)uci_lookup_option_string(iVar6,piVar16,"fw_new_notify");
                    if (pcVar12 == (char *)0x0) {
                      piVar16 = (int *)*piVar16;
                    }
                    else {
                      iVar17 = atoi(pcVar12);
                      bVar2 = true;
                      piVar16 = (int *)*piVar16;
                    }
                  }
                  else {
                    iVar5 = strcmp(acStack_40c,pcVar12);
                    if (iVar5 == 0) {
                      pcVar12 = (char *)uci_lookup_option_string(iVar6,piVar16,"download_url");
                      if (pcVar12 == (char *)0x0) {
                        piVar16 = (int *)*piVar16;
                      }
                      else if (*pcVar12 == '\0') {
                        piVar16 = (int *)*piVar16;
                      }
                      else {
                        strcpy(local_3c,pcVar12);
                        piVar16 = (int *)*piVar16;
                        local_40 = 1;
                      }
                    }
                    else {
                      piVar16 = (int *)*piVar16;
                    }
                  }
                }
                iVar5 = local_2c;
                if (bVar2) {
                  if (iVar17 == 0) {
                    iVar9 = FUN_004081b0(iVar9 + 0xc);
                    while (iVar5 = local_2c, iVar9 != 0) {
                      iVar5 = FUN_00408680(iVar9);
                      *(undefined4 *)(*(int *)(iVar9 + 0x30) + 0x48) = 0xf;
                      iVar6 = apupd_update_wtp_entry_delete(iVar9);
                      iVar9 = iVar5;
                      if (iVar6 == -1) {
                        if ((g_apupd_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                        goto LAB_0065d3c4;
                        pcVar12 = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
                        uVar13 = 0x14dd;
                        goto LAB_0065d5d8;
                      }
                    }
                  }
                  else if ((local_40 != 0) && (*(char *)(iVar9 + 0x5c) != '\0')) {
                    *(undefined4 *)(iVar9 + 0x38) = 2;
                    apupd_get_version_num = apupd_get_version_num + -1;
                  }
                }
              }
              goto LAB_0065ccb4;
            }
            iVar6 = uci_alloc_context();
            if (iVar6 == 0) {
              if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                pcVar12 = "[APUPD_ERROR]%32s() %05d: alloc uci context failed.\r\n";
                uVar13 = 0x14c4;
                goto LAB_0065d5d8;
              }
            }
            else {
              iVar5 = uci_load(iVar6,"cloud_config_ap",&local_478);
              if (iVar5 == 0) goto LAB_0065d22c;
              uci_free_context(iVar6);
            }
          }
          else {
            __s_00 = (char *)(iVar9 + 0x5c);
            memset(acStack_2f0,0,0x100);
            pcVar10 = strrchr(__s_00,0x2f);
            pcVar12 = pcVar10 + 1;
            if (pcVar10 == (char *)0x0) {
              pcVar12 = __s_00;
            }
            sprintf(acStack_2f0,"/tmp/%s",pcVar12);
            if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[APUPD_DEBUG]%32s() %05d: trnasfer download url %s to file path %s\r\n",
                     "apupd_update_model_timeout_check",0x14ee,__s_00,acStack_2f0);
            }
            __n = apupd_image_size_get(acStack_2f0);
            iVar5 = local_2c;
            if (__n == 0) goto LAB_0065ccb4;
            if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[APUPD_DEBUG]%32s() %05d: file path %s\'s file_size is %d\r\n",
                     "apupd_update_model_timeout_check",0x14f2,acStack_2f0,__n);
            }
            __s = (void *)FUN_00408450(__n,0x14f3);
            *(void **)(iVar9 + 0x48) = __s;
            if (__s == (void *)0x0) {
              if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                pcVar12 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
                uVar13 = 0x14f6;
LAB_0065d5d8:
                printf(pcVar12,"apupd_update_model_timeout_check",uVar13);
              }
            }
            else {
              memset(__s,0,__n);
              sVar11 = apupd_image_file_read(acStack_2f0,*(undefined4 *)(iVar9 + 0x48),__n);
              if (__n == sVar11) {
                local_470 = 0;
                local_46c = 0;
                local_468 = 0;
                local_464 = 0;
                if (((*(char *)(*(int *)(iVar4 + 0x10) + 0x13a) == '\0') &&
                    (cVar1 = *(char *)(*(int *)(iVar4 + 0x10) + 0x138), cVar1 != '\x01')) &&
                   (cVar1 != '\x03')) {
                  iVar5 = dkmgt_firmwareInfo_check(*(undefined4 *)(iVar9 + 0x48),__n,auStack_1f0);
                  if (iVar5 == 0) {
                    iVar5 = apupd_cloud_image_file_check(auStack_1f0,*(int *)(iVar4 + 0x10) + 0x119)
                    ;
                    if ((iVar5 == 0) &&
                       (iVar5 = apupd_transfer_softver_str_to_softver_struct(auStack_1dc,&local_470)
                       , iVar5 == 0)) goto LAB_0065daa4;
                  }
                  iVar5 = FUN_004081b0(iVar9 + 0xc);
                  while (iVar5 != 0) {
                    local_40 = FUN_00408680(iVar5);
                    if (*(int *)(*(int *)(iVar4 + 0x10) + 0x7ec) == 3) {
                      iVar6 = *(int *)(iVar5 + 0x30);
                    }
                    else {
                      iVar6 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar5 + 0x30),6);
                      if (iVar6 == -1) {
                        FUN_00407df0(*(undefined4 *)(iVar9 + 0x48));
                        *(undefined4 *)(iVar9 + 0x48) = 0;
                        if ((g_apupd_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                        goto LAB_0065d3c4;
                        pcVar12 = "[APUPD_ERROR]%32s() %05d: add log failed.\r\n";
                        uVar13 = 0x1511;
                        goto LAB_0065d5d8;
                      }
                      iVar6 = *(int *)(iVar5 + 0x30);
                    }
                    memset(acStack_40c,0,0x80);
                    sprintf(acStack_40c,"%02X-%02X-%02X-%02X-%02X-%02X",
                            (uint)*(byte *)(iVar6 + 0x2e),(uint)*(byte *)(iVar6 + 0x2f),
                            (uint)*(byte *)(iVar6 + 0x30),(uint)*(byte *)(iVar6 + 0x31),
                            (uint)*(byte *)(iVar6 + 0x32),(uint)*(byte *)(iVar6 + 0x33));
                    memset(auStack_44c,0,0x40);
                    memset(acStack_38c,0,0x9a);
                    FUN_00408190(*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x1c),
                                 *(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x24),
                                 *(undefined4 *)(iVar6 + 0x28),auStack_44c,0x40,"---");
                    uVar13 = apmngr_db_product_type_str
                                       (*(undefined1 *)(*(int *)(iVar4 + 0x10) + 0x138));
                    uVar8 = FUN_006505b0(iVar6 + 0x2e,acStack_38c);
                    loggerk_reg(0x54,0x3817,1,uVar13,1,uVar8,1,auStack_44c,1,acStack_40c,0);
                    *(undefined4 *)(*(int *)(iVar5 + 0x30) + 0x48) = 0x10;
                    iVar6 = apupd_update_wtp_entry_delete(iVar5);
                    iVar5 = local_40;
                    if (iVar6 == -1) {
                      FUN_00407df0(*(undefined4 *)(iVar9 + 0x48));
                      *(undefined4 *)(iVar9 + 0x48) = 0;
                      if ((g_apupd_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                      goto LAB_0065d3c4;
                      pcVar12 = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
                      uVar13 = 0x1525;
                      goto LAB_0065d5d8;
                    }
                  }
                  goto LAB_0065db94;
                }
LAB_0065daa4:
                if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                  printf("[APUPD_DEBUG]%32s() %05d: tmp_update_model->model->is_large_fw = %d\r\n",
                         "apupd_update_model_timeout_check",0x152d,
                         (uint)*(byte *)(*(int *)(iVar4 + 0x10) + 0x13a));
                }
                if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                  printf("[APUPD_DEBUG]%32s() %05d: tmp_online_wtp_list->is_large_fw = %d\r\n",
                         "apupd_update_model_timeout_check",0x152e,(uint)*(byte *)(iVar9 + 0x174));
                }
                if (g_apupd_debug == 0) {
                  iVar5 = *(int *)(iVar4 + 0x10);
                }
                else {
                  iVar5 = is_target_debug_ap();
                  if (iVar5 == 0) {
                    iVar5 = *(int *)(iVar4 + 0x10);
                  }
                  else {
                    printf("[APUPD_DEBUG]%32s() %05d: tmp_online_wtp_list->got_image_size = %d\r\n",
                           "apupd_update_model_timeout_check",0x152f,*(undefined4 *)(iVar9 + 0x194))
                    ;
                    iVar5 = *(int *)(iVar4 + 0x10);
                  }
                }
                if ((*(char *)(iVar5 + 0x138) != '\x01') && (*(char *)(iVar5 + 0x138) != '\x03')) {
                  memcpy((void *)(iVar9 + 0x164),&local_470,0x10);
                  memcpy((void *)(iVar9 + 0x28),auStack_1f0,0x10);
                }
                apupd_md5_calc(*(undefined4 *)(iVar9 + 0x48),__n,iVar9 + 0x4c,5);
                if (*(char *)(iVar9 + 0x174) == '\x01') {
                  if (*(int *)(iVar9 + 0x194) == 0) {
                    *(undefined1 *)(iVar9 + 400) = 0;
                    cVar1 = *(char *)(*(int *)(iVar4 + 0x10) + 0x138);
                    if (cVar1 == '\x01') goto LAB_0065dd28;
                    if (cVar1 != '\x03') {
                      dkmgt_firmwareInfo_check(*(undefined4 *)(iVar9 + 0x48),__n,auStack_1f0);
                      apupd_transfer_softver_str_to_softver_struct(auStack_1dc,&local_470);
                      memcpy((void *)(*(int *)(iVar4 + 0x10) + 0x1c4),&local_470,0x10);
                      memcpy((void *)(iVar9 + 0x28),auStack_1f0,0x10);
                      goto LAB_0065dd28;
                    }
                    iVar5 = *(int *)(iVar9 + 0x194);
                  }
                  else {
                    *(char *)(iVar9 + 400) = *(char *)(iVar9 + 400) + '\x01';
LAB_0065dd28:
                    iVar5 = *(int *)(iVar9 + 0x194);
                  }
                  *(size_t *)(iVar9 + 0x194) = iVar5 + __n;
                  iVar5 = *(int *)(iVar4 + 0x10);
                  if (*(int *)(iVar5 + 0x1a8) == *(int *)(iVar5 + 0x144)) {
                    *(undefined4 *)(iVar5 + 0x1a8) = 0;
                    if (g_apupd_debug == 0) {
                      iVar5 = *(int *)(iVar9 + 0x38);
                      goto LAB_0065db1c;
                    }
                    iVar5 = is_target_debug_ap();
                    if (iVar5 != 0) {
                      printf("[APUPD_DEBUG]%32s() %05d: reply_num == need_update, set reply_num = 0\r\n"
                             ,"apupd_update_model_timeout_check",0x154b);
                    }
                  }
                  if (g_apupd_debug == 0) {
                    iVar5 = *(int *)(iVar9 + 0x38);
                  }
                  else {
                    iVar5 = is_target_debug_ap();
                    if (iVar5 == 0) {
                      iVar5 = *(int *)(iVar9 + 0x38);
                    }
                    else {
                      printf("[APUPD_DEBUG]%32s() %05d: sub_image_num = %d, got_image_size = %d, reply_num = %d\r\n"
                             ,"apupd_update_model_timeout_check",0x154d,(uint)*(byte *)(iVar9 + 400)
                             ,*(undefined4 *)(iVar9 + 0x194),
                             *(undefined4 *)(*(int *)(iVar4 + 0x10) + 0x1a8));
                      iVar5 = *(int *)(iVar9 + 0x38);
                    }
                  }
                }
                else {
                  iVar5 = *(int *)(iVar9 + 0x38);
                }
LAB_0065db1c:
                uVar13 = 4;
                *(size_t *)(iVar9 + 0x44) = __n;
                if (iVar5 != 3) {
                  uVar13 = 10;
                }
                *(undefined4 *)(iVar9 + 0x38) = uVar13;
                if (*(char *)(iVar9 + 0x174) == '\x01') {
                  if (*(uint *)(iVar9 + 0x178) <= *(uint *)(iVar9 + 0x194)) {
                    iVar5 = *(int *)(iVar4 + 0x10);
                    goto LAB_0065dbd8;
                  }
                  if (g_apupd_debug == 0) {
                    iVar5 = *(int *)(iVar4 + 0x10);
                  }
                  else {
                    iVar5 = is_target_debug_ap();
                    if (iVar5 == 0) {
                      iVar5 = *(int *)(iVar4 + 0x10);
                    }
                    else {
                      printf("[APUPD_DEBUG]%32s() %05d: reset uci info\r\n",
                             "apupd_update_model_timeout_check",0x1553);
                      iVar5 = *(int *)(iVar4 + 0x10);
                    }
                  }
                  apupd_delete_info_in_uci(iVar5 + 0x119,local_40);
                  apupd_get_newest_firmware(*(int *)(iVar4 + 0x10) + 0x119,local_40);
                }
                else {
                  iVar5 = *(int *)(iVar4 + 0x10);
LAB_0065dbd8:
                  apupd_delete_info_in_uci(iVar5 + 0x119,local_40);
                }
                apupd_download_software_num = apupd_download_software_num + -1;
LAB_0065db94:
                remove(acStack_2f0);
                iVar5 = local_2c;
                goto LAB_0065ccb4;
              }
              if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[APUPD_ERROR]%32s() %05d: read file %s failed.\r\n",
                       "apupd_update_model_timeout_check",0x14fc,acStack_2f0);
              }
              FUN_00407df0(*(undefined4 *)(iVar9 + 0x48));
            }
          }
LAB_0065d3c4:
          if (iVar15 == 0) goto LAB_0065d3dc;
          uci_unload(iVar15,local_474);
        }
        uci_free_context(iVar15);
LAB_0065d3dc:
        uVar13 = 0xffffffff;
        goto LAB_0065cc4c;
      }
LAB_0065cc1c:
      iVar4 = FUN_00408680(iVar4);
      if (iVar4 == 0) break;
      iVar5 = *(int *)(iVar4 + 0x10);
    } while( true );
  }
  if (iVar15 != 0) {
    uci_unload(iVar15,local_474);
    uci_free_context(iVar15);
  }
  uVar13 = 0;
LAB_0065cc4c:
  if (iVar19 != 0) {
    uci_unload(iVar19,local_478);
    uci_free_context(iVar19);
  }
  return uVar13;
}

