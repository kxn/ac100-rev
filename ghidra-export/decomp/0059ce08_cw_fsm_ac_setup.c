// func cw_fsm_ac_setup @ 0059ce08 size=208

undefined4 cw_fsm_ac_setup(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0xffffffff;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_setup",0x113,"session");
  }
  else {
    *(undefined4 *)(param_1 + 0xbc) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 1;
    *(undefined4 *)(param_1 + 0xd0) = DAT_0074cfd0;
    *(undefined4 *)(param_1 + 0xcc) = 5;
    uVar3 = 0;
    if ((capwap_fsm_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar2 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
      printf("[FSM_DEBUG]%31s():%4d | session[%p] state[%s] is created\n","cw_fsm_ac_setup",0x11f,
             param_1,uVar2);
    }
  }
  return uVar3;
}

