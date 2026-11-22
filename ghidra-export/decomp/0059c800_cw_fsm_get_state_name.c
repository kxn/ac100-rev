// func cw_fsm_get_state_name @ 0059c800 size=44

char * cw_fsm_get_state_name(uint param_1)

{
  if (param_1 < 0xf) {
    return (&PTR_s_START_006e4510)[param_1];
  }
  return "-INVALID_STATE-";
}

