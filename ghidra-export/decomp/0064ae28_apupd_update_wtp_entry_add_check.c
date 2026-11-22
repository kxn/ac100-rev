// func apupd_update_wtp_entry_add_check @ 0064ae28 size=268

int apupd_update_wtp_entry_add_check(int param_1)

{
  int iVar1;
  int iVar2;
  int local_2f0 [2];
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  iVar2 = 0;
  memset(auStack_2e8,0,0x2d8);
  local_2f0[1] = 0;
  local_2f0[0] = 1;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x50) != 0)) {
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x134) == 0) {
      iVar2 = 1;
    }
    else {
      iVar1 = apmngr_db_entry_get_by_mac(param_1 + 0x2e,auStack_2e8);
      if (iVar1 == -1) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: get ap entry by mac failed.\r\n",
                 "apupd_update_wtp_entry_add_check",0x5d3);
        }
      }
      else {
        local_2f0[1] = 1;
        mesh_db_ap_entry_child_foreach_proc
                  (local_2d8,0,apupd_update_wtp_check_before_upgrade,local_2f0);
        iVar2 = local_2f0[0];
        if (local_2f0[0] != 0) {
          local_2f0[1] = 0;
          mesh_db_ap_entry_parent_foreach_proc
                    (local_2d8,0,apupd_update_wtp_check_before_upgrade,local_2f0);
          iVar2 = local_2f0[0];
        }
      }
    }
  }
  return iVar2;
}

