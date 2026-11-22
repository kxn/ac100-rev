// func cw_ac_data_manager_timer_event_process @ 00589640 size=204

void cw_ac_data_manager_timer_event_process(int param_1,int *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x67e;
    pcVar2 = "timer_data";
  }
  else {
    if (param_1 != 0) {
      memcpy((void *)(*(int *)(param_1 + 0xc) + 0x7c),(void *)(param_1 + 0x2c),0x14);
      *(undefined2 *)(*(int *)(param_1 + 0xc) + 0x90) = *(undefined2 *)(param_1 + 0x40);
      if (*param_2 == 1) {
        cw_fsm_ac_echo_interval_set(param_1,param_2[1]);
        return;
      }
      return;
    }
    uVar1 = 0x67f;
    pcVar2 = "session";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_data_manager_timer_event_process",uVar1,
         pcVar2);
  return;
}

