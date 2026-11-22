// func cw_fsm_ac_teardown @ 0059d0b0 size=416

undefined4 cw_fsm_ac_teardown(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [20];
  undefined2 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_teardown",0x155,"session");
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
        printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] is teardown\n","cw_fsm_ac_teardown",
               0x156,param_1,uVar3);
        uVar3 = *(undefined4 *)(param_1 + 0xc);
      }
    }
    cw_fsm_ac_timer_clear(param_1);
    cw_ac_session_remove(uVar3,param_1);
    memset(auStack_48,0,0x34);
    memcpy(auStack_38,(void *)(param_1 + 0x2c),0x14);
    local_24 = *(undefined2 *)(param_1 + 0x40);
    local_20 = *(undefined4 *)(param_1 + 0x44);
    local_1c = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
    local_18 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
    if (*(int *)(param_1 + 0x10) != 0) {
      memcpy(auStack_48,(void *)(param_1 + 0x14),6);
    }
    serv_ent_handle(0,auStack_48,0,0);
    if ((capwap_fsm_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] destructed by ac_data[%p]\n",
             "cw_fsm_ac_teardown",0x16a,param_1,uVar2,uVar3);
    }
    cw_fsm_stat_dec(param_1);
    capwap_ac_session_free(param_1);
    uVar3 = 0;
  }
  return uVar3;
}

