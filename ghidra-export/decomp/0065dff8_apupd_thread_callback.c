// func apupd_thread_callback @ 0065dff8 size=2236

void apupd_thread_callback(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  
LAB_0065e030:
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  while (iVar1 = FUN_00407fe0(apupd_update_model_list), iVar1 == 0) {
    FUN_004086c0(apupd_db_cond,apupd_db_mutex,0xffffffff);
  }
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_config_update_response_check start\r\n",
           "apupd_thread_callback",0x163c);
  }
  iVar1 = apupd_update_wtp_config_update_response_check();
  if (((iVar1 == -1) && (g_apupd_error != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: check wtp skip update response failed.\r\n",
           "apupd_thread_callback",0x1640);
  }
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_model_timeout_check start\r\n",
           "apupd_thread_callback",0x1642);
  }
  iVar1 = apupd_update_model_timeout_check();
  if (((iVar1 == -1) && (g_apupd_error != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: check model timeout failed.\r\n","apupd_thread_callback",
           0x1646);
  }
  if (*apupd_config != 0) {
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_update_model_and_update_wtp_add start\r\n",
             "apupd_thread_callback",0x1650);
    }
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_update_model_and_update_wtp_add start\r\n",
             "apupd_update_model_and_update_wtp_add",0x158f);
    }
    iVar1 = FUN_004081b0(apupd_update_model_list);
joined_r0x0065e0e8:
    do {
      iVar3 = iVar1;
      if (iVar3 == 0) goto LAB_0065e258;
      iVar1 = FUN_00408680(iVar3);
      if (APUPD_UPDATING_MODLE_NUM_MAX <= apupd_updating_model_num) {
        if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_updating_model_num:%u\r\n",
                 "apupd_update_model_and_update_wtp_add",0x159a,apupd_updating_model_num);
        }
        if ((apupd_updating_wtp_num < (uint)(APUPD_UPDATING_WTP_NUM_MAX * 3) >> 2) &&
           (*(int *)(*(int *)(iVar3 + 0x10) + 0x140) != 2)) {
          iVar2 = FUN_00407fe0(iVar3 + 0x14);
          if (iVar2 == 0) {
            iVar2 = *(int *)(iVar3 + 0x10);
            goto LAB_0065e194;
          }
          if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[APUPD_DEBUG]%32s() %05d: APUPD_UPDATING_WTP_NUM_MAX = %d, apupd_updating_wtp_num = %d\r\n"
                   ,"apupd_update_model_and_update_wtp_add",0x15a9,APUPD_UPDATING_WTP_NUM_MAX,
                   apupd_updating_wtp_num);
          }
          iVar2 = apupd_update_model_handle
                            (iVar3,APUPD_UPDATING_WTP_NUM_MAX - apupd_updating_wtp_num);
          if (iVar2 != -1) {
            iVar2 = *(int *)(iVar3 + 0x10);
            goto LAB_0065e194;
          }
          if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            pcVar5 = "[APUPD_ERROR]%32s() %05d: add upadting wtp failed.\r\n";
            uVar6 = 0x15ac;
            goto LAB_0065e520;
          }
          goto LAB_0065e34c;
        }
        goto LAB_0065e258;
      }
      if ((uint)(APUPD_UPDATING_WTP_NUM_MAX * 3) >> 2 <= apupd_updating_wtp_num) {
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_updating_wtp_num:%u\r\n",
                 "apupd_update_model_and_update_wtp_add",0x15b6,apupd_updating_wtp_num);
        }
        goto LAB_0065e258;
      }
      if (*(int *)(*(int *)(iVar3 + 0x10) + 0x140) != 2) {
        iVar2 = FUN_00407fe0(iVar3 + 0x14);
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar3 + 0x10);
        }
        else {
          iVar2 = apupd_update_model_handle
                            (iVar3,APUPD_UPDATING_WTP_NUM_MAX - apupd_updating_wtp_num);
          if (iVar2 == -1) {
            if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              uVar6 = 0x15d9;
              pcVar5 = "[APUPD_ERROR]%32s() %05d: add upadting wtp failed.\r\n";
              goto LAB_0065e520;
            }
            goto LAB_0065e34c;
          }
          iVar2 = *(int *)(iVar3 + 0x10);
        }
        goto LAB_0065e194;
      }
    } while ((*(int *)(*(int *)(iVar3 + 0x10) + 0x7ec) == 1) &&
            (APUPD_IMPORT_SOFTWARE_NUM_MAX <= apupd_import_software_num));
    if (g_apupd_debug == 0) {
      iVar2 = *(int *)(iVar3 + 0x10);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar3 + 0x10);
      }
      else {
        printf("[APUPD_DEBUG]%32s() %05d: set model->state:APUPD_MODEL_STATE_TYPE_UPDATE\r\n",
               "apupd_update_model_and_update_wtp_add",0x15c6);
        iVar2 = *(int *)(iVar3 + 0x10);
      }
    }
    *(undefined4 *)(iVar2 + 0x140) = 3;
    apupd_updating_model_num = apupd_updating_model_num + 1;
    iVar2 = FUN_00407fe0(iVar3 + 0x14);
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar3 + 0x10);
LAB_0065e194:
      if ((*(int *)(iVar2 + 0x7ec) == 1) || (*(int *)(iVar2 + 0x7ec) == 3)) {
        iVar2 = FUN_004081b0(iVar3 + 0x30);
        while (iVar7 = iVar2, iVar7 != 0) {
          iVar2 = FUN_00408680(iVar7);
          iVar4 = FUN_00407fe0(iVar7 + 0xc);
          if (iVar4 == 0) {
            iVar4 = *(int *)(iVar7 + 0x38);
            if (*(int *)(iVar7 + 0x48) != 0) {
              if (((2 < iVar4) &&
                  (apupd_import_software_num = apupd_import_software_num - 1, g_apupd_debug != 0))
                 && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                       "apupd_update_model_and_update_wtp_add",0x15ee,apupd_import_software_num);
              }
              FUN_00407df0(*(undefined4 *)(iVar7 + 0x48));
              *(undefined4 *)(iVar7 + 0x48) = 0;
              iVar4 = *(int *)(iVar7 + 0x38);
            }
            if (iVar4 == 1) {
              apupd_get_version_num = apupd_get_version_num + -1;
              apupd_delete_info_in_uci(*(int *)(iVar3 + 0x10) + 0x119,iVar7 + 0x18);
              iVar4 = *(int *)(iVar7 + 0x38);
            }
            else {
              iVar4 = *(int *)(iVar7 + 0x38);
            }
            if ((iVar4 == 3) || (iVar4 == 9)) {
              apupd_download_software_num = apupd_download_software_num + -1;
              apupd_delete_info_in_uci(*(int *)(iVar3 + 0x10) + 0x119,iVar7 + 0x18);
              uVar6 = *(undefined4 *)(iVar3 + 0x2c);
            }
            else {
              uVar6 = *(undefined4 *)(iVar3 + 0x2c);
            }
            FUN_00407f40(uVar6,iVar7);
            FUN_00408500(iVar7);
            FUN_00407df0(iVar7);
          }
        }
      }
      iVar7 = *(int *)(iVar3 + 0x10);
      uVar6 = 0;
      iVar2 = FUN_00407fe0(iVar3 + 0x14);
      if ((iVar2 != 0) || (uVar6 = 0, *(int *)(iVar7 + 0x144) != 0)) goto LAB_0065e238;
      if (g_apupd_debug == 0) {
        iVar2 = *(int *)(iVar3 + 0x10);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar3 + 0x10);
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: tmp_update_model->update_wtp_list IS NULL\r\n",
                 "apupd_update_model_and_update_wtp_add",0x1608);
          iVar2 = *(int *)(iVar3 + 0x10);
        }
      }
      if (*(int *)(iVar2 + 0x140) == 3) {
        if (apupd_updating_model_num != 0) {
          apupd_updating_model_num = apupd_updating_model_num - 1;
          goto LAB_0065e1f0;
        }
        iVar4 = *(int *)(iVar2 + 0x7ec);
      }
      else {
LAB_0065e1f0:
        iVar4 = *(int *)(iVar2 + 0x7ec);
      }
      uVar6 = 4;
      if (iVar4 == 3) {
        uVar6 = 0;
      }
      *(undefined4 *)(iVar2 + 0x140) = uVar6;
      if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: set model[%s] state = %d\r\n",
               "apupd_update_model_and_update_wtp_add",0x1615,*(int *)(iVar3 + 0x10) + 0x5c,
               *(undefined4 *)(*(int *)(iVar3 + 0x10) + 0x140));
      }
      iVar2 = apupd_update_model_entry_delete(iVar3);
      if (iVar2 != -1) {
        uVar6 = 1;
        *(undefined1 *)(*(int *)(iVar3 + 0x10) + 0x1a1) = 2;
LAB_0065e238:
        if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: clear_model_flag = %d\r\n",
                 "apupd_update_model_and_update_wtp_add",0x161e,uVar6);
        }
        apupd_update_model_and_wtp_add_if_wtp_wait(iVar7,0,uVar6);
        goto joined_r0x0065e0e8;
      }
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065e34c;
      pcVar5 = "[APUPD_ERROR]%32s() %05d: delete upadting model failed.\r\n";
      uVar6 = 0x1618;
    }
    else {
      iVar2 = apupd_update_model_handle(iVar3,APUPD_UPDATING_WTP_NUM_MAX - apupd_updating_wtp_num);
      if (iVar2 != -1) {
        iVar2 = *(int *)(iVar3 + 0x10);
        goto LAB_0065e194;
      }
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065e34c;
      pcVar5 = "[APUPD_ERROR]%32s() %05d: add upadting wtp failed.\r\n";
      uVar6 = 0x15cd;
    }
LAB_0065e520:
    printf(pcVar5,"apupd_update_model_and_update_wtp_add",uVar6);
LAB_0065e34c:
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065e358;
    __format = "[APUPD_ERROR]%32s() %05d: add update model and update wtp failed.\r\n";
    pcVar5 = "apupd_thread_callback";
    uVar6 = 0x1654;
    goto LAB_0065e280;
  }
  goto LAB_0065e364;
LAB_0065e258:
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    uVar6 = 0x1623;
    __format = "[APUPD_DEBUG]%32s() %05d: apupd_update_model_and_update_wtp_add end\r\n";
    pcVar5 = "apupd_update_model_and_update_wtp_add";
LAB_0065e280:
    printf(__format,pcVar5,uVar6);
  }
LAB_0065e358:
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_model_and_update_wtp_add finish\r\n",
           "apupd_thread_callback",0x1656);
  }
LAB_0065e364:
  FUN_00407f30(apupd_db_mutex);
  sleep(10);
  goto LAB_0065e030;
}

