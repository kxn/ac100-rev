// func bcast_storm_ctrl_debug_help @ 0045f9d4 size=1

void bcast_storm_ctrl_debug_help(void)

{
  puts("bcast_storm_ctrl debug commands:");
  puts("bcast_storm_ctrl_debug_help() -- help menu");
  (*(code *)PTR_puts_00758f90)
            ("bcast_storm_ctrl_debug_cfg_dump() -- show bcast_storm_ctrl config info");
  return;
}

