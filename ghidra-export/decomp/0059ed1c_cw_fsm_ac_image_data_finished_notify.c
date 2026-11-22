// func cw_fsm_ac_image_data_finished_notify @ 0059ed1c size=208

undefined4 cw_fsm_ac_image_data_finished_notify(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    uVar2 = 0xaf;
    pcVar3 = "session";
  }
  else {
    if (param_2 != 0) {
      if ((capwap_fsm_debug_switch != 0) &&
         (iVar1 = is_target_debug_ap("et file[%s] fail!\n",10), iVar1 != 0)) {
        uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] image data transfer finished\n",
               "cw_fsm_ac_image_data_finished_notify",0xb2,param_1,uVar2);
      }
      cw_fsm_ac_change_state(param_1,10);
      return 0xffffffff;
    }
    uVar2 = 0xb0;
    pcVar3 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_image_data_finished_notify",uVar2,
         pcVar3);
  return 0xffffffff;
}

