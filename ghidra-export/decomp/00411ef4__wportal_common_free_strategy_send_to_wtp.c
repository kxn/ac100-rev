// func _wportal_common_free_strategy_send_to_wtp @ 00411ef4 size=636

undefined4 _wportal_common_free_strategy_send_to_wtp(int param_1,int param_2,int param_3)

{
  undefined4 *__s;
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  size_t __n;
  int local_30;
  int local_2c;
  undefined4 *local_28;
  
  uVar3 = 0xffffffff;
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    if (param_3 == 1) {
      __n = g_max_free_strategy * 0x9c + 0x1398;
    }
    else {
      __n = 0;
      if (param_3 == 2) {
        if (param_2 == 0) {
          return 0xffffffff;
        }
        __n = g_max_free_strategy * 0xa8 + 0x1518;
      }
    }
    if ((wportal_info_switch != 0) && (iVar4 = is_target_debug_ap(param_1,0x1864), iVar4 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Create WPORTAL_AP_EVENT_BUILD_CAPWAP buffer len: %d\n",
             "_wportal_common_free_strategy_send_to_wtp",0x1862,__n);
    }
    __s = (undefined4 *)FUN_00408450(__n,0x1864);
    if (__s == (undefined4 *)0x0) {
      uVar3 = 0xffffffff;
      if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d Malloc buffer error\n",
               "_wportal_common_free_strategy_send_to_wtp",0x1867);
      }
    }
    else {
      memset(__s,0,__n);
      if (param_3 == 1) {
        *__s = 6;
      }
      else if (param_3 == 2) {
        *__s = 0x11;
      }
      local_28 = __s + 6;
      __s[3] = 0;
      local_2c = 0;
      if (param_2 == 0) {
        pcVar2 = _wportal_common_free_strategy_traverse_old_func;
      }
      else {
        pcVar2 = _wportal_common_free_strategy_traverse_func;
      }
      local_30 = param_3;
      wportal_db_ftt_traverse(pcVar2,&local_30);
      if (param_3 == 1) {
        iVar4 = 0x9c;
      }
      else {
        iVar4 = 0xa8;
      }
      iVar4 = iVar4 * local_2c;
      __s[5] = local_2c;
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Portal count: %d, free strategy count: %d\n",
               "_wportal_common_free_strategy_send_to_wtp",0x188b,__s[3],__s[5]);
      }
      iVar4 = _wportal_update_to_ap(__s,iVar4 + 0x18,param_1,1);
      if (((iVar4 != 0) && (wportal_debug_switch != 0)) &&
         (iVar4 = is_target_debug_ap(__s), iVar4 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Update to ap error\n",
               "_wportal_common_free_strategy_send_to_wtp",0x1892);
      }
      uVar3 = 0;
      FUN_00407df0(__s);
    }
  }
  return uVar3;
}

