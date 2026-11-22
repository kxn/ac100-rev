// func wportal_cert_check @ 004159c8 size=224

void wportal_cert_check(void)

{
  int iVar1;
  
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d uac check, begin cert check...\n","wportal_cert_check",0x3134);
  }
  system("lua /usr/lib/lua/luci/model/check_cert.lua");
  cert_time_check_timer = FUN_00408340(0x15180,0,wportal_cert_check,0,0,"wportal_cert_check",0x3138)
  ;
  if (((cert_time_check_timer == -1) && (wportal_err_switch != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_ERR]%s()/%d add  cert_time_check_timer failed!\n","wportal_cert_check",0x313a);
    return;
  }
  return;
}

