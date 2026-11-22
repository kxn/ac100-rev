// func cw_ac_max_session_num_clear @ 0058b04c size=180

undefined4 cw_ac_max_session_num_clear(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d new max session num: %d\n","cw_ac_max_session_num_clear",0x157,0);
  }
  if (l_profile == 0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d l_profile is NULL!\n","cw_ac_max_session_num_clear",0x15a);
    }
  }
  else {
    uVar2 = 0;
    *(undefined4 *)(l_profile + 0x140) = 0;
  }
  return uVar2;
}

