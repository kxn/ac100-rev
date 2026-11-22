// func cw_fsm_ac_timer_clear @ 0059ca38 size=252

undefined4 cw_fsm_ac_timer_clear(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_timer_clear",0xcb,"session");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    if (*(int *)(param_1 + 0xbc) != 0) {
      if (capwap_fsm_debug_switch == 0) {
        iVar2 = *(int *)(param_1 + 0xc);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0xc);
        }
        else {
          uVar1 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          if (*(uint *)(param_1 + 0xc4) < 0xc) {
            pcVar3 = (&PTR_s__TIMER_NONE__006e4ae8)[*(uint *)(param_1 + 0xc4)];
          }
          else {
            pcVar3 = "-INVALID_TIMER-";
          }
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] stop timer[%s], timer_id=%p\n",
                 "cw_fsm_ac_timer_clear",0xcf,param_1,uVar1,pcVar3,*(undefined4 *)(param_1 + 0xbc));
          iVar2 = *(int *)(param_1 + 0xc);
        }
      }
      cw_timer_remove(*(undefined4 *)(iVar2 + 0x44),*(undefined4 *)(param_1 + 0xbc));
      uVar1 = 0;
      *(undefined4 *)(param_1 + 0xbc) = 0;
      *(undefined4 *)(param_1 + 0xc0) = 0;
    }
  }
  return uVar1;
}

