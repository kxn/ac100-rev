// func stats_db_bssid_changed_notify_register @ 006711dc size=248

undefined4 stats_db_bssid_changed_notify_register(void *param_1)

{
  void *__dest;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == (void *)0x0) {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Input invalid.\n","stats_db_bssid_changed_notify_register",
             0x119d);
    }
  }
  else {
    uVar3 = 0xffffffff;
    __dest = (void *)FUN_00408450(0x20,0x11a1);
    if (__dest != (void *)0x0) {
      memcpy(__dest,param_1,0x20);
      iVar1 = FUN_004081b0(&g_bssid_changed_callback_list);
      if (iVar1 == 0) {
LAB_0067125c:
        uVar3 = 0;
        FUN_004086b0(&g_bssid_changed_callback_list,__dest);
      }
      else {
        uVar2 = *(uint *)(iVar1 + 0x10);
        while (*(uint *)((int)param_1 + 0x10) <= uVar2) {
          iVar1 = FUN_00408680();
          if (iVar1 == 0) goto LAB_0067125c;
          uVar2 = *(uint *)(iVar1 + 0x10);
        }
        FUN_00408170(iVar1,__dest);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

