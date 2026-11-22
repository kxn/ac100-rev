// func wportal_db_nsa_rbtree_sync @ 00434998 size=76

void wportal_db_nsa_rbtree_sync(void)

{
  int iVar1;
  
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d no support sync\n","wportal_db_nsa_rbtree_sync",0x1e88);
    return;
  }
  return;
}

