// func apupd_update_wtp_upd_list_clear_wtp @ 0064cfec size=696

undefined4 apupd_update_wtp_upd_list_clear_wtp(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if ((g_apupd_debug == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) {
    if (param_1 == 0) goto LAB_0064d12c;
    iVar5 = *(int *)(param_1 + 0x3c);
  }
  else {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_upd_list_clear_wtp start\r\n",
           "apupd_update_wtp_upd_list_clear_wtp",0x10a5);
    if (param_1 == 0) {
LAB_0064d12c:
      uVar4 = 0xffffffff;
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar3 = 0x10a9;
      goto LAB_0064d184;
    }
    iVar5 = *(int *)(param_1 + 0x3c);
  }
  iVar6 = *(int *)(iVar5 + 0x34);
  while (iVar5 != 0) {
    iVar1 = FUN_00408680(iVar5);
    *(undefined4 *)(*(int *)(iVar5 + 0x30) + 0x48) = param_2;
    iVar2 = apupd_update_wtp_entry_delete_only(iVar5);
    iVar5 = iVar1;
    if (((iVar2 == -1) && (g_apupd_error != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n",
             "apupd_update_wtp_upd_list_clear_wtp",0x10b5);
    }
  }
  if (*(int *)(param_1 + 0x3c) == 0) {
    if (*(int *)(param_1 + 0x38) < 3) {
      iVar5 = *(int *)(param_1 + 0x38);
    }
    else {
      apupd_import_software_num = apupd_import_software_num + -1;
      if (g_apupd_debug == 0) {
        iVar5 = *(int *)(param_1 + 0x38);
      }
      else {
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x38);
        }
        else {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                 "apupd_update_wtp_upd_list_clear_wtp",0x10bf,apupd_import_software_num);
          iVar5 = *(int *)(param_1 + 0x38);
        }
      }
    }
    if (iVar5 == 1) {
      apupd_get_version_num = apupd_get_version_num + -1;
      apupd_delete_info_in_uci(*(int *)(iVar6 + 0x10) + 0x119,param_1 + 0x18);
      iVar5 = *(int *)(param_1 + 0x38);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x38);
    }
    if ((iVar5 == 3) || (iVar5 == 9)) {
      apupd_download_software_num = apupd_download_software_num + -1;
      apupd_delete_info_in_uci(*(int *)(iVar6 + 0x10) + 0x119,param_1 + 0x18);
      iVar5 = *(int *)(param_1 + 0x48);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x48);
    }
    if (iVar5 == 0) {
      uVar4 = *(undefined4 *)(iVar6 + 0x2c);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x48) = 0;
      uVar4 = *(undefined4 *)(iVar6 + 0x2c);
    }
    FUN_00407f40(uVar4,param_1);
    FUN_00408500(param_1);
    FUN_00407df0(param_1);
  }
  uVar4 = 0;
  if (g_apupd_debug == 0) {
    return 0;
  }
  iVar5 = is_target_debug_ap();
  if (iVar5 == 0) {
    return 0;
  }
  __format = "[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_upd_list_clear_wtp end\r\n";
  uVar3 = 0x10d5;
LAB_0064d184:
  printf(__format,"apupd_update_wtp_upd_list_clear_wtp",uVar3);
  return uVar4;
}

