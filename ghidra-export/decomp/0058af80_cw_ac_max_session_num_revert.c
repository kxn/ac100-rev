// func cw_ac_max_session_num_revert @ 0058af80 size=204

undefined4 cw_ac_max_session_num_revert(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (l_profile == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d l_profile is NULL!\n";
    uVar2 = 0x169;
  }
  else {
    iVar1 = FUN_0051eb48("ac_capwap","max_session_num",l_profile + 0x140);
    if (iVar1 != -1) {
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d read profile failed.\n";
    uVar2 = 0x16f;
  }
  printf(__format,"cw_ac_max_session_num_revert",uVar2);
  return 0xffffffff;
}

