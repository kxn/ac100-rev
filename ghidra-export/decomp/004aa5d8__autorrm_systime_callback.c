// func _autorrm_systime_callback @ 004aa5d8 size=316

undefined4 _autorrm_systime_callback(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (g_autorrm_enable != 0) {
    if (g_autorrm_timer != -1) {
      if (rrm_debug_switch != '\0') {
        printf("[RRM_DEBUG]%s()/%d stop timer for rrm.\n\n","_autorrm_systime_callback",0xa4d);
      }
      FUN_00408060(g_autorrm_timer);
      g_autorrm_timer = -1;
    }
    uVar1 = _autorrm_tmo_caculate(0,g_autorrm_date,&g_autorrm_time);
    g_autorrm_timer =
         FUN_00408340(uVar1,0,_autorrm_tmo_handle,0,0,"_autorrm_systime_callback",0xa54);
    if (g_autorrm_timer == -1) {
      uVar2 = 0xffffffff;
      if (rrm_err_switch != '\0') {
        printf("[RRM_ERROR]%s()/%d Failed to start a timer to rrm.\n","_autorrm_systime_callback",
               0xa57);
      }
    }
    else {
      uVar2 = 0;
      if (rrm_debug_switch != '\0') {
        printf("[RRM_DEBUG]%s()/%d start a timer waiting %ld seconds to timeout.\n",
               "_autorrm_systime_callback",0xa5b,uVar1);
      }
    }
  }
  return uVar2;
}

