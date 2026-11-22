// func cw_fsm_ac_process_event @ 0059d3e8 size=392

undefined4 cw_fsm_ac_process_event(int param_1,uint *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    uVar3 = 0x18a;
    pcVar4 = "session";
  }
  else {
    if (param_2 != (uint *)0x0) {
      if (*(uint *)(param_1 + 0xb4) < 0xf) {
        if (*(code **)(&l_event_processes + *(uint *)(param_1 + 0xb4) * 4) != (code *)0x0) {
                    /* WARNING: Jumptable at 0x0059d478 did not pass sanity check. */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (**(code **)(&l_event_processes + *(uint *)(param_1 + 0xb4) * 4))();
          return uVar3;
        }
        if (capwap_fsm_err_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        if (*param_2 < 0xe) {
          pcVar4 = (&PTR_s__EVENT_NONE__006e4ab0)[*param_2];
        }
        else {
          pcVar4 = "-INVALID_EVENT-";
        }
        __format = "[FSM_ERROR]%31s():%4d | session[%p] state[%s] no process-func for event[%s]\n";
        uVar2 = 0x194;
      }
      else {
        if (capwap_fsm_err_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        uVar3 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
        pcVar4 = *(char **)(param_1 + 0xb4);
        __format = "[FSM_ERROR]%31s():%4d | session[%p] state[%s] Invalid state \'%d\'\n";
        uVar2 = 399;
      }
      printf(__format,"cw_fsm_ac_process_event",uVar2,param_1,uVar3,pcVar4);
      return 0xffffffff;
    }
    uVar3 = 0x18b;
    pcVar4 = "event";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_process_event",uVar3,pcVar4);
  return 0xffffffff;
}

