// func cw_fsm_ac_idle @ 0059e7d0 size=1

undefined4 cw_fsm_ac_idle(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    uVar2 = 0x52;
    pcVar4 = "session";
  }
  else {
    if (param_2 != (int *)0x0) {
      if (capwap_fsm_debug_switch == 0) {
        iVar1 = *param_2;
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          iVar1 = *param_2;
        }
        else {
          uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar3 = cw_fsm_ac_get_event_name(*param_2);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] got event[%s]\n","cw_fsm_ac_idle",
                 0x55,param_1,uVar2,uVar3);
          iVar1 = *param_2;
        }
      }
      if (iVar1 == 7) {
        cw_fsm_ac_timer_set(param_1,1,0);
        uVar2 = 4;
      }
      else {
        if (iVar1 != 8) {
          if (capwap_fsm_debug_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar3 = cw_fsm_ac_get_event_name(*param_2);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] got invalid event[%s]\n",
                 "cw_fsm_ac_idle",0x65,param_1,uVar2,uVar3);
          return 0xffffffff;
        }
        cw_fsm_ac_timer_set(param_1,2,0);
        uVar2 = 6;
      }
      cw_fsm_ac_change_state(param_1,uVar2);
      return 0;
    }
    uVar2 = 0x53;
    pcVar4 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_idle",uVar2,pcVar4);
  return 0xffffffff;
}

