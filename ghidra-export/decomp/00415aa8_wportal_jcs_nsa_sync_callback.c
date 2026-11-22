// func wportal_jcs_nsa_sync_callback @ 00415aa8 size=152

void wportal_jcs_nsa_sync_callback(void)

{
  int iVar1;
  
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d wportal_jcs_nsa_sync_callback() begin.\n",
           "wportal_jcs_nsa_sync_callback",0x25f3);
  }
  wportal_db_nsa_rbtree_sync();
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d wportal_jcs_nsa_sync_callback() success.\n",
           "wportal_jcs_nsa_sync_callback",0x25f5);
    return;
  }
  return;
}

