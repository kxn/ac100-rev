// func apupd_update_wtp_entry_list_delete @ 0064c814 size=596

undefined4 apupd_update_wtp_entry_list_delete(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  do {
    iVar1 = FUN_004081b0(param_1 + 0x30);
    if (iVar1 == 0) {
      do {
        iVar1 = FUN_004081b0(param_1 + 0x20);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = apupd_update_wtp_entry_delete_only(iVar1);
      } while (iVar1 != -1);
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        uVar3 = 0x57d;
LAB_0064c984:
        printf("[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n",
               "apupd_update_wtp_entry_list_delete",uVar3);
      }
      return 0xffffffff;
    }
    while (iVar2 = FUN_004081b0(iVar1 + 0xc), iVar2 != 0) {
      iVar2 = apupd_update_wtp_entry_delete_only(iVar2);
      if (iVar2 == -1) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        uVar3 = 0x559;
        goto LAB_0064c984;
      }
    }
    if (*(int *)(iVar1 + 0x38) < 3) {
      iVar2 = *(int *)(iVar1 + 0x38);
    }
    else {
      if (apupd_import_software_num != 0) {
        apupd_import_software_num = apupd_import_software_num + -1;
      }
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
                 "apupd_update_wtp_entry_list_delete",0x563,apupd_import_software_num);
          iVar2 = *(int *)(iVar1 + 0x38);
        }
      }
    }
    if (iVar2 == 1) {
      apupd_get_version_num = apupd_get_version_num + -1;
      apupd_delete_info_in_uci(*(int *)(param_1 + 0x10) + 0x119,iVar1 + 0x18);
      iVar2 = *(int *)(iVar1 + 0x38);
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x38);
    }
    if ((iVar2 == 3) || (iVar2 == 9)) {
      apupd_download_software_num = apupd_download_software_num + -1;
      apupd_delete_info_in_uci(*(int *)(param_1 + 0x10) + 0x119,iVar1 + 0x18);
      iVar2 = *(int *)(iVar1 + 0x48);
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x48);
    }
    if (iVar2 == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x2c);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 0x48) = 0;
      uVar3 = *(undefined4 *)(param_1 + 0x2c);
    }
    FUN_00407f40(uVar3,iVar1);
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  } while( true );
}

