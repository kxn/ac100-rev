// func cw_frag_timer_arg_free_callback @ 005966e0 size=76

void cw_frag_timer_arg_free_callback(void)

{
  int iVar1;
  
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d free timer arg\n","cw_frag_timer_arg_free_callback",0xdd);
    return;
  }
  return;
}

