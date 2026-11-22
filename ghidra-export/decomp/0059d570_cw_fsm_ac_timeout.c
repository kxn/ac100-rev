// func cw_fsm_ac_timeout @ 0059d570 size=184

void cw_fsm_ac_timeout(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    if ((capwap_fsm_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] timeout timer[%d/%p]\n",
             "cw_fsm_ac_timeout",0xc5,param_1,uVar2,*(undefined4 *)(param_1 + 0xc0),
             *(undefined4 *)(param_1 + 0xbc));
    }
    *(undefined4 *)(param_1 + 0xbc) = 0;
    cw_fsm_ac_process_event(param_1,param_1 + 0xc0);
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_timeout",0xc3,"session");
  return;
}

