// func _apmngr_systime_callback @ 0052a25c size=384

undefined4 _apmngr_systime_callback(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (g_apmngr_auto_reboot != 0) {
    if (g_apmngr_reboot_timer != -1) {
      if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d stop timer for rebooting all ap.\n\n",
               "_apmngr_systime_callback",0xcbf);
      }
      FUN_00408060(g_apmngr_reboot_timer);
      g_apmngr_reboot_timer = -1;
    }
    uVar1 = _apmngr_tmo_caculate(0,g_apmngr_reboot_date,&g_apmngr_reboot_time);
    g_apmngr_reboot_timer =
         FUN_00408340(uVar1,0,_apmngr_reboot_tmo_handle,0,0,"_apmngr_systime_callback",0xcc6);
    if (g_apmngr_reboot_timer == -1) {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      printf("[APMNGR_ERROR]%s()/%d Failed to start a timer to reboot all ap.\n",
             "_apmngr_systime_callback",0xcc9);
      return 0xffffffff;
    }
    if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d start a timer waiting %ld seconds to timeout.\n",
             "_apmngr_systime_callback",0xccd,uVar1);
    }
  }
  apmngr_db_foreach_proc(0x15f0000,_apmngr_systime_led_timer_callback,0);
  return 0;
}

