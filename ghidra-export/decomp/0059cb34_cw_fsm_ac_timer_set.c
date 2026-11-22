// func cw_fsm_ac_timer_set @ 0059cb34 size=612

undefined4 cw_fsm_ac_timer_set(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  param_3 = param_3 & 0xffff;
  if (param_1 == 0) {
    uVar4 = 0xffffffff;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_timer_set",0xdd,"session");
  }
  else if (param_2 - 1U < 10) {
    if (param_3 == 0) {
      param_3 = cw_fsm_ac_get_timer_timeout();
    }
    uVar4 = 0;
    if (param_2 != 10) {
      if (*(int *)(param_1 + 0xbc) != 0) {
        if ((capwap_fsm_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          uVar4 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          if (*(uint *)(param_1 + 0xc4) < 0xc) {
            pcVar3 = (&PTR_s__TIMER_NONE__006e4ae8)[*(uint *)(param_1 + 0xc4)];
          }
          else {
            pcVar3 = "-INVALID_TIMER-";
          }
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] stop previous timer[%s], timer_id=%p\n"
                 ,"cw_fsm_ac_timer_set",0xf0,param_1,uVar4,pcVar3,*(undefined4 *)(param_1 + 0xbc));
        }
        cw_fsm_ac_timer_clear(param_1);
      }
      uVar4 = 0;
      memset((void *)(param_1 + 0xc0),0,8);
      *(int *)(param_1 + 0xc4) = param_2;
      *(undefined4 *)(param_1 + 0xc0) = 5;
      if (0 < (int)param_3) {
        uVar1 = cw_timer_add(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x44),param_3,
                             cw_fsm_ac_timeout,param_1,0);
        *(undefined4 *)(param_1 + 0xbc) = uVar1;
        if ((capwap_fsm_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          uVar1 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          if (*(uint *)(param_1 + 0xc4) < 0xc) {
            pcVar3 = (&PTR_s__TIMER_NONE__006e4ae8)[*(uint *)(param_1 + 0xc4)];
          }
          else {
            pcVar3 = "-INVALID_TIMER-";
          }
          uVar4 = 0;
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] start timer[%s], timer_id=%p, timeout:%ds\n"
                 ,"cw_fsm_ac_timer_set",0xfe,param_1,uVar1,pcVar3,*(undefined4 *)(param_1 + 0xbc),
                 param_3);
        }
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((capwap_fsm_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      uVar1 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      printf("[FSM_ERROR]%31s():%4d | session[%p] state[%s] Invalid timer[%d]\n",
             "cw_fsm_ac_timer_set",0xe1,param_1,uVar1,param_2);
    }
  }
  return uVar4;
}

