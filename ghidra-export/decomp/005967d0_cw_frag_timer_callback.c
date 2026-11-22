// func cw_frag_timer_callback @ 005967d0 size=144

void cw_frag_timer_callback(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_frag_timer_callback",0xcd,"NULL != session")
    ;
    return;
  }
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(param_1), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d frag timer expired, start free frag session\n",
           "cw_frag_timer_callback",0xce);
  }
  cw_frag_mngr_frag_free(param_1);
  return;
}

