// func cw_fsm_ac_get_event_name @ 0059c830 size=44

char * cw_fsm_ac_get_event_name(uint param_1)

{
  if (param_1 < 0xe) {
    return (&PTR_s__EVENT_NONE__006e4ab0)[param_1];
  }
  return "-INVALID_EVENT-";
}

