// func apupd_db_update_wtp_sub_image_action_request_confirm @ 0065ebb8 size=2660

undefined4
apupd_db_update_wtp_sub_image_action_request_confirm(void *param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *__dest;
  byte bVar3;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined1 auStack_308 [16];
  ushort local_2f8;
  int local_30;
  int local_2c;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: receive sub image action. type:%d\r\n",
           "apupd_db_update_wtp_sub_image_action_request_confirm",0x244b,(uint)*param_2);
  }
  memset(auStack_308,0,0x2d8);
  memset(auStack_308,0,0x2d8);
  if ((param_1 == (void *)0x0) || (param_2 == (byte *)0x0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n",
           "apupd_db_update_wtp_sub_image_action_request_confirm",0x245a);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0065f070;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get update wtp by mac failed.\r\n";
    uVar6 = 0x2464;
LAB_0065f348:
    printf(pcVar5,"apupd_db_update_wtp_sub_image_action_request_confirm",uVar6);
    goto LAB_0065f070;
  }
  iVar9 = *(int *)(*(int *)(iVar1 + 0x34) + 0x10);
  iVar2 = apmngr_db_entry_get_by_mac(param_1,auStack_308);
  if (iVar2 != 0) {
    if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: get ap_entry by mac[%02X:%02X:%02X:%02X:%02X:%02X] failed.\r\n"
             ,"apupd_db_update_wtp_sub_image_action_request_confirm",0x246c,
             (uint)*(byte *)(iVar1 + 0x18),(uint)*(byte *)(iVar1 + 0x19),
             (uint)*(byte *)(iVar1 + 0x1a),(uint)*(byte *)(iVar1 + 0x1b),
             (uint)*(byte *)(iVar1 + 0x1c),(uint)*(byte *)(iVar1 + 0x1d));
    }
    goto LAB_0065f070;
  }
  if (*(int *)(iVar1 + 0x28) == -1) {
    iVar2 = *(int *)(iVar1 + 0x20);
  }
  else {
    FUN_00408060();
    *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
    iVar2 = *(int *)(iVar1 + 0x20);
  }
  if (iVar2 == 3) {
    iVar2 = *(int *)(iVar1 + 0x24);
LAB_0065eca8:
    if (((iVar2 == 5) || (iVar2 == 7)) || (iVar2 == 10)) {
      if (*(int *)(iVar9 + 0x7ec) == 1) {
LAB_0065eddc:
        iVar2 = FUN_00407fa0(*(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x2c),
                             *(int *)(iVar1 + 0x30) + 0x58);
        if (iVar2 == 0) {
          local_30 = 0;
          uVar11 = 0;
          uVar10 = 0;
        }
        else {
          uVar10 = *(uint *)(iVar2 + 0x178);
          uVar11 = *(uint *)(iVar2 + 0x194);
          local_30 = *(int *)(iVar2 + 0x17c);
        }
      }
      else {
        if (*(int *)(iVar9 + 0x7ec) == 3) {
          if (*(int *)(*(int *)(iVar1 + 0x30) + 0x54) == 1) goto LAB_0065eddc;
          uVar10 = *(uint *)(iVar9 + 0x188);
        }
        else {
          uVar10 = *(uint *)(iVar9 + 0x188);
        }
        uVar11 = *(uint *)(iVar9 + 0x1a4);
        local_30 = *(int *)(iVar9 + 0x18c);
      }
      if (*param_2 == 1) {
        if (*(int *)(param_2 + 4) == 0) {
          *(undefined4 *)(iVar1 + 0x20) = 0;
          *(undefined4 *)(iVar1 + 0x24) = 8;
          FUN_00407e70();
          *(undefined4 *)(iVar1 + 0x2c) = extraout_v1;
          *(int *)(iVar9 + 0x1a8) = *(int *)(iVar9 + 0x1a8) + 1;
          if (g_apupd_debug == 0) {
            iVar2 = *(int *)(iVar9 + 0x1a8);
          }
          else {
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              iVar2 = *(int *)(iVar9 + 0x1a8);
            }
            else {
              printf("[APUPD_DEBUG]%32s() %05d: reply_num = %d, need_update = %d, total_image_size = %d, got_image_size = %d\r\n"
                     ,"apupd_db_update_wtp_sub_image_action_request_confirm",0x24a9,
                     *(undefined4 *)(iVar9 + 0x1a8),*(undefined4 *)(iVar9 + 0x144),uVar10,uVar11);
              iVar2 = *(int *)(iVar9 + 0x1a8);
            }
          }
          if ((iVar2 == *(int *)(iVar9 + 0x144)) && (uVar11 < uVar10)) {
            if (g_apupd_debug == 0) {
              iVar2 = *(int *)(iVar9 + 0x7ec);
            }
            else {
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                iVar2 = *(int *)(iVar9 + 0x7ec);
              }
              else {
                printf("[APUPD_DEBUG]%32s() %05d: tmp_model->upd_type = %d, tmp_update_wtp->wtp->update_type = %d\r\n"
                       ,"apupd_db_update_wtp_sub_image_action_request_confirm",0x24ac,
                       *(undefined4 *)(iVar9 + 0x7ec),*(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x54)
                      );
                iVar2 = *(int *)(iVar9 + 0x7ec);
              }
            }
            if (iVar2 == 1) {
              iVar2 = *(int *)(iVar1 + 0x34);
LAB_0065f428:
              iVar2 = FUN_004081b0(iVar2 + 0x30);
              while (iVar8 = iVar2, iVar8 != 0) {
                if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[APUPD_DEBUG]%32s() %05d: wtp_list->state = %d\r\n",
                         "apupd_db_update_wtp_sub_image_action_request_confirm",0x24b3,
                         *(undefined4 *)(iVar8 + 0x38));
                }
                local_2c = FUN_00408680(iVar8);
                if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[APUPD_DEBUG]%32s() %05d: APUPD_UPDATE_WTP_LIST_STATE_TYPE_SUB_SEND_FINISH\r\n"
                         ,"apupd_db_update_wtp_sub_image_action_request_confirm",0x24b6);
                }
                *(undefined4 *)(iVar8 + 0x38) = 8;
                apupd_import_software_num = apupd_import_software_num + -1;
                if (g_apupd_debug == 0) {
                  iVar4 = *(int *)(iVar8 + 0x48);
                }
                else {
                  iVar2 = is_target_debug_ap();
                  if (iVar2 == 0) {
                    iVar4 = *(int *)(iVar8 + 0x48);
                  }
                  else {
                    printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                           "apupd_db_update_wtp_sub_image_action_request_confirm",0x24b9,
                           apupd_import_software_num);
                    iVar4 = *(int *)(iVar8 + 0x48);
                  }
                }
                iVar2 = local_2c;
                if (iVar4 != 0) {
                  FUN_00407df0();
                  *(undefined4 *)(iVar8 + 0x48) = 0;
                  iVar2 = local_2c;
                }
              }
            }
            else {
              if (iVar2 == 3) {
                if (*(int *)(*(int *)(iVar1 + 0x30) + 0x54) == 1) {
                  iVar2 = *(int *)(iVar1 + 0x34);
                  goto LAB_0065f428;
                }
                uVar6 = *(undefined4 *)(iVar9 + 0x58);
              }
              else {
                uVar6 = *(undefined4 *)(iVar9 + 0x58);
              }
              *(undefined4 *)(iVar9 + 0x1a8) = 0;
              apupd_db_send_sub_action_to_update_wtp(uVar6,5,*(undefined1 *)(iVar9 + 0x1a0),0);
            }
          }
          if ((uint)param_2[1] == local_30 - 1U) {
            *(undefined4 *)(iVar1 + 0x20) = 3;
            *(undefined4 *)(iVar1 + 0x24) = 10;
            apupd_all_image_eof_send(local_2f8);
            bVar3 = *param_2;
          }
          else {
            bVar3 = *param_2;
          }
          goto LAB_0065ed00;
        }
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: AP[%d] sub check fail ,stop update\r\n",
                 "apupd_db_update_wtp_sub_image_action_request_confirm",0x2498,(uint)local_2f8);
        }
        *(undefined4 *)(iVar1 + 0x24) = 9;
        *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x48) = 0x19;
        apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
        iVar2 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar1 + 0x30),10);
        if ((((iVar2 == -1) || (iVar1 = apupd_update_wtp_entry_delete(iVar1), iVar1 == -1)) &&
            (g_apupd_error != 0)) && (iVar1 = is_target_debug_ap(local_2f8), iVar1 != 0)) {
          uVar6 = 0x249e;
LAB_0065f304:
          printf("[APUPD_ERROR]%32s() %05d: add log or del update wtp failed.\r\n",
                 "apupd_db_update_wtp_sub_image_action_request_confirm",uVar6);
        }
      }
      else {
        bVar3 = *param_2;
LAB_0065ed00:
        if (bVar3 != 3) {
          bVar3 = *param_2;
LAB_0065ed10:
          if (bVar3 == 5) {
            if (g_apupd_debug == 0) {
              iVar2 = *(int *)(iVar9 + 0x1a8);
            }
            else {
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                iVar2 = *(int *)(iVar9 + 0x1a8);
              }
              else {
                printf("[APUPD_DEBUG]%32s() %05d: AP[%d] return downloading image response\r\n",
                       "apupd_db_update_wtp_sub_image_action_request_confirm",0x2509,(uint)local_2f8
                      );
                iVar2 = *(int *)(iVar9 + 0x1a8);
              }
            }
            *(int *)(iVar9 + 0x1a8) = iVar2 + 1;
            if ((iVar2 + 1 == *(int *)(iVar9 + 0x144)) && (uVar11 < uVar10)) {
              if ((g_apupd_debug == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
                *(undefined1 *)(iVar9 + 0x1a1) = 1;
              }
              else {
                printf("[APUPD_DEBUG]%32s() %05d: set can_down_sub_image = %d\r\n",
                       "apupd_db_update_wtp_sub_image_action_request_confirm",0x250d,1);
                *(undefined1 *)(iVar9 + 0x1a1) = 1;
              }
            }
            *(undefined4 *)(iVar1 + 0x24) = 8;
            if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[APUPD_DEBUG]%32s() %05d: reply_num = %d, need_update = %d, total_image_size = %d, got_image_size = %d\r\n"
                     ,"apupd_db_update_wtp_sub_image_action_request_confirm",0x2511,
                     *(undefined4 *)(iVar9 + 0x1a8),*(undefined4 *)(iVar9 + 0x144),uVar10,uVar11);
            }
          }
          FUN_00407f30(apupd_db_mutex);
          return 0;
        }
        if (*(int *)(param_2 + 4) == 0) {
          *(undefined4 *)(iVar1 + 0x24) = 0xb;
          *(undefined4 *)(iVar1 + 0x20) = 4;
          iVar2 = apupd_sub_image_action_add(param_3,2,0xff,0);
          if (iVar2 == -1) {
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_0065f070;
            pcVar5 = "[APUPD_ERROR]%32s() %05d: apupd_sub_image_action_add failed.\r\n";
            uVar6 = 0x24e9;
          }
          else {
            __dest = (void *)FUN_00408450(6,0x24ed);
            if (__dest != (void *)0x0) {
              memcpy(__dest,param_1,6);
              if (*(int *)(iVar1 + 0x28) != -1) {
                FUN_00408060();
                *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
              }
              iVar2 = FUN_00408340(0x1a4,0,apupd_update_wtp_timer_callback,__dest,
                                   apupd_update_wtp_argv_callback,
                                   "apupd_db_update_wtp_sub_image_action_request_confirm",0x24fa);
              *(int *)(iVar1 + 0x28) = iVar2;
              if (iVar2 == -1) {
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  printf("[APUPD_ERROR]%32s() %05d: start update wtp timer failed.\r\n",
                         "apupd_db_update_wtp_sub_image_action_request_confirm",0x24fd);
                }
                FUN_00407df0(__dest);
                return 0xffffffff;
              }
              FUN_00407e70();
              *(undefined4 *)(iVar1 + 0x2c) = extraout_v1_00;
              *(int *)(iVar9 + 0x1a8) = *(int *)(iVar9 + 0x1a8) + 1;
              if (g_apupd_debug == 0) {
                bVar3 = *param_2;
              }
              else {
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  bVar3 = *param_2;
                }
                else {
                  printf("[APUPD_DEBUG]%32s() %05d: reply_num = %d, need_update = %d, total_image_size = %d, got_image_size = %d\r\n"
                         ,"apupd_db_update_wtp_sub_image_action_request_confirm",0x2503,
                         *(undefined4 *)(iVar9 + 0x1a8),*(undefined4 *)(iVar9 + 0x144),uVar10,uVar11
                        );
                  bVar3 = *param_2;
                }
              }
              goto LAB_0065ed10;
            }
            if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_0065f070;
            pcVar5 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
            uVar6 = 0x24ef;
          }
          goto LAB_0065f348;
        }
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: AP[%d] large check fail ,stop update\r\n",
                 "apupd_db_update_wtp_sub_image_action_request_confirm",0x24d8,(uint)local_2f8);
        }
        *(undefined4 *)(iVar1 + 0x24) = 0xc;
        *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x48) = 0x19;
        apupd_updating_wtp_num = apupd_updating_wtp_num + -1;
        iVar2 = apupd_wtp_log_entry_add(*(undefined4 *)(iVar1 + 0x30),10);
        if (((iVar2 == -1) || (iVar1 = apupd_update_wtp_entry_delete(iVar1), iVar1 == -1)) &&
           ((g_apupd_error != 0 && (iVar1 = is_target_debug_ap(local_2f8), iVar1 != 0)))) {
          uVar6 = 0x24de;
          goto LAB_0065f304;
        }
      }
      apmngr_db_ap_run_state_update(local_2f8,2);
      goto LAB_0065f070;
    }
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0065f070;
    uVar7 = *(undefined4 *)(iVar1 + 0x24);
    pcVar5 = "[APUPD_ERROR]%32s() %05d: update wtp large_image_update_state(%d) is invalib\r\n";
    uVar6 = 0x247f;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar1 + 0x24);
      goto LAB_0065eca8;
    }
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0065f070;
    uVar7 = *(undefined4 *)(iVar1 + 0x20);
    pcVar5 = "[APUPD_ERROR]%32s() %05d: update wtp state(%d) is invalib\r\n";
    uVar6 = 0x2478;
  }
  printf(pcVar5,"apupd_db_update_wtp_sub_image_action_request_confirm",uVar6,uVar7);
LAB_0065f070:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

