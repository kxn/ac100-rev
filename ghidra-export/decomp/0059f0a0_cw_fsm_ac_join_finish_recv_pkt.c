// func cw_fsm_ac_join_finish_recv_pkt @ 0059f0a0 size=648

undefined4 cw_fsm_ac_join_finish_recv_pkt(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 == 0) {
    uVar4 = 0x80;
    pcVar5 = "session";
  }
  else {
    if (param_2 != (int *)0x0) {
      iVar6 = param_2[1];
      if (*param_2 != 3) {
        cw_fsm_ac_teardown();
        return 0;
      }
      if (iVar6 == 0xf) {
        if ((capwap_fsm_debug_switch != 0) && (iVar6 = is_target_debug_ap(0xf,9), iVar6 != 0)) {
          uVar4 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar3 = cw_fsm_ac_get_event_name(*param_2);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is IMAGE_DATA_REQUEST\n"
                 ,"cw_fsm_ac_join_finish_recv_pkt",0x89,param_1,uVar4,uVar3);
        }
        cw_fsm_ac_timer_set(param_1,9,0);
        uVar4 = 8;
      }
      else {
        if (iVar6 != 5) {
          if (iVar6 == 3) {
            if (capwap_fsm_debug_switch == 0) {
              return 0;
            }
            iVar6 = is_target_debug_ap();
            if (iVar6 == 0) {
              return 0;
            }
            uVar4 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
            uVar3 = cw_fsm_ac_get_event_name(*param_2);
            printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is JOIN_REQUEST, re-transmit JOIN_RESPONSE\n"
                   ,"cw_fsm_ac_join_finish_recv_pkt",0x9b,param_1,uVar4,uVar3);
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
          uVar3 = cw_fsm_ac_get_event_name(*param_2);
          uVar2 = cw_control_msg_name(iVar6);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] invalid message %s\n",
                 "cw_fsm_ac_join_finish_recv_pkt",0x9f,param_1,uVar4,uVar3,uVar2);
          return 0xffffffff;
        }
        if ((capwap_fsm_debug_switch != 0) && (iVar6 = is_target_debug_ap(5,4), iVar6 != 0)) {
          uVar4 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar3 = cw_fsm_ac_get_event_name(*param_2);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is CONFIGURE_REQUEST\n"
                 ,"cw_fsm_ac_join_finish_recv_pkt",0x93,param_1,uVar4,uVar3);
        }
        cw_fsm_ac_timer_set(param_1,4,0);
        uVar4 = 9;
      }
      cw_fsm_ac_change_state(param_1,uVar4);
      return 0;
    }
    uVar4 = 0x81;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_join_finish_recv_pkt",uVar4,pcVar5);
  return 0xffffffff;
}

