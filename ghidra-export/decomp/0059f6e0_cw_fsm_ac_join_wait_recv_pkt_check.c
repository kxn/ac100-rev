// func cw_fsm_ac_join_wait_recv_pkt_check @ 0059f6e0 size=368

undefined4 cw_fsm_ac_join_wait_recv_pkt_check(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 == 0) {
    uVar2 = 0x36;
    pcVar5 = "session";
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      iVar6 = param_2[1];
      if (iVar6 == 3) {
        if (capwap_fsm_debug_switch == 0) {
          return 0;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0;
        }
        uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        uVar3 = cw_fsm_ac_get_event_name(*param_2);
        printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is JOIN_REQUEST, packet matches the state\n"
               ,"cw_fsm_ac_join_wait_recv_pkt_check",0x3d,param_1,uVar2,uVar3);
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
             "cw_fsm_ac_join_wait_recv_pkt_check",0x40,param_1,uVar2,uVar3,uVar4);
      return 0xffffffff;
    }
    uVar2 = 0x37;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_join_wait_recv_pkt_check",uVar2,pcVar5)
  ;
  return 0xffffffff;
}

