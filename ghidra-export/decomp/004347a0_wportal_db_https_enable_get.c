// func wportal_db_https_enable_get @ 004347a0 size=116

undefined4 wportal_db_https_enable_get(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Input error\n","wportal_db_https_enable_get",0x1d7d);
    }
  }
  else {
    uVar2 = 0;
    *param_1 = g_https_enable;
  }
  return uVar2;
}

