// func cw_fsm_ac_reset_send_pkt @ 005a003c size=272

undefined4 cw_fsm_ac_reset_send_pkt(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    uVar5 = 0x8c;
    pcVar4 = "session";
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      uVar5 = param_2[1];
      if (capwap_fsm_debug_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      uVar3 = cw_fsm_ac_get_event_name(*param_2);
      uVar5 = cw_control_msg_name(uVar5);
      printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] event[%s] pkt is %s\n",
             "cw_fsm_ac_reset_send_pkt",0x91,param_1,uVar2,uVar3,uVar5);
      return 0;
    }
    uVar5 = 0x8d;
    pcVar4 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_reset_send_pkt",uVar5,pcVar4);
  return 0xffffffff;
}

