// func cw_fsm_ac_timer_value_set @ 0059d628 size=1

void cw_fsm_ac_timer_value_set(int param_1,undefined4 param_2)

{
  if (param_1 - 1U < 10) {
    *(undefined4 *)(&l_timeouts + param_1 * 4) = param_2;
    return;
  }
  printf("type[%d] is illegal\n",param_1);
  return;
}

