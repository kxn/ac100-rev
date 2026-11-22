// func cw_fsm_ac_get_timer_timeout @ 0059c9bc size=124

int cw_fsm_ac_get_timer_timeout(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = -1;
  if (param_2 < 0xc) {
    if ((((param_2 - 1 < 2) || (param_2 == 5)) || (param_2 == 3)) || (param_2 == 4)) {
      return *(int *)(&l_timeouts + param_2 * 4);
    }
    iVar1 = 0;
    if (param_2 == 9) {
      iVar1 = *(int *)(param_1 + 0xd0);
      if (iVar1 < 1) {
        iVar1 = -1;
      }
      return iVar1;
    }
  }
  return iVar1;
}

