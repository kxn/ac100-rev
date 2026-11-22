// func cw_fsm_ac_echo_interval_set @ 0059d378 size=112

undefined4 cw_fsm_ac_echo_interval_set(int param_1,int param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (param_1 == 0) {
    uVar1 = 0x181;
    pcVar2 = "session";
  }
  else {
    if (-1 < param_2) {
      *(int *)(param_1 + 0xd0) = param_2;
      return 0;
    }
    uVar1 = 0x182;
    pcVar2 = "echo_interval >= 0";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_echo_interval_set",uVar1,pcVar2);
  return 0xffffffff;
}

