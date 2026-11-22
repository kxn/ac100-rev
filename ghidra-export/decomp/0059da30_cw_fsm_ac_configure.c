// func cw_fsm_ac_configure @ 0059da30 size=664

undefined4 cw_fsm_ac_configure(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  if (param_1 == 0) {
    uVar3 = 0xba;
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
                 "cw_fsm_ac_configure",0xbd,param_1,uVar3,uVar4);
          iVar1 = *param_2;
        }
      }
      if (iVar1 - 2U < 2) {
        uVar3 = cw_fsm_ac_configure_recv_pkt(param_1,param_2);
        return uVar3;
      }
      if (iVar1 == 1) {
        uVar3 = cw_fsm_ac_configure_recv_pkt_check(param_1,param_2);
        return uVar3;
      }
      if (iVar1 == 5) {
        iVar1 = param_2[1];
        if (iVar1 == 4) {
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
              printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] ChangeStatePendingTimer timeout, teardown the session\n"
                     ,"cw_fsm_ac_configure",0xcd,param_1,uVar3);
              iVar1 = *(int *)(param_1 + 0xc);
            }
          }
          *(int *)(iVar1 + 0x6c) = *(int *)(iVar1 + 0x6c) + 1;
          cw_fsm_ac_timer_clear(param_1);
          cw_fsm_ac_enter_reset(param_1,1);
          cw_fsm_ac_session_delete(param_1);
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
        uVar6 = 0xd8;
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
        uVar6 = 0xde;
      }
      printf(pcVar5,"cw_fsm_ac_configure",uVar6,param_1,uVar3,uVar4);
      return 0xffffffff;
    }
    uVar3 = 0xbb;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_configure",uVar3,pcVar5);
  return 0xffffffff;
}

