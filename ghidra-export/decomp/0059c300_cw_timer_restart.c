// func cw_timer_restart @ 0059c300 size=1

undefined4 cw_timer_restart(int param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if (capwap_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d The cw_timer or timer node is NULL\n","cw_timer_restart",0xca);
      return 0xffffffff;
    }
  }
  else {
    if ((*(int *)(param_2 + 0x18) <= *(int *)(param_1 + 4)) && (0 < *(int *)(param_2 + 0x18))) {
      lVar2 = FUN_00524078();
      *(longlong *)(param_2 + 0x10) = lVar2 + *(int *)(param_2 + 0x18) * 1000000;
      FUN_00408500(param_2);
      FUN_004086b0(*(int *)(param_1 + 0x10) + (*(int *)(param_2 + 0x18) + -1) * 0xc,param_2);
      return 0;
    }
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d timer\'s time(%d) is illegal\n","cw_timer_restart",0xcf,
             *(undefined4 *)(param_2 + 0x18));
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

