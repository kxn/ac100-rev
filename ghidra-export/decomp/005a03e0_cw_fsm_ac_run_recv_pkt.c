// func cw_fsm_ac_run_recv_pkt @ 005a03e0 size=1

undefined4 cw_fsm_ac_run_recv_pkt(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 == 0) {
    uVar2 = 0xc9;
    pcVar5 = "session";
  }
  else {
    if (param_2 != (int *)0x0) {
      iVar6 = param_2[1];
      if (capwap_fsm_debug_switch == 0) {
        iVar6 = *param_2;
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          iVar6 = *param_2;
        }
        else {
          uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar3 = cw_fsm_ac_get_event_name(*param_2);
          uVar4 = cw_control_msg_name(iVar6);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is %s\n",
                 "cw_fsm_ac_run_recv_pkt",0xce,param_1,uVar2,uVar3,uVar4);
          iVar6 = *param_2;
        }
      }
      if (iVar6 == 3) {
        *(undefined4 *)(param_1 + 200) = 0;
        cw_fsm_ac_timer_set(param_1,9,0);
        return 0;
      }
      cw_fsm_ac_teardown(param_1,9);
      return 0xffffffff;
    }
    uVar2 = 0xca;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_run_recv_pkt",uVar2,pcVar5);
  return 0xffffffff;
}

