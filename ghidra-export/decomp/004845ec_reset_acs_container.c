// func reset_acs_container @ 004845ec size=48

void reset_acs_container(void)

{
  init_acs_to_end_state();
  FUN_00408090(begin_acs_container);
  begin_acs_container = 0;
  return;
}

