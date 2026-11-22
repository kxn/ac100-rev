// func apupd_update_wtp_entry_delete_only @ 0064c520 size=336

undefined4 apupd_update_wtp_entry_delete_only(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00407f40(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x28) == -1) {
      iVar1 = *(int *)(param_1 + 0x38);
    }
    else {
      FUN_00408060();
      *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
      iVar1 = *(int *)(param_1 + 0x38);
    }
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        FUN_00407df0();
        *(undefined4 *)(*(int *)(param_1 + 0x38) + 4) = 0;
        apupd_import_software_num = apupd_import_software_num + -1;
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                 "apupd_update_wtp_entry_delete_only",0x50f,apupd_import_software_num);
        }
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x38));
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    FUN_00408500(param_1);
    uVar2 = 0;
    FUN_00408500(param_1 + 0xc);
    iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x50);
    *(int *)(iVar1 + 0x144) = *(int *)(iVar1 + 0x144) + -1;
    FUN_00407df0(param_1);
  }
  else {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: remove update wtp from hash failed.\r\n",
             "apupd_update_wtp_entry_delete_only",0x4fe);
    }
  }
  return uVar2;
}

