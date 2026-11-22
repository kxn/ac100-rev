// func apmngr_callback_register @ 0052aaec size=248

undefined4 apmngr_callback_register(void *param_1)

{
  void *__dest;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == (void *)0x0) {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Input invalid.\n","apmngr_callback_register",0xe9);
    }
  }
  else {
    uVar3 = 0xffffffff;
    __dest = (void *)FUN_00408450(0x4c,0xed);
    if (__dest != (void *)0x0) {
      memcpy(__dest,param_1,0x4c);
      iVar1 = FUN_004081b0(&g_apmngr_callback_list);
      if (iVar1 == 0) {
LAB_0052ab6c:
        uVar3 = 0;
        FUN_004086b0(&g_apmngr_callback_list,__dest);
      }
      else {
        uVar2 = *(uint *)(iVar1 + 0x10);
        while (*(uint *)((int)param_1 + 0x10) <= uVar2) {
          iVar1 = FUN_00408680();
          if (iVar1 == 0) goto LAB_0052ab6c;
          uVar2 = *(uint *)(iVar1 + 0x10);
        }
        FUN_00408170(iVar1,__dest);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

