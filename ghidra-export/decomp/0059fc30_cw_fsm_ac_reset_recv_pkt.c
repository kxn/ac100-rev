// func cw_fsm_ac_reset_recv_pkt @ 0059fc30 size=500

undefined4 cw_fsm_ac_reset_recv_pkt(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 == 0) {
    uVar2 = 0x4a;
    pcVar5 = "session";
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      iVar6 = param_2[1];
      if ((capwap_fsm_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        uVar3 = cw_fsm_ac_get_event_name(*param_2);
        uVar4 = cw_control_msg_name(iVar6);
        printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is %s\n",
               "cw_fsm_ac_reset_recv_pkt",0x4f,param_1,uVar2,uVar3,uVar4);
      }
      if (iVar6 == 0x12) {
        if ((capwap_fsm_debug_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar3 = cw_fsm_ac_get_event_name(*param_2);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is RESET_RESPONSE\n",
                 "cw_fsm_ac_reset_recv_pkt",0x53,param_1,uVar2,uVar3);
        }
        cw_fsm_ac_session_delete(param_1);
        return 0;
      }
      if (capwap_fsm_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      uVar3 = cw_fsm_ac_get_event_name(*param_2);
      uVar4 = cw_control_msg_name(iVar6);
      printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] invalid message %s\n",
             "cw_fsm_ac_reset_recv_pkt",0x5c,param_1,uVar2,uVar3,uVar4);
      return 0xffffffff;
    }
    uVar2 = 0x4b;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_reset_recv_pkt",uVar2,pcVar5);
  return 0xffffffff;
}

