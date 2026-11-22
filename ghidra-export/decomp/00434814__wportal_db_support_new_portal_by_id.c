// func _wportal_db_support_new_portal_by_id @ 00434814 size=196

uint _wportal_db_support_new_portal_by_id(undefined2 param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_2e8 [592];
  uint local_98;
  byte abStack_85 [121];
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    uVar2 = 0;
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d get ap entry by id failed.\n",
             "_wportal_db_support_new_portal_by_id",0x1d8c);
    }
  }
  else {
    uVar2 = 0;
    if ((local_98 & 4) != 0) {
      iVar1 = apmngr_db_get_sub_capability_idx(2);
      if (iVar1 != -1) {
        uVar2 = ((uint)abStack_85[iVar1 * 4] << 0x1e) >> 0x1f;
      }
    }
  }
  return uVar2;
}

