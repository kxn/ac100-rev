// func cw_fsm_ac_dtls_setup @ 0059e330 size=596

undefined4 cw_fsm_ac_dtls_setup(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  if (param_1 == 0) {
    uVar3 = 0x56;
    pcVar5 = "session";
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
          uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar4 = cw_fsm_ac_get_event_name(*param_2);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] got event[%s]\n",
                 "cw_fsm_ac_dtls_setup",0x59,param_1,uVar3,uVar4);
          iVar1 = *param_2;
        }
      }
      if (iVar1 == 8) {
        cw_fsm_ac_timer_set(param_1,2,0);
        cw_fsm_ac_change_state(param_1,6);
        return 0;
      }
      if (iVar1 == 5) {
        iVar1 = param_2[1];
        if (iVar1 == 1) {
          if (capwap_fsm_debug_switch == 0) {
            iVar1 = *(int *)(param_1 + 0xc);
          }
          else {
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              iVar1 = *(int *)(param_1 + 0xc);
            }
            else {
              uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
              printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] WaitDTLS timeout, teardown the session\n"
                     ,"cw_fsm_ac_dtls_setup",0x67,param_1,uVar3);
              iVar1 = *(int *)(param_1 + 0xc);
            }
          }
          *(int *)(iVar1 + 100) = *(int *)(iVar1 + 100) + 1;
          cw_fsm_ac_teardown(param_1);
          return 0;
        }
        if (capwap_fsm_debug_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        uVar4 = cw_fsm_ac_get_timer_name(iVar1);
        pcVar5 = "[FSM_DEBUG]%31s():%4d | session[%p] state[%s] invalid timeout[%s]\n";
        uVar6 = 0x72;
      }
      else {
        if (capwap_fsm_debug_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        uVar4 = cw_fsm_ac_get_event_name(*param_2);
        pcVar5 = "[FSM_DEBUG]%31s():%4d | session[%p] state[%s] got invalid event[%s]\n";
        uVar6 = 0x78;
      }
      printf(pcVar5,"cw_fsm_ac_dtls_setup",uVar6,param_1,uVar3,uVar4);
      return 0xffffffff;
    }
    uVar3 = 0x57;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_dtls_setup",uVar3,pcVar5);
  return 0xffffffff;
}

