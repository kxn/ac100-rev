// func apupd_systime_callback_models_timer_restart @ 00645204 size=112

undefined4 apupd_systime_callback_models_timer_restart(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = apupd_db_system_time_change_confirm();
  if (((iVar1 == -1) && (uVar2 = 0xffffffff, g_apupd_error != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: restart models timer failed.\r\n",
           "apupd_systime_callback_models_timer_restart",0x125c);
  }
  return uVar2;
}

