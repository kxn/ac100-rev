// func cw_fsm_ac_configure_recv_pkt @ 0059d6e0 size=568

undefined4 cw_fsm_ac_configure_recv_pkt(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 == 0) {
    uVar4 = 0x6e;
    pcVar5 = "session";
  }
  else {
    if (param_2 != (int *)0x0) {
      iVar6 = param_2[1];
      if (*param_2 != 3) {
        if ((capwap_fsm_debug_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          uVar4 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] packet checked failed\n",
                 "cw_fsm_ac_configure_recv_pkt",0x94,param_1,uVar4);
        }
        cw_fsm_ac_timer_clear(param_1);
        cw_fsm_ac_enter_reset(param_1,1);
        cw_fsm_ac_session_delete(param_1);
        return 0;
      }
      if (iVar6 == 0xb) {
        if ((capwap_fsm_debug_switch != 0) &&
           (iVar6 = is_target_debug_ap("et file[%s] fail!\n",9), iVar6 != 0)) {
          uVar4 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar2 = cw_fsm_ac_get_event_name(*param_2);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is CHANGE_STATE_EVENT_REQUEST\n"
                 ,"cw_fsm_ac_configure_recv_pkt",0x77,param_1,uVar4,uVar2);
        }
        cw_fsm_ac_timer_set(param_1,9,0);
        cw_fsm_ac_enter_run(param_1);
        *(int *)(*(int *)(param_1 + 0xc) + 0x60) = *(int *)(*(int *)(param_1 + 0xc) + 0x60) + 1;
        cw_fsm_ac_change_state(param_1,0xd);
        return 0;
      }
      if (iVar6 == 5) {
        return 0;
      }
      if (capwap_fsm_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      uVar4 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      uVar2 = cw_fsm_ac_get_event_name(*param_2);
      uVar3 = cw_control_msg_name(iVar6);
      printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] invalid message %s\n",
             "cw_fsm_ac_configure_recv_pkt",0x8e,param_1,uVar4,uVar2,uVar3);
      return 0xffffffff;
    }
    uVar4 = 0x6f;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_configure_recv_pkt",uVar4,pcVar5);
  return 0xffffffff;
}

