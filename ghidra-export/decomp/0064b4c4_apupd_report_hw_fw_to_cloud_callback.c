// func apupd_report_hw_fw_to_cloud_callback @ 0064b4c4 size=2128

void apupd_report_hw_fw_to_cloud_callback(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 local_1f98;
  undefined4 local_1f94;
  undefined4 local_1f90;
  undefined4 local_1f8c;
  undefined4 local_1f88;
  undefined4 local_1f84;
  undefined4 local_1f80;
  undefined4 local_1f7c;
  undefined4 local_1f78;
  undefined4 local_1f74;
  undefined4 local_1f70;
  undefined4 local_1f6c;
  undefined4 local_1f68;
  char *local_1f64;
  char *local_1f60;
  undefined1 *local_1f5c;
  undefined4 local_1f58;
  char *local_1f54;
  undefined4 local_1f50;
  undefined4 local_1f4c;
  undefined1 auStack_1f48 [32];
  undefined1 local_1f28;
  undefined4 local_1f24;
  undefined4 local_1f20;
  undefined4 local_1f1c;
  undefined4 local_1f18;
  undefined1 local_1f04;
  undefined1 auStack_1f00 [200];
  undefined1 auStack_1e38 [36];
  undefined1 auStack_1e14 [48];
  undefined1 auStack_1de4 [20];
  undefined1 auStack_1dd0 [36];
  undefined1 auStack_1dac [68];
  undefined1 auStack_1d68 [48];
  undefined1 auStack_1d38 [1284];
  char acStack_1834 [2048];
  undefined1 auStack_1034 [2048];
  char acStack_834 [2052];
  int local_30;
  
  local_1f64 = (char *)0x0;
  local_1f60 = (char *)0x0;
  local_1f5c = (undefined1 *)0x0;
  local_1f58 = 0;
  local_1f54 = (char *)0x0;
  local_1f50 = 0;
  local_1f4c = 0;
  local_1f98 = 0xffffffff;
  memset(acStack_834,0,0x800);
  memset(auStack_1034,0,0x800);
  memset(acStack_1834,0,0x800);
  local_1f74 = 0;
  local_1f70 = 0;
  local_1f6c = 0;
  local_1f68 = 0;
  local_1f84 = 0;
  local_1f80 = 0;
  local_1f7c = 0;
  local_1f78 = 0;
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_report_hw_fw_to_cloud_callback begin\r\n",
           "apupd_report_hw_fw_to_cloud_callback",0x16d1);
  }
  iVar1 = FUN_00408660(auStack_1f00);
  if (iVar1 == 0) {
    sprintf(acStack_1834,
            "&deviceId=%s&fwId=%s&fwVer=%s&hwId=%s&deviceHwVer=%s&deviceMac=%s&deviceModel=%s&tcspVer=%s&deviceName=%s&alias=%s"
            ,auStack_1e14,auStack_1d68,auStack_1dac,auStack_1d38,auStack_1dd0,auStack_1de4,
            auStack_1e38,&DAT_0071484c,auStack_1f00,"SMB_Device");
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: device_info is %s\r\n",
             "apupd_report_hw_fw_to_cloud_callback",0x16df,acStack_1834);
    }
    iVar1 = cJSON_CreateObject();
    if (iVar1 != 0) {
      if (DAT_007cc7c0 == 0) {
        if (DAT_007cc7e8 == 1) {
          DAT_007cc7e8 = 0;
          if ((g_apupd_debug != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
            printf("[APUPD_DEBUG]%32s() %05d: no hw-list but need report.\n\r\n",
                   "apupd_report_hw_fw_to_cloud_callback",0x16ed);
          }
          goto LAB_0064b7c0;
        }
        if ((g_apupd_debug == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0)) {
LAB_0064b708:
          pcVar7 = (char *)0x0;
          iVar10 = -1;
        }
        else {
          pcVar8 = "[APUPD_DEBUG]%32s() %05d: no hw-list and go exit.\n\r\n";
          uVar9 = 0x16f1;
LAB_0064ba10:
          pcVar7 = (char *)0x0;
          printf(pcVar8,"apupd_report_hw_fw_to_cloud_callback",uVar9);
          iVar10 = -1;
        }
      }
      else {
LAB_0064b7c0:
        iVar10 = cJSON_CreateObject();
        if (iVar10 == 0) {
          pcVar7 = (char *)0x0;
          if (g_apupd_error == 0) goto LAB_0064b708;
          iVar10 = is_target_debug_ap();
          if (iVar10 != 0) {
            pcVar8 = "[APUPD_ERROR]%32s() %05d: malloc obj failed.\n\r\n";
            uVar9 = 0x16f9;
            goto LAB_0064ba10;
          }
          iVar10 = -1;
        }
        else {
          cJSON_AddItemToObject(iVar1,&DAT_00714930,iVar10);
          FUN_004082d0(apupd_db_mutex,0xffffffff);
          for (iVar2 = FUN_004081b0(&apupd_report_upgrade_info); iVar2 != 0;
              iVar2 = FUN_00408680(iVar2)) {
            if (*(int *)(iVar2 + 0x1c) != 0) {
              local_1f74 = 0;
              local_1f70 = 0;
              local_1f6c = 0;
              local_1f68 = 0;
              iVar3 = memcmp((void *)(iVar2 + 0xc),&local_1f74,0x10);
              if (iVar3 == 0) {
                if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  printf("[APUPD_DEBUG]%32s() %05d: invalid hw_id,continue.\n\r\n",
                         "apupd_report_hw_fw_to_cloud_callback",0x170b);
                }
              }
              else {
                iVar3 = cJSON_CreateArray();
                if (iVar3 == 0) {
                  if ((g_apupd_error != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
                    printf("[APUPD_ERROR]%32s() %05d: malloc obj failed.\n\r\n",
                           "apupd_report_hw_fw_to_cloud_callback",0x1712);
                  }
                  FUN_00407f30(apupd_db_mutex);
                  goto LAB_0064b708;
                }
                local_1f24 = 0;
                local_1f20 = 0;
                local_1f1c = 0;
                local_1f18 = 0;
                FUN_004084f0((void *)(iVar2 + 0xc),0x10,&local_1f24);
                local_1f04 = 0;
                iVar4 = FUN_004081b0(*(undefined4 *)(iVar2 + 0x1c));
                local_30 = 0;
                for (; iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
                  local_1f84 = 0;
                  local_1f80 = 0;
                  local_1f7c = 0;
                  local_1f78 = 0;
                  iVar5 = memcmp((void *)(iVar4 + 0xc),&local_1f84,0x10);
                  if (iVar5 == 0) {
                    if ((g_apupd_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                      printf("[APUPD_DEBUG]%32s() %05d: invalid fw_id,continue.\n\r\n",
                             "apupd_report_hw_fw_to_cloud_callback",0x1722);
                    }
                  }
                  else {
                    memset(auStack_1f48,0,0x21);
                    FUN_004084f0((void *)(iVar4 + 0xc),0x10,auStack_1f48);
                    local_1f28 = 0;
                    iVar5 = cJSON_CreateString(auStack_1f48);
                    if (iVar5 == 0) {
                      if ((g_apupd_error != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
                        printf("[APUPD_ERROR]%32s() %05d: malloc obj failed.\n\r\n",
                               "apupd_report_hw_fw_to_cloud_callback",0x172c);
                      }
                      FUN_00407f30(apupd_db_mutex);
                      cJSON_Delete(iVar3);
                      goto LAB_0064b708;
                    }
                    cJSON_AddItemToArray(iVar3,iVar5);
                    local_30 = 1;
                  }
                }
                if (local_30 == 0) {
                  cJSON_Delete(iVar3,&local_1f24);
                }
                else {
                  cJSON_AddItemToObject(iVar10,&local_1f24,iVar3);
                }
              }
            }
          }
          FUN_00407f30(apupd_db_mutex);
          uVar9 = cJSON_CreateString(auStack_1e14);
          cJSON_AddItemToObject(iVar1,"deviceId",uVar9);
          pcVar7 = (char *)cJSON_Print(iVar1);
          if ((g_apupd_debug != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
            printf("[APUPD_DEBUG]%32s() %05d: tmp_report_str1 is %s\r\n",
                   "apupd_report_hw_fw_to_cloud_callback",0x1745,pcVar7);
          }
          if (pcVar7 == (char *)0x0) {
            iVar10 = -1;
            if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar8 = "[APUPD_ERROR]%32s() %05d: malloc obj failed.\n\r\n";
              uVar9 = 0x1749;
LAB_0064bb6c:
              printf(pcVar8,"apupd_report_hw_fw_to_cloud_callback",uVar9);
            }
          }
          else {
            local_1f94 = 0;
            local_1f90 = 0;
            local_1f8c = 0;
            local_1f88 = 0;
            sVar6 = strlen(pcVar7);
            apupd_md5_calc(pcVar7,sVar6,&local_1f94,5);
            iVar10 = memcmp(&local_1f94,&g_apupd_report_buf_md5,0x10);
            if (iVar10 != 0) {
              strcpy(acStack_834,pcVar7);
              free(pcVar7);
              cJSON_Delete(iVar1);
              local_1f64 = "/common/v3/uploadSubscribeMsg";
              local_1f54 = acStack_1834;
              local_1f5c = auStack_1034;
              local_1f58 = 0x800;
              local_1f60 = acStack_834;
              iVar10 = sendto_basic_by_short_link(&local_1f64,&local_1f98);
              if (-1 < iVar10) {
                memcpy(&g_apupd_report_buf_md5,&local_1f94,0x10);
                if (DAT_007cc7c0 != 0) {
                  DAT_007cc7e8 = 1;
                }
                goto LAB_0064b598;
              }
              if ((g_apupd_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_0064b598;
              pcVar7 = "[APUPD_DEBUG]%32s() %05d: sendto_basic_by_short_link failed.\n\r\n";
              uVar9 = 0x1765;
              goto LAB_0064b780;
            }
            iVar10 = 0;
            if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar8 = "[APUPD_ERROR]%32s() %05d: same report info just return.\n\r\n";
              uVar9 = 0x1751;
              goto LAB_0064bb6c;
            }
          }
        }
      }
      cJSON_Delete(iVar1);
      if (pcVar7 != (char *)0x0) {
        free(pcVar7);
      }
      goto LAB_0064b598;
    }
    iVar10 = -1;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0064b598;
    pcVar7 = "[APUPD_ERROR]%32s() %05d: malloc obj failed.\n\r\n";
    uVar9 = 0x16e4;
  }
  else {
    iVar10 = -1;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0064b598;
    pcVar7 = "[APUPD_ERROR]%32s() %05d: Failed to get device info\r\n";
    uVar9 = 0x16d5;
  }
LAB_0064b780:
  printf(pcVar7,"apupd_report_hw_fw_to_cloud_callback",uVar9);
LAB_0064b598:
  if (DAT_007cc7c8 != -1) {
    FUN_00408060();
  }
  DAT_007cc7c8 = -1;
  if ((((iVar10 != 0) &&
       (DAT_007cc7c8 = FUN_00408340(g_apupd_report_interval,0,apupd_timer_report_hw_fw_to_cloud,0,0,
                                    "apupd_report_hw_fw_to_cloud_callback",0x178d),
       DAT_007cc7c8 == -1)) && (g_apupd_error != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0))
  {
    printf("[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n",
           "apupd_report_hw_fw_to_cloud_callback",0x1790);
  }
  return;
}

