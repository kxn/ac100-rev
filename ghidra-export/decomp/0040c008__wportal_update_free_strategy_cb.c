// func _wportal_update_free_strategy_cb @ 0040c008 size=480

undefined4 _wportal_update_free_strategy_cb(undefined4 param_1,undefined4 *param_2)

{
  void *__s;
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  __s = (void *)FUN_00408450(0x14,0x395);
  if (__s == (void *)0x0) {
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_free_strategy_cb",0x398
            );
    }
  }
  else {
    memset(__s,0,0x14);
    *(undefined4 *)((int)__s + 0xc) = 2;
    pvVar1 = (void *)FUN_00408450(0x10,0x39e);
    *(void **)((int)__s + 0x10) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_free_strategy_cb",
               0x3a1);
      }
    }
    else {
      memset(pvVar1,0,0x10);
      puVar3 = *(undefined4 **)((int)__s + 0x10);
      *puVar3 = param_1;
      memcpy(puVar3 + 1,param_2,0xc);
      puVar3[1] = 0;
      pvVar1 = (void *)FUN_00408450(0x144,0x3ad);
      puVar3[1] = pvVar1;
      if (pvVar1 != (void *)0x0) {
        memcpy(pvVar1,(void *)*param_2,0x144);
        FUN_004082d0(wportal_update_rdt_ftt_mutex,0xffffffff);
        FUN_004086b0(&g_wportal_update_rdt_ftt_list,__s);
        FUN_004084b0(wportal_update_rdt_ftt_cond);
        FUN_00407f30(wportal_update_rdt_ftt_mutex);
        return 1;
      }
      if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d Malloc memory failed!\n","_wportal_update_free_strategy_cb",
               0x3b0);
      }
      FUN_00407df0(puVar3);
    }
    FUN_00407df0(__s);
  }
  return 0xffffffff;
}

