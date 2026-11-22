// func apupd_wtp_entry_delete @ 0065a890 size=608

undefined4 apupd_wtp_entry_delete(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_1 + 0x48) == 7) {
    uVar5 = 0;
    if (g_apupd_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar3 = "[APUPD_DEBUG]%32s() %05d: don\'t delete wtp, delete it by timer\r\n";
    uVar4 = 0x8c9;
    goto LAB_0065a9b8;
  }
  iVar1 = apupd_wtp_entry_delete_before_handle();
  if (iVar1 == -1) {
    uVar5 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: handle wtp before deleting failed.\r\n";
    uVar4 = 0x8d0;
    goto LAB_0065a9b8;
  }
  iVar1 = FUN_00407fa0(apupd_model_hash,param_1 + 0x34);
  if (iVar1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar3 = "[APUPD_ERROR]%32s() %05d: tmp_model get failed.\r\n";
      uVar5 = 0x8e4;
LAB_0065a9fc:
      printf(pcVar3,"apupd_wtp_entry_delete",uVar5);
    }
  }
  else {
    iVar2 = FUN_00407fa0(apupd_hwid_hash,iVar1 + 0x119);
    if (iVar2 == 0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar3 = "[APUPD_ERROR]%32s() %05d: tmp_hw_fw_node get failed.\r\n";
        uVar5 = 0x8df;
        goto LAB_0065a9fc;
      }
    }
    else {
      apupd_update_hw_fw_info(param_1,0,iVar1,0);
    }
  }
  iVar1 = FUN_00407f40(apupd_wtp_hash,param_1);
  if (iVar1 == 0) {
    FUN_00408500(param_1);
    FUN_00408500(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x50) = 0;
    if (*(int *)(param_1 + 0x8c) != 0) {
      if (*(int *)(*(int *)(param_1 + 0x8c) + 4) != 0) {
        FUN_00407df0();
        *(undefined4 *)(*(int *)(param_1 + 0x8c) + 4) = 0;
        apupd_import_software_num = apupd_import_software_num + -1;
        if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_DEBUG]%32s() %05d: apupd_import_software_num = %d\r\n",
                 "apupd_wtp_entry_delete",0x8f7,apupd_import_software_num);
        }
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x8c));
      *(undefined4 *)(param_1 + 0x8c) = 0;
    }
    FUN_00407df0(param_1);
    return 0;
  }
  uVar5 = 0xffffffff;
  if (g_apupd_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar3 = "[APUPD_ERROR]%32s() %05d: remove wtp from hash failed.\r\n";
  uVar4 = 0x8ea;
LAB_0065a9b8:
  printf(pcVar3,"apupd_wtp_entry_delete",uVar4);
  return uVar5;
}

