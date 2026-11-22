// func apupd_update_wtp_entry_handle_after_add @ 0064af34 size=192

void apupd_update_wtp_entry_handle_after_add(int param_1)

{
  int iVar1;
  undefined1 auStack_2e0 [16];
  undefined2 local_2d0;
  
  memset(auStack_2e0,0,0x2d8);
  if ((param_1 != 0) && (*(int *)(param_1 + 0x50) != 0)) {
    iVar1 = apmngr_db_entry_get_by_mac(param_1 + 0x2e,auStack_2e0);
    if (iVar1 == -1) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: get ap entry by mac failed.\r\n",
               "apupd_update_wtp_entry_handle_after_add",0x5ea);
      }
    }
    else if (*(int *)(*(int *)(param_1 + 0x50) + 0x134) != 0) {
      mesh_db_ap_entry_parent_foreach_proc(local_2d0,0,apupd_update_parent_wtp_remove,0);
    }
  }
  return;
}

