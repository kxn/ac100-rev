// func cw_fsm_ac_session_delete @ 0059d250 size=296

undefined4 cw_fsm_ac_session_delete(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_session_delete",0x171,"session");
    uVar3 = 0xffffffff;
  }
  else {
    if (capwap_fsm_debug_switch == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0xc);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar3 = *(undefined4 *)(param_1 + 0xc);
      }
      else {
        uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] is teardown\n",
               "cw_fsm_ac_session_delete",0x172,param_1,uVar3);
        uVar3 = *(undefined4 *)(param_1 + 0xc);
      }
    }
    cw_fsm_ac_timer_clear(param_1);
    cw_ac_session_remove(uVar3,param_1);
    if ((capwap_fsm_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] destructed by ac_data[%p]\n",
             "cw_fsm_ac_session_delete",0x17a,param_1,uVar2,uVar3);
    }
    cw_fsm_stat_dec(param_1);
    capwap_ac_session_free(param_1);
    uVar3 = 0;
  }
  return uVar3;
}

