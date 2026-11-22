// func cw_fsm_ac_get_timer_name @ 0059c85c size=44

char * cw_fsm_ac_get_timer_name(uint param_1)

{
  if (param_1 < 0xc) {
    return (&PTR_s__TIMER_NONE__006e4ae8)[param_1];
  }
  return "-INVALID_TIMER-";
}

