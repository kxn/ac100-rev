// func apmngr_global_config_set @ 0052b394 size=620

undefined4 apmngr_global_config_set(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  undefined2 local_28;
  undefined1 local_26;
  
  iVar3 = 7;
  local_28 = 0;
  local_26 = 0;
  if (param_1 == 0) {
LAB_0052b414:
    if (g_apmngr_reboot_timer != -1) {
      if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d stop timer for rebooting all ap.\n\n",
               "apmngr_global_config_set",0x321);
      }
      FUN_00408060(g_apmngr_reboot_timer);
      g_apmngr_reboot_timer = -1;
    }
    if (param_1 != 0) {
LAB_0052b4c4:
      if (g_apmngr_reboot_timer == -1) {
        uVar1 = _apmngr_tmo_caculate(0,iVar3,&local_28);
        g_apmngr_reboot_timer =
             FUN_00408340(uVar1,0,_apmngr_reboot_tmo_handle,0,0,"apmngr_global_config_set",0x32b);
        if (g_apmngr_reboot_timer == -1) {
          if (apmngr_err_switch == '\0') {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          __format = "[APMNGR_ERROR]%s()/%d Failed to start a timer to reboot all ap.\n";
          uVar1 = 0x32e;
          goto LAB_0052b590;
        }
        if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d start a timer waiting %ld seconds to timeout.\n",
                 "apmngr_global_config_set",0x331,uVar1);
        }
      }
    }
    uVar4 = 0;
    g_apmngr_reboot_time = local_28;
    DAT_007c582e = local_26;
    g_apmngr_reboot_date = iVar3;
    g_apmngr_auto_firm = param_2;
    g_apmngr_auto_reboot = param_1;
  }
  else {
    if ((param_3 != 0) && (param_4 != 0)) {
      iVar3 = apmngr_db_date_parse();
      apmngr_db_time_parse(param_4,&local_28);
      if ((iVar3 != g_apmngr_reboot_date) ||
         (iVar2 = memcmp(&local_28,&g_apmngr_reboot_time,3), iVar2 != 0)) goto LAB_0052b414;
      goto LAB_0052b4c4;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap(param_3);
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Input date_str or time_str invalid.\n";
    uVar1 = 0x313;
LAB_0052b590:
    uVar4 = 0xffffffff;
    printf(__format,"apmngr_global_config_set",uVar1);
  }
  return uVar4;
}

