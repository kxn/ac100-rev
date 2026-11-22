// func stats_db_sample_time_changed_notify_register @ 006710c0 size=284

undefined4 stats_db_sample_time_changed_notify_register(void *param_1,uint param_2)

{
  int iVar1;
  void *__dest;
  uint uVar2;
  undefined4 uVar3;
  
  if ((param_1 == (void *)0x0) || (3 < param_2)) {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Input invalid.\n","stats_db_sample_time_changed_notify_register"
             ,0x1174);
    }
  }
  else {
    uVar3 = 0xffffffff;
    __dest = (void *)FUN_00408450(0x1c,0x1178);
    if (__dest != (void *)0x0) {
      memcpy(__dest,param_1,0x1c);
      iVar1 = FUN_004081b0(&g_sample_time_changed_callback_list + param_2 * 0xc);
      if (iVar1 == 0) {
LAB_006711a0:
        FUN_004086b0(&g_sample_time_changed_callback_list + param_2 * 0xc,__dest);
        uVar3 = 0;
      }
      else {
        uVar2 = *(uint *)(iVar1 + 0x10);
        while (*(uint *)((int)param_1 + 0x10) <= uVar2) {
          iVar1 = FUN_00408680();
          if (iVar1 == 0) goto LAB_006711a0;
          uVar2 = *(uint *)(iVar1 + 0x10);
        }
        FUN_00408170(iVar1,__dest);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

