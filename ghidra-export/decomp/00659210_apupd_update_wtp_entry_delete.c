// func apupd_update_wtp_entry_delete @ 00659210 size=1844

undefined4 apupd_update_wtp_entry_delete(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: delete update wtp.mac[%02X-%02X-%02X-%02X-%02X-%02X]\r\n",
           "apupd_update_wtp_entry_delete",0x43b,(uint)*(byte *)(param_1 + 0x18),
           (uint)*(byte *)(param_1 + 0x19),(uint)*(byte *)(param_1 + 0x1a),
           (uint)*(byte *)(param_1 + 0x1b),(uint)*(byte *)(param_1 + 0x1c),
           (uint)*(byte *)(param_1 + 0x1d));
  }
  iVar1 = FUN_00407f40(apupd_update_wtp_hash,param_1);
  if (iVar1 != 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: remove update wtp from hash failed.\r\n",
           "apupd_update_wtp_entry_delete",0x445);
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x28) == -1) {
    iVar1 = *(int *)(param_1 + 0x30);
  }
  else {
    FUN_00408060();
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
    iVar1 = *(int *)(param_1 + 0x30);
  }
  if (*(int *)(iVar1 + 0x54) == 1) {
    iVar1 = FUN_00407fa0(*(undefined4 *)(*(int *)(param_1 + 0x34) + 0x2c),iVar1 + 0x58);
    if (iVar1 == 0) goto LAB_006592fc;
    if ((*(int *)(iVar1 + 0x3c) != 0) &&
       (iVar2 = memcmp((void *)(*(int *)(iVar1 + 0x3c) + 0x18),(void *)(param_1 + 0x18),6),
       iVar2 == 0)) {
      uVar3 = FUN_00408680(param_1);
      *(undefined4 *)(iVar1 + 0x3c) = uVar3;
    }
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: is online. delete update wtp.\r\n",
             "apupd_update_wtp_entry_delete",0x458);
    }
    FUN_00408500(param_1);
    FUN_00408500(param_1 + 0xc);
    iVar2 = FUN_00407fe0(iVar1 + 0xc);
    if (iVar2 == 0) {
      if (*(int *)(iVar1 + 0x38) < 3) {
        iVar2 = *(int *)(iVar1 + 0x38);
      }
      else {
        apupd_import_software_num = apupd_import_software_num + -1;
        if (g_apupd_debug == 0) {
          iVar2 = *(int *)(iVar1 + 0x38);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            iVar2 = *(int *)(iVar1 + 0x38);
          }
          else {
            printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                   "apupd_update_wtp_entry_delete",0x461,apupd_import_software_num);
            iVar2 = *(int *)(iVar1 + 0x38);
          }
        }
      }
      if (iVar2 == 1) {
        apupd_get_version_num = apupd_get_version_num + -1;
        apupd_delete_info_in_uci(*(int *)(*(int *)(param_1 + 0x30) + 0x50) + 0x119,iVar1 + 0x18);
        iVar2 = *(int *)(iVar1 + 0x38);
      }
      else {
        iVar2 = *(int *)(iVar1 + 0x38);
      }
      if ((iVar2 == 3) || (iVar2 == 9)) {
        apupd_download_software_num = apupd_download_software_num + -1;
        apupd_delete_info_in_uci(*(int *)(*(int *)(param_1 + 0x30) + 0x50) + 0x119,iVar1 + 0x18);
      }
      FUN_00408500(iVar1);
      FUN_00407f40(*(undefined4 *)(*(int *)(param_1 + 0x34) + 0x2c),iVar1);
      if (*(int *)(iVar1 + 0x48) != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 0x48) = 0;
      }
      FUN_00407df0(iVar1);
      iVar1 = 0;
      goto LAB_006592fc;
    }
    iVar2 = *(int *)(param_1 + 0x38);
  }
  else {
    if (g_apupd_debug == 0) {
      iVar1 = *(int *)(param_1 + 0x34);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 0x34);
      }
      else {
        printf("[APUPD_DEBUG]%32s() %05d: is manual. delete update wtp.\r\n",
               "apupd_update_wtp_entry_delete",0x47b);
        iVar1 = *(int *)(param_1 + 0x34);
      }
    }
    if (param_1 == *(int *)(iVar1 + 0x3c)) {
      uVar3 = FUN_00408680(param_1);
      *(undefined4 *)(iVar1 + 0x3c) = uVar3;
    }
    FUN_00408500(param_1);
    FUN_00408500(param_1 + 0xc);
    iVar1 = 0;
LAB_006592fc:
    iVar2 = *(int *)(param_1 + 0x38);
  }
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x30);
  }
  else {
    if (*(int *)(iVar2 + 4) != 0) {
      FUN_00407df0();
      *(undefined4 *)(*(int *)(param_1 + 0x38) + 4) = 0;
      apupd_import_software_num = apupd_import_software_num + -1;
      if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
               "apupd_update_wtp_entry_delete",0x48b,apupd_import_software_num);
      }
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
    iVar2 = *(int *)(param_1 + 0x30);
  }
  *(int *)(*(int *)(iVar2 + 0x50) + 0x144) = *(int *)(*(int *)(iVar2 + 0x50) + 0x144) + -1;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x4c) = 0;
  if (*(char *)(*(int *)(*(int *)(param_1 + 0x34) + 0x10) + 0x13a) != '\x01') goto LAB_0065937c;
  iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x50);
  if ((*(int *)(iVar2 + 0x144) == 0) && (*(int *)(iVar2 + 0x148) != 0)) {
    *(int *)(iVar2 + 0x144) = *(int *)(iVar2 + 0x148);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x30) + 0x50) + 0x148) = 0;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x30) + 0x50) + 0x1a8) = 0;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x30) + 0x50) + 0x1a4) = 0;
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x30) + 0x50) + 0x1a0) = 0;
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x30) + 0x50) + 0x1a1) = 3;
  }
  if (g_apupd_debug == 0) {
    iVar2 = *(int *)(param_1 + 0x34);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x34);
    }
    else {
      printf("[APUPD_DEBUG]%32s() %05d: update wtp state = %d, large_image_update_state = %d\r\n",
             "apupd_update_wtp_entry_delete",0x49f,*(undefined4 *)(param_1 + 0x20),
             *(undefined4 *)(param_1 + 0x24));
      iVar2 = *(int *)(param_1 + 0x34);
    }
  }
  iVar5 = *(int *)(iVar2 + 0x10);
  if (*(int *)(iVar5 + 0x7ec) == 1) {
    iVar1 = *(int *)(param_1 + 0x30);
LAB_006596b8:
    iVar1 = FUN_00407fa0(*(undefined4 *)(iVar2 + 0x2c),iVar1 + 0x58);
    if (iVar1 == 0) {
      uVar7 = 0;
      uVar6 = 0;
    }
    else {
      uVar6 = *(uint *)(iVar1 + 0x178);
      uVar7 = *(uint *)(iVar1 + 0x194);
    }
  }
  else {
    if (*(int *)(iVar5 + 0x7ec) == 3) {
      if (*(int *)(*(int *)(param_1 + 0x30) + 0x54) == 1) {
        iVar1 = *(int *)(param_1 + 0x30);
        goto LAB_006596b8;
      }
      uVar6 = *(uint *)(iVar5 + 0x188);
    }
    else {
      uVar6 = *(uint *)(iVar5 + 0x188);
    }
    uVar7 = *(uint *)(iVar5 + 0x1a4);
  }
  if (g_apupd_debug == 0) {
    iVar2 = *(int *)(iVar5 + 0x144);
  }
  else {
    iVar4 = is_target_debug_ap();
    iVar2 = *(int *)(iVar5 + 0x144);
    if (iVar4 != 0) {
      printf("[APUPD_DEBUG]%32s() %05d: reply_num = %d, need_update = %d, total_image_size = %d, got_image_size = %d\r\n"
             ,"apupd_update_wtp_entry_delete",0x4b0,*(undefined4 *)(iVar5 + 0x1a8),iVar2,uVar6,uVar7
            );
      iVar2 = *(int *)(iVar5 + 0x144);
    }
  }
  if (iVar2 != 0) {
    if ((*(int *)(iVar5 + 0x1a8) != iVar2) || (uVar6 <= uVar7)) goto LAB_0065937c;
    if (*(int *)(iVar5 + 0x7ec) == 1) {
LAB_00659894:
      if (iVar1 != 0) {
        if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: APUPD_UPDATE_WTP_LIST_STATE_TYPE_SUB_SEND_FINISH\r\n",
                 "apupd_update_wtp_entry_delete",0x4c7);
        }
        *(undefined4 *)(iVar1 + 0x38) = 8;
        apupd_import_software_num = apupd_import_software_num + -1;
        if (g_apupd_debug == 0) {
          iVar2 = *(int *)(iVar1 + 0x48);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            iVar2 = *(int *)(iVar1 + 0x48);
          }
          else {
            printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                   "apupd_update_wtp_entry_delete",0x4ca,apupd_import_software_num);
            iVar2 = *(int *)(iVar1 + 0x48);
          }
        }
        if (iVar2 != 0) {
          FUN_00407df0();
          *(undefined4 *)(iVar1 + 0x48) = 0;
        }
      }
    }
    else {
      if (*(int *)(iVar5 + 0x7ec) == 3) {
        if (*(int *)(*(int *)(param_1 + 0x30) + 0x54) == 1) goto LAB_00659894;
        uVar3 = *(undefined4 *)(iVar5 + 0x58);
      }
      else {
        uVar3 = *(undefined4 *)(iVar5 + 0x58);
      }
      *(undefined4 *)(iVar5 + 0x1a8) = 0;
      apupd_db_send_sub_action_to_update_wtp(uVar3,5,*(undefined1 *)(iVar5 + 0x1a0),0);
    }
    goto LAB_0065937c;
  }
  if (*(int *)(iVar5 + 0x1b0) == 0) {
LAB_006595b0:
    *(undefined4 *)(iVar5 + 0x1a8) = 0;
  }
  else {
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: free image memory\r\n","apupd_update_wtp_entry_delete",0x4b5
            );
    }
    FUN_00407df0(*(undefined4 *)(iVar5 + 0x1b0));
    *(undefined4 *)(iVar5 + 0x1b0) = 0;
    apupd_import_software_num = apupd_import_software_num + -1;
    *(undefined1 *)(iVar5 + 0x1a1) = 2;
    if (g_apupd_debug == 0) goto LAB_006595b0;
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      *(undefined4 *)(iVar5 + 0x1a8) = 0;
    }
    else {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
             "apupd_update_wtp_entry_delete",0x4ba,apupd_import_software_num);
      *(undefined4 *)(iVar5 + 0x1a8) = 0;
    }
  }
  *(undefined4 *)(iVar5 + 0x1a4) = 0;
  *(undefined1 *)(iVar5 + 0x1a0) = 0;
LAB_0065937c:
  FUN_00407df0(param_1);
  return 0;
}

