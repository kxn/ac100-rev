// func cw_fsm_ac_data_check_recv_pkt @ 0059dcd0 size=676

undefined4 cw_fsm_ac_data_check_recv_pkt(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 == 0) {
    uVar1 = 0x62;
    pcVar5 = "session";
  }
  else {
    if (param_2 != (int *)0x0) {
      iVar6 = param_2[1];
      if (capwap_fsm_debug_switch == 0) {
        iVar4 = *param_2;
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = *param_2;
        }
        else {
          uVar1 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar2 = cw_fsm_ac_get_event_name(*param_2);
          uVar3 = cw_control_msg_name(iVar6);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is %s\n",
                 "cw_fsm_ac_data_check_recv_pkt",0x67,param_1,uVar1,uVar2,uVar3);
          iVar4 = *param_2;
        }
      }
      if (iVar4 != 3) {
        cw_fsm_ac_teardown(param_1);
        return 0;
      }
      if ((iVar6 == 0xd) || (iVar6 == 9)) {
        if ((capwap_fsm_debug_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          uVar1 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar2 = cw_fsm_ac_get_event_name(*param_2);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is ECHO_REQUEST/WTP_EVENT_REQUEST, RUN it.\n"
                 ,"cw_fsm_ac_data_check_recv_pkt",0x6c,param_1,uVar1,uVar2);
        }
        cw_fsm_ac_timer_set(param_1,9,0);
        cw_fsm_ac_change_state(param_1,0xd);
        *(int *)(*(int *)(param_1 + 0xc) + 0x60) = *(int *)(*(int *)(param_1 + 0xc) + 0x60) + 1;
        cw_fsm_ac_enter_run(param_1);
        return 0;
      }
      if (iVar6 != 0xb) {
        if (capwap_fsm_debug_switch == 0) {
          return 0xffffffff;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        uVar1 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        uVar2 = cw_fsm_ac_get_event_name(*param_2);
        uVar3 = cw_control_msg_name(iVar6);
        printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] invalid message %s\n",
               "cw_fsm_ac_data_check_recv_pkt",0x7b,param_1,uVar1,uVar2,uVar3);
        return 0xffffffff;
      }
      if (capwap_fsm_debug_switch == 0) {
        return 0;
      }
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        return 0;
      }
      uVar1 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      uVar2 = cw_fsm_ac_get_event_name(*param_2);
      printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is CHANGE_STATE_EVENT_REQUEST, re-transmit CHANGE_STATE_EVENT_RESPONSE\n"
             ,"cw_fsm_ac_data_check_recv_pkt",0x77,param_1,uVar1,uVar2);
      return 0;
    }
    uVar1 = 99;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_data_check_recv_pkt",uVar1,pcVar5);
  return 0xffffffff;
}

