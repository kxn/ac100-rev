// func apmngr_global_status_set @ 0052e6f4 size=228

undefined4 apmngr_global_status_set(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == g_apmngr_status) {
    return 0;
  }
  g_apmngr_status = param_1;
  if (param_1 != 0) {
    cw_ac_enable_packet_handler();
    if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d call cw_ac_max_session_num_revert().\n",
             "apmngr_global_status_set",0x2f5);
    }
    uVar1 = cw_ac_max_session_num_revert();
    return uVar1;
  }
  apmngr_reboot_all_ap(1,0);
  cw_ac_disable_packet_handler();
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d call cw_ac_max_session_num_clear().\n","apmngr_global_status_set",
           0x2fe);
  }
  uVar1 = cw_ac_max_session_num_clear();
  return uVar1;
}

