// func apupd_update_wtp_entry_list_add @ 0064cb84 size=364

undefined4 apupd_update_wtp_entry_list_add(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_update_wtp_entry_list_add\r\n",
           "apupd_update_wtp_entry_list_add",0x608);
  }
  iVar1 = FUN_004081b0(param_2 + 0x7f4);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = *(int *)(iVar1 + 0x48);
  do {
    if ((iVar2 == 1) && (iVar2 = apupd_update_wtp_entry_add_check(iVar1), iVar2 != 0)) {
      iVar2 = apupd_update_wtp_entry_add(param_1,iVar1);
      if (iVar2 == 0) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(param_1), iVar1 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: add update wtp failed.\r\n",
                 "apupd_update_wtp_entry_list_add",0x619);
        }
        iVar1 = apupd_update_wtp_entry_list_delete(param_1);
        if (iVar1 != -1) {
          return 0xffffffff;
        }
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        printf("[APUPD_ERROR]%32s() %05d: delete update wtp list failed.\r\n",
               "apupd_update_wtp_entry_list_add",0x61c);
        return 0xffffffff;
      }
      *(undefined4 *)(iVar1 + 0x48) = 2;
      apupd_update_wtp_entry_handle_after_add(iVar1);
    }
    iVar1 = FUN_00408680(iVar1);
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar1 + 0x48);
  } while( true );
}

