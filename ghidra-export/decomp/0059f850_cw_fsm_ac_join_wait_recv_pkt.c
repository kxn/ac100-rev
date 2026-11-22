// func cw_fsm_ac_join_wait_recv_pkt @ 0059f850 size=332

undefined4 cw_fsm_ac_join_wait_recv_pkt(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    uVar2 = 0x48;
    pcVar3 = "session";
  }
  else {
    if (param_2 != (int *)0x0) {
      if ((*param_2 == 3) && (param_2[1] == 3)) {
        if ((capwap_fsm_debug_switch != 0) && (iVar1 = is_target_debug_ap(3,7), iVar1 != 0)) {
          uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] JOIN_REQUEST checked passed, send JOIN_RESPONSE with success result element\n"
                 ,"cw_fsm_ac_join_wait_recv_pkt",0x4f,param_1,uVar2);
        }
        cw_fsm_ac_change_state(param_1,7);
        *(int *)(*(int *)(param_1 + 0xc) + 0x5c) = *(int *)(*(int *)(param_1 + 0xc) + 0x5c) + 1;
      }
      else {
        if ((capwap_fsm_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] JOIN_REQUEST checked failed, send JOIN_RESPONSE with failed result element\n"
                 ,"cw_fsm_ac_join_wait_recv_pkt",0x56,param_1,uVar2);
        }
        cw_fsm_ac_teardown(param_1);
      }
      return 0;
    }
    uVar2 = 0x49;
    pcVar3 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_join_wait_recv_pkt",uVar2,pcVar3);
  return 0xffffffff;
}

