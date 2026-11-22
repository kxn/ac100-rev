// func cw_fsm_ac_run @ 005a091c size=1

undefined4 cw_fsm_ac_run(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  if (param_1 == 0) {
    uVar3 = 0x135;
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
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] got event[%s]\n","cw_fsm_ac_run",
                 0x138,param_1,uVar3,uVar4);
          iVar1 = *param_2;
        }
      }
      if (iVar1 - 2U < 2) {
        if (param_1 == 0) {
          uVar3 = 0xc9;
          pcVar5 = "session";
        }
        else {
          if (param_2 != (int *)0x0) {
            iVar1 = param_2[1];
            if (capwap_fsm_debug_switch == 0) {
              iVar1 = *param_2;
            }
            else {
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                iVar1 = *param_2;
              }
              else {
                uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
                uVar4 = cw_fsm_ac_get_event_name(*param_2);
                uVar6 = cw_control_msg_name(iVar1);
                printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is %s\n",
                       "cw_fsm_ac_run_recv_pkt",0xce,param_1,uVar3,uVar4,uVar6);
                iVar1 = *param_2;
              }
            }
            if (iVar1 == 3) {
              *(undefined4 *)(param_1 + 200) = 0;
              cw_fsm_ac_timer_set(param_1,9,0);
              return 0;
            }
            cw_fsm_ac_teardown(param_1,9);
            return 0xffffffff;
          }
          uVar3 = 0xca;
          pcVar5 = "event";
        }
        printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_run_recv_pkt",uVar3,pcVar5);
        return 0xffffffff;
      }
      if (iVar1 == 1) {
        if (param_1 == 0) {
          uVar3 = 0x118;
          pcVar5 = "session";
        }
        else {
          if (param_2 != (int *)0x0) {
            iVar1 = param_2[1];
            if ((capwap_fsm_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
              uVar4 = cw_fsm_ac_get_event_name(*param_2);
              uVar6 = cw_control_msg_name(iVar1);
              printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is %s\n",
                     "cw_fsm_ac_run_recv_pkt_check",0x11c,param_1,uVar3,uVar4,uVar6);
            }
            if (iVar1 == 0xd) {
              return 0;
            }
            if (iVar1 == 9) {
              return 0;
            }
            if (iVar1 == 8) {
              return 0;
            }
            if (iVar1 == 0x12) {
              return 0;
            }
            if (iVar1 == 0x18) {
              return 0;
            }
            if (iVar1 == 0x1a) {
              return 0;
            }
            if (iVar1 == 0xf) {
              return 0;
            }
            if (iVar1 == 0x10) {
              return 0;
            }
            if (iVar1 == 0x33dd02) {
              return 0;
            }
            if (iVar1 != 0xb) {
              return 0xffffffff;
            }
            return 0;
          }
          uVar3 = 0x119;
          pcVar5 = "event";
        }
        printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_run_recv_pkt_check",uVar3,pcVar5)
        ;
        return 0xffffffff;
      }
      if (iVar1 == 0xb) {
        if (param_1 == 0) {
          uVar3 = 0xe6;
          pcVar5 = "session";
        }
        else {
          if (param_2 != (int *)0x0) {
            iVar1 = param_2[1];
            if ((capwap_fsm_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
              uVar4 = cw_fsm_ac_get_event_name(*param_2);
              uVar6 = cw_control_msg_name(iVar1);
              printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is %s\n",
                     "cw_fsm_ac_run_send_pkt_check",0xeb,param_1,uVar3,uVar4,uVar6);
            }
            if (((((iVar1 == 7) || (iVar1 == 0x15)) || (iVar1 == 0x17)) ||
                ((iVar1 == 0x19 || (iVar1 == 0x33dd01)))) && (*(int *)(param_1 + 0xb8) != 2)) {
              return 0;
            }
            if (2 < iVar1 - 0xfU) {
              return 0xffffffff;
            }
            return 0;
          }
          uVar3 = 0xe7;
          pcVar5 = "event";
        }
        printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_run_send_pkt_check",uVar3,pcVar5)
        ;
        return 0xffffffff;
      }
      if (iVar1 == 0xc) {
        if (param_1 == 0) {
          uVar3 = 0xfe;
          pcVar5 = "session";
        }
        else {
          if (param_2 != (int *)0x0) {
            iVar1 = param_2[1];
            if ((capwap_fsm_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
              uVar4 = cw_fsm_ac_get_event_name(*param_2);
              uVar6 = cw_control_msg_name(iVar1);
              printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is %s\n",
                     "cw_fsm_ac_run_send_pkt",0x103,param_1,uVar3,uVar4,uVar6);
            }
            if (iVar1 != 0x11) {
              if (iVar1 != 0xf) {
                return 0;
              }
              *(undefined4 *)(param_1 + 0xb8) = 2;
              return 0;
            }
            cw_fsm_ac_timer_clear(param_1);
            *(int *)(*(int *)(param_1 + 0xc) + 0x60) = *(int *)(*(int *)(param_1 + 0xc) + 0x60) + -1
            ;
            cw_fsm_ac_enter_reset(param_1,0);
            return 0;
          }
          uVar3 = 0xff;
          pcVar5 = "event";
        }
        printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_run_send_pkt",uVar3,pcVar5);
        return 0xffffffff;
      }
      if (iVar1 == 5) {
        iVar1 = param_2[1];
        if (iVar1 == 9) {
          if (*(int *)(param_1 + 200) < *(int *)(param_1 + 0xcc)) {
            *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
            if ((capwap_fsm_debug_switch != 0) &&
               (iVar1 = is_target_debug_ap(param_1,9), iVar1 != 0)) {
              uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
              printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] echo timeout[%d/%d]\n",
                     "cw_fsm_ac_run",0x160,param_1,uVar3,*(undefined4 *)(param_1 + 200),
                     *(undefined4 *)(param_1 + 0xcc));
            }
            cw_fsm_ac_timer_set(param_1,9,0);
            return 0;
          }
        }
        else if (iVar1 != 10) {
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
          uVar6 = 0x166;
          goto code_r0x005a0ac0;
        }
        if ((capwap_fsm_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
          uVar4 = cw_fsm_ac_get_timer_name(iVar1);
          printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] %s timeout, teardown the session\n",
                 "cw_fsm_ac_run",0x150,param_1,uVar3,uVar4);
        }
        iVar2 = *(int *)(param_1 + 0xc);
        if (iVar1 == 9) {
          *(int *)(iVar2 + 0x74) = *(int *)(iVar2 + 0x74) + 1;
        }
        else {
          *(int *)(iVar2 + 0x78) = *(int *)(iVar2 + 0x78) + 1;
        }
        cw_fsm_ac_timer_clear(param_1);
        cw_fsm_ac_teardown(param_1);
        return 0;
      }
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
      uVar6 = 0x16c;
code_r0x005a0ac0:
      printf(pcVar5,"cw_fsm_ac_run",uVar6,param_1,uVar3,uVar4);
      return 0xffffffff;
    }
    uVar3 = 0x136;
    pcVar5 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_run",uVar3,pcVar5);
  return 0xffffffff;
}

