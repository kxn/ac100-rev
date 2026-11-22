// func _wportal_apmngr_callback_wtp_join @ 00415908 size=192

undefined4 _wportal_apmngr_callback_wtp_join(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (wportal_debug_switch == 0) {
    uVar1 = *(uint *)(param_1 + 600);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      uVar1 = *(uint *)(param_1 + 600);
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d _wportal_apmngr_callback_wtp_join start\n",
             "_wportal_apmngr_callback_wtp_join",0x2adc);
      uVar1 = *(uint *)(param_1 + 600);
    }
  }
  if ((uVar1 & 0x1000) != 0) {
    system("[ ! -f /var/run/nginx.pid ] && /etc/init.d/nginx restart");
  }
  if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d _wportal_apmngr_callback_wtp_join end\n",
           "_wportal_apmngr_callback_wtp_join",0x2ae1);
  }
  return 0;
}

