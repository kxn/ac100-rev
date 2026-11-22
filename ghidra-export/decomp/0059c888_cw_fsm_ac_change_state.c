// func cw_fsm_ac_change_state @ 0059c888 size=308

undefined4 cw_fsm_ac_change_state(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0xffffffff;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_change_state",0x9a,"session");
  }
  else if (param_2 < 0xf) {
    if (capwap_fsm_debug_switch == 0) {
      *(uint *)(param_1 + 0xb4) = param_2;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        uVar2 = cw_fsm_get_state_name(param_2);
        printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] state is changed to [%s]\n",
               "cw_fsm_ac_change_state",0xa2,param_1,uVar3,uVar2);
        *(uint *)(param_1 + 0xb4) = param_2;
        return 0;
      }
      *(uint *)(param_1 + 0xb4) = param_2;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
    if ((capwap_fsm_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      printf("[FSM_ERROR]%31s():%4d | session[%p] state[%s] Invalid state \'%d\'\n",
             "cw_fsm_ac_change_state",0x9e,param_1,uVar2,param_2);
    }
  }
  return uVar3;
}

