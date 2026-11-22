// func apmngr_db_first_ap_get @ 005389d8 size=1

undefined4 apmngr_db_first_ap_get(void *param_1)

{
  int iVar1;
  void *__src;
  
  if (param_1 == (void *)0x0) {
    if (apmngr_err_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[APMNGR_ERROR]%s()/%d ap_entry_d is null.\n","apmngr_db_first_ap_get",0x58c);
      return 0xffffffff;
    }
  }
  else {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    for (iVar1 = FUN_004081b0(&g_apmngr_group_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      __src = (void *)FUN_004081b0(iVar1 + 0x78);
      if (__src != (void *)0x0) {
        memcpy(param_1,__src,0x2d8);
        FUN_00407f30(apmngr_db_mutex);
        return 0;
      }
    }
    FUN_00407f30(apmngr_db_mutex);
  }
  return 0xffffffff;
}

